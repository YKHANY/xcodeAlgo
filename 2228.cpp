//
//  2228.cpp
//  Algo
//
//  Created by younghan on 2016. 8. 2..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include<iostream>
using namespace std;
int n,m;
int sum[101];
int d[101][101][51];
int func(int i, int j, int m)
{
    if(i < 0 || j < 0) return 0;
    if(d[i][j][m]!= 0) return d[i][j][m];
    if(i==j){
        if(m == 0) return 0;
        if(j < m*2){
            return d[i][j][m] =  func(i, j-1, m-1);
        }
        int t1 = func(i,j-1,m-1);
        int t2 = func(i-1, j-1, m);
        return d[i][j][m] = max(t1,t2);
    }else{
        if( j == 0) return d[i][j][m] = sum[i];
        if(j == m*2){
            return d[i][j][m] = func(j-1, j-1, m)+ sum[i]-sum[j];
        }
        int t1 = func(i,j-1,m);
        int t2 = func(j-1, j-1, m)+ sum[i]-sum[j];
        return d[i][j][m] = max(t1,t2);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        int tmp;
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }
    cout << func(n,n,m) << "\n";
    
    return 0;
}