//
//  main.cpp
//  Find Median from Data Stream
//
//  Created by liaogang on 15/12/2.
//  Copyright © 2015年 liaogang. All rights reserved.
//

#include <iostream>

/**
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 Examples:
 
 
 中位数
 就是一排数据从小到大排列后，中间那个数。
 举例说，1，3，6，9，11。中间那个数是6，这就是中位数。1，3，6，9，11，13。这是有六个数，中间是两个数了，那么中位数就是6和9
 
 [2,3,4] , the median is 3
 
 [2,3], the median is (2 + 3) / 2 = 2.5
 
 Design a data structure that supports the following two operations:
 
 void addNum(int num) - Add a integer number from the data stream to the data structure.
 double findMedian() - Return the median of all elements so far.
 
 For example:
 
 add(1)
 add(2)
 findMedian() -> 1.5
 add(3)
 findMedian() -> 2
 
 */

#include "../leetcode.h"
#include <list>


void insertToSortedList(list<int> l,int t)
{
    
}


class MedianFinder {
private:
    int size;
    //有偶数个元素
    bool even;
    list<int> low;
    list<int> high;
public:
    MedianFinder():size(0),even(true)
    {
        
    }
    
    
    
    // Adds a number into the data structure.
    void addNum(int num) {
        
        even=!even;
        size+=1;
        
        if (size == 0) {
            low.push_back(num);
        }
        else if(size == 1)
            high.push_back(num);
        else
        {
            if (even) {
                
            }
            else
            {
                
            }
            
            
        }
        
        

    }
    
    // Returns the median of current data stream
    double findMedian()
    {
        if (size == 0)
        {
            return 0.0;
        }
        else
        {
            if (even == true) {
               //return  middle value
                return  (datas[size/2-1] + datas[size/2])/ 2.0;
            }
            else
            {
                //return the middle one in the list

                return datas[ (size+1)/2 - 1];
            }
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();


int main(int argc, const char * argv[]) {
    
    
    MedianFinder mf;
    mf.addNum(6);
    printf("%f\n", mf.findMedian() );
    mf.addNum(10);
    printf("%f\n", mf.findMedian() );
    mf.addNum(2);
    printf("%f\n", mf.findMedian() );
    
    /*
    mf.addNum(-4);
    mf.findMedian();
    mf.addNum(-5);
    mf.findMedian();
    */
    
    
    
    return 0;
}
