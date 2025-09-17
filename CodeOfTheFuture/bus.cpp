#include <iostream>
using namespace std;

int main() {
    long long K, N;

    cin >> K >> N;

    long long remainder = N % K;

    cout << min(remainder, K - remainder);

    return 0;
}