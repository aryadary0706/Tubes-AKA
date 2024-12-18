#ifndef RECURSIVE_H_INCLUDED
#define RECURSIVE_H_INCLUDED

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Players{
    int ID[500]; //ID yang dimiliki tiap pemain. Ascending ke Atas
    string nama[500];
    string role[500]; // Posisi Pemain di lapangan
    int Overall[500]; // Total perhitungan kekuatan pemain dari atribut-atribut dalam game. Detail tidak akan dijelaskan
    int value[500]; // Harga Transfer suatu pemain dalam game
};
//init_players_x : prosedur memasukkan data pemain ke dalam Players. urutan x (1->5)
//DataPemain : Urutan (5->1)

void resetPlayers(Players &players, int N);
void init_players_1(Players &DataPemain5);

#endif // RECURSIVE_H_INCLUDED
