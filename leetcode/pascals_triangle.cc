//No.118
//https://leetcode.com/problems/pascals-triangle/
class Solution{
public:
    vector<vector<int> > generate(int numRows){
        vector<vector<int> > result;
        if (numRows == 0) return result;
        result.push_back(vector<int>(1,1));
        for(int i=2; i<= numRows; ++i){
            vector<int> current(i,1);
            const vector<int> &prev = result[i-2];
            for(int j=1; j<i-1; ++j){
                current[j] = prev[j]+prev[j-1];
            }
            result.push_back(current);
        }
        return result;
    }

    vector<vector<int> > generate2(int numRows){
        vector<vector<int> > result;
        vector<int> array;
        for(int i=1; i<= numRows; ++i){
            for(int j=i-2; j>0 ; j--){
                array[j] = array[j-1]+array[j];
            }
            array.push_back(1);
            result.push_back(array);
        }
        return result;
    }
};
