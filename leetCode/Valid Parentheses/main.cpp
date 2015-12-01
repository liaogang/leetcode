//
//  main.cpp
//  Valid Parentheses
//
//  Created by liaogang on 15/8/12.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//


/**
 Valid Parentheses
 
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include "../leetcode.h"

bool match(char first,char second)
{
    if (first == '(') {
        return second == ')';
    }
    else if (first == '[')
    {
        return second == ']';
    }
    else if (first == '{')
    {
        return second == '}';
    }
    
    
    //assert(false);
    return false;
}


bool isValid(string s) {
 
    vector<char> vec;
    
    size_t len = s.length();
    for (int i=0; i<len; i++) {
        char t = s[i];
        
        
        bool bMatched = false;
        
        if(vec.size() != 0)
        {
            char top = vec.back();
            if ( match( top ,t )) {
                vec.erase(vec.end()-1);
                bMatched = true;
            }
        }
            
        
        if (!bMatched)
        {
            vec.push_back(t);
        }
        
    }
    
    
    return vec.size() == 0;
}

int main(int argc, const char * argv[]) {
   
    {
        string s("(]");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
    
    {
        string s("(])");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
   {
        string s("(])");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
   {
        string s("([]");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
   {
        string s("(]]");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
   {
        string s("(");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
    {
        string s("()");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
    
     {
        string s("()[]");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
     {
        string s("{}[]()");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
    
    {
        string s("");
        printf("%s isValid? %d\n",s.c_str(),isValid(s));
    }
        return 0;
}
