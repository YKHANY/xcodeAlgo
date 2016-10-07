//
//  9095.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 6..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int cache[1000];
int sum(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    
    int res;
    if(cache[n] != -1)
    {
        return cache[n];
    }else{
        res = sum(n-1)+sum(n-2)+sum(n-3);
        cache[n] = res;
        return res;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; j++){
        
        int n;
        scanf("%d",&n);
        for(int i=0; i<1000; i++)
        {
            cache[i] = -1;
        }
        printf("%d\n",sum(n));
    }
    
    return 0;
}