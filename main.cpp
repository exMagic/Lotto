//  Symulator Lotto
//  Version 1.1
//  Created by Maciej Anuszkiewicz on 25/09/2016.
//  Copyright © 2016 Maciej Anuszkiewicz. All rights reserved.
//
#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace std;
int liczba;
int typpy[6];
double konto=100;

int main()

{
    cout << "Witaj Otrzymujesz 100zł na start." << endl;
    cout << "Koszt jednego zakładu to 3zł." << endl;
    cout << "Chcesz spróbować szczęścia? jeśli tak to" << endl;
    cout << "Podaj swoje typowane 6 liczb z zakresu od 1 do 49:" << endl;
    for (int i=0; i<=5; i++) {
        cout << "liczba nr "<<i+1<<endl;
        cin >> typpy[i];
    }
    cout <<"Twoje typypowane liczby to: "
    <<typpy[0]<<" "
    <<typpy[1]<<" "
    <<typpy[2]<<" "
    <<typpy[3]<<" "
    <<typpy[4]<<" "
    <<typpy[5]<<endl;
    for (;;) {
        
        cout << "WITAJ! za 2 sekundy nastapi zwolnienie blokady" << endl;
        sleep(2);
        srand(time(NULL));
        
        for(int i=0;i<6;i++){
            liczba=rand()%49+1;
            cout<<"\a"<<liczba<<"\n";
            
            sleep(1);
        }
    }
    return 0;
}
