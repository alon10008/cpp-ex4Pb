#include <iostream>
#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

string pandemic::GeneSplicer::role(){

    return "GeneSplicer";

}
GeneSplicer& pandemic::GeneSplicer::drive(City city) {
    
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
GeneSplicer& pandemic::GeneSplicer::fly_direct(City city) {
    
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
GeneSplicer& pandemic::GeneSplicer::fly_charter(City city) {
    
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
GeneSplicer& pandemic::GeneSplicer::fly_shuttle(City city) {
    
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
void pandemic::GeneSplicer::discover_cure(Color color) {

    if(this->card_num < MIN_CARD)
    {
        throw invalid_argument("Not enough cards!\n");
    }
    if(this->board.cures[color])
    {
        return;
    }
    if(!this->board.research[this->current])
    {
        throw invalid_argument("This city dont have reasearch station!\n");
    }
    int counter = 0;
    for(map<City, bool>::iterator it = this->cards.begin() ; it != this->cards.end() ; it++)
    {
        if(it->second)
        {
            counter++;
        }
        if(counter == MIN_CARD)
        {
            break;
        }
    }
    if(counter == MIN_CARD)
    {
        counter = 0;
        for(map<City, bool>::iterator it = this->cards.begin() ; counter < MIN_CARD ; counter++)
        {
            if(it->second)
            {
                this->cards[it->first] = false;
                this->card_num--;
            }    
        }
    }
    else
    {
        throw invalid_argument("Not enough card!\n");
    }
    this->board.cures[color] = true;

}
GeneSplicer& pandemic::GeneSplicer::take_card(City city) {

    this->cards[city] = true;
    this->card_num++;
    return *this;
    
}
