/**
 *Given a string, find the length of the longest substring without repeating characters. 
 *For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 *For "bbbbb" the longest substring is "b", with the length of 1.
 */


#include "stdio.h"
#include <iostream>
#include <string>

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


int lengthOfLongestSubstring(string s) 
{
 	string t=s;
 	
 	int count = s.length();
 	int *array = new int[count];
 	for (int i = 0; i < count; ++i)
 	{
 		array[i]=0;
 	}

 	map<char,int> _map;

 	char *beg = &(*(s.begin()));
 	char *end = &(*(s.end()));
 	char *curr = beg++;
 	for ( ; curr != end; curr++)
 	{
 		if( map[curr[0]] == NULL )











 		char *finded　= isRepeated(beg,curr);
 		if (curr == finded )
 		{
 			//no found

 		}
 		else
 		{
 			//found
			array[finded - beg] = curr - finded;
 		}
 	}






 	//print it
 	 for (int i = 0; i < count; ++i)
 	{
 		
 		if (array[i]>0)
 		{
	 		//print s[i] -> len array[i]
	 		for (int j = 0; j < array[i]; ++j)
	 		{
	 			cout<<s[i+j];
	 		}
	 		cout<<endl;
 		}
 	}

}





int main(int argc, char const *argv[])
{
	lengthOfLongestSubstring("abcabcbbqweruyiowasdflkjh9ozxcvm");
	

	return 0;
}








