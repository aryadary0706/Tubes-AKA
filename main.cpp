#include "header.h"

int main(){
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
    
}
