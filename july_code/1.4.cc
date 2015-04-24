//判断回文数
bool IsPalindrome(const char *s, int n){
    if(s==nullptr || n<1) return false; //这个应该判断成非法输入么?还是直接判断ok
    char *front, *back;
    front = s;
    back = s+n-1;

    while(fonrt<back){
        if(*front != *back)
            return false;
        ++front;
        --back;
    }
    return true;
}
//直白 时间O(n), 空间O(1)

//Method2.从中间展开，向两头扩展

bool IsPalindrome(const char *s, int n){
    if(s==nullptr || n<1) return false;
    if(n==1) return true;
    char *first, *second;
    int m = (n>>1)-1;
    first = s+m;
    second = s+n-1-m;//可以省略对奇偶的判断
    while(first>=s){
        if(s[first--] != s[second++])
            return false;
    }
    return true;
}

//链表的回文判断
//如果是单向链表，可以对链表的后半部分进行逆置操作。
//
//借住一个栈，将全部字符串压入，再出栈，实际上就逆置了，对比就可以判断了
