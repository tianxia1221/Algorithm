class Solution {
    enum STATE{
        START,
        RUNING,
        SPACE,
    }

    int long2int(long res) {
        if(res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        else if(res<Integer.MIN_VALUE) return Integer.MIN_VALUE;
        return (int)res ;
    }

    public int myAtoi(String str) {
        int n = str.length();
        long res = 0;
        STATE state = STATE.START;
        char c;
        int i=0;
        int sign = 1;
        while(i<n){
            c = str.charAt(i++);
            switch(state){
                case START:
                    if(c >= '0' && c <='9') {
                        state = STATE.RUNING;
                        i--;
                    }
                    else if(c=='+') {
                        state = STATE.RUNING;
                    }
                    else if(c=='-') {
                        state = STATE.RUNING;
                        negtive = -1;
                    }
                    else if(c==' ') {
                        state = STATE.SPACE;
                    }
                    else {
                        return 0;
                    }
                    break;
                case SPACE:
                    if(c >= '0' && c <='9') {
                        state = STATE.RUNING;
                        i--;
                    }
                    else if(c=='+') {
                        state = STATE.RUNING;
                    }
                    else if(c=='-') {
                        state = STATE.RUNING;
                        negtive = -1;
                    }
                    else if(c==' ') {
                        continue;
                    }
                    else {
                        return 0;
                    }
                    break;
                case RUNING:
                    if(res*sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
                    else if(res*negtive<Integer.MIN_VALUE) return Integer.MIN_VALUE;

                    if(c >= '0' && c <='9') {
                        res = res*10 + ( c-'0');
                    }
                    else{
                        return long2int(res * negtive);
                    }
                    break;
                default:
                    break;
            }
        }
        return long2int(res * sign);
    }
}