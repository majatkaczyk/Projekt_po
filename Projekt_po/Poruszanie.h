#pragma once
#include <iostream>
#include "Mapa.h"
#include <vector>
#include <random>

class Poruszanie
{
public:
	void ruchy(Mapa& p, default_random_engine& rng);
};

