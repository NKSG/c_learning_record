//No.67
//https://leetcode.com/problems/add-binary/
//Add Binary
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int apos = a.size()-1;
        int bpos = b.size()-1;
        int adigit, bdigit, carry = 0;
        while(apos>=0||bpos>=0||carry==1){
            adigit = bdigit = 0;
            if(apos>=0) adigit = a[apos--]=='1';
            if(bpos>=0) bdigit = b[bpos--]=='1';
            result = static_cast<char>(adigit^bdigit^carry+'0')+result;
            carry = adigit + bdigit + carry >=2;
        }
        return result;
    }
};
