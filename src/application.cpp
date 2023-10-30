#include <iostream>
#include "LinkedList.cpp"

template <typename T>
void print(const LinkedList<T> &list)
{
	for (std::size_t i = 0; i < list.size(); ++i)
		std::cout << list.get(i) << ' ';
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
	list.push(55);

	print(list);

	return 0;
}
