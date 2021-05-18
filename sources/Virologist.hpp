#include <iostream>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class Virologist: public Player{

        public:
            Virologist(Board& board, City city) : Player(board, city) {}
            static string role();
            Virologist& treat(City city);
            Virologist& take_card(City city);
            Virologist& drive(City city);
            Virologist& fly_direct(City city);
            Virologist& fly_charter(City city);
            Virologist& fly_shuttle(City city);

    };
    
}
