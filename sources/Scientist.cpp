#include <iostream>
#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

string pandemic::Scientist::role(){

    return "Scientist";

}
Scientist& pandemic::Scientist::drive(City city) {
    
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
Scientist& pandemic::Scientist::fly_direct(City city) {
    
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
Scientist& pandemic::Scientist::fly_charter(City city) {
    
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
Scientist& pandemic::Scientist::fly_shuttle(City city) {
    
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
void pandemic::Scientist::discover_cure(Color color) {
  
    if(this->board.cures[color])
    {
        return;
    }
    if(this->card_num<this->n)
    {
        throw invalid_argument("Not enough cards!\n");
    }
    if(!this->board.research[this->current])
    {
        throw invalid_argument("This city don't have reasearch station!\n");
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
    if(counter >= this->n)
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
                    this->card_num--;
                }
            }
            if(counter == this->n)
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
Scientist& pandemic::Scientist::take_card(City city) {

    this->cards[city] = true;
    this->card_num++;
    return *this;
    
}
