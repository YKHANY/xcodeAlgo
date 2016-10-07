//
//  7569.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 26..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int r,c,h;
int map[111][111][111];
bool visited[111][111][111];

int dir[6][3] ={// r,c,h
    -1,0,0,
    0,-1,0,
    0,1,0,
    1,0,0,
    0,0,1,
    0,0,-1};

class dat{
public:
    int r,c,h;
    int step;
    dat(){};
    dat(int r, int c, int h, int step): r(r),c(c),h(h),step(step){};
};
queue<dat> q;
int res;
int tomato_cnt;
int tomato_tmp;
void bfs()
{
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        if(out.step > res)
            res = out.step;
    
        for(int i=0; i<6; i++){
            int next_row = out.r + dir[i][0];
            int next_col = out.c + dir[i][1];
            int next_h = out.h + dir[i][2];
            
            if(next_row > 0 && next_row <= r && next_col > 0 && next_col <= c && next_h > 0 && next_h <= h && !visited[next_row][next_col][next_h])
            {
                if(map[next_row][next_col][next_h] == 0){
                    q.push(dat(next_row,next_col,next_h,out.step+1));
                    visited[next_row][next_col][next_h] = true;
                    tomato_tmp++;
                }
            }
        }
    }
}
int main()
{
    cin >> c >> r >> h;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=r; j++){
            for(int k=1; k<=c; k++){
                cin >> map[j][k][i];
                if(map[j][k][i] == -1)
                    visited[j][k][i] = true;
                else if(map[j][k][i] == 0)
                    tomato_cnt++;
            }
        }
    }
    
    for(int i=1; i<=h; i++){
        for(int j=1; j<=r; j++){
            for(int k=1; k<=c; k++){
                if(map[j][k][i] == 1 && !visited[j][k][i]){
                    q.push(dat(j,k,i,0));
                    visited[j][k][i] = true;
                }
            }
        }
    }
    
    bfs();
    if(tomato_cnt == tomato_tmp){
        cout << res << "\n";
    }else{
        cout << -1 << "\n";
    }
    return 0;
}



