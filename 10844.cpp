//
//  10844.cpp
//  Algo
//
//  Created by younghan on 2016. 4. 28..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#define lld long long

lld cache[101][10];
int n;
lld step(int num, int s)
{
    if(s == n)
        return 1;
    
    if(cache[s][num] != 0)
        return cache[s][num];
    
    
    lld tmp=0;
    if(num-1 >= 0){
        tmp += step(num-1, s+1);
    }
    if(num+1 < 10){
        tmp += step(num+1, s+1);
    }
    
    cache[s][num] += tmp%1000000000;
    
    
    return cache[s][num];
}

int main()
{
    
    scanf("%d",&n);
    lld res=0;
    for(int i=1; i<= 9 ; i++)
    {
        res += step(i, 1);
    }
    
    
    printf("%lld\n",res%1000000000);
    
    
    return 0;
}