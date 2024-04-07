#include "Menu.h"
#include "Edmondskarp.h"

Menu::Menu(){}

void Menu::run(){
    this->data = FileReader();
    data.read();
    data.Setup();
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
    cout << "|      3. Balance the network            |\n";
    cout << "|      4. Reservoir Failure Impact       |\n";
    cout << "|      5. Station Failure Impact         |\n";
    cout << "|      6. Pipeline Failure Impact        |\n";
    cout << "|      \033[31mq. QUIT \033[0m                          |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    string code;
    string code_dest;
    switch(op)
    {
        case '1':
            MaxFlowMenu();
            break;
        case '2':
            VerifyFlow();
            mainMenu();
            break;
        case '3':
            break;
        case '4':
            cout << "Enter the reservoir code:";
            cin >> code;
            Reservoir_Failure(code);
            mainMenu();
            break;
        case '5':
            cout << "Enter the station code:";
            cin >> code;
            Station_Failure(code);
            mainMenu();
            break;
        case '6':
            cout << "Enter the sorce code of the pipe:";
            cin >> code;
            cout << "Enter the destination code of the pipe:";
            cin >> code_dest;
            Pipe_Failture(code, code_dest);
            mainMenu();
            break;
        case 'q':
            cout << "End" << endl;
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
    cout << "|      3. Total                          |\n";
    cout << "|      \033[31mq. Go back \033[0m                       |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    string code;
    switch(op)
    {
        case '1':
            cout << "Enter the city code:";
            cin >> code;
            SScity(code);
            MaxFlowMenu();
            break;
        case '2':
            All_Cities();
            MaxFlowMenu();
            break;
        case '3':
            Total();
            MaxFlowMenu();
            break;
        case 'q':
            mainMenu();
            break;
        default:
            cout << "Invalid Option..." << endl;
            break;
    }
}

void Menu::SScity(string code) {
    cout << "______________________________________________\n";
    cout << "| City Code    | City Name    | Flow         |" << endl;
    cout << "|____________________________________________|\n";

    auto cities = data.getCities();
    auto city = cities.find(code);
    if (city != cities.end()) {
        cout << "| " << setw(12) << left << city->second->getCode() << " | " << setw(12) << left << city->second->getCity() << " | "
        << setw(12) << left << city->second->getMaxFlow() << " |" << endl;
        cout << "______________________________________________" << endl;
    }
}

void Menu::All_Cities() {
    cout << "_________________________________________________\n";
    cout << "| City Code    | City Name       | Flow         |" << endl;
    cout << "|______________|_________________|______________|\n";
    auto cities = data.getCities();
    for (auto c : cities) {
        cout << "| " << setw(12) << left << c.second->getCode() << " | " << setw(15) << left << c.second->getCity() << " | "
             << setw(12) << left << c.second->getMaxFlow() << " |" << endl;
        cout << "|______________|_________________|______________|" << endl;
    }
}

void Menu::Total() {
    int total = 0;
    auto cities = data.getCities();
    for (auto c : cities) {
        total += c.second->getMaxFlow();
    }
    cout << "Total flow: " << total << endl;
}

void Menu::VerifyFlow() {
    cout << "_________________________________________________________________________________\n";
    cout << "| City Code    | City Name       | Demand         | Flow         | Deficit      |" << endl;
    cout << "|______________|_________________|________________|______________|______________|\n";
    bool works = true;
    auto cities = data.getCities();
    for (auto c : cities) {
        double deficit = c.second->getDemand() - c.second->getMaxFlow() ;
        if (deficit > 0) {
            works = false;
            cout << "| " << setw(12) << left << c.second->getCode() << " | " << setw(15) << left << c.second->getCity() << " | " << setw(14) << left << c.second->getDemand()
            << " | " << setw(12) << left << c.second->getMaxFlow() << " |" << setw(13) << left << deficit << " | " << endl;
            cout << "|______________|_________________|________________|______________|______________|\n";
        }
    }
    if (works){
        cout << "It's supplied enough water." << endl;
    } else{
        cout << "It isn't supplied enough water to every delivery site." << endl;
    }
}

void Menu::Reservoir_Failure(std::string code) {
    auto reservoirs = data.getReservoirs();
    auto res = reservoirs[code];
    cout << "Case: Reservoir " << code << ": " << res->getReservoir() << " is removed (it had a maximum delivery of " << res->getMaxDelivery() << "m3/sec)" << endl;
    cout << endl;
    cout << "________________________________________________________________________________\n";
    cout << "| City Code    | City Name       | Old Flow       | New Flow     | Deficit     |" << endl;
    cout << "|______________|_________________|________________|______________|_____________|\n";

    double w;
    auto grafo = data.getGrafo();
    for (auto v : grafo.getVertexSet()){
        if (v->getInfo() == code){
            for (auto edge : v->getIncoming()){
                w = edge->getWeight();
                edge->setWeight(0);
            }
        }
    }

    edmondsKarp(grafo,"mainSrc","mainTarg");

    auto cities = data.getCities();
    bool affected = false;
    for (auto v : grafo.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            double flowafter = 0;
            for (auto edge : v->getIncoming()) {
                flowafter += edge->getFlow();
            }
            auto c = cities[v->getInfo()];
            double flowbefore = c->getMaxFlow();
            double deficit = flowafter - flowbefore;
            if (deficit != 0){
                affected = true;
                cout << "| " << left << setw(13) << v->getInfo() << "| " << setw(16) << c->getCity() << "| " << setw(13) << flowbefore
                << "  | " << setw(12) << flowafter << " | " << setw(12) << deficit << "|" << endl;
                cout << "|______________|_________________|________________|______________|_____________|\n";
            }
        }
    }
    if (affected){
        cout << "There are no cities affected." << endl;
    }

    for (auto v : grafo.getVertexSet()){
        if (v->getInfo() == code){
            for (auto edge : v->getIncoming()){
                edge->setWeight(w);
            }
        }
    }
}

void Menu::Station_Failure(string code){
    auto stations = data.getStations();
    if (stations.find(code) == stations.end()){
        return;
    }
    cout << "Case: Station " << code << " is removed.These cities are affected:" << endl;
    cout << endl;
    cout << "________________________________________________________________________________\n";
    cout << "| City Code    | City Name       | Old Flow       | New Flow     | Deficit     |" << endl;
    cout << "|______________|_________________|________________|______________|_____________|\n";

    double w;
    auto grafo = data.getGrafo();
    for (auto v : grafo.getVertexSet()){
        if (v->getInfo() == code){
            for (auto edge : v->getIncoming()){
                w = edge->getWeight();
                edge->setWeight(0);
            }
        }
    }

    edmondsKarp(grafo,"mainSrc","mainTarg");
    auto cities = data.getCities();
    bool naffected = true;
    for (auto v : grafo.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            double flowafter = 0;
            for (auto edge : v->getIncoming()) {
                flowafter += edge->getFlow();
            }
            auto c = cities[v->getInfo()];
            double flowbefore = c->getMaxFlow();
            double deficit = flowafter - flowbefore;
            if (deficit != 0){
                naffected = false;
                cout << "| " << left << setw(13) << v->getInfo() << "| " << setw(16) << c->getCity() << "| " << setw(13) << flowbefore
                     << "  | " << setw(12) << flowafter << " | " << setw(12) << deficit << "|" << endl;
                cout << "|______________|_________________|________________|______________|_____________|\n";
            }
        }
    }
    if (naffected){
        cout << "There are no cities affected." << endl;
    }

    for (auto v : grafo.getVertexSet()){
        if (v->getInfo() == code){
            for (auto edge : v->getIncoming()){
                edge->setWeight(w);
            }
        }
    }
}

void Menu::Pipe_Failture(string code, string code_dest) {
    auto stations = data.getStations();
    auto reservoirs = data.getReservoirs();
    auto cities = data.getCities();
    if (stations.find(code) == stations.end() && reservoirs.find(code) == reservoirs.end() && cities.find(code) == cities.end()
    || stations.find(code_dest) == stations.end() && reservoirs.find(code_dest) == reservoirs.end() && cities.find(code_dest) == cities.end()){
        return;
    }

    double w;
    int direction = 2;
    auto grafo = data.getGrafo();
    for (auto v : grafo.getVertexSet()){
        if (v->getInfo() == code){
            for(auto d : v->getAdj()){
                if(d->getDest()->getInfo() == code_dest){
                    direction -= 1;
                }
            }
            if (direction == 2){
                return;
            }
        }
    }
    for (auto v :grafo.getVertexSet()){
        if (v->getInfo() == code_dest){
            for(auto d : v->getAdj()){
                if(d->getDest()->getInfo() == code){
                    direction -= 1;
                }
            }
        }
    }
    cout << "Case: Pipe " << code << "-" << code_dest <<" is removed" << endl;
    cout << endl;
    cout << "________________________________________________________________________________\n";
    cout << "| City Code    | City Name       | Old Flow       | New Flow     | Deficit     |" << endl;
    cout << "|______________|_________________|________________|______________|_____________|\n";


    for (auto v: grafo.getVertexSet()) {
        if (v->getInfo() == code) {
            for (auto edge: v->getAdj()) {
                if (edge->getDest()->getInfo() == code_dest) {
                    w = edge->getWeight();
                    edge->setWeight(0);
                    break;
                }
            }
        }
    }

    if (direction != 1) {
        for (auto v: grafo.getVertexSet()) {
            if (v->getInfo() == code_dest) {
                for (auto edge: v->getAdj()) {
                    if (edge->getDest()->getInfo() == code) {
                        w = edge->getWeight();
                        edge->setWeight(0);
                        break;
                    }
                }
            }
        }
    }

    edmondsKarp(grafo,"mainSrc","mainTarg");

    bool naffected = true;
    for (auto v : grafo.getVertexSet()) {
        if (v->getInfo()[0] == 'C') {
            double flowafter = 0;
            for (auto edge : v->getIncoming()) {
                flowafter += edge->getFlow();
            }
            auto c = cities[v->getInfo()];
            double flowbefore = c->getMaxFlow();
            double deficit = flowafter - flowbefore;
            if (deficit < 0){
                naffected = false;
                cout << "| " << left << setw(13) << v->getInfo() << "| " << setw(16) << c->getCity() << "| " << setw(13) << flowbefore
                     << "  | " << setw(12) << flowafter << " | " << setw(12) << deficit << "|" << endl;
                cout << "|______________|_________________|________________|______________|_____________|\n";
            }
        }
    }
    if (naffected){
        cout << "There are no cities affected." << endl;
    }

    for (auto v: grafo.getVertexSet()) {
        if (v->getInfo() == code) {
            for (auto edge: v->getAdj()) {
                if (edge->getDest()->getInfo() == code_dest) {
                    edge->setWeight(w);
                }
            }
        }
    }
    if (direction != 1){
        for (auto v: grafo.getVertexSet()) {
            if (v->getInfo() == code_dest) {
                for (auto edge: v->getAdj()) {
                    if (edge->getDest()->getInfo() == code) {
                        edge->setWeight(w);
                    }
                }
            }
        }
    }
}

