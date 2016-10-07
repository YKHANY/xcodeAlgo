//
//  2482.cpp
//  Algo
//
//  Created by younghan on 2016. 8. 26..
//  Copyright © 2016년 younghan. All rights reserved.
//

#if 0
#include<iostream>
using namespace std;
int d[1000][30];
char str1[1000], str2[30];
int solve(int i, int j)
{
    if(j == strlen(str2)) return 1;
    if(i == strlen(str1)) return 0;
    if(d[i][j] != 0 ) return d[i][j];
    
    int ret =0;
    
    if(str1[i] == str2[j])
    {
        ret += solve(i+1, j+1);
        ret += solve(i+1, j);
    }else{
        ret += solve(i+1, j);
    }
    d[i][j] = ret;
    return ret;
}
int main()
{
    cin >> str1;
    cin >> str2;
    
    cout << solve(0,0);
    return 0;
}

#endif

#if 1
#include<iostream>
using namespace std;
int n,k;
int d[1001][1001][2];
int sol(int start, int k, bool state)
{
    if(k == 0) return 1;
    if(state && start == n) return 0;
    if(start > n) return 0;
    if(d[start][k][state] != -1) return d[start][k][state];
    int ret = 0;
    ret += (sol(start+2, k-1, state))%1000000003;
    ret += (sol(start+1, k, state))%1000000003;
    d[start][k][state] = ret%1000000003;
    return ret%1000000003;
}
int main()
{
    cin >> n >> k;
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            d[i][j][0] = d[i][j][1] = -1;
        }
    }
    cout << (sol(3,k-1,true) + sol(2,k,false))%1000000003<< "\n";
    
    return 0;
}
#endif