#include <iostream>
#include <vector>
#include "LinkedList.cpp"

template <typename T>
void print(const LinkedList<T> &list)
{
	for (std::size_t i = 0; i < list.size(); ++i)
		std::cout << list.get(i) << ' ';
	std::cout << std::endl;
}

template <typename T>
void print_iteratively(LinkedList<T> &list)
{
	for (typename LinkedList<T>::Iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void a()
{
	std::cout << std::endl;
}

int main()
{
	LinkedList<int> list;
	list.push(1);
	list.push(3);
	list.push(4);
	list.push_at(2, 1);
	list.push_at(0, 0);
	list.push(5); // 0,1,2,3,4,5; size = 6

	// print(list);
	// std::cout << std::endl;
	// print_iteratively(list);

	list.pop_front();

	std::cout << list.front(); // tail

	return 0;
}
