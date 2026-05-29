#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Piece
{
public:

    struct Coordinates
    {
        char file; //horizontal
        unsigned rank; //vertical
    };

    enum class Color
    {
        WHITE,
        BLACK
    };

    Piece() {}

    Piece(Color color, unsigned move_limit, char board_symbol)
    : color(color),
      move_limit(move_limit),
      board_symbol(board_symbol)
    {}

    virtual bool is_valid_move(Coordinates curr_coords, Coordinates next_coords) const;

    Color color;
    unsigned move_limit;
    char board_symbol;
};

class ForwardMover : public virtual Piece
{
public:

    bool is_valid_move(Coordinates curr_coords, Coordinates next_coords) const override
    {
        if (this->color == Piece::Color::WHITE)
        {
            return next_coords.file == curr_coords.file &&
                   next_coords.rank + 1 == curr_coords.rank;
        }
        else
        {
            return next_coords.file == curr_coords.file &&
                   std::max(next_coords.rank - 1, 0u) == curr_coords.rank;   
        }
    } 
};

class LinearMover : public virtual Piece
{
public:

    bool is_valid_move(Coordinates curr_coords, Coordinates next_coords) const override
    {
        for (unsigned i = 1; i < move_limit; ++i)
        {
            if ((curr_coords.file + i == next_coords.file &&
                curr_coords.rank == next_coords.rank) ||
                (curr_coords.file == next_coords.file &&
                curr_coords.rank + i == next_coords.rank))
            {
                return true;
            }

            if ((std::max(curr_coords.file - i, 0u) == next_coords.file &&
                curr_coords.rank == next_coords.rank) ||
                (curr_coords.file == next_coords.file &&
                std::max(curr_coords.rank - i, 0u) == next_coords.rank))
            {
                return true;
            }
        }

        return false;
    }
};

class DiagonalMover : public virtual Piece
{
public:

    bool is_valid_move(Coordinates curr_coords, Coordinates next_coords) const override
    {
        for (unsigned i = 1; i < move_limit; ++i)
        {
            if (curr_coords.file + i == next_coords.file &&
                curr_coords.rank + i== next_coords.rank)
            {
                return true;
            }

            if (std::max(curr_coords.file - i, 0u) == next_coords.file &&
                std::max(curr_coords.file - i, 0u) == next_coords.rank)
            {
                return true;
            }
        }

        return false;
    }
};

class LShapeMover : public virtual Piece
{
public:

    bool is_valid_move(Coordinates curr_coords, Coordinates next_coords) const override
    {
        for (unsigned i = -1; i <= 1; i += 2)
        {
            for (unsigned j = -3; j <= 3; j += 6)
            {
                if ((std::max(curr_coords.file + i, 0u) == next_coords.file &&
                    std::max(curr_coords.rank + j, 0u) == next_coords.rank) ||
                    (std::max(curr_coords.rank + i, 0u) == next_coords.rank &&
                    std::max(curr_coords.file + j, 0u) == next_coords.file))
                {
                    return true;
                }
            }

            return false;
        }

        return false;
    }
};

class King : public LinearMover, public DiagonalMover
{
    King(Color color) : Piece(color, 1, 'k') {}

    bool is_valid_move(Coordinates curr_coords, Coordinates next_coords) const final
    {
        return LinearMover::is_valid_move(curr_coords, next_coords) ||       
               DiagonalMover::is_valid_move(curr_coords, next_coords);
    }
};

class Queen : public LinearMover, public DiagonalMover
{
    Queen(Color color) : Piece(color, 7, 'q') {}

    bool is_valid_move(Coordinates curr_coords, Coordinates next_coords) const final
    {
        return LinearMover::is_valid_move(curr_coords, next_coords) ||       
               DiagonalMover::is_valid_move(curr_coords, next_coords);
    }
};

class Rook : public LinearMover
{
    Rook(Color color) : Piece(color, 7, 'r') {}
};

class Bishop : public DiagonalMover
{
    Bishop(Color color) : Piece(color, 7, 'b') {}
};

class Knight : public LShapeMover
{
    Knight(Color color) : Piece(color, 7, 'n') {}
};

class Square
{
public:
    void put_piece(std::unique_ptr<Piece> new_piece)
    {
        this->piece = std::exchange(new_piece, nullptr);
    }

    // king = k, queen = q, rook = r, bishop = b, knight = n; pawn = p; empty = _
    // capital letters for white
    friend std::ostream& operator<<(std::ostream& os, const Square& sq)
    {
        if (!sq.piece)
        {
            os << "_ ";
            return os;
        }

        if (sq.piece->color == Piece::Color::WHITE)
        {
            os << std::toupper(sq.piece->board_symbol);
        }
        else
        {
            os << sq.piece->board_symbol;
        }

        return os;
    }

    std::unique_ptr<Piece> piece;
};

class Board
{
public:
    Board() : board(8, std::vector<Square>(8)) {}

    void print_console()
    {
        for (std::size_t i = 0; i < 8; ++i)
        {
            for (std::size_t j = 0; j < 8; ++j)
            {
                std::cout << board.at(i).at(j) << ' ';
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::vector<Square>> board;
};

int main()
{
    Board b;
    b.print_console();
}