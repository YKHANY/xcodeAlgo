//
//  10451.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 23..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int cnt;
int arr[1001];
bool visited[1001];
int dfs(int n)
{
    visited[n] = true;
    
    if(visited[arr[n]]){
        cnt++;
        return 0;
    }
    
    dfs(arr[n]);

    return 0;
}
int main()
{
    int t;
    
    scanf("%d", &t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        
        
        
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        
        printf("%d\n",cnt);
        
        cnt=0;
        for(int i=1; i<=1000; i++)
        {
            visited[i] = false;
        }
    }
    
    return 0;
}