//No.171
//https://leetcode.com/problems/excel-sheet-column-number/
//excel_sheet_column_number
class Solution {
public:
    int titleToNumber(string s) {
       int ans = 0;
       for(int i=0; i<s.size(); i++){
           ans = ans*26+(s.at(i)-'A'+1);
       }
       return ans;
    }
};
