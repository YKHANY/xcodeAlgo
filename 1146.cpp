//
//  1146.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 4..
//  Copyright © 2016년 younghan. All rights reserved.
//

#if 0
#include <iostream>
using namespace std;
int n;
int arr[111];
bool check[111];
int dfs(int d)
{
    if(d == n+1) return 1;
    
    int ret =0;
    if(d <= 2){
        for(int i=1; i<=n; i++){
            if(!check[i]){
                arr[d] = i;
                check[i] = true;
                ret += dfs(d+1);
                arr[d] = 0;
                check[i] = false;
            }
            
        }
    }else{
        for(int i=1; i<=n; i++){
            if(arr[d-2] > arr[d-1] && i > arr[d-1] && !check[i]){
                arr[d] = i;
                check[i] = true;
                ret += dfs(d+1);
                arr[d] = 0;
                check[i] = false;
            }
            if(arr[d-2] < arr[d-1] && i < arr[d-1] && !check[i]){
                arr[d] = i;
                check[i] = true;
                ret += dfs(d+1);
                arr[d] = 0;
                check[i] = false;
            }
        }
        
    }
    return ret;
}
int main()
{
    cin >> n;
    cout << dfs(1) << "\n";
    return 0;
}

#endif

#include<iostream>
#include<memory.h>
using namespace std;
int n;
int d[111][111][2];

int solve(int s, int num, bool state)
{
    if(num == 1) return 1;
    if(d[s][num][state] != -1) return d[s][num][state];
    int ret = 0;
    if(!state){
        for(int i= s; i<num; i++){
            ret += solve(i,num-1, !state);
        }
    }else{
        for(int i =1; i<s; i++){
            ret += solve(i,num-1, !state);
        }
    }
    d[s][num][state] = ret % 1000000;
    return ret % 1000000;
}

int main()
{
    cin >> n;
    memset(d,-1,sizeof(d));
    
    int res = 0;
    for(int i=1; i<= n; i++){
        res = (res + solve(i,n,0) + solve(i,n,1)) % 1000000;
    }
    if(n== 1)
        cout << n << "\n";
    else
        cout << res <<"\n";
    return 0;
}
