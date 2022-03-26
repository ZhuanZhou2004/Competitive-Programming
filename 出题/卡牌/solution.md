> 我会 IO ！

对于 $n=1,m=0$ 的情况，直接输出 1 即可。

> 我会计算 $m=1$ ！

考虑 $\text{minmax}$ 容斥，记 $\max (S)$ 表示该 B 类评论在 $S$ 状态的最后一个 A 类评论前期望出现次数，$\min (S)$ 表示最早一个 A 类评论前期望出现次数，不难发现，我们要计算的即为 $n+\max (\{1,2,\cdots, n\})$ 。

由 $\text{minmax}$ 容斥知：

$$\max (S) = \sum\limits_{T\subset S} (-1)^{|T|-1} \min(T)$$ 

而 $\min(T)$ 很好计算，令 $W=\sum\limits_{x\in T} A_x$ ，则 $\min(T)=\frac{B}{W+B}$ 。

由于 $A_i\le 100$ ，所以可以 dp 求 $cnt[W]$ 表示有多少个 $T$ 状态的 $A_i$ 和等于 $W$ ，然后简单计算。 

在实际 dp 的过程中，可以顺便将 $-1$ 系数给算进去，这样 $cnt[W]$ 的意义转化为容斥系数和。

> 我会运用期望的线性性！

 不难发现，这 $m$ 个 B 类评论是相互独立的，由期望的线性性可知，对于每一个 B 类评论分别执行上述流程，贡献相加即为答案。

令 $S=\sum\limits_{i=1}^{n} A_i$ ，时间复杂度 $O(nS+mS\log mod)$ 。

> 我会分治 fft ！

记 $f(x)=\sum a_ix^i$ ，$a_i$ 表示 $W=i$ 的容斥系数和，则显然有：

$$f(x)=-\prod\limits_{i=1}^{n} (1-x^{a_i})$$

直接分治 $fft$ 即可，时间复杂度 $O(S\log^2 S+mS\log mod)$ 。

> 我会 exp !

先不管这个负号，两边求 ln ：$\ln f(x)=\sum\limits_{i=1}^{n}\ln (1-x^{a_i})$ 

将 ln 泰勒展开：$\ln f(x)=\sum\limits_{i=1}^{n} -\sum\limits_{j=1}^{\infty} \frac{\left(x^{a_i}\right)^j}{j}$ 

记录 $cnt[x]$ 表示有多少个 $a_i=x$  ，发现指数个数是调和级数个，于是可以快速得到 $\ln f(x)$ 。

将其 $exp$ 回去即可得到 $f(x)$ （记得将系数全取负），时间复杂度 $O(S\log S+mS\log mod)$ 。

> 我会优化逆元！

每次暴力求逆元，会显得很费。发现一共需要求 $mS$ 个逆元，约 $5e7$ 个，将其离线下来，用 $O(mS)$ 的时间批量处理逆元。

时间复杂度降至 $O(S\log S+mS+\log mod)$ ，可以通过。



subtask 4

// $O(nS+mS\log mod)$

subtask 5

// $O(S \log^2 S+mS\log mod)$

subtask 6

// $O(S\log S+ms\log mod)$

subtask 7

// $O(S\log S+ms+\log mod)$

