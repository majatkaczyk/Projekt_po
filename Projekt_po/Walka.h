#pragma once
#include <iostream>
#include "Mapa.h"
#include <random>
#include <cmath> 
	class Walka
{
public:
	static int Walcz(std::unique_ptr<Bandyta>& a, std::unique_ptr<Policjant>& b, std::default_random_engine& rng);
	static int Walcz(std::unique_ptr<Bandyta>& a, std::unique_ptr<Przechodzien>& b, std::default_random_engine& rng);
	friend class Mapa;
};

