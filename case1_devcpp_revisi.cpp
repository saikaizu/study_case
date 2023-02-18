#include <iostream>
#include <string>
using namespace std;

string solution(int N) {
    string s = "CODILITY";
    int primes[] = {2, 3, 5};
    string result = "";

    for (int i = 0; i < 3; i++) {
        while (N % primes[i] == 0) {
            int index = (N / primes[i]) - 1;
            if (index >= 0 && index < s.length() && s[index] != ' ') {
                result += s[index];
                s[index] = ' ';
            }
            N /= primes[i];
        }
    }

    return result;
}

int main() {
    int N;
    cout << "Masukkan nilai N: ";
    cin >> N;

    string result = solution(N);
    cout << "Hasil: " << result << endl;

    return 0;
}

