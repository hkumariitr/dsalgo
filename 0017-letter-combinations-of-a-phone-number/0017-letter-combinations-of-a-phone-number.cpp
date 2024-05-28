class Solution {
public:
    void solve(unordered_map<char,string> &mpp, vector <string> &ans,string temp,int i,string digits){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }

        for(char ch: mpp[digits[i]]){
            
            solve(mpp,ans,temp +ch,i+1,digits);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        if(digits.empty()){
            return ans;
        }
        string temp;
        unordered_map<char,string> mpp {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8', "tuv"},
            {'9',"wxyz"}
        };

        solve(mpp,ans,temp,0,digits);

        return ans;
    }
};