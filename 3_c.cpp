//
//  3_c.cpp
//  Algo
//
//  Created by younghan on 2016. 1. 10..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int m,n; // m: row , n :column
int map[501][501],visit[501][501];
int cnt; // result
void dfs(int r,int c){
    visit[r][c] = 1;
    if(r==m && c==n){
        cnt++;
        return;
    }
   if(r-1>0 && map[r-1][c]!= 0 && visit[r-1][c] == 0){
        if(map[r-1][c] < map[r][c]){
            dfs(r-1,c);
            visit[r-1][c] = 0;
        }
    }
    if(r+1<=m && map[r+1][c]!= 0 && visit[r+1][c] == 0){
        if(map[r+1][c] < map[r][c]){
            dfs(r+1,c);
            visit[r+1][c] = 0;
        }
    }
    if(c-1>0 && map[r][c-1]!= 0 && visit[r][c-1] == 0){
        if(map[r][c-1] < map[r][c]){
            dfs(r,c-1);
            visit[r][c-1] = 0;
        }
    }
    if(c+1<=n && map[r][c+1]!= 0 && visit[r][c+1] == 0){
        if(map[r][c+1] < map[r][c]){
            dfs(r,c+1);
            visit[r][c+1] = 0;
        }
    }
}
int main(){
    int direction[4][2] = {1,0,-1,0,0,1,0,-1};
    
    scanf("%d %d",&m,&n);
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&map[i][j]);
        }
    }
    dfs(1,1);
    printf("%d\n",cnt);
    
}