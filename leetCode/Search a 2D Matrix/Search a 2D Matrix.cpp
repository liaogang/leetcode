//
//  main.cpp
//  Search a 2D Matrix
//
//  Created by liaogang on 14/12/25.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
/**
 Search a 2D Matrix
 
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 
 For example,
 
 Consider the following matrix:
 
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 
 Given target = 3, return true.
 */

#include <vector>
using namespace std;

#include "../../leetcode.h"


bool searchMatrixRow(MatrixRow &row,int target)
{
    int s = (int)row.size();
    
    if (s == 0 ) {
        return false;
    }
    else if ( s == 1)
    {
        return target == row.front();
    }
    else
    {
        int beg = 0;
        int end = s;
        
        while (1)
        {
            int i = (end + beg)/2;
            int cmp = row[i] - target;
            
            if(cmp == 0 )
                return true;
            
            
            if ( cmp > 0)
                end = i;
            else
                beg = i;
            
            if( end == beg || end == beg + 1)
                return false;
            
        }
        
    }
    
}


bool searchMatrix(Matrix &matrix, int target)
{
    auto high = matrix.end()-1;
    auto low = matrix.begin();
    while ( low <= high)
    {
        auto mid = (high - low ) /2 + low;
        
        MatrixRow row = *mid;
        
        int rowEnd = row.back();
        int rowBeg = row.front();
        if ( rowBeg >= target )
        {
            if (rowBeg == target) return true;
            high = mid - 1;
        }
        else if ( rowEnd <= target)
        {
            if (rowEnd == target) return true;
            low = mid + 1;
        }
        else
        {
            return searchMatrixRow(row,target);
        }
        
    }
    
    return false;
}

int main(int argc, const char * argv[])
{
    Matrix test;
    test.push_back({1,   3,  5,  7});
    test.push_back({ 10, 11, 16, 20});
    test.push_back({ 23, 30, 34, 50});
    
    printf("%d\n", searchMatrix( test , 50) );
    
    return 0;
}
