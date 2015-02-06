//
//  main.cpp
//  Word Search
//
//  Created by liaogang on 14/12/25.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
/**
 Word Search
 
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 For example,
 Given board =
 [
    ["ABCE"],
    ["SFCS"],
    ["ADEE"]
 ]
 
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
 
 */


#include <vector>
#include <string>
using namespace std;

typedef vector<int> BoardRow;
typedef vector<BoardRow> Board;


bool dfs(Board &board ,int boardX , int boardY, string &word, int wordIndex)
{

    char target = word[wordIndex];
    
    BoardRow row = board[boardY];
    
    bool endReached = wordIndex == word.length() - 1;
    if (endReached)
        return true;
    
    
    if (row[boardX] == target)
    {
        /// search next.
        
        // left
        if (boardX -1>0) {
            dfs(board, , boardX -1,boardY,  word, wordIndex);
        }
        
        
    }
    else
    {
        return false;
    }
    

    
    
    
    
    
    return false;
}


bool exist(Board &board, string word)
{
    int wordLen = (int)word.length();
    if (wordLen == 0)
        return true;
    
    
    auto end = board.end();
    for ( auto i = board.begin(); i != end; i++)
    {
        BoardRow row = *i;
        
        auto end = row.end();
        for (auto j = row.begin(); j != end; j ++)
        {
            char wordA = word.front();
            char rowc = row[j];
            
            if (wordA == rowc)
                if (dfs(board, 0, 0, word, 0))
                    return true;
        }
    }
    
    
    return false;
}

int main(int argc, const char * argv[])
{
    Board board;
    board.push_back({{"ABCE"}});
    board.push_back({{"SFCS"}});
    board.push_back({{"ADEE"}});
    
    printf("%d\n", exist(board, "ABCCED"));
    printf("%d\n", exist(board, "SEE"));
    printf("%d\n", exist(board, "ABCB"));
    
    
    return 0;
}
