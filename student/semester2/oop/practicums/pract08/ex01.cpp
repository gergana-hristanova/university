#include <iostream>

template <typename T>
struct Node
{
    Node(T data, Node* next = nullptr) : data(data), next(next) {}
    Node(const Node& other) : data(other.data), next(other.next) {}

    operator bool() const
    {
        return next;
    }

    T data;
    Node* next;
};

template <typename T>
class LinkedList
{
public:
    LinkedList() : first(nullptr), last(nullptr) {}
    LinkedList(const LinkedList& other) : first(nullptr), last(nullptr)
    {
        if (!other.first)
        {
            return;
        }

        Node<T>* current = first = new Node(other.first);
        while(current)
        {
            current = new Node(current->next);
        }
    }

    ~LinkedList()
    {
        if (!first)
        {
            return;
        }

        Node<T>* current = first;
        Node<T>* next = current;
        while (current)
        {
            next=current->next;
            delete [] current;
            current = next;
        }
    }

    LinkedList& push_back(T el)
    {
        if (!last)
        {
            first = last = new Node(el);
        }
        else
        {
            last->next = new Node(el);
            last = last->next;
        }

        return *this;
    }

    // LinkedList& pop_back()
    // {
    //     if (!first)
    //     {
    //         return;
    //     }

    //     Node* current = 
    // }

    void print()
    {
        Node<T>* current = first;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }

private:
    Node<T>* first;
    Node<T>* last;
};

int main()
{
    LinkedList<int> l = LinkedList<int>();
    l.push_back(1).push_back(2).push_back(3);
    l.print();
}