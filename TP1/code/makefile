all: bin/hanoi

obj/hanoi.o: src/hanoi.c include/hanoi.h include/pile.h include/pile_type.h
	gcc -Iinclude -o obj/hanoi.o -c src/hanoi.c
obj/pile.o: src/pile.c include/pile.h include/pile_type.h
	gcc -Iinclude -o obj/pile.o -c src/pile.c
obj/main.o: src/main.c include/pile.h include/hanoi.h include/pile_type.h
	gcc -Iinclude -o obj/main.o -c src/main.c

bin/hanoi: obj/main.o obj/pile.o obj/hanoi.o
	gcc -o bin/hanoi obj/main.o obj/pile.o obj/hanoi.o

clean:
	rm -f obj/*.o