#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

#include <cstddef>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class LinkedList
{
private:
    template <typename G>
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
    void                push_at(const T &a, std::size_t index = 0);

    void                erase(std::size_t pos);
    const T &           get(unsigned pos) const;

    T &                 top();
    const T&            top() const;

    std::size_t         size() const;
    void                sort();

    struct Iterator
    {
                        Iterator() : current(nullptr){};
                        Iterator(Ptr current) : current(current){};
        friend bool     operator==(const Iterator &a, const Iterator &b)
        {
            return a.ptr == b.ptr; 
        }
        friend bool     operator!=(const Iterator &a, const Iterator &b)
        {
            return !(a == b);
        }

        T &             operator*() const {}
        Iterator &      operator++() {}
        Iterator        operator++(int) {}

    private:
        Ptr             current;
    };

    Iterator            begin() { return Iterator(); }
    Iterator            end() { return Iterator(); }

private:
    void                clear();

private:
    Ptr                 head;
    std::size_t         m_size;
};

#include "LinkedList.inl"

#endif // LINKED_LIST_H