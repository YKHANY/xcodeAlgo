//
//  2157.cpp
//  Algo
//
//  Created by younghan on 2016. 10. 2..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;
int n,m,k;
int d[333][333];
int in[333][333];

int solve(int dest, int cnt)
{
    //if(dest < 1) return 0;
    if(cnt == 2){
        if(in[1][dest] == 0) return -12345678;
        else return in[1][dest];
    }
    if(d[dest][cnt] != -1){
        //    cout << "!"<<dest << " " << cnt << " " << d[dest][cnt] << endl;
        return d[dest][cnt];
    }
    
    int ret = -12345678;
    for(int i = dest-1; i >= cnt-1 ; i--){
        if(in[i][dest] == 0) continue;
        ret = max(ret, solve(i,cnt-1)+ in[i][dest]);
    }
    
    d[dest][cnt] = ret;
    
    return ret;
}
int main()
{
    memset(d,-1, sizeof d);
    cin >> n >> m >> k;
    for(int i=0;i < k; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(in[a][b] < c)
            in[a][b] = c;
    }
    
    int res =0;
    for(int i = m; i>= 2; i--)
    {
        res = max(res,solve(n,i));
    }
    cout << res << "\n";
    return 0;
}
