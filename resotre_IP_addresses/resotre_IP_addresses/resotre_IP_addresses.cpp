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


//bool next(string s,int *divide , int currDivide)
//{
//    
//    
//    
//}

///partNum [0~x]
bool isValid(string s,int len1,int len2,int len3,int len4,int partNum)
{
    if (!(len1 >= 0 && len1 <= 3))
        return false;
    if (!(len2 >= 0 && len2 <= 3))
        return false;
    if (!(len3 >= 0 && len3 <= 3))
        return false;
    if (!(len4 >= 0 && len4 <= 3))
        return false;
    
    
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
    
    string tmp = s.substr(begins,ends-begins);
    
    //第一个不能为0,如025
    if (tmp.length() > 1 && tmp[0] == '0'   ) {
        return false;
    }
    
    int result = -1;
    result = atoi(tmp.c_str());
    
    
    return result >= 0 && result <= 255;
}


void printIPAddress(string s, int len1,int len2,int len3,int len4 ,vector<string> &result)
{
    string strResult;
    for (int i = 0; i < len1+len2+len3+len4; i++)
    {
        if (i == len1)
        {
            strResult.append(".");
            cout<<".";
        }
         if (i == len1+len2)
         {
            strResult.append(".");
            cout<<".";
         }
         if (i == len1+len2+len3)
         {
            strResult.append(".");
             cout<<".";
         }
        
        
        strResult.append(&s[i],1);
        cout<<s[i];
    }
    
    cout<<endl;
    
    result.push_back(strResult);
}



void part4(string s,int len1,int len2,int len3,int len4,int left,vector<string> &result)
{
        if(isValid(s,len1,len2,len3,len4+left,3))
    printIPAddress(s,len1,len2,len3,len4+left,result);
}


void part3(string s,int len1,int len2,int len3,int len4,int left,vector<string> &result)
{
    for (int i = 0; i <= left && len3 < 3; i++)
    {
        if(isValid(s,len1,len2,len3+i,len4,2))
        part4(s,len1,len2,len3+i,len4,left-i,result);
    }
    
}


void part2(string s,int len1,int len2,int len3,int len4,int left,vector<string> &result)
{
    for (int i = 0; i <= left && len2 < 3; i++)
    {
        if(isValid(s,len1,len2+i,len3,len4,1))
        part3(s,len1,len2+i,len3,len4,left-i,result);
    }
    
}



void part1(string s,int len1,int len2,int len3,int len4,int left,vector<string> &result)
{
    for (int i = 0; i <=left && len1 < 3; i++)
    {
        if(isValid(s,len1+i,len2,len3,len4,0))
            part2(s,len1+i,len2,len3,len4,left-i,result);
    }
    
}


vector<string> restoreIpAddresses(string s)
{
    int len = s.length();
    
    int left = len -4;
    
    vector<string> result;
    
    part1(s, 1, 1, 1, 1, left,result);
    
    return  result;
}



int main(int argc, const char * argv[])
{
//    restoreIpAddresses("25525511135");
//    restoreIpAddresses("0000");
   
    
    restoreIpAddresses("010010");
    //Expected: ["0.10.0.10","0.100.1.0"]
    
    
    
    return 0;
}
