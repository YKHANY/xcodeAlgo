//
//  1726.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 25..
//  Copyright © 2016년 younghan. All rights reserved.
//

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

void bfs(dat start)
{
    q.push(start);
    visited[start.r][start.c][start.d] = true;
    while(!q.empty())
    {
        dat out = q.front();
        q.pop();
        
        if(out.r == er && out.c == ec && out.d == ed){
            res = out.step;
            break;
        }
        int dir = out.d;
        dat next_data;
        if(dir == 1) // east
        {
            for(int i=1; i<=3; i++){
                if(out.c+i > 0 && out.c+i <= w && !visited[out.r][out.c+i][out.d] && map[out.r][out.c+i] != 1){
                    if(i==1){
                        next_data = dat(out.r,out.c+i,out.d,out.step+1);
                        q.push(next_data);
                        visited[out.r][out.c+i][out.d] = true;
                    }
                    if(i == 2 && map [out.r][out.c+1] != 1){
                        next_data = dat(out.r, out.c+i, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r][out.c+i][out.d] = true;
                        
                    }
                    if(i == 3 && map[out.r][out.c+1] != 1 && map[out.r][out.c+2] != 1){
                        next_data = dat(out.r, out.c+i, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r][out.c+i][out.d] = true;
                    }
                    
                }
            }
            
            if(!visited[out.r][out.c][4]){
                q.push(dat(out.r, out.c, 4, out.step+1));
                visited[out.r][out.c][4]= true;
            }
            if(!visited[out.r][out.c][3]){
                q.push(dat(out.r, out.c, 3, out.step+1));
                visited[out.r][out.c][3]= true;
            }
            
            
        }else if(dir == 2){ //west
            for(int i=1; i<=3; i++){
                if(out.c-i > 0 && out.c-i <= w && !visited[out.r][out.c-i][out.d] && map[out.r][out.c-i] != 1){
                    if(i==1){
                        next_data = dat(out.r,out.c-i,out.d,out.step+1);
                        q.push(next_data);
                        visited[out.r][out.c-i][out.d] = true;
                    }
                    if(i == 2 && map[out.r][out.c-1] != 1){
                        next_data = dat(out.r, out.c-i, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r][out.c-i][out.d] = true;
                    }
                    if(i == 3 && map[out.r][out.c-1] != 1 && map[out.r][out.c-2] != 1){
                        next_data = dat(out.r, out.c-i, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r][out.c-i][out.d] = true;
                    }
                    
                }
            }
            if(!visited[out.r][out.c][4]){
                q.push(dat(out.r, out.c, 4, out.step+1));
                visited[out.r][out.c][4]= true;
                
            }
            if(!visited[out.r][out.c][3]){
                q.push(dat(out.r, out.c, 3, out.step+1));
                visited[out.r][out.c][3]= true;
                
            }
            
        }else if(dir == 3){ //south
            for(int i=1; i<=3; i++){
                if(out.r+i > 0 && out.r+i <= h && !visited[out.r+i][out.c][out.d]  && map[out.r+i][out.c] != 1){
                    if(i==1){
                        next_data = dat(out.r+i,out.c,out.d,out.step+1);
                        q.push(next_data);
                        visited[out.r+i][out.c][out.d] = true;
                    }
                    if(i == 2 && map[out.r+1][out.c] != 1){
                        next_data = dat(out.r+i, out.c, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r+i][out.c][out.d] = true;
                    }
                    if(i == 3 && map[out.r+1][out.c] != 1 && map[out.r+2][out.c] != 1){
                        next_data = dat(out.r+i, out.c, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r+i][out.c][out.d] = true;
                    }
                    
                }
            }
            
            if(!visited[out.r][out.c][1]){
                q.push(dat(out.r, out.c, 1, out.step+1));
                visited[out.r][out.c][1]= true;
                
            }
            if(!visited[out.r][out.c][2]){
                q.push(dat(out.r, out.c, 2, out.step+1));
                visited[out.r][out.c][2]= true;
                
            }

            
        }else{ // north
            for(int i=1; i<=3; i++){
                if(out.r-i > 0 && out.r-i <= h && !visited[out.r-i][out.c][out.d] && map[out.r-i][out.c] != 1){
                    if(i==1){
                        next_data = dat(out.r-i,out.c,out.d,out.step+1);
                        q.push(next_data);
                        visited[out.r-i][out.c][out.d] = true;
                    }
                    if(i == 2 && map[out.r-1][out.c] != 1){
                        next_data = dat(out.r-i, out.c, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r-i][out.c][out.d] = true;
                    }
                    if(i == 3 && map[out.r-1][out.c] != 1 && map[out.r-2][out.c] != 1){
                        next_data = dat(out.r-i, out.c, out.d, out.step+1);
                        q.push(next_data);
                        visited[out.r-i][out.c] [out.d]= true;
                    }
                    
                }
            }
            if(!visited[out.r][out.c][1]){
                q.push(dat(out.r, out.c, 1, out.step+1));
                visited[out.r][out.c][1]= true;
                
            }
            if(!visited[out.r][out.c][2]){
                q.push(dat(out.r, out.c, 2, out.step+1));
                visited[out.r][out.c][2]= true;
                
            }
            
        }
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
    
    bfs(dat(sr,sc,sd,0));
    
    cout << res << "\n";
    
    
    return 0;
}
