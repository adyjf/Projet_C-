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
	cout << vainqueur_ << endl;
}
/*--------------------------------------------------*/
void Majorite_deux_tour::decompte_voix()
{
	vector<Candidat> liste = (*simulateur).get_liste_candidats_();
	
}


/*--------------------------------------------------*/
int higher_rank(vector<int> tab)
{
	int rank=0;
	for(int i=1; i<tab.size(); i++)
	{
		if(tab[rank]<tab[i])
			rank = i;
	}
	return rank;
}

int lower_rank(vector<int> tab)
{
	int rank=0;
	for(int i=1; i<tab.size(); i++)
	{
		if(tab[rank]>tab[i])
			rank = i;
	}
	return rank;
}