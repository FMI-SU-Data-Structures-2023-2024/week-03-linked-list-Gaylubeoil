cmake_minimum_required (VERSION 3.13)

PROJECT("Week 3: Linked List" )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Library target for the solution
add_library(solution STATIC)

target_sources(
	solution
	PRIVATE
		src/LinkedList.cpp
)


# Executable target for the application
add_executable(checker)

target_link_libraries(
	checker
	PRIVATE
		solution
		Catch2::Catch2WithMain
)

target_sources(
	checker
	PRIVATE
		src/application.cpp
)


#
# Make Catch2 available. For more information check
# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md
#
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG      v3.4.0)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)


# Executable target for the unit tests
add_executable(testing)

target_link_libraries(
	testing
	PRIVATE
		solution
		Catch2::Catch2WithMain
)

target_include_directories(testing PRIVATE "src")

target_sources(
	testing
	PRIVATE
		test/solution.cpp
)


# Automatically register all tests
include(CTest)
include(Catch)
catch_discover_tests(testing)
