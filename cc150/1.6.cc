#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int> > &matrix){
    int length = matrix.size();
    for(int layer = 0; layer<length/2; layer++){
        int first = layer;
        int last = length-1-layer;
        for(int i=first; i<last; ++i){
            int offset = i-first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}


void printMatrix(std::vector<std::vector<int> > &matrix){
    int length = matrix.size();
    for(int i=0; i<length; ++i){
        for(int j=0; j<length; ++j){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    
    std::vector<std::vector<int> > b(4,std::vector<int>(4,0));    
    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j)
            b[i][j] = a[4*i+j];
    
    printMatrix(b);
    //
    rotate(b);
    printMatrix(b);

}
