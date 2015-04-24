#include <cstdio>
#include <iostream>

bool Find(int* matrix, int rows, int columns, int number){
    bool found = false;

    if(matrix!=nullptr && rows>0 && columns>0){
        int row = 0;
        int column = columns-1;
        while(row<rows && column>=0){
            if(matrix[row*columns+column]==number){
                found = true;
                break;
            }else if(matrix[row*columns+column]>number){
                --column;
            }else
                ++row;
        }
    }
    return found;
}

//find2有局限性，且测试有问题，待修改
bool Find2(int* matrix, int rows, int columns, int number){
    bool found = false;
    if(matrix!=nullptr && rows>0 && columns>0){
        int temp=0;
        for(int i=0; i<rows; i++){
            if(number>=matrix[i*columns+i]){
                temp = i;
                break;
            }
        }
        for(int i=0; i<=temp; i++){
            if(number==matrix[i*columns+temp]){
                found = true;
                break;
            }
            if(number==matrix[temp*columns+i]){
                found = true;
                break;
            }
        }
    }
    return found;
}


// ==== Test ====
void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected){
    if(testName != nullptr)
        printf("%s begins: ", testName);
    bool result = Find(matrix,rows,columns,number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1(){
    int matrix[][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Test("Test1",(int*)matrix,4,4,7,true);
}

void Test2(){
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

void Test7()
{
    Test("Test7", NULL, 0, 0, 16, false);
}

int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
