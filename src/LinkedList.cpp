#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

#include <cstddef>
#include <stdexcept>
#include <initializer_list>

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
typedef Node<T>*        Ptr;

public:
                        LinkedList();
                        LinkedList(const LinkedList<T> &rhs);
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

    T &                 front();
    const T&            front() const;

    T &                 back();
    const T&            back() const;

    std::size_t         size() const;
    bool                empty() const;
    void                sort();

    struct Iterator
    {
    public:
                        Iterator() : current(nullptr), prev(nullptr) {};
                        Iterator(Ptr current) : current(current), prev(nullptr) {};
                        Iterator(Ptr current, Ptr prev) : current(current), prev(prev) {};
        bool            operator==(const Iterator &rhs);
        bool            operator!=(const Iterator &rhs);

        //Iterator&       prev();

        T &             operator*() const;
        Iterator &      operator++();
        Iterator        operator++(int);
    private:
        Ptr             current;
        Ptr             prev;
    };

    Iterator            begin();
    Iterator            end();

private:
    void                clear();

private:
    Ptr                 head;
    Ptr                 tail;
    std::size_t         m_size;
};

#include "LinkedList.inl"
#include "Iterator.inl"

#endif // LINKED_LIST_H