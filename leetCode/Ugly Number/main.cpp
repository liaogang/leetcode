//
//  main.cpp
//  Ugly Number
//
//  Created by liaogang on 16/3/14.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"
#include <assert.h>
#include <deque>

/**
  Ugly Number I
 Write a program to check whether a given number is an ugly number.
 
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 
 Note that 1 is typically treated as an ugly number.
 */


/**
 Ugly Number II
 Write a program to find the n-th ugly number.
 
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 
 Note that 1 is typically treated as an ugly number.
 */



class Solution {
public:

    
    bool isUgly(int num) {
       
        if (num < 1) {
            return false;
        }
        
        
        if (num == 1) {
            return true;
        }
        
        if( num % 2 == 0  )
        {
            return isUgly(num/2);
        }
        else if(num % 3 == 0)
        {
            return isUgly(num/3);
        }
        else if(num % 5 == 0)
        {
            return isUgly(num / 5);
        }
        else
        {
            // not 2,3,5
            return false;
        }
    
        
        // should not be here.
        assert(false);
        return true;
    }
    
    //使用二分查找,return insert index
    int insertToSortedDeque( deque<long> &big, long v , int start = 0)
    {
        int len = big.size();
        
        if (len == 0) {
            big.push_back(v);
            return 0;
        }
        else
        {
            if (v > big.back()) {
                big.push_back(v);
                return 0;
            }
            else if( v < big.front())
            {
                big.push_front(v);
                return 0;
            }
            
            
            if (len == 1)
            {
                if (big[0] > v) {
                    big.push_front(v);
                }
                else if( big[0] < v)
                {
                    big.push_back(v);
                }
                
                return 0;
            }
            else if (len == 2)
            {
                if (v > big[1]) {
                    big.push_back(v);
                }
                else
                {
                    if( big[0] < v)
                        big.insert(big.begin()+1, v);
                    else
                        big.push_front(v);
                    
                }
                
                
                return 0;
            }
            
            
            
            int end = len -1;
            
            while ( end - start > 1  ) {
                int pointer = ( end + start ) / 2;
                if ( big[pointer] > v) {
                    end = pointer;
                }
                else if ( big[pointer] < v)
                {
                    start = pointer;
                }
                else
                {
                    // has the same value in queue,insert nothing
                    return pointer;
                }
            }
            
            
            
            if ( v < big[start]  ) {
                big.insert( big.begin()+start , v);
            }
            else if( v > big[start]  )
            {
                if (v < big[end]) {
                    big.insert( big.begin()+start +1, v);
                }
                else
                    big.insert( big.begin()+ end , v);
            }
         
            
            
            return start;
        }
        
        
    }
    


    long nthUglyNumber(int n) {
        
        static bool first = true;
        const int len  = 1000;
        static bool fill[len] = {0};
        static deque<long> big;

        
        
        if (first) {
            first = false;
            
            
            fill[1]= true;
            fill[2]=true;
            fill[3]=true;
            fill[4]=true;
            fill[5]=true;
            
            int j = 0;
            for (int i = 2 ; i  < len; i++) {

                int v = fill[i];
                if ( v == true) {
                    
                    int i2 = i*2;
                    if (i2 < len)
                    {
                        fill[i2] = true;
                    }
                    else
                        insertToSortedDeque(big,i2);
                    
                    int i3 = i*3;
                    if (i3 < len)
                    {
                        fill[i3] = true;
                    }else
                        insertToSortedDeque(big, i3);
                    
                    int i5 = i*5;
                    if (i5 < len)
                    {
                        fill[i5] = true;
                    }
                    else
                    {
                        if (j == 0)
                            j = i;
                        insertToSortedDeque( big,i5);
                    }
                    
                    
                }
                
            }
            
            
        }
        
        
        
        
        
        
        
        static int uglyCountInLen = -1;
        
        int uglyCount = 0;
        if ( uglyCountInLen != -1 && uglyCountInLen < n -1) {
            uglyCount = uglyCountInLen ;
        }
        else
        {
            for (int i = 0; i < len ; i++) {
                if (fill[i] == true) {
                    uglyCount++;
                    
                    if (uglyCount == n) {
                        return i;
                    }
                    
                }
                
            }
            
            
            if (uglyCountInLen == -1)
                uglyCountInLen = uglyCount;
        }
        
        
        
        static int lastUglyCountMax = 0 ;
        static int pAtMax = 0;
        int p = 0;
        
        if (lastUglyCountMax != 0 && lastUglyCountMax < n ) {
            uglyCount = lastUglyCountMax;
            p = pAtMax;
        }
        
        while ( 1 ) {
            
            long v = big[p];
            uglyCount++;
            p++;
            if( uglyCount == n)
            {
                if (uglyCount > lastUglyCountMax) {
                    lastUglyCountMax = uglyCount;
                    pAtMax = p;
                }
                
                return v;
            }
            
            int index = insertToSortedDeque( big,v * 2);
            index = insertToSortedDeque( big,v * 3, index);
            insertToSortedDeque( big,v * 5,index);
         

        }
        

       
        assert(false);
        return 0;
    }
};







int main(int argc, const char * argv[]) {
    
    Solution a;
    int i = 1;
    printf("beautiful numbers are: \n");
    while (i < 999) {
        if (!a.isUgly(i)) {
//            printf("%d\n",i);
        }
        else
        {
            printf("%d\n",i);
        }
        
        //    printf("%d is ugly? %d\n" , i , a.isUgly(i));
        i++;
    }
    
    
    printf("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn\n");
    
    
    unsigned int t = -1;
    printf("int max , %d \n" , (int)t);

    int n;
    
//    n = 86;
//    printf(" The %d nth ugly number is %d\n", n,a.nthUglyNumber(n) ); // 1000
    
    
//    n = 144;
//    printf(" The %d nth ugly number is %d\n", n,a.nthUglyNumber(n) ); // 5000
    
    
    n = 145;
    printf(" The %d nth ugly number is %ld\n", n,a.nthUglyNumber(n) ); // 5120
    
    n = 153;
    printf(" The %d nth ugly number is %ld\n", n,a.nthUglyNumber(n) ); // 5120

//    n = 313;
//    printf(" The %d nth ugly number is %d\n", n,a.nthUglyNumber(n) );
    
//    n = 1487;
//    printf(" The %d nth ugly number is %d\n", n,a.nthUglyNumber(n) );
    
    
    n = 1422;
    printf(" The %d nth ugly number is %ld\n", n,a.nthUglyNumber(n) ); //536870912
    
    n = 1407;
    printf(" The %d nth ugly number is %d\n", n,a.nthUglyNumber(n) ); //536870912
    
    
    
    return 0;
}
