#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll nod(ll a, ll b) {
  if (b > a)
    swap(a, b);
  if (a % b == 0)
    return b;
  return nod(b, a % b);
}

ll nok(ll a, ll b) {
  if (b > a)
    swap(a, b);
  return a * b / nod(a, b);
}

map<vector<int>, int> mp;

int n;
template <typename T> void print_vec(vector<T> &vc) {
  cout << "printing: ";
  for (int i = 0; i < vc.size(); i++) {
    cout << vc[i] << " ";
  }
  cout << "\n";

}

int foo(set<int> used, vector<int> nums, int eq = 0) {
  if (nums.size() == n) {
    // for (int i = 0; i < nums.size(); i++)
    //{
    //	cout << nums[i] << " ";
    // }
    // cout << "\n" << eq << "\n";
    return eq;
  }
  int sm = 0;
  for (int i = 0; i < n; i++) {
    if (used.find(i) == used.end()) {
      nums.push_back(i);
      used.insert(i);
      // print_vec(nums);
      if (i == nums.size() - 1) {
        sm += foo(used, nums, 1 || eq);
      } else {
        sm += foo(used, nums, 0 || eq);
      }
      nums.pop_back();
      used.erase(i);
    }
  }
  // nums.push_back(eq);
  mp[nums] = sm;

  // cout << mp[nums] << "<----\n";
  return sm;
}

int main() {
  ofstream fout("out.txt");
  cin >> n;
  cout << foo({}, {}, 0);
  /*vector<int>vc1 = {1, 2};
  vector<int>vc2 = {1, 2};
  map<vector<int>, int>test;
  test[vc1] = 8;
  cout << test[vc2];*/
}
