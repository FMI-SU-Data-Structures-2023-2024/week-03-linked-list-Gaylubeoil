#include "LinkedList.cpp"

////////////////////////////////////////////////////////////////////////
/////////////////////////////////Iterator///////////////////////////////
////////////////////////////////////////////////////////////////////////

template <typename T>
T &LinkedList<T>::Iterator::operator*() const
{
    return current->key;
}

template <typename T>
bool LinkedList<T>::Iterator::operator==(const Iterator &rhs)
{
    return current == rhs.current;
}

template <typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator &rhs)
{
    return current != rhs.current;
}

template <typename T>
typename LinkedList<T>::Iterator &LinkedList<T>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int)
{
    LinkedList<T>::Iterator it(current);
    ++it;
    return it;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////const Iterator//////////////////////////////
////////////////////////////////////////////////////////////////////////

template <typename T>
const T &LinkedList<T>::cIterator::operator*() const
{
    return current->key;
}

template <typename T>
bool LinkedList<T>::cIterator::operator==(const cIterator &rhs)
{
    return current == rhs.current;
}

template <typename T>
bool LinkedList<T>::cIterator::operator!=(const cIterator &rhs)
{
    return current != rhs.current;
}

template <typename T>
typename LinkedList<T>::cIterator &LinkedList<T>::cIterator::operator++()
{
    current = current->next;
    return *this;
}

template <typename T>
typename LinkedList<T>::cIterator LinkedList<T>::cIterator::operator++(int)
{
    LinkedList<T>::cIterator it(current);
    ++it;
    return it;
}