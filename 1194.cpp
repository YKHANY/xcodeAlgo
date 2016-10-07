//
//  1194.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 30..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int r,c;
char map[55][55];
bool visited[51][51][64];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
class dat {
public:
    int r,c;
    char key;
    int step;
    dat(){}
    dat(int r,int c, char key, int step):r(r),c(c),key(key),step(step) {}
};
char bit_arr[6] = {
    0x20,
    0x10,
    0x08,
    0x04,
    0x02,
    0x01
};
queue<dat> q;
int res = -1;
void bfs(dat start)
{
    q.push(start);
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        if(out.r < 1 || out.r > r || out.c < 1 || out.c > c) continue;
        if(map[out.r][out.c] == '#') continue;
        if(map[out.r][out.c] >= 'A' && map[out.r][out.c] <='Z'){
            if((out.key & bit_arr[map[out.r][out.c]-'A']) == 0) continue;
        }
        
        if(map[out.r][out.c] == '1'){
            res = out.step;
            return;
        }
        
        if(visited[out.r][out.c][out.key]) continue;
        visited[out.r][out.c][out.key] = 1;
        
        char next_key = out.key;
        if(map[out.r][out.c] >= 'a' && map[out.r][out.c] <= 'z'){
            if((out.key & bit_arr[map[out.r][out.c]-'a']) == 0)
                next_key ^= bit_arr[map[out.r][out.c] - 'a'];
        }
        for(int i=0; i<4; i++){
            int next_row = out.r + dir[i][0];
            int next_col = out.c + dir[i][1];
            q.push(dat(next_row,next_col,next_key,out.step+1));
        }
    }
}
int main()
{
    int sr, sc;
    cin >> r >> c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> map[i][j];
            if(map[i][j] == '0'){
                sr = i; sc = j;
            }
        }
    }
    bfs(dat(sr,sc,0x00,0));
    cout << res <<"\n";
    return 0;
}
