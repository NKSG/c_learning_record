#include <iostream>
#include <cstdio>

void ReplaceBlank(char string[], int length){
    if(string == nullptr && length<=0)
        return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i=0;
    
    while(string[i]!='\0'){
        ++originalLength;
        if(string[i]==' ')
            ++numberOfBlank;
        ++i;
    }

    int newLength = originalLength+2*numberOfBlank;
    if(newLength>length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal>=0 && indexOfNew>indexOfOriginal){
        if(string[indexOfOriginal]==' '){
            string[indexOfNew --] = '0';
            string[indexOfNew --] = '2';
            string[indexOfNew --] = '%';
        }else{
            string[indexOfNew --] = string[indexOfOriginal];
        }
        -- indexOfOriginal;
    }
}

void Test(char* testName, char string[], int length, char expected[]){
    if(testName != nullptr)
        printf("%s begins: ",testName);
    ReplaceBlank(string,length);
    if(expected == nullptr && string == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && string != nullptr)
        printf("failed.\n");
    else if(strcmp(string,expected)==0)
        printf("passed.\n");
    else
        printf("passed.\n");
}

void Test1(){
    const int length = 100;
    char string[length] = "hello world";
    Test("Test1",string,length,"hello%20world");
}

void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
