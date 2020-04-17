INCLUDES=graphe_adj_type.h  graphe_liste_type.h   util_adj.h \
         graphe.h   graphe_poids_type.h  util_poids.h
CFLAGS=-Wall -g

all: main

main: main.o util_adj.o graphe.o util_poids.o
	gcc main.o util_adj.o util_poids.o graphe.o -o main

main_sol: main_sol.o util_adj.o graphe_sol.o util_poids.o graphe_liste.o
	gcc main_sol.o util_adj.o util_poids.o graphe_liste.o graphe_sol.o -o main_sol

main_flot: main_flot.o util_flot.o graphe_flot.o
	gcc ${CFLAGS} main_flot.o util_flot.o graphe_flot.o -o main_flot

%.o: %.c $(INCLUDES)
	gcc ${CFLAGS} $< -c -o $@

clean:
	\rm -rf *.o main main_sol *~ test_*.dot

tarSol : clean
	cd ..; tar cvf TDGraphe-sol.tar  code/*

tar : clean
	cd ..; tar cvf TDGraphe.tar --exclude main_sol.c --exclude graphe_flot.c --exclude main_flot.c --exclude graphe_sol.c --exclude graphe_liste.c code/*
