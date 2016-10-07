//
//  1600.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 25..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int k, h, w;
int map[222][222];
bool visited[222][222][33];
class dat {
    public :
    int r,c,k,step;
    dat(){};
    dat(int r, int c, int k, int step): r(r),c(c),k(k),step(step) {};
};
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int horse[8][2] = {
    -1,-2,
    -2,-1,
    -2,1,
    -1,2,
    1,-2,
    1,2,
    2,-1,
    2,1};
queue<dat> q;
int res = -1;
void bfs(dat start)
{
    q.push(start);
    visited[start.r][start.c][start.k] = true;
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        
        if(out.r == h && out.c == w){
            res = out.step;
            break;
        }
        
        for(int i=0; i<4; i++){
            int next_row = out.r + dir[i][0];
            int next_col = out.c + dir[i][1];
            
            if(next_row > 0 && next_row <= h && next_col > 0 && next_col <= w && !visited[next_row][next_col][out.k] && map[next_row][next_col] != 1){
                q.push(dat(next_row, next_col, out.k, out.step+1));
                visited[next_row][next_col][out.k] = true;
            }
        }
        
        if( out.k > 0){
            for(int i=0; i<8; i++){
                int next_row = out.r + horse[i][0];
                int next_col = out.c + horse[i][1];
                
                if(next_row > 0 && next_row <= h && next_col > 0 && next_col <= w && !visited[next_row][next_col][out.k-1] && map[next_row][next_col] != 1){
                    q.push(dat(next_row, next_col, out.k-1, out.step+1));
                    visited[next_row][next_col][out.k-1] = true;
                }
            }
        }
    }
}
int main()
{
    cin >> k;
    cin >> w >> h;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> map[i][j];
        }
    }
    bfs(dat(1,1,k,0));
    cout << res << "\n";
    return 0;
}
