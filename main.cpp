#include "header.h"

int main(){
    /*
    int num = 0;
    Players Database;
    while (num >= 0 && num <= 5){
        cout<<"Pilih Database yang mau dipakai:\n";
        cout<<"Data_Pemain1 (50)\n";
        cin>>num;
        if (num == 1) {
        int N = 50;
        init_players_1(Database);

        cout<<"Masukkan Data Pemain (position, Overall, value)"<<endl;
        string cache_posisi;
        int cache_Overall, cache_value;
        cout<<"Masukkan posisi: "
        cin>>cache_posisi
        cout<<endl;
        cout<<"Masukkan overall: "
        cin>>cache_Overall
        cout<<endl;
        cout<<"Masukkan value: "
        cin>>cache_value
        cout<<endl;

        findPlayerIterative(Database, position, Overall, value, 50)
        resetPlayers(Database, N);
        }else if (num == 2){

        }
    }


    init_players_1(Data);
    string SearchedPlayers;
    SearchedPlayers = findPlayerIterative(Data, "ST", 91, 180000000, 50);

    // Input pencarian pemain
    string searchPosition;
    int searchOverall, searchValue;

    cout << "Masukkan posisi pemain yang dicari (contoh: ST): ";
    cin >> searchPosition;

    cout << "Masukkan overall pemain yang dicari (79-91): ";
    cin >> searchOverall;

    cout << "Masukkan nilai transfer pemain yang dicari: ";
    cin >> searchValue;
    */

    Players Data;
    int N = 50;

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
    string result = findPlayerIterative(Data, searchPosition, searchOverall, searchValue, N);

    // Output hasil pencarian
    if (result != "None") {
        cout << "Pemain ditemukan: " << result << endl;
    } else {
        cout << "Pemain tidak ditemukan." << endl;
    }

    return 0;
}

