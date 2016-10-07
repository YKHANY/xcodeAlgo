//
//  10816.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 22..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
// lower_bound , upper_bound 사용하면 훨씬 쉽다. 
using namespace std;
vector<int> v;
int tl,tr;
int main()
{
    int n,m;
    scanf("%d",&n);
    int in;
    for(int i =0; i<n; i++){
        scanf("%d",&in);
        v.push_back(in);
    }
    
    sort(v.begin(),v.end());

    scanf("%d",&m);
    for(int i=0; i<m; i++){
        scanf("%d",&in);
        
        int l=0,r=(int)v.size()-1, p;
        
        // min
        while(l <= r)
        {
            p = (l + r)/2;
            if(v[p] >= in){
                r = p;
            }else{
                l = p+1;
            }
            if(l == r){
                if(v[l] == in){
                    tl = l-1;
                }else if(v[l] != in){
                    tl = 0;
                }
                break;
            }
        }
        
        // max
        
        l = 0; r = (int)v.size()-1;
        while(l <= r)
        {
            p = (l+r+1)/2;
            
            if(v[p] > in){
                r = p-1;
            }else if(v[p] <= in){
                l = p;
            }
            if(l == r){
                if(v[l] == in)
                    tr = l;
                else
                    tr = 0;
                break;
            }
        }
        printf("%d ",tr-tl);
        
    }
    
    
    return 0;
    
}
