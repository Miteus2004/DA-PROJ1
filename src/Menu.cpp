#include "Menu.h"

Menu::Menu(){}

void Menu::run(){
    FileReader data = FileReader();
    data.read();
    this->reservoirs = data.getReservoirs();
    this->cities = data.getCities();
    this->stations = data.getStations();
    this->Points = data.getPoints();
    this->grafo = data.getflow();
    mainMenu();
}


void Menu::mainMenu(){
    char op;
    cout << "__________________________________________\n";
    cout << "|                MainMenu                |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Find Max Water Flow            |\n";
    cout << "|      2. Verify Water Supply            |\n";
    cout << "|      3. Reservoir Impact               |\n";
    cout << "|      4. Pumping Station Impact         |\n";
    cout << "|      5. Pipeline Failure Impact        |\n";
    cout << "|      \033[31mq. QUIT \033[0m                          |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            MaxFlowMenu();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case 'p':
            break;
        default:
            cout << "Invalid Option..." << endl;
            break;
    }
}

void Menu::MaxFlowMenu() {
    char op;
    cout << "__________________________________________\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. Select Specific City           |\n";
    cout << "|      2. All Cities                     |\n";
    cout << "|      \033[31mq. Go back \033[0m                       |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            SScity();
            mainMenu();
            break;
        case '2':
            All_Cities();
            mainMenu();
            break;
        default:
            cout << "Invalid Option..." << endl;
            break;
    }
}

void Menu::SScity() {
    cout << "Enter the city code:";
    string code;
    cin >> code;

    auto x = cities.find(code);
    City *city = x->second;
    string name = city->getCity();
    unsigned int demand = city->getDemand();
}

void Menu::All_Cities() {}