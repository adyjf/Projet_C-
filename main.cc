/*
Fichier : main.cc
Auteur : 
	ABBAR Yassine
	DRAY Paul-Alexis
	THAI Jean-François
Date : 22/01/17

progrmme test
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Simulateur.hh"

using namespace std;

int main()
{
	srand(time(NULL));
	float temps;
	clock_t t1, t2;

	t1 = clock();

	Simulateur simulation(NB_VOTANTS);
	simulation.init_simulation();
	//simulation.print_liste_votants();
	simulation.print_liste_candidats();

	cout << endl;

	simulation.run_1();
	simulation.run_2();
	
	t2 = clock();
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	cout << "Temps d'éxécution : " << temps << " sec" << endl;
	return 0;
}
