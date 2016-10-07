//
//  1850.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 3..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define lld long long
int main()
{
    lld a,b;
    //
    scanf("%lld %lld",&a,&b);
    lld max = max(a,b);
    lld min = min(a,b);
    lld g = 0;
    while(max%min){
        lld r = max % min;
        max = min;
        min = r;
    }
    g = min;
    
    for(lld i=0; i<g; i++)
        printf("1");
    printf("\n");
    return 0;
}