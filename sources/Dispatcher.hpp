#include <iostream>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class Dispatcher: public Player{

        public:
            Dispatcher(Board& board, City city) : Player(board, city) {}
            static string role();
            Dispatcher& fly_direct(City city);
            Dispatcher& take_card(City city);
            Dispatcher& drive(City city);
            Dispatcher& fly_charter(City city);
            Dispatcher& fly_shuttle(City city);

    };
    
}
