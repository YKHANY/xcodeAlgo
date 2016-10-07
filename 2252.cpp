//
//  2252.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 21..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int arr[32001];
queue<int> q;
int main()
{
    scanf("%d %d",&n,&m);
    
    // make adjacency list
    vector< list<int> > adj(n+1);
    int u,v;
    for(int i=0; i<m; i++){
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        arr[v]++;
    }
    
    //indegree check and push to queue
    for(int i=1; i<=n; i++){
        //q.push( make_pair((int)adj[i].size(), i));
        if(arr[i] == 0){
            arr[i] = -1;
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int outq = q.front();
        printf("%d ",outq);
        q.pop();
        
        int size = (int)adj[outq].size();
        for(int i = 0; i<size; i++){
            int nextNode = adj[outq].front();
            adj[outq].pop_front();
            arr[nextNode]--;
            if(arr[nextNode] == 0)
            {
                q.push(nextNode);
            }
        }
    }

    return 0;
}