//
//  bfs.cpp
//  Algo
//
//  Created by younghan on 2016. 3. 12..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;


int graph[100][100]; // adjacency matrix
int start = 1;

bool visit[100];
void bfs()
{
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        
        //
        for(int next = 1; next < 100; next++)
        {
            if(graph[here][next] == 1 && visit[next] == false)
            {
                visit[next] = true;
                q.push(next);
            }
        }
    }
}

void dfs(int i)
{
    visit[i] = true;
    for(int next = 0; next <100; next++)
    {
        if(graph[i][next] == 1 && visit[next] == false)
        {
            dfs(next);
        }
    }
}