#pragma once
#include <iostream>
#include <cstdlib>
#include <>

#include "Candidat.hh"

class Simulateur;
class Candidat;

class Scrutin
{
protected:
	Simulateur *simulateur_;
	Candidat vainqueur_;

public:
	Scrutin();
	Scrutin(Simulateur *sim);
	~Scrutin();

	virtual void decompte_voix()=0;
	virtual void print_results()=0;
};

class Scrutin_majoritaire : public Scrutin
{
protected:
	Scrutin_majoritaire(Simulateur *sim);
	~Scrutin_majoritaire();
public:
	virtual void decompte_voix()=0;
	virtual void print_results()=0;
};

class Majorite_un_tour : public Scrutin_majoritaire
{
protected:
public:
	Majorite_un_tour(Simulateur *sim);
	~Majorite_un_tour();

	void decompte_voix();
	void print_results();
};

class Majorite_deux_tour : public Scrutin_majoritaire
{
protected:
	std::vector<Candidat> resultat_premier_tour_;
public:
	Majorite_deux_tour(Simulateur *sim);
	~Majorite_deux_tour();

	void decompte_voix();
	void print_results();
};

int higher_rank(vector<int> tab);

int lower_rank(vector<int> tab);