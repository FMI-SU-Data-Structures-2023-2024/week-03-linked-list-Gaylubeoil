#include <iostream>
#include <vector>
#include <list>
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

using ilist = LinkedList<int>;
int main()
{
	ilist list = {4, 3, 2, 1, 0};
	list.sort();
	print_iteratively(list);

	std::cout << list.front() << ' ' << list.back() <<std::endl;

	return 0;
}
