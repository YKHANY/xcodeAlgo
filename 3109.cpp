
//
//  3109.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 28..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
using namespace std;

int R,C;
char map[10001][501];
bool visited[10001][501];
int dir[3][2] = {-1,1,0,1,1,1};
bool dfs(int r, int c)
{
    visited[r][c] = 1;
    if(c == C) return 1;
    bool check = 0;
    for(int i=0; i<3; i++){
        if(!check){
            int next_row = r + dir[i][0];
            int next_col = c + dir[i][1];
            if(next_row > 0 && next_row <= R && next_col >0 && next_col <=C && map[next_row][next_col] != 'x' && !visited[next_row][next_col])
                check = dfs(next_row,next_col);
        }
    }
    return check;
}
int main()
{
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> map[i][j];
        }
    }
    
    int res=0;
    for(int i=1; i<=R; i++){
        res += dfs(i,1);
    }
    cout << res << "\n";
    return 0;
}
