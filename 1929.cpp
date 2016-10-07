//
//  1929.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 20..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <math.h>
bool field[1000000];
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    
    field[0] = true; field[1] = true;
    for(int i=2; i<=sqrt((double)n); i++)
    {
        for(int j=i; i*j<=n; j++)
        {
            field[i*j] = true; // not prime
        }
    }
    
    for(int i=m; i<=n; i++)
    {
        if(!field[i])
            printf("%d\n",i);
    }
    return 0;
}