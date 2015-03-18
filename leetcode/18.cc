//No.18
//https://leetcode.com/problems/4sum/
//4 Sum
class Solution {
public:
    /*
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size()<4) return result;
        sort(num.begin(),num.end());
        auto last = num.end();
        for(auto a = num.begin(); a<prev(last,3);++a){
            for(auto b = next(a); b<prev(last,2);++b){
                while(num[b+1]==num[b]){
                    ++b;
                }
                auto c = next(b);
                auto d = prev(last);
                
                while(c<d){
                    int sum = *a+*b+*c+*d;
                    if(sum<target){
                        ++c;    
                    }else if(sum>target){
                        --d;
                    }else{
                        result.push_back({*a,*b,*c,*d});
                        while(c<d && num[c]=num[c+1]) ++c;
                        while(c<d && num[d]=num[d-1]) --d;
                    }
                }
            }

        }
//        sort(result.begin(),result.end());
//        result.erase(unique(result.begin(),result.end()),result.end());
        return result;

    }
    */

        void search(vector<std::pair<int,int> > &pairs, int start, const int target, const vector<int> &num){
        int end = num.size()-1;
        while(start<end){
            int sum = num[start]+num[end];
            if(sum==target){
                pairs.push_back(make_pair(num[start],num[end]));
                while(start<end && num[start]== num[start+1]) ++start;
                ++start;
                while(start<end && num[end]==num[end-1]) --end;
                --end;
            }else if(sum>target)
                --end;
            else
                ++start;
        }
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > result;
        if(n<4) return result;
        std::sort(num.begin(),num.end());

        for(int a=0; a<n-3; ++a){
            if(num[a]+num[a+1]+num[a+2]+num[a+3]>target) break;
            for(int b=a+1; b<n-2; ++b){
                int sum = num[a]+num[b];
                vector<std::pair<int,int> > pairs;
                search(pairs, b+1, target-sum, num);
                if(!(pairs.empty())){
                    for(auto it = pairs.begin(); it !=pairs.end(); it++)
                        result.push_back(vector<int>{num[a],num[b],it->first,it->second});
                }
                while(b+1<n-2 && num[b+1]==num[b]) b++;
            }
            while(a<n-3 && num[a+1]==num[a]) a++;
        }
        return move(result);
    }
};
