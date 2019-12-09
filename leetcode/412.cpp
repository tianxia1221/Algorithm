//Runtime: 8 ms, faster than 59.87% of C++ online submissions for Fizz Buzz.
//Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Fizz Buzz.
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        ans.resize(n);

        int cur = 3;
        while(cur <= n){
            ans[cur - 1] = "Fizz";
            cur += 3;
        }

        cur = 5;
        while(cur <= n) {
            if(ans[cur - 1].length() > 0) {
                ans[cur - 1] = "FizzBuzz";
            }
            else{
                ans[cur - 1] = "Buzz";
            }
            cur += 5;
        }

        for(int i = 0; i<n; i++) {
            if(ans[i].length() == 0) {
                ans[i] = std::to_string(i+1);
            }
        }

        return ans;
    }
};

//Runtime: 4 ms, faster than 96.71% of C++ online submissions for Fizz Buzz.
//Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Fizz Buzz.
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        int j;
        for(int i=1; i<=n; i++){
            j = i - 1;
            if(i%3 == 0) {
                ans[j].append("Fizz");
            }

            if(i%5 == 0) {
                ans[j].append("Buzz");
            }

            if(ans[j].length() == 0)
                ans[j].append(to_string(i));
        }

        return ans;

    }
};