<center><font size=6>xay loves snacks</center>

时间限制 $\text{2000ms}$ 空间限制 $\text{512MB}$

#### Description

$\text{xay5421}$ 最近天天跑小店里买零食，然后手机就被没收了。支付宝莫得用，小小 $\text{xay5421}$ 只能从家里硬币罐子掏硬币来支付了。

我们假设 $\text{xay5421}$ 有 $n$ 种面值的硬币 $a_1,a_2,\cdots,a_n$ （可能相等）。

因为 $\text{xay5421}$ 是金钱掌控大师，所以 $n$ 特别大，且每种硬币都有无限枚；

因为 $\text{xay5421}$ 是随机掏钱大师，所以 $a_1,a_2,\cdots,a_n$ 都是 $[2,m]$ 的随机数；

~~可惜 $\text{xay5421}$ 不是时间管理大师~~。

但是，$\text{xay5421}$ 发现了一个致命的问题，那就是用支付宝可以支付任意的金额，但是硬币就不一定了，可能会出现无法支付的金额。

现在，$\text{xay5421}$ 想知道，最大不能支付的金额是多少呢？

#### Input

第一行，输入三个数 $n, m$ 和 $seed$ 。

对于 $a_1,a_2,\cdots,a_n$ ，采用如下方式生成（需开启 `-std=c++11` ）：

```cpp
int main() {
  scanf("%d%d%d", &n, &m, &seed);
  mt19937 rng(seed);
  auto get = [&]() {
    uniform_int_distribution<int> qwq(2, m);
    return qwq(rng);
  };
  for (int i = 1; i <= n; i++) {
    a[i] = get();
  }
}
```

#### Output

输出最大不能支付的金额。

#### Sample Input1

```
5 5 3
```

#### Sample Output1

```
1
```

#### Explanation1

**注意，样例仅作为参考。该数据范围不会出现在最终测试数据中，下同。**

生成的 $a$ 序列为 `4 2 4 5 3` 。最大不能被支付的金额显然是 `1` 。

#### Sample Input2

```
2 100 10
```

#### Sample Output2

```
2309
```

#### Explanation2

生成的 $a$ 序列为 `78 31` 。最大不能被支付的金额是 `2309` 。你问我为啥，我只能说：小凯的疑惑。 

#### Sample Input3

```
3 100 10
```

#### Sample Output3

```
89
```

#### Explanation3

生成的 $a$ 序列为 `78 31 4` 。最大不能被支付的金额是 `89` 。你问我为啥，我只能说：蛤？无可奉告！

#### Sample Input4

```
50 50000000 97
```

#### Sample Output4

```
50215765
```

#### Sample Input5

```
100 100000000 114514
```

#### Sample Output5

```
59493065
```

#### Sample Input6

```
50 100000000 114514
```

#### Sample Output6

```
96349667
```

#### Constraints

对于前 $10\%$ 的数据，$n\le100, m\le 100 $ ；

对于前 $30\% $ 的数据，$n\le100,m\le 10000$ ；

对于另外 $5\%$ 的数据，$n=10000000,m\le 100$ ；

对于另外 $5\%$ 的数据，$n=114514,m=1919810,seed=19260817$ ；

对于另外 $5\%$ 的数据，$n=1919810,m=10^6,seed=114514$ ；

对于前 $60\%$ 的数据，$2\le m\le 10^7$ ；

对于前 $80\%$ 的数据，$2\le m\le 5\times 10^7$ ；

对于 $100\%$ 的数据，$50\le n\le 10^7,2\le m\le 10^8, 0\le seed<2^{31}$ 。

数据有梯度，~~祝大家乱搞愉快~~！