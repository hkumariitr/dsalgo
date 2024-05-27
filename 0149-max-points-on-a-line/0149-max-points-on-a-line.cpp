class Solution {
public:
    int gcd(int a, int b){
        return b==0 ?a:gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<string,int> mpp;
        int maxi = 1;
        for(int i =0;i<n;i++){
            int x1 = points[i][0], y1 = points[i][1];
            cout<<"looking for point ("<<x1<<y1<<")"<<endl;
            string key;
            for(int j = i+1;j<n;j++){
                int x2 = points[j][0], y2 = points[j][1];

                int deltax = x2-x1, deltay = y2-y1;
                int divisor = gcd(deltax,deltay);
                key = to_string(deltax/divisor)+"."+ to_string(deltay/divisor);
                mpp[key]++;
                cout<< "Updating for "<<key<<" as "<<mpp[key]<<endl;
                maxi = max(maxi, mpp[key] +1);
            }
            mpp.clear();

        }
        return maxi;
    }
};