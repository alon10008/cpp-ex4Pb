#include "Board.hpp"
#include <stdexcept>
#include <string>
#include "Color.hpp"
#include "City.hpp"
#include <map>

using namespace std;
using namespace pandemic;

int& pandemic::Board::operator[](City city) {

    return this->disease[city];

}
ostream& pandemic::operator<<(ostream& os, Board board) {

    for(map<City, string>::iterator it = board.names.begin() ; it != board.names.end() ; it++)
    {
        os << it->second << ": disease lvl - " << board[it->first];
        if(board.research[it->first])
        {
            os << " ----- have research station!" << endl;
        }
        else
        {
            os<< " ---- don't have research station" << endl;
        }
    }
    os << "--------------------------------------------------------------" << endl;
    os << "--------------------------------------------------------------" << endl;
    
    return os;

}
bool pandemic::Board::is_clean() {

    for(map<City, int>::iterator it = this->disease.begin() ; it != this->disease.end() ; it++)
    {
        if(it->second > 0)
        {
            return false;
        }
    }
    return true;

}
void pandemic::Board::remove_cures() {

    this->cures[Color::Black] = false;
    this->cures[Color::Red] = false;
    this->cures[Color::Yellow] = false;
    this->cures[Color::Blue] = false;

}
void pandemic::Board::remove_station() {

    for(map<City, bool>::iterator it = this->research.begin() ; it != this->research.end() ; it++)
    {
        this->research[it->first] = false;
    }

}
void pandemic::Board::init() {

    this->neigh[City::Algiers].insert(City::Madrid);
    this->neigh[City::Algiers].insert(City::Paris);
    this->neigh[City::Algiers].insert(City::Istanbul);
    this->neigh[City::Algiers].insert(City::Cairo);
    this->colors[City::Algiers] = Color::Black;
    this->names[City::Algiers] = "Algiers";
    this->neigh[City::Atlanta].insert(City::Chicago);
    this->neigh[City::Atlanta].insert(City::Miami);
    this->neigh[City::Atlanta].insert(City::Washington);
    this->colors[City::Atlanta] = Color::Blue;
    this->names[City::Atlanta] = "Atlanta";
    this->neigh[City::Baghdad].insert(City::Tehran);
    this->neigh[City::Baghdad].insert(City::Istanbul);
    this->neigh[City::Baghdad].insert(City::Cairo);
    this->neigh[City::Baghdad].insert(City::Riyadh);
    this->neigh[City::Baghdad].insert(City::Karachi);
    this->colors[City::Baghdad] = Color::Black;
    this->names[City::Baghdad] = "Baghdad";
    this->neigh[City::Bangkok].insert(City::Kolkata);
    this->neigh[City::Bangkok].insert(City::Chennai);
    this->neigh[City::Bangkok].insert(City::Jakarta);
    this->neigh[City::Bangkok].insert(City::HoChiMinhCity);
    this->neigh[City::Bangkok].insert(City::HongKong);
    this->colors[City::Bangkok] = Color::Red;
    this->names[City::Bangkok] = "Bangkok";
    this->neigh[City::Beijing].insert(City::Shanghai);
    this->neigh[City::Beijing].insert(City::Seoul);
    this->colors[City::Beijing] = Color::Red;
    this->names[City::Beijing] = "Beijing";
    this->neigh[City::Bogota].insert(City::MexicoCity);
    this->neigh[City::Bogota].insert(City::Lima);
    this->neigh[City::Bogota].insert(City::Miami);
    this->neigh[City::Bogota].insert(City::SaoPaulo);
    this->neigh[City::Bogota].insert(City::BuenosAires);
    this->colors[City::Bogota] = Color::Yellow;
    this->names[City::Bogota] = "Bogota";
    this->neigh[City::BuenosAires].insert(City::Bogota);
    this->neigh[City::BuenosAires].insert(City::SaoPaulo);
    this->colors[City::BuenosAires] = Color::Yellow;
    this->names[City::BuenosAires] = "BuenosAires";
    this->neigh[City::Cairo].insert(City::Algiers);
    this->neigh[City::Cairo].insert(City::Istanbul);
    this->neigh[City::Cairo].insert(City::Baghdad);
    this->neigh[City::Cairo].insert(City::Khartoum);
    this->neigh[City::Cairo].insert(City::Riyadh);
    this->colors[City::Cairo] = Color::Black;
    this->names[City::Cairo] = "Cairo";
    this->neigh[City::Chennai].insert(City::Mumbai);
    this->neigh[City::Chennai].insert(City::Delhi);
    this->neigh[City::Chennai].insert(City::Kolkata);
    this->neigh[City::Chennai].insert(City::Bangkok);
    this->neigh[City::Chennai].insert(City::Jakarta);
    this->colors[City::Chennai] = Color::Black;
    this->names[City::Chennai] = "Chennai";
    this->neigh[City::Chicago].insert(City::SanFrancisco);
    this->neigh[City::Chicago].insert(City::LosAngeles);
    this->neigh[City::Chicago].insert(City::MexicoCity);
    this->neigh[City::Chicago].insert(City::Atlanta);
    this->neigh[City::Chicago].insert(City::Montreal);
    this->colors[City::Chicago] = Color::Blue;
    this->names[City::Chicago] = "Chicago";
    this->neigh[City::Delhi].insert(City::Tehran);
    this->neigh[City::Delhi].insert(City::Karachi);
    this->neigh[City::Delhi].insert(City::Mumbai);
    this->neigh[City::Delhi].insert(City::Chennai);
    this->neigh[City::Delhi].insert(City::Kolkata);
    this->colors[City::Delhi] = Color::Black;
    this->names[City::Delhi] = "Delhi";
    this->neigh[City::Essen].insert(City::London);
    this->neigh[City::Essen].insert(City::Paris);
    this->neigh[City::Essen].insert(City::Milan);
    this->neigh[City::Essen].insert(City::StPetersburg);
    this->colors[City::Essen] = Color::Blue;
    this->names[City::Essen] = "Essen";
    this->neigh[City::HoChiMinhCity].insert(City::Jakarta);
    this->neigh[City::HoChiMinhCity].insert(City::Bangkok);
    this->neigh[City::HoChiMinhCity].insert(City::HongKong);
    this->neigh[City::HoChiMinhCity].insert(City::Manila);
    this->colors[City::HoChiMinhCity] = Color::Red;
    this->names[City::HoChiMinhCity] = "HoChiMinhCity";
    this->neigh[City::HongKong].insert(City::Bangkok);
    this->neigh[City::HongKong].insert(City::Kolkata);
    this->neigh[City::HongKong].insert(City::HoChiMinhCity);
    this->neigh[City::HongKong].insert(City::Shanghai);
    this->neigh[City::HongKong].insert(City::Manila);
    this->neigh[City::HongKong].insert(City::Taipei);
    this->colors[City::HongKong] = Color::Red;
    this->names[City::HongKong] = "HongKong";
    this->neigh[City::Istanbul].insert(City::Milan);
    this->neigh[City::Istanbul].insert(City::Algiers);
    this->neigh[City::Istanbul].insert(City::StPetersburg);
    this->neigh[City::Istanbul].insert(City::Cairo);
    this->neigh[City::Istanbul].insert(City::Baghdad);
    this->neigh[City::Istanbul].insert(City::Moscow);
    this->colors[City::Istanbul] = Color::Black;
    this->names[City::Istanbul] = "Istanbul";
    this->neigh[City::Jakarta].insert(City::Chennai);
    this->neigh[City::Jakarta].insert(City::Bangkok);
    this->neigh[City::Jakarta].insert(City::HoChiMinhCity);
    this->neigh[City::Jakarta].insert(City::Sydney);
    this->colors[City::Jakarta] = Color::Red;
    this->names[City::Jakarta] = "Jakarta";
    this->neigh[City::Johannesburg].insert(City::Kinshasa);
    this->neigh[City::Johannesburg].insert(City::Khartoum);
    this->colors[City::Johannesburg] = Color::Yellow;
    this->names[City::Johannesburg] = "Johannesburg";
    this->neigh[City::Karachi].insert(City::Tehran);
    this->neigh[City::Karachi].insert(City::Baghdad);
    this->neigh[City::Karachi].insert(City::Riyadh);
    this->neigh[City::Karachi].insert(City::Mumbai);
    this->neigh[City::Karachi].insert(City::Delhi);
    this->colors[City::Karachi] = Color::Black;
    this->names[City::Karachi] = "Karachi";
    this->neigh[City::Khartoum].insert(City::Cairo);
    this->neigh[City::Khartoum].insert(City::Lagos);
    this->neigh[City::Khartoum].insert(City::Kinshasa);
    this->neigh[City::Khartoum].insert(City::Johannesburg);
    this->colors[City::Khartoum] = Color::Yellow;
    this->names[City::Khartoum] = "Khartoum";
    this->neigh[City::Kinshasa].insert(City::Lagos);
    this->neigh[City::Kinshasa].insert(City::Khartoum);
    this->neigh[City::Kinshasa].insert(City::Johannesburg);
    this->colors[City::Kinshasa] = Color::Yellow;
    this->names[City::Kinshasa] = "Kinshasa";
    this->neigh[City::Kolkata].insert(City::Delhi);
    this->neigh[City::Kolkata].insert(City::Chennai);
    this->neigh[City::Kolkata].insert(City::Bangkok);
    this->neigh[City::Kolkata].insert(City::HongKong);
    this->colors[City::Kolkata] = Color::Black;
    this->names[City::Kolkata] = "Kolkata";
    this->neigh[City::Lagos].insert(City::SaoPaulo);
    this->neigh[City::Lagos].insert(City::Khartoum);
    this->neigh[City::Lagos].insert(City::Kinshasa);
    this->colors[City::Lagos] = Color::Yellow;
    this->names[City::Lagos] = "Lagos";
    this->neigh[City::Lima].insert(City::MexicoCity);
    this->neigh[City::Lima].insert(City::Bogota);
    this->neigh[City::Lima].insert(City::Santiago);
    this->colors[City::Lima] = Color::Yellow;
    this->names[City::Lima] = "Lima";
    this->neigh[City::London].insert(City::NewYork);
    this->neigh[City::London].insert(City::Madrid);
    this->neigh[City::London].insert(City::Essen);
    this->neigh[City::London].insert(City::Paris);
    this->colors[City::London] = Color::Blue;
    this->names[City::London] = "London";
    this->neigh[City::LosAngeles].insert(City::SanFrancisco);
    this->neigh[City::LosAngeles].insert(City::Chicago);
    this->neigh[City::LosAngeles].insert(City::MexicoCity);
    this->neigh[City::LosAngeles].insert(City::Sydney);
    this->colors[City::LosAngeles] = Color::Yellow;
    this->names[City::LosAngeles] = "LosAngeles";
    this->neigh[City::Madrid].insert(City::London);
    this->neigh[City::Madrid].insert(City::NewYork);
    this->neigh[City::Madrid].insert(City::Paris);
    this->neigh[City::Madrid].insert(City::SaoPaulo);
    this->neigh[City::Madrid].insert(City::Algiers);
    this->colors[City::Madrid] = Color::Blue;
    this->names[City::Madrid] = "Madrid";
    this->neigh[City::Manila].insert(City::Taipei);
    this->neigh[City::Manila].insert(City::SanFrancisco);
    this->neigh[City::Manila].insert(City::HoChiMinhCity);
    this->neigh[City::Manila].insert(City::Sydney);
    this->neigh[City::Manila].insert(City::HongKong);
    this->colors[City::Manila] = Color::Red;
    this->names[City::Manila] = "Manila";
    this->neigh[City::MexicoCity].insert(City::LosAngeles);
    this->neigh[City::MexicoCity].insert(City::Chicago);
    this->neigh[City::MexicoCity].insert(City::Miami);
    this->neigh[City::MexicoCity].insert(City::Lima);
    this->neigh[City::MexicoCity].insert(City::Bogota);
    this->colors[City::MexicoCity] = Color::Yellow;
    this->names[City::MexicoCity] = "MexicoCity";
    this->neigh[City::Miami].insert(City::Atlanta);
    this->neigh[City::Miami].insert(City::MexicoCity);
    this->neigh[City::Miami].insert(City::Washington);
    this->neigh[City::Miami].insert(City::Bogota);
    this->colors[City::Miami] = Color::Yellow;
    this->names[City::Miami] = "Miami";
    this->neigh[City::Milan].insert(City::Essen);
    this->neigh[City::Milan].insert(City::Paris);
    this->neigh[City::Milan].insert(City::Istanbul);
    this->colors[City::Milan] = Color::Blue;
    this->names[City::Milan] = "Milan";
    this->neigh[City::Montreal].insert(City::Chicago);
    this->neigh[City::Montreal].insert(City::Washington);
    this->neigh[City::Montreal].insert(City::NewYork);
    this->colors[City::Montreal] = Color::Blue;
    this->names[City::Montreal] = "Montreal";
    this->neigh[City::Moscow].insert(City::StPetersburg);
    this->neigh[City::Moscow].insert(City::Istanbul);
    this->neigh[City::Moscow].insert(City::Tehran);
    this->colors[City::Moscow] = Color::Black;
    this->names[City::Moscow] = "Moscow";
    this->neigh[City::Mumbai].insert(City::Karachi);
    this->neigh[City::Mumbai].insert(City::Delhi);
    this->neigh[City::Mumbai].insert(City::Chennai);
    this->colors[City::Mumbai] = Color::Black;
    this->names[City::Mumbai] = "Mumbai";
    this->neigh[City::NewYork].insert(City::Montreal);
    this->neigh[City::NewYork].insert(City::Washington);
    this->neigh[City::NewYork].insert(City::London);
    this->neigh[City::NewYork].insert(City::Madrid);
    this->colors[City::NewYork] = Color::Blue;
    this->names[City::NewYork] = "NewYork";
    this->neigh[City::Osaka].insert(City::Taipei);
    this->neigh[City::Osaka].insert(City::Tokyo);
    this->colors[City::Osaka] = Color::Red;
    this->names[City::Osaka] = "Osaka";
    this->neigh[City::Paris].insert(City::Algiers);
    this->neigh[City::Paris].insert(City::Essen);
    this->neigh[City::Paris].insert(City::Madrid);
    this->neigh[City::Paris].insert(City::Milan);
    this->neigh[City::Paris].insert(City::London);
    this->colors[City::Paris] = Color::Blue;
    this->names[City::Paris] = "Paris";
    this->neigh[City::Riyadh].insert(City::Baghdad);
    this->neigh[City::Riyadh].insert(City::Cairo);
    this->neigh[City::Riyadh].insert(City::Karachi);
    this->colors[City::Riyadh] = Color::Black;
    this->names[City::Riyadh] = "Riyadh";
    this->neigh[City::SanFrancisco].insert(City::LosAngeles);
    this->neigh[City::SanFrancisco].insert(City::Chicago);
    this->neigh[City::SanFrancisco].insert(City::Tokyo);
    this->neigh[City::SanFrancisco].insert(City::Manila);
    this->colors[City::SanFrancisco] = Color::Blue;
    this->names[City::SanFrancisco] = "SanFrancisco";
    this->neigh[City::Santiago].insert(City::Lima);
    this->colors[City::Santiago] = Color::Yellow;
    this->names[City::Santiago] = "Santiago";
    this->neigh[City::SaoPaulo].insert(City::Bogota);
    this->neigh[City::SaoPaulo].insert(City::BuenosAires);
    this->neigh[City::SaoPaulo].insert(City::Lagos);
    this->neigh[City::SaoPaulo].insert(City::Madrid);
    this->colors[City::SaoPaulo] = Color::Yellow;
    this->names[City::SaoPaulo] = "SaoPaulo";
    this->neigh[City::Seoul].insert(City::Beijing);
    this->neigh[City::Seoul].insert(City::Shanghai);
    this->neigh[City::Seoul].insert(City::Tokyo);
    this->colors[City::Seoul] = Color::Red;
    this->names[City::Seoul] = "Seoul";
    this->neigh[City::Shanghai].insert(City::Beijing);
    this->neigh[City::Shanghai].insert(City::HongKong);
    this->neigh[City::Shanghai].insert(City::Taipei);
    this->neigh[City::Shanghai].insert(City::Seoul);
    this->neigh[City::Shanghai].insert(City::Tokyo);
    this->colors[City::Shanghai] = Color::Red;
    this->names[City::Shanghai] = "Shenghai";
    this->neigh[City::StPetersburg].insert(City::Essen);
    this->neigh[City::StPetersburg].insert(City::Istanbul);
    this->neigh[City::StPetersburg].insert(City::Moscow);
    this->colors[City::StPetersburg] = Color::Blue;
    this->names[City::StPetersburg] = "StPetersburg";
    this->neigh[City::Sydney].insert(City::Jakarta);
    this->neigh[City::Sydney].insert(City::Manila);
    this->neigh[City::Sydney].insert(City::LosAngeles);
    this->colors[City::Sydney] = Color::Red;
    this->names[City::Sydney] = "Sydney";
    this->neigh[City::Taipei].insert(City::Shanghai);
    this->neigh[City::Taipei].insert(City::HongKong);
    this->neigh[City::Taipei].insert(City::Osaka);
    this->neigh[City::Taipei].insert(City::Manila);
    this->colors[City::Taipei] = Color::Red;
    this->names[City::Taipei] = "Taipei";
    this->neigh[City::Tehran].insert(City::Baghdad);
    this->neigh[City::Tehran].insert(City::Moscow);
    this->neigh[City::Tehran].insert(City::Karachi);
    this->neigh[City::Tehran].insert(City::Delhi);
    this->colors[City::Tehran] = Color::Black;
    this->names[City::Tehran] = "Tehran";
    this->neigh[City::Tokyo].insert(City::Seoul);
    this->neigh[City::Tokyo].insert(City::Shanghai);
    this->neigh[City::Tokyo].insert(City::Osaka);
    this->neigh[City::Tokyo].insert(City::SanFrancisco);
    this->colors[City::Tokyo] = Color::Red;
    this->names[City::Tokyo] = "Tokyo";
    this->neigh[City::Washington].insert(City::Atlanta);
    this->neigh[City::Washington].insert(City::NewYork);
    this->neigh[City::Washington].insert(City::Montreal);
    this->neigh[City::Washington].insert(City::Miami);
    this->colors[City::Washington] = Color::Blue;
    this->names[City::Washington] = "Washington";

    for(map<City, Color>::iterator it = this->colors.begin() ; it != this->colors.end() ; it++)
    {
        this->disease[it->first] = 0;
        this->research[it->first] = false;
    }

    this->cures[Color::Black] = false;
    this->cures[Color::Blue] = false;
    this->cures[Color::Red] = false;
    this->cures[Color::Yellow] = false;

}


