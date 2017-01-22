#include "Candidat.hh"
#include "Simulateur.hh"

using namespace std;

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

/*affiche candidat*/
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

/*compte les bulletins_ au début de la simulation*/
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

/*nécessaire pour map<Candidat, int> : comparateur numéro*/
bool Candidat::operator<(const Candidat& autre) const
{
	if((*this).get_num_()<autre.get_num_())
		return true;
	else return false;
}

Candidat& Candidat::operator=(const Candidat& c)
{	
	simulateur_ = c.simulateur_;
	numero_ = c.numero_;
	nombre_voix_ = c.nombre_voix_;
	return (*this);
}

ostream& operator<<(ostream& os, const Candidat& c)
{
	os << "Candidat " << c.numero_ +1<< endl;
	return os;
}