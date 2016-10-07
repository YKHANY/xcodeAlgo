//
//  11653.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 20..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <math.h>
bool arr[10000000];
int main()
{
    int n;
    scanf("%d",&n);
    
    arr[0] = true; arr[1] = true;
    for(int i=2; i<=sqrt((double)n); i++)
    {
        if(arr[i]) continue;
        for(int j=i; j*i<=n; j++)
        {
            arr[j*i] = true;
        }
    }
    
    int i=2;
    while(n > 1)
    {
        if(!arr[i]){
            if(n%i == 0){
                n/=i;
                printf("%d\n",i);
            }
            else{
                i++;
            }
        }else{
            i++;
        }
    }
    
    return 0;
}