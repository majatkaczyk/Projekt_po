#include "Policjant.h"
#include <iostream>
#include <random>
int Policjant::atak(std::default_random_engine& rng) 
{
	std::uniform_int_distribution<int> r(0, punkty_ataku);
	return r(rng);
}

int Policjant::obrona(std::default_random_engine& rng)
 {
	std::uniform_int_distribution<int> r(0, punkty_obrony);
	return r(rng);

 }
int Policjant::redukcja(std::default_random_engine& rng)
{
	std::uniform_int_distribution<int> r(0, pancerz);
	return r(rng);
}
Policjant::Policjant(int a, bool b, int x, int y, bool f, int z)
	:Czlowiek(a, b, x, y)
{
	drugie_zycie = f;
	ktory_obiekt = z;
}

 int Policjant::getX()
 {
	 return x;
 }
  int Policjant::getY()
 {
	 return y;
 }
 void Policjant::giveX(int p)
 {
	 x = p;
 }
 void Policjant::giveY(int p)
 {
	 y = p;
 }
 void Policjant::zmien_hp(int x)
 {
	 punkty_zycia -= x;
	 if (punkty_zycia < 0)
		 punkty_zycia = 0;
 }
 int Policjant::sprawdz_hp()
 {
	 return punkty_zycia;
 }