//
//  1405.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 28..
//  Copyright © 2016년 younghan. All rights reserved.
//
#if 0
#include <stdio.h>
bool visited[30][30];
int N;
int in[4];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
double dfs(int cur_row,int cur_col, int step, double val)
{
    if(visited[cur_row][cur_col]){
        printf("ret :0.0\n");
        return 0.0;
    }
    if(step == N){
        printf("ret step == N :%lf\n",val);
        return val;
    }
    double ret =0;
    for(int i=0; i<4; i++){
        int next_row = cur_row + dir[i][0];
        int next_col = cur_col + dir[i][1];
        double next_val = val * (in[i]/100.0);
        printf("next_val :%d/%lf ",i,next_val);
        visited[cur_row][cur_col] = 1;
        ret += dfs(next_row,next_col,step+1,next_val);
        visited[next_row][next_col] = 0;
    }
    printf("ret :%lf \n",ret);
    return ret;
}
int main()
{
    scanf("%d",&N);
    for(int i=0; i<4; i++)
        scanf("%d",&in[i]);
    float res;
    res = dfs(15,15,0, 1.0);
    
    printf("%lf\n",res);
    return 0;
}
#endif

#if 1
#include <stdio.h>
bool visited[30][30];
int N;
int in[4];
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
double dfs1(int cur_row,int cur_col, int step, double val)
{
    if(step == N) return val;
    double ret =0;
    for(int i=0; i<4; i++){
        int next_row = cur_row + dir[i][0];
        int next_col = cur_col + dir[i][1];
        double next_val = val * (in[i]/100.0);
        if(visited[next_row][next_col]) continue;
        visited[next_row][next_col] = 1;
        ret += dfs1(next_row,next_col,step+1,next_val);
        visited[next_row][next_col] = 0;
        
    }
    return ret;
}
double dfs(int cur_row,int cur_col, int step, double val)
{
    if(visited[cur_row][cur_col]) return 0.0;
    if(step == N) return val;
    visited[cur_row][cur_col] = 1;
    double ret =0;
    for(int i=0; i<4; i++){
        int next_row = cur_row + dir[i][0];
        int next_col = cur_col + dir[i][1];
        double next_val = val * (in[i]/100.0);
        ret += dfs(next_row,next_col,step+1,next_val);
    }
    visited[cur_row][cur_col] = 0;
    return ret;
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<4; i++)
        scanf("%d",&in[i]);
    double res;
    res = dfs(15,15,0, 1.0);
    printf("%.10lf\n",res);
    return 0;
}
#endif
