//
//  1707.cpp
//  Algo
//
//  Created by younghan on 2016. 5. 9..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;
int adj[20001][20001];
int tmp[20001][20001];
bool visit[20001];
int v,e;
bool res;
bool in[20001];
void dfs(int num, int step)
{
    visit[num] = true;

    for(int i=1; i<=v; i++){
        if(adj[num][i] == 1 && !visit[i])
        {
            if(step==1){
                tmp[num][i] = tmp[i][num] = 1;
                dfs(i,step);
            }else{
                if(tmp[num][i] != 0){
                    dfs(i,step);
                }else{
                    res = true; // not bi
                }
            }
            
        }
    }
}
int main()
{
    
    int k;
    scanf("%d",&k);
    
    for(int i=0; i<k; i++)
    {
        
        scanf("%d %d",&v,&e);
        
        for(int j=0; j<e; j++)
        {
            // adjacency matrix
            int a,b;
            scanf("%d %d",&a,&b);
            in[a] = true;
            adj[a][b] = adj[b][a] = 1;
        }
        
        for(int j=1; j<=v; j++)
        {
            if(in[j]){
                dfs(j,j);
            }
        }
        
        if(res)
            printf("NO\n");
        else
            printf("YES\n");
        
        
    }
    
    
    
    return 0;
}