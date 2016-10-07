//
//  1234.cpp
//  Algo
//
//  Created by younghan on 2016. 10. 4..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#define ll long long
int n,r,g,b;
ll d[11][111][111][111];
int c[11][11];
int combi(int n, int r)
{
    if(n == r || r == 0) return 1;
    int &ret = c[n][r];
    if(ret != 0) return ret;
    
    ret = combi(n-1,r-1) + combi(n-1, r);
    return ret;
}
ll solve(int level, int red, int green, int blue)
{
    if(level > n) return 1;
    ll &ret = d[level][red][green][blue];
    if(ret != 0) return ret;
    
  
    if(level % 1 == 0){
        if(red >= level)
            ret += solve(level+1, red-level, green, blue);
        if(green >=level)
            ret += solve(level+1, red, green-level, blue);
        if(blue >=level)
            ret += solve(level+1, red,green, blue-level);
    }
    ll res=0;
    if(level % 2 == 0){
        if(red >= level/2 && green >= level/2){
            res = solve(level+1, red-level/2, green-level/2, blue);
            if(level == 2){
                for(int i =level; i>=1; i-=1)
                    res *= combi(i,1);
            }else{
                for(int i =level; i>=level/2; i-=level/2)
                    res *= combi(i,level/2);
            }
            ret += res;
        }
        if(red >= level/2 && blue >=level/2){
            res = solve(level+1, red-level/2, green, blue-level/2);
            if(level == 2){
                for(int i =level; i>=1; i-=1)
                    res *= combi(i,1);
            }else{
                for(int i =level; i>=level/2; i-=level/2)
                    res *= combi(i,level/2);
            }
            ret += res;
        }
        if(green>= level/2 && blue>= level/2){
            res = solve(level+1, red, green-level/2, blue-level/2);
            if(level == 2){
                for(int i =level; i>=1; i-=1)
                    res *= combi(i,1);
            }else{
                for(int i =level; i>=level/2; i-=level/2)
                    res *= combi(i,level/2);
            }
            ret += res;
        }
    }
    if(level % 3 == 0){
        if(red >= level/3 && green >= level/3 && blue >= level/3){
            res = solve(level+1, red-level/3, green-level/3, blue-level/3);
            if(level == 3){
                for(int i=level; i>=1; i-=1)
                    res *= combi(i,1);
            }else{
                for(int i=level; i>=level/3; i-=level/3)
                    res *= combi(i,level/3);
            }
            ret += res;
        }
    }
    return ret;
}
int main()
{
    scanf("%d %d %d %d",&n,&r,&g,&b);
    
    printf("%lld\n",solve(1,r,g,b));
    return 0;
}
