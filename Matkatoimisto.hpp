// Matkatoimisto.hpp

#ifndef MATKATOIMISTO_H
#define MATKATOIMISTO_H
#include <string>


class Matkatoimisto
{
private:
    std::string tunnus;
    std::string nimi;
    std::string rekisterointipvm;
    std::string henkiloita;
    std::string johtaja;
public:
    Matkatoimisto(std::string&, std::string&, std::string&, std::string&, std::string&);
    ~Matkatoimisto();
    std::string haeNimi();
    std::string haeTunnus();
    void tulostaTiedot();
};
#endif

