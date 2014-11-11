//
//  main.cpp
//  Pascal's_Triangle
//
//  Created by liaogang on 14/11/11.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Given numRows, generate the first numRows of Pascal's triangle.
 
 For example, given numRows = 5,
 Return
 
 [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]

 */


#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows)
{
    vector<vector<int>> result;
    
    //row 0
    if (numRows >= 1)
    {
        vector<int> row0({1});
        result.push_back(row0);
    }
    
    //row 1 ~ row numRows-1
    for (int row = 1; row < numRows; row++)
    {
        vector<int> vecRow;
        
        int itemsInRow = row+1;
        
        cout<<"row"<<row<<endl;
        
        vector<int> vecRow2 = result[row-1];//row -1
        for (int i = 0; i < itemsInRow ; i++)
        {
            //a(row+1,i) = a(row,i-1) +  a(row,i)
            // a3 = a1 + a2
            
            int a3 = 1;
            
            if (i + 1 != itemsInRow )
            {
            int a1=0;
            if (i-1>=0)
                a1=vecRow2[i-1];
            
            int a2 = vecRow2[i];
                
             a3 = a1 + a2;
            cout<<"a1: "<<a1<<", a2: "<<a2<<", a3: "<<a3 <<endl;
            }
            
            
            
            
            vecRow.push_back( a3 );
        }
        
        result.push_back(vecRow);
    }
    
    
    
    return result;
}


/**
 Pascal's Triangle II
 
 Given an index k, return the kth row of the Pascal's triangle.
 
 For example, given k = 3,
 Return [1,3,3,1].
 
 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 */

vector<int> getRow(int rowIndex)
{
    if (rowIndex == 0)
        return vector<int>();
    
    int r[100];
    int a[100];
    
    //int *r = new int[rowIndex+1]; //r(n)
    //int *a = new int[rowIndex+1]; //r(n-1)
    
    //row 0
    //r[0]=1;
    a[0]=1;
    
    for (int currRow = 1; currRow <= rowIndex; currRow++)
    {
        int itemsInRow = currRow + 1;
        r[0]=1;
        r[itemsInRow-1]=1;
        for (int i = 1; i < itemsInRow -1 ; i++)
        {
            r[i]=a[i-1]+a[i];
        }
        
        memcpy( a, r, sizeof(r[0]) * itemsInRow);
    }
    

    
    vector<int> result( r, r+rowIndex+1);
    return  result;
}

int main(int argc, const char * argv[])
{
    auto result = generate( 2 );
    
    
    auto r = getRow(3);
    r =getRow(4);
    r =getRow(5);
    r =getRow(6);
    
    return 0;
}


