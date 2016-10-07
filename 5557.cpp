//
//  5557.cpp
//  Algo
//
//  Created by younghan on 2016. 8. 30..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int in[101];
long long d[101][22];
long long sol(int idx, int cur)
{
    if(cur > 20) return 0;
    if(cur < 0) return 0;
    if(idx == n-1 && cur == in[n]) return 1;
    if(idx == n-1 && cur != in[n]) return 0;
    if(d[idx][cur] != -1) return d[idx][cur];
    long long ret =0;
    ret += sol(idx+1, cur + in[idx+1]);
    ret += sol(idx+1, cur - in[idx+1]);
    d[idx][cur] = ret;
    return ret;
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> in[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=22; j++){
            d[i][j] = -1;
        }
    }
    sol(1,in[1]);
    cout << d[1][in[1]]<< "\n";
    return 0;
}
