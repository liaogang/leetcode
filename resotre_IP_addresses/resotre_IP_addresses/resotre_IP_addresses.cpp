//
//  main.cpp
//  resotre_IP_addresses
//
//  Created by liaogang on 14/11/5.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//


/**********************************************************************************
 *
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 *
 **********************************************************************************/

//(a,b,c,d) 0~255


#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;


bool next(string s,int *divide , int currDivide)
{
    
    
    
}

///partNum [0~x]
bool isValid(string s,int len1,len2,len3,len4,int partNum)
{
    int *parts=new int[4];
    parts[0]=len1;
    parts[1]=len2;
    parts[2]=len3;
    parts[3]=len4;
    
    
    
    int begins=0;
    int i =0;
    for ( ; i < 4 && i<partNum; i++)
    {
        begins+=parts[i];
    }
    
    int ends=begins+parts[i];
    
    string tmp = s
    
    
    
    
}

int part1(string s,int len1,int len2,int len3,int len4,int left)
{
    for (int i = 1; i < left && len1 < 3; i++)
    {
        part2(s,len1+i,len2,len3,len4,left-i);
    }
    
}

int part2(string s,int len1,int len2,int len3,int len4,int left)
{
    for (int i = 0; i < left && len2 < 3; i++)
    {
        part3(s,len1,len2+i,len3,len4,left-i);
    }
    
}

int part3(string s,int len1,int len2,int len3,int len4,int left)
{
    for (int i = 0; i < left && len3 < 3; i++)
    {
        part4(s,len1,len2,len3+i,len4,left-i);
    }
    
}

void printIPAddress(string s, int len1,len2,len3,len4)
{
    
}

int part4(string s,int len1,int len2,int len3,int len4,int left)
{
    printIPAddress(s,len1,len2,len3,len4+left);
}




void aaa(string s, int left , int *partLen)
{
    if (left == 0)
        return;
    
    int partLen2=new int[4];
    memcpy(partLen2, partLen, sizeof(int)*3);
    
    
    int spendOne ;
    for (int i=0; i < 4; i++)
    {
        spendOne = i;
        
        partLen2[i]+=1;
        
        aaa(s,left-1,partLen);
    }
}


vector<string> restoreIpAddresses(string s)
{
    int partPos[4]={1,2,3,4};
    
    int partLen[4]={1,1,1,1};
    
    int len = s.length();
    
    int len2= 3*4 - len;
    
    //unsigned long ipaddr = atol(s.c_str());
    int left = len -4;
    
    aaa(s,left,partLen);
    
    
    
    
    
    next(s,divide,0);
}



int main(int argc, const char * argv[])
{
    
    return 0;
}
