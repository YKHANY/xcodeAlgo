//
//  2609.cpp
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
    // gcd, lcm
    int a,b;
    scanf("%d %d",&a,&b);
    int max = max(a,b);
    int min = min(a,b);
    while(max % min)
    {
        int r = max%min;
        max = min;
        min = r;
    }
    int g = min;
    printf("%d\n",g); // gcm
    printf("%d\n",g*(a/g)*(b/g));
    return 0;
}