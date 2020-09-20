









## Priority Queue

```c++
        auto cmp = [](int a, int b) {
            return dis[a] < dis[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp); //大顶堆
```

## auto

### pair

```c++
 queue<pair<int, double>> q;
 q.emplace(start, 1.0);
 auto [cur, pr] = q.front(); q.pop();
 
```

### function

```
        auto cmp = [](int a, int b) {
            return dis[a] < dis[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp); //大顶堆
```

## MOD



> ` if(res >= MOD) res -= MOD`  替代 `%MOD`

## Bit Operation

```c++
int __builtin_ffs (unsigned int x)
返回二进制表示中 x 的最后一位  1 （最右边的）是从后向前第几位，比如 7368(1110011001000) 返回 4 。
```

## 运算符优先级

高 -> 低  [ 算术 -- 移位  --- 比较 ---位运算 - 逻辑 ]