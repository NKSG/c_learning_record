//Method1.
//枚举中心，两边扩展判断
//但需要对奇偶不同情况进行判断，比较繁琐。

int LongestPalindrome(const char *s, int n){
    int i,j,c;
    if(s==0||n<1) return 0;
    int max = 0;

    for(i=0;i<n;++i){
        for(j=0;(i-j)>0 && (i+j<n); ++j){
            if(s[i-j]!=s[i+j])
                break;
            c = j*2+1;
        }
        if(c>max)
            max = c;
        for(j=0;(i-j>=0)&&(i+j+1<n);++j){
            if(s[i-j]!=s[i+j+1])
                break;
            c = j*2+2;
        }
        if(c>max)
            max = c;
    }
    return max;
}

//Method2.
//不用考虑奇偶的不同情况，引入Manacher算法。线性复杂度O(n)
//就是那个插入#号的方法，将整个字符串变成奇数的情况
//用P[i]纪录以字符S[i]为中心的最长回文子串向左右扩张的长度（包括S[i]）
//P[i]-1是原字符串中最长回文串总长度。
//辅助变量两个，id,mx.
//id表示最大回文子串中心位置，mx为id+P[id]，也就是最大回文子串边界。
//mx>i 则P[i] >= Min(P[2*id-i],mx-i)
//



int LongestPalindrome(const char *s, int n){
    
    //preProcess
    int p[1000], mx=0, id=0;
    memset(p,0,sizeof(p));
    for(int i=1; s[i]!='\0'; i++){
        p[i] = mx>i?min(p[2*id-i],mx-i):1;
        while(s[i+p[i]] == s[i-p[i]])
            p[i]++;
        if(i+p[i]>mx){
            mx = i+p[i];
            id = i;
        }
    }
    //find max p[i]

}
