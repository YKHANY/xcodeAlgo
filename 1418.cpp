//
//  1418.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 20..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int arr[100000];
int n,k;
int main()
{
    scanf("%d %d",&n,&k);
    
    arr[1] = 1;
    for(int i=2; i<= n; i++){
        if(arr[i]) continue;
        for(int j=2; j*i<=n; j++)
        {
            arr[j*i] = i;
        }
    }
    
    int res=0;

    for(int i=1; i<=n; i++){
        if(arr[i] <= k && arr[i] > 0) res++;
        if(arr[i] == 0 && i <= k) res++;
    }
    
    printf("%d\n",res);
    
    return 0;
}