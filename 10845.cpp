//
//  10845.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 20..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
queue<int> q;
int n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char cmd[10];
        int n;
        scanf("%s",cmd);
        if(strcmp(cmd,"push")==0){
            scanf("%d",&n);
            q.push(n);
        }else if(strcmp(cmd,"pop")==0){
            if(q.empty()){
                printf("-1\n");
            }else{
                printf("%d\n",q.front());
                q.pop();
            }
        }else if(strcmp(cmd,"size")==0){
            printf("%d\n",(int)q.size());
        }else if(strcmp(cmd,"empty")==0){
            if(q.empty()){
                printf("1\n");
            }else{
                printf("0\n");
            }
            
        }else if(strcmp(cmd,"front")==0){
            if(q.empty()){
                printf("-1\n");
            }else{
                printf("%d\n",q.front());
            }
        }else if(strcmp(cmd,"back")==0){
            if(q.empty()){
                printf("-1\n");
            }else{
                printf("%d\n",q.back());
            }
        }
    }
    
    
    return 0;
}