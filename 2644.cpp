//
//  2644.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 11..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int map[200][200];
int visit[200];
int cnt=-1;
int n,m;
int s,e;

void dfs(int start, int res)
{
    visit[start] = 1;
    if(start == e) cnt = res;
    res++;
  //  printf("res : %d\n",res);
    for(int i=1; i<=n; i++)
    {
        if(map[start][i] == 1 && visit[i] == 0)
        {
            dfs(i,res);
        }
    }
}

int main()
{
    
    scanf("%d",&n);
    
    scanf("%d %d",&s,&e);
    scanf("%d",&m);
    
    for(int i=1; i<=m; i++)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        map[t1][t2] = map[t2][t1] = 1;
    }
    
    dfs(s,0);
    printf("%d\n",cnt);
    return 0;
}