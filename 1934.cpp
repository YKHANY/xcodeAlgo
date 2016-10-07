//
//  1934.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 3..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int main()
{
    //lcm
    int a,b;
    int n;
    scanf("%d",&n);
    while(n-- > 0){
        scanf("%d %d",&a,&b);
        int max = max(a,b);
        int min = min(a,b);
        while(max % min)
        {
            int r = max % min;
            max = min;
            min = r;
        }
        printf("%d\n",a*b/min);
    }
    
    return 0;
}