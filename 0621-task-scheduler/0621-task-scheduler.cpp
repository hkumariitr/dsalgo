class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(char ch: tasks){
            mp[ch-'A']++;
        }
        sort(mp.begin(),mp.end());
        for(auto ch:mp){
            cout<< ch <<" ";
        }
        int gaps = mp[25] -1;
        int slots = gaps*n;

        for(int i =24;i>=0;i--){
            slots -= min(mp[i],gaps);
        }

        if(slots>0){
            return tasks.size() +slots;
        }
        
        return tasks.size();
        

        return 0;
    }
};