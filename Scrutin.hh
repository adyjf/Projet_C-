#pragma once
#include <iostream>
#include <cstdlib>

#include "Candidat.hh"

class Simulateur;
class Candidat;

class Scrutin
{
private:
	Simulateur *simulateur_;
	Candidat vainqueur_;

public:
	Scrutin();
	Scrutin(Simulateur *sim);
	~Scrutin();

	void decompte_voix();
	void print_results();
};

/*pour l'instant, majorité relative*/