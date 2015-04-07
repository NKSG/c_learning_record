#include <vector>
#include <cstdio>
using namespace std;

static const int MAX_SIZE = 10000;
class MinHeap{
    int node[MAX_SIZE];
    int size;
public:    
    MinHeap():size(0){};
    
    inline int Father(int pos) {return (pos-1)>>1;}
    inline int Left(int pos) {return (pos<<1)+1;}
    inline int Right(int pos) {return (pos<<1)+2;}
    
    void FixDown(int pos){
        while(Left(pos)<size){
            int temp;
            if(Right(pos)<size && node[Right(pos)]<node[Left(pos)])
                temp = Right(pos);
            else
                temp = Left(pos);
            if(node[temp]<node[pos]){
                std::swap(node[temp],node[pos]);
                pos = temp;
            }
            else
                break;
        }
    }
    void FixUp(int pos){
        while(pos>0){
            if(node[Father(pos)]>node[pos]){
                std::swap(node[Father(pos)],node[pos]);
                pos = Father(pos);
            }
            else
                break;
        }
    }
    
    void Maintain(int pos){
        FixDown(pos);
        FixUp(pos);
    }
    
    void Insert(int data){
        if(size == MAX_SIZE)
            return;
        else{
            node[size++] = data;
            Maintain(size-1);
        }
    }
    
    int Top(){
        if(size == 0){
            return -1;//出错
        }else{
            return node[0];
        }
    }
    
    void Pop(){
        if(size == 0){
            return;
        }else{
            node[0] = node[--size];
            Maintain(0);
        }
    }

};

vector<vector<int> > Solution(vector<int>& input){
    MinHeap minheap;
    vector<vector<int> > result;
    vector<int> temp;
    
    if(input.empty()) return result;
    int start = input.front();
    result.push_back(vector<int>(start));
    for(auto i: input){
        if(int *i == start+1){
            temp.clear();
            temp.push_back(*i);
            while(minheap.Top()==temp.back()+1){
                temp.push_back(minheap.Top());
                minheap.Pop();
            }
            start = temp.back();
            result.push_back(temp);
        }else if(*i>start+1){
            minheap.Insert(*i);
        }else{
            break; //出错
        }
    }
    return result;
}

void printResult(vector<vector<int> >& input){
    for(auto it=input.begin(); it!=input.end(); it++){
        for(auto it2 = input(it).begin(); it2!=input[it].end(); it2++){
            printf("%d ",*it2)
        }
        printf("\n");
    }
}

int main(){

    int a[] = {1,2,5,8,10,4,3,6,9,7};
    vector<int> input_eg(a);
    printResult(Solution(input_eg));
    return 0;
}
