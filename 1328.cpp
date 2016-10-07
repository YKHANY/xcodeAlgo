//
//  1328.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 5..
//  Copyright © 2016년 younghan. All rights reserved.
//
#include <iostream>
#include <memory.h>
using namespace std;

int N,L,R;
int d[2][2][111][111][111];
bool visited[111];
int solve(bool LR, bool state, int s, int cnt, int num)
{
    
    if(LR && num == 0 && cnt == 0 ) { cout<< "h" ;return 1;}
  //  if(d[LR][state][s][cnt][num] != -1) return d[LR][state][s][cnt][num];
    int ret = 0;
    if(!LR && cnt == 0){
        for(int i=1; i<s; i++){
            ret += solve(!LR, 1, i, R-1, num-1) + solve(!LR, 0, i, R, num-1);
            
        }
        
    }
    
    if(!LR){
        if(!state){
            for(int i=s+1; i<= num; i++){
                if(!visited[i]){
                    visited[i] = true;
                    ret += solve(LR, state, i, cnt-1, num-1);
                    visited[i] = false;
                }
            }
        }else{
            for(int i=1; i< s; i++){
                if(!visited[i]){
                    visited[i] = true;
                    ret += solve(LR, state, i, cnt, num-1);
                    visited[i] = false;
                }
            }
        }
    }else{
        cout<< "z";
        if(!state){
            for(int i=s+1; i<= num; i++){
                if(!visited[i]){
                    visited[i] = true;
                    ret += solve(LR, state, i, cnt, num-1);
                    visited[i] = false;
                }
                
            }
        }else{
            for(int i=1; i< s; i++){
                if(!visited[i]){
                    visited[i] = true;
                    ret += solve(LR, state, i, cnt-1, num-1);
                    visited[i] = false;
                }
                
            }
        }
        
    }
    d[LR][state][s][cnt][num] = ret % 1000000007;
    return ret % 1000000007;
}
int main()
{
    cin >> N >> L >> R;
    
    memset(d,-1,sizeof(d));
    int res = 0;
    for(int i=1; i<=N; i++){
        visited[i] = true;
        res = (res + solve(0, 0, i, L-1, N-1) + solve(0, 1, i, L-1, N-1)) % 1000000007;
        visited[i] = false;
    }
    
    cout << res << "\n";
    
    return 0;
}