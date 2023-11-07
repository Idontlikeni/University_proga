#include <iostream>
#include <queue>
using namespace std;

void task1(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << (c - a) / b;
}

void task2(){
    int n;
    bool fl = false;
    cin >> n;
    for(int i = 0; i < n / 4; i++){
        if((n - i * 4) % 3 == 0){
            cout << (n - i * 4) / 3 << "\n" << i;
            fl = true;
            return;
        }
    }
    if(!fl)cout << " 0 \n 0";
}

void task3(){
    int n, m;
    cin >> n >> m;
    cout << ((n + 1) * n / 2) * ((m + 1) * m / 2);
}

bool foo(int* arr, int n){
    bool fl = true;
    for(int i = 1; i < 5; i++){
        //cout << arr[i + (n - 1) * 4] << " " <<  + (n - 1) * 4 << "<----1\n";
        if(arr[i + (n - 1) * 4] == 0)return false;
    }
    //cout << arr[54 - 2 * (n - 1)] << " " << arr[54 - 1 - 2 * (n - 1)] << " " << 54 - 2 * (n - 1) << "<-----2\n";
    if(arr[54 - 2 * (n - 1)] == 0 || arr[54 - 1 - 2 * (n - 1)] == 0)return false;
    return true;
}

void task4(){
    int n, mx = 0, cnt = 0;
    cin >> n;
    int arr[55];
    arr[0] = -1;
    for(int i = 1; i <= 54; i++)arr[i] = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr[a] = 1;
    }
    for(int i = 1; i <= 9; i++){
        if(foo(arr, i))cnt++;
        else{
            mx = max(mx, cnt);
            cnt = 0;
        }
        //cout <<foo(arr, i) << " " << i << "\n";
    }
    mx = max(mx, cnt);
    cout << mx;
}

void task5(){
    queue<int>vec;
    int n, k;
    cin >> n >> k;
    vec.push(n);
    for(int i = 0; i < k; i++){
        int a, b;
        if(vec.front() % 2 == 0){
            a = vec.front() / 2;
            b = a - 1;
        }else a = b = vec.front() / 2;
        vec.pop();
        vec.push(a);
        vec.push(b);
        if(i == k - 1)cout << b << "\n" << a;
    }
}

int main()
{
    task5();
    return 0;
}
