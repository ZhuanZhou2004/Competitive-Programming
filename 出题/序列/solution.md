做法一

定义 $L(k)$ 表示权值 $\le k$ 的 $n$ - 小 X 序列个数，问题转化为求 $\sum_{k=0}^{n-1} \left(n^n-L(k)\right)$ 。

对于一个 $k$ ，用 $dp[i]$ 表示长度为 $i$ 的小 X 序列个数，显然有：

- $1\le i\le k$ ，$dp[i]=n\times dp[i-1]$ 
- $i=k+1$ ，$dp[i]=n\times dp[i-1]-n$ 
- $i>k+1$ ，$dp[i]=n\times dp[i-1]-(n-1)\times dp[i-k-1]$ 

时间复杂度 $O(n^2)$ 。

考虑该 dp 式的组合意义，相当于走楼梯，往上走 1 步贡献 * n，往上走 $k+1$ 步贡献 * -(n-1) 。

枚举走的第一步是哪种以及走的 $k+1$ 步数，可得方案：

$$\sum\limits_{i=0}^{n/(k+1)}\left(n^{n-i(k+1)}(1-n)^i\binom{n-i(k+1)+i-1}{i}-n^{n-i(k+1)+1}(1-n)^{i-1}\binom{n-i(k+1)+i-1}{i-1}\right)$$

时间复杂度 $O(n\ln n)$ 。

做法二

求 $L(k)$ 的问题转化为把长为 $n$ 的小 X 序列分成 $i$ 段，每段长度为 $[1,k]$ ，答案的贡献即为 $n\times (n-1)^{i-1}$ 。

钦定 $j$ 段长度 $>k$ ，则方案数为 $\binom{i}{j}\binom{n-jk-1}{i-1}$ 。

枚举段数，二项式反演：

$$\sum\limits_{i=1}^{n}n(n-1)^{i-1}\sum\limits_{j}(-1)^j\binom{i}{j}\binom{n-jk-1}{i-1}$$ 

因此所有的 $L(k)$ 之和为：

$$\sum\limits_{k=0}^{n-1}\sum\limits_{i=1}^{n}n(n-1)^{i-1}\sum\limits_{j}(-1)^j\binom{i}{j}\binom{n-jk-1}{i-1}$$ 

化简一下即可，时间复杂度 $O(n\ln n)$ 。

