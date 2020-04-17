#include "graphe_adj_type.h"
#include "graphe_poids_type.h"
#include "util_adj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (((a)<(b))?(a):(b))


int sameMat(GRAPHE g1, GRAPHE g2){
	for(int i = 0; i < g1.nb_sommets; i++){
		for(int j = 0; j < g1.nb_sommets; j++){
			if(g1.adj[i][j] != g2.adj[i][j]){
				return (0);
			}
		}
	}
	return (1);
}

GRAPHE copy(GRAPHE g){
	GRAPHE h = init_adj_mat(g.nb_sommets);
	for(int i = 0; i < g.nb_sommets; i++){
		for(int j = 0; j < g.nb_sommets; j++){
			h.adj[i][j] = g.adj[i][j];
		}
	}
	return (h);
}


GRAPHE fermeture_transistive(GRAPHE g){

	int N = g.nb_sommets;
	GRAPHE m = copy(g);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(g.adj[i][j] == 1){
				for(int k = 0; k < N; k++){
					if(g.adj[j][k] == 1) {
						m.adj[i][k] = 1;
					}
				}
			}
		}
	}

	if(sameMat(g, m) == 1){
		return m;
	}

	return fermeture_transistive(m);

}

int *dijkstra(GRAPHE_POIDS g,int source) {

	int infini = 100000;
	int *d = malloc(g.nb_sommets);
	int all_marque = 0;
	int index = (source - 1);

	// Init

	for (int n = 0; n < g.nb_sommets; n++) {
		d[n] = infini;
	}
	d[index] = 0;

	g.marque[index] = 1; //marquage de la source

	// parcour
	while (all_marque == 0) {

		//on cherche le min
		for(int i = 0; i < g.nb_sommets; i++) {
			if (g.marque[i] == 0) {
				for (int j = 0; j < g.nb_sommets; j++) {
					if (g.adj[j][i] == 1) {
						d[i] = MIN(d[i], MIN(d[i], (d[j] + g.poids[j][i])));
					}
				}
				g.marque[i] = 1;
			}

		}

		//on test si tous les sommets ont ete parcouru
		all_marque = 1;
		for (int i = 0; i < g.nb_sommets; i++) {
			if (g.marque[i] == 0) {
				all_marque = 0;
			}
		}
	}

	return d;
}