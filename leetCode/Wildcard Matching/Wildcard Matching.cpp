//
//  main.cpp
//  Wildcard Matching
//
//  Created by liaogang on 15/1/15.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"


/**
 Wildcard Matching
 
 Implement wildcard pattern matching with support for '?' and '*'.
 
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false

 */


bool dfs(const char *s,int slen,int ps,const char *p ,int plen,int pp)
{
    bool r = true;
    
    for ( ; pp < plen && ps < slen; )
    {
        if (p[pp] == '?')
        {
            pp++,ps++;
        }
        else if (p[pp] == '*')
        {
            bool r2 = false;
            while (r2 == false && ps++<slen  )
            {
                 r2 |= dfs(s, slen, ps, p, plen, pp+1);
            }
            
            if (r2 == false)
            {
                r = false;
                break;
            }
            
            pp++;
        }
        else
        {
            if (s[ps] != p[pp])
            {
                r = false;
                break;
            }
            
            pp++,ps++;
        }
        
        
        if (pp == plen && ps == slen)
        {
            r = true;
            break;
        }
        else if(pp == plen || ps == slen)
        {
            r = false;
            break;
        }
        
        
    }
 
    return r;
}


bool isMatch(const char *s, const char *p)
{
    bool r = true;
    
    int plen = strlen(p);
    int slen = strlen(s);
    
    
    r = dfs(s, slen, 0, p, plen, 0);
    
    
    return r;
}


int main(int argc, const char * argv[])
{
    cout<<isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba", "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*")  <<endl;//→ true
    
    
    cout<<isMatch("aa", "a*")  <<endl;//→ true
    cout<<isMatch("ab", "?*")  <<endl;//→ true
    cout<<isMatch("aab", "c*a*b")  <<endl;//→ false
    cout<<isMatch("aa", "*")  <<endl;//→ true
    cout<<isMatch("aa","aa") <<endl; //→ true
    cout<< isMatch("aa","a") <<endl; // → false
    cout<<isMatch("aaa","aa")  <<endl;//→ false
    
    
    
    return 0;
}





