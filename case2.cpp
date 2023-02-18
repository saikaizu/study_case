#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int solution(int N, string S) {
    vector<vector<bool> > seats(N, vector<bool>(10, true)); // Membuat matriks untuk kursi
    int families = 0;

    // Mengubah string S menjadi vektor yang memuat kursi yang sudah dipesan
    vector<string> reservedSeats;
    istringstream iss(S);
    string token;
    while (iss >> token) {
        reservedSeats.push_back(token);
    }

    // Menandai kursi yang sudah dipesan
    for (string reservedSeat : reservedSeats) {
        int row = stoi(reservedSeat.substr(0, reservedSeat.length()-1)) - 1;
        int col = reservedSeat[reservedSeat.length()-1] - 'A';

        seats[row][col] = false;
    }

    // Menghitung keluarga yang dapat ditampatkan
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (seats[i][j]) { // Kursi kosong
                count++;
                if (count == 4) { // Menemukan empat kursi yang kosong berdampingan
                    count = 0;
                    families++;
                }
            } else { // Kursi sudah dipesan
                count = 0;
                if (j == 1 || j == 4 || j == 7) { // Menambah satu kursi jika terdapat lorong
                    j++;
                }
            }
        }
    }
    return families;
}

int main() {
    int N = 2;
    string S = "1A 2F 1C";
    cout << solution(N, S) << endl; // Output: 2

    N = 1;
    S = "";
    cout << solution(N, S) << endl; // Output: 2

    N = 22;
    S = "1A 30 2B 20G SA";
    cout << solution(N, S) << endl; // Output: 41

    return 0;
}

