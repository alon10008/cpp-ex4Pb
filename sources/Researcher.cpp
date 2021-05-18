#include <iostream>
#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

string pandemic::Researcher::role(){

    return "Researcher";

}
Researcher& pandemic::Researcher::drive(City city) {
    
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
Researcher& pandemic::Researcher::fly_direct(City city) {
    
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
Researcher& pandemic::Researcher::fly_charter(City city) {
    
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
Researcher& pandemic::Researcher::fly_shuttle(City city) {
    
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
void pandemic::Researcher::discover_cure(Color color) {

    if(this->board.cures[color])
    {
        return;
    }
    int counter = 0;
    for(map<City, bool>::iterator it = this->cards.begin() ; it != this->cards.end() ; it++)
    {

        if(it->second)
        {
            if(this->board.colors[it->first] == color)
            {
                counter++;
            }
        }
    }
    if(counter >= MIN_CARD)
    {
        counter = 0;
        for(map<City, bool>::iterator it = this->cards.begin() ; it != this->cards.end() ; it++)
        {
            if(it->second)
            {
                if(this->board.colors[it->first] == color)
                {
                    counter++;
                    this->cards[it->first] = false;
                }
            }
            if(counter == MIN_CARD)
            {
                break;
            }
        }
    }
    else
    {
        throw invalid_argument("Not enough card with the right color!\n");
    }
    this->board.cures[color] = true;

}
Researcher& pandemic::Researcher::take_card(City city) {

    this->cards[city] = true;
    this->card_num++;
    return *this;
    
}
