#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;
using namespace pandemic;


Player& pandemic::Player::drive(City city) {
    
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
Player& pandemic::Player::fly_direct(City city) {
    
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
Player& pandemic::Player::fly_charter(City city) {
    
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
Player& pandemic::Player::fly_shuttle(City city) {
    
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
void pandemic::Player::build() {

    if(!this->cards[this->current])
    {
        throw invalid_argument("Don't have the right card!\n");
    }
    if(!this->board.research[this->current])
    {
        this->cards[this->current] = false;
        this->card_num--;
    }
    this->board.research[this->current] = true;

}
void pandemic::Player::discover_cure(Color color) {

    if(this->board.cures[color])
    {
        return;
    }
    if(!this->board.research[this->current])
    {
        throw invalid_argument("This city don't have reasearch station!\n");
    }
    if(this->card_num < MIN_CARD)
    {
        throw invalid_argument("Not enough cards!\n");
    }
    int counter = 0;
    for(map<City, Color>::iterator it = this->board.colors.begin() ; it != this->board.colors.end() ; it++)
    {
        if(this->cards[it->first])
        {
            if(it->second == color)
            {
                counter++;
            }
        }
        if(counter == MIN_CARD)
        {
            break;
        }
    }
    if(counter == MIN_CARD)
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
Player& pandemic::Player::treat(City city) {
    
    if(this->current != city)
    {
        throw invalid_argument("Can't treat remote city!\n");
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
Player& pandemic::Player::take_card(City city) {

    this->cards[city] = true;
    this->card_num++;
    return *this;
}

string pandemic::Player::role() {
    
    return "Player";

}
void pandemic::Player::remove_cards() {

    for(map<City, bool>::iterator it = this->cards.begin() ; it != this->cards.end() ; it++)
    {
        this->cards[it->first] = false;
    }
    this->card_num = 0;

}


