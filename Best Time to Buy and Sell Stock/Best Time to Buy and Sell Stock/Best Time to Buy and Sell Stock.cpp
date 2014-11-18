//
//  main.cpp
//  Best Time to Buy and Sell Stock
//
//  Created by liaogang on 14/11/17.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Best Time to Buy and Sell Stock
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction(交易) (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit（利润）.
 
 :先要买入才能卖出。
 */

#include <vector>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int len = prices.size();
    if (len <= 1)
        return 0;
    
    
    int min = prices[0];
    int max =0;
    int maxProfit=0;
    for (int i = 0; i < len; i++)
    {
        int p = prices[i];
        cout<<p<<endl;
        if (p<min)
        {
            
            min = p;
            max = 0;
        }
        
        if (p > max)
        {
            max = p;
            
            if (max - min > maxProfit)
                maxProfit = max - min;
        }
        
        
    }
    
    
    return maxProfit;
}

void test()
{
    vector<int> test({1,2,8,6,100,20});
    cout<<maxProfit(test)<<endl;
    
}

/**
Best Time to Buy and Sell Stock II
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

int maxProfit2(vector<int> &prices)
{
    int len = prices.size();
    if (len == 0 || len == 1)
        return 0;
    
    int maxProfit=0;
    bool haveStones = false;

    
    int currPrice=prices[0];
    int stonesPrice = currPrice;
    for (int i = 1; i <= len; i++)
    {
        int nextPrice ;
        
        if (i == len )
            nextPrice = 0;
        else
            nextPrice = prices[i];
        
        
        if (haveStones)
        {
            /// sell stones at top.
            if (nextPrice<currPrice)
            {
                maxProfit += currPrice - stonesPrice;
                cout<<"sell at price: "<<currPrice<<endl;
                haveStones = false;
            }
        }
        else
        {
            /// buy stones at bottom.
            if (nextPrice > currPrice)
            {
                stonesPrice = currPrice;
                cout<<"buy a price: "<<currPrice<<endl;
                haveStones = true;
            }
            
        }
        
        
        ///
        currPrice = nextPrice;
    }
    
    return maxProfit;
}


void test2()
{
    vector<int> test({1,2,8,6,100,20});
//    vector<int> test({1,2});
    cout<<maxProfit2(test)<<endl;
}






/**
 Best Time to Buy and Sell Stock III
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 
 */

int maxProfit3(vector<int> &prices)
{
    int len = prices.size();
    if (len <= 1)
        return 0;
    else if(len == 2)
    {
        if (prices[0] < prices[1])
            return prices[1]-prices[0];
        else
            return 0;
    }
    
    int minPos = 0 ;
    int maxPos ;
    int min = prices[0];
    int max =0;
    int maxProfit=0;
    for (int i = 0; i < len; i++)
    {
        int p = prices[i];
        cout<<p<<endl;
        if (p<min)
        {
            minPos = i;
            min = p;
            max = 0;
        }
        
        if (p > max)
        {
            max = p;
            
            if (max - min > maxProfit)
            {
                maxProfit = max - min;
                maxPos = i;
            }
        }
    }
    
    
    
    int maxProfitSecond=0;
    min = prices[0];
    max =0;

    ///second time.
    ///from 0~ minPos , from maxPos+1 ~ Len.
    for (int i = 0; ( 0 <= i  && i < minPos ) || (maxPos < i && i < len); i++)
    {
        int p = prices[i];
        cout<<p<<endl;
        
        if (i == maxPos + 1)
        {
            min = p;
            max = p;
        }
        
        
        if (p<min)
        {
            min = p;
            max = 0;
        }
        
        if (p > max)
        {
            max = p;
            
            if (max - min > maxProfitSecond)
            {
                maxProfitSecond = max - min;
            }
        }
        
        
        if (i == minPos -1)
        {
            i = maxPos ;
        }
    }
    
    
    
    
    cout<<"profit1: "<< maxProfit<<", profit2: "<<maxProfitSecond<<endl;
    
    return maxProfit + maxProfitSecond;
}


void test3()
{
//    vector<int> test({1,2,8,6,100,20,0,1000});
    vector<int> test({1,2,4});
    cout<<maxProfit3(test)<<endl;
}

int main(int argc, const char * argv[])
{
    //test();
    //test2();
    test3();
    return 0;
}
