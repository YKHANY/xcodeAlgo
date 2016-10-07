//
//  1_a.cpp
//  Algo
//
//  Created by younghan on 2015. 11. 27..
//  Copyright © 2015년 younghan. All rights reserved.
//

#include<stdio.h>
bool check(int tmp,int num,int s,int b){
    int i1,i2,i3;
    int n1,n2,n3;
    int ts=0, tb=0;
    i1 = tmp/100;
    tmp %= 100;
    i2 = tmp/10;
    tmp %= 10;
    i3 = tmp;
    
    tmp = num;
    n1 = tmp/100;
    tmp %= 100;
    n2 = tmp/10;
    tmp %= 10;
    n3 = tmp;
    
    if(n1 == i1)
        ts++;
    if(n2 == i2)
        ts++;
    if(n3 == i3)
        ts++;
    if(n1 == i2 || n1 == i3)
        tb++;
    if(n2 == i1 || n2 == i3)
        tb++;
    if(n3 == i1 || n3 ==i2)
        tb++;
    
    if(s == ts && b == tb){
        return true;
    }
    return false;
}

bool checkNum(int tmp){
    int i1,i2,i3;
    int n1,n2,n3;
    
    i1 = tmp/100;
    tmp %= 100;
    i2 = tmp/10;
    tmp %= 10;
    i3 = tmp;
    
    if(i1 == 0 || i2 ==0 || i3 ==0)
        return false;
    if(i1 == i2 || i1 ==i3)
        return false;
    if(i2 == i1 || i2 ==i3)
        return false;
    if(i3 == i1 || i3 ==i2)
        return false;
    
    return true;
}
int main()
{
    int n;
    int res=0;
    int num[100],s[100],b[100];
    scanf("%d",&n);
    
    for(int i=0; i<n;i++){
        scanf("%d",num+i);
        scanf("%d",s+i);
        scanf("%d",b+i);
    }
    
    for(int i=123; i<=987; i++)
    {
        if(checkNum(i)){
            for(int j=0; j<n; j++){
                if(check(i,num[j],s[j],b[j])){		
                    if(j == n-1){ 
                        res++;
                    }
                }else 
                    break;
            }
        }
    }
    
    printf("%d",res);
    
    return 0;
}