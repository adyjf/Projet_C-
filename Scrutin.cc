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

void Scrutin::decompte_voix()
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

void Scrutin::print_results()
{
	cout << vainqueur_ << endl;
}