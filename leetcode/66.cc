//No.66
//https://leetcode.com/problems/plus-one/
//Plus One
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        if(n==0) return digits;
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            int digit = (digits[i]+carry)%10;
            carry = (digits[i]+carry)/10;
            digits[i] = digit;
            if(carry==0)
                return digits;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};
