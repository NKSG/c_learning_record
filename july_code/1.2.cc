//字符串包含
//第一个想到的实现
bool StringContains(string &A, string &B){
    int a[26] = {0};
    //如果是字符出现过就行，用bool数组；
    //和出现次数有关，就用int数组
    for(auto c : A){
        int val = static_cast<int>(c-'A');
        a[val]++; 
    }
    for(auto c : B){
        int val = static_cast<int>(c-'A');
        a[val]--;
        if(a[val]<0) return false;
    }
    return true;
}
//Method2.排序，轮询
bool StringContains(string &A, string &B){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //string的length和size操作有区别么
    for(int pa = 0, pb = 0; pb<b.length();){
        while((pa<a.length())&&(a[pa]<b[pb])){
            ++pa;
        }
        if((pa>=a.length())||(a[pa]>b[pb])){
            return false;
        }
        ++pb;
    }
    return true;
}
//时间O(mlogm)+O(nlogn)+O(m+n)

//Method3.素数对应
//方法很新颖，但素数相乘结果很容易导致整数溢出
//Method4.HashMap
//这就是和bool数组思想类似，但是依靠位操作实现。
bool StringContain(string &A, string &B){
    int hash = 0;
    for(int i=0; i<a.length(); ++i){
        hash |= (1<<(a[i]-'A'));
    }
    for(int i=0; i<b.length(); ++b){
        if((hash&(1<<(b[i]-'A')))==0){
            return false;
        }
    }
    return true;
}
//时间复杂度O(m+n),空间O(1)

//关于变位词：
//Method1.判断长度，排序，一一对应判等
//Method2.判断长度，维护char_count.
