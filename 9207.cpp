/*
 
 10
 ###...###
 .........
 .........
 .........
 ###...###
 
 ###...###
 .........
 ...o.....
 .........
 ###...###
 
 ###...###
 .........
 ....oo...
 .........
 ###...###
 
 ###...###
 ..oo.....
 .....oo..
 .........
 ###...###
 
 ###...###
 ..oo.o...
 ...o.oo..
 ...oo....
 ###...###
 
 ###o..###
 .o.oo....
 o.o......
 .o.o.....
 ###...###
 */

//
//  9207.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 1..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#define INF 0x7fffffff
using namespace std;
int t;
char map[10][10];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int res1 = INF, res2 = INF;
int min(int a, int b){ return a>b ? b : a;}
void dfs(int rem, int move)
{
    
    for(int i=1; i<=5; i++){
        for(int j=1; j<=9; j++){
            if(map[i][j] == 'o'){
                for(int k = 0; k<4; k++){
                    int next_row = i + dir[k][0];
                    int next_col = j + dir[k][1];
                    
                    if(next_row > 0 && next_row <= 5 && next_col > 0 && next_col <= 9 && map[next_row][next_col] == 'o'){
                        int nnext_row = next_row + dir[k][0];
                        int nnext_col = next_col + dir[k][1];
                        
                        if(map[nnext_row][nnext_col] == '.'){
                            map[i][j] = map[next_row][next_col] = '.';
                            map[nnext_row][nnext_col] = 'o';
                            if(rem-1 == min(res1, rem-1)){
                                res1 = rem - 1;
                                res2 = move + 1;
                            }
                            dfs(rem-1,move+1);
                            
                            map[i][j] = map[next_row][next_col] = 'o';
                            map[nnext_row][nnext_col] = '.';
                            
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> t;
    while(t--){
        int rem = 0;
        for(int i=1; i<=5; i++){
            for(int j=1; j<=9; j++){
                cin >> map[i][j];
                if(map[i][j] == 'o'){
                    rem ++;
                }
            }
        }
        
        dfs(rem, 0);
        //cout << res1 << " " << res2 << "\n";
       
        if(res1 == INF && res2 == INF){
            cout << rem << " " << 0 << "\n";
        }else{
            cout << res1 << " " << res2 << "\n";
        }
        
        res1 = res2 = INF;
    }
    
    
    return 0;
}
