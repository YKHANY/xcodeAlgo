//
//  11724.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 3..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

int adj[1001][1001];
bool visit[1001];
queue<int> q;
int n,m;
int bfs(int num)
{
    visit[num] = 1;
    q.push(num);
    
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i=1; i<=n; i++)
        {
            if(adj[t][i] == 1 && !visit[i])
            {
                q.push(i);
                visit[i] = true;
            }
        }
    }
    
    return 1;
}
int main()
{
    
    scanf("%d %d",&n,&m);
    
    for(int i=1; i<=m; i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v] = adj[v][u] = 1;
    }
    
    int res=0;
    for(int i =1; i<=n; i++)
    {
        if(!visit[i]){
            res += bfs(i);
        }
    }
    
    printf("%d\n",res);

    return 0;
}