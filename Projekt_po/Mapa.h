#pragma once
#include <iostream>
#include <vector>
#include "Bandyta.h" 
#include "Policjant.h"
#include "Przechodzien.h"
#include "Walka.h"
#include <random>
using namespace std;      
class Mapa
{  
	vector<unique_ptr<Bandyta>> b;
	vector<unique_ptr<Policjant>> po;
	vector<unique_ptr<Przechodzien>> pr;
	int liczba_b, liczba_po, liczba_pr;
 public:
	const int rozmiar_mapy=500;
	Mapa(int x = 0, int y = 0, int z = 0);

	void dodaj_bandyte();
	void dodaj_policjanta();
	void dodaj_przechodnia();
	void usun_bandyte(int miejsce);
	void usun_policjanta(int miejsce);
	void usun_przechodnia(int miejsce);
	int sprawdz_wynik();
	void porownaj_polozenie(default_random_engine &rng);
	friend class Poruszanie;
	friend class Walka;

};

