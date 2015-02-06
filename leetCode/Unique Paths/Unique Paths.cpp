//
//  main.cpp
//  Unique Paths
//
//  Created by liaogang on 15/2/6.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"
#include <math.h>

/**
 Unique Paths
 
 
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 
 How many possible unique paths are there?
 
 http://leetcode.com/wp-content/uploads/2014/12/robot_maze.png
 
 Above is a 3 x 7 grid. How many possible unique paths are there?
 
 Note: m and n will be at most 100.
 
 */

int uniquePaths3(int m, int n)
{
    if (m <= n) {
        int tmp = m;
        m = n;
        n = tmp;
    }
    return C ( m + n - 2, m -1 );
}


int uniquePaths2(int m, int n)
{
    cout<<m<<": ";
    
    int len = m + n -2;
    
    int sum =
    A( len ,2) - (A( len -(m-1) , 2 ) +1) - ( A ( len - (n - 1) , 2) + 0 );
    
    
    return sum;
}

#include <map>


map< pair<int, int> , int> result;

int uniquePaths(int m, int n)
{
    if (m <= n) {
        int tmp = m;
        m = n;
        n = tmp;
    }

    pair<int, int> pa (m,n);
    if (result.find( pa )!= result.end()) {
        return  result[ pa];
    }
    
    if (m == 1 || n == 1)
        return 1;
    
    if (m == 2 )
        return n;
    
    if ( n  == 2)
        return m;
    
    
    int sum = 0;
    
    int i = m ;
    while ( i-- >= 2 ) {
        sum += uniquePaths( i , n -1 );
    }
    
    i = n ;
    while ( i-- >= 2 ) {
        sum += uniquePaths( m -1 , i);
    }
    
    result[ pa] = sum;
    
    return sum;
}

int main(int argc, const char * argv[])
{
    cout<< uniquePaths(1, 1) <<endl; // ==> 1
    cout<< uniquePaths(2, 2) <<endl; // ==> 2
    cout<< uniquePaths(3, 3) <<endl; // ==> 6
    
    cout<< uniquePaths(4, 4) <<endl; // ==> 20
    cout<< uniquePaths(5, 5) <<endl; // ==> 70
    cout<< uniquePaths(6, 6) <<endl; // ==> 252
    cout<< uniquePaths(7, 7) <<endl; // ==> 924
    cout<< uniquePaths(8, 8) <<endl; // ==> 3432
    cout<< uniquePaths( 51 , 9) <<endl; // ==> 1916797311?  //Time Limit Exceeded
    
    cout<<A(2,2)<<endl;
    
    cout<< uniquePaths2(3, 3) <<endl; // ==> 20
    cout<< uniquePaths2(4, 4) <<endl; // ==> 20
    cout<< uniquePaths2(5, 5) <<endl; // ==> 70
    cout<< uniquePaths2(6, 6) <<endl; // ==> 252
    cout<< uniquePaths2(7, 7) <<endl; // ==> 924
    cout<< uniquePaths2(8, 8) <<endl; // ==> 3432
    cout<<A(4,4)<<endl;
    cout<<A(5,5)<<endl;
    cout<<A(7,7)<<endl;
    cout<<A(8,8)<<endl;
    
    cout << "--------------" << endl;
    
    cout<< uniquePaths3(3, 3) <<endl; // ==> 20
    cout<< uniquePaths3(4, 4) <<endl; // ==> 20
    cout<< uniquePaths3(5, 5) <<endl; // ==> 70
    cout<< uniquePaths3(6, 6) <<endl; // ==> 252
    cout<< uniquePaths3(7, 7) <<endl; // ==> 924
    cout<< uniquePaths3(8, 8) <<endl; // ==> 3432
    cout<< uniquePaths3(51, 9) <<endl; // ==> 3432
    
//    cout<< uniquePaths(2, 4) <<endl; // ==> 2
//    cout<< uniquePaths(3, 4) <<endl; // ==> 6
    
    return 0;
}
