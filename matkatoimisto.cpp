// matkatoimisto.cpp
#include <string>
#include <iostream>
#include "Matkatoimisto.hpp"

using namespace std;

Matkatoimisto::Matkatoimisto(std::string& t, std::string& n, std::string& r, std::string& h, std::string& j) : tunnus(t), nimi(n), rekisterointipvm(r), henkiloita(h), johtaja(j)
{
}
Matkatoimisto::~Matkatoimisto()
{
}
std::string Matkatoimisto::haeNimi()
{
    return nimi;
}
std::string Matkatoimisto::haeTunnus()
{
    return tunnus;
}
void Matkatoimisto::tulostaTiedot()
{
    cout << "Matkatoimiston tiedot: " << endl;
    cout << tunnus << " " << nimi << " " << rekisterointipvm << " " << henkiloita << " " << johtaja << endl;
}