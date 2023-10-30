#include "LinkedList.cpp"

#include <limits.h>

template <typename T>
LinkedList<T>::LinkedList()
    : head(nullptr), m_size(0){};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)
    : head(nullptr), m_size(rhs.m_size)
{
    if (rhs.head == nullptr)
        return;
    head = new Node<T>(rhs.head->key);
    Ptr current = head;
    Ptr other = rhs.head->next;

    while (other)
    {
        current->next = new Node<T>(other->key);
        current = current->next;
        other = other->next;
    }
};

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> list) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const
{
    if (m_size != rhs.m_size)
        return false;

    Node<T> *current = this->head, *other = rhs.head;
    while (current->next)
    {
        if (current->key != other->key)
            return false;
        current = current->next;
        other = other->next;
    }
    return true;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    if (this == &rhs)
        return *this;
    clear();
    m_size = rhs.m_size;
    if (rhs.head)
    {
        head = new Node<T>(rhs.head->key);
        Ptr current = head;
        Ptr other = rhs.head->next;

        while (other)
        {
            current->next = new Node<T>(other->key);
            current = current->next;
            other = other->next;
        }
    }
    return *this;
}

template <typename T>
void LinkedList<T>::push(const T &a)
{
    Node<T> *new_node = new Node<T>(a);
    std::size_t index = 0;
    if (!head)
        head = new_node;
    else
    {
        Node<T> *current = head;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
    m_size++;
}

template <typename T>
void LinkedList<T>::push_at(const T &a, std::size_t index)
{
    if (index > this->m_size) // Too large index
        throw std::out_of_range("LL::Out of range.\n");
    if (index == 0)
    { // index is 0
        Node<T> *temp = new Node<T>(a);
        temp->next = head;
        head = temp;
        m_size++;
        return;
    }

    Node<T> *begin = head;
    while (index > 1)
    {
        begin = begin->next;
        index--;
    }
    Node<T> *temp = begin->next;
    begin->next = new Node<T>(a);
    begin = begin->next;
    begin->next = temp;
    m_size++;
}

template <typename T>
void LinkedList<T>::erase(std::size_t pos)
{
    // Check if the passed position is within the list
    if (pos >= m_size)
        throw std::out_of_range("LL::Out of range.\n");

    if (pos == 0)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        m_size--;
        return;
    }

    Node<T> *begin = this->head;
    // This loop sets 'begin' to the elemnt before the one we need to erase
    while (pos-- > 1)
        begin = begin->next;

    // This needs to be erased
    Node<T> *temp = begin->next;
    begin->next = begin->next->next;
    delete temp;
    m_size--;
}

template <typename T>
const T &LinkedList<T>::get(unsigned pos) const
{
    if (m_size == 0 || pos >= m_size)
        throw std::out_of_range("Invalid position");

    if (pos == 0)
        return head->key;

    Node<T> *begin = head;
    while (pos-- != 0)
        begin = begin->next;
    return begin->key;
}

template <typename T>
T &LinkedList<T>::top()
{
    if (head)
        return head->key;
    throw std::out_of_range("List is empty");
}

template <typename T>
const T &LinkedList<T>::top() const
{
    if (head)
        return head->key;
    throw std::out_of_range("List is empty");
}

template <typename T>
std::size_t LinkedList<T>::size() const
{
    return m_size;
}

template <typename T>
void LinkedList<T>::clear()
{
    while (head)
    {
        Node<T> *temp = head->next;
        delete head;
        head = temp;
    }
    m_size = 0;
}

template <typename T>
void LinkedList<T>::sort()
{
    //merge_sort(this);
}

// template <typename T>
// void LinkedList<T>::merge_sort(LinkedList<T> *main)
// {
// }

// template <typename T>
// void LinkedList<T>::split_list(Ptr source, Node<T> **front, Node<T> **back)
// {
// }

// template <typename T>
// LinkedList<T>::Node<T> *LinkedList<T>::merge_lists(Node<T> *a, Node<T> *b)
// {
// }