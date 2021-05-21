#include "Przechodzien.h"
#include <iostream>
#include <random>
int Przechodzien::atak(std::default_random_engine& rng)  
{
	std::uniform_int_distribution<int> r(0, punkty_ataku);
	return r(rng);
}

int Przechodzien::obrona(std::default_random_engine& rng)
{
	std::uniform_int_distribution<int> r(0, punkty_obrony);
	return r(rng);

}
Przechodzien::Przechodzien(int a, bool b, int x, int y, int z)
	:Czlowiek(a, b, x, y)
{
	ktory_obiekt = z;
}

 int Przechodzien::getX()
{
	return x;
}
 int Przechodzien::getY()
{
	return y;
}
void Przechodzien::giveX(int p)
{
	x = p;
}
void Przechodzien::giveY(int p)
{
	y = p;
}
void Przechodzien::zmien_hp(int x)
{
	punkty_zycia -= x;
	if (punkty_zycia < 0)
		punkty_zycia = 0;
}
int Przechodzien::sprawdz_hp()
{
	return punkty_zycia;
}

