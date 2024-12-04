#include <bits/stdc++.h> //для работы с gcd (есть загвоздка gcd работает только так: __gcd())

using namespace std;

#define DEBUG
#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif // DEBUG

bool canCutSegments(const vector<long long>& wires, long long segmentLength, long long K) {
    long long count = 0;
    for (auto wire : wires) {
        count += wire / segmentLength;
        if (count >= K) return true;  // Early exit if we've already got enough segments
    }
    return count >= K;
}

long long findMaxSegmentLength(const vector<long long>& wires, long long K) {
    long long left = 1;
    long long right = *max_element(wires.begin(), wires.end());
    long long maxSegmentLength = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canCutSegments(wires, mid, K)) {
            maxSegmentLength = mid;
            left = mid + 1;  // Try for a longer segment
        } else {
            right = mid - 1;  // Try for a shorter segment
        }
    }
    return maxSegmentLength;
}

int main() {
    /*
    Задача №672. Провода
    Дано N отрезков провода длиной L1, L2, ..., LN сантиметров. Требуется с помощью разрезания получить из них K равных отрезков как можно большей длины, выражающейся целым числом сантиметров. Если нельзя получить K отрезков длиной даже 1 см, вывести 0.

    Ограничения: 1 <= N <= 10 000, 1 <= K <= 10 000, 100 <= Li <= 10 000 000, все числа целые.

    Входные данные
    В первой строке находятся числа N и К. В следующих N строках - L1, L2, ..., LN, по одному числу в строке.

    Выходные данные
    Вывести одно число - полученную длину отрезков.
    */
    long long N, K;
    cin >> N >> K;

    vector<long long> wires(N);
    for (long long i = 0; i < N; ++i) {
        cin >> wires[i];
    }

    long long result = findMaxSegmentLength(wires, K);
    cout << result << endl;

    return 0;
}
