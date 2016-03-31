//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321


#include <iostream>



int reverse(int xx) {
    
    long x = xx;
    bool fu = x < 0;

    if (fu ) {
        x = -x;
    }
    
    int y=0;
    int n;
    while( x != 0){
        n = x%10;
        
        long yNew = y;
        y = y*10 + n;
        
        yNew = yNew*10 + n;
        
        if ( (yNew > 0 && y < yNew) ||
            (yNew < 0 && y < yNew)
            ) {
            //over flow
            return 0;
        }
        
        x /= 10;
    }
    
    if (fu) {
        return y*-1;
    }
    
    return y;
}

int main()
{
//    printf("%d, %d\n", 1, reverse(1));
//    printf("%d, %d\n", 123, reverse(123));
//    printf("%d, %d\n", -123, reverse(-123));
//    printf("%d, %d\n", 100, reverse(100));
//    printf("%d, %d\n", 1002, reverse(1002));
    //overflow
//    printf("%d, %d\n", 1000000003 , reverse(1000000003 ));
//    printf("%d, %d\n", -2147447412 , reverse(-2147447412 ));
//    printf("%d\n", -2147447412 == reverse(-2147447412 ));
    
//    printf("%d, %d\n", 1534236469, reverse(1534236469));
    printf("%d, %d\n", -2147483648, reverse(-2147483648));
    
    
    unsigned int a = -1;
    int32_t b = -1;
    
    
    printf(" int max %u\n", a );
 
    
    printf("%ld \n",GetTValueMax(a));
   
    
    
    return 0;
}




