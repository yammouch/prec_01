#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void read_data(int n, map<int, set<int> > &m)
{
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    m[a].insert(b);
    m[b].insert(a);
  }

  return;
}

void unidir(map<int, set<int> > &m)
{
  vector<int> stack;
  stack.push_back(1);
  while(!stack.empty()) {
    for (int i = 0; i < stack.size(); i++) {
      cout << ' ' << stack[i];
    }
    cout << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
      cout << "  " << it->first;
      for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        cout << " " << *it2;
      }
    }
    cout << endl;
    int node = stack.back();
    stack.pop_back();
    for (auto it = m[node].begin(); it != m[node].end(); it++) {
      stack.push_back(*it);
      auto it2 = m[*it].find(node);
      if (it2 != m[*it].end()) {
        m[*it].erase(it2);
      }
    }
  }

  return;
}

void add1(int p, int x, map<int, set<int> > &m, vector<int> acc)
{
  vector<int> stack;

  stack.push_back(1);
  while(!stack.empty()) {
    int node = stack.back();
    stack.pop_back();
    acc[node] += x;
    for (auto it = m[node].begin(); it != m[node].end(); it++) {
      stack.push_back(*it);
    }
  }

  return;
}

int main()
{
  int n, q;
  map<int, set<int> > m;
  cin >> n >> q;
  vector<int> acc(n-1);

  read_data(n, m);
  cout << "read_data() finished." << endl;
  unidir(m);
  cout << "unidir() finished." << endl;

  for (int i = 0; i < q; i++) {
    int p, x;
    cin >> p >> x;
    add1(p, x, m, acc);
  }
  cout << "add1() finished." << endl;

  for (int i = 0; i < acc.size(); i++) {
    cout << acc[i] << ' ';
  }
  cout << endl;

  return 0;
}
