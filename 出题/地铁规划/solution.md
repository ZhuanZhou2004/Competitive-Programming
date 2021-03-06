## subtask1

对于每个左端点，暴力扫右端点直至 `check` 为零，然后  `undo` 回去即可。

操作次数 $\frac{n^2}{2}$。

## subtask2

由于可撤销 dsu 能撤销最近一次的操作，而我们需要撤销最远一次的操作，不难想到采用一种“双栈结构”来维护它。

具体地，我们加入 dsu 的边可以用一个栈维护。其中已经翻转过的边用 `0` 表示，未翻转过的边用 `1` 表示。我们只要时刻保证栈顶为 `0` 边即可直接进行 `undo` 操作。

对于当前左端点的查询，它会使得栈顶加入若干个 `1` 边。考虑暴力弹栈顶直至弹出来的 `0` 边和 `1` 边数量相等，然后把 `1` 边按原顺序加回栈，再把 `0` 边按原顺序加回栈，这样就满足栈顶为 `0` 边，可以直接 `undo` 了。特殊情况是把栈弹空了仍然不满足 `0` 边和 `1` 边数量相等，此时如果栈中压根没有 `0` 边，我们就把所有 `1` 边倒着加回栈中，这样所有 `1` 边变成了 `0` 边；否则我们仍按照上述方式加回栈中即可。

容易证明上述做法是根号量级的。

## subtask3

数据随机，留给 subtask2 的根号做法、不会证操作次数的乱搞做法以及单 $\log $ 的大常数写法。

## subtask4

结合二进制位去考虑该问题。

我们每次额外加一个计数器 $\text{top}$，表示栈内有多少个已经翻转过的边（即 `0` 边）。

- 如果栈的头未被 $\text{rev}$ 过，则一直弹，然后再弹 $\text{lowbit(top)}$ 个 $\text{rev}$ 过的边；
- 如果栈的头被 $\text{rev}$ 过，啥事都不干。

执行完上述流程后，可以发现栈一定 $\text{rev}$ 过，并且一定是左端点 $l$ 对应的边，因此直接 `undo`，并 `top--` 即可。

考虑分析该做法的复杂度。

我们定义一个点的**位前进**表示它在未 $\text{rev}$ 状态时击败了一个位的状态，**位后退**表示它在 $\text{rev}$ 状态时回退一个位的状态。不难发现，我们记一个点的势能为它被**位前进**+**位后退**的总次数，即为 $\Phi(u)$，则总操作次数为 $\mathcal O(\sum\limits_{i=1}^{n}\Phi(i) )$。

对于未被 $\text{rev}$ 的边，它在自身位于栈尾连续段内才会被执行**位前进**，而想要进行挪动的代价是击败一个 $\text{top}$ 的位，即它至多进行 $\log n$ 次**位前进**。

对于已被 $\text{rev}$ 的边，它需要在被 $\text{rev}$ 的边中处于末 $\text{lowbit}(top)$ 条边里才会被执行**位后退**，并且在后退以后，$\text{top}$ 从 $\text{lowbit}$ 处被摊平成若干个 $1$ （例如原来 `top=1010000` ，则 `top--` 后末尾的位均被摊成了 $1$，即 `top=1001111`），所以它至多进行 $\log n$ 次**位后退**。

因此 $\Phi(x)=\log n+\log n=\mathcal O(\log n)$，复杂度得证。

