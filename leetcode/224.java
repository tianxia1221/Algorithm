class Solution {
    private enum State {BEGIN, NUM, OPT}

    ;

    public int calculate(String s) {
        State state = State.BEGIN;
        int num = 0;
        boolean canComp = false;
        Stack<Integer> data = new Stack<Integer>();
        Stack<Character> sign = new Stack<Character>();
        char cur;
        for (int i = 0; i < s.length(); i++) {
            cur = s.charAt(i);
            if (cur == ' ') continue;
            switch (state) {
                case BEGIN:
                    if (cur >= '0' && cur <= '9') {
                        state = State.NUM;
                    } else {
                        state = State.OPT;
                    }
                    i--;
                    break;
                case NUM:
                    if (cur >= '0' && cur <= '9') {
                        num = num * 10 + (cur - '0');
                    } else {
                        data.push(num);
                        // 1 + 2 +
                        if (canComp == true) compute(data, sign);
                        num = 0;
                        state = State.OPT;
                        i--;
                    }
                    break;
                case OPT:
                    if (cur == '+' || cur == '-') {
                        canComp = true;
                        //   state = State.NUM;
                        sign.push(cur);
                    } else if (cur >= '0' && cur <= '9') {
                        state = State.NUM;
                        i--;
                    } else if (cur == '(') {

                        canComp = false;
                        state = State.NUM;
                    } else if (cur == ')') {
                        System.out.println("))");
                        compute(data, sign);
                    }
                    break;
                default:
                    break;
            }

        }
        if (num != 0) {
            data.push(num);
            compute(data, sign);
        }

        if (data.empty()) return 0;

        return data.peek();
    }

    void compute(Stack<Integer> data, Stack<Character> sign) {
        if (data.size() < 2 || sign.size() < 1) return;
        int data1 = data.pop();
        int data2 = data.pop();
        char opt = sign.pop();
        data.push(opt == '+' ? data2 + data1 : data2 - data1);
    }
}