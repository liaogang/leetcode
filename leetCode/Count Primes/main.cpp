//
//  main.cpp
//  Count Primes
//
//  Created by liaogang on 15/7/9.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

int countPrimes(int n) {
    enum
    {
        is_prime = 0,
        not_prime = 1,
    };
    
    int *a = new int[n];
    memset(a, is_prime, n);

    
    for (int i = 2; i <= n / 2 + 1 ; i++) {
        for (int j = 2; j <= n/i + 1; j++) {
            a[i*j] = not_prime;
        }
    }
    
    a[1] = not_prime;
    a[2] = not_prime;
    
    int result = 0;
    for (int k = 1; k <= n ; k++) {
        if (a[k] == is_prime) {
            result++;
        }
    }
    
    delete a;
    
    return result;
}

int main(int argc, const char * argv[]) {
   
    int t = 4;
    
    printf("%d prime number %d\n",t,countPrimes(t));
    
    return 0;
}
