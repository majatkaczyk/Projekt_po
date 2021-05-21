#include "Mapa.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

using namespace std;
Mapa::Mapa(int x, int y, int z)
{
	liczba_b = x;
	liczba_po = y;
	liczba_pr = z;
}
void Mapa::dodaj_bandyte() 
{
	b.push_back(make_unique<Bandyta>());
	liczba_b++;
	(*b[liczba_b - 1]).ktory_obiekt = liczba_b;
}
void Mapa::dodaj_policjanta() 
{
	po.push_back(make_unique<Policjant>());
	liczba_po++;
	(*po[liczba_po - 1]).ktory_obiekt = liczba_po;
}
void Mapa::dodaj_przechodnia() 
{
	pr.push_back(make_unique<Przechodzien>());
	liczba_pr++;
	(*pr[liczba_pr - 1]).ktory_obiekt = liczba_pr;
}
void Mapa::usun_bandyte(int miejsce) 
{
	liczba_b--;
	if (miejsce != liczba_b)
	{
		swap(b[miejsce], b[liczba_b]);
		b[liczba_b] = nullptr;
		(*b[miejsce]).ktory_obiekt = miejsce +1;
	}
	b.pop_back();
}
void Mapa::usun_policjanta(int miejsce) 
{
	liczba_po--;
	if (miejsce != liczba_po)
	{
		swap(po[miejsce], po[liczba_po]);
		po[liczba_po] = nullptr;
		(*po[miejsce]).ktory_obiekt = miejsce +1;
	}
	po.pop_back();
}
void Mapa::usun_przechodnia(int miejsce) 
{
	liczba_pr--;
	if (miejsce != liczba_pr)
	{
		swap(pr[miejsce], pr[liczba_pr]);
		pr[liczba_pr] = nullptr;
		(*pr[miejsce]).ktory_obiekt = miejsce+1;
	}
	pr.pop_back();
}

int Mapa::sprawdz_wynik()
{
	if (liczba_b == 0)
	{
		cout << "Wygrali cywile";
		return 1;
	}
	if (liczba_po == 0 && liczba_pr == 0)	
	{
		cout << "Wygrali bandyci";
		return 2;
	}
	return 0;
}

void Mapa::porownaj_polozenie(default_random_engine &rng)
{
	for (int i = liczba_b; i > 0; i--)
	{
		for (int j = liczba_po; j > 0; j--)
		{
			
			if ((*(b[i - 1])).x == (*(po[j - 1])).x)
			{
				if ((*(b[i - 1])).y == (*(po[j - 1])).y)
				{

					if (Walka::Walcz(b[i - 1], po[j - 1],rng))
					{
						usun_bandyte(i - 1);
						cout << "Bandyta polegl" << endl;
						break;

					}
					else
					{
						usun_policjanta(j - 1);
						cout << "Policjanta polegl" << endl;
					}
				}
			}
		}
	}
    for (int i = liczba_b; i > 0; i--)
	{
		for (int j = liczba_pr; j > 0; j--)
		{
			if ((*(b[i - 1])).x == (*(pr[j - 1])).x)
			{	
				if ((*(b[i - 1])).y == (*(pr[j - 1])).y)
				{
					if (Walka::Walcz(b[i - 1], pr[j - 1], rng))
					{
						usun_bandyte(i - 1);
						cout << "Bandyta polegl" << endl;
						break;
					}
					else
					{
						usun_przechodnia(j - 1);
						cout << "Przechodzien polegl" << endl;
					}
				}
			}
		}
	} 
}
