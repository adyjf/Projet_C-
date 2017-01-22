#pragma once
#include <iostream>
#include <cstdlib>
#include <map>


class Candidat;
class Simulateur;

class Votant
{
private:
	Simulateur *simulateur_;
	std::map<Candidat, int> bulletin_;

public:
	Votant(Simulateur *sim);
	~Votant();

	std::map<Candidat, int> get_bulletin_() {return bulletin_;}

	void init();
	void print_votant();
	void voter();
};

void ordre_aleatoire(int tab[], int n);

/*int bernoulli(float prob);*/