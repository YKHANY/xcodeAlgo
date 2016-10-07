//
//  priority_queue.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 21..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <functional>

using namespace std;

priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > q;
int main()
{
    q.push(make_pair(2,1));
    q.push(make_pair(5,2));
    q.push(make_pair(4,3));
    q.push(make_pair(1,4));
    q.push(make_pair(3,5));
    
    
    printf("que size : %ld\n",q.size());
    int size = (int)q.size();
    for(int i=0; i<size; i++){
        pair<int,int> tmp = q.top();
        printf("pair : %d %d\n",tmp.first,tmp.second);
        q.pop();
    }
    
    return 0;
}