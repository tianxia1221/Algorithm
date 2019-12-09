//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Two Integers.
//Memory Usage: 8.3 MB, less than 8.33% of C++ online submissions for Sum of Two Integers.
class Solution {
public:
    int getSum(int a, int b) {
        int size = sizeof(int) * 8;
        int mask = 1;
        int res = 0;
        int lastHasCarry = 0;
        int curBitResult;
        int curHasCarry = false;
        for(int i=0; i< size; i++) {
            getBitSum(a&mask, b&mask, curBitResult, curHasCarry, lastHasCarry);
            res = res | curBitResult;
            if(i!=size - 1) {
                lastHasCarry = curHasCarry << (i+1);
                mask = mask << 1;
            }
        }

        return res;
    }

    void getBitSum(int a, int b, int& result, int& curHasCarry, int lastHasCarry) {
        result = a ^ b ^ lastHasCarry;
        curHasCarry = (a && b) || (a && lastHasCarry) || (b && lastHasCarry);
    }
};
//
//Line 9: Char 25: runtime error: left shift of negative value -2147483648 (solution.cpp)
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;

        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }

        return sum;
    }
};