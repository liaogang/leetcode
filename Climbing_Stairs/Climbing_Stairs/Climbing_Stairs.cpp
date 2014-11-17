//
//  main.cpp
//  Climbing_Stairs
//
//  Created by liaogang on 14/11/14.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Climbing Stairs
 
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */



/**
    组合: C(m,n)=A(m,n)/A(n,n)
    排列: A(m,n)=(m-0)*(m-1)*(m-2)...(m-(n-1))  ,0~n
 */

/// 全排列
long A(int m,int n)
{
    if (n == 0)
        return 1;
   //else if(n ==1 )
   //    return m;
    
    long total = 1;
    for (int i = 0; i < n; i++)
    {
        total *= (m - i);
    }
    
    return total;
}


/// 组合
long C(int m,int n)
{
    if (n == 0)
        return 1;
    else if(n ==1)
        return m;
    
    return A(m,n)/A(n,n);
}



int climbStairs(int n)
{
    /**
        result =
        C(n,0)
       +C(n-1,1)
       +C(n-2,2)
       +C(n-3,3)
       +C(n-3,i)  i*2<=n

     */
    
    long total = 0;
    for (int i = 0; i <= n /2 ; i++)
    {
        total+= C(n-i,i);
    }
    
    
    return total;
}

int main(int argc, const char * argv[])
{
    std::cout<<climbStairs(1)<<std::endl;
    std::cout<<climbStairs(2)<<std::endl;
    std::cout<<climbStairs(3)<<std::endl;
    std::cout<<climbStairs(4)<<std::endl; //5
    std::cout<<climbStairs(5)<<std::endl;  //8
    std::cout<<climbStairs(35)<<std::endl;  //14930352
    std::cout<<INT_MAX<<std::endl;
    return 0;
}
