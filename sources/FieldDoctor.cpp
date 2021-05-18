#include <iostream>
#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

string pandemic::FieldDoctor::role(){

    return "FieldDoctor";

}
FieldDoctor& pandemic::FieldDoctor::drive(City city) {
    
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
FieldDoctor& pandemic::FieldDoctor::fly_direct(City city) {
    
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
FieldDoctor& pandemic::FieldDoctor::fly_charter(City city) {
    
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
FieldDoctor& pandemic::FieldDoctor::fly_shuttle(City city) {
    
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
FieldDoctor& pandemic::FieldDoctor::treat(City city) {

    int connected = this->board.neigh[this->current].count(city);
    if(connected != 1 && this->current != city)
    {
        throw invalid_argument("Can't treat disconnected city!\n");
    }
    if(this->board[city] == 0)
    {
        throw invalid_argument("Nothing to treat!\n");
    }
    if(this->board.cures[this->board.colors[city]])
    {
        this->board[city] = 0;
    }
    else
    {
        this->board[city]--;
    }
    return *this;

}
FieldDoctor& pandemic::FieldDoctor::take_card(City city) {

    this->cards[city] = true;
    this->card_num++;
    return *this;
    
}


