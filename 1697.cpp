//
//  1697.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 27..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int n,k;
bool visited[100011];
class dat {
    public :
    int x,step;
    dat () {};
    dat(int x, int step):x(x),step(step) {};
};

queue<dat> q;
int res;
void bfs(dat start)
{
    q.push(start);
    visited[start.x] = true;
    
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        if(out.x == k){
            res= out.step;
            return;
        }
        
        int next = out.x -1;
        if(next >= 0 && !visited[next]){
            q.push(dat(next,out.step+1));
            visited[next] = true;
        }
        next = out.x+1;
        if(next >= 0 && next <= 100000 && !visited[next]){
            q.push(dat(next,out.step+1));
            visited[next] = true;
        }
        next = out.x *2;
        if(next >= 0 && next <= 100000 && !visited[next]){
            q.push(dat(next,out.step+1));
            visited[next] = true;
        }
        
        
    }
}
int main()
{
    cin >> n >> k;
    
    
    bfs(dat(n,0));
    cout << res << "\n";
    return 0;
}
