#include <iostream>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class Medic: public Player{

        public:
            Medic(Board& board, City city) : Player(board, city) {}
            static string role();
            Medic& treat(City city);
            Medic& drive(City city);
            Medic& fly_direct(City city);
            Medic& fly_shuttle(City city);
            Medic& fly_charter(City city);
            Medic& take_card(City city);

    };
    
}
