#include <string>
using namespace std;

string solution(int N) {
    string letters = "CODILITY";
    string uncovered = "";
    while (N > 1 && !letters.empty()) {
        if (N % 2 == 0) {
            uncovered += letters[0];
            letters.erase(0, 1);
            N /= 2;
        } else if (N % 3 == 0) {
            uncovered += letters[0];
            letters.erase(0, 1);
            N /= 3;
        } else if (N % 5 == 0) {
            uncovered += letters[0];
            letters.erase(0, 1);
            N /= 5;
        } else {
            break;
        }
    }
    return uncovered;
}
