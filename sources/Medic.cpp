#include <iostream>
#include "Medic.hpp"

using namespace std;
using namespace pandemic;

string pandemic::Medic::role(){

    return "Medic";

}
Medic& pandemic::Medic::drive(City city) {
    
    if(this->current == city)
    {
        throw invalid_argument("Can't drive to the current city!\n");
    }
    int c = this->board.neigh[this->current].count(city);
    if(c != 1)
    {
        throw invalid_argument("Can't travel to disconnected city!\n");
    }
    this->current = city;
    if(this->board.cures[this->board.colors[city]])
    {
        this->board[city] = 0;
    }
    return *this;
    
}
Medic& pandemic::Medic::fly_direct(City city) {
    
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
    if(this->board.cures[this->board.colors[city]])
    {
        this->board[city] = 0;
    }
    return *this;

}
Medic& pandemic::Medic::fly_charter(City city) {
    
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
    if(this->board.cures[this->board.colors[city]])
    {
        this->board[city] = 0;
    }
    return *this;
    
}
Medic& pandemic::Medic::fly_shuttle(City city) {
    
    if(this->current == city)
    {
        throw invalid_argument("Can't fly to the current city!\n");
    }
    if(!this->board.research[city])
    {
        throw invalid_argument("Currrent city dont have research station!\n");
    }
    if(!this->board.research[city])
    {
        throw invalid_argument("Can't fly to city without research station!\n");
    }
    this->current = city;
    if(this->board.cures[this->board.colors[city]])
    {
        this->board[city] = 0;
    }
    return *this;
    
}
Medic& pandemic::Medic::treat(City city) {

    if(this->current != city)
    {
        throw invalid_argument("Can't treat remote city!\n");
    }
    if(this->board[city] == 0)
    {
        throw invalid_argument("Nothing to treat!\n");
    }
    this->board[city] = 0;
    return *this;

}
Medic& pandemic::Medic::take_card(City city) {

    this->cards[city] = true;
    this->card_num++;
    return *this;

}
