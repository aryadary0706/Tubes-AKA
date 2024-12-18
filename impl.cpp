#include "recursive.h"

// Array posisi pemain
const string role[15] = {"GK", "CB", "RB", "RWB", "LB", "LWB", "CDM", "CM", "LM", "RM", "CAM", "RW", "LW", "CF", "ST"};
//GK 0
//CB 1
//RB 2
//RWB 3
//LB 4
//LWB 5
//CDM 6
//CM 7
//LM 8
//RM 9
//CAM 10
//RW 11
//LW 12
//CF 13
//ST 14

//Reset Players
void resetPlayers(Players &players, int N) {
    for (int i = 0; i < N; i++) {
        players.ID[i] = 0; // Reset ID ke 0
        players.nama[i] = ""; // Reset nama ke string kosong
        players.role[i] = ""; // Reset role ke string kosong
        players.Overall[i] = 0; // Reset Overall ke 0
        players.value[i] = 0; // Reset value ke 0
    }
}

//Cek validitas Overall
bool checkOverallInput(int Overall){
    bool valid_overall;
    if (Overall >= 79 && Overall <= 91){
        valid_overall = true;
    }else{
        valid_overall = false;
    }
    return valid_overall;
}

//Cek Validitas Posisi
bool checkPositionInput(string position){
    bool valid_position = false;
    for (int i = 0; i < 15; i++){
        if (position == role[i]){
            valid_position = true;
        }
    }
    return valid_position;
}

int findPlayersByPosition(Players players, int n, string position, int indices[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (players.role[i] == position) {
            indices[count++] = i;
        }
    }
    return count;
}

string binarySearch(Players players, int indices[], int count, int overall, int price) {
    int low = 0, high = count - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int idx = indices[mid];

        int priceRange = players.value[idx] * 0.1; // 10% dari harga pemain

        if (players.Overall[idx] == overall &&
            (players.value[idx] - priceRange <= price && price <= players.value[idx] + priceRange)) {
            return players.nama[idx];
        } else if (players.Overall[idx] < overall) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return "Tidak ada pemain yang cocok."; // Jika tidak ada pemain yang cocok
}

string findplayerRecursively(Players Dataplayer, string position, int Overall, int value, int N){
    bool validPost = checkPositionInput(position);
    bool validOvr = checkOverallInput(Overall);
    if (validPost && validOvr){
        // Mencari pemain berdasarkan posisi
        int indices[500];
        int count = findPlayersByPosition(players, n, inputPosition, indices);

        // Mengurutkan pemain berdasarkan overall dan value
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                int idx1 = indices[j];
                int idx2 = indices[j + 1];

                if (players.Overall[idx1] > players.Overall[idx2] ||
                (players.Overall[idx1] == players.Overall[idx2] && players.value[idx1] > players.value[idx2])) {
                    int temp = indices[j];
                    indices[j] = indices[j + 1];
                    indices[j + 1] = temp;
                }
            }
        }
        string binaryresult = binarySearch(players, indices, count, inputOverall, inputPrice);
    }
}

/*
int findPlayersByPosition(Players players, int n, string position, int indices[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (players.role[i] == position) {
            indices[count++] = i;
        }
    }
    return count;
}

string binarySearch(Players players, int indices[], int count, int overall, int price) {
    int low = 0, high = count - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int idx = indices[mid];

        int priceRange = players.value[idx] * 0.1; // 10% dari harga pemain

        if (players.Overall[idx] == overall &&
            (players.value[idx] - priceRange <= price && price <= players.value[idx] + priceRange)) {
            return players.nama[idx];
        } else if (players.Overall[idx] < overall) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return "Tidak ada pemain yang cocok."; // Jika tidak ada pemain yang cocok
}

string findPlayer(Players players, int n, string inputPosition, int inputOverall, int inputPrice) {
    // Daftar posisi yang valid
    string validPositions[] = {"ST", "CF", "LW", "RW", "RM", "LM", "CM", "CAM", "CDM", "LWB", "RWB", "RB", "LB", "CB", "GK"};
    bool isValidPosition = false;

    for (string pos : validPositions) {
        if (inputPosition == pos) {
            isValidPosition = true;
            break;
        }
    }

    if (!isValidPosition) {
        cout << "Posisi tidak valid." << endl;
        return "";
    }

    // Validasi overall
    if (inputOverall <= 79 || inputOverall >= 92) {
        cout << "Overall harus lebih dari 79 dan kurang dari 92." << endl;
        return "";
    }

    // Mencari pemain berdasarkan posisi
    int indices[500];
    int count = findPlayersByPosition(players, n, inputPosition, indices);

    // Mengurutkan pemain berdasarkan overall dan value
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int idx1 = indices[j];
            int idx2 = indices[j + 1];

            if (players.Overall[idx1] > players.Overall[idx2] ||
                (players.Overall[idx1] == players.Overall[idx2] && players.value[idx1] > players.value[idx2])) {
                swap(indices[j], indices[j + 1]);
            }
        }
    }

    // Mencari pemain menggunakan binary search
    return binarySearch(players, indices, count, inputOverall, inputPrice);
}
*/

// Deklarasi global dan inisialisasi langsung
void init_players_1(Players &DataPemain5){ //50 pemain
    DataPemain5.ID[0] = 1;
    DataPemain5.nama[0] = "Erling Braut Haland";
    DataPemain5.role[0] = role[14]; // ST
    DataPemain5.Overall[0] = 91;
    DataPemain5.value[0] = 180000000;

    DataPemain5.ID[1] = 2;
    DataPemain5.nama[1] = "Kylian Mbappe Lottin";
    DataPemain5.role[1] = role[14]; // ST
    DataPemain5.Overall[1] = 91;
    DataPemain5.value[1] = 181500000;

    DataPemain5.ID[2] = 3;
    DataPemain5.nama[2] = "Kevin De Bruyne";
    DataPemain5.role[2] = role[7]; // CM
    DataPemain5.Overall[2] = 91;
    DataPemain5.value[2] = 103000000;

    DataPemain5.ID[3] = 4;
    DataPemain5.nama[3] = "Rodri";
    DataPemain5.role[3] = role[6]; // CDM
    DataPemain5.Overall[3] = 90;
    DataPemain5.value[3] = 129500000;

    DataPemain5.ID[4] = 5;
    DataPemain5.nama[4] = "Harry Kane";
    DataPemain5.role[4] = role[14]; // ST
    DataPemain5.Overall[4] = 90;
    DataPemain5.value[4] = 119500000;

    DataPemain5.ID[5] = 6;
    DataPemain5.nama[5] = "Thibaut Nicolas Marc Courtois";
    DataPemain5.role[5] = role[0]; // GK
    DataPemain5.Overall[5] = 90;
    DataPemain5.value[5] = 63000000;

    DataPemain5.ID[6] = 7;
    DataPemain5.nama[6] = "Robert Lewandowski";
    DataPemain5.role[6] = role[14]; // ST
    DataPemain5.Overall[6] = 90;
    DataPemain5.value[6] = 58000000;

    DataPemain5.ID[7] = 8;
    DataPemain5.nama[7] = "Lionel Andres Messi Cuccitini";
    DataPemain5.role[7] = role[13]; // RW
    DataPemain5.Overall[7] = 90;
    DataPemain5.value[7] = 41000000;

    DataPemain5.ID[8] = 9;
    DataPemain5.nama[8] = "Rúben dos Santos Gato Alves Dias";
    DataPemain5.role[8] = role[1]; // CB
    DataPemain5.Overall[8] = 89;
    DataPemain5.value[8] = 106500000;

    DataPemain5.ID[9] = 10;
    DataPemain5.nama[9] = "Vinicius José Paixão de Oliveira Junior";
    DataPemain5.role[9] = role[13]; // RW
    DataPemain5.Overall[9] = 89;
    DataPemain5.value[9] = 158500000;

    DataPemain5.ID[10] = 11;
    DataPemain5.nama[10] = "Alisson Ramsés Becker";
    DataPemain5.role[10] = role[0]; // GK
    DataPemain5.Overall[10] = 89;
    DataPemain5.value[10] = 68500000;

    DataPemain5.ID[11] = 12;
    DataPemain5.nama[11] = "Mohamed Salah";
    DataPemain5.role[11] = role[11]; // RW
    DataPemain5.Overall[11] = 89;
    DataPemain5.value[11] = 85500000;

    DataPemain5.ID[12] = 13;
    DataPemain5.nama[12] = "Virgil van Dijk";
    DataPemain5.role[12] = role[1]; // CB
    DataPemain5.Overall[12] = 89;
    DataPemain5.value[12] = 70500000;

    DataPemain5.ID[13] = 14;
    DataPemain5.nama[13] = "Marc-André ter Stegen";
    DataPemain5.role[13] = role[0]; // GK
    DataPemain5.Overall[13] = 89;
    DataPemain5.value[13] = 54500000;

    DataPemain5.ID[14] = 15;
    DataPemain5.nama[14] = "Jude Victor William Bellingham";
    DataPemain5.role[14] = role[7]; // CM
    DataPemain5.Overall[14] = 88;
    DataPemain5.value[14] = 128500000;

    DataPemain5.ID[15] = 16;
    DataPemain5.nama[15] = "Federico Santiago Valverde";
    DataPemain5.role[15] = role[7]; // CM
    DataPemain5.Overall[15] = 88;
    DataPemain5.value[15] = 124000000;

    DataPemain5.ID[16] = 17;
    DataPemain5.nama[16] = "Lautaro Javier Martínez";
    DataPemain5.role[16] = role[14]; // ST
    DataPemain5.Overall[16] = 88;
    DataPemain5.value[16] = 116000000;

    DataPemain5.ID[17] = 18;
    DataPemain5.nama[17] = "Martin Ødegaard";
    DataPemain5.role[17] = role[7]; // CM
    DataPemain5.Overall[17] = 88;
    DataPemain5.value[17] = 118000000;

    DataPemain5.ID[18] = 19;
    DataPemain5.nama[18] = "Bernardo Silva";
    DataPemain5.role[18] = role[7]; // CM
    DataPemain5.Overall[18] = 88;
    DataPemain5.value[18] = 91500000;

    DataPemain5.ID[19] = 20;
    DataPemain5.nama[19] = "Ederson Santana de Moraes";
    DataPemain5.role[19] = role[0]; // GK
    DataPemain5.Overall[19] = 88;
    DataPemain5.value[19] = 70000000;

    DataPemain5.ID[20] = 21;
    DataPemain5.nama[20] = "Jan Oblak";
    DataPemain5.role[20] = role[0]; // GK
    DataPemain5.Overall[20] = 88;
    DataPemain5.value[20] = 61000000;

    DataPemain5.ID[21] = 22;
    DataPemain5.nama[21] = "Antoine Griezmann";
    DataPemain5.role[21] = role[14]; // ST
    DataPemain5.Overall[21] = 88;
    DataPemain5.value[21] = 74000000;

    DataPemain5.ID[22] = 23;
    DataPemain5.nama[22] = "Neymar da Silva Santos Júnior";
    DataPemain5.role[22] = role[13]; // RW
    DataPemain5.Overall[22] = 88;
    DataPemain5.value[22] = 75500000;

    DataPemain5.ID[23] = 24;
    DataPemain5.nama[23] = "Karim Benzema";
    DataPemain5.role[23] = role[14]; // ST
    DataPemain5.Overall[23] = 88;
    DataPemain5.value[23] = 39000000;

    DataPemain5.ID[24] = 25;
    DataPemain5.nama[24] = "Florian Richard Wirtz";
    DataPemain5.role[24] = role[7]; // CM
    DataPemain5.Overall[24] = 87;
    DataPemain5.value[24] = 118500000;

    DataPemain5.ID[25] = 26;
    DataPemain5.nama[25] = "Philip Walter Foden";
    DataPemain5.role[25] = role[13]; // RW
    DataPemain5.Overall[25] = 87;
    DataPemain5.value[25] = 109000000;

    DataPemain5.ID[26] = 27;
    DataPemain5.nama[26] = "Gregor Kobel";
    DataPemain5.role[26] = role[0]; // GK
    DataPemain5.Overall[26] = 87;
    DataPemain5.value[26] = 81500000;

    DataPemain5.ID[27] = 28;
    DataPemain5.nama[27] = "Declan Rice";
    DataPemain5.role[27] = role[6]; // CDM
    DataPemain5.Overall[27] = 87;
    DataPemain5.value[27] = 88500000;

    DataPemain5.ID[28] = 29;
    DataPemain5.nama[28] = "Victor James Osimhen";
    DataPemain5.role[28] = role[14]; // ST
    DataPemain5.Overall[28] = 87;
    DataPemain5.value[28] = 104500000;

    DataPemain5.ID[29] = 30;
    DataPemain5.nama[29] = "Gianluigi Donnarumma";
    DataPemain5.role[29] = role[0]; // GK
    DataPemain5.Overall[29] = 87;
    DataPemain5.value[29] = 85500000;

    DataPemain5.ID[30] = 31;
    DataPemain5.nama[30] = "Frenkie de Jong";
    DataPemain5.role[30] = role[7]; // CM
    DataPemain5.Overall[30] = 87;
    DataPemain5.value[30] = 93000000; // Nilai tidak tersedia

    DataPemain5.ID[31] = 32;
    DataPemain5.nama[31] = "Cristiano Ronaldo";
    DataPemain5.role[31] = role[14]; // ST
    DataPemain5.Overall[31] = 86;
    DataPemain5.value[31] = 15000000;

    DataPemain5.ID[32] = 33;
    DataPemain5.nama[32] = "Sadio Mané";
    DataPemain5.role[32] = role[13]; // RW
    DataPemain5.Overall[32] = 86;
    DataPemain5.value[32] = 80000000;

    DataPemain5.ID[33] = 34;
    DataPemain5.nama[33] = "Son Heung-min";
    DataPemain5.role[33] = role[13]; // RW
    DataPemain5.Overall[33] = 86;
    DataPemain5.value[33] = 85000000;

    DataPemain5.ID[34] = 35;
    DataPemain5.nama[34] = "N'Golo Kanté";
    DataPemain5.role[34] = role[6]; // CDM
    DataPemain5.Overall[34] = 86;
    DataPemain5.value[34] = 60000000;

    DataPemain5.ID[35] = 36;
    DataPemain5.nama[35] = "Riyad Mahrez";
    DataPemain5.role[35] = role[13]; // RW
    DataPemain5.Overall[35] = 86;
    DataPemain5.value[35] = 50000000;

    DataPemain5.ID[36] = 37;
    DataPemain5.nama[36] = "Gareth Bale";
    DataPemain5.role[36] = role[13]; // RW
    DataPemain5.Overall[36] = 85;
    DataPemain5.value[36] = 20000000;

    DataPemain5.ID[37] = 38;
    DataPemain5.nama[37] = "Paul Pogba";
    DataPemain5.role[37] = role[7]; // CM
    DataPemain5.Overall[37] = 85;
    DataPemain5.value[37] = 40000000;

    DataPemain5.ID[38] = 39;
    DataPemain5.nama[38] = "Marcus Rashford";
    DataPemain5.role[38] = role[13]; // RW
    DataPemain5.Overall[38] = 85;
    DataPemain5.value[38] = 70000000;

    DataPemain5.ID[39] = 40;
    DataPemain5.nama[39] = "Jadon Sancho";
    DataPemain5.role[39] = role[13]; // RW
    DataPemain5.Overall[39] = 85;
    DataPemain5.value[39] = 80000000;

    DataPemain5.ID[40] = 41;
    DataPemain5.nama[40] = "Gianluigi Buffon";
    DataPemain5.role[40] = role[0]; // GK
    DataPemain5.Overall[40] = 85;
    DataPemain5.value[40] = 10000000;

    DataPemain5.ID[41] = 42;
    DataPemain5.nama[41] = "Zlatan Ibrahimović";
    DataPemain5.role[41] = role[14]; // ST
    DataPemain5.Overall[41] = 85;
    DataPemain5.value[41] = 5000000;

    DataPemain5.ID[42] = 43;
    DataPemain5.nama[42] = "Thiago Alcântara";
    DataPemain5.role[42] = role[7]; // CM
    DataPemain5.Overall[42] = 85;
    DataPemain5.value[42] = 30000000;

    DataPemain5.ID[43] = 44;
    DataPemain5.nama[43] = "David De Gea";
    DataPemain5.role[43] = role[0]; // GK
    DataPemain5.Overall[43] = 85;
    DataPemain5.value[43] = 15000000;

    DataPemain5.ID[44] = 45;
    DataPemain5.nama[44] = "César Azpilicueta";
    DataPemain5.role[44] = role[1]; // CB
    DataPemain5.Overall[44] = 85;
    DataPemain5.value[44] = 10000000;

    DataPemain5.ID[45] = 46;
    DataPemain5.nama[45] = "Mason Mount";
    DataPemain5.role[45] = role[7]; // CM
    DataPemain5.Overall[45] = 84;
    DataPemain5.value[45] = 60000000;

    DataPemain5.ID[46] = 47;
    DataPemain5.nama[46] = "Jorginho";
    DataPemain5.role[46] = role[7]; // CM
    DataPemain5.Overall[46] = 84;
    DataPemain5.value[46] = 40000000;

    DataPemain5.ID[47] = 48;
    DataPemain5.nama[47] = "Nicolas Pépé";
    DataPemain5.role[47] = role[13]; // RW
    DataPemain5.Overall[47] = 84;
    DataPemain5.value[47] = 30000000;

    DataPemain5.ID[48] = 49;
    DataPemain5.nama[48] = "Youri Tielemans";
    DataPemain5.role[48] = role[7]; // CM
    DataPemain5.Overall[48] = 84;
    DataPemain5.value[48] = 50000000;

    DataPemain5.ID[49] = 50;
    DataPemain5.nama[49] = "Ruben Loftus-Cheek";
    DataPemain5.role[49] = role[7]; // CM
    DataPemain5.Overall[49] = 84;
    DataPemain5.value[49] = 25000000;

    DataPemain5.ID[50] = 51;
    DataPemain5.nama[50] = "Emile Smith Rowe";
    DataPemain5.role[50] = role[13]; // RW
    DataPemain5.Overall[50] = 84;
    DataPemain5.value[50] = 30000000;
}
