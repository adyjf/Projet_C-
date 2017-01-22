/*
Fichier : Simulateur.cc
Auteur : 
	ABBAR Yassine
	DRAY Paul-Alexis
	THAI Jean-François
Date : 22/01/17

contient les méthodes de la classe Simulateur
*/

#include <string>
#include <fstream>
#include <sstream>
#include "Simulateur.hh"
#include "Candidat.hh"
#include "Votant.hh"
#include "Scrutin.hh"

using namespace std;

/*--------------------------------------------------*/
Simulateur::Simulateur(int n):nb_votants_(n), scrutin_1(this), scrutin_2(this)
{}

Simulateur::~Simulateur()
{}

/*--------------------------------------------------*/

/*
Fonction : initialise la liste des candidats et la liste des votants aléatoirement
Paramètres :
Return :
*/
void Simulateur::init_simulation()
{
	(*this).init_candidats();
	(*this).init_votants();
}

/*
Fonction : initialise la liste des votants aléatoirement
Paramètres :
Return :
*/
void Simulateur::init_votants()
{
	for(int i=0; i<NB_VOTANTS; i++)
	{
		Votant votant(this);
		votant.init();
		liste_votants_.push_back(votant);
	}
}

/*
Fonction : initialise la liste des candidats aléatoirement
Paramètres :
Return :
*/
void Simulateur::init_candidats()
{
	for(int i=0; i<NB_CANDIDATS; i++)
	{
		Candidat candidat(this);
		liste_candidats_.push_back(candidat);
	}
}

/*--------------------------------------------------*/

/*
Fonction : affiche les liste des votants
Paramètres :
Return :
*/
void Simulateur::print_liste_votants()
{
	vector<Votant>::iterator it;
	for(it=liste_votants_.begin(); it!=liste_votants_.end(); it++)
	{
		//(*it).voter();
		(*it).print_votant();
	}
}

/*
Fonction : affiche les liste des candidats
Paramètres :
Return :
*/
void Simulateur::print_liste_candidats()
{
	vector<Candidat>::iterator it;
	cout << "\t\t";
	for(int i=1; i<NB_CANDIDATS+1; i++)
		cout << i << "\t";
	cout << endl;
	for(it=liste_candidats_.begin(); it!=liste_candidats_.end(); it++)
	{
		(*it).compte_voix_init();
		(*it).print_candidat();
	}
}

/*--------------------------------------------------*/

/*
Fonction : lance le décompte des voix pour le scrutin majoritaire à un tour
Paramètres :
Return :
*/
void Simulateur::run_1()
{
	scrutin_1.decompte_voix();
	scrutin_1.print_results();
}

/*
Fonction : lance le décompte des voix pour le scrutin majoritaire à deux tours (incomplète)
Paramètres :
Return :
*/
void Simulateur::run_2()
{
	scrutin_2.decompte_voix();
	/*vector<Candidat> second_liste = scrutin_2.get_premier_tour_();
	vector<Votant>::iterator it;
	for(it=liste_votants_.begin(); it!=liste_votants_.end(); ++it)
	{

	}*/
	scrutin_2.print_results();
}
