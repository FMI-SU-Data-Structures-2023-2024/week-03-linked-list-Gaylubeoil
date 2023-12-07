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

#include <list>
int main()
{
	LinkedList<int> mlist{1, 2, 3, 4, 5, 6, 7, 8, 9};

	mlist.reverse();
	print_iteratively(mlist);
	mlist.remove(1);
	print_iteratively(mlist);
	mlist.erase(1);
	print_iteratively(mlist);
	mlist.pop_back();
	print_iteratively(mlist);
	mlist.pop_front();
	print_iteratively(mlist);
	mlist.remove_if([](int val)
					{ return (val == 5); });
	print_iteratively(mlist);
	mlist.push(99);
	print_iteratively(mlist);
	std::cout << mlist.size() << std::endl;

	return 0;
}
