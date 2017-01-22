#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>

#include "Candidat.hh"
#include "Votant.hh"
#include "Scrutin.hh"

#define NB_CANDIDATS 4
#define NB_VOTANTS 1000

class Candidat;
class Votant;
class Scrutin;

class Simulateur
{
private:
	int nb_votants_;
	std::vector<Candidat> liste_candidats_;
	std::vector<Votant> liste_votants_;
	Majorite_un_tour scrutin_1;
	Majorite_deux_tour scrutin_2;

public:
	Simulateur(int n);
	~Simulateur();

	std::vector<Candidat> get_liste_candidats_() const {return liste_candidats_;}
	std::vector<Votant>* get_liste_votants_() {return &liste_votants_;}

	void init_simulation();
	void init_votants();
	void init_candidats();
	void print_liste_votants();
	void print_liste_candidats();

	void run_1();
	void run_2();
};


