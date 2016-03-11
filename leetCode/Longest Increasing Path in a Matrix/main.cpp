//
//  main.cpp
//  Longest Increasing Path in a Matrix
//
//  Created by liaogang on 16/2/18.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"
#include <stack>

/**
 Given an integer matrix, find the length of the longest increasing path.
 
 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 
 Example 1:
 
 nums = [
 [9,9,4],
 [6,6,8],
 [2,1,1]
 ]
 
 Return 4
 The longest increasing path is [1, 2, 6, 9].
 
 Example 2:
 
 nums = [
 [3,4,5],
 [3,2,6],
 [2,2,1]
 ]
 
 Return 4
 The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 

 
 #Tag:
 Topological Sort 拓扑排序
 Memoization 记忆 
 Depth-first Search 深度优先搜索
 */

struct MatrixPoint
{
    int x;
    int y;
    MatrixPoint(int x_,int y_):x(x_),y(y_)
    {
    }
};

class Solution {
public:
    
    
    /**
     深度优先搜索
     @link https://zh.wikipedia.org/wiki/%E6%B7%B1%E5%BA%A6%E4%BC%98%E5%85%88%E6%90%9C%E7%B4%A2
     */
    int findAPath( vector<vector<int>>& matrix , int column,int row)
    {
        cout<<"findAPath , start from: column,row "<< column << ","<< row <<endl;
        
        int columns = matrix.front().size();
        int rows = matrix.size();
        
        stack<MatrixPoint> unvisited;
        unvisited.push(MatrixPoint(row,column));
        int length = 1;
        int lengthMax = 0;
        while (!unvisited.empty()) {
            MatrixPoint mp = unvisited.top();
            unvisited.pop();
            
            
            int v =matrix[mp.y][mp.x];
            int unvisitedLength = unvisited.size();
            
            //left
            if (mp.x != 0) {
                int v2 = matrix[mp.y][mp.x-1];
                if ( v2 > v ) {
                    unvisited.push(MatrixPoint(mp.x-1,mp.y) );
                }
            }
            
            //right
            if (mp.x != columns - 1) {
                int v2 = matrix[mp.y][mp.x+1];
                if ( v2 > v ) {
                    unvisited.push( MatrixPoint(mp.x+1,mp.y) );
                }
            }
            
            //up
            if (mp.y != 0) {
                int v2 = matrix[mp.y-1][mp.x];
                if ( v2 > v ) {
                    unvisited.push( MatrixPoint(mp.x,mp.y - 1) );
                }
            }
            
            //down
            if (mp.y != rows - 1) {
                int v2 = matrix[mp.y+1][mp.x];
                if ( v2 > v ) {
                    unvisited.push( MatrixPoint(mp.x,mp.y + 1) );
                }
            }
            
            

            cout<< v <<endl;
            if (unvisited.size() != unvisitedLength) {
                length++;
                cout<<"length++"<<length<<endl;
            }
            else
            {
                // find a path ended
                cout<< "find a path ended" << length  <<endl;
                
                if (length>lengthMax) {
                    lengthMax = length;
                }
                
                length--;
                cout<<"length--"<<length<<endl;
            }
            
        }
        
        return lengthMax;
    }
    
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int columns = matrix.front().size();
        int rows = matrix.size();
        
        int cells = columns * rows;
        int *mMark = new int[ cells ];
        memset(mMark, 0, cells * sizeof(mMark[0]));
        
        findAPath(matrix, 2, 2);
        
        int lengthMax = 0;
        
        int i = 0;
        for (auto itColumn = matrix.begin(); itColumn != matrix.end(); itColumn++,i++) {
            vector<int> row = *itColumn;
            
            int j = 0;
            for (auto itRow = row.begin(); itRow != row.end(); itRow++,j++) {
                
                if (mMark[columns*i + j ] == 1) {
                    // this cell is marked
                }
                else{
                    int length = findAPath( matrix , i ,j );
                    if (lengthMax < length) {
                        lengthMax = length;
                    }
                }
            }
            
        }
        
        
        
        return lengthMax;
    }
};


int main(int argc, const char * argv[]) {
    
    {
    vector<vector<int>> matrix;
    
    matrix.push_back( vector<int>({9,9,4}) );
    matrix.push_back( vector<int>({6,6,8}) );
    matrix.push_back( vector<int>({2,2,1}) );
    
    Solution a;
    int l = a.longestIncreasingPath(matrix);
    
    cout<<"longestIncreasingPath"<<l<<endl;
        
        // Return 4
       // The longest increasing path is [1, 2, 6, 9].
    }
    
    
    
    
    {
    vector<vector<int>> matrix;
       
    matrix.push_back( vector<int>({3,4,5}) );
    matrix.push_back( vector<int>({3,2,6}) );
    matrix.push_back( vector<int>({2,2,1}) );
    
    Solution a;
    int l = a.longestIncreasingPath(matrix);
    
    cout<<"longestIncreasingPath"<<l<<endl;
        
//        Return 4
//        The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
        
        
    }
    return 0;
}


