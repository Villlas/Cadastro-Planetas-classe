#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node *prev;

    Node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class List
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }

        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void swap(Node<T> *a, Node<T> *b)
    {
        T temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node<T> *partition(Node<T> *low, Node<T> *high)
    {
        T pivot = high->data;
        Node<T> *i = low->prev;

        for (Node<T> *j = low; j != high; j = j->next)
        {
            if (j->data < pivot)
            {
                i = (i == nullptr) ? low : i->next;
                swap(i, j);
            }
        }

        i = (i == nullptr) ? low : i->next;
        swap(i, high);
        return i;
    }

    void quickSort(Node<T> *low, Node<T> *high)
    {
        if (high != nullptr && low != high && low != high->next)
        {
            Node<T> *pivot = partition(low, high);
            quickSort(low, pivot->prev);
            quickSort(pivot->next, high);
        }
    }

    void sort()
    {
        quickSort(head, tail);
    }

    void clear()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void bubbleSort()
    {
        if (isEmpty())
        {
            return;
        }

        bool swapped;
        Node<T> *current;
        Node<T> *last = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != last)
            {
                if (current->data > current->next->data)
                {
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }

            last = current;
        } while (swapped);
    }
};

int main()
{
    List<int> myList;
    myList.insert(9);
    myList.insert(5);
    myList.insert(7);
    myList.insert(3);
    myList.insert(1);

    cout << "Original List: ";
    myList.display();

    myList.sort();

    cout << "Sorted List: ";
    myList.display();

    myList.clear();

    return 0;
}
