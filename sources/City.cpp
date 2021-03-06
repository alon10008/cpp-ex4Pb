#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include <map>

using namespace pandemic;
using namespace std;


/* string City::Algiers = "Algiers";
string City::Atlanta = "Atlanta";
string City::Baghdad = "Baghdad";
string City::Bangkok = "Bangkok";
string City::Beijing = "Beijing";
string City::Bogota = "Bogota";
string City::BuenosAires = "BuenosAires";
string City::Cairo = "Cairo";
string City::Chennai = "Chennai";
string City::Chicago = "Chicago";
string City::Delhi = "Delhi";
string City::Essen = "Essen";
string City::HoChiMinhCity = "HoChiMinhCity";
string City::HongKong = "HongKong";
string City::Istanbul = "Istanbul";
string City::Jakarta = "Jakarta";
string City::Johannesburg = "Johannesburg";
string City::Karachi = "Karachi";
string City::Khartoum = "Khartoum";
string City::Kinshasa = "Kinshasa";
string City::Kolkata = "Kolkata";
string City::Lagos = "Lagos";
string City::Lima = "Lima";
string City::London = "London";
string City::LosAngeles = "LosAngeles";
string City::Madrid = "Madrid";
string City::Manila = "Manila";
string City::MexicoCity = "MexicoCity";
string City::Miami = "Miami";
string City::Milan = "Milan";
string City::Montreal = "Montreal";
string City::Moscow = "Moscow";
string City::Mumbai = "Mumbai";
string City::NewYork = "NewYork";
string City::Osaka = "Osaka";
string City::Paris = "Paris";
string City::Riyadh = "Riyadh";
string City::SanFrancisco = "SanFrancisco";
string City::Santiago = "Santiago";
string City::SaoPaulo = "SaoPaulo";
string City::Seoul = "Seoul";
string City::Shanghai = "Shanghai";
string City::StPetersburg = "StPetersburg";
string City::Sydney = "Sydney";
string City::Taipei = "Taipei";
string City::Tehran = "Tehran";
string City::Tokyo = "Tokyo";
string City::Washington = "Washington"; */

//map<string, City> City::cities = map<string, city>();
/*City pandemic::City::Algiers();//("Black Madrid Paris Istanbul Cairo");
City::cities["Algiers"] = City::Algiers;
City pandemic::City::Atlanta();//("Blue Chicago Miami Washington");
City::cities["atlanta"] = City::Atlanta;
City pandemic::City::Baghdad("Black Tehran Istanbul Cairo Riyadh Karachi");
City::cities["Baghdad"] = City::Baghdad;
City pandemic::City::Bangkok ("Red Kolkata Chennai Jakarta HoChiMinhCity HongKong");
City::cities["Bangkok"] = City::Bangkok;
City pandemic::City::Beijing("Red Shanghai Seoul");
City::cities["Beijing"] = City::Beijing;
City pandemic::City::Bogota("Yellow MexicoCity Lima Miami SaoPaulo BuenosAires");
City::cities["Bogota"] = City::Bogota;
City pandemic::City::BuenosAires("Yellow Bogota SaoPaulo");
City::cities["BuenosAires"] = City::BuenosAires;
City pandemic::City::Cairo("Black Algiers Istanbul Baghdad Khartoum Riyadh");
City::cities["Cairo"] = City::Cairo;
City pandemic::City::Chennai("Black Mumbai Delhi Kolkata Bangkok Jakarta");
City::cities["Chnnai"] = City::Chennai;
City pandemic::City::Chicago("Blue SanFrancisco LosAngeles MexicoCity Atlanta Montreal");
City::cities["Chicago"] = City::Chicago;
City pandemic::City::Delhi("Black Tehran Karachi Mumbai Chennai Kolkata");
City::cities["Delhi"] = City::Delhi;
City pandemic::City::Essen("Blue London Paris Milan StPetersburg");
City::cities["Essen"] = City::Essen;
City pandemic::City::HoChiMinhCity("Red Jakarta Bangkok HongKong Manila");
City::cities["HoChiMinhCity"] = City::HoChiMinhCity;
City pandemic::City::HongKong("Red Bangkok Kolkata HoChiMinhCity Shanghai Manila Taipei");
City::cities["HongKong"] = City::HongKong;
City pandemic::City::Istanbul("Black Milan Algiers StPetersburg Cairo Baghdad Moscow");
City::cities["Istanbul"] = City::Istanbul;
City pandemic::City::Jakarta("Red Chennai Bangkok HoChiMinhCity Sydney");
City::cities["Jakarta"] = City::Jakarta;
City pandemic::City::Johannesburg("Yellow Kinshasa Khartoum");
City::cities["Johannesburg"] = City::Johannesburg;
City pandemic::City::Karachi("Black Tehran Baghdad Riyadh Mumbai Delhi");
City::cities["Karachi"] = City::Karachi;
City pandemic::City::Khartoum("Yellow Cairo Lagos Kinshasa Johannesburg");
City::cities["Khartoum"] = City::Khartoum;
City pandemic::City::Kinshasa("Yellow Lagos Khartoum Johannesburg");
City::cities["Kinshasa"] = City::Kinshasa;
City pandemic::City::Kolkata("Black Delhi Chennai Bangkok HongKong");
City::cities["Kolkata"] = City::Kolkata;
City pandemic::City::Lagos("Yellow SaoPaulo Khartoum Kinshasa");
City::cities["Lagos"] = City::Lagos;
City pandemic::City::London"Blue NewYork Madrid Essen Paris");
City::cities["London"] = City::London;
City pandemic::City::LosAngeles("Yellow SanFrancisco Chicago MexicoCity Sydney");
City::cities["LosAngeles"] = City::LosAngeles;
City pandemic::City::Madrid("Blue London NewYork Paris SaoPaulo Algiers");
City::cities["Madrid"] = City::Madrid;
City pandemic::City::Manila("Red Taipei SanFrancisco HoChiMinhCity Sydney");
City::cities["Manila"] = City::Manila;
City pandemic::City::MexicoCity("Yellow LosAngeles Chicago Miami Lima Bogota");
City::cities["MexicoCity"] = City::MexicoCity;
City pandemic::City::Miami("Yellow Atlanta MexicoCity Washington Bogota");
City::cities["Miami"] = City::Miami;
City pandemic::City::Milan("Blue Essen Paris Istanbul");
City::cities["Milan"] = City::Milan;
City pandemic::City::Montreal("Blue Chicago Washington NewYork");
City::cities["Montreal"] = City::Montreal;
City pandemic::City::Moscow("Black StPetersburg Istanbul Tehran");
City::cities["Moscow"] = City::Moscow;
City pandemic::City::Mumbai("Black Karachi Delhi Chennai");
City::cities["Mumbai"] = City::Mumbai;
City pandemic::City::NewYork("Blue Montreal Washington London Madrid");
City::cities["NewYork"] = City::NewYork;
City pandemic::City::Osaka("Red Taipei Tokyo");
City::cities["Osaka"] = City::Osaka;
City pandemic::City::Paris("Blue Algiers Essen Madrid Milan London");
City::cities["Paris"] = City::Paris;
City pandemic::City::Riyadh("Black Baghdad Cairo Karachi");
City::cities["Riyadh"] = City::Riyadh;
City pandemic::City::SanFrancisco("Blue LosAngeles Chicago Tokyo Manila");
City::cities["SanFrancisco"] = City::SanFrancisco;
City pandemic::City::Santiago("Yellow Lima");
City::cities["Santiago"] = City::Santiago;
City pandemic::City::SaoPaulo("Yellow Bogota BuenosAires Lagos Madrid");
City::cities["SaoPaulo"] = City::SaoPaulo;
City pandemic::City::Seoul("Red Beijing Shanghai Tokyo");
City::cities["Seoul"] = City::Seoul;
City pandemic::City::Shanghai("Red Beijing HongKong Taipei Seoul Tokyo");
City::cities["Shanghai"] = City::Shanghai;
City pandemic::City::StPetersburg("Blue Essen Istanbul Moscow");
City::cities["StPetersburg"] = City::StPetersburg;
City pandemic::City::Sydney("Red Jakarta Manila LosAngeles");
City::cities["Sydney"] = City::Sydney;
City pandemic::City::Taipei("Red Shanghai HongKong Osaka Manila");
City::cities["Taipei"] = City::Taipei;
City pandemic::City::Tehran("Black Baghdad Moscow Karachi Delhi");
City::cities["Tehran"] = City::Tehran;
City pandemic::City::Tokyo("Red Seoul Shanghai Osaka SanFrancisco");
City::cities["Tokyo"] = City::Tokyo;
City pandemic::City::Washington("Blue Atlanta NewYork Montreal Miami");
City::cities["Washington"] = City::Washington; */



