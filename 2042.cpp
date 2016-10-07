//
//  2042.cpp
//  Algo
//
//  Created by younghan on 2016. 6. 23..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
long long arr[3000000], n, m, k, s;
int main()
{
    scanf("%lld %lld %lld",&n,&m,&k);
    s=1;
    
    while(s < n)
    {
        s<<= 1;
        
    }
    
    for(int i=0; i<n ; i++){
        scanf("%lld",arr+i+s);
    }
    
    long long tmp = s-1;
    while(tmp)
    {
        arr[tmp] = arr[tmp*2] + arr[tmp * 2 +1];
        tmp--;
    }
    
    int a,b,c;
    
    for(int i=0; i< m +k; i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a==1){
            tmp = s + b -1;
            arr[tmp] = c;
            tmp /= 2;
            while(tmp)
            {
                arr[tmp] = arr[tmp *2] + arr[tmp*2 + 1];
                tmp/=2;
            }
        }else{
            long long sum = 0;
            long long  L = s+b-1 , R = s+c-1;
            while(L<R)
            {
                if(L%2== 1){
                    sum += arr[L];
                    L++;
                }
                L/=2;
                
                if(R%2 == 0){
                    sum += arr[R];
                    R--;
                }
                R/=2;
                
            }
            if(L==R)
            {
                sum += arr[L];
            }
            printf("%lld\n",sum);
        }
    }
    
}
