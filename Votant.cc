/*
Fichier : Votant.cc
Auteur : 
	ABBAR Yassine
	DRAY Paul-Alexis
	THAI Jean-François
Date : 22/01/17

contient les méthodes de la classe Votant
*/

#include "Votant.hh"
#include "Simulateur.hh"
#include "Candidat.hh"

using namespace std;

/*--------------------------------------------------*/
Votant::Votant(Simulateur *sim):simulateur_(sim)
{}

Votant::~Votant()
{}

/*--------------------------------------------------*/

/*
Fonction : initialise alétoirement un bulletin_ pour Votant au début du programme
Paramètres :
Return :
*/
void Votant::init()
{
	int tab[NB_CANDIDATS];
	ordre_aleatoire(tab, NB_CANDIDATS);
	int i=0;
	vector<Candidat> liste = (*simulateur_).get_liste_candidats_();
	vector<Candidat>::iterator it;
	for(it=liste.begin(); it!=liste.end(); ++it)
	{
		bulletin_[(*it)] = tab[i];
		i++;
	}
}

/*
Fonction : affiche bulletin_
Paramètres :
Return :
*/
void Votant::print_votant()
{
	map<Candidat, int>::iterator it;
	for(it=bulletin_.begin(); it!=bulletin_.end(); ++it)
	{
		cout << "Candidat_" << (it->first).get_num_() << " " << it->second << "\t";
	}
	cout << endl;
}

/*
Fonction : incomplète
Paramètres :
Return :
*/
void Votant::voter(int n, vector<Candidat> liste)
{
	int tab[n];
	ordre_aleatoire(tab, n);
	int i=0;
	//vector<Candidat> liste = (*simulateur_).get_liste_candidats_();
	vector<Candidat>::iterator it;
	for(it=liste.begin(); it!=liste.end(); ++it)
	{
		bulletin_[(*it)] = tab[i];
		i++;
	}
}

/*--------------------------------------------------*/

/*
Fonction : génère un ordre alétoire
Paramètres :
Return :
*/
void ordre_aleatoire(int tab[], int n)
{
	for(int i=0; i<n; i++)
	{
		int val=rand()%NB_CANDIDATS + 1;
		bool b=true;
		if(i==0)
			tab[i] = val;
		else
		{
			for(int j=0; j<i; j++)
			{
				if(tab[j]==val)
					b=false;
			}
			if(b)
				tab[i]=val;
			else
				i--;
		}
	}
}

/*int bernoulli(float prob)
{
	random_device rd;
	mt19937 gen(rd());
	bernoulli_distribution d(prob);

	return d(gen);
}*/
