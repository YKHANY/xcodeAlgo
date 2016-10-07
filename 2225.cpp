//
//  2225.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 5..
//  Copyright © 2016년 younghan. All rights reserved.
//
#include <iostream>
#include <memory.h>
using namespace std;
int n, k;
long long d[222][222][222];

long long solve(int start, int cnt, int num)
{
    if (num < 0 || cnt < 0) return 0;
    if (cnt == 1 && num == 0) return 1;
    if(d[start][cnt][num] != -1) { return d[start][cnt][num];}
    long long ret =0;
    for(int i=0; i<=n; i++){
        ret += solve(i,cnt-1,num-start);
    }
    
    
    
    d[start][cnt][num] = ret % 1000000000;
    return ret % 1000000000;
}

int main()
{
    
    
    
    cin >> n >> k;
    memset(d, -1, sizeof(d));
    long long res = 0;
    for (int i = 0; i <= n; i++){
        res = (res + solve(i, k, n)) % 1000000000;
    }
    cout << res << "\n";
    return 0;
}
