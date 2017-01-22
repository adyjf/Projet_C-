/*
Fichier : Scrutin.cc
Auteur : 
	ABBAR Yassine
	DRAY Paul-Alexis
	THAI Jean-François
Date : 22/01/17

contient les méthodes de la classe Scrutin et des classes héritées
*/

#include "Scrutin.hh"
#include "Simulateur.hh"
#include "Candidat.hh"

using namespace std;

/*--------------------------------------------------*/
Scrutin::Scrutin()
{}

Scrutin::Scrutin(Simulateur *sim):simulateur_(sim)
{}

Scrutin::~Scrutin()
{}

/*--------------------------------------------------*/
Scrutin_majoritaire::Scrutin_majoritaire(Simulateur *sim):Scrutin(sim)
{}

Scrutin_majoritaire::~Scrutin_majoritaire()
{}

/*--------------------------------------------------*/
Majorite_un_tour::Majorite_un_tour(Simulateur *sim):Scrutin_majoritaire(sim)
{}

Majorite_un_tour::~Majorite_un_tour()
{}

/*--------------------------------------------------*/
Majorite_deux_tour::Majorite_deux_tour(Simulateur *sim):Scrutin_majoritaire(sim)
{}

Majorite_deux_tour::~Majorite_deux_tour()
{}

/*--------------------------------------------------*/

/*
Fonction : majorité à un tour => le vainqueur_ est le Candidat ayant receuilli le plus de vote de rang 1
Paramètres :
Return :
*/
void Majorite_un_tour::decompte_voix()
{
	vector<Candidat> liste = (*simulateur_).get_liste_candidats_();
	vector<Candidat>::iterator it;
	vainqueur_ = *(liste.begin());
	for(it=liste.begin(); it!=liste.end(); ++it)
	{
		if((*it).get_nombre_voix_(1) > vainqueur_.get_nombre_voix_(1))
			vainqueur_ = (*it);
	}
}


/*
Fonction : affichage
Paramètres :
Return :
*/
void Majorite_un_tour::print_results()
{
	cout << "\t-----SCRUTIN MAJORITAIRE A UN TOUR-----"<< endl;
	cout << vainqueur_ << "\t" << (float)(vainqueur_.get_nombre_voix_(1))/NB_VOTANTS << "%" << endl;
}

/*--------------------------------------------------*/

/*
Fonction : donne les résultats du premier tour => les 2 Candidats ayant receuilli le plus vote accèdent au second tour
Paramètres :
Return :
*/
void Majorite_deux_tour::decompte_voix()
{
	vector<Candidat> liste = (*simulateur_).get_liste_candidats_();
	vector<int> result_1;
	vector<Candidat>::iterator it;
	for(it=liste.begin(); it!=liste.end(); ++it)
	{
		result_1.push_back((*it).get_nombre_voix_(1));
	}

	resultat_premier_tour_.push_back(liste[higher_rank(result_1)]);
	result_1.erase(result_1.begin()+higher_rank(result_1));
	resultat_premier_tour_.push_back(liste[higher_rank(result_1)]);
}

/*
Fonction : affichage
Paramètres :
Return :
*/
void Majorite_deux_tour::print_results()
{
	cout << "\t-----SCRUTIN MAJORITAIRE A DEUX TOUR-----"<< endl;
	vector<Candidat>::iterator it;
	cout << "RESULTAT PREMIER TOUR" << endl;
	for(it=resultat_premier_tour_.begin(); it!=resultat_premier_tour_.end(); ++it)
	{
		cout << (*it) << " " << (float)(*it).get_nombre_voix_(1)/NB_VOTANTS << "%" << endl;
	}
	cout << "\nRESULTAT SECOND TOUR" << endl;
	//cout << vainqueur_ << endl;
}

/*--------------------------------------------------*/

int higher_rank(vector<int> tab)
{
	int rank=0;
	for(int i=1; i<(int)tab.size(); i++)
	{
		if(tab[rank]<tab[i])
			rank = i;
	}
	return rank;
}

int lower_rank(vector<int> tab)
{
	int rank=0;
	for(int i=1; i<(int)tab.size(); i++)
	{
		if(tab[rank]>tab[i])
			rank = i;
	}
	return rank;
}

/*--------------------------------------------------*/
/*
Algorithme de triFusion fonctionnel 
nous voulions l'utiliser pour ordonner les candidats en fonction du nombre de voix obtenu.
*/
vector<int> triFusion(vector<int> tab)
{
	if(tab.size()<=1)
		return tab;
	else
	{	
		size_t const half = tab.size()/2;
		vector<int> split_hi(std::make_move_iterator(tab.begin()+half), std::make_move_iterator(tab.end()));
		tab.erase(tab.begin()+half, tab.end());
		return fusion(triFusion(tab), triFusion(split_hi));
	}
}

vector<int> fusion(vector<int> a, vector<int> b)
{
	if(a.empty())
		return b;
	if(b.empty())
		return a;
	if(a[0] <= b[0])
	{
		vector<int> split_hi(std::make_move_iterator(a.begin()+1),
	std::make_move_iterator(a.end()));
		a.erase(a.begin()+1, a.end());
		vector<int> fuse = fusion(split_hi, b);
		a.insert(a.end(), fuse.begin(), fuse.end());
		return a;
	}
	else
	{
		vector<int> split_hi(std::make_move_iterator(b.begin()+1),
	std::make_move_iterator(b.end()));
		b.erase(b.begin()+1, b.end());
		vector<int> fuse = fusion(a, split_hi);
		b.insert(b.end(), fuse.begin(), fuse.end());
		return b;
	}
}
