#include "Menu.h"

Menu::Menu(){}

void Menu::run(){
    FileReader data = FileReader();
    data.readCities();
    data.readReservoirs();
    data.readStations();
    data.readPipes();
    mainMenu();
}


void Menu::mainMenu(){
    char op;
    cout << "__________________________________________\n";
    cout << "|                MainMenu                |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Load Network                   |\n";
    cout << "|      2. Find Max Water Flow            |\n";
    cout << "|      3. Verify Water Supply            |\n";
    cout << "|      4. Load Optimization              |\n";
    cout << "|      5. Reservoir Impact               |\n";
    cout << "|      6. Pumping Station Impact         |\n";
    cout << "|      7. Pipeline Failure Impact        |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            break;
        default:
            cout << "Invalid Option..." << endl;
            break;
    }
}