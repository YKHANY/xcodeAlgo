//
//  1753.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 21..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <functional>
#include <list>
using namespace std;

int v,e,k;
//char arr[20001][20001]; // arr[u][v2] : u -> v2
vector< list<pair<int,int>> > adj(20001);
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
int res[20001];
int main()
{
    scanf("%d %d %d",&v,&e,&k);
    // make graph
    int u,v2,w;
    for(int i=0; i<e; i++){
        scanf("%d %d %d",&u,&v2,&w);
        adj[u].push_back(make_pair(v2,w));
       // arr[u][v2] = w;
    }
    
    int size = (int)adj[k].size();
    for(int i=0; i<size; i++){
        pair<int,int> t = adj[k].front();
        adj[k].pop_front();
        q.push(make_pair(t.second, t.first));
        
    }
    /*
    // k와 인접한 노드를 넣는다.
    for(int i=1; i<=v; i++)
    {
        if(arr[k][i] > 0){
            q.push(make_pair(arr[k][i],i));
        }
    }
    */
    while(!q.empty())
    {
        pair<int,int> tmp = q.top();
        q.pop();
        
        if(tmp.second != k && ( res[tmp.second] == 0 || tmp.first < res[tmp.second] )){
            res[tmp.second] = tmp.first;
            int size = (int)adj[tmp.second].size();
            for(int i=0; i<size; i++){
                pair<int,int> t = adj[tmp.second].front();
                adj[tmp.second].pop_front();
                q.push(make_pair(res[tmp.second] + t.second, t.first));
                
            }
            /*
            for(int i=1; i<=v; i++){
                if(arr[tmp.second][i] > 0){
                    q.push(make_pair(res[tmp.second] + arr[tmp.second][i], i));
                }
            }
             */
        }
    }
    
    for(int i=1;i<=v; i++){
        if(i == k){
            printf("%d\n",res[i]);
        }else{
            if(res[i] != 0)
                printf("%d\n",res[i]);
            else
                printf("INF\n");
        }
        
    }
    
    return 0;
}