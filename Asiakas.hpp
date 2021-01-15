
#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <string>


class Asiakas
{
private:
    std::string tunnus;
    std::string nimi;
    std::string puhnro;
    std::string osoite;
public:
    Asiakas(std::string&, std::string&, std::string&, std::string&);
    ~Asiakas();
    std::string haeNimi();
    std::string haeTunnus();
    void tulostaTiedot();
};
#endif
