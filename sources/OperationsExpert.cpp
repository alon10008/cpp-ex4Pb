#include <iostream>
#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

string pandemic::OperationsExpert::role(){

    return "OperationsExpert";

}
OperationsExpert& pandemic::OperationsExpert::drive(City city) {
    
    if(this->current == city)
    {
        throw invalid_argument("Can't drive to the current city!\n");
    }
    int c = this->board.neigh[this->current].count(city);
    if(c == 0)
    {
        throw invalid_argument("Can't travel to disconnected city!\n");
    }
    this->current = city;
    return *this;
    
}
OperationsExpert& pandemic::OperationsExpert::fly_direct(City city) {
    
    if(this->current == city)
    {
        throw invalid_argument("Can't fly to the current city!\n");
    }
    if(!this->cards[city])
    {
        throw invalid_argument("Don't have the city card!\n");
    }
    this->cards[city] = false;
    this->card_num--;
    this->current = city;
    return *this;

}
OperationsExpert& pandemic::OperationsExpert::fly_charter(City city) {
    
    if(this->current == city)
    {
        throw invalid_argument("Can't fly to the current city!\n");
    }
    if(!this->cards[this->current])
    {
        throw invalid_argument("Don't have the right card!\n");
    }
    this->cards[this->current] = false;
    this->card_num--;
    this->current = city;
    return *this;
    
}
OperationsExpert& pandemic::OperationsExpert::fly_shuttle(City city) {
    
    if(this->current == city)
    {
        throw invalid_argument("Can't fly to the current city!\n");
    }
    if(!this->board.research[this->current])
    {
        throw invalid_argument("Currrent city dont have research station!\n");
    }
    if(!this->board.research[city])
    {
        throw invalid_argument("Can't fly to city without research station!\n");
    }
    this->current = city;
    return *this;
    
}
void pandemic::OperationsExpert::build() {

    this->board.research[this->current] = true;

}
OperationsExpert& pandemic::OperationsExpert::take_card(City city) {

    this->cards[city] = true;
    this->card_num++;
    return *this;
    
}