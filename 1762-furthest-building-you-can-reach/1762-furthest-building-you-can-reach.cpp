class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();
        for(int i = 0;i<n;i++){
            if(i==n-1){
                return n-1;
            }
            int diff = heights[i+1]-heights[i];
            if(diff>0){
                if(bricks>=diff){
                    bricks -=diff;
                    pq.push(diff);
                }else if(ladders>0){
                    if(!pq.empty()){
                        int max_bused = pq.top();
                        if(diff<max_bused){
                            bricks+=max_bused;
                            bricks-=diff;
                            pq.pop();
                            pq.push(diff);
                            ladders--;
                        }else{
                            ladders--;
                        }
                    }else{
                        ladders--;
                    }
                }else{
                    return i;
                }
            }
        }
        return -1;
    }
};