// asiakas.cpp
#include <string>
#include <iostream>
#include "Asiakas.hpp"

using namespace std;


Asiakas::Asiakas(std::string& t, std::string& n, std::string& p, std::string& o) : tunnus(t), nimi(n), puhnro(p), osoite(o)
{
}
Asiakas::~Asiakas()
{
}
std::string Asiakas::haeNimi()
{
    return nimi;
}
std::string Asiakas::haeTunnus()
{
    return tunnus;
}
void Asiakas::tulostaTiedot()
{
    cout << "Asiakkaa tiedot: " << endl;
    cout << tunnus << " " << nimi << " " << puhnro << " " << osoite << endl;
}