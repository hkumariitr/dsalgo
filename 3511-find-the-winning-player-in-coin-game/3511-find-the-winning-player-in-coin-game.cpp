class Solution {
public:
    string losingPlayer(int x, int y) {
        if (x<1 && y<4) return "Bob";
        bool aliceWin = false;
        while(x>=1 && y>=4){
            x -=1;
            y -=4;
            aliceWin = !aliceWin;
        }
        if(aliceWin){
            return "Alice";
        }else{
            return "Bob";
        }
    }
};