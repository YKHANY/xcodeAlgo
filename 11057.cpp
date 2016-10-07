//
//  11057.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 3..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
int n;
int cache[1001][10];

int upStep(int num, int step)
{
    if(step == n)
        return 1;
    
    if(cache[step][num] != 0) return cache[step][num];
    
    int tmp=0;
    
    for(int i=num; i<10; i++)
    {
        tmp += upStep(i, step+1);
    }
    
    cache[step][num] += (tmp%10007);
    
    return cache[step][num]%10007;
    
}

int main()
{
    scanf("%d",&n);
    
    int res=0;
    for(int i=0; i<10; i++){
        res += upStep(i,1);
    }
    
    printf("%d\n",res%10007);
    return 0;
}