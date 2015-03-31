#include <iostream>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <sys/timeb.h>

using namespace std;

vector<int> fill_vec(vector<int> &intvec, int n, int range){
    intvec.clear();
    srand(rand());
    for(int i=0; i<n; i++)
        intvec.push_back(rand()%range);
    return intvec;
}

void print_result(vector<int> intvec, int n){
    for(vector<int>::iterator it = intvec.begin(); it!= intvec.begin()+n && it!=intvec.end(); ++it){
        cout<<*it<<"\t";
    }
    cout<<endl;
    return;
}

class BubbleSort{
public:
    static void Bubble_sort(vector<int> &intv){
        int temp;
        for(int i=0; i<intv.size()-1; ++i){
            for(int j=0; j<intv.size()-1-i; ++j){
                if(intv[j]>intv[j+1]){
                    temp = intv[j];
                    intv[j] = intv[j+1];
                    intv[j+1] = temp;
                }
            }
        }
        return;
    }
};

class QuickSort{
public:
    static void Quick_sort(vector<int> &intv, int start, int end){
        if(start>=end) return;
        int left = start;
        int right = end;
        int key = intv[left];
        while(left<right){
            while(left<right && intv[right]>=key)
                --right;
            intv[left] = intv[right];
            while(left<right && intv[left]<=key)
                ++left;
            intv[right] = intv[left];
        }
        intv[left] = key;
        Quick_sort(intv,start,left-1);
        Quick_sort(intv,right+1,end);
        return;
    }

    static void Quick_sort(vector<int> &intv){
        Quick_sort(intv,0,intv.size()-1);
    }
};

class SelectSort{
public:
    static void Select_sort(vector<int> &intv, int n){
        int currentMax;
        int temp;
        for(int i=0; i<n; ++i){
            currentMax = 0;
            for(int j=0;j<n-i; ++j){
                if(intv[currentMax]<intv[j])
                    currentMax = j;
            }
            temp = intv[currentMax];
            intv[currentMax] = intv[n-1-i];
            intv[n-1-i] = temp;
        }
        return;
    }

    static void Select_sort(vector<int> &intv){
        Select_sort(intv,intv.size());
        return;
    }
};

class Heap{
public:
    vector<int> m_array;//或者下面数组形式都可以
    //static const int MAX_SIZE = 100;
    //int node[MAX_SIZE];
    //int size;
    //如果为数组实现，那么需记住MAX_SIZE为容量，数组中元素多少为size
    //如果用vector实现，那么size就等于m_array.size();
    
    inline void swap(int &a, int&b){ int t=a; a=b; b=t; }
    inline int father(int pos){ return (pos-1)>>1; }
    inline int left(int pos){ return (pos<<1)+1; }
    inline int right(int pos){ return (pos<<1)+2; }
    
    
    template<typename Compare>
    void FixUp(int pos, Compare comp){
        while(pos>0){
            if(comp(m_array[pos],m_array[father(pos)])){
                swap(m_array[pos],m_array[father(pos)]);
                pos = father(pos);
            }else{
                break;
            }
        }
    }
    
    template<typename Compare>
    void FixDown(int pos, Compare comp){
        int min;
        while(left(pos)<m_array.size()){
            min = left(pos);
            if(right(pos)<m_array.size()){
                if(comp(m_array[right(pos)],m_array[min]))
                    min = right(pos);
            }
            if(comp(m_array[pos],m_array[min])){
                break;
            }else{
                swap(m_array[pos],m_array[min]);
                pos = min;
            }
        }
    }

    template<typename Compare>
    void Maintain(int pos, Compare comp){
        FixDown(pos,comp);
        FixUp(pos,comp);
    }

    template<typename Compare>    
    void Insert(int data, Compare comp){
        m_array.push_back(data);
        Maintain(m_array.size()-1, comp);
    }
    
    template<typename Compare>    
    int Remove(int pos, Compare comp){
        if(pos<0 || pos>m_array.size())
            return -1;
        else{
            m_array[pos] = m_array[m_array.size()-1];
            m_array.pop_back();
            Maintain(pos,comp);
            return 0;
        }
    }
    
    
    int Top(){
        if(m_array.empty())
            return -1;
        else
            return m_array[0];
    }

    template<typename Compare>
    int Update(int pos, int data, Compare comp){
        if(pos<0 || pos>m_array.size()){
            return -1;
        }else{
            m_array[pos] = data;
            Maintain(pos,comp);
            return 0;
        }
    
    }


    int Size(){
        return m_array.size();
    }
    
    Heap(const vector<int>& intv){
        m_array.assign(intv.begin(),intv.end());
    }
    //void BuildHeap(int data[], int n)
    template<typename Compare>    
    void BuildHeap(Compare comp){
        for(int j=(m_array.size()>>1)-1; j>=0; j--)
        //for(int j=m_array.size()-1; j>=0; j--)
            FixDown(j,comp);
        return;
    }

    template<typename Compare>    
    void print_kth(int n, Compare comp){
        while(n--){
            cout<<m_array[0]<<'\t';
            Remove(0,comp);
        }
        cout<<endl;
    }

};

class ShellSort{
public:
    static void Insert_sort(vector<int>& intv){
        for(int i=1; i<intv.size(); i++){
            int temp = intv[i];
            int j;
            for(j=i-1; j>=0 && temp<intv[j]; j--)
                intv[j+1] = intv[j];
            intv[j+1] = temp;
        }
    }

    static void Shell_sort(vector<int>& intv){
        int step = intv.size()>>1;
        while(step>=1){
            for(int i=step; i<intv.size(); i++){
                int temp = intv[i];
                int j;
                for(j=i-step; j>=0 && temp<intv[j]; j=j-step){
                    intv[j+step] = intv[j];
                }
                intv[j+step] = temp;
            }
            step>>=1;
        }
    }

};

class MergeSort{
public:

    vector<int> temp;

    void Merge_sort(vector<int>& intv1, vector<int>& intv2, int left, int right){
        if(left>=right) return;
        int mid = (right+left)>>1;
        Merge_sort(intv1,intv2,left,mid-1);
        Merge_sort(intv1,intv2,mid+1,right);
        int p_final = left, p_left = left, p_right = mid+1;
        while(p_left<=mid && p_right<=right){
            if(intv1[p_left]<=intv1[p_right])
                intv2[p_final++] = intv1[p_left++];
            else
                intv2[p_final++] = intv1[p_right++];
        }
        while(p_left<=mid)
            intv2[p_final++] = intv1[p_left++];
        while(p_right<=right)
            intv2[p_final++] = intv1[p_right++];
        for(int i=left; i<=right; i++)
            intv1[i] = intv2[i];
    }

    void Merge_sort(vector<int>& intv1){
        temp.assign(intv1.begin(),intv1.end());
        Merge_sort(intv1,temp,0,intv1.size()-1);
    }
};

int main(){
    vector<int> intvec;
    struct timeb start,end;

    for(int i=0; i<3; ++i){
        cout<<"第"<<i+1<<"次比较:"<<endl;
        fill_vec(intvec, 10000, 30000);
        
        //STL sort()
        ///*
        vector<int> intvec2(intvec);
        ftime(&start);
        sort(intvec2.begin(),intvec2.end(), less<int>() );
        ftime(&end);
        long long cost = (end.time-start.time)*1000+(end.millitm-start.millitm);
        cout<<"用STL中sort()耗时"<<cost<<"ms, 输出前10个数据如下: "<<endl;
        print_result(intvec2, 10);
        //*/

        //selectSort
        ///*
        vector<int> intvec3(intvec);
        ftime(&start);
        SelectSort::Select_sort(intvec3);
        ftime(&end);
        cost = (end.time-start.time)*1000+(end.millitm-start.millitm);
        cout<<"用选择排序耗时"<<cost<<"ms, 输出前10个数据如下: "<<endl;
        print_result(intvec3, 10);
        //*/

        //自己编写QuickSort
        ///*
        vector<int> intvec4(intvec);
        ftime(&start);
        QuickSort::Quick_sort(intvec4);
        ftime(&end);
        cost = (end.time-start.time)*1000+(end.millitm-start.millitm);
        cout<<"用自己编写快排耗时"<<cost<<"ms, 输出前10个数据如下: "<<endl;
        print_result(intvec4, 10);
        //*/
        
        //heapsort
        ///*
        vector<int> intvec5(intvec);
        ftime(&start);
        Heap heap(intvec5);
        heap.BuildHeap(less<int>());
        cout<<"使用堆排序获取前10个数，数据如下:"<<endl;
        heap.print_kth(10,less<int>());
        ftime(&end);
        cost = (end.time-start.time)*1000+(end.millitm-start.millitm);
        cout<<"共耗时"<<cost<<"ms"<<endl;
        //*/

        //ShellSort
        ///*
        vector<int> intvec6(intvec);
        ftime(&start);
        ShellSort::Shell_sort(intvec6);
        ftime(&end);
        cost = (end.time-start.time)*1000+(end.millitm-start.millitm);
        cout<<"用希尔排序耗时"<<cost<<"ms, 输出前10个数据如下: "<<endl;
        print_result(intvec6, 10);
        //*/

        //MergeSort
        /*
        vector<int> intvec7(intvec);
        print_result(intvec7,10);
        ftime(&start);
        MergeSort ms;
        ms.Merge_sort(intvec7);
        ftime(&end);
        cost = (end.time-start.time)*1000+(end.millitm-start.millitm);
        cout<<"用归并排序耗时"<<cost<<"ms, 输出前10个数据如下: "<<endl;
        print_result(intvec7, 10);
        */



        //BubbleSort
        ///*
        ftime(&start);
        BubbleSort::Bubble_sort(intvec);
        ftime(&end);
        cost = (end.time-start.time)*1000+(end.millitm-start.millitm);
        cout<<"用冒泡排序耗时"<<cost<<"ms, 输出前10个数据如下: "<<endl;
        print_result(intvec, 10);
        //*/


    }
    cout<<"对比结束"<<endl;
    return 0;
}

