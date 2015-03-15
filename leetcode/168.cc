//No.168
//https://leetcode.com/problems/excel-sheet-column-title/
//Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        char tmp;
        while(n){
            n -= 1;
            tmp = 'A'+n%26;
            result = tmp+result;
            n /= 26;
        }
        return result;
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        return n==0?"":convertToTitle(n/26)+char(--n%26+'A');
    }
};
