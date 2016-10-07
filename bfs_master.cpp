//
//  bfs_master.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 27..
//  Copyright © 2016년 younghan. All rights reserved.
//
#if 0
#include <iostream>
#include <queue>
using namespace std;
int f,s,g,u,d;
class dat {
public:
    int move, cnt;
    dat() {}
    dat(int move, int cnt): move(move),cnt(cnt){}
};
bool visited[1111111];
int res;
queue<dat> q;
void bfs(dat start)
{
    q.push(start);
    
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        if(out.move < 1 || out.move > 1000000) continue;
        if(out.move == g){
            res = out.cnt;
            cout << res << "\n";
            return;
        }
        if(visited[out.move]) continue;
        visited[out.move] = true;
        q.push(dat(out.move+u, out.cnt+1));
        q.push(dat(out.move-d, out.cnt+1));
    }
    cout << "use the stairs\n";
}
int main()
{
    cin >> f >> s >> g >> u >> d;
    bfs(dat(s,0));
    return 0;
}
#endif

#if 0


#include<stdio.h>
#include<queue>
using namespace std;
int map[111][111];
bool visited[111][111];
int r,c;
class dat {
public:
    int r,c;
    int step;
    dat() {}
    dat(int r, int c, int step):r(r),c(c),step(step){}
};
int res;
queue<dat> q;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
void bfs(dat start){
    q.push(start);
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        if(out.r < 1 || out.r > r || out.c< 1 || out.c > c || map[out.r][out.c] == 0) continue;
        if(out.r == r && out.c == c){
            res = out.step;
            return;
        }
        if(visited[out.r][out.c]) continue;
        visited[out.r][out.c] = true;
        for(int i=0; i<4; i++){
            int next_row = out.r + dir[i][0];
            int next_col = out.c + dir[i][1];
            
            q.push(dat(next_row,next_col,out.step+1));
        }
    }
}
int main()
{
    scanf("%d %d",&r,&c);
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    bfs(dat(1,1,1));
    printf("%d\n",res);
    return 0;
}
#endif

#if 0

#include <iostream>
#include <queue>
using namespace std;
int map[111][111];
int h, w;
int sr, sc, sd;
int er, ec, ed;
bool visited[111][111][5];
class dat
{
    public :
    int r,c,d,step;
    dat(){};
    dat(int r, int c, int d, int step) :r(r), c(c), d(d), step(step){};
};
queue<dat> q;
int res;
int dir[4][2] = {0,1,0,-1,1,0,-1,0,};
int rot[4][2] = {3,2,2,3,0,1,1,0};
void bfs(dat start)
{
    q.push(start);

    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        
        if(out.r < 1 || out.c < 1 || out.r > h || out.c > w || map[out.r][out.c] == 1) continue;
        
        if(out.r == er && out.c == ec && out.d == ed){
            res = out.step;
            return;
        }
        
        if(visited[out.r][out.c][out.d]) continue;
        visited[out.r][out.c][out.d] = true;
        
        // 자기 방향에서 갈 수 있는 곳
        for(int i=1; i<=3; i++){
            if(map[out.r + dir[out.d][0]*i][out.c + dir[out.d][1]*i] == 1) break;
            else{
                q.push(dat(out.r + dir[out.d][0]*i, out.c + dir[out.d][1]*i, out.d, out.step+1));
            }
        }
        // 방향 전환
        q.push(dat(out.r,out.c,rot[out.d][0], out.step+1));
        q.push(dat(out.r,out.c,rot[out.d][1], out.step+1));
    
    }
    
}
int main()
{
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> map[i][j];
        }
    }
    cin >> sr >> sc >> sd;
    cin >> er >> ec >> ed;
    
    sd--; ed--;
    bfs(dat(sr,sc,sd,0));
    
    cout << res << "\n";
    
    
    return 0;
}


#endif

#if 1

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <string>
using namespace std;
char map[111][111];
bool visited[111][111];
int r,c;
bool key[27];
queue<pair<int,int>> q;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
vector<pair<int,int>> v;
int res;
bool key_check=true;
void bfs()
{
    key_check = false;
    while(!q.empty())
    {
        pair<int,int> out  = q.front();
        q.pop();
        
        if(out.first < 1 || out.first > r || out.second < 1 || out.second > c) continue;
        if(map[out.first][out.second] == '*') continue;
        if(map[out.first][out.second] >= 'A' && map[out.first][out.second] <='Z'){
            if(!key[map[out.first][out.second]-'A']){
                v.push_back(make_pair(out.first,out.second));
                continue;
            }
        }
        

        if(visited[out.first][out.second]) continue;
        visited[out.first][out.second] = true;

        if(map[out.first][out.second] == '$'){
            res++;
        }
        if(map[out.first][out.second] >= 'a' && map[out.first][out.second] <='z'){
            key[map[out.first][out.second] - 'a'] = true;
            key_check = true;
        }
        for(int i=0; i<4; i++)
        {
            int next_row = out.first + dir[i][0];
            int next_col = out.second + dir[i][1];
            q.push(make_pair(next_row,next_col));
        }
        
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> r >> c;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                cin >> map[i][j];
                if(i == 1 || i == r || j == 1 || j == c){
                    if(map[i][j] != '*')
                        q.push(make_pair(i,j));
                }
            }
        }
       
        string k;
        cin >> k;
        for(int i=0; i<k.size(); i++){
            if(k[i] == '0')
                break;
            key[k[i]-'a'] = true;
        }
        
        while(key_check)
        {
            unsigned long vsize = v.size();
            for(int i=0; i<vsize; i++){
                q.push(v.back());
                v.pop_back();
            }
            v.clear();
            bfs();
        }
        cout << res << "\n";
        memset(visited,0,sizeof visited);
        memset(key, 0, sizeof key);
        res = 0;
        key_check = true;
        v.clear();
    }
    
    return 0;
}

#endif

/*
 4
 3 3
 ABC
 D$E
 FGH
 g
 5 11
 *A*D*******
 *xB$*...*$*
 *****X*.*D*
 *$b...*....
 a**********
 0
 3 3
 ABC
 D$E
 FGH
 h
 6 11
 *A*D*******
 *xB$*...*$*
 ****dX*.*D*
 *$b.*.*....
 a**...*****
 ***********
 0
 */

