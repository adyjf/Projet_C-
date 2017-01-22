/*
Fichier : Candidat.cc
Auteur : 
	ABBAR Yassine
	DRAY Paul-Alexis
	THAI Jean-François
Date : 22/01/17

contient les méthodes de la classe Candidat
*/

#include "Candidat.hh"
#include "Simulateur.hh"

using namespace std;

/*--------------------------------------------------*/
int Candidat::nb_=0;

Candidat::Candidat()
{}

Candidat::Candidat(Simulateur *sim):simulateur_(sim),numero_(nb_)
{
	nb_++;
}

Candidat::~Candidat()
{}

/*--------------------------------------------------*/

/*
Fonction : affiche le nombre de voix recueilli par le candidat
Paramètres :
Return :
*/
void Candidat::print_candidat()
{
	map<int, int>::iterator it;
	cout << "Candidat " << this->get_num_() +1 << " :\t";
	for(it=nombre_voix_.begin(); it!=nombre_voix_.end(); ++it)
	{
		cout << it->second << "\t";
	}
	cout << endl;
}

/*
Fonction : compte les bulletins_ des Votants à l'initialisation
Paramètres :
Return :
*/
void Candidat::compte_voix_init()
{
	vector<Votant>* liste_p = (*simulateur_).get_liste_votants_();
	vector<Votant>::iterator it_liste;
	for(it_liste=liste_p->begin(); it_liste!=liste_p->end(); ++it_liste)
	{
		map<Candidat, int> bulletin_p = (*it_liste).get_bulletin_();
		map<Candidat, int>::iterator it_bulletin;
		for(it_bulletin=bulletin_p.begin(); it_bulletin!=bulletin_p.end(); ++it_bulletin)
		{
			if(((*it_bulletin).first).get_num_() == this->get_num_())
				++nombre_voix_[(*it_bulletin).second];
		}
	}
}

/*--------------------------------------------------*/

/*
Fonction : comparateur Candidat selon numero_. Opérateur nécessaire pour l'utilisation de map<Candidat, int> dans la classe Votant
Paramètres : Candidat& autre
Return : true si numero_<autre.numero_
	false sinon
*/
bool Candidat::operator<(const Candidat& autre) const
{
	if((*this).get_num_()<autre.get_num_())
		return true;
	else return false;
}

/*
Fonction : opérateur= pour initiliser un Candidat à partir d'un autre
Paramètres :
Return :
*/
Candidat& Candidat::operator=(const Candidat& c)
{	
	simulateur_ = c.simulateur_;
	numero_ = c.numero_;
	nombre_voix_ = c.nombre_voix_;
	return (*this);
}

/*
Fonction : opérateur<< flux de sortie pour l'affichage de Candidat
Paramètres :
Return :
*/
ostream& operator<<(ostream& os, const Candidat& c)
{
	os << "Candidat " << c.numero_ +1;
	return os;
}
