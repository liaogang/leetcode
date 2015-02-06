//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321


#include <iostream>



int reverse(int x) {
    int y=0;
    int n;
    while( x != 0){
        n = x%10;
        y = y*10 + n;
        x /= 10;
    }
    return y;
}
int main()
{
    printf("%d, %d\n", 123, reverse(123));
    printf("%d, %d\n", -123, reverse(-123));
    printf("%d, %d\n", 100, reverse(100));
    printf("%d, %d\n", 1002, reverse(1002));
    //overflow
    printf("%d, %d\n", 1000000003 , reverse(1000000003 ));
    printf("%d, %d\n", -2147447412 , reverse(-2147447412 ));
    printf("%d\n", -2147447412 == reverse(-2147447412 ));
    return 0;
}