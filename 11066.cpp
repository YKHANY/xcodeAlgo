//
//  11066.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 2..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#define INF 0x7fffffff
using namespace std;
int t,k;
int in[555];
int d[555][555];

int solve(int s, int e)
{
    if(s == e) { return 0;}
    if(d[s][e] != -1) return d[s][e];
    int ret = INF;
    int sum = 0;
    for(int i=s; i< e; i++){
        sum += in[i];
        ret = min(ret , solve(s,i) + solve(i+1, e));
    }
    d[s][e] = ret + sum + in[e];
    return d[s][e];
}
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> k;
        
        for(int i=1; i<=k; i++){
            cin >> in[i];
        }
        for(int i=0; i<555; i++){
            for(int j=0; j<555; j++){
                d[i][j] = -1;
            }
        }
        
        cout << solve(1,k) << "\n";
    }
    return 0;
    
}