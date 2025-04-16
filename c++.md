### TD

#### lower_bound 

> \>=

#### upper_bound

> \>

##### define

```cpp
bool LowerCompare(Elem elem, int target) {
    return elem.val < target; //实现<
}
template<class ForwardIterator, class T, class Compare>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last,
                            const T& value, Compare comp)
{
    ForwardIterator it;
    std::iterator_traits<ForwardIterator>::difference_type count, step;
    count = std::distance(first,last);
 
    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (comp(*it, value)), // elem.val < target
            first = ++it;
            count -= step + 1;
        } else count = step;  // elem.val >= target !!!!!!!!
    }
    return first;
 }

// upper_bound找上边界（右），elem在上（右）
bool UpperCompare(int target, Elem elem) {
    return target < elem.val; //实现<
}
template<class ForwardIterator, class T, class Compare>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last,
                            const T& value, Compare comp)
{
    ForwardIterator it;
    std::iterator_traits<ForwardIterator>::distance_type count, step;
    count = std::distance(first,last);
 
    while (count > 0) {
        it = first; 
        step = count / 2;
        std::advance(it, step);
        if (!comp(value, *it)),  // target >= elem.val;
            first = ++it;
            count -= step + 1
        } else count = step;    // target < elem.val; !!!!!!!!!
    }
    return first;
}
```



##### Sample

```cpp
 				auto  uppcmp = [](int target, pair<int,int> elem) {
            return target < elem.first; //实现<
        };
        for (const int i: worker) {
            ans += (*(std::upper_bound(dd.begin(), dd.end(), i, uppcmp) - 1)).second;
        }
```



```cpp
struct Elem {
    int val = 0;
    Elem(int val): val(val) {}
};
// 自定义比较函数，目标是实现<操作，
// lower_bound找下边界（左），elem在下（左）
bool LowerCompare(Elem elem, int target) {
    return elem.val < target; //实现<
}

// upper_bound找上边界（右），elem在上（右）
bool UpperCompare(int target, Elem elem) {
    return target < elem.val; //实现<
}
//////////////////////////////////////////////////////////////////////
std::vector<Elem> vec = {1, 2, 4, 4, 4, 6, 7};
    int target = 4;

    // 使用自定义比较函数进行 lower_bound 查找
    auto lower = std::lower_bound(vec.begin(), vec.end(), target, LowerCompare);
    if (lower != vec.end()) {
        int lowerIndex = lower - vec.begin();
        std::cout << "Lower bound of " << target << " is at index: " << lowerIndex << " with value: " << lower->val<< std::endl; /// Lower bound of 4 is at index: 2 with value: 4
    } else {
        std::cout << "Lower bound of " << target << " not found!" << std::endl;
    }

    // 使用自定义比较函数进行 upper_bound 查找
    auto upper = std::upper_bound(vec.begin(), vec.end(), target, UpperCompare);
    if (upper != vec.end()) {
        int upperIndex = upper - vec.begin();
        std::cout << "Upper bound of " << target << " is at index: " << upperIndex << " with value: " << upper->val << std::endl; // Upper bound of 4 is at index: 5 with value: 6
    } else {
        std::cout << "Upper bound of " << target << " not found!" << std::endl;
    }

Lower bound of 4 is at index: 2 with value: 4
Upper bound of 4 is at index: 5 with value: 6
```



### Function 定义

#### Leetcode 150

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        map<string,function<int(int,int)>> m = 
        {
            {"+",[](int x,int y){return x + y;}},
            {"-",[](int x,int y){return x - y;}},
            {"*",[](int x,int y){return x * y;}},
            {"/",[](int x,int y){return x / y;}}
        };

        for(auto& str:tokens)
        {
            if(m.find(str) == m.end())//不存在,说明是数字
            {
                st.push(stoi(str));
            }
            else //碰到了操作符，计算
            {
                int right = st.top();//右操作数
                st.pop();
                int left = st.top();//左操作数
                st.pop();
                st.push(m[str](left,right));
            }
        }
        return st.top();
    }
};

```

```c++
function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0) return c == 0;
            int &res = cache[i][c];
            if (res != -1) return res;
            if (c < nums[i]) return res = dfs(i - 1, c);
            return res = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };
