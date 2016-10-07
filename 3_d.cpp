//
//  3_d.cpp
//  Algo
//
//  Created by younghan on 2016. 1. 13..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int narray[4000001];
int narray2[4000001];
int cnt;
int main()
{

    int n;
    scanf("%d",&n);
    int ac=0;
    int* arr = (int*)calloc(n+1,sizeof(int));
    
    for(int i=2; i<=n; i++){
        narray[i] = i;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n/i; j++){
            narray[i*j] = 0;
        }
    }
    
    for(int i=0; i<=n; i++){
        if(narray[i] != 0)
            arr[ac++] = narray[i];
    }
  
    int sum=0;
    for(int i=0; i<=ac; i++){
        for(int j=i; j<=ac; j++)
        {
            sum += arr[j];
            if(sum == n)
            {
              cnt++;
                
            }
            if(sum >=n )
            {
                break;
            }
        }
        sum = 0;
    }
    
    printf("%d\n",cnt);
    
    return 0;
}
