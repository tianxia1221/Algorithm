class Solution {
    
    
public:
    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size()==0 && s2.size()==0 && s3.size() == 0) return true;
        
        if(s1.size()==0 ) return s3==s2;
        if(s2.size()==0 ) return s3==s1;
        
        vector<vector<bool> > v(s1.size()+1,vector<bool>(s2.size()+1,false));
        
        v[0][0] = false;
        for(int i=1; i<=s1.size(); i++){
            v[i][0] = (s1[i-1] == s3[i-1]);
            if(!v[i][0]) break;
        }
        
        for(int i=1; i<=s2.size(); i++){
            v[0][i] = s2[i-1] == s3[i-1];
            if(!v[0][i]) break;
        }
        
        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                v[i][j] = (v[i-1][j] && s1[i-1] == s3[i+j-1])
                    ||(v[i][j-1] && s2[j-1] == s3[i+j-1]) ;
            }
        }
        
        return v[s1.size()][s2.size()];
        
    }
};


class Solution {
    
    
public:
    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size()==0 && s2.size()==0 && s3.size() == 0) return true;
        
        
        vector<vector<int>> v(s1.size(),vector(s3.size(), INT_MIN));
        
        return helper(s1, s2, s3, s1.size()-1, s2.size()-1, s3.size()-1, v);
    }
    
    bool helper(string s1, string s2, string s3, int end1, int end2, int end3, vector<vector<int>>&v){
        if(end1 < 0) {
            string left2 = s2.substr(0,end2+1);
            string left3 = s3.substr(0,end3+1);
            return left2 == left3;   
        }
        
        if(end2 < 0) {
            string left1 = s1.substr(0, end1+1);
            string left3 = s3.substr(0, end3+1);
            return left1 == left3;   
        }
        
        if(v[end1][end3] != INT_MIN) return v[end1][end3];
        
        //s1 match s3 end char
        if(s1[end1] == s3[end3]){
            v[end1][end3] = helper(s1, s2, s3, end1-1, end2, end3 -1 ,v);
            if(v[end1][end3]) return true;
        }

        //s2 match s3 end char
        if(s2[end2] == s3[end3]){
            return v[end1][end3] = helper(s1, s2, s3, end1, end2-1, end3 -1 ,v);
        }

        return v[end1][end3] = false;
    }
};

class Solution {
    
    
public:
    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.size()==0 && s2.size()==0 && s3.size() == 0) return true;
        
        vector<vector<vector<int>>> v(s1.size(),vector<vector<int>>(s2.size(), vector<int>(s3.size(), INT_MIN)));
        
        return helper(s1, s2, s3, s1.size()-1, s2.size()-1, s3.size()-1, v);
    }
    
    bool helper(string s1, string s2, string s3, int end1, int end2, int end3, vector<vector<vector<int>>>&v){
        
        
        cout << "end1:" << end1 <<"  end2:"<<end2 <<"  end3:"<< end3 <<endl;
        
        if(end1 < 0) {
            string left2 = s2.substr(0,end2+1);
            string left3 = s3.substr(0,end3+1);
            if(left2 != left3) {                
                return false;
            }else{                 
                return true;
            }       
        }
        
        if(end2 < 0) {
            string left1 = s1.substr(0, end1+1);
            string left3 = s3.substr(0, end3+1);
            if(left1 != left3) {                 
                return false;
            }else{                
                return true;
            }       
        }
        
        if(v[end1][end2][end3] != INT_MIN) return v[end1][end2][end3];
        
        //s1 match s3 end char
        if(s1[end1] == s3[end3]){
            v[end1][end2][end3] = helper(s1, s2, s3, end1-1, end2, end3 -1 ,v);
            if(v[end1][end2][end3]) return true;
        }

        //s2 match s3 end char
        if(s2[end2] == s3[end3]){
            return v[end1][end2][end3] = helper(s1, s2, s3, end1, end2-1, end3 -1 ,v);
        }

        return v[end1][end2][end3] = false;
    }
};
