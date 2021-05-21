#pragma once
#include <iostream>
#include "Czlowiek.h"
#include <random>
class Policjant :public Czlowiek
{  
protected:
    int ktory_obiekt;
    bool drugie_zycie;
public:
    const int punkty_ataku = 30;
    const int pancerz = 15;
    const int punkty_obrony = 40;
    Policjant(int a = 300, bool b = 0, int x = 0, int y = 0, bool f = 1, int z = 0);
    int getX();
    int getY();
    void giveX(int p);
    void giveY(int p);
    void zmien_hp(int x);
    int sprawdz_hp();

    int atak(std::default_random_engine& rng) override;
    int obrona(std::default_random_engine& rng) override;
    int redukcja(std::default_random_engine& rng);
   
    friend class Mapa;
};

