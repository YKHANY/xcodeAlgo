//
//  2331.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 24..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int a,p;
bool arr[10000000];
int num[10000000];
int res,cnt;
int decomp(int n)
{
    int res=0;
    while(n != 0)
    {
        int multi =1;
        int tmp = n%10;
        n /= 10;
        
        for(int i=0; i<p; i++)
        {
            multi *= tmp;
        }
        res += multi;
    }
    
    return res;
}
void dfs(int n)
{
    num[n] = ++cnt;
    arr[n] = true;
    int check=decomp(n);
    
    if(arr[check]){
        res = check;
        return ;
    }
    dfs(check);
    
    return;
}

int main()
{
    scanf("%d %d",&a,&p);
    
    dfs(a);
    printf("%d\n",num[res]-1);
    
    return 0;
}