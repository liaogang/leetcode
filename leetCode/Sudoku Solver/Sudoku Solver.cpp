//
//  Sudoku Solver
//
//  Created by liaogang on 15/3/2.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/**
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 
 Empty cells are indicated by the character '.'.
 
 You may assume that there will be only one unique solution.
 */

void solveSudoku(vector<vector<char> > &board)
{
    vector<int> b({-1,-1,-1,-1,-1,-1,-1,-1,-1});
    
    vector<vector<int>> bb;
    
    int i = 9;
    while (i-->0) {
        bb.push_back(b);
    }
    
    
    
    
}

int main(int argc, const char * argv[])
{
    
    vector<vector<char>> board
    {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'},
    };
    
    solveSudoku(board);
    
    
    return 0;
}
