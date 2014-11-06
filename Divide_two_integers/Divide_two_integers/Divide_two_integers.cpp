//
//  main.cpp
//  Divide_two_integers
//
//  Created by liaogang on 14/10/31.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//


/**********************************************************************************
 *
 * Divide two integers without using multiplication, division and mod operator.
 *
 *
 * 计算两个的除法值，不能使用乘法，除法，和求模运算
 **********************************************************************************/

#include <stdio.h>
#include <string.h>


int divide2(int dividend, int divisor , int dividendNumbers);

/**
 * @param dividend: 除数
 * @param divisor: 被除数
 * @return 商
 *
 * 24/3=8
 * 8 = divide(3,24);
 * return = divisor /dividend ;
 */
int divide3(int dividend, int divisor)
{
    int sum = 0;

    
    
    
    
    
    divide2(dividend, divisor, 0);
    
    
    
    
    
    return sum;
}


int divide2(int dividend, int divisor , int dividendNumbers)
{
    int sum = 0;
    
    
    
    
    
    
    
    
    
    
    
    return sum;
}





int divide(int dividend, int divisor) {
    int sign = 1;
    long long dvd = dividend;
    long long dvs = divisor;
    if (dvd<0) {
        dvd = -dvd;
        sign = -sign;
    }
    if (dvs<0) {
        dvs = -dvs;
        sign = -sign;
    }
    long long bit_num[32];
    memset( bit_num, 0, sizeof(bit_num)/sizeof(bit_num[0]) );
    int i=0;
    long long d = dvs;
    bit_num[i] = d;
    while( d <= dvd ){
        bit_num[++i] = d = d << 1;
    }
    i--;
    unsigned int result = 0;
    while(dvd >= dvs){
        if (dvd >= bit_num[i]){
            dvd -= bit_num[i];
            result += (1<<i);
        }else{
            i--;
        }
    }
    return result * sign;
}





#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    
    cout << "10/2=" << divide(10, 2) << endl;
    cout << "10/3=" << divide(10, 3) << endl;
    cout << "10/5=" << divide(10, 5) << endl;
    cout << "10/7=" << divide(10, 7) << endl;
    cout << "10/10=" << divide(10, 10) << endl;
    cout << "10/11=" << divide(10, 11) << endl;
    cout << "1/-1=" << divide(1, -1) << endl;
    cout << "-1/-1=" << divide(-1, -1) << endl;
    cout << "2147483647/1=" << divide(2147483647, 1) << endl;
    cout << "-2147483647/1=" << divide(-2147483647, 1) << endl;
    cout << "2147483647/-1=" << divide(2147483647, -1) << endl;
    cout << "-2147483647/-1=" << divide(-2147483647, -1) << endl;
    cout << "2147483647/2=" << divide(2147483647, 2) << endl;
    cout << "2147483647/10=" << divide(2147483647, 10) << endl;
    cout << "-2147483648/1=" << divide(-2147483648, 1) << endl;
    
    
    
    
    
    return 0;
}
