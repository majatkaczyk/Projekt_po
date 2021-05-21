#pragma once
#include <iostream>
#include "Czlowiek.h"
#include <random>
class Bandyta :public Czlowiek
{  
protected:
    int szansa_na_unik; 
    int ktory_obiekt;
public:
    const int punkty_ataku = 30;
    const int punkty_obrony = 40;
    Bandyta(int a = 300, bool b = 1, int x = 0, int y = 0, int f = 40, int z = 0);
    int getX();
    int getY();
    void giveX( int p);
    void giveY( int p);
    void zmien_hp(int x);
    int sprawdz_hp();
   
    int atak(std::default_random_engine& rng) override ;
    int obrona(std::default_random_engine& rng) override;
    bool unik(std::default_random_engine& rng);
    friend class Mapa;
};

