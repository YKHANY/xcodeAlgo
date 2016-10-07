//
//  11052_2.cpp
//  Algo
//
//  Created by younghan on 2016. 4. 27..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int arr[1001];

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(int i=2; i<=n; i++)
    {
        int max = 0;
        for(int j=1; j<=i; j++){
            int tmp =  arr[j] + arr[i-j];
            if( tmp > max ){
                max = tmp;
            }
        }
        arr[i] = max;
        
    }
    
    printf("%d\n",arr[n]);
    
    
    return 0;
}