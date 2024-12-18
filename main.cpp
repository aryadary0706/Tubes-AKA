#include "tubes.h"

using namespace std;

int main() {
    Players Data;
    int N = 2; // Jumlah pemain yang diinisialisasi

    // Inisialisasi data pemain
    init_players_1(Data);

    // Input pencarian
    string searchPosition;
    int searchOverall, searchValue;

    cout << "Masukkan posisi pemain yang dicari (contoh: ST): ";
    cin >> searchPosition;

    cout << "Masukkan overall pemain yang dicari (79-91): ";
    cin >> searchOverall;

    cout << "Masukkan nilai transfer pemain yang dicari: ";
    cin >> searchValue;

    // Pencarian pemain
    string result = findPlayer(Data, searchPosition, searchOverall, searchValue, N, searchValue * 0.1);

    // Output hasil pencarian
    if (result != "None") {
        cout << "Pemain ditemukan: " << result << endl;
    } else {
        cout << "Pemain tidak ditemukan." << endl;
    }

    return 0;
}
