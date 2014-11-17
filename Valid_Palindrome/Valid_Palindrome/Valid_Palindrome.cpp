//
//  main.cpp
//  Valid_Palindrome
//
//  Created by liaogang on 14/11/11.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>


/**
     Valid Palindrome
     
     Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
     
     For example,
     "A man, a plan, a canal: Panama" is a palindrome.
     "race a car" is not a palindrome.
     
     Note:
     Have you consider that the string might be empty? This is a good question to ask during an interview.
     
     For the purpose of this problem, we define empty string as valid palindrome.
 */


using namespace std;


///是否是数字或文字
bool isAlphanumeric(char c)
{
    return isalnum((unsigned char)c);
}



bool isEqualIgnoreCast(char b,char a)
{
    int offset = 'A' - 'a';
    return b == a || b -a == offset || a -b == offset;
}

bool isPalindrome(string s)
{
    bool isPalindrome = true;
    
    if (s.length()==0)
        return true;
        
    int beg=0;
    int end=s.length()-1;
    
    while (beg<=end)
    {
        char b=s[beg];
        while (beg<=end && !isAlphanumeric(b))
        {
            beg++;
            b=s[beg];
        }
        
        char e=s[end];
        while (beg<=end && !isAlphanumeric(e))
        {
            end--;
            e=s[end];
        }
        
        if (beg > end)
        {
//            isPalindrome=false;
            break;
        }
        

        if (!isEqualIgnoreCast(b, e))
        {
            isPalindrome=false;
            break;
        }
        
        
        beg++;
        end--;
    }
    
    return isPalindrome;
}

int main(int argc, const char * argv[])
{
//    cout<<isPalindrome("")<<endl;
    cout<<isPalindrome(" ")<<endl;
//    cout<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
//    cout<<isPalindrome("race a car")<<endl;
    
    return 0;
}
