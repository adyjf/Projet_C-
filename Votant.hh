/*
Fichier : Votant.hh
Auteur : 
	ABBAR Yassine
	DRAY Paul-Alexis
	THAI Jean-François
Date : 22/01/17

classe Votant
*/

#pragma once
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>


class Candidat;
class Simulateur;

class Votant
{
private:
	Simulateur *simulateur_;
	std::map<Candidat, int> bulletin_; //Candidat - rang

public:
	Votant(Simulateur *sim);
	~Votant();

	std::map<Candidat, int> get_bulletin_() {return bulletin_;}

	void init();
	void print_votant();
	void voter(int n, std::vector<Candidat> liste);
};

void ordre_aleatoire(int tab[], int n);

/*int bernoulli(float prob);*/
