// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <math.h>
#include <map>
using namespace std;

ifstream fin;
ofstream fout;

void task1() {

    fout.open("input.txt");
    int a, sm = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> a;
        fout << '\n' << a;
    }
    fout.close();

    fin.open("input.txt");
    while (!fin.eof()) {
        fin >> a;
        sm += a;
    }
    cout << "----->" << sm << "<-----";
    fin.close();
}

int sign(int x) {
    if (x > 0) return 1;
    if (x == 0) return 0;
    return -1;
}

void task2() {
    int x;
    cin >> x;
    cout << sign(x);
}

double rect(int w, int h) { return w * h; }
double trig(int w, int h) { return w * h / 2; }
double circ(int r) { return M_PI * r * r; }

void task3() {
    char s = '-';
    int a, b, c;
    cout << "Площадь чего считать?(r - прямоуг. t - треугольник, c - круг)";
    while (s != 'r' && s != 't' && s != 'c')cin >> s;
    switch (s)
    {
    case 'r':
        cin >> a >> b;
        cout << rect(a, b);
        break;
    case 't':
        cin >> a >> b;
        cout << trig(a, b);
        break;
    case 'c':
        cin >> a;
        cout << circ(a);
        break;
    default:
        break;
    }
}

void task4() {
    for (int y = 0; y < 13; y++)
    {
        for (int x = 0; x < 40; x++) {
            if (y < 4 && x < 12)cout << '*';
            else cout << '_';
        }
        cout << "\n";
    }
}

void task5(){
    fout.open("output.txt");
    char field[256][256];
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            field[i][j] = ' ';
        }
    }
    for (int i = 0; i < 256; i++)
    {
        double x = (i * M_PI) / 25;
        double y = sin(x) * 15;
        cout << "x: " << x << " y: " << y << "\n";
        field[int(round(y)) + 64][int(round(x * 25 / M_PI))] = '$';
    }
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            fout << field[i][j];
        }
        fout << "\n";
    }

}

int task6(){
    map<char, int> nums{    {'I', 1},
                            {'V', 5},
                            {'X', 10},
                            {'L', 50},
                            {'C', 100},
                            {'D', 500},
                            {'M', 1000}};
    //set<string> st = {'IV'}
    string str;
    cin >> str;
    int res = 0, count = 0, lst, i = 0;
    while (i < str.length()){
        //cout << nums[str[i]] << " " << nums[str[i + 1]] << "\n";
        if(nums[str[i]] < nums[str[i + 1]]){
            int ras = nums[str[i + 1]] - nums[str[i]];
            while(ras >= 10){
                if(ras % 10 != 0){
                    cout << "1 Невозможно";
                    return -1;
                }
                ras /= 10;
            }
            if(ras == 4 || ras == 9){
                //cout << "2-" << nums[str[i + 1]] << " " << nums[str[i]] << "\n";
                res += nums[str[i + 1]] - nums[str[i]];
                i++;
            }else{
                cout << "2 Невозможно";
                return -1;
            }
        }else{
            if(nums[str[i]] == nums[str[i + 1]])count++;
            else count = 0;
            if(count > 2){
                cout << "3 Невозможно";
                return -1;
            }
            //cout << "1-" << nums[str[i]] << "\n";
            res += nums[str[i]];
        }
        i++;
    }
    cout << res;
}

void task7(){
    int s = 0, m, i, c;
    cin >> m >> i >> c;
    for (int j = 0; j < i; j++)
    {
        s = (m * s + j + 1) % c;
        cout << s << " ";
    }

}

int task9(){
    string alph = "0123456789ABCDEF";
    map <char, int>mp;
    for (int i = 0; i < alph.length(); i++)
    {
        mp[alph[i]] = i;
    }

    string a, res = "";
    int b, c, dec = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < a.length(); i++)
    {
        if(mp[a[i]] >= b){
            cout << "Невозможно";
            return -1;
        }
        dec += mp[a[i]] * pow(b, a.length() - i - 1);
        //cout << mp[a[i]] << " " << b << " " << a.length() - i - 1 << "\n";
    }
    //cout << dec << "\n";
    while(dec > 0){
        res = alph[dec % c] + res;
        dec /= c;
    }
    cout << res;
    return 0;
}

void task8(){
    double a[3][4] = {  {5, 2, 0, 10},
                        {3, 5, 2, 5},
                        {20, 0, 0, 0}};

    double b[4][2] = {  {1.2, 0.5},
                        {2.8, 0.4},
                        {5.0, 1.0},
                        {2.0, 1.5}};

    double c[3][2] = {  {0, 0},
                        {0, 0},
                        {0, 0}};

    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < 4; j++)
            {
                //cout << a[i][j] << " " << b[j][k] << "\n";
                c[i][k] += a[i][j] * b[j][k];
            }
            //cout << "-----------------\n";
        }
    }

    cout << "Матрица C:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    double mx = 0, mn = 999999;
    int ind1 = 0, ind2 = 0;
    for (int i = 0; i < 3; i++)
    {
        if(c[i][0] > mx){
            mx = c[i][0];
            ind1 = i;
        }

        if(c[i][0] < mn){
            mn = c[i][0];
            ind2 = i;
        }
    }
    cout << "Номер продавца с самой большой выручкой: " << ind1 + 1 << " С самой меньшей: " << ind2 + 1<< "\n";

    mx = 0, mn = 999999;
    ind1 = 0, ind2 = 0;

    for (int i = 0; i < 3; i++)
    {
        if(c[i][1] > mx){
            mx = c[i][1];
            ind1 = i;
        }

        if(c[i][1] < mn){
            mn = c[i][1];
            ind2 = i;
        }
    }
    cout << "Номер продавца с самыми большими коммисионными: " << ind1 + 1 << " С самыми меньшими: " << ind2 + 1<< "\n";

    double sum = 0;

    for (int i = 0; i < 3; i++)
    {
        sum += c[i][0] - c[i][1];
    }
    cout << "Общая сумма выручки: " << sum << "\n";

    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += c[i][1];
    }
    cout << "Общее кол-во коммисионных: " << sum << "\n";

    sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += c[i][0];
    }
    cout << "Общая сумма денег: " << sum << "\n";

}

int main()
{
    setlocale(LC_ALL, "Russian");
    // 1
    //task1();

    // 2
    //task2();

    // 3
    //task3();

    // 4
    //task4();

    // 5
    //task5();

    // 6
    //task6();

    // 7
    //task7();

    //8
    //task8();

    //9
    //task9();
    cout << "\n_______________________________________________\n";
}
