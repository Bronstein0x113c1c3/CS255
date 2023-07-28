#include "Node.h"

template <typename Value>
class Queue
{
private:
    Node<Value> *head = nullptr;
    Node<Value> *tail = nullptr;
    int size = 0;

public:
    // Constructors
    Queue() : head{nullptr}, tail{nullptr} {};
    Queue(const Value &new_tail_value);
    Queue(Node<Value> *new_tail);
    Queue(std::initializer_list<Value> list);
    Queue(const Queue& otherQueue);         // COPY CONSTRUCTOR
    ~Queue();

    // METHODS
    void Enqueue(const Value &new_tail_value);
    void Enqueue(Node<Value> *new_tail);
    Value Dequeue();
    Value Peek() const;

    // ITERABLE (for Read-only Purpose)
    class Iterator
    {
    private:
        Node<Value>* current = nullptr;
    public:
        Iterator(Node<Value>* iterator) : current{iterator} {};
        Node<Value>& operator*() const
        {
            return *current;
        }

        Iterator operator++()
        {
            this->current = this->current->getNextNode();
            return *this;
        } 

        // Define COMPARISON for Iterator
        bool operator!=(const Iterator& otherNode)
        {
            return this->current != otherNode.current;
        }

        bool operator==(const Iterator& otherNode)
        {
            return this->current == otherNode.current;
        }
    };
    
    Iterator begin() const    // Beginning of the Queue
    {
        return Iterator(this->head);
    }
    
    Iterator end() const
    {
        return Iterator(this->tail->getNextNode());
    }
};

// CONSTRUCTORS
template <typename Value>
Queue<Value>::Queue(const Value &new_tail_value)
{
    Node<Value> *new_tail = new Node<Value>(new_tail_value);

    // If the Queue has No Element
    if (this->size == 0)
    {
        this->head = new_tail;
        this->tail = new_tail;
        this->size++;
        return;
    }
    // If the Queue has More than 1 Elements
    else
    {
        this->tail->setNextNode(new_tail);
        this->tail = new_tail;
        this->size++;
        return;
    }
}

template <typename Value>
Queue<Value>::Queue(Node<Value> *new_tail)
{
    // If the Queue has No Element
    if (this->size == 0)
    {
        this->head = new_tail;
        this->tail = new_tail;
        this->size++;
        return;
    }
    // If the Queue has More than 1 Elements
    else
    {
        this->tail->setNextNode(new_tail);
        this->tail = new_tail;
        this->size++;
        return;
    }
}

template <typename Value>
Queue<Value>::Queue(std::initializer_list<Value> list)
{
    for (const Value &value : list)
    {
        Node<Value> *new_tail = new Node<Value>(value);
        switch (this->size)
        {
        case 0:
            this->head = new_tail;
            this->tail = new_tail;
            this->size++;
            break;

        default:
            this->tail->setNextNode(new_tail);
            this->tail = new_tail;
            this->size++;
            break;
        }
    }
}

//! CURRENTLY WORKING ON
template <typename Value>
Queue<Value>::Queue(const Queue& otherQueue)         // COPY CONSTRUCTOR
{

}
template <typename Value>
Queue<Value>::~Queue()
{
}

template <typename Value>
void Queue<Value>::Enqueue(const Value &new_tail_value)
{
    Node<Value> *new_tail = new Node<Value>(new_tail_value);
    if (this->size == 0) // If the Queue Is Empty
    {
        this->head = new_tail;
        this->tail = new_tail;
        this->size++;
        return;
    }

    this->tail->setNextNode(new_tail);
    this->tail = new_tail;
    this->size++;
}

template <typename Value>
void Queue<Value>::Enqueue(Node<Value> *new_tail)
{
    if (this->size == 0) // If the Queue Is Empty
    {
        this->head = new_tail;
        this->tail = new_tail;
        this->size++;
        return;
    }

    this->tail->setNextNode(new_tail);
    this->tail = new_tail;
    this->size++;
}

template <typename Value>
Value Queue<Value>::Dequeue()
{
    // The Size cannot be Negative
    if (this->size <= 0)
    {
        throw std::out_of_range("Queue Is Empty!!!");
    }

    Node<Value> *node_to_remove = this->head;
    Value node_to_remove_value = node_to_remove->getValue();
    Node<Value> *new_head = this->head->getNextNode();
    switch (this->size)
    {
    case 1:
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
        delete node_to_remove;
        break;

    default:
        this->head = new_head;
        this->size--;
        delete node_to_remove;
        break;
    }
    return node_to_remove_value;
}

template <typename Value>
Value Queue<Value>::Peek() const
{
    return this->head->getValue();
}