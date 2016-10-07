//
//  9010.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 20..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;
stack<char> st;
int t;
int main()
{
    scanf("%d",&t);
    int i;
    while(t--)
    {
        char in[51];
        scanf("%s",in);
        i=0;
        while(1){
            
            if(in[i] == '\0' ) { break; }
            if(in[i] == '(' || in[i] == ')'){
                if(st.empty()){
                    st.push(in[i]);
                }else{
                    if(in[i] == ')' && st.top() != in[i]){
                        st.pop();
                    }else{
                        st.push(in[i]);
                    }
                }
            }
            i++;
        }
      
        if(st.empty())
            printf("YES\n");
        else
            printf("NO\n");
        
        for(;!st.empty();)
            st.pop();
        
    }
    
    return 0;
}