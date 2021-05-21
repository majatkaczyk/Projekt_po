#include "Poruszanie.h"
#include "Mapa.h"
#include <vector>
#include <random>

void Poruszanie::ruchy(Mapa& p, default_random_engine& rng)
{
	uniform_int_distribution<int> r(-1, 1);
	uniform_int_distribution<int> ra(0, 1);
	uniform_int_distribution<int> rmax(-1, 0);
	int a;
	for (int i = 0; i < p.liczba_b; i++)
	{
		a = (*(p.b[i])).getX();
		if ((a < p.rozmiar_mapy) && (a > 0))
		{
			a += r(rng);
			(*(p.b[i])).giveX(a);
		}
		else if (a == 0)
		{
			a += ra(rng);
			(*(p.b[i])).giveX(a);
		}
		else
		{
			a += rmax(rng);
			(*(p.b[i])).giveX(a);
		}

		a = (*(p.b[i])).getY();

		if ((a < p.rozmiar_mapy) && (a > 0))
		{
			a += r(rng);
			(*(p.b[i])).giveY(a);
		}
		else if (a == 0)
		{
			a += ra(rng);
			(*(p.b[i])).giveY(a);
		}
		else
		{
			a += rmax(rng);
			(*(p.b[i])).giveY(a);
		}
	}

	for (int i = 0; i < p.liczba_po; i++)
	{

		a = (*(p.po[i])).getX();
		if ((a < p.rozmiar_mapy) && (a > 0))
		{
			a += r(rng);
			(*(p.po[i])).giveX(a);
		}
		else if (a == 0)
		{
			a += ra(rng);
			(*(p.po[i])).giveX(a);
		}
		else
		{
			a += rmax(rng);
			(*(p.po[i])).giveX(a);
		}
		a = (*(p.po[i])).getY();
		if ((a < p.rozmiar_mapy) && (a > 0))
		{
			a += r(rng);
			(*(p.po[i])).giveY(a);
		}
		else if (a == 0)
		{
			a += ra(rng);
			(*(p.po[i])).giveY(a);
		}
		else
		{
			a += rmax(rng);
			(*(p.po[i])).giveY(a);
		}
	}

	for (int i = 0; i < p.liczba_pr; i++)
	{

		a = (*(p.pr[i])).getX();
		if ((a < p.rozmiar_mapy) && (a > 0))
		{
			a += r(rng);
			(*(p.pr[i])).giveX(a);
		}
		else if (a == 0)
		{
			a += ra(rng);
			(*(p.pr[i])).giveX(a);
		}
		else
		{
			a += rmax(rng);
			(*(p.pr[i])).giveX(a);
		}
		a = (*(p.pr[i])).getY();
		if ((a < p.rozmiar_mapy) && (a > 0))
		{
			a += r(rng);
			(*(p.pr[i])).giveY(a);
		}
		else if (a == 0)
		{
			a += ra(rng);
			(*(p.pr[i])).giveY(a);
		}
		else
		{
			a += rmax(rng);
			(*(p.pr[i])).giveY(a);
		}
	}
}