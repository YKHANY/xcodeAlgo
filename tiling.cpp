//
//  tiling.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 6..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#define lld long long
lld cache[2000];
lld tile(int n)
{
    if(n==1) return 1;
    if(n==2) return 2;
    lld res;
    if(cache[n] != -1)
        res = cache[n];
    else{
        res = tile(n-1)+tile(n-2);
        cache[n] = res%10007;
    }
    return res%10007;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<2000; i++) cache[i] = -1;
    
    printf("%lld\n",tile(n));
    return 0;
}