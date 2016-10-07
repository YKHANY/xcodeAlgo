//
//  1260.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 3..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

queue<int> q;
int adj[1001][1001];
bool visit[1001];
int v,e,start;

void dfs(int num){
    
    if(visit[num]) return;
    
    visit[num] = 1;
    printf("%d ",num);
    
    for(int i=1; i<=v; i++){
        if(adj[num][i] != 0 && !visit[i]){
            dfs(i);
        }
    }
    

}

void bfs(int num){
    
    visit[num] = 1;
    q.push(num);
    
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        printf("%d ",t);
        for(int i=1; i<=v; i++)
        {
            if(adj[t][i] != 0 && !visit[i]){
                q.push(i);
                visit[i] = true;
            }
            
        }
    }
}
int main()
{
    scanf("%d %d %d",&v,&e,&start);
    
    for(int i=1; i<=e; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v] = adj[v][u] = 1;
    }
    
    dfs(start);
    printf("\n");
    
    
    for(int i=1; i<=v; i++)
    {
        visit[i] = false;
    }
    
    bfs(start);
    
    
    return 0;
}