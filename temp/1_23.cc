#include <iostream>
#include "Sales_item.h"
int main(){
    Sales_item trans1,trans2;
    std::cout<<"输入一堆是吧你懂的"<<std::endl;
    int num;
    if(std::cin>>trans1){
        while(std::cin>>trans2)
            if(compareIsbn(trans1,trans2))
                num++;
            else{
                std::cout<<trans1.isbn()<<"共有"<<num<<"条销售记录"<<std::endl;
                trans1 = trans2;
                num=1;
            }
        std::cout<<trans1.isbn()<<"共有"<<num<<"条销售记录"<<std::endl;
    }else{
        std::cout<<"没有数据"<<std::endl;
        return -1;
    }
    return 0;
}
