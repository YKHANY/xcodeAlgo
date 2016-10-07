//
//  1520.cpp
//  Algo
//
//  Created by younghan on 2016. 4. 23..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>

int map[501][501];
int dirX[4] = {-1,1,0,0};
int dirY[4] = {0,0,1,-1};
int m,n;
int cache[501][501];
int cnt;

int func(int x, int y)
{
    int res=0;
    
    if(x == 1 && y == 1)
    {
        return 1;
    }
    
    for(int i=0; i<4; i++)
    {
        if(x + dirX[i] > 0 && y + dirY[i] > 0 && x + dirX[i] <= n && y + dirY[i] <= m){
            if(map[y + dirY[i]][x + dirX[i]] > map[y][x]){
                if(cache[y + dirY[i]][x + dirX[i]] > 0){
                    res += cache[y + dirY[i]][x + dirX[i]];
                }else{
                    cache[y + dirY[i]][x + dirX[i]] =  func(x + dirX[i],y + dirY[i]);
                    res += cache[y + dirY[i]][x + dirX[i]];
                }
                
            }
        }
    }
    
    return res;
}

int main()
{
    scanf("%d %d", &m, &n);
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    printf("%d",func(n,m));
    
    
    return 0;
}