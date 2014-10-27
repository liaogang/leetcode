/**
 *Given a string, find the length of the longest substring without repeating characters.
 *For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 *For "bbbbb" the longest substring is "b", with the length of 1.
 */


#include "stdio.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

///is test repeated in [beg,end)?,return the first repeated char*
char* isRepeated(char *beg, char *test)
{
    for (; beg != test; beg++)
    {
        if (beg[0]==test[0])
        {
            break;
        }
    }
    
    
    return beg;
}


struct pos_len
{
    pos_len(int pos2,int len2):pos(pos2),len(len2)
    {};
    int pos,len;
};

int lengthOfLongestSubstring(string s)
{
    int count = s.length();
    if (count == 0) {
        return 0;
    }
    
    vector<pos_len> vecArray;
    
    map<char,int> _map;
    


    int lastfinded = 0;
    
    for (int i = 0 ; i < count; i++)
    {
        cout<<"-->: "<<s[i]<<endl;
        
        if( _map.find( s[i] ) == _map.end() )
        {
            //not found
            _map[s[i]] = i;
        }
        else
        {
            auto it = _map.find( s[i] );
            int pos = it->second;
            
            
            _map.erase(s[i]);
            
            cout<<"pos:"<< pos <<"="<<s[i] <<endl;
            
            vecArray.push_back( pos_len(pos,i-pos) );
            
            
            lastfinded = i;
        }
        
        
 
    }
    
    
    //array[ lastfinded ] =  s.length() - lastfinded;
    vecArray.push_back( pos_len(lastfinded, count - lastfinded) );
    
    auto maxLen = vecArray.begin();
    
    //print it
    for (auto it = vecArray.begin(); it != vecArray.end(); it++) {
        int i = it->pos;
        int len = it->len;
        
        if( len > maxLen->len )
        {
            maxLen = it;
        }
        
        cout<<len<<"  ";
        
        for (int j = i; j <= i + len; ++j)
        {
            cout<<s[j];
        }
        
        cout<<endl;
    }
    
    
    
    
    
    auto left = maxLen -1;
    auto right = maxLen +1;
    

    if (maxLen == vecArray.begin()) {
        left = maxLen;
    }
    else
    if (maxLen +1 == vecArray.end()) {
        right = maxLen;
    }
    else
    {
        if (left->len < right->len)
        {
            right = maxLen;
        }
        else
        {
            left = maxLen;
        }
    }
    

    int maxmax = left->len + right->len -  (   left->pos + left->len - right->pos  ) - 1 ;
    
    
    cout<< "maxLen:" << maxmax<<endl;
    
    return maxmax;
}





int main(int argc, char const *argv[])
{
    lengthOfLongestSubstring("wfrxsjybldbefsarcbynec");
    //lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    
    
    //lengthOfLongestSubstring("");
    
    //lengthOfLongestSubstring("abcabcbbqweruyiowasdflkjh9ozxcvm");
    
    //lengthOfLongestSubstring("abcabcbb");
    

    
    return 0;
}








