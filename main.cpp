#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int nod(int a, int b) {
    while (a % b != 0) {
        a%=b;
        swap(a, b);
    }
    return b;
}

int nod_m(int a, int b){
    if(a < b)swap(a, b);
    while(a - b != 0){
        a = a - b;
        if(a < b)swap(a, b);
    }
    return a;
}

int* erat(int n) {
  int *a = new int[n];
  for (int i = 0; i < 100; i++)
    a[i] = i + 1;
    a[0] = 0;
  for (int i = 1; i < 100; i++) {
    if (a[i] != 0)
      for (int j = a[i] * 2 - 1; j < 100; j += a[i])
        a[j] = 0;
  }
  return a;
}

void t_3_1() {

  // условие: строчка длиной 3 символа, должна содержать латинские буквы И
  // цифры.
  string s;
  fin >> s;
  for (int i = 0; i < s.length() - 3; i++) {
    bool a = false, b = false;
    for (int j = 0; j < 3; j++) {
      if (s[i + j] >= '0' && s[i + j] <= '9')
        b = true;
      if ((s[i + j] >= 'a' && s[i + j] <= 'b') ||
          (s[i + j] >= 'A' && s[i + j] <= 'B'))
        a = true;
    }
    if (a && b)
      cout << s.substr(i, 3) << " ";
  }
  fin.close();
  fout.close();
}

void t_3_2() {
  string s;
  while (fin >> s) {
    int n = s.length();
    for (int i = 0; i < n; i++)
      fout << int(s[i]);
    fout << "\n";
  }
}

void t_4_1() {
  int n;
  cin >> n;
  vector<int> vec(n);
  vector<string> vec2(n);
  for (int i = 0; i < n; i++) {
    int a, count = 0;
    cin >> a;
    vec[i] = 0;
    while (a > 0) {
      if (a % 10 > 4)
        return;
      vec[i] += a % 10 * pow(5, count);
      a = a / 10;
      count++;
    }
    bitset<256> b(vec[i]);
    vec2[i] = b.to_string();
  }
  for (int i = 0; i < vec2.size(); i++){
    while(vec2[i][0] == '0'){
        vec2[i] = vec2[i].substr(1);
    }
    cout << vec2[i] << " ";
  }

}

void t_4_2() {
  int n, a;
  double res = 0, p;
  cin >> n >> a;
  p = a;
  for (int i = 0; i < n; i++) {
    res += (i + 1) / p;
    a++;
    p *= a;
  }
  cout << res;
}

void t_5_1() {
  string s;
  int ans;
  while (fin >> s) {
    int n = s.length();
    string test = string(" ", n);
    if (test == s)
      continue;
    string c = s;
    sort(s.begin(), s.end());
    if (c == s)
      ans++;
  }
  cout << ans;
}

void t_5_2() {
  int n;
  fin >> n;
  vector<vector<double>> m1(n, vector<double>(n));
  vector<vector<double>> m2(n, vector<double>(n));
  vector<vector<double>> e(n, vector<double>(n, 0));
  vector<vector<double>> c(n, vector<double>(n, 0));
  vector<vector<double>> r(n, vector<double>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> m1[i][j];
      c[i][j] = 1 / (i + j + 2);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> m2[i][j];
    }
  }
  cout << "A:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << m1[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "B:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << m2[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "B-E:\n";
  for (int i = 0; i < n; i++)
    e[i][i] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m2[i][j] = m2[i][j] - e[i][j];
      cout << m2[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        r[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }

  cout << "A * (B-E):\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << r[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[i][j] = r[i][j] + c[i][j];
      cout << r[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
    if(!fin)cout << "Input is failed";
    if(!fout)cout << "Output is failed";
    // task 1
    /*int a, b;
    cin >> a >> b;
    cout << nod(a, b) << " " << nod_m(a, b);*/

    // task 2

    /* int n;
    cin >> n;
    int *b = erat(n);
    for (int i = 0; i < n; i++)if(b[i] != 0)cout << b[i] << " "; */


    // task 3.1
    // t_3_1();

    // task 3.2 взял 08 потому что у меня номер 087, а 87 номера нет
    // t_3_2();

    // task 4.1
    t_4_1();

    // task 4.2
    // t_4_2();

    // task 5.1
    // t_5_1();

    // task 5.2
    // t_5_2();

    fout.close();
    fin.close();
    return 0;
}
