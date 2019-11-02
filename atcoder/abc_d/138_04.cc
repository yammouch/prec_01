#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

void read_data(int n, vector<set<int> > &to)
{
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    to[a].insert(b);
    to[b].insert(a);
  }

  return;
}

void unidir(vector<set<int> > &to, vector<int> &parent, vector<int> &depth)
{
  int d_cnt = 0;
  queue<int> q;
  q.push(1);
  parent[0] = -1;
  parent[1] = 0;
  depth[0] = d_cnt++;
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    depth[node] = d_cnt++;
    for (auto it = to[node].begin(); it != to[node].end(); it++) {
      q.push(*it);
      parent[*it] = node;
      auto it2 = to[*it].find(node);
      if (it2 != to[*it].end()) {
        to[*it].erase(it2);
      }
    }
  }

  return;
}

class Comp {
 public:
  vector<int> &depth;

  Comp(vector<int> &d): depth(d) { }
  bool operator() (const tuple<int, int> &t1, const tuple<int, int> &t2) {
    return depth[get<0>(t1)] < depth[get<0>(t2)];
  }
};

void add(
 int n, int q, vector<int> &parent, vector<int> &depth, vector<int64_t> &acc)
{
  vector<tuple<int, int> > pacc(n+1);
  for (int i = 0; i <= n; i++) {
    pacc[i] = make_tuple(i, 0);
  }

  for (int i = 0; i < q; i++) {
    int p1;
    int x;
    cin >> p1 >> x;
    get<1>(pacc[p1]) += x;
  }

  sort(pacc.begin(), pacc.end(), Comp(depth));
  vector<int> stack;

  for (int i = 1; i <= n; i++) {
    acc[get<0>(pacc[i])] = acc[parent[get<0>(pacc[i])]] + get<1>(pacc[i]);
  }

  return;
}

int main()
{
  int n, q;
  cin >> n >> q;
  vector<set<int> > to(n+1);
  vector<int64_t> acc(n+1);
  vector<int> parent(n+1), depth(n+1);

  read_data(n, to);
  unidir(to, parent, depth);
  add(n, q, parent, depth, acc);

  for (int i = 1; i < acc.size(); i++) {
    cout << acc[i] << ' ';
  }
  cout << endl;

  return 0;
}
