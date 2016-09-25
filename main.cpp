//  Symulator Lotto
//  Version 1.0
//  Created by Maciej Anuszkiewicz on 25/09/2016.
//  Copyright © 2016 Maciej Anuszkiewicz. All rights reserved.
//
#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace std;
int liczba;
int main()
{
    cout << "WITAJ! za 2 sekundy nastapi zwolnienie blokady" << endl;
    sleep(2);
    srand(time(NULL));
    
    for(int i=0;i<6;i++){
        liczba=rand()%49+1;
        cout<<"\a"<<liczba<<"\n";
        
        sleep(1);
    }
    
    return 0;
}
