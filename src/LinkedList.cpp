#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

#include <cstddef>
#include <stdexcept>
#include <initializer_list>
#include <functional>

template <typename T>
class LinkedList
{
private:
    template<typename G>
    struct Node
    {
                        Node(G key) : key(key), next(nullptr){};
                        G key;
                        Node<G> *next;
    };
using Ptr               = Node<T>*;

public:
                        LinkedList() noexcept;
                        LinkedList(const LinkedList<T> &rhs);
                        LinkedList(LinkedList&& rhs) noexcept;
                        LinkedList(std::initializer_list<T> list);
                        ~LinkedList();

    bool                operator==(const LinkedList<T> &rhs) const;

    LinkedList<T> &     operator=(const LinkedList<T> &rhs);
    void                push(const T& a);
    void                pop_front();
    void                pop_back();
    void                push_at(const T &a, std::size_t index = 0);

    void                erase(std::size_t pos);
    const T &           get(unsigned pos) const;
    void                clear() noexcept;

    T &                 front();
    const T&            front() const;

    T &                 back();
    const T&            back() const;

    std::size_t         size() const noexcept;
    bool                empty() const noexcept;
    void                sort();
    void                reverse() noexcept;
    void                remove(const T& val);
    void                remove_if(std::function<bool(const T&)> condition);
    

    struct Iterator
    {
    public:
                        Iterator() : current(nullptr) {};
                        Iterator(Ptr current) : current(current) {};
        bool            operator==(const Iterator &rhs);
        bool            operator!=(const Iterator &rhs);

        T &             operator*() const;
        Iterator &      operator++();
        Iterator        operator++(int);

    private:
        Ptr             current;
    };

    struct cIterator{
                        cIterator() : current(nullptr) {};
                        cIterator(Ptr current) : current(current) {};

        bool            operator==(const cIterator& rhs);
        bool            operator!=(const cIterator& rhs);

        const T &       operator*() const;
        cIterator &     operator++();
        cIterator       operator++(int);

    private:
        Ptr             current;
    };

    Iterator            begin() noexcept;
    cIterator           begin() const noexcept;

    Iterator            end() noexcept;
    cIterator           end() const noexcept;


private:
    Ptr                 head;
    Ptr                 tail;
    std::size_t         m_size;
};

#include "LinkedList.inl"
#include "Iterator.inl"

#endif // LINKED_LIST_H