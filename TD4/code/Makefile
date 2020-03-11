CFLAGS = -g -Wall -DDEBUG
LDLAGS = -g -Wall -DDEBUG
SOURCE = pointeur1.c pointeur2.c pointeur3.c pointeur1-bis.c produitScalaireSol.c
OBJECT = $(SOURCE:.c=.o)
# List a partir de la list des source en remplacant le .c par .o
TARGET = $(SOURCE:.c=)
# List a partir de la list des source en remplacant le .c par rien

.INTERMEDIATE: $(OBJECT) #pegagogic plugin: if not there, make will use its
			 #own implicit rules to compile the .c files
			 #instead of mine

all:  $(TARGET)



%: %.o	# % veut dire n'importe quoi # $< prend apres le : et $@ prend avant
	gcc  $< -o $@

%.o: %.c
	gcc $(TEST) -c $< -o $@


tar: 
	cd ..; tar cvf  TD4-code.tar code/pointeur*.c code/Makefile code/produitScalaireSol.c

clean: 
	\rm -rf *.o $(TARGET)  *~
