//
//  1916.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 21..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <list>
#include <functional>

using namespace std;
int n,m,s,e;
int res[1001];
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;  // pair < sum of w, v >
int main()
{
    scanf("%d %d",&n,&m);
    
    // make adjacency list
    vector< list<pair<int,int>> > adj(n+1); // pair < v, w >
    
    /*
    vector< vector< pair<int,int> > > vec;
    vec.clear(); vec.resize(n+1);
    */
    
    int u,v,w;
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(make_pair(v,w));
    }
    scanf("%d %d",&s,&e); // start, end
    
    // init start와 인접한 노드들을 priority_queue에 넣는다.
    int size = (int)adj[s].size();
    for(int i=0; i<size; i++)
    {
        pair<int,int> tmp = adj[s].front(); // < v, w >
        adj[s].pop_front();
        q.push(make_pair(tmp.second, tmp.first));
    }
    
    while(!q.empty())
    {
        pair<int,int> tmp = q.top(); // < w, v >
        q.pop();
        
        if(tmp.second != s && (res[tmp.second]== 0 || tmp.first < res[tmp.second])){
            res[tmp.second] = tmp.first;
    
            int size = (int)adj[tmp.second].size();
            for(int i=0; i<size; i++){
                pair<int,int> t = adj[tmp.second].front();
                adj[tmp.second].pop_front();
                q.push(make_pair(res[tmp.second]+ t.second, t.first ));
            }
        }
    }
    
    printf("%d\n",res[e]);
    
    return 0;
}