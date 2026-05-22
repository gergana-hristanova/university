#include <iostream>
#include <vector>
#include <string>

constexpr unsigned standard_deck_card_count = 52;
constexpr unsigned hot_potato_cards_count = 10;

Card deck[standard_deck_card_count];

class Card {};

class Hand
{
public:
    Hand& add_card(const Card& card)
    {
        cards.push_back(card);

        return *this;
    }

private:
    std::vector<Card> cards;
};

class Player
{
public:
    Player& add_card(const Card& card)
    {
        hand.add_card(card);

        return *this;
    }

private:
    std::string name;
    Hand hand;
};

class HotPotato : public Card {};

class CardGame
{
public:
    virtual void setup() const = 0;
};

class CardGameWithPlayers : public CardGame
{
public:
    void setup() const override
    {
        unsigned cards_per_player = standard_deck_card_count / players.size();

        for (Player p : players)
        {
            for(std::size_t i = 0; i < cards_per_player; ++i)
            {
                p.add_card(deck[i]);
            }
        }
    }

    // move semantics exercise
    void spin_cards()
    {
        std::size_t players_size = players.size();

        Player player_0 = std::move(players[0]);

        for (std::size_t i = 1; i < players_size; ++i)
        {
            players[i - 1] = std::move(players[i]);
        }

        players[players_size] = std::move(player_0);
    }

private:
    std::vector<Player> players;
};

class CardGameWithHotPotato : public CardGame
{
public:
    void setup() const override
    {
        // TODO
    }
};

int main()
{

}