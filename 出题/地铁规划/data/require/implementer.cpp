#include "subway.h"
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
class IOLocker{
	public:
		static const int MAX_MOGIC_DUP = 100;

		IOLocker() : in(STDIN_FILENO), out(STDOUT_FILENO) {
			srand(time(NULL));
			lock();
		}

		void lock(){
			int cnt = rand() % MAX_MOGIC_DUP;
			for(int i = 0; i < cnt; ++i) djq += dup(STDERR_FILENO);

			int nin = dup(in);
			fclose(stdin); close(in); in = nin;

			int nout = dup(out);
			fclose(stdout); close(out); out = nout;

			stdin = stdout = NULL;
		}

		void unlock(){
			stdin = fdopen(in, "r");
			stdout = fdopen(out, "w");
		}

	private:
		int in, out, djq;
};
static IOLocker IO __attribute__((init_priority(101)));
namespace l9tl161h85 {
	void gg(int id) {
		IO.unlock();
		printf("cxclcxbq31\n");
		printf("Wrong Answer [%d]\n", id);
		exit(0);
		IO.lock();
		exit(0);
	}
	vector < int > fa;
	vector < pair < int, int > > sta;
	vector < pair < int, int > > e;
	vector < int > ans;
	const int LIMIT = 20000000;
	int n, m, limit, cnt;
	int cur, curl, able;
	int gf(int a) {
		while (fa[a] > 0) a = fa[a];
		return a;
	}
	void graderInit() {
		IO.unlock();
		if (3 != scanf("%d%d%d", &n, &m, &limit)) gg(-1);
		init(n, m, limit);
		e.resize(m + 1);
		for (int i = 1; i <= m; i++) if (2 != scanf("%d%d", &e[i].first, &e[i].second)) gg(-1);
		fa = vector < int > (n + 1, -1);
		IO.lock();
	}
	void merge(int x) {
		if (!able) gg(1);
		if (x <= 0 || x > m) gg(2);
		if (x < curl) gg(3);
		if (++cnt > LIMIT) gg(4);
		cur = std::max(cur, x);
		int u = gf(e[x].first), v = gf(e[x].second);
		if (u == v) gg(5);
		if (fa[u] > fa[v]) std::swap(u, v);
		sta.emplace_back(u, fa[u]);
		sta.emplace_back(v, fa[v]);
		fa[u] += fa[v];
		fa[v] = u;
	}
	bool check(int x) {
		if (x <= 0 || x > m) gg(6);
		int u = gf(e[x].first), v = gf(e[x].second);
		return u != v;
	}
	void undo() {
		if (sta.empty()) gg(7);
		fa[sta.back().first] = sta.back().second;
		sta.pop_back();
		fa[sta.back().first] = sta.back().second;
		sta.pop_back();
	}
	void main() {
		graderInit();
		ans.resize(m + 1);
		for (int i = 1; i <= m; i++) {
			cur = i, curl = i;
			able = 1;
			ans[i] = solve(i);
			able = 0;
			if (cur > ans[i]) gg(8);
		}
		IO.unlock();
		printf("cxclcxbq31\n");
		if (cnt <= limit) printf("Success\n");
		else printf("Too many merge\n");
		printf("Count of merge: %d\n", cnt);
		for (int i = 1; i <= m; i++) printf("%d%c", ans[i], " \n"[i == m]);
		IO.lock();
	}
}
void undo() {
	l9tl161h85::undo();
}
bool check(int x) {
	return l9tl161h85::check(x);
}
void merge(int x) {
	l9tl161h85::merge(x);
}
int main() {
	l9tl161h85::main();
}