#include <iostream>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class FieldDoctor: public Player{

        public:
            FieldDoctor(Board& board, City city) : Player(board, city) {}
            static string role();
            FieldDoctor& treat(City city);
            FieldDoctor& take_card(City city);
            FieldDoctor& drive(City city);
            FieldDoctor& fly_direct(City city);
            FieldDoctor& fly_charter(City city);
            FieldDoctor& fly_shuttle(City city);

    };
    
}
