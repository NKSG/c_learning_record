#include <iostream>
#include "Sales_item.h"
int main(){
    Sales_item book1, book2;
    std::cout<<"请输入两条ISBN相同的销售记录："<<std::endl;
    std::cin>>book1>>book2;//这里可以不endl
    if(compareIsbn(book1, book2)){
        std::cout<<"汇总信息：ISBN、销售本数、销售额、平均售价为"<<book1+book2<<std::endl;
    }else{
        std::cout<<"两条销售记录ISBN不同"<<std::endl;
    }
    return 0;
}

