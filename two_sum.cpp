/*
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. 
 
 Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
 */
#include <iostream>
#include <vector>




using namespace std;
class Solution 
{
 public:
     static vector<int> twoSum(vector<int> &numbers, int target) 
     {
	vector<int> ret;
	 size_t size = numbers.size();
         for(int i = 0; i < size ; ++i)
	 {
		for( int j = i + 1; j < size ; ++j)
		{
		    if( numbers[i] + numbers[j] == target )
		    {
			int index1 = numbers[i];
			int index2 = numbers[j];
			if( index1 >  index2 )
			{
			    index1 = numbers[j];
			    index2 = numbers[i];
			}

			ret.push_back(index1);
			ret.push_back(index2);
			break;
		    }
		}
	 }
         
	 return ret;
     }


 };


     void print(vector<int>& numbers)
     {
	 cout<<"index1="<<numbers[0]<<","<<"index2="<<numbers[1]<<endl;
     }




int  main(int args, char  * argv[])
{
    vector<int> test1 ({  2 , 7 ,11 , 15 });

    auto ret = Solution::twoSum(test1,9);
    print( ret );
    


    vector<int> test2 ({3,4,2,9,5,8});
    Solution::twoSum(test2,13);




    return 0;
}




