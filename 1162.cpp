//
//  1162.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 23..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

vector< vector< pair<int, int> > > adj;
int n,m,k;
int main()
{
    
    scanf("%d %d %d",&n,&m,&k);
    adj.clear();
    adj.resize(n+1);
    
    
    for(int i=0; i<m; i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(make_pair(v,w));
    }
    
    
    
    
    
    return 0;
}