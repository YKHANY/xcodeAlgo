//
//  11052.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 6..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int n;
int a[2000];
int cache[2000];
int f(int n)
{
    
    if(n == 0) return 0;
    if(cache[n] != -1)
    {
        return cache[n];
    }else{
    
        int max=0;
        for(int i=1; i<=n; i++)
        {
            int res = a[i]+f(n-i);
            cache[n] = res;
            
            if(res > max){
                max = res;
            }
        }
        return max;
    }
}



int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0; i<2000; i++)
    {
        cache[i] = -1;
    }
    
    printf("%d\n",f(n));
    
    return 0;
}