### 字符串

- string 类的 [substr](https://zh.cppreference.com/w/cpp/string/basic_string/substr) 方法

  `basic_string substr( size_type pos = 0, size_type count = npos ) const;` 返回子串 `[pos, pos+count)` 。若请求的字串越过字符串的结尾，即 `count` 大于 size() - pos （例如若 count == npos ），则返回的子串为 `[pos, size())` 。

  ```cpp
  // count 为 npos ，返回 [pos, size())
  std::string sub1 = a.substr(10);
  // pos 和 pos+count 都在边界内，返回 [pos, pos+count)
  std::string sub2 = a.substr(5, 3);
  // pos 在边界内， pos+count 不在，返回 [pos, size()) 
  std::string sub4 = a.substr(a.size()-3, 50);
  
  // static const size_type npos = -1;
  // npos 是无符号类型的最大值
  ```

- string 类的 `stoi`、`stod` 等方法
  
  ```cpp
  try {
      double n = stod(s);
  } catch (std::invalid_argument e) {
      // ...
  }
  ```
  
- string 类的 `find` 方法
  
  ```cpp
  if (s.find('c') != string::npos) { /*...*/ }
  ```
  
- string 类的 `insert` 方法

  PAT 中通常使用下标版本：`s.insert(pos, args)` 在下标 `pos` 前插入 `args` 指定的字符，`args` 可以是：

  - `str` 字符串
  - `str, pos, len` str 中从 pos 开始最多 len 个字符
  - `cp, len` 从 cp 指向的字符数组的前 len 个字符
  - `n, c` n 个字符 c
  
- 泛型算法 `replace`

  输入接受 4 个参数，前两个指定范围，第三个是要搜索的值，第四个是要替换的新值：

  ```cpp
  // 将所有值为 0 的元素替换为 42
  replace(ilst.begin(), ilst.end(), 0, 42);
  ```

- 字符串 IO

  ```cpp
  char str[99];
  sprintf(str, "1 + 1 = %d", 2); // 输出到字符串
  sscanf(str, "%d", &n); // 从str中读取
  
  // 类似的，C++中把 string 作为流读写：
  #include <sstream>
  stringstream ss; // 可以把 ss 当做 cout 和 cin 用
  ```

- :warning: 在对字符串操作时，本意想添加字符数字，应该像这样：`int i; s.push_back(i + '0');`

- :warning: 把字符串当做数字读入时，一定要当心前面可能含有前导0，在输出时一定要使用格式控制进行补全。

### 容器

- 基础的顺序容器常见的有：`vector`、`deque`、`string`，`queue` 是基于 `deque` 实现的容器适配器。
  其中只有 `deque` 支持 `pop_front` 和 `push_front` 操作。
  
- `vector<T>` 、`queue<T>` 等容器的尾部构造：`c.emplace_back(args)`。参数 `args` 是 `T` 的构造函数的参数，不要加花括号！

- `insert` 插入元素

  ```cpp
  c.insert(p, t); // p 之前插入元素 t
  c.insert(p, n, t); // p 之前插入 n 个元素 t
  c.insert(p, v.begin(), v.end()); // 把迭代器范围内的插入到 p 之前
  ```

  

### 排序

- `map` 或 `unordered_map` 也可以使用 `sort` 函数按值排序
- `sort` 是不稳定排序，`stable_sort` 稳定排序

### 数学

- `<cmath>` 头文件中一些常用函数

  - `round()` 四舍五入
  - `ceil()` 向上取整
  - `floor()` 向下取整
  - `abs()` 取绝对值
  - `pow(x, y)` x 的 y 次幂 
  - `exp()` e 的给定次幂 `exp2()` 2 的给定次幂
  
- 判断素数方法

  ```cpp
  bool isPrime(int n) {
      if (n == 0 || n == 1) return false;
      for (int i = 2; i * i <= n; i++)
          if (n % i == 0) return false;
      return true;
  }
  
  // 快速方法
  bool isPrime(long long num){
      // 特殊情况
      if (num <= 3) return num > 1;
      // 不在 6 两侧的一定不是素数
      if (num%6 != 1 && num%6 != 5) return false;
      // 在 6 两侧的也有可能不是素数
      // 在 6 两侧的数如果不是素数必然有一个在 6 两侧的因数
      for (long long i = 5; i <= sqrt(num); i+=6){
          if (num % i == 0 || num % (i+2) == 0) return false;
      }
      return true;
  }
  ```

  

### 其他

- :warning: PAT 有时不会对题目描述得很清楚，但应该按照常识尽可能考虑周全。比如 1016，当消费者没有产生消费时（包含一些应该忽略的错误记录），则应该没有账单，即不输出任何东西。

### 单词

| 英文                  | 中文         |
| --------------------- | ------------ |
| prime                 | 素数         |
| 2 decimal places      | 小数点后两位 |
| At the mean time      | 同时         |
| since that            | 因为         |
| chronologically       | 按时间顺序   |
| chronological order   | 按时间顺序   |
| It is guaranteed that | 可以保证     |
|                       |              |
|                       |              |
| charge                | 收费         |
| determine by          | 取决于       |
| denoting              | 表示         |
