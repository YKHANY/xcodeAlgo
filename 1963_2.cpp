//
//  1963_2.cpp
//  Algo
//
//  Created by younghan on 2016. 9. 29..
//  Copyright © 2016년 younghan. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int in1,in2;
bool prime[10000];
bool visited[10000];
class dat {
public:
    int d, cnt;
    dat(){}
    dat(int d,int cnt): d(d),cnt(cnt){}
};
queue<dat> q;
void bfs(dat start)
{
    q.push(start);
    while(!q.empty())
    {
        
        dat out  = q.front();
        q.pop();
        
        if(out.d < 1000 || out.d >9999) continue;
        if(visited[out.d]) continue;
        visited[out.d] = 1;
        
        if(out.d == in2){
            cout << out.cnt << "\n";
            return;
        }
        
        int tmp[4];
        tmp[0] = out.d/1000;
        out.d %= 1000;
        tmp[1] = out.d/100;
        out.d %= 100;
        tmp[2] = out.d/10;
        tmp[3] = out.d%10;
        
        //cout <<"* "<< tmp[0] << " " << tmp[1] << " " << tmp[2] << " " <<tmp[3] << endl;
        
        for(int i=0; i<4; i++){
            for(int j= 0; j<=9; j++){
                if(j == tmp[i]) continue;
                if(i == 0 && j == 0) continue;
                int arr[4];
                for(int i=0; i<4; i++) arr[i] = tmp[i];
                arr[i] = j;
                int next = arr[0]*1000 + arr[1]*100 + arr[2]*10 + arr[3];
                //cout << next << "\n";
                if(prime[next]){
                    q.push(dat(next,out.cnt+1));
                    
                }
            }
        }
    }
    cout << "Impossible\n";
}
int main()
{
    int T;
    cin >> T;
    
    // from 1 ~ to 9999 array
    //
    for(int i=2; i<=9999; i++) prime[i] = 1;
    for(int i=2; i<= 9999; i++){
        for(int j=i+i; j<= 9999; j += i){
            prime[j] = 0;
        }
    }
    
    while(T--)
    {
        cin >> in1 >> in2;
        bfs(dat(in1,0));
        while(q.size())
        {
            q.pop();
        }
        memset(visited,0,sizeof visited);
    }
    return 0;
}
