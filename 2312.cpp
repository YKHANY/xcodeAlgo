//
//  2312.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 20..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
int arr[100000];
int res[100000];
int t,n;
int main()
{
    for(int i=2; i<=1000; i++)
    {
        if(arr[i]) continue;
        for(int j=i; j*i<=100000; j++)
            arr[i*j] = true;
    }
    
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        int cnt= 0;
        int i=2;
        while(n>1)
        {
            if(!arr[i]){
                if(n%i == 0){
                    res[i]++;
                    n/=i;
                }
                else{
                    i++;
                }
            }
        }
        
        // ing .. 
        
    }
    return 0;
}