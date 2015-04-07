#include <iostream>
#include <vector>

void setZeros(std::vector<std::vector<int> > &matrix){
    std::vector<bool> row(matrix.size(),0);
    std::vector<bool> col(matrix[0].size(),0);
    
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(matrix[i][j]==0) {
                row[i] = true;
                col[j] = true;
            }

    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[0].size(); j++)
            if(row[i] || col[j])
                matrix[i][j] = 0;

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
    int a[] = {1,2,3,4,5,0,7,8,9,10,11,12,13,14,15,16};
    
    std::vector<std::vector<int> > b(4,std::vector<int>(4,0));    
    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j)
            b[i][j] = a[4*i+j];

    printMatrix(b);
    setZeros(b);
    printMatrix(b);

}
