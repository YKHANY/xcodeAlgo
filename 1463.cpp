//
//  1463.cpp
//  Algo
//
//  Created by younghan on 2016. 4. 27..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int cache[1000001];
int calc(int n)
{
    int res = 0;
    
    if( n == 2)
        return 1;
    if( n == 3)
        return 1;
    
    if(cache[n] > 0) return cache[n];
    
    int res1= 0 , res2 = 0, res3 = 0;
    
    res1 += calc(n-1)+1;
    res = res1;
    
    if(n%2 == 0){
        res2 += calc(n/2)+1;
        if(res > res2)
            res = res2;
    }
    
    if(n%3 == 0){
        res3 += calc(n/3)+1;
        if( res > res3)
            res = res3;
    }
   
    cache[n] = res;
    return res;
    
}

int main()
{
    int n;
    scanf("%d",&n);
    
    printf("%d\n",calc(n));
    
    
    return 0;
}