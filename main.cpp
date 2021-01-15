#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Matkatoimisto.hpp"
#include "Asiakas.hpp"
#include "Matka.hpp"
#include "Kuljettaja.hpp"
using namespace std;

void naytaValikko();
void haeMatkatoimisto(string);
void haeAsiakas(string);
void haeMatka(string);
void lueMatkat();
void lueAsiakkaat();
void lisaaMatka();
void poistaMatka(string);
unsigned int lueMatkatoimistot();
void haePalvelut(string);
void lueKuljettajat();
void haeKuljettaja(string);
void haeAsiakkaanKuljettajat(string);

typedef vector<Matkatoimisto> MatkatoimistoRepo;
MatkatoimistoRepo matkatoimistot;
typedef vector<Asiakas> AsiakasRepo;
AsiakasRepo asiakkaat;
typedef vector<Matka> MatkaRepo;
MatkaRepo matkat;
typedef vector<Kuljettaja> KuljettajaRepo;
KuljettajaRepo kuljettajat;

int main()
{
	string haettava;
	string poistettava;
    float x, y;
	int choice;
    unsigned int lukuOnnistui = 0;

    lukuOnnistui = lueMatkatoimistot();
	lueAsiakkaat();
	lueMatkat();
	lueKuljettajat();

	do
	{
		naytaValikko();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Anna matkatoimiston nimi tai tunnus: ";
			cin >> haettava;
			haeMatkatoimisto(haettava);
			break;
		case 2:
			cout << "Anna asiakkaan nimi tai tunnus: ";
			cin >> haettava;
			haeAsiakas(haettava);
			break;
		case 3:
			cout << "Anna kuljettajan nimi tai tunnus: ";
			cin >> haettava;
			haeKuljettaja(haettava);
			break;
		case 4:
			cout << "Anna matkan tiedot: " << endl;
			lisaaMatka();
			break;
        case 5:
			cout << "Anna poistettavan matkan tunnus: ";
			cin >> poistettava;
			poistaMatka(poistettava);
			break;
        case 6:
			cout << "Anna matkan tunnus: ";
			cin >> haettava;
			haeMatka(haettava);
			break;
        case 7:
			cout << "Anna asiakkaan tunnus: ";
			cin >> haettava;
			haePalvelut(haettava);
			break;
        case 8:
			cout << "Anna asiakkaan tunnus: ";
			cin >> haettava;
			haeAsiakkaanKuljettajat(haettava);
			break;
		case 9:
			break;
		default:
			cout << "Vaara valinta" << endl;
	
		}
	}while (choice != 9);

	return 0;
}

void naytaValikko()
{
	cout << "MENU" << endl;
	cout << "1: Etsi matkatoimisto " << endl;
	cout << "2: Etsi asiakas " << endl;
	cout << "3: Etsi kuljettaja " << endl;
	cout << "4: Lisaa matka " << endl;
    cout << "5: Poista matka " << endl;
    cout << "6: Etsi matka " << endl;
    cout << "7: Asiakkaan palvelujen tulostaminen " << endl;
    cout << "8: Asiakasta palvelleiden kuljettajien tulostaminen " << endl;
	cout << "9: Exit " << endl;
	cout << "Valintasi: ";
}

unsigned int lueMatkatoimistot()
{
    ifstream toimistot("agencies.txt");
    string temp_tunnus;
    string temp_nimi;
    string temp_pvm;
    string temp_lkm;
    string temp_johtaja;

    if (!toimistot) {
        cout << "Tiedoston agencies.txt avaaminen epäonnistui." << endl;
        return 1;
    }
    
    while (toimistot >> temp_tunnus >> temp_nimi >> temp_pvm >> temp_lkm >> temp_johtaja) {
        Matkatoimisto temp_matkatoimisto(temp_tunnus, temp_nimi, temp_pvm, temp_lkm, temp_johtaja);
        matkatoimistot.push_back(temp_matkatoimisto);
    }

    toimistot.close();
    return 0;
}

