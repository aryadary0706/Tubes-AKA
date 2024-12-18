#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED


#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Struktur data untuk menyimpan informasi pemain
struct Players {
    int ID[500];           // ID yang dimiliki tiap pemain (ascending)
    string nama[500];      // Nama pemain
    string role[500];      // Posisi pemain di lapangan
    int Overall[500];      // Kekuatan pemain berdasarkan atribut dalam game
    int value[500];        // Harga transfer pemain dalam game
};

// Fungsi dan prosedur yang digunakan
bool checkOverallInput(int Overall);
bool checkPositionInput(string position);
string findPlayerRecursive(Players Dataplayer, string position, int Overall, int value, int N, int index, int price_range);
string findPlayer(Players Dataplayer, string position, int Overall, int value, int N, int price_range);
void init_players_1(Players &DataPemain5);
void init_player_2(Players &DataPemain5);
void init_player_3(Players &DataPemain5);
void init_player_4(Players &DataPemain5);
void init_player_5(Players &DataPemain5);
void init_player_6(Players &DataPemain5);
void init_player_7(Players &DataPemain5);
void init_player_8(Players &DataPemain5);
void init_player_9(Players &DataPemain5);
void init_player_10(Players &DataPemain5);


#endif // TUBES_H_INCLUDED
