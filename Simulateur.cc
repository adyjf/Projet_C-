#include <string>
#include <fstream>
#include <sstream>
#include "Simulateur.hh"
#include "Candidat.hh"
#include "Votant.hh"
#include "Scrutin.hh"

using namespace std;

Simulateur::Simulateur(int n):nb_votants_(n), scrutin_(this)
{}

Simulateur::~Simulateur()
{}

/*--------------------------------------------------*/

/*genère NB_VOTANTS votants aléatoirement + liste des partis*/
void Simulateur::init_simulation()
{
	(*this).init_candidats();
	(*this).init_votants();
}

void Simulateur::init_votants()
{
	for(int i=0; i<NB_VOTANTS; i++)
	{
		Votant votant(this);
		votant.init();
		liste_votants_.push_back(votant);
	}
}

void Simulateur::init_candidats()
{
	for(int i=0; i<NB_CANDIDATS; i++)
	{
		Candidat candidat(this);
		liste_candidats_.push_back(candidat);
	}
}
/*--------------------------------------------------*/

/*affiche la liste des votants*/
void Simulateur::print_liste_votants()
{
	vector<Votant>::iterator it;
	for(it=liste_votants_.begin(); it!=liste_votants_.end(); it++)
	{
		//(*it).voter();
		(*it).print_votant();
	}
}

void Simulateur::print_liste_candidats()
{
	vector<Candidat>::iterator it;
	cout << "\t\t";
	for(int i=1; i<NB_CANDIDATS+1; i++)
		cout << i << "\t";
	cout << endl;
	for(it=liste_candidats_.begin(); it!=liste_candidats_.end(); it++)
	{
		//(*it).voter();
		(*it).compte_voix_init();
		(*it).print_candidat();
	}
}

/*--------------------------------------------------*/

void Simulateur::run()
{
	scrutin_.decompte_voix();
	scrutin_.print_results();
}