```



### 后序遍历

####  if(!t->right || t->right == pre) {

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode*> s;
        TreeNode* t;
        map<TreeNode*,bool> m;
        TreeNode* pre = NULL;
        while(root || !s.empty()){
            if(root){
                s.push(root);
                root = root->left;
                continue;
            }
            t = s.top();
            if(!t->right || t->right == pre) {
                s.pop();
                r.push_back(t->val);
                pre = t;
                continue;
            }
            root = t->right;          
        }
        return r;
    }
};
```



#### auto [t, n] = q.top()

```c++
class Solution {
public:
using pii = pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii> > eg(n+1);
        for(auto& E: eg) E.reserve(n+1);
        vector<int> vis(n+1);
        int ans = 0;
        for(auto& x: times){
            eg[x[0]].emplace_back(x[1], x[2]);
        }
        priority_queue<pii, vector<pii>, greater<pii> > q;
        q.emplace(0, k);
        while(q.size()){
            auto [time, now] = q.top();
            q.pop();
            if(vis[now])continue;
            ans = max(ans, time);
            vis[now] = true;
            for(auto [next, nextTime]: eg[now]){
                if(vis[next] == false) q.emplace(nextTime + time, next);
            }
        }
        return count(begin(vis)+1, end(vis), true) == n ? ans : -1;
    }
};
```



### 最小生成树

#### Kruskal

```c++
 class DisjointSetUnion {
private:
    vector<int> f, rank;
    int n;

public:
    DisjointSetUnion(int _n) {
        n = _n;
        rank.resize(n, 1);
        f.resize(n);
        iota(f.begin(), f.end(), 0);
    }

    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int unionSet(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        f[fy] = fx;
        return true;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dist = [&](int x, int y) {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };
        int n = points.size();
        DisjointSetUnion dsu(n);
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) { return a.len < b.len; });
        int ret = 0, num = 1;
        for (auto &[len, x, y] : edges) {
            if (dsu.unionSet(x, y)) {
                ret += len;
                if (++num == n) break;
            }
        }
        return ret;
    }
};

```

```c++
class Solution {
public:
    struct Edge{
        int a, b, w;
        bool operator<(const Edge& e) const {
            return w < e.w;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 1) return 0;
        //connections每一行是两个顶点和权重
        vector<Edge> connections;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                connections.push_back({i, j, 
                abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
            }
        }
        return minimumCost(n, connections);
    }
    //Kruskal 
    int minimumCost(int n, vector<Edge>& connections) {
        vector<int> parent = vector<int>(n);
        iota(begin(parent), end(parent), 0); // 算法函数 c++11引入
        //for(auto i: parent) cout << i << " ";
        //把所有边按权值进行排序
        sort(connections.begin(), connections.end());
        
        function<int(int)> find = [&](int x) { // 因为有递归调用， 不能写成 auto find
            return x == parent[x] ? x : parent[x] = find(parent[parent[x]]);
        };
        int res = 0;
        for (Edge& e : connections) {
            int pa = find(e.a);
            int pb = find(e.b);
            if (pa == pb) continue;
            parent[pb] = pa;
            res += e.w;
            if(--n==1) return res;
        }
        return -1;
    }
};
```



#### Prim

```c++
class Solution {

public:
    // prime 
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        using Pair = pair<int,int>; //(-weight, node v);
        vector<vector<Pair>> g(n);
        vector<int> seen(n, 0);

        if(n <= 1) return 0;

        // 1. construct graph
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                g[i].push_back({w, j});
                g[j].emplace_back(w, i);
            }
        }

        //2. get minimal edge by priority queue
        priority_queue<Pair> p;
        p.push({0, 0});
        while(n > 0) {
            const int w = -p.top().first;
            const int v = p.top().second;
            p.pop();

            if(seen[v]) continue;
            seen[v]++;
            for(auto& u: g[v]){
                if(seen[u.second]) continue;
                p.emplace(-u.first, u.second);
            }

            n--;
            res += w; // weight;
        }
        return res;
    }
    
};
```

