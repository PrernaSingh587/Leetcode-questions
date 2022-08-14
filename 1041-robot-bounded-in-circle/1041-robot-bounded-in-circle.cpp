class Solution {
public:
    char switchDir(char dir, char p ) {
        if(dir =='L') {
            switch(p) {
                case 'n':
                    p='w';
                    break;
                case 's':
                    p='e';
                    break;
                case 'w' :
                    p='s';
                    break;
                case 'e' :
                    p='n';
                default :
                    break;
            }
        } else if(dir == 'R') {
            switch(p) {
                case 'n':
                    p='e';
                    break;
                case 's':
                    p='w';
                    break;
                case 'w' :
                    p='n';
                    break;
                case 'e' :
                    p='s';
                default :
                    break;
            }
        }
        return p;
    }
    bool isRobotBounded(string s) {
        int n=s.size();
        int x=0,y=0;
        char p = 'n';
        for(char c : s) {
            if(c=='G') {
                switch(p) {
                    case 'n' : 
                        y++;
                        break;
                    case 's' :
                         y--;
                        break;
                    case 'e' :
                        x++;
                        break;
                    case 'w' :
                        x--;
                        break;
                    default : 
                        break;
                }   
            } else {
               p = switchDir(c,p);
            }
        }
        if(x==0 && y==0) return 1;
        if(p == 'n') return 0;
        return 1;
            
    }
};