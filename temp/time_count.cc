//
#include <iostream>
#include <ctime>
#include <unistd.h>
/*
int main(){
    time_t start,end;
    time(&start);
    sleep(5);
    time(&end);
    std::cout<<(end-start)<<std::endl;
    return 0;
}
*/
/*
int main(){
    double start, end, cost;
    start = clock();
    sleep(2);
    end = clock();
    std::cout<<(end-start)<<std::endl;
    return 0;
}*/

#include <sys/timeb.h>
int main(){
    struct timeb tp1,tp2;
    ftime(&tp1);
    usleep(10000000);
    ftime(&tp2);
    std::cout<<(tp2.time-tp1.time)<<std::endl;
    std::cout<<tp2.millitm-tp1.millitm<<std::endl;
}