void lueAsiakkaat() 
{
	ifstream asiakastiedosto("customers.txt");
    string temp_tunnus;
    string temp_nimi;
    string temp_puhnro;
    string temp_osoite;

    if (!asiakastiedosto) {
        cout << "Tiedoston customers.txt avaaminen epäonnistui." << endl;
    }
    

    while (asiakastiedosto >> temp_tunnus >> temp_nimi >> temp_puhnro >> temp_osoite) {
        Asiakas temp_asiakas(temp_tunnus, temp_nimi, temp_puhnro, temp_osoite);
        asiakkaat.push_back(temp_asiakas);
    }

    asiakastiedosto.close();
}

void lueMatkat() 
{
	ifstream matkatiedosto("travels.txt");
    string temp_tunnus;
    string temp_kuljettaja;
    string temp_matkanAlkuPvm;
	string temp_matkanAlkuKello;
    string temp_asiakas;
    string temp_lahtoPaikka;
    string temp_paamaara;
	string temp_palkkio;

    if (!matkatiedosto) {
        cout << "Tiedoston travels.txt avaaminen epäonnistui." << endl;
    }

    while (matkatiedosto >> temp_tunnus >> temp_kuljettaja >> temp_matkanAlkuPvm >> temp_matkanAlkuKello >> temp_asiakas >> temp_lahtoPaikka >> temp_paamaara >> temp_palkkio) {
		Matka temp_matka(temp_tunnus, temp_kuljettaja, temp_matkanAlkuPvm, temp_matkanAlkuKello, temp_asiakas, temp_lahtoPaikka, temp_paamaara, temp_palkkio);
        matkat.push_back(temp_matka);
    }

    matkatiedosto.close();
}

void lueKuljettajat() 
{
	ifstream kuljettajatiedosto("drivers.txt");
    string temp_tunnus;
    string temp_toimistonTunnus;
    string temp_nimi;
	string temp_tyohontuloPvm;
    string temp_automalli;
	string rivi;

    if (!kuljettajatiedosto) {
        cout << "Tiedoston drivers.txt avaaminen epäonnistui." << endl;
    }

    while (getline(kuljettajatiedosto, rivi))
    {
        istringstream ss(rivi);

        ss >> temp_tunnus >> temp_toimistonTunnus >> temp_nimi >> temp_tyohontuloPvm; // >> temp_automalli;
		getline(ss, temp_automalli);
   		Kuljettaja temp_kuljettaja(temp_tunnus, temp_toimistonTunnus, temp_nimi, temp_tyohontuloPvm, temp_automalli);
        kuljettajat.push_back(temp_kuljettaja);
    }

    kuljettajatiedosto.close();
}

void haeMatkatoimisto(string haettava) {
	bool loytyy = false;
	for (int i = 0; i<matkatoimistot.size();i++)
	{
		if (matkatoimistot[i].haeNimi() == haettava) {
			matkatoimistot[i].tulostaTiedot();
			loytyy = true;
		} else if (matkatoimistot[i].haeTunnus() == haettava)
		{
			matkatoimistot[i].tulostaTiedot();
			loytyy = true;
		}
	}

	if (!loytyy) {
		cout << "Matkatoimistoa ei loydy. Yrita uudelleen." << endl;
	}
}

void haeAsiakas(string haettava) {
	bool loytyy = false;
	for (int i = 0; i<asiakkaat.size();i++)
	{
		if (asiakkaat[i].haeNimi() == haettava) {
			asiakkaat[i].tulostaTiedot();
			loytyy = true;
		} else if (asiakkaat[i].haeTunnus() == haettava)
		{
			asiakkaat[i].tulostaTiedot();
			loytyy = true;
		}
	}

	if (!loytyy) {
		cout << "Asiakasta ei loydy. Yrita uudelleen." << endl;
	}
}

