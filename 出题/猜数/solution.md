原题：[PE328 Lowest-cost Search](https://projecteuler.net/problem=328)， difficulty: 95%

用 $dp[l][r]$ 表示当前猜数范围为 $[l,r]$ 的最小总成本。显然有 $O(n^3)$ 的转移：

$dp[l][r]=\min\{\max(dp[l][k-1],dp[k+1][r])+k\}$ 

固定 $l,r$ ，随着 $k$ 的增大， 先是 $dp[l][k-1]< dp[k+1][r]$ ，再是 $dp[l][k-1]\ge dp[k+1][r]$ ，记决策点为 $k_0$ 。

不难得出后半部分长度以及决策点与右端点距离均为 $O(\frac{n}{\log n})$ 量级。

前半部分用单调队列维护，后半部分显然取 $dp[l][k_0-1]+k_0$ 。

设阈值 $S=\frac{n}{\log n}$ ，只需维护 $dp[1][i]$ 和 $dp[i-S+1$~$i][i]$ 即可。

时间复杂度 $O(\frac{n^2}{\log n})$ ，空间复杂度 $O(\frac{n^2}{\log ^2n})$ 。

Bonus: PE 题解区存在 $O(n\log n)$ 的做法，在 $n=10^7$ 下需 $3s$ ，有兴趣的可自行理解。