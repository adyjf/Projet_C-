#include "Votant.hh"
#include "Simulateur.hh"
#include "Candidat.hh"

using namespace std;

Votant::Votant(Simulateur *sim):simulateur_(sim)
{}

Votant::~Votant()
{}

/*initialise aléatoirement un bulletin_ pour votant*/
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

/*affiche bulletin de votant*/
void Votant::print_votant()
{
	map<Candidat, int>::iterator it;
	for(it=bulletin_.begin(); it!=bulletin_.end(); ++it)
	{
		cout << "Candidat_" << (it->first).get_num_() << " " << it->second << "\t";
	}
	cout << endl;
}

void Votant::voter()
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

/*génère ordre aléatoire pour le bulletin_*/
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