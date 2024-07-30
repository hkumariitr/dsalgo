class Solution {
public:
    bool isUgly(int n) {
        if(n==0) return false;
        while(n%2==0){
            n = n/2;
        }
        cout<<"checked 2 "<<n<<endl;
        while(n%3==0){
            n /= 3;
        }
        cout<<"checked 3 "<<n<<endl;
        while(n%5==0){
            n/= 5;
        }
        cout<<"checked 5 "<<n<<endl;

        if(n==1) return true;
        return false;
    }
};