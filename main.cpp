#include <iostream>
#include "nama_pemain.h"
using namespace std;

void searchPlayers(Player data[], int n, string posisi, int minRating, int maxRating, int minPrice, int maxPrice) {
    bool found = false;

    cout << "\nHasil pencarian pemain:\n";
    for (int i = 0; i < n; i++) {
        if (data[i].posisi == posisi && data[i].overall >= minRating && data[i].overall <= maxRating && data[i].price >= maxPrice && data[i].price <= maxPrice) {
            cout << "- " << data[i].nama << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ada pemain yang memenuhi kriteria.\n";
    }
}

int main() {
    string posisi;
    int minRating, minPrice;
    int maxRating, maxPrice;

    cout << "Masukkan posisi yang dicari (contoh: ST, GK, CM): ";
    cin >> posisi;
    cout << "Masukkan rating minimal pemain: ";
    cin >> minRating;
    cout << "Masukkan rating maximal pemain: ";
    cin >> maxRating;
    cout << "Masukkan harga minimal pemain: ";
    cin >> minPrice;
    cout << "Masukkan harga maksimal pemain: ";
    cin >> maxPrice;

    searchPlayers(Dataplayers, N, posisi, minRating,maxRating, minPrice, maxRating);

    return 0;
}
