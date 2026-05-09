#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET   "\033[0m"


void gererEvenementAleatoire (int *pvAJ, int pvMJ, int *pvAM, int pvMM, char monsterName[25])
{
    int typeEvent = rand() % 3;

                    printf(YELLOW "\n[!!!] EVENEMENT ALEATOIRE [!!!]\n" RESET);

                    switch (typeEvent)
                    {
                    case 0:
                        printf(YELLOW "[!] Le sol tremble violemment !\n" RESET);
                        printf(RED "[-] Le %s est destabilise : -80 PV\n\n" RESET, monsterName);
                        *pvAM -= 80;

                        if (*pvAM < 0)
                            *pvAM = 0;
                        break;

                    case 1:
                        printf(YELLOW "[!] Une pluie acide s'abat sur l'arene !\n" RESET);
                        printf(RED "{!} Vous perdez 60 PV a cause de la corrosion.\n\n" RESET);
                        *pvAJ -= 60;

                        if (*pvAJ < 0)
                            *pvAJ = 0;
                        break;

                    case 2:
                        printf(YELLOW "[!] Vous trouvez une herbe d'herbe medecinale rare !\n" RESET);
                        printf(GREEN "{+} Restauration systeme : +100 PV\n\n" RESET);
                        *pvAJ += 100;

                        if (*pvAJ > pvMJ)
                            *pvAJ = pvMJ;
                        break;
                    }
}

