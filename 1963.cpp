//
//  1963.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 12..
//  Copyright © 2016년 younghan. All rights reserved.
//
#if 0
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int prim[10001];
typedef struct
{
    int x;
    int cnt;
}data;

queue<data> q;
bool visit[10000];
bool res;
int s,e;
//void bfs(data d1)
void bfs(data d1)
{
    queue<data> q;
    visit[d1.x] = true;

    q.push(d1);
    
    while(!q.empty())
    {
        data t = q.front();
        q.pop();
        
        if(t.x == e)
        {
            //res = t.cnt;
            res = true;
            printf("%d\n",t.cnt);
            break;
        }else{
            int n = t.x/1000;
            int n2 = (t.x - (n*1000))/100;
            int n4 = t.x%10;
            int n3 = (t.x%100 - n4)/10;
            
            for(int i=0; i<10; i++){
                if(i == 0 || i == n) continue;
                int tmp = i*1000 + t.x % (n*1000);
                if(prim[tmp]==0 && !visit[tmp]){
                    data in = {tmp, t.cnt+1};
                    q.push(in);
                    visit[in.x] = true;
                }
                
            }
            
            for(int i=0; i<10; i++){
                if(i == n2) continue;
                int tmp = n*1000+i*100+n3*10+n4;
                if(prim[tmp]==0 && !visit[tmp]){
                    data in = {tmp, t.cnt+1};
                    q.push(in);
                    visit[in.x] = true;
                }
            }
            
            for(int i=0; i<10; i++){
                if(i == n3) continue;
                int tmp = n*1000 + n2*100 + i*10+n4;
                if(prim[tmp]==0 && !visit[tmp]){
                    data in = {tmp, t.cnt+1};
                    q.push(in);
                    visit[in.x] = true;
                }

            }
            
            for(int i=0; i<10; i++){
                if(i == n4) continue;
                int tmp = n*1000 + n2*100 + n3*10 + i;
                if(prim[tmp]==0 && !visit[tmp]){
                    data in = {tmp, t.cnt+1};
                    q.push(in);
                    visit[in.x] = true;
                }

            }
        }
    }
    if(!res){
        printf("Impossible\n");
    }
}

int main()
{
    // prim number
    
    for(int i=2; i<10000; i++)
    {
        for(int j=2*i; j<10000; j+=i){
            prim[j] = 1;
        }
    }
    
    
    int iter;
    scanf("%d",&iter);
    for(int i=0; i<iter; i++)
    {
        scanf("%d %d",&s,&e);
        
        data start = {s,0};
        bfs(start);
        /*
        if(res == 0 && q.empty())
        {
            printf("Impossible\n");
        }
        */
        res = false;
        
        if(!q.empty())
        {
            q.pop();
        }
        
        for(int i=0; i<10001; i++)
        {
            visit[i] = false;
        }
    }
    
    return 0;
}
#endif

#include<stdio.h>
int main()
{
    long long x = 3400000000;
    
    for(int i=1; i<= 10; i++){
        x = x + x*0.1;
    }
    
    printf("%lld\n",x);
}