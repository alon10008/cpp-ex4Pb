#include <iostream>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    
    class Scientist: public Player{

        public:
            //Scientist(Board board, City city) : Player(board, city) {}
            Scientist(Board& board, City city, int n) : Player(board, city) , n(n) {if(n<0)throw invalid_argument("n is natural number!\n");}
            static string role();
            void discover_cure(Color color);
            Scientist& take_card(City city);
            Scientist& drive(City city);
            Scientist& fly_direct(City city);
            Scientist& fly_charter(City city);
            Scientist& fly_shuttle(City city);
            int n;

    };
    
}
