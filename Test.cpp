#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace ariel;

Board board;

TEST_CASE("General tests")
{
    Board testBoard;

    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Vertical, "Hello"));
    CHECK_NOTHROW(testBoard.post(5, 5, Direction::Vertical, "Hello"));
    CHECK_NOTHROW(testBoard.post(5, 0, Direction::Vertical, "Hello World"));
    CHECK_NOTHROW(testBoard.post(0, 5, Direction::Horizontal, "Hello 2"));
    CHECK_NOTHROW(testBoard.post(0, 100, Direction::Horizontal, "Hello test"));
    CHECK_NOTHROW(testBoard.read(0, 0, Direction::Vertical, 5));
    CHECK_NOTHROW(testBoard.read(5, 5, Direction::Vertical, 5));
    CHECK_NOTHROW(testBoard.read(5, 0, Direction::Vertical, 11));
    CHECK_NOTHROW(testBoard.read(0, 5, Direction::Horizontal, 3));
    CHECK_NOTHROW(testBoard.read(0, 100, Direction::Horizontal, 2));

    CHECK_NOTHROW(testBoard.post(UINT_MAX, 0, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.read(0, UINT_MAX, Direction::Horizontal, 5));

    CHECK_NOTHROW(testBoard.read(0, 0, Direction::Horizontal, 5));
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Horizontal, "Hello"));
    CHECK_NOTHROW(testBoard.read(30, 24, Direction::Horizontal, 5));
}

TEST_CASE("Simple post+read")
{
    board.post(0, 1, Direction::Horizontal, "hello");
    CHECK(board.read(0, 1, Direction::Horizontal, 5) == "hello");

    board.post(10, 0, Direction::Vertical, "check");
    CHECK(board.read(10, 0, Direction::Vertical, 5) == "check");

    board.post(0, 6, Direction::Horizontal, "hello1");
    CHECK(board.read(0, 6, Direction::Horizontal, 6) == "hello1");

    board.post(1, 0, Direction::Vertical, "check mate");
    CHECK(board.read(1, 0, Direction::Vertical, 10) == "check mate");

    board.post(1, 1, Direction::Horizontal, "hello2");
    CHECK(board.read(1, 1, Direction::Horizontal, 6) == "hello2");

    board.post(1, 6, Direction::Vertical, "check");
    CHECK(board.read(1, 6, Direction::Vertical, 5) == "check");

    board.post(2, 3, Direction::Horizontal, "check");
    CHECK(board.read(2, 3, Direction::Horizontal, 5) == "check");

    board.post(51, 40, Direction::Vertical, "check");
    CHECK(board.read(51, 40, Direction::Vertical, 5) == "check");
}

TEST_CASE("overwrite posts")
{
    board.post(39, 40, Direction::Vertical, "check2");
    CHECK(board.read(39, 40, Direction::Vertical, 5) == "check");
    CHECK(board.read(40, 40, Direction::Vertical, 5) == "heck2");

    board.post(0, 0, Direction::Horizontal, "check3");
    CHECK(board.read(0, 0, Direction::Horizontal, 6) == "check3"); 

    board.post(0, 2, Direction::Horizontal, "test10");
    CHECK(board.read(0, 2, Direction::Horizontal, 6) == "test10"); 

    board.post(3, 0, Direction::Vertical, "check4");
    CHECK(board.read(3, 0, Direction::Vertical, 6) == "check4"); 

    board.post(2, 2, Direction::Horizontal, "check5");
    CHECK(board.read(2, 2, Direction::Horizontal, 6) == "check5"); 

    board.post(3, 8, Direction::Vertical, "hello");
    CHECK(board.read(3, 8, Direction::Vertical, 5) == "hello");
}