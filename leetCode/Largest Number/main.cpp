//
//  main.cpp
//  Largest Number
//
//  Created by liaogang on 15/1/15.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
 Largest Number
 
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.
 */


/// 获取整数最大的位
int getMostSignificantN(int &number)
{
    int wei = 0;
    int total = 1;
    for (; number >= total*10; wei++)
        total=total*10;
    
    int most = number / total;

    int left = number -  most *total;
    
    number = left;
    
    return most;
}

int comp(int a,int b)
{
    char tmp1[22]={0};
    char tmp2[22]={0};
    sprintf(tmp1, "%d%d" , a,b);
    sprintf(tmp2, "%d%d" , b,a);
    
    return strcmp(tmp1, tmp2) > 0;
}

string largestNumber(vector<int> &num)
{
    string result;
    
    sort(num.begin(), num.end(), comp);
    
    bool biggestOneZero = true;
    
    for (int i : num)
    {
        if( i != 0)
            biggestOneZero = false;
        else
        {
            if (biggestOneZero == true)
                continue;
        }
        
        char buf[10]={0};
        sprintf(buf, "%d" , i);
        
        result+=buf;
    }
    
    if (result.size() == 0)
        result = "0";
    
    return result;
}

int main(int argc, const char * argv[])
{
    /*
    vector<int> test({3, 30, 34, 5, 9});
    cout<<largestNumber( test)<<endl;
    return 0;
    */
    
    
    cout<<((comp(121,12))?"正确":"应反过来")<<endl;
    
    
    
    cout<<((comp(34,9))?"正确":"应反过来")<<endl;
    cout<<((comp(9,3))?"正确":"应反过来")<<endl;
    cout<<((comp(34,3))?"正确":"应反过来")<<endl;
    cout<<((comp(33,34))?"正确":"应反过来")<<endl;
    cout<<((comp(93,4))?"正确":"应反过来")<<endl;
    cout<<((comp(93,3))?"正确":"应反过来")<<endl;
    
    
    
    int a = 5423;
    cout<<getMostSignificantN(a)<<endl;
    a= 1;
    cout<<getMostSignificantN(a)<<endl;
    a = 10;
    cout<<getMostSignificantN(a)<<endl;
    a = 123465;
    cout<<getMostSignificantN(a)<<endl;
    a = 600000;
    cout<<getMostSignificantN(a)<<endl;
    
    return 0;
}
