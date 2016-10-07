//
//  2610.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 27..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int n,m;
int adj[101][101];
bool visit[101][101];
int t,t2;

typedef struct _st
{
    int x;
    int cnt;
}data;
queue<data> q;

void bfs(int start)
{
    data d = {start,0};
    q.push(d);
    
    while(!q.empty())
    {
        
    }
    
}

int main()
{
    scanf("%d %d",&n,&m);
    
    // make adjacency matrix
    for(int i=0; i<m; i++)
    {
        int tmp,tmp2;
        scanf("%d %d",&tmp,&tmp2);
        adj[tmp][tmp2] = adj[tmp2][tmp] = 1;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(adj[i][j] == 1)
            {
                
            }
        }
    }
    
}