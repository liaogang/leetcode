/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/


#include <iostream>

using namespace std;


int jump(int A[], int n)
{
    if (n == 1 ) {
        return 0;
    }
    
    int nextJumpPos = 0;
    int jumped=0;
    
    while (nextJumpPos + A[nextJumpPos] +1 < n)
    {
        int tmpPos= nextJumpPos ;
        int maxJump=0;
        for (int i = nextJumpPos + 1 ; i < nextJumpPos + A[nextJumpPos] + 1 ; i++)
        {
            cout<< A[i]<<endl;
            int tmp = (A[i] + i);
            if ( tmp >= maxJump)
            {
                maxJump = tmp;
                tmpPos = i;
            }
        }
        
        nextJumpPos=tmpPos;
        jumped++;
        
        cout<<"jumped to:"<<A[nextJumpPos]<<"          at pos:"<<nextJumpPos <<endl;
    }
    jumped++;
   cout<<"reached end"<<endl;
    return jumped;
}


void doTest(int A[] ,int n)
{
    jump(A,n);
    
}


int main(int argc, const char * argv[]) {
//    int test[] = {2,3,1,1,4};
//    int test[] = {1,1,1,1};
//    int test[] = {1,2,0,1};
    int test[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    //int test[] = {1,2};
    
    int len = sizeof(test)/sizeof(test[0]) ;
    
    
    
    doTest(test,len);
    
    
//    int test2[] = {3, 1 ,4,1,1,6,1,3,5};
//    
//    len = sizeof(test2)/sizeof(test2[0]) -1;
    //doTest(test2,len);
    
    
    
    return 0;
}
