//旋转字符串
//Method1.暴力移位
void LeftShiftOne(char* s, int n){
    char temp = s[0];
    for(int i=1; i<n; i++){
        s[i-1] = s[i];
    }
    s[n-1] = temp;
}

void LeftRotateString(char* s, int n, int m){
    while(m--){
        LeftShiftOne(s,n);
    }
}

//时间O(m*n),空间O(1)

//Method2.3步反转
void ReverseString(char* s, int from, int to){
    while(from<to){
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void LeftRotateString(char* s, int n, int m){
    m %= n;//若要左移大于n位，和％n相当。
    //这个简化应该记住。
    ReverseString(s,0,m-1);
    ReverseString(s,m,n-1);
    ReverseString(s,0,n-1);
}
