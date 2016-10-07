//
//  1654.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 22..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int k,n;
vector<long long> vec;
int main()
{
    scanf("%d %d",&k,&n);
    for(int i=0; i<k; i++){
        long long in;
        scanf("%lld",&in);
        vec.push_back(in);
    }
    
    sort(vec.begin(), vec.end(),greater<int>());
    
    long long l,r,m,sum=0;
    l = 1, r=vec[0]; m = (l+r)/2;
    while(l<r)
    {
        sum = 0;
        for(int i=0; i<vec.size(); i++ ){
            sum += vec[i]/m;
        }
        if(sum > n){
            l = m+1;
            m = (l+r+1)/2;
        }else if( sum < n) {
            r = m-1;
            m = (l+r)/2;
        }else{
            // finish
            // 최대치 구하기
            l = m;
            m = (l+r+1)/2;
        }
    }
    
    sum =0;
    for(int i=0; i<vec.size(); i++ ){
        sum += vec[i]/l;
    }
    if(sum < n)
        printf("%lld\n",l-1);
    else
    printf("%lld\n",l);
    
    
    
    return 0;
}