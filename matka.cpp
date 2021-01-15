// matka.cpp
#include <string>
#include <iostream>
#include "Matka.hpp"

using namespace std;

Matka::Matka(std::string& t, std::string& k, std::string& mp, std::string& mk, std::string& a, std::string& l, std::string& p, std::string& pp) : tunnus(t), kuljettaja(k), matkanAlkuPvm(mp), matkanAlkuKello(mk), asiakas(a), lahtoPaikka(l), paamaara(p), palkkio(pp)
{
}
Matka::~Matka()
{
}

std::string Matka::haeTunnus()
{
    return tunnus;
}
void Matka::tulostaTiedot()
{
    cout << tunnus << " " << kuljettaja << " " << matkanAlkuPvm << " " << matkanAlkuKello << " " << asiakas << " " << lahtoPaikka << " " << paamaara << " " << palkkio << endl;
}
std::string Matka::haeAsiakas()
{
    return asiakas;
}
std::string Matka::haeKuljettaja()
{
    return kuljettaja;
}