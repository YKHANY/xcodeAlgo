//
//  3108.cpp
//  Algo
//
//  Created by younghan on 2016. 10. 7..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

int n;
int map[1111][1111];
bool adj[1111][1111];
bool visited[1111];
queue<int> q;
void bfs(int start)
{
    q.push(start);
    while(!q.empty())
    {
        int out = q.front();
        q.pop();
        
        if(visited[out]) continue;
        visited[out] =1;
        for(int i=1; i<=n; i++){
            if(adj[out][i])
                q.push(i);
        }
    }
}
int main()
{
    scanf("%d",&n);
    int r1,c1,r2,c2;
    for(int t=1; t<=n; t++){
        scanf("%d %d %d %d",&c1,&r1,&c2,&r2);
        c1+=500; r1+=500; c2+=500; r2+=500;
        
        for(int i = r1; i<=r2; i++){ // left
            if(map[i][c1] != 0){
                adj[map[i][c1]][t] = adj[t][map[i][c1]] = 1;
            }else{
                map[i][c1] = t;
                adj[t][t] = 1;
            }
        }
        
        for(int i = r1; i<=r2; i++){ // right
            if(map[i][c2] != 0){
                adj[map[i][c2]][t] = adj[t][map[i][c2]] = 1;
            }else{
                map[i][c2] = t;
                adj[t][t] = 1;
            }
        }
        
        for(int i = c1; i<=c2; i++){ // up
            if(map[r1][i] != 0){
                adj[map[r1][i]][t] = adj[t][map[r1][i]] = 1;
            }else{
                map[r1][i] = t;
                adj[t][t] = 1;
            }
        }
        
        for(int i = c1; i<=c2; i++){ // down
            if(map[r2][i] != 0){
                adj[map[r2][i]][t] = adj[t][map[r2][i]] = 1;
            }else{
                map[r2][i] = t;
                adj[t][t] = 1;
            }
        }
    }
  
    
    int res=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            res++;
            bfs(i);
        }
    }
    
    if(map[500][500] != 0)
        res--;
    
    printf("%d\n",res);
    return 0;
}
