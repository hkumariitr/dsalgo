class Solution {
public:
    string longestPalindrome(string s) {
        string result= "";
        if(s.size()==1){
            return s;
        }
        int max =1;
        for(int i =0;i<s.size();i++){
            int left =i,right = i;

            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(right-left+1 >= max){
                    max = right-left+1;
                    result = s.substr(left,right-left+1);
                }
                left--;
                right++;
            }
            left =i;
            right = i+1;

            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(right-left+1 > max){
                    max = right-left+1;
                    result = s.substr(left,right-left+1);
                }
                left--;
                right++;
            }
        }
        cout<<max;
        return result;
    }
};