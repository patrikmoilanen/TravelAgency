// kuljettaja.cpp
#include <string>
#include <iostream>
#include "Kuljettaja.hpp"

using namespace std;

Kuljettaja::Kuljettaja(std::string& t, std::string& tt, std::string& n, std::string& tpvm, std::string& am) : tunnus(t), toimistonTunnus(tt), nimi(n), tyohontuloPvm(tpvm), automalli(am)
{
}
Kuljettaja::~Kuljettaja()
{
}
std::string Kuljettaja::haeNimi()
{
    return nimi;
}
std::string Kuljettaja::haeTunnus()
{
    return tunnus;
}
void Kuljettaja::tulostaTiedot()
{
    cout << tunnus << " " << toimistonTunnus << " " << nimi << " " << tyohontuloPvm << " " << automalli << endl;
}
