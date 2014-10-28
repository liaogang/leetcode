//Implement pow(x, n).


#include <iostream>
#include <math.h>
using namespace std;


/**
 * 即x的n次方
 * 采用非递归二分法实现.
 * http://blog.csdn.net/morewindows/article/details/7174143
 */
double pow4(double x, int n)
{
    //cout<<hex<<n<<endl;
    if (n == INT_MIN) {
        //over flow
        return 1.0;
    }
    
    if (x == 1) {
        return 1.0;
    }
    
    
    
    double result=1;
    double curr = x;
    
    bool negtive = n < 0;
    

    
    
    if (negtive)
    {
        n= -1 * n;
    }
    
    //cout<<hex<<n<<endl;
    
    if (n == 0)
    {
        return 1;
    }
    else
    {
        while ( 0 == (n & 1) )
        {
            n >>= 1;
            //cout<<hex<<n<<endl;
            //cout<<n<<endl;
            curr *= curr;
        }
    }
    
    
    
    while ( n != 0)
    {
       if( n & 1 )
       {
           result *= curr ;
       }
        
        curr*=curr;
        
        n >>= 1;
    }
    
    
    return  negtive?(1/result):result;
}






int main(int argc, const char * argv[])
{
    
//    cout<<pow4(2.23, -1)<<endl;
//    cout<<pow4(2, -1)<<endl;
//    cout<<pow4(2, 2)<<endl;
//    cout<<pow4(2, 0)<<endl;
//    cout<<pow4(2, 1)<<endl;
    
    /*
    int a= -2147483648;
    
    cout<<"-2147483648"<<endl<<a<<endl;
    
    int b = -a;
    if (b == a) {
        cout<<"haaa"<<endl;
    }
    
    cout<<INT_MAX<<endl;
    cout<<INT_MIN<<endl;
    */
    
    
//    cout<<pow4(1.00000, -2147483648)<<endl;
    
    cout<<pow4(3.89707,2)<<endl;

    return 0;
}


