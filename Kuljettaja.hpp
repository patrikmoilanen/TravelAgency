
#ifndef KULJETTAJA_H
#define KULJETTAJA_H
#include <string>


class Kuljettaja
{
private:
    std::string tunnus;
    std::string toimistonTunnus;
    std::string nimi;
    std::string tyohontuloPvm;
    std::string automalli;

public:
    Kuljettaja(std::string&, std::string&, std::string&, std::string&, std::string&);
    ~Kuljettaja();
    std::string haeNimi();
    std::string haeTunnus();
    void tulostaTiedot();
 
};
#endif