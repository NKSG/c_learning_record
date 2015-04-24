#include <iostream>
#include <queue>

using namespace std;

bool connected[20][20], n[20];
queue<int> q;

void init(){
    memset(connected,false,sizeof(connected));
    memset(n,false,sizeof(n));
}

void addEdge(int from, int to){
    connected[from][to] = true;
    //无向
    //connected[to][from] = true;
}

bool search(int start, int end){
    q.push(start);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(temp==end) return true;
        for(int i=0; i<20; ++i){
            if(connected[temp][i] && !n[i]){
                q.push(i);
                n[i] = true;
            }
        }
    }
    return false;
}

int main(){
    init();
    int from,to;
    while(cin>>from){
        if(cin>>to){
            addEdge(from,to);
        }
    }
    
    cout<<search(0,6)<<endl;

}
