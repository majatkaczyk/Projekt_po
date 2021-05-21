#include "Walka.h"
#include <iostream>
#include "Mapa.h"
#include <random>
#include <cmath> 
int Walka::Walcz(std::unique_ptr<Bandyta>& a, std::unique_ptr<Policjant>& b, std::default_random_engine& rng)
{
	Czlowiek* wskb;
	Czlowiek* wskpo;


	for (;;)
	{
		int x;
		wskb = &(*a);
		wskpo = &(*b);
		x = (round((wskb->atak(rng)) * ((100.0 - (wskpo->obrona(rng))) / 100) - (*b).redukcja(rng)));
		if (x < 0) x = 0;
			(*b).zmien_hp(x);

		if ((*b).sprawdz_hp() == 0)
			return 0;

		if ((*a).unik(rng))
			{ }
		else
		{
			x = (round((wskpo->atak(rng)) * ((100.0 - wskb->obrona(rng))) / 100));

			(*a).zmien_hp(x);
			if ((*a).sprawdz_hp() == 0)
				return 1;
		}	


	}
}
int Walka::Walcz(std::unique_ptr<Bandyta>& a, std::unique_ptr<Przechodzien>& b, std::default_random_engine& rng)
{
	Czlowiek* wskb;
	Czlowiek* wskpr;


	for (;;)
	{
		int x;
		wskb = &(*a);
		wskpr = &(*b);
		x = (round((wskb->atak(rng)) * ((100.0 - (wskpr->obrona(rng))) / 100)));

		(*b).zmien_hp(x);
		if ((*b).sprawdz_hp() == 0)
			return 0;


		x = (round((wskpr->atak(rng)) * ((100.0 - wskb->obrona(rng))) / 100));

		(*a).zmien_hp(x);
		if ((*a).sprawdz_hp() == 0)
			return 1;
	}
}

