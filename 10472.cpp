//
//  10472.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 26..
//  Copyright © 2016년 younghan. All rights reserved.
//
// 0x0001
/*
 0x0100
 0x0080
 0x0040
 
 0x0020
 0x0010
 0x0008
 
 0x0004
 0x0002
 0x0001
 */
#if 0
#include <iostream>
#include <queue>
#include<stdio.h>
using namespace std;
short map;
int t;
unsigned short arr[3][3] = {
    0x0100,
    0x0080,
    0x0040,
    0x0020,
    0x0010,
    0x0008,
    0x0004,
    0x0002,
    0x0001};
class dat {
public:
    unsigned short d;
    int r,c;
    dat(){};
    dat(unsigned short d,int r, int c) : d(d),r(r),c(c){};
};
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int res =99999999;
int c;
void dfs(dat start, int cnt)
{
    //printf("%x ",start.d);
    c++;
    if(start.d == 0x00) {
       // cout << start.r << " "<<start.c << " " << cnt <<endl;
        if(cnt < res){
            cout << "a";
            res = cnt;
        }
    }
    
    if(start.d == 0x26 ){
        printf("(%X) ",start.d);
    }
    unsigned short tmp = start.d;
    tmp ^= arr[start.r][start.c];
    for(int i=0; i<4; i++){
        int next_row = start.r + dir[i][0];
        int next_col = start.c + dir[i][1];
        if(next_row >=0 && next_row <3 && next_col>=0 && next_col<3){
            tmp ^= arr[next_row][next_col];
        }
    }
    if(tmp == 0x00);
        //cout << "("<<start.r << " "<<start.c << " )" << cnt <<endl;
    
    if(start.d == 0x26){
        printf("(%X) ",tmp);
    }
    int sr = start.r;
    int sc = start.c;
    if(start.c == 2){
        sc = 0;
        sr++;
    }else{
        sc ++;
    }
    for(int i=sr; i<3; i++){
        for(int j=sc; j<3; j++){
                dfs(dat(tmp, i,j),cnt+1);
        }
    }

int main()
{
    cin >> t;
    while(t--)
    {
        unsigned short in = 0x0;
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                char tmp;
                cin >> tmp;
                if(tmp == '*'){
                    in = in | arr[i][j];
                    
                }
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                dfs(dat(in,i,j),0);
                //visited[i][j] = true;
            }
     
        }
        cout << res << "\n";
    }
    
    //cout << " ("<<c <<")"<< endl;
    
    return 0;
}
#endif

#include <stdio.h>
#include <vector>

char map[3][4];
int visit[512];
int table[512];

int dir[9] = {0x1A0,0x1D0,0x0C8,
    0x134,0x0BA,0x059,
    0x026,0x017,0x00B};

int target = 0;

void DFS(int data,int l,int pre)
{
    if(l>9)
        return;
    
    int temp = data;
    for(int i=pre+1;i<9;i++)
    {
        data = data^dir[i];
        DFS(data,l+1,i);
        data = temp;
    }
    if(table[data] > l)
        table[data] = l;
}

int main()
{
    int Tc;
    scanf("%d",&Tc);
    while(Tc--)
    {
        scanf("%s",map[0]);
        scanf("%s",map[1]);
        scanf("%s",map[2]);
        for(int i=0;i<512;i++)
        {
            table[i] = 123456789;
            visit[i] = 0;
        }
        target = 0;
        
        if(map[2][2] == '*')
            target += 1;
        if(map[2][1] == '*')
            target += 2;
        if(map[2][0] == '*')
            target += 4;
        if(map[1][2] == '*')
            target += 8;
        if(map[1][1] == '*')
            target += 16;
        if(map[1][0] == '*')
            target += 32;
        if(map[0][2] == '*')
            target += 64;
        if(map[0][1] == '*')
            target += 128;
        if(map[0][0] == '*')
            target += 256;
        
        DFS(0,0,-1);
        printf("%d\n",table[target]);
        
    }
    
    return 0;
}