void haeKuljettaja(string haettava) {
	bool loytyy = false;
	for (int i = 0; i<kuljettajat.size();i++)
	{
		if (kuljettajat[i].haeNimi() == haettava) {
			kuljettajat[i].tulostaTiedot();
			loytyy = true;
		} else if (kuljettajat[i].haeTunnus() == haettava)
		{
			kuljettajat[i].tulostaTiedot();
			loytyy = true;
		}
	}

	if (!loytyy) {
		cout << "KUljettajaa ei loydy. Yrita uudelleen." << endl;
	}	
}

void haeMatka(string haettava) {
	bool loytyy = false;
	for (int i = 0; i<matkat.size();i++)
	{
		if (matkat[i].haeTunnus() == haettava) {
			cout << "Matkan tiedot: " << endl;
			matkat[i].tulostaTiedot();
			loytyy = true;
		}
	}

	if (!loytyy) {
		cout << "Matkaa ei loydy. Yrita uudelleen." << endl;
	}
}

void lisaaMatka() {

	string temp_tunnus;
    string temp_kuljettaja;
    string temp_matkanAlkuPvm;
	string temp_matkanAlkuKello;
    string temp_asiakas;
    string temp_lahtoPaikka;
    string temp_paamaara;
	string temp_palkkio;

	cout << "Anna matkan tunnus: ";
	cin >> temp_tunnus;
	cout << "Anna kuljettajan tunnus: ";
	cin >> temp_kuljettaja;
	cout << "Anna matkan alku paivamaara: ";
	cin >> temp_matkanAlkuPvm;
	cout << "Anna matkan alku kelloaika: ";
	cin >> temp_matkanAlkuKello;
	cout << "Anna asiakkaan tunnus: ";
	cin >> temp_asiakas;
	cout << "Anna matkan lahtopaikka: ";
	cin >> temp_lahtoPaikka;
	cout << "Anna matkan paamaara: ";
	cin >> temp_paamaara;
	cout << "Anna matkan palkkio: ";
	cin >> temp_palkkio;

	Matka temp_matka(temp_tunnus, temp_kuljettaja, temp_matkanAlkuPvm, temp_matkanAlkuKello, temp_asiakas, temp_lahtoPaikka, temp_paamaara, temp_palkkio);
	matkat.push_back(temp_matka);

}

void poistaMatka(string poistettava) {
	bool loytyy = false;
	for (int i = 0; i<matkat.size();i++)
	{
		if (matkat[i].haeTunnus() == poistettava) {
 			matkat.erase(matkat.begin()+i);
			loytyy = true;
			cout << "Matka poistettu." << endl;
		}
	}

	if (!loytyy) {
		cout << "Matkaa ei loydy. Yrita uudelleen." << endl;
	}

}

void haePalvelut(string haettava) {

	bool loytyy = false;
	cout << "Asiakkaan matkat: " << endl;
	for (int i = 0; i<matkat.size();i++)
	{
		if (matkat[i].haeAsiakas() == haettava) {
			matkat[i].tulostaTiedot();
			loytyy = true;
		}
	}

	if (!loytyy) {
		cout << "Asiakkaalle ei loydy markoja. Yrita uudelleen." << endl;
	}

}

void haeAsiakkaanKuljettajat(string haettava) {
	string temp_kuljettaja;
	bool loytyy = false;
	for (int i = 0; i<matkat.size();i++)
	{
		if (matkat[i].haeAsiakas() == haettava) {
			temp_kuljettaja = matkat[i].haeKuljettaja();

			for (int j = 0; j<kuljettajat.size();j++){
				if (kuljettajat[j].haeTunnus() == temp_kuljettaja){
					kuljettajat[j].tulostaTiedot();
					loytyy = true;
				}
			}
		}
	}

	if (!loytyy) {
		cout << "Asiakkaalle ei loydy matkoja. Yrita uudelleen." << endl;
	}
}
