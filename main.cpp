//  Symulator Lotto
//  Version 1.2
//  Created by Maciej Anuszkiewicz on 25/09/2016.
//  Copyright © 2016 Maciej Anuszkiewicz. All rights reserved.
//
#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace std;
int liczba;
int typpy[6];
int wylosowaneLiczby[6];
double konto=100;
int wynik=0;
int menu1;
int menu2=2;

///////////////////////////
int podajTypy(){
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
    return 0;
}
///////////////////////////
int losuj(){
    konto=konto-3;
    cout << "Stan Twojego konta: "<< konto<<endl << endl;
    cout << "WITAJ! za 2 sekundy nastapi zwolnienie blokady" << endl;
    sleep(2);
    srand(time(NULL));
    
    for(int i=0;i<6;i++){
        liczba=rand()%49+1;
        cout<<"\a"<<liczba<<"\n";
        wylosowaneLiczby[i]=liczba;
        sleep(1);
    }
    cout <<"Wylosowane liczby to: "
    <<wylosowaneLiczby[0]<<" "
    <<wylosowaneLiczby[1]<<" "
    <<wylosowaneLiczby[2]<<" "
    <<wylosowaneLiczby[3]<<" "
    <<wylosowaneLiczby[4]<<" "
    <<wylosowaneLiczby[5]<<endl;
    return 0;
}
///////////////////////////
int sprawdzWynik(){
    for (int k=0; k<=5; k++) {
        
        for (int i=k; i<=5; i++) {
            //porównuje pierwszą moją liczbę z wszystkimi wylosowanymi
            if (typpy[k]==wylosowaneLiczby[i]) {
                wynik++;
            }
        }
    }
    return 0;
}
///////////////////////////


int main()

{
    cout << "Witaj Otrzymujesz 100zł na start." << endl;
    cout << "Koszt jednego zakładu to 3zł." << endl;
    cout << "Chcesz spróbować szczęścia?" << endl<<endl;
    cout << "MENU" << endl;
    cout << "---------------------" << endl;
    cout << "1 - Nowa gra" << endl;
    cout << "0 - Zakończ grę" << endl;
    cin>> menu1;
    
    if (menu1==1) {
        for (;;) {
            
            switch (menu2) {
                case 1:
                    losuj();
                    sprawdzWynik();
                    cout<<endl<<endl<<"Twój wynik: "<<wynik<<endl;
                    cout<<endl<<"Stan Twojego konta: "<<konto<<endl<<endl;
                    break;
                case 2:
                    podajTypy();
                    losuj();
                    sprawdzWynik();
                    cout<<endl<<endl<<"Twój wynik: "<<wynik<<endl;
                    cout<<endl<<"Stan Twojego konta: "<<konto<<endl<<endl;
                    break;
                case 0:
                    cout<<"Do widzenia sknero!";
                    break;
                default:
                    cout<<"Nie ma takiej opcji w menu";
                    break;
            }
            
            
            cout << "MENU" << endl;
            cout << "---------------------" << endl;
            cout << "1 - Nowa gra " << endl;
            cout << "2 - Nowa gra i nowe typy" << endl;
            cout << "0 - Zakończ grę" << endl;
            cin>> menu2;
        }
    }
    else if (menu1==0){
        cout<<"Do widzenia sknero!";
    }
    else{
        cout<<"Nie ma takiej opcji w menu";}
    return 0;
}
