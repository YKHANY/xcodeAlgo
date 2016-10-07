//
//  2240.cpp
//  Algo
//
//  Created by younghan on 2016. 10. 3..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int t, w;
int in[1111];
int d[1111][2][33];

int solve(int cur_time, int tree, int cnt)
{
    int &ret = d[cur_time][tree][cnt];
    if(ret != 0) return ret;
    if(cur_time > t) return 0;
    
    if(cnt == w){ // 이동못하는 경우
        if(in[cur_time] == tree)
            ret += solve(cur_time+1,tree,cnt)+1;
        else
            ret += solve(cur_time+1,tree,cnt);
    }else{ // 이동 더 할 수 있는 경우
        if(in[cur_time] == tree){
            if(tree == 1)
                ret +=max(solve(cur_time+1,tree,cnt), solve(cur_time+1,2,cnt+1))+1;
            else
                ret +=max(solve(cur_time+1,tree,cnt), solve(cur_time+1,1,cnt+1))+1;
        }else{
            if(tree == 1)
                ret += max(solve(cur_time+1,tree,cnt), solve(cur_time+1,2,cnt+1));
            else
                ret +=max(solve(cur_time+1,tree,cnt), solve(cur_time+1,1,cnt+1));
        }
    }
    return ret;
}
int main()
{
    memset(d,0,sizeof d);
    cin >> t >> w;
    for(int i=1; i<=t; i++)
    {
        cin >> in[i];
    }
    
    
    cout << solve(0,1,0) << "\n";
    
    return 0;
}
