struct struct_cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

class class_cmp {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

bool fun_cmp(int a, int b) {
	return a > b;
}

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// sort(coins.begin(), coins.end(), fun_cmp);
		// for(auto i: coins) cout << i << " :fun_cmp" << endl;
		// sort(coins.begin(), coins.end(), class_cmp());
		// for(auto i: coins) cout << i << " :class_cmp()" << endl;
		// sort(coins.begin(), coins.end(), struct_cmp());
		// for(auto i: coins) cout << i << " struct_cmp()" << endl;
		sort(coins.begin(), coins.end(), greater<int>());
		//  for(auto i: coins) cout << i << " greater<int>()" << endl; //result oriented, not compare sign

		unordered_map<int, int> map;
		return helper(coins, amount, map);
	}

	int helper(vector<int>& coins, int amount, unordered_map<int, int> &map) {
		if (map.find(amount) != map.end()) return map[amount];
		if (amount == 0) return map[0] = 0;

		map[amount] = INT_MAX;
		int tmp = 0;
		for (int i = 0; i < coins.size(); i++) {
			tmp = amount - coins[i];
			if (tmp < 0) continue;
			helper(coins, tmp, map);
			if (map[tmp] != -1 && (map[tmp] + 1 < map[amount])) {
				map[amount] = map[tmp] + 1;
			}
		}

		if (map[amount] == INT_MAX) {
			map[amount] = -1;
		}

		return map[amount];
	}
};