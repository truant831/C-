#include <iostream>
// #include <conio.h> // Library where getch() is stored
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <cstring>  //для работы с символоами
#include <stdlib.h> //для max, min и т.д.
#include <string>
#include <cctype>  // для работы с topper(), isupper() и tolower(), islower() работает только с char
#include <fstream> //для работы с файлами как потоками
// #include <algorithm>
#include <bits/stdc++.h> //для работы с gcd (есть загвоздка gcd работает только так: __gcd())

using namespace std;

#define DEBUG
#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif // DEBUG

// бек слеш + n работают как enter

// бек слеш + t работают как пробел

// бек слеш + b работают как backscape

int triangle(int longs)
{
    int a = 0;
    for (size_t i = 0; i < longs; i++)
    {
        a = i;
        while (a >= 0)
        {
            cout << "o";
            a--;
        }
        cout << "\n";
    }
    return 0;
}

int nod(int a, int b)
{
    if (b > a) // если сначала маленькое, то меняем местами
    {
        swap(a, b);
    }

    int t = 0;
    int i = 0;

    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
        i++;
    }
    return a;
}

int minimum(int a, int b)
{
    int mini = a;
    if (a > b)
    {
        mini = b;
        }
    // cout<<a<<" "<<b<<"=>"<<mini<<"  ";
    return mini;
        }

string revers_numbers(int number)
{
    string res = "";
    string number_long = to_string(number);

    for (size_t i = 0; i < number_long.size(); i++)
    {
        res += to_string(number % 10);
        number /= 10;
    }
    return res;
}

const float pi = 3.14;

void S_krug(int radius)
{
    int S = pi * (radius * radius);
    cout << S;
}

int Chetvert(int x, int y)
{
    int chetvert = 0;
    if (x > 0)
    {
        if (y > 0)
        {
            chetvert = 1;
        }
        else if (y < 0)
        {
            chetvert = 2;
        }
    }
    else
    {
        if (y > 0)
        {
            chetvert = 4;
        }
        else if (y < 0)
        {
            chetvert = 3;
        }
    }
    return chetvert;
}

int nok(int n, int k)
{
    long long nod;
    long long nok;

    nod = __gcd(n, k);
    nok = n * k / nod;
    return nok;
}

bool isPrime(int n)
{
    int count = 0, k = 2;
    while (k * k <= n and count == 0)
    {
        if (n % k == 0)
        {
            count++;
        }
        k++;
    }
    return (count == 0);
}

void printHello(int a)
{
    for (size_t i = 0; i < a; i++)
    {
        cout << "Hello" << "\n";
    }
}

double Sparalel(int a, int b, int c)
{
    return a * b * sin(c * 180 / pi);
}

int max_of_numbers_in_mass(char a[], int ind)
{
    if (ind == 0)
    {
        return int(a[0] - '0');
    }
    int maxi = max(int(a[ind] - '0'), max_of_numbers_in_mass(a, ind - 1));
    return maxi;
}

int length = 0;
char ch;

void q1();

void q0()
{
    ch = getchar();
    if ((ch >= 'A') && (ch <= 'z'))
    {
        length++;
        q0();
    }
    else if (ch == ' ')
    {
        q1();
    }
    else
    {
        length = 0;
        q0();
    }
}

void q1()
{
    return; // ???
}

int sum (int a)
{
    int s=0;
    for (size_t i = 0; a>10; i++)
    {
        s+=a%10;
        a/10;
    }
    return s;
}

bool comp (string a,string b)
{
   return a[6]>b[6];
}

int main()
{
    /*
       
    */
    
    int a=0,b=0,l=0,r=0,mid=0; 
    int tmp=0,otv =0;
    cin>>a;
    vector <int> bin;
    //bin.push_back(0);
    for (size_t i = 0; i < a; i++)
    {
        cin>>tmp;
        bin.push_back(tmp);
    }
    bin.push_back(1e9);
    cin>>b;
    int fnd[b];
    for (size_t i = 0; i < b; i++)
    {
        cin>>fnd[i];
    }
    
    auto tst = upper_bound(bin.begin(),bin.end(),4)-bin.begin();
    cout<<tst<<" tst\n";


    for (size_t i = 0; i < b; i++)
    {
        otv = lower_bound(bin.begin(),bin.end(),fnd[i])-bin.begin();
        if (otv != a)
        {
            cout<<otv<<" ";
        }
        else
        {
            cout<<"0 ";
        }
        otv = upper_bound(bin.begin(),bin.end(),fnd[i])-bin.begin()-1;
        if (otv != a)
        {
            cout<<otv<<" ";
        }
        else
        {
            cout<<"0";
        }
        cout<<"\n";
    }


    // printHello(5);
    // cout<<isPrime(9);

    // system ("pause");
    //  auto temp = a.end();
    //--temp;
    //  cout << *temp <<"\n";
    //  cout<<fixed << setprecision(n) << b; вывод числа b с n знаками после запятой
}

/*
    long d = 0,s= 0,a=0,l=0;
    cin >>d>>s;
    float otv = 0.0000;
    float pi = 3.141592654;
    otv = (s/(d*pi))*360;
    //otv = round(otv * 10000) / 10000;
    a = otv;
    //cout<<a<<"\n";
    for (size_t i = 2; 9 < a; i++)
    {
        a = a/10;
        l=i;
        //cout<<a<<"\n";
    }

    cout.precision(l+4);
    cout<<otv;
    return 0;
*/