#include <iostream>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class Researcher: public Player{

        public:
            Researcher(Board& board, City city) : Player(board, city) {}
            static string role();
            void discover_cure(Color color);
            Researcher& take_card(City city);
            Researcher& drive(City city);
            Researcher& fly_direct(City city);
            Researcher& fly_charter(City city);
            Researcher& fly_shuttle(City city);

    };
    
}
