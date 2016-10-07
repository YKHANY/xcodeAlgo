//
//  1526.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 12..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
int n;

int dfs(int x)
{
    if(n >= x){
        int t7,t4;
        t7 = dfs(x*10+7);
        t4 = dfs(x*10+4);
        if(t7 > t4)
            return t7;
        else
            return t4;
    }else{
        return x/10;
    }
}

int main()
{
    
    scanf("%d",&n);
    int r7,r4;
    r7 = dfs(7);
    r4 = dfs(4);
    if(r7>r4)
        printf("%d\n",r7);
    else
        printf("%d\n",r4);
    
    return 0;
}