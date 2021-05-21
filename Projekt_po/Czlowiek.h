#include <iostream>
#include <random>
#pragma once
class Czlowiek
{
protected:
	int punkty_zycia;
	bool wrogosc;
	int x, y;
public:
	Czlowiek( int a = 50, bool b = 0, int x = 0,  int y = 0) 
	{
		punkty_zycia = a;
		wrogosc = b;
		this->x = x;
		this->y = y;
	}
	virtual ~Czlowiek() {}
	virtual int atak(std::default_random_engine &rng) = 0 ;
	virtual int obrona(std::default_random_engine& rng) = 0;
};

