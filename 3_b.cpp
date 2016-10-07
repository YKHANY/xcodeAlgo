//
//  3_b.cpp
//  Algo
//
//  Created by younghan on 2016. 1. 10..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
int n,m;

typedef struct _st
{
    int val;
    int index;
}st;

typedef struct _st2
{
    int s;
    int e;
}st2;

bool comp(st a, st b){
    return a.val < b.val;
}
int main()
{
    scanf("%d %d",&n,&m);
    st arr[100000];
    st2 arr2[100000];
    
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i].val);
        arr[i].index = i+1;
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d",&arr2[i].s,&arr2[i].e);
    }
    
    std::sort(arr,arr+n,comp);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[j].index >= arr2[i].s && arr[j].index <= arr2[i].e){
                printf("%d\n",arr[j].val);
                break;
            }
        }
        
    }
    return 0;
}