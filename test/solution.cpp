#include "catch2/catch_all.hpp"
#include "LinkedList.cpp"
using namespace std;

TEST_CASE("LinkedList adding elements") {
	LinkedList<int> list;

	SECTION("initial size should be zero") {
		REQUIRE(list.getSize() == 0);
	}

	SECTION("adding element should increase the size") {
		list.insertAtPos(1, 0);
		REQUIRE(list.getSize() == 1);
	}

	SECTION("adding element should increase the size") {
		list.insertAtPos(1, 0);
		CHECK(list.getSize() == 1);
		list.insertAtPos(2, 0);
		CHECK(list.getSize() == 2);
		list.insertAtPos(12, 1);
		CHECK(list.getElementAtPos(1) == 12);	
	}
	SECTION("Adding of element out of range should throw out of range error") {
		REQUIRE_THROWS_AS(list.insertAtPos(10, 10), std::out_of_range);
	}
}

TEST_CASE("LinkedList getting elements") {
	LinkedList<int> list;
	list.insertAtPos(1, 0);
	list.insertAtPos(10, 0);
	list.insertAtPos(100, 0);
	list.insertAtPos(1000, 0);
	
	list.insertAtPos(15, 1);
	list.insertAtPos(16, 2);

	SECTION("non exising position should throw out of rance") {
		REQUIRE_THROWS_AS(list.getElementAtPos(100), std::out_of_range);
	}
	SECTION("adding element should increase the size") {
		CHECK(list.getElementAtPos(0) == 1000);
		CHECK(list.getElementAtPos(1) == 15);
		CHECK(list.getElementAtPos(2) == 16);
		CHECK(list.getElementAtPos(3) == 100);
		CHECK(list.getElementAtPos(4) == 10);
		CHECK(list.getElementAtPos(5) == 1);
	}
}

TEST_CASE("LinkedList removing elements") {
	LinkedList<int> list;
	list.insertAtPos(1, 0);
	list.insertAtPos(10, 0);
	list.insertAtPos(100, 0);
	list.insertAtPos(1000, 0);
	
	list.insertAtPos(15, 1);
	list.insertAtPos(16, 2);

	SECTION("non exising position should throw out of rance") {
		REQUIRE_THROWS_AS(list.removeAtPos(100), std::out_of_range);
	}

	SECTION("removing element should decrease the size and move the position of the next elements") {
		list.removeAtPos(4);
		CHECK(list.getElementAtPos(4) == 1);
	}
	// Add operator =, iter... for homework...
	
}
