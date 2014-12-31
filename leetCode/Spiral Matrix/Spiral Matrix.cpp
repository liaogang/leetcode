//
//  main.cpp
//  Spiral Matrix
//
//  Created by liaogang on 14/12/31.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>

#include "../../leetcode.h"

/**
    Spiral Matrix
    
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 
 You should return [1,2,3,6,9,8,7,4,5].
 */



template <typename T>
T * StartOf( std::vector <T> & v ) {
    return &v[0];
}

vector<int> spiralOrder(Matrix &matrix)
{
    int mHeight =(int) matrix.size();
    
    
    if (mHeight == 0)
        return vector<int>();
    
    
    int mWidth = (int) matrix.begin()->size();
    
    int area = mWidth * mHeight;
    
//    int *result = new int[area];
    int result[100] = {0};
    
    int resultPt = 0;
    
    int left=0;
    int top=0;
    int right =mWidth-1;
    int bottom=mHeight-1;
    
    for( ; left<=right && top <= bottom; left+=1,right-=1,top+=1,bottom-=1)
    {
        int currWidth = right - left + 1;
        
        // top
        memcpy( result + resultPt, StartOf(*(matrix.begin() + top) ) + left, currWidth* sizeof(int));
        resultPt+=currWidth;
        
        //right
        for (int i = top + 1 ; i <= bottom -1 ; i++)
        {
            result[resultPt++] = matrix[i][right];
        }
        
        // bottom
        if(bottom == top)
        {
            bottom--;
        }
        else
        {
            auto itRow = matrix.begin() + bottom;
            reverse( itRow->begin() + left + 1, itRow->begin() + bottom -1);
            
            memcpy( result + resultPt , StartOf( *itRow ) + left, currWidth* sizeof(int));
            resultPt+=currWidth;
        }
        
        // left
        if (left == right)
        {
            left++;
        }
        else
        {
            for (int i = bottom -1 ; i >= top + 1; i--)
            {
                result[resultPt++] = matrix[i][left];
            }
        }
    }
    
    
    vector<int> vecResult (result , result + area);
    return vecResult;
}

int main(int argc, const char * argv[])
{
//    Matrix ma({ {1,2,3},{4,5,6},{7,8,9} });
//    Matrix ma({ {2,3} });
//    Matrix ma({ {2},{3} });
    
//    Matrix ma({  });
    Matrix ma({ {1},{2},{3},{4},{5},{6},{7},{8},{9},{10} });

    printContainer( spiralOrder(ma) );
    
    return 0;
}
