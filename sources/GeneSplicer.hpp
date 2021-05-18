#include <iostream>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class GeneSplicer: public Player{

        public:
            GeneSplicer(Board& board, City city) : Player(board, city) {}
            static string role();
            void discover_cure(Color color);
            GeneSplicer& take_card(City city);
            GeneSplicer& drive(City city);
            GeneSplicer& fly_direct(City city);
            GeneSplicer& fly_charter(City city);
            GeneSplicer& fly_shuttle(City city);

    };
    
}
