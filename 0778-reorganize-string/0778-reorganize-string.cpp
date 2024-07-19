class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26,0);
        using p = pair<int,char>;
        int n = s.size();

        for(char ch:s){
            count[ch-'a']++;
            if(count[ch-'a']>(n+1)/2) return "";
        }

        priority_queue<p> pq;

        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']>0){
                pq.push({count[ch-'a'],ch});
            }
        }
        string ans = "";
        while(pq.size()>=2){
            auto P1 = pq.top();
            pq.pop();
            auto P2 = pq.top();
            pq.pop();
            ans.push_back(P1.second); P1.first--;
            ans.push_back(P2.second); P2.first--;

            if(P1.first>0) pq.push(P1);
            if(P2.first>0) pq.push(P2);            
        }
        
        while(!pq.empty()){
            auto P = pq.top();
            pq.pop();
            ans.push_back(P.second);
        }
        return ans;
    }
};