//
//  main.cpp
//  Valid Sudoku
//
//  Created by liaogang on 16/2/16.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"


/**
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 校验独数有效性
 
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 
 
 A partially filled sudoku which is valid.
 
 Note:
 A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 

 */

/**
 There are just 3 rules to Sudoku.
 Each row must have the numbers 1-9 occuring just once.
 Each column must have the numbers 1-9 occuring just once.
 And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
 
 每一行，每一列，每一宫，必须包含1-9全部数字，且无重复
 */


static int asdffill[9];

bool validChar(char ch)
{
    if (ch != '.')
    {
        int c = ch - '1';
        if( 1 == asdffill[c] )
            return false;
        else
            asdffill[c] = true;
    }
    
    return true;
}

bool valid(char a1,char a2,char a3,
           char a4,char a5,char a6,
           char a7,char a8,char a9)
{
    memset(asdffill, 0, sizeof(asdffill[0])*9);
    
    return validChar(a1) && validChar(a2)  && validChar(a3)
     && validChar(a4)  && validChar(a5)  && validChar(a6)
    && validChar(a7)  && validChar(a8)  && validChar(a9);
}


class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board) {
    auto &b = board;
    bool isValid = true;
    
    //按宫遍历
    
    //上三宫
    if(! valid(b[0][0], b[0][1], b[0][2], b[1][0], b[1][1], b[1][2], b[2][0], b[2][1], b[2][2]
               ))
        return false;
       
    if(!valid(b[0][3], b[0][4], b[0][5], b[1][3], b[1][4], b[1][5], b[2][3], b[2][4], b[2][5]
              ))
        return false;
    
   if( !valid(b[0][6], b[0][7], b[0][8],
          b[1][6], b[1][7], b[1][8],
          b[2][6], b[2][7], b[2][8]
             ))return false;

    //中三宫
    if(!valid(b[3][0], b[3][1], b[3][2],
          b[4][0], b[4][1], b[4][2],
          b[5][0], b[5][1], b[5][2]
              ) ) return false;
    
    if(!valid(b[3][3], b[3][4], b[3][5],
          b[4][3], b[4][4], b[4][5],
          b[5][3], b[5][4], b[5][5]
              ))return false;
    
    if(!valid(b[3][6], b[3][7], b[3][8],
          b[4][6], b[4][7], b[4][8],
          b[5][6], b[5][7], b[5][8]
              ))return false;
    
    
    //下三宫
    if(!valid(b[6][0], b[6][1], b[6][2],
          b[7][0], b[7][1], b[7][2],
          b[8][0], b[8][1], b[8][2]
             ))return false;
    
    if(!valid(b[6][3], b[6][4], b[6][5],
          b[7][3], b[7][4], b[7][5],
          b[8][3], b[8][4], b[8][5]
             ))return false;
    
    if(!valid(b[6][6], b[6][7], b[6][8],
          b[7][6], b[7][7], b[7][8],
          b[8][6], b[8][7], b[8][8]
              ))return false;
    
    
    
    //按行遍历
    for (auto row : board)
    {
        isValid =  valid(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]);
        if (!isValid) {
            return false;
        }
    }
    
 
    //按列遍历
    isValid =
    valid(b[0][0], b[1][0], b[2][0], b[3][0], b[4][0], b[5][0], b[6][0], b[7][0], b[8][0])&&
    valid(b[0][1], b[1][1], b[2][1], b[3][1], b[4][1], b[5][1], b[6][1], b[7][1], b[8][1])&&
    valid(b[0][2], b[1][2], b[2][2], b[3][2], b[4][2], b[5][2], b[6][2], b[7][2], b[8][2])&&
    valid(b[0][3], b[1][3], b[2][3], b[3][3], b[4][3], b[5][3], b[6][3], b[7][3], b[8][3])&&
    valid(b[0][4], b[1][4], b[2][4], b[3][4], b[4][4], b[5][4], b[6][4], b[7][4], b[8][4])&&
    valid(b[0][5], b[1][5], b[2][5], b[3][5], b[4][5], b[5][5], b[6][5], b[7][5], b[8][5])&&
    valid(b[0][6], b[1][6], b[2][6], b[3][6], b[4][6], b[5][6], b[6][6], b[7][6], b[8][6])&&
    valid(b[0][7], b[1][7], b[2][7], b[3][7], b[4][7], b[5][7], b[6][7], b[7][7], b[8][7])&&
    valid(b[0][8], b[1][8], b[2][8], b[3][8], b[4][8], b[5][8], b[6][8], b[7][8], b[8][8]);
    
    
    return isValid;
}
};


int main(int argc, const char * argv[]) {

    
    
    
   //["..4...63.",".........","5......9.",
//    "...56....","4.3.....1","...7.....",
//    "...5.....",".........","........."]
    
    vector<vector<char>> board;
    
    char *arr;
    
    
    /*
    arr = ".87654321";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "2........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "3........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "4........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "5........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "6........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "7........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "8........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "9........";
    board.push_back(     vector<char>(arr,arr+9) );
    */
    
    
    

    arr = "......5..";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = ".........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = ".........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "93..2.4..";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "..7...3..";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = ".........";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = "...34....";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = ".....3...";
    board.push_back(     vector<char>(arr,arr+9) );
    arr = ".....52..";
    board.push_back(     vector<char>(arr,arr+9) );
    //==> not valide
    
    
    
    
    Solution s;
   if( s.isValidSudoku(board) )
        printf("is valid\n" );
    else
        printf("is not valid\n" );
    
    return 0;
}

