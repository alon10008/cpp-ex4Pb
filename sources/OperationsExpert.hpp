#include <iostream>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class OperationsExpert: public Player{

        public:
            OperationsExpert(Board& board, City city) : Player(board, city) {}
            static string role();
            void build();
            OperationsExpert& take_card(City city);
            OperationsExpert& drive(City city);
            OperationsExpert& fly_direct(City city);
            OperationsExpert& fly_charter(City city);
            OperationsExpert& fly_shuttle(City city);

    };
    
}
