class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        vector<int> chk(n);
        
        for(int i =0;i<n;i++){
            if((s[i]+0)%2==0){
                chk[i]=0;
            }else{
                chk[i]=1;
            }
        }
        string mini = s;
        
        for(int i =0;i<n-1;i++){
            if(chk[i]==chk[i+1]){
                string temp = "";
                swap(s[i],s[i+1]);
                temp = s;
                swap(s[i],s[i+1]);
                if(temp<mini){
                    mini = temp;
                }
            }
        }
        return mini;
    }
};