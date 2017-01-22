#include "Scrutin.hh"
#include "Simulateur.hh"
#include "Candidat.hh"

using namespace std;

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

void Majorite_un_tour::print_results()
{
	cout << "\t-----SCRUTIN MAJORITAIRE A UN TOUR-----"<< endl;
	cout << vainqueur_ << "\t" << (float)(vainqueur_.get_nombre_voix_(1))/NB_VOTANTS << "%" << endl;
}
/*--------------------------------------------------*/
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

