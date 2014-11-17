//
//  main.cpp
//  Longest_Palindromic_Substring
//
//  Created by liaogang on 14/11/17.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>




/**
 Longest Palindromic Substring
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 
 palindromic: 回文，正读与反读相同的字符串
 */

#include <string>
using namespace std;

bool isEqualIgnoreCast(char b,char a)
{
    int offset = 'A' - 'a';
    return b == a || b -a == offset || a -b == offset;
}

int findPalindrome(int *pBeg,int *pEnd,string &s,int len)
{


    bool finded=true;
    int beg=*pBeg;
    int end=*pEnd;
    
    int initBeg = beg;
    bool allsame = s[beg] == s[end];
    
    beg--;
    end++;
    for (;beg>=0 && end<len; beg--,end++)
    {
        while (!isalnum((unsigned char)s[beg] ))
            beg--;
        
        while (!isalnum((unsigned char)s[end] ))
            end++;
        
        cout<<s[beg]<<"~~~"<<s[end]<<endl;


        
        if(!isEqualIgnoreCast(s[beg],s[end] ) )
            break;
        else
        {
            if (!isEqualIgnoreCast(s[beg],s[initBeg]) )
            {
                allsame = false;
            }
            
                
            *pBeg = beg;
            *pEnd = end;
            finded=true;
        }
    }
    
    
    if (finded)
    {
        if (allsame)
        {
            return 0;
        }
    }
    
    return finded;
}

int testSame(string &s,int pos,int len)
{
    int count=1;
    char cPos=s[pos];
    
    for (int prev=pos-1;
         prev>=0 && (!isalnum((unsigned char)s[prev] ) || isEqualIgnoreCast(s[prev], cPos));
         count++,prev--)
        ;

    for (int next=pos+1;
         next<len && (!isalnum((unsigned char)s[next] ) || isEqualIgnoreCast(s[next], cPos));
         count++,next++)
    {
        cout<<s[next]<<endl;
    }
    
    
    return count;
}

string longestPalindrome(string s)
{
    cout<<s<<endl;
    int len = s.length();
    
    if(len == 1)
        return s;
    
    string tmp;
    int lastLen=0;
    for (int i = 0 ; i < len ; i++)
    {
        int beg=i;
        int end=i;
        
        while (!isalnum((unsigned char)s[beg] ))
            beg--;
                
        while (!isalnum((unsigned char)s[end] ))
            end++;
        
        int count = testSame(s,beg,len);
        if (count>1)
        {
            if (count > lastLen)
            {
                lastLen=count;
                tmp = s.substr(beg,count);
            }
            
            int t = (count%2==0?0:1);
            int tt = (count-t)/2;
            i += tt -1 ;
        }
        
        if (s[i]==s[i+1])
        {
            beg=i;
            end=i+1;
            
            findPalindrome(&beg, &end, s, len);
            
            
            //i = end;
            if (end-beg+1>lastLen)
            {
                lastLen=end-beg+1;
                tmp = s.substr(beg,end-beg+1);
                cout<<tmp<<endl;
            }
        }
        
        if(s[i-1] == s[i+1])
        {
            beg=i-1;
            end=i+1;
            
            findPalindrome(&beg, &end, s, len);
            
            
            //i = end;
            if (end-beg+1>lastLen)
            {
                lastLen=end-beg+1;
                tmp = s.substr(beg,end-beg+1);
                cout<<tmp<<endl;
            }
        }

    }
    
    return tmp;
}

int main(int argc, const char * argv[])
{
    //string tmp = longestPalindrome(string("panama aabsdf race a car A man a plan, a c anal panama") );
    
//    string tmp = longestPalindrome(string("aaaa") );
    string tmp = longestPalindrome(string("bb") );
    
    
    cout<<tmp<<endl;
    
    
    return 0;
}
