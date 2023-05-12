#include <stdio.h>

const char sym_Joueur1 = 'X';
const char sym_Joueur2 = 'O';

void affichage_interface(char tabdouble[3][3])
{
	printf(" %c | %c | %c \n", tabdouble[0][0], tabdouble[0][1], tabdouble[0][2]);
	printf("--------\n");
	printf(" %c | %c | %c \n", tabdouble[1][0], tabdouble[1][1], tabdouble[1][2]);
	printf("--------\n");
	printf(" %c | %c | %c \n", tabdouble[2][0], tabdouble[2][1], tabdouble[2][2]);
}

void choix_case(char tabdouble[3][3], int tour)
{
	int x = 0, y = 0;
	
	do
	{
		//Choix de la case
		printf("Veuillez choisir un numéro de ligne puis de colonne\nLigne : ");
		scanf("%d", &x);
		printf("Colonne :");
		scanf("%d", &y);

		if(tabdouble[x-1][y-1] != 0)
			printf("Cette case est déjà prise !\n");

	}while(tabdouble[x-1][y-1] != 0);

	//Incrémentation du bon symbole selon le tour
	if(tour%2 == 0)
		tabdouble[x-1][y-1] = sym_Joueur2;
	else
		tabdouble[x-1][y-1] = sym_Joueur1;
}

void conditionVictoire(char tabdouble[3][3], int tour, int *finPartie)
{
	int x = 0, y = 0;

	//Vérification victoire dans les lignes
	for(y = 0; y < 3; y++)
	{
		if(tabdouble[0][y] != 0 && tabdouble[0][y] == tabdouble[1][y] && tabdouble[1][y] == tabdouble[2][y])
			*finPartie = 0;
	}
	y = 0;

	//Vérificatoin de victoire dans les colonnes
	for(x = 0; x < 3; x++)
	{
		if(tabdouble[x][0] != 0 && tabdouble[x][0] == tabdouble[x][1] && tabdouble[x][1] == tabdouble[x][2])
			*finPartie = 0;
	}
	x = 0;

	//Vérification de victoire dans les diagonales
	if(tabdouble[0][0] != 0 && tabdouble[0][0] == tabdouble[1][1] && tabdouble[1][1] == tabdouble[2][2] || tabdouble[2][0] != 0 && tabdouble[2][0] == tabdouble[1][1] && tabdouble[1][1] == tabdouble[0][2])
		*finPartie = 0;

	if(tour == 9)
		*finPartie = 0;
}

void reset(char tabdouble[3][3], int *tour, int *finJeu)
{
	int awnser = 0, fin = 1;
	printf("Voulez vous recommencer une partie ?\nOui................................0\nNon................................1\n");
	scanf("%d", &awnser);
	if(awnser == 1)
		*finJeu = 0;
	else
	{
		*tour = 1;
		for(int x = 0; x < 3; x++)
		{
			for(int y = 0; y < 3; y++)
			{
				tabdouble[x][y] = 0;
			}
		}
	}
}

void main()
{
	
	//Initialisation des variables du jeu
	int tour = 1;
	int finPartie = 1, finJeu = 1;
	char sym_aff[3][3] = {{0}, {0}};

	do
	{
		affichage_interface(sym_aff);
		choix_case(sym_aff, tour);
		conditionVictoire(sym_aff, tour, &finPartie);
		tour++;
		if(finPartie == 0)
		{
			affichage_interface(sym_aff);
			reset(sym_aff, &tour, &finJeu);
			finPartie = 1;
		}
	}while(finJeu != 0);
}