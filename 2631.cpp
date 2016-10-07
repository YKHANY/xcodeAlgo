//
//  2631.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 5..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int in[222];
int LISarr[222];
int max(int a, int b) { return a > b ? a : b; }
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> in[i];
    }
    
    // LIS
    int m = 0;
    for(int i=1; i<=n; i++){
        int tmp = 0;
        for(int j=1; j<n; j++){
            if(in[i] > in[j]){
                tmp = max(LISarr[j],tmp);
            }
        }
        LISarr[i] = tmp+1;
        m = max(LISarr[i], m);
    }
    cout << n - m << "\n";
}