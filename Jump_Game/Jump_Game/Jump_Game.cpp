/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include <iostream>

using namespace std;

bool canJump(int A[], int n)
{
    if (n==1) {
        return true;
    }
    
    bool bCanJump = true;
    
    int posZero = -1;
    for (int i = n -1 ; i >= 0 ; i--)
    {
        if (A[i] == 0)
        {
            if (posZero == -1)
            {
                bCanJump=false;
                posZero = i;
            }
            else
            {
            }
        }
        else
        {
            if (posZero != -1)
            {
                if(A[i] + i  - posZero > 0 || A[i] + i == n - 1)
                {
                    //find next zero
                    posZero = -1;
                    bCanJump = true;
                }
            }
        }
        
        
        
    }
    
    
    
    cout<<"can jump?:"<<bCanJump<<endl;
    return bCanJump;
}




int main(int argc, const char * argv[])
{
//    int test[] = {0};
    int test[] = {2,0,0};
   // int test[] = {1,0,2};
    
//    int test[] = {3,2,1,0,4};
    
    int len = sizeof(test)/sizeof(test[0]);
    canJump( test, len);
    
    
    
    
    
    return 0;
}


