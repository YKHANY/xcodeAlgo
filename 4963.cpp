//
//  4963.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 12..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

typedef struct _st{
    int w,h;
}data;
queue<data> q;
int map[51][51];
bool visit[51][51];
int dirX[8] = {0,0,1,-1,1,-1,1,-1};
int dirY[8] = {1,-1,0,0,1,-1,-1,1};
int w,h;
int res;

int bfs(data start)
{
    int cnt=0;
    int hereX = start.w;
    int hereY = start.h;
    visit[hereY][hereX] = true;
    q.push(start);
    cnt++;
    
    while(!q.empty())
    {
        data tmp = q.front();
        q.pop();
        int hereX = tmp.w;
        int hereY = tmp.h;
        
        for(int i=0; i<8; i++)
        {
            int nextX = hereX + dirX[i];
            int nextY = hereY + dirY[i];
            
            if(nextY >0 && nextY <=h && nextX > 0 && nextX <= w && visit[nextY][nextX] == false && map[nextY][nextX]==1){
                visit[nextY][nextX] = true;
                data d1 = {nextX, nextY};
                q.push(d1);
            }
        }
    }
  //  printf("%d %d : %d\n",hereY,hereX,cnt);
    return cnt;
}

int main()
{
 
    while(true){
        
        scanf("%d %d",&w,&h);
        if(w == 0 && h == 0) break;
        
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                scanf("%d",&map[i][j]);
                if(map[i][j] == 0){
                    visit[i][j] = true;
                }
            }
        }
        
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(map[i][j] == 1 && !visit[i][j]){
                    data t = {j,i};
                    if(bfs(t) > 0){
                        res++;
                    }
                }
            }
        }
        
        printf("%d\n",res);
        
        
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                map[i][j] = 0;
                visit[i][j] = false;
            }
        }
        
        res = 0;
        
        

    }
    
    return 0;
}