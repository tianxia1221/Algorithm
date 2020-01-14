class Solution {
public:
    string minWindow(string s, string t) {
        string ret;
        vector<int> s_num(128, 0);
        vector<int> t_num(128, 0);
        int begin = 0;
        int len = INT_MAX;
        for(int i=0; i<t.size(); i++) t_num[t[i]]++;

        for(int i=0; i<s.size(); i++) {
            s_num[s[i]]++;
            while(begin < i) {
                if(t_num[s[begin]] == 0) begin++;
                else if(s_num[s[begin]] > t_num[s[begin]]) {
                    s_num[s[begin]]--;
                    begin++;
                }
                else {
                    break;
                }
            }
            if(is_ok_window(s_num, t_num)) {
                int size =  i-begin+1;
                if(len > size) {
                    len = size;
                    ret = s.substr(begin, size);

                }
            }
        }

        return ret;
    }

    bool is_ok_window(vector<int> &s, vector<int> &t) {
        for(int i=0; i<t.size(); i++) {
            if(s[i] < t[i] ) return false;
        }
        return true;
    }
};