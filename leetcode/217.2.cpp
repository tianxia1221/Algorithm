class Solution {


public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		//   if(prerequisites.size() == 0) return true;

		vector<bool> v(numCourses, false);
		vector<bool> cv(numCourses, false);
		vector<vector<int>> e(numCourses);

		for (int i = 0; i < prerequisites.size(); i++) {
			e[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}

		for (int i = 0; i < numCourses; i++) {
			if (!v[i]) {
				if (hasCircle(e, v, cv, i)) return false;
			}
		}
		return true;
	}

	bool hasCircle(vector<vector<int>> &e, vector<bool>&v, vector<bool>&cv, int c) {
		v[c] = true;
		cv[c] = true;
		for (int i = 0; i < e[c].size(); i++) {
			if (!cv[e[c][i]]) {
				if (hasCircle(e, v, cv, e[c][i])) return true;
			}
			else {
				return true;
			}
		}
		cv[c] = false;
		return false;
	}

};