#include <iostream>
#include <string>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include "City.hpp"
#include "Color.hpp"

#ifndef BOARD
#define BOARD

using namespace std;
using namespace pandemic;

namespace pandemic{

   class Board {

        public:
            Board(){this->init();}
            map<Color, bool> cures;
            map<City, bool> research;
            map<City,set<City>> neigh;
            map<City, Color> colors;
            map<City, string> names;
            int& operator[](City city);
            friend ostream& operator<<(ostream& os, Board board);
            bool is_clean();
            void remove_cures();
            void remove_station();
        private:
            void init();
            map<City, int> disease;
       
   };

}
#endif