对于 $n,m$ 较小的情况，猜测最大不能被表示的数不太大，那么就可以直接跑完全背包，用 bitset 优化。

不妨假设 $k = \min\limits_{i=1}^{n} a_i$ ，对于模 $k$ 跑同余最短路，$dis[i]$ 表示最小的模 $k=i$ 的数，则 $dis[i]+ki$ 均可被表示出来（不停加入 $k$ ），因此答案就是 $\min\limits_{i=0}^{k-1}\left(dis_i-k\right)$  。 

考虑到 $a$ 序列纯随机， $n$ 个在 $[1,m]$ 中等概率随机的整数的最小值是 $\frac{m}{n+1}$ 的。因此时间复杂度 $\mathcal O(\frac{m}{n+1}n)=\mathcal O(m)$ 。