class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26);
        for(char c:s){
            freq[c-'a']++;
        }
        int cnt =0;
        for(int i=0;i<26;i++){
            if(freq[i]<3){
                cnt += freq[i];
            }else{
                while(freq[i]>=3){
                    freq[i] -=2; 
                }
                cnt+=freq[i];
            }
        }
        return cnt;
        
    }
};