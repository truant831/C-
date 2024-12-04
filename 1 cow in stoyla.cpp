#include <bits/stdc++.h> //для работы с gcd (есть загвоздка gcd работает только так: __gcd())

using namespace std;

#define DEBUG
#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif // DEBUG

bool canPlaceCows(const vector<long long>& stalls, long long minDist, long long K) {
    long long count = 1;  
    long long lastPos = stalls[0];

    for (size_t i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count >= K) return true;
        }
    }
    return count >= K;
}

long long findMaxMinDistance(const vector<long long>& stalls, long long K) {
    long long left = 1;
    long long right = stalls.back() - stalls[0];
    long long maxMinDist = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canPlaceCows(stalls, mid, K)) {
            maxMinDist = mid;
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }
    return maxMinDist;
}

int main() 
{
    /*
    Задача №1. Коровы - в стойла
    На прямой расположены стойла, в которые необходимо расставить коров так, чтобы минимальное расcтояние между коровами было как можно больше.

    Входные данные
    В первой строке вводятся числа N
    (2<N<10001)
    – количество стойл и K
    (1<K<N)
    – количество коров. Во второй строке задаются N
    натуральных чисел в порядке возрастания – координаты стойл (координаты не превосходят 109
    )

    Выходные данные
    Выведите одно число – наибольшее возможное допустимое расстояние.
    */
    long long N, K;
    cin >> N >> K;

    vector<long long> stalls(N);
    for (long long i = 0; i < N; ++i) {
        cin >> stalls[i];
    }

    long long result = findMaxMinDistance(stalls, K);
    cout << result << endl;

    return 0;
}

