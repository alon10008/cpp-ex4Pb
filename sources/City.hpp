#include <iostream>
#include "Color.hpp"
#include <string>
#include <cstring>
#include <map>

#ifndef CITY
#define CITY

using namespace std;
using namespace pandemic;

namespace pandemic{

    enum class City{

        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington

    };
    /*class City {

        public:

            static map<string, City> cities;
            map<City, bool> neigh;
            Color color;
            string detail;
            City(){this->detail = "";}
            City(string detail)
            {
                this->detail = detail;
                string word;
                bool first = true;
                char str[detail.size() + 1];
                strcpy(str, &detail[0]);
                for(int i=0 ; i<detail.length() ; i++)
                {
                    if(str[i] == ' ' || i == (detail.length()-1))
                    {
                        if(first)
                        {
                            this->color = Color::colors[word];
                            first = false;
                        }
                        else
                        {
                            this->neigh[cities[word]] = true;
                        }
                        word = "";
                    }
                    else
                    {
                        word += str[i];
                    }
                }
                
            } */

            /*static string Algiers;
            static string Atlanta;
            static string Baghdad;
            static string Bangkok;
            static string Beijing;
            static string Bogota;
            static string BuenosAires;
            static string Cairo;
            static string Chennai;
            static string Chicago;
            static string Delhi;
            static string Essen;
            static string HoChiMinhCity;
            static string HongKong;
            static string Istanbul;
            static string Jakarta;
            static string Johannesburg;
            static string Karachi;
            static string Khartoum;
            static string Kinshasa;
            static string Kolkata;
            static string Lagos;
            static string Lima;
            static string London;
            static string LosAngeles;
            static string Madrid;
            static string Manila;
            static string MexicoCity;
            static string Miami;
            static string Milan;
            static string Montreal;
            static string Moscow;
            static string Mumbai;
            static string NewYork;
            static string Osaka;
            static string Paris;
            static string Riyadh;
            static string SanFrancisco;
            static string Santiago;
            static string SaoPaulo;
            static string Seoul;
            static string Shanghai;
            static string StPetersburg;
            static string Sydney;
            static string Taipei;
            static string Tehran;
            static string Tokyo;
            static string Washington;*/
            
           /* static City Algiers;
            static City Atlanta;
            static City Baghdad;
            static City Bangkok;
            static City Beijing;
            static City Bogota;
            static City BuenosAires;
            static City Cairo;
            static City Chennai;
            static City Chicago;
            static City Delhi;
            static City Essen;
            static City HoChiMinhCity;
            static City HongKong;
            static City Istanbul;
            static City Jakarta;
            static City Johannesburg;
            static City Karachi;
            static City Khartoum;
            static City Kinshasa;
            static City Kolkata;
            static City Lagos;
            static City Lima;
            static City London;
            static City LosAngeles;
            static City Madrid;
            static City Manila;
            static City MexicoCity;
            static City Miami;
            static City Milan;
            static City Montreal;
            static City Moscow;
            static City Mumbai;
            static City NewYork;
            static City Osaka;
            static City Paris;
            static City Riyadh;
            static City SanFrancisco;
            static City Santiago;
            static City SaoPaulo;
            static City Seoul;
            static City Shanghai;
            static City StPetersburg;
            static City Sydney;
            static City Taipei;
            static City Tehran;
            static City Tokyo;
            static City Washington; 

    }; */



}

#endif
