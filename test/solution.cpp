#include "catch2/catch_all.hpp"
#include "LinkedList.cpp"
using namespace std;

TEST_CASE("LinkedList adding elements")
{
	LinkedList<int> list;

	SECTION("initial size should be zero")
	{
		REQUIRE(list.size() == 0);
	}

	SECTION("adding element should increase the size")
	{
		list.push_at(1);
		REQUIRE(list.size() == 1);
	}

	SECTION("adding element should increase the size")
	{
		list.push_at(1);
		CHECK(list.size() == 1);
		list.push_at(2);
		CHECK(list.size() == 2);
		list.push_at(12, 1);
		CHECK(list.get(1) == 12);
	}
	SECTION("Adding of element out of range should throw out of range error")
	{
		REQUIRE_THROWS_AS(list.push_at(10, 10), std::out_of_range);
	}
}

TEST_CASE("LinkedList getting elements")
{
	LinkedList<int> list;
	list.push_at(1, 0);
	list.push_at(10, 0);
	list.push_at(100, 0);
	list.push_at(1000, 0);

	list.push_at(15, 1);
	list.push_at(16, 2);

	SECTION("non exising position should throw out of rance")
	{
		REQUIRE_THROWS_AS(list.get(100), std::out_of_range);
	}
	SECTION("adding element should increase the size")
	{
		CHECK(list.get(0) == 1000);
		CHECK(list.get(1) == 15);
		CHECK(list.get(2) == 16);
		CHECK(list.get(3) == 100);
		CHECK(list.get(4) == 10);
		CHECK(list.get(5) == 1);
	}
}

TEST_CASE("LinkedList removing elements")
{
	LinkedList<int> list;
	list.push_at(1, 0);
	list.push_at(10, 0);
	list.push_at(100, 0);
	list.push_at(1000, 0);

	list.push_at(15, 1);
	list.push_at(16, 2);

	SECTION("non exising position should throw out of rance")
	{
		REQUIRE_THROWS_AS(list.erase(100), std::out_of_range);
	}

	SECTION("removing element should decrease the size and move the position of the next elements")
	{
		list.erase(4);
		CHECK(list.get(4) == 1);
	}
	// Add operator =, iter... for homework...
}