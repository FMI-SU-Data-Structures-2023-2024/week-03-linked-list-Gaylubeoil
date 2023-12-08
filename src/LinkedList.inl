#include "LinkedList.cpp"

template <typename T>
LinkedList<T>::LinkedList() noexcept
    : head(nullptr), tail(nullptr), m_size(0){};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)
    : head(nullptr), tail(nullptr), m_size(rhs.m_size)
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
        if (!other->next)
            tail = current;
    }
};

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&rhs) noexcept
    : head(rhs.head), tail(rhs.tail), m_size(rhs.m_size)
{
    // Reset the other object.
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.m_size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> list)
    : head(nullptr), tail(nullptr), m_size(list.size())
{
    if (m_size == 0)
        return;

    head = new Node(*list.begin());
    Ptr current = head;
    for (auto it = list.begin() + 1; it != list.end(); ++it)
    {
        current->next = new Node(*it);
        current = current->next;
    }
    tail = current;
}

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

    if (m_size == 0)
        return true;

    Ptr current = this->head, *other = rhs.head;
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
            if (!other->next)
                head = other;
        }
    }
    return *this;
}

template <typename T>
void LinkedList<T>::push(const T &a)
{
    Ptr new_node = new Node<T>(a);
    std::size_t index = 0;
    if (!head)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        Ptr current = head;
        while (current->next)
            current = current->next;
        current->next = new_node;
        tail = new_node;
    }
    m_size++;
}

template <typename T>
void LinkedList<T>::push_at(const T &a, std::size_t index)
{
    if (index > this->m_size) // Too large index
        throw std::out_of_range("LL::Out of range.\n");
    if (index == 0)
    {
        Ptr new_head = new Node<T>(a);
        new_head->next = head;
        head = new_head;
        if (m_size == 0)
            tail = head;
        m_size++;
        return;
    }
    Ptr current = head;
    while (index > 1)
    {
        current = current->next;
        index--;
    }
    Ptr temp = current->next;
    current->next = new Node<T>(a);
    current = current->next;
    current->next = temp;
    m_size++;
}

template <typename T>
void LinkedList<T>::pop_front()
{
    if (head == tail)
    {
        pop_back();
        return;
    }
    Ptr begin = head;
    while (begin->next != tail)
        begin = begin->next;
    delete tail;
    tail = begin;
    tail->next = nullptr;
    m_size--;
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if (head == tail)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
        m_size--;
        return;
    }
    Ptr temp = head;
    head = head->next;
    delete temp;
    m_size--;
}

template <typename T>
void LinkedList<T>::erase(std::size_t pos)
{
    // Check if the passed position is within the list
    if (pos >= m_size)
        throw std::out_of_range("LL::Out of range.\n");

    if (pos == 0)
        pop_back();
    if (pos == m_size - 1)
        pop_front();

    Ptr begin = this->head;
    // This loop sets 'begin' to the elemnt before the one we need to erase
    while (pos-- > 1)
        begin = begin->next;

    // This needs to be erased
    Ptr temp = begin->next;
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

    Ptr begin = head;
    while (pos-- != 0)
        begin = begin->next;
    return begin->key;
}

template <typename T>
T &LinkedList<T>::back()
{
    if (tail)
        return tail->key;
    throw std::out_of_range("List is empty");
}

template <typename T>
const T &LinkedList<T>::back() const
{
    if (tail)
        return tail->key;
    throw std::out_of_range("LL::List is empty.");
}

template <typename T>
T &LinkedList<T>::front()
{
    if (head)
        return head->key;
    throw std::out_of_range("LL::List is empty.");
}

template <typename T>
const T &LinkedList<T>::front() const
{
    if (head)
        return head->key;
    throw std::out_of_range("LL::List is empty.");
}

template <typename T>
std::size_t LinkedList<T>::size() const noexcept
{
    return m_size;
}

template <typename T>
bool LinkedList<T>::empty() const noexcept
{
    return (size == 0);
}

template <typename T>
void LinkedList<T>::clear() noexcept
{
    while (head)
    {
        Ptr temp = head->next;
        delete head;
        head = temp;
    }
    tail = nullptr;
    head = nullptr;
    m_size = 0;
}

template <typename T>
void LinkedList<T>::sort()
{
    // If the list has 0 or 1 elements, it's already sorted
    if (m_size == 0 || m_size == 1)
        return;

    merge_sort(&head);

    //Fix size and tail
    m_size = 1;
    Ptr current = head;
    while (current->next) {
        m_size++;
        current = current->next;
    }
    tail = current;
}

template <typename T>
void LinkedList<T>::reverse() noexcept
{
    Ptr prev = nullptr;
    Ptr current = head;
    Ptr next = nullptr;
    while (current)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    tail = head;
    head = prev;
}

template <typename T>
void LinkedList<T>::merge(const LinkedList<T> &other)
{
    for (auto i : other)
    {
        tail->next = new Node(i);
        tail = tail->next;
    }
    m_size += other.m_size;
}

template <typename T>
void LinkedList<T>::remove(const T &val)
{
    Ptr current = head;
    Ptr prev = nullptr;

    while (current)
    {
        if (current->key == val)
        {
            if (prev == nullptr)
                head = current->next;
            else
                prev->next = current->next;

            if (current == tail)
                tail = prev;

            delete current;
            current = nullptr;
            m_size--;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

template <typename T>
void LinkedList<T>::remove_if(std::function<bool(const T &)> condition)
{
    Ptr current = head;
    Ptr prev = nullptr;

    while (current)
    {
        if (condition(current->key))
        {
            if (!prev)
                head = current->next;
            else
                prev->next = current->next;

            if (current == tail)
                tail = prev;

            delete current;
            current = nullptr;
            m_size--;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() noexcept
{
    return Iterator(head);
}

template <typename T>
typename LinkedList<T>::cIterator LinkedList<T>::begin() const noexcept
{
    return cIterator(head);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() noexcept
{
    return Iterator(nullptr);
}

template <typename T>
typename LinkedList<T>::cIterator LinkedList<T>::end() const noexcept
{
    return cIterator(nullptr);
}

template <typename T>
void LinkedList<T>::merge_sort(Ptr *source)
{
    Ptr head_ref = *source;
    Ptr left, right;

    // If the list has <= 2 elements, break recursion
    if (!head_ref || !head_ref->next)
        return;
    split(head_ref, &left, &right);

    merge_sort(&left);
    merge_sort(&right);

    *source = m_merge(left, right);
}

template <typename T>
void LinkedList<T>::split(Ptr source, Ptr *front, Ptr *back)
{
    if (source == nullptr || source->next == nullptr)
    {
        *front = source;
        *back = nullptr;
        return;
    }

    Ptr slow = source;
    Ptr fast = source->next;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

template <typename T>
LinkedList<T>::Node<T> *LinkedList<T>::m_merge(Ptr left, Ptr right)
{
    Ptr result = nullptr;
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->key <= right->key)
    {
        result = left;
        result->next = m_merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = m_merge(left, right->next);
    }

    return result;
}