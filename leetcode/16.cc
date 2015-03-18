//No.16
//https://leetcode.com/problems/3sum-closest/
//3 Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        std::sort(num.begin(),num.end());
        for(auto a = num.begin(); a!=prev(num.end(),2); ++a){
            auto b = next(a);
            auto c = prev(num.end());
            while(b<c){
                const int sum = *a+*b+*c;
                const int gap = abs(sum-target);
                if(gap<min_gap){
                    result = sum;
                    min_gap = gap;
                }
                if(sum<target)
                    ++b;
                else
                    --c;
            }
        }
        return result;
    }

    
    int threeSumClosest(vector<int> &num, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        std::sort(num.begin(),num.end());
        int size = num.size();
        for(int a=0; a<size-2; ++a){
            int b=a+1;
            int c=size-1;
            while(b<c){
                int sum = num[a]+num[b]+num[c];
                int gap = abs(sum-target);
                if(gap<min_gap){
                    min_gap = gap;
                    result = sum;
                }
                if(sum<target)
                    ++b;
                else
                    --c;
            }
        }
        return result;
    }

};


