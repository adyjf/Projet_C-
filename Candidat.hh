/*
Fichier : Candidat.hh
Auteur : 
	ABBAR Yassine
	DRAY Paul-Alexis
	THAI Jean-François
Date : 22/01/17

classe Candidat
*/

#pragma once
#include <iostream>
#include <cstdlib>
#include <map>

class Simulateur;

class Candidat
{
private:
	static int nb_;
	Simulateur *simulateur_;
	int numero_;
	std::map<int, int> nombre_voix_; //rang - nombre de voix

public:
	Candidat();
	Candidat(Simulateur *sim);
	~Candidat();

	int get_num_() const {return numero_;}
	std::map<int, int>* get_nombre_voix_() {return &nombre_voix_;}
	int get_nombre_voix_(int rank) {return nombre_voix_[rank];}

	void print_candidat();
	void compte_voix_init();

	bool operator<(const Candidat& autre) const;
	Candidat& operator=(const Candidat& c);
	friend std::ostream& operator<<(std::ostream& os, const Candidat& c);
};
