// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin;
ofstream fout;

int task1() {
    double s, p, n, m, r;
    cin >> s >> p >> n;
    r = p / 100;
    if (12 * (pow(1 + r, n) - 1) == 0) {
        cout << "impossible";
        return 1;
    }
    m = (s * r * (pow(1 + r, n))) / (12 * (pow(1 + r, n) - 1));
    cout << m;
    return 0;
}

int task2() {
    double s, p, n, m, r, t, m2, mn = 1000000000;
    int ans = NULL;
    cin >> s >> m >> n;
    
    for (double i = 0; i < 100000; i+= 0.5)
    {
        r = i / 100;
        if (12 * (pow(1 + r, n) - 1) != 0) {
            m2 = (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
            if (abs(m - m2) <= mn) {
                mn = abs(m - m2);
                ans = i;
            }
        }
    }
    cout << ans << " " << mn;
    return 0;
} 

int task3() {
    fin.open("first.txt");
    char c;
    string str;
    if (fin.is_open()) {
        while (!fin.eof())
        {
            fin >> str;
            cout << str << "\n";
        }
        fin.close();
    }
    return 0;
}

int task4() {
    fin.open("second.txt");
    char ch;
    string str, nm = "";
    int num = 0;
    if (fin.is_open()) {
        while (fin.get(ch))
        {
            num = ch - '0';
            if (num >= 0 && num <= 9) {
                nm += ch;
            }
            else if(nm.size() > 0){
                cout << nm << "\n";
                nm = "";
            }
        }
        cout << nm << "\n";
        fin.close();
    }
    return 0;
}

bool comp(char a, char b) {
    int ai = a, bi = b;
    if (a >= 'A' && a <= 'Z')ai = a - 'A' + 'a';
    
    if (b >= 'A' && b <= 'Z')bi = b - 'A' + 'a';
    return ai < bi;
}

int task5() {
    string str = "";
    while (str.length() != 30)cin >> str;
    sort(str.begin(), str.end(), comp);
    cout << str;
    return 0;
}

int main()
{

    //Задание 1
    //task1();

    //Задание 2
    //task2(); 

    //Задание 3
    //task3();

    //Задание 4
    //task4();

    //Задание 5
    //task5();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
