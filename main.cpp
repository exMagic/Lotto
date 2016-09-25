//  Symulator Lotto
//  Version 1.5
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
int nagroda;
int numerLosowania=1;
int x;
int y;

///////////////////////////
int podajTypy(){
    cout << "Podaj swoje typowane 6 liczb z zakresu od 1 do 49:" << endl;
    for (int i=0; i<=5; i++) {
        cout << "wpisz liczbę nr "<<i+1<<endl;
        cin >> typpy[i];
    }
    
    return 0;
}
///////////////////////////
int losuj(){
    numerLosowania++;
    konto=konto-3;
    cout << "za chwilę nastąpi zwolnienie blokady" << endl;
    usleep(1000000);
    srand(time(NULL));
    
    for(int i=0;i<6;i++){
        
        if (i==0) {
            x=rand()%49+1;
            y=rand()%49+1;
            liczba=x*y%49+1;
            wylosowaneLiczby[0]=liczba;
        }
        else{
            do {
                x=rand()%49+1;
                y=rand()%49+1;
                liczba=x*y%49+1;
            } while (liczba==wylosowaneLiczby[i-1]);
            wylosowaneLiczby[i]=liczba;
            
        }
        
        cout<<"\a"<<liczba<<"\n";
        usleep(100000);
    }
    cout <<endl<<"Wylosowane liczby to: ";
    for (int i=0; i<6; i++) {
        
        if(wylosowaneLiczby[i]<10){
            cout<<" "<<wylosowaneLiczby[i]<<" | ";
        }
        else{
            cout<<wylosowaneLiczby[i]<<" | ";
        }
    }
    cout <<endl<<"Wytypowane liczby to: ";
    for (int i=0; i<6; i++) {
        if(typpy[i]<10){
            cout<<" "<<typpy[i]<<" | ";
        }
        else{
            cout<<typpy[i]<<" | ";
        }
    }
    
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
    switch (wynik) {
        case 0:
            nagroda=0;
            break;
        case 1:
            nagroda=0;
            break;
        case 2:
            nagroda=0;
            break;
        case 3:
            nagroda=24;
            break;
        case 4:
            nagroda=95;
            break;
        case 5:
            nagroda=5600;
            break;
        case 6:
            nagroda=2000000;
            break;
            
        default:
            break;
    }
    konto=konto+nagroda;
    return 0;
}
///////////////////////////
int wyswietlStatystyki(){
    cout<<endl<<endl<<"Twój wynik: "<<wynik<<endl;usleep(100000);
    cout<<"Wygrywasz: "<<nagroda<<"zł"<<endl;usleep(100000);
    cout<<"Stan Twojego konta: "<<konto<<endl<<endl;usleep(100000);
    return 0;
}

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
        while (menu1==1) {
            
            switch (menu2) {
                case 1:
                    cout<<endl<<"/////////////////  "<<"LOSOWANIE NR "<<numerLosowania<<"  //////////////////"<<endl<<endl;
                    losuj();
                    sprawdzWynik();
                    wyswietlStatystyki();
                    break;
                case 2:
                    podajTypy();
                    cout<<endl<<"/////////////////  "<<"LOSOWANIE NR "<<numerLosowania<<"  //////////////////"<<endl<<endl;
                    losuj();
                    sprawdzWynik();
                    wyswietlStatystyki();
                    break;
                case 0:
                    cout<<"Do widzenia sknero!"<<endl;
                    break;
                default:
                    cout<<"Nie ma takiej opcji w menu"<<endl;
                    break;
            }
            
            cout << "---------------------" << endl;
            cout << "MENU" << endl;usleep(100000);
            cout << "1 - Nowa gra " << endl;usleep(100000);
            cout << "2 - Nowa gra i nowe typy" << endl;usleep(100000);
            cout << "0 - Zakończ grę" << endl;usleep(100000);
            cout << "---------------------" << endl;
            cin>> menu2;
            wynik=0;
        }
    }
    else if (menu1==0){
        cout<<"Do widzenia sknero!"<<endl;
    }
    else{
        cout<<"Nie ma takiej opcji w menu"<<endl;}
    return 0;
}
