//
//  9328.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 23..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<memory.h>
using namespace std;
char map[111][111];
bool visited[111][111];
bool key[27];
int h,w;
queue<pair<int,int>> q;
vector<vector<pair<int,int>>> door;
int dir[4][2] = {0,-1,0,1,1,0,-1,0};
int res;
bool condition;
void bfs(pair<int, int> cur)
{
    q.push(cur);
    visited[cur.first][cur.second] = true;
    
    while(!q.empty()){
        
        pair<int, int> out = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int next_row = out.first + dir[i][0];
            int next_col = out.second + dir[i][1];
            
            if(next_row > 0 && next_row <= h && next_col > 0 && next_col <= w && !visited[next_row][next_col]){
                if(map[next_row][next_col] == '.'){
                    q.push(make_pair(next_row, next_col));
                    visited[next_row][next_col] = true;
                }
                if(map[next_row][next_col] >= 97 && map[next_row][next_col] <= 122){ // key
                    key[map[next_row][next_col] -96] = true;
                    q.push(make_pair(next_row, next_col));
                    visited[next_row][next_col] = true;
                    condition = true;
                }
                if(map[next_row][next_col] >= 65 && map[next_row][next_col] <= 90){ // door
                    if(key[map[next_row][next_col] - 64]){ // 열쇠를 갖고있다면
                        q.push(make_pair(next_row, next_col));
                        visited[next_row][next_col] = true;
                    }else{ // 열쇠를 갖고 있지 않다면
                        door[map[next_row][next_col] - 64].push_back(make_pair(next_row,next_col));
                        visited[next_row][next_col] = true;
                    }
                }
                if(map[next_row][next_col] == '$'){
                    visited[next_row][next_col] = true;
                    q.push(make_pair(next_row,next_col));
                    res++;
                }
            }
        }
    }
}

void routine(int i, int j)
{
    if(!visited[i][j] && map[i][j]== '.'){
        bfs(make_pair(i,j));
    }
    if(!visited[i][j] && map[i][j] >= 65 && map[i][j] <= 90){ // door
        if(key[map[i][j] - 64]){
            bfs(make_pair(i,j));
        }else{
            door[map[i][j] - 64].push_back(make_pair(i,j));
            visited[i][j] = true;
        }
    }
    if(!visited[i][j] && map[i][j] >= 97 && map[i][j] <= 122){ // key
        bfs(make_pair(i,j));
    }
    if(!visited[i][j] && map[i][j] == '$'){
        bfs(make_pair(i,j));
        res++;
    }
    
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> h >> w;
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin >> map[i][j];
                if(map[i][j] == '*')
                    visited[i][j] = true;
            }
        }
        
        string in;
        cin >> in;
        for(int i=0; i<in.size(); i++){
            if(in[i] == '0') break;
            key[in[i] - 96] = true;
        }
        
        door.clear();
        door.resize(27);
        
        // get door key
        for(int i=1; i<=w; i++){
            if(map[1][i] >= 97 && map[1][i] <= 122){
                key[map[1][i] - 96] = true;
            }
            
        }
        for(int i=1; i<=w; i++){
            if(map[h][i] >= 97 && map[h][i] <= 122){
                key[map[h][i] - 96] = true;
            }
            
        }
        for(int i=1; i<=h; i++){
            if(map[i][1] >= 97 && map[i][1] <= 122){
                key[map[i][1] - 96] = true;
            }
            
        }
        for(int i=1; i<=h; i++){
            if(map[i][w] >= 97 && map[i][w] <= 122){
                key[map[i][w] - 96] = true;
            }
        }
        
        //
        for(int i=1; i<=w; i++){
            routine(1,i);
        }
        for(int i=1; i<=w; i++){
            routine(h,i);
        }
        for(int i=1; i<=h; i++){
            routine(i,1);
        }
        for(int i=1; i<=h; i++){
            routine(i,w);
        }
        while(1)
        {
            condition = false;
            for(int i=1; i<=26; i++){
                if(key[i] && door[i].size() != 0){
                    while(door[i].size())
                    {
                        bfs(door[i].back());
                        door[i].pop_back();
                    }
                }
            }
            if(!condition)
                break;
        }
        
        cout << res << "\n";
        
        /// init
        res = 0;
        memset(map,0,sizeof map);
        memset(visited, 0, sizeof visited);
        memset(key,0, sizeof key);
    }
    
    return 0;
}
