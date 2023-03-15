#include "pch.h"
#include <gtest/gtest.h>
#include "TTT.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;


TEST(TicTacToe, TestValidIndexChecker) {
    vector<string> board{ "0", "1", "2", "3", "4", "5", "6", "7", "8" };

    EXPECT_TRUE(validIndexChecker(9, board));
    EXPECT_TRUE(validIndexChecker(-1, board));
    EXPECT_FALSE(validIndexChecker(0, board));
    EXPECT_FALSE(validIndexChecker(2, board));
    EXPECT_FALSE(validIndexChecker(8, board));
}

TEST(TicTacToe, TestCheckWin) {
    vector<string> board1{  "X", "X", "X", "X", "O", "O","O", "X", "O" };
    vector<string> board2{ "O", "O", "X", "O", "O", "O", "O", "X", "X" };
    vector<string> board3{ "O", "X", "X", "X", "O", "O", "X", "X", "X" };
    vector<string> board4{ "O", "X", "X", "X", "O", "X", "X", "O", "X" };
    vector<string> board5{ "O", "X", "X", "X", "O", "X", "X", "O", "X" };
    vector<string> board6{ "O", "X", "O", "O", "O", "X", "O", "O", "X" };

    EXPECT_TRUE(checkWin(board1));
    EXPECT_TRUE(checkWin(board2));
    EXPECT_TRUE(checkWin(board3));
    EXPECT_TRUE(checkWin(board4));
    EXPECT_TRUE(checkWin(board5));
    EXPECT_TRUE(checkWin(board6));
}

TEST(TicTacToe, TestCheckDraw) {
    EXPECT_FALSE(checkDraw(0));
    EXPECT_FALSE(checkDraw(5));
    EXPECT_TRUE(checkDraw(9));
}



