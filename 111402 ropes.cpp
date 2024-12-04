#include <bits/stdc++.h> //для работы с gcd (есть загвоздка gcd работает только так: __gcd())

using namespace std;

#define DEBUG
#ifdef DEBUG
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif // DEBUG


bool canCutSegments(const vector<long long>& ropes, long long segmentLength, long long K) {
    long long count = 0;
    for (auto rope : ropes) {
        count += rope / segmentLength;
        if (count >= K) return true;  // Early exit if we've already got enough segments
    }
    return count >= K;
}

long long findMaxSegmentLength(const vector<long long>& ropes, long long K) {
    long long left = 1;
    long long right = *max_element(ropes.begin(), ropes.end());
    long long maxSegmentLength = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canCutSegments(ropes, mid, K)) {
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
    Задача №111402. Веревочки
    С утра шел дождь, и ничего не предвещало беды. Но к обеду выглянуло солнце, и в лагерь заглянула СЭС. Пройдя по всем домикам и корпусам, СЭС вынесла следующий вердикт: бельевые веревки в жилых домиках не удовлетворяют нормам СЭС. Как выяснилось, в каждом домике должно быть ровно по одной бельевой веревке, и все веревки должны иметь одинаковую длину. В лагере имеется N
    бельевых веревок и K
    домиков. Чтобы лагерь не закрыли, требуется так нарезать данные веревки, чтобы среди получившихся веревочек было K
    одинаковой длины. Размер штрафа обратно пропорционален длине бельевых веревок, которые будут развешены в домиках. Поэтому начальство лагеря стремиться максимизировать длину этих веревочек.

    Входные данные
    В первой строке заданы два числа — N
    (1≤N≤10001) и K (1≤K≤10001). Далее в каждой из последующих N
    строк записано по одному числу — длине очередной бельевой веревки. Длина веревки задана в сантиметрах. Все длины лежат в интервале от 
    1 сантиметра до 100 километров включительно.

    Выходные данные
    В выходной файл следует вывести одно целое число — максимальную длину веревочек, удовлетворяющую условию, в сантиметрах. В случае, если лагерь закроют, выведите 0.
    */
    long long N, K;
    cin >> N >> K;

    vector<long long> ropes(N);
    for (long long i = 0; i < N; ++i) {
        cin >> ropes[i];
    }

    long long result = findMaxSegmentLength(ropes, K);
    cout << result << endl;

    return 0;
}