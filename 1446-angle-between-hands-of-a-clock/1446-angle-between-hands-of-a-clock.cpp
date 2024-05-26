class Solution {
public:
    double angleClock(int hour, int minutes) {
        double first = (hour ==12)?(static_cast<double>(minutes) / 12): (static_cast<double>(minutes) / 12) + hour * 5;
        double second = minutes;
        cout<< first <<" "<<second<<endl;
        double ans = (first>=second)? (first-second)*6 : (second-first)*6;
        return min(ans,360-ans);
        // cout<<first<<endl;
        // double second;
        // if (hour ==12){
        //     first = minutes/60;
        // }else{
        //     first = hour*5 + (minutes/60)*5;
        // }
        // cout<<first;
        // double diff = (minutes > hour)?minutes -hour : hour-minutes;
        // return diff*6;

    }
};