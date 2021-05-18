#include <iostream>
#include <string>
#include "Board.hpp"
#include "City.hpp"
#include <stdexcept>

#ifndef PLAYER
#define PLAYER

#define MIN_CARD 5

using namespace std;

namespace pandemic {

    class Player{

        public:
            
            Board& board;
            map<City, bool> cards;
            City current;
            int card_num;
            Player(Board& board, City city) : current(city), board(board), card_num(0) {}
            //Player(){}
            Player& drive(City city);
            Player& fly_direct(City city);
            Player& fly_charter(City city);
            Player& fly_shuttle(City city);
            void build();
            void discover_cure(Color color);
            Player& treat(City city);
            Player& take_card(City city);
            static string role();
            void remove_cards();            

    };
    
}

#endif
