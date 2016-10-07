//
//  5427.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 27..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
char map[1111][1111];
bool f_visited[1111][1111];
bool visited[1111][1111];
int w,h;
class dat {
public:
    int r,c;
    int cnt;
    bool flag; // true == fire // false == man
    dat(){};
    dat(int r, int c, int cnt, bool flag): r(r),c(c),cnt(cnt),flag(flag){};
};
queue<dat> q;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int res= -1;
void bfs()
{
    while(!q.empty()){
        dat out = q.front();
        q.pop();
        
        if(out.r == 1 || out.r == h || out.c == 1 || out.c == w){
            if(!out.flag){
                res = out.cnt;
                break;
            }
        }
        for(int i=0; i<4; i++){
            int next_row = out.r + dir[i][0];
            int next_col = out.c + dir[i][1];
            
            if(next_row > 0 && next_row <=h && next_col > 0 && next_col <=w){
                if(out.flag && !f_visited[next_row][next_col]){
                    q.push(dat(next_row,next_col,out.cnt+1,out.flag));
                    f_visited[next_row][next_col] = true;
                }
                if(!out.flag && !visited[next_row][next_col] && !f_visited[next_row][next_col]){
                    q.push(dat(next_row,next_col,out.cnt+1,out.flag));
                    visited[next_row][next_col] = true;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> w >> h;
        int start_row=0, start_col=0;
        for(int i=1;i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> map[i][j];
                if(map[i][j] == '#'){
                    visited[i][j] = f_visited[i][j] = true;
                }else if(map[i][j] == '*'){
                    q.push(dat(i,j,0,true));
                    f_visited[i][j] = true;
                }else if(map[i][j] == '@'){
                    start_row = i;
                    start_col = j;
                }
            }
        }
        
        q.push(dat(start_row,start_col,0,false));
        visited[start_row][start_col] = true;
        
        bfs();
        
        if(res == -1){
            cout << "IMPOSSIBLE\n";
        }else{
            cout << res+1 << "\n";
        }
        
        memset(map, 0, sizeof map);
        memset(visited, 0, sizeof visited);
        memset(f_visited, 0, sizeof f_visited);
        res = -1;
        int size = q.size();
        for(int i=0; i<size ; i++)
            q.pop();
    }
    return 0;
}
