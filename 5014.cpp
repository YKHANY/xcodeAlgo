//
//  5014.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 12..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int f,s,g,u,d;
bool visit[1010000];
int res=-1;

typedef struct _st
{
    int floor;
    int cnt;
}data;
queue<data> q;

void bfs(data start)
{
    visit[start.floor] = true;
    q.push(start);
    
    while(!q.empty())
    {
        data tmp = q.front();
        
        q.pop();
        
        if(tmp.floor == g) res = tmp.cnt;
        
        if(tmp.floor+u <= f && visit[tmp.floor+u]==false){
            
            data d1 = {tmp.floor+u,tmp.cnt+1};
            
            q.push(d1);
            
            visit[tmp.floor+u] = true;
        }
        
        if(tmp.floor-d > 0 && visit[tmp.floor-d]== false){
            
            data d1 = {tmp.floor-d,tmp.cnt+1};
            
            q.push(d1);
            
            visit[tmp.floor-d] = true;
            
            //if(tmp.floor-d == g) {res = d1.cnt ;break;}
        }
    }
}

int main()
{
    for(int i=0;i<=1000000;i++) visit[i]=false;

    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
    
    data d1 = {s,0};
    bfs(d1);
    
    if(res != -1)
        printf("%d\n",res);
    else
        printf("use the stairs\n");
    
    return 0;
}