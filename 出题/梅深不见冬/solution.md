$$S = \sum_{a_1=1}^{n}\sum_{a_2=1}^{n}...\sum_{a_k}^{n}gcd(a_1,a_2,...,a_k)$$

我们把$gcd$提前:

$$S = \sum_{g=1}^{n}g\sum_{a_1=1}^{n/g}\sum_{a_2=1}^{n/g}...\sum_{a_k=1}^{n/g}[gcd(a_1,a_2,...,a_k)=1]$$

$$=\sum_{g=1}^{n}g\sum_{a_1=1}^{n/g}\sum_{a_2=1}^{n/g}...\sum_{a_k=1}^{n/g}\sum_{d|gcd(a_1,a_2,...,a_k)}\mu(d)$$

我们把$\mu(d)$提前：

$$S=\sum_{d=1}^{n}\mu(d) \sum_{g=1}^{n}g \sum_{a_1=1}^{n/(gd)}\sum_{a_2=1}^{n/(gd)}...\sum_{a_k=1}^{n/(gd)}1$$

$$=\sum_{d=1}^{n}\mu(d)\sum_{g=1}^{n}g\lfloor \frac{n}{gd}\rfloor ^k$$

令$T=gd$：

$$S=\sum_{T=1}^{n}\lfloor \frac{n}{T}\rfloor ^k \sum_{d|T}\mu(d)\frac{T}{d}$$

$$=\sum_{T=1}^{n}\lfloor \frac{n}{T}\rfloor ^k\phi(T)$$

整除分块+杜教筛即可。