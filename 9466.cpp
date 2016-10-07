//
//  9466.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 24..
//  Copyright © 2016년 younghan. All rights reserved.
//
/*
 
 3
 7
 3 1 3 7 3 4 6
 8
 1 2 3 4 5 6 7 8
 6
 2 3 1 4 2 3
 
 */

#include <stdio.h>

int arr[100001];
int cache[100001];
int res;

int dfs(int n, int start)
{
    if(cache[arr[n]] != 0) return cache[n] = -1;
    if(start == arr[n]){
       // if(start != pre)
        cache[n] = 1;
        return 1;
    }
    
    if(n == arr[n]){
        cache[n] = 1;
        return -1;
    }
    
    int tmp = dfs(arr[n], start);
    cache[n] = tmp;
    
    return tmp;
    
}
int main()
{
    int t;
    
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        
        for(int i=1; i<=n; i++)
        {
            if(cache[i] == 0)
                dfs(i,i);
            /*printf("%d::",i);
             
            for(int j=1; j<=n; j++){
                // if(cache[i] == 1)
                //     printf("%d ",i);
                printf("%d ",cache[j]);
            }
            printf("\n");
             */
        }
        
        for(int i=1; i<=n; i++)
        {
            if(cache[i] == -1)
                res++;
        }
        
        printf("%d\n",res);
        
       /*
        for(int i=1; i<=n; i++){
           // if(cache[i] == 1)
           //     printf("%d ",i);
            printf("%d ",cache[i]);
        }
        
        printf("\n");
        */
        // init variable
        
        for(int i=1; i<=n; i++){
            arr[i] = 0;
            cache[i] = 0;
        }
        
        res = 0;
    }
    return 0;
}

