//
//  main.cpp
//  Insert Interval
//
//  Created by liaogang on 14/12/29.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"


/**
 Insert Interval
 
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */


void midFind(vector<Interval> &A,int low,int high,int target,int &left,int &right)
{
    int len =(int)A.size();

    if (A.front().start > target)
    {
        left=-1;
        right=-1;
        return;
    }
    else if(A.back().end < target)
    {
        left=len;
        right=len;
        return;
    }
    else
    {
        while (low <= high)
        {
            int mid = ( low + high ) / 2;
            
            Interval tmp = A[mid];
            
            if (tmp.start > target )
            {
                right=mid;
                high = mid -1;
            }
            else if(tmp.start <= target)
            {
                if (tmp.end >= target)
                {
                    left=right=mid;
                    break;
                }
             
                left=mid;
                low = mid +1;
            }
        }
        
    }
 


}


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
    int len =(int)intervals.size();
    if (len == 0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    
    
    
    int startLeft;
    int startRight;
    int endLeft;
    int endRight;
    int target;
    
    int low = 0;
    int high= len -1;
    target=newInterval.start;
    midFind(intervals , low , high,  target, startLeft, startRight);
    //printf("left: %d,right: %d\n",startLeft,startRight);
    
    high = len -1;
    target=newInterval.end;
    midFind(intervals, low , high , target, endLeft, endRight);
    //printf("left: %d,right: %d\n",endLeft,endRight);
    
    
    int eraseBeg = 0;
    int eraseEnd = 0;
    if (startLeft == startRight ) {
        if( startLeft >= 0 && startLeft < len)
            newInterval.start = intervals[startLeft].start;
        
        eraseBeg = startLeft;
        
        if (eraseBeg == -1)
            eraseBeg = 0;
    }
    else
    {
        eraseBeg = startRight;
    }
    
    
    eraseEnd= endLeft;
    if (endLeft == endRight && endLeft < len && endLeft >= 0)
    {
        newInterval.end = intervals[endLeft].end;
    }
   
    
    if (eraseEnd - eraseBeg >= 0)
    {
        auto beg = intervals.begin();
        if (eraseEnd >= len  )
            intervals.erase(beg + eraseBeg, intervals.end());
        else
            intervals.erase(beg + eraseBeg, beg + eraseEnd + 1);
    }
    
    auto beg = intervals.begin();
    intervals.insert( beg + eraseBeg, newInterval);
    
    return intervals;
}


int main(int argc, const char * argv[])
{
//    vector<Interval> test;//({{1,2},{3,4},{5,6},{7,8},{9,10},{11,12},{13,14},{15,16},{17,18} });

    vector<Interval> test({{1,5} });
//    vector<Interval> test({{0,1} ,{5,5} ,{6,7} ,{9,11} ,{12,21} });
    Interval n(6,8);
    auto out = insert(test, n);
    
    printfIntervals(out);
    
    return 0;
}

