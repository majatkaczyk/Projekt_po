#include "Bandyta.h"
#include <iostream>
#include <random>
 int Bandyta::atak(std::default_random_engine& rng)  
 {
	 std::uniform_int_distribution<int> r(0, punkty_ataku);
	 return r(rng);
 }

int Bandyta::obrona(std::default_random_engine& rng)
{
	std::uniform_int_distribution<int> r(0, punkty_obrony);
	return r(rng);
}
bool Bandyta::unik(std::default_random_engine& rng)
{
	std::uniform_int_distribution<int> r(0,100);
	if (r(rng) < szansa_na_unik)
		return 1;   
	return 0;
	
}

Bandyta::Bandyta(int a, bool b, int x, int y, int f, int z)
	:Czlowiek(a, b, x, y)
{
	szansa_na_unik = f;
	ktory_obiekt = z;
}

int Bandyta::getX()
{
	return x;	
}
int Bandyta::getY()
{
	return y;
}
void Bandyta::giveX(int p)
{
	x = p;
}
void Bandyta::giveY(int p)
{
	y=p;
}
void Bandyta::zmien_hp(int x)
{
	punkty_zycia -= x;
	if (punkty_zycia < 0)
		punkty_zycia = 0;
}
int Bandyta::sprawdz_hp()
{ 
	return punkty_zycia;
}