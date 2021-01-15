// Matka.hpp

#ifndef MATKA_H
#define MATKA_H
#include <string>


class Matka
{
private:
    std::string tunnus;
    std::string kuljettaja;
    std::string matkanAlkuPvm;
    std::string matkanAlkuKello;
    std::string asiakas;
    std::string lahtoPaikka;
    std::string paamaara;
    std::string palkkio;
public:
    Matka(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
    ~Matka();
    std::string haeTunnus();
    void tulostaTiedot();
    std::string haeAsiakas();
    std::string haeKuljettaja();
};
#endif
