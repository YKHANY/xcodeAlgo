//
//  9_b.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 6..
//  Copyright © 2016년 younghan. All rights reserved.
//
#include <stdio.h>

#define lld long long int
lld cache[1000];
// i번째 피보나치 수를 구하는 함수
lld fibo(int i)
{
    //base case
    if(i==0) return 0;
    if(i==1) return 1;
    
    lld ret = cache[i];
    
    if(ret!=-1) return ret;
    
    ret = fibo(i-1) + fibo(i-2);
    
    cache[i] = ret;
    
    return ret;
}

int main()
{
    
    for(int i=0;i<1000;i++) cache[i] = -1;
    printf("%lld\n",fibo(50));
    
    return 0;
}