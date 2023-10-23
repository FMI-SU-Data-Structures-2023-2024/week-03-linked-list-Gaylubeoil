#include <cstddef>

template <class T>
class LinkedList {
    private:
        template <class G>
        struct Node {
            G key;
            Node<G>* next;
            Node(G key) : key(key), next(nullptr){};
        };
        Node<T>* front;
        size_t size;
    public:
        LinkedList() {
        };
        ~LinkedList() {
        };
        LinkedList(const LinkedList<T>& other) {
        };
        bool operator==(const LinkedList<T>& other) const {
        }
        LinkedList<T>& operator=(const LinkedList<T>& other) {
        }
        void insertAtPos(T a, std::size_t pos = 0) {
        }
        void removeAtPos(std::size_t pos) {
        }
        const T& getElementAtPos(unsigned pos) {
        }
        T& top() const {
        }
		std::size_t getSize() {
            return -1;
		}
        void sort() { // sort based on operator <
        }
		struct Iterator { // can this be also class?
			Iterator() : current(nullptr) {};
			Iterator(Node<T>* _current) : current(_current){};
			friend bool operator==(const Iterator& a, const Iterator& b) {
				return a.current == b.current;
			}
			friend bool operator!=(const Iterator& a, const Iterator& b) {
				return a.current != b.current;
			}
			T& operator*() const {}
			Iterator& operator++() {}
			Iterator operator++(int) {}
		private:
			Node<T>* current;
		};
		Iterator begin() {return Iterator();}
		Iterator end() {return Iterator();} // is there a way to know this value?
};
