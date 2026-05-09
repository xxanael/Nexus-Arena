
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "evenement.h"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// Infos du joueur
char nomJoueur[25];
int pvMaxJoueur;
int pvActuelJoueur;
int degatBaseJoueur;
char classeJoueur[20];

// Infos monstre
char monster[25] = "Nexus_Monster";
int pvMaxMonstre = 3000;
int pvActuelMonstre;

// Code principal
int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int choix = 0;
    int action;
    int rejouer = 1;

    do
    {
        printf(
            "+--------------|*|--------------+\n"
            "|          NEXUS-ARENA          |\n"
            "+-------------------------------+\n\n");

        // Saisi du nom de l'utilisateur
        printf("[*] Veuillez entrer votre nom d'utilisateur : ");
        scanf("%24s", nomJoueur);
        viderBuffer();

        // Choix de la classe de l'utilisateur
        printf("\n***|CHOIX DE CLASSE|***\n\n");
        printf("[*] Veuillez choisir une classe : \n\n");
        printf("1.Chevalier\n2.Assassin\n3.Mage\n4.Archer\n5.Quitter\n\n");
        printf("Choix : ");

        if (scanf("%d", &choix) != 1)
        {
            viderBuffer();
            printf("Entree invalide.\n");
        }
        else
        {
            viderBuffer();

            // Notifications liées aux choix des classes
            switch (choix)
            {
            case 1:
                printf(GREEN "\n[!!!] NOTIFICATION [!!!]\n");
                pvMaxJoueur = 2000;
                degatBaseJoueur = 30;
                strcpy(classeJoueur, "Chevalier");
                printf("\n[!] FELICITATIONS ! Vous etes a present un chevalier et vous avez %d pv\n" RESET, pvMaxJoueur);
                imageChevalier();
                break;
            case 2:
                printf(GREEN "\n[!!!] NOTIFICATION [!!!]\n");
                pvMaxJoueur = 1500;
                degatBaseJoueur = 55;
                strcpy(classeJoueur, "Assassin");
                printf("\n[!] FELICITATIONS ! Vous etes a present un assassin et vous avez %d pv\n" RESET, pvMaxJoueur);
                imageAssassin();
                break;
            case 3:
                printf(GREEN "\n[!!!] NOTIFICATION [!!!]\n");
                pvMaxJoueur = 1400;
                degatBaseJoueur = 60;
                strcpy(classeJoueur, "Mage");
                printf("\n[!] FELICITATIONS ! Vous etes a present un mage et vous avez %d pv\n" RESET, pvMaxJoueur);
                imageMage();
                break;
            case 4:
                printf(GREEN "\n[!!!] NOTIFICATION [!!!]\n");
                pvMaxJoueur = 1700;
                degatBaseJoueur = 40;
                strcpy(classeJoueur, "Archer");
                printf("\n[!] FELICITATIONS ! Vous etes a present un archer et vous avez %d pv\n" RESET, pvMaxJoueur);
                imageArcher();
                break;
            case 5:
                printf("Au revoir\n");
                break;
            default:
                printf("Ce choix ne figure pas parmis les options disponibles\n");
                continue;
            }

            if (choix == 5)
                break;

            pause();

            // Points de vie du Joueur et du Monstre
            pvActuelJoueur = pvMaxJoueur;
            pvActuelMonstre = pvMaxMonstre;

            clearScreen();

            // Début de la game
            printf("\n---------------|GAME !|---------------\n\n");

            int nbTour = 1;
            int capaciteUtilise = 0;

            int bouclierActif = 0;
            int nbUtilisationBouclier = 0;

            while (pvActuelJoueur > 0 && pvActuelMonstre > 0)
            {
                printf("=====|TOUR %d|=====\n\n", nbTour);

                // Evènements aléatoires lors de la game (10% de chance de se réaliser à chaque tour)

                int chanceEvent = rand() % 100;

                if (chanceEvent < 10)
                {
                    gererEvenementAleatoire (&pvActuelJoueur, pvMaxJoueur, &pvActuelMonstre, pvMaxMonstre, monster);
                    if (pvActuelMonstre <= 0 || pvActuelJoueur <= 0)
                        break;
                }

                // Affichage du nom, classe et nb de Pv du joueur et du nombre de pv du monstre
                printf("%s [%s] : %d/%d PV  VS  %s : %d/%d PV\n\n",
                       nomJoueur, classeJoueur, pvActuelJoueur, pvMaxJoueur,
                       monster, pvActuelMonstre, pvMaxMonstre);

                // Affichage du dragon uniquement au premier tour
                if (nbTour == 1)
                {
                    apparitionMonster(monster);
                }

                // Choix de l'action à réaliser par le joueur entre attaquer, se soigner, utiliser une capacité spéciale et passer son tour
                printf("[*] Veuillez choisir une action\n\n");
                printf("1.Attaquer\t\t2.Se soigner\t\t3.Capacite Special\t\t4.Passer son tour\n\n");
                printf("Action : ");

                if (scanf("%d", &action) != 1)
                {
                    viderBuffer();
                    printf("Entree invalide.\n\n");
                    continue;
                }
                viderBuffer();

                if (action == 1)
                {
                    int degatsJoueur = rand() % 50 + degatBaseJoueur;
                    pvActuelMonstre -= degatsJoueur;
                    if (pvActuelMonstre < 0)
                        pvActuelMonstre = 0;
                    printf(RED "{-} Vous avez inflige %d degats au %s !\n\n" RESET, degatsJoueur, monster);
                }
                else if (action == 2)
                {
                    int soin = rand() % 100 + 50;
                    pvActuelJoueur += soin;
                    if (pvActuelJoueur > pvMaxJoueur)
                        pvActuelJoueur = pvMaxJoueur;
                    printf(GREEN "\n{+} Vous vous etes soigne de %d PV ! (%d/%d)\n\n" RESET, soin, pvActuelJoueur, pvMaxJoueur);
                }
                else if (action == 3)
                {
                    if (capaciteUtilise == 1)
                    {
                        printf("[!] Capacite speciale deja utilisee ! Veuillez reessayer\n\n");
                        continue;
                    }
                    else if (choix == 1 && capaciteUtilise == 0)
                    {
                        printf(YELLOW "[!] Vous utilisez la capacite speciale {Bouclier Royal}\n\n" RESET);
                        bouclierActif = 1;
                        nbUtilisationBouclier = 2;

                        capaciteUtilise = 1;
                    }
                    else if (choix == 2 && capaciteUtilise == 0)
                    {
                        printf(YELLOW "[!] Vous utilisez la capacite speciale {Frappe des doubles lames sanglantes}\n\n" RESET);

                        // Degats de la premiere lame
                        int degats1 = rand() % 50 + degatBaseJoueur;
                        pvActuelMonstre -= degats1;
                        if (pvActuelMonstre < 0)
                            pvActuelMonstre = 0;
                        printf(RED "{-} [LAME 1] Vous avez inflige %d degats au %s !\n\n" RESET, degats1, monster);

                        // Degats de la deuxieme lame
                        int degats2 = rand() % 50 + degatBaseJoueur;
                        pvActuelMonstre -= degats2;
                        if (pvActuelMonstre < 0)
                            pvActuelMonstre = 0;
                        printf(RED "{-} [LAME 2] Vous avez inflige %d degats au %s !\n\n" RESET, degats2, monster);

                        capaciteUtilise = 1;
                    }
                    else if (choix == 3 && capaciteUtilise == 0)
                    {
                        printf(YELLOW "[!] Vous utilisez la capacite speciale {Jugement celeste}\n\n" RESET);
                        printf(GREEN "... L'energie magique se concentre...\n\n" RESET);

                        // Degats de la capacite
                        int degatsJoueur = rand() % 300 + 300;
                        pvActuelMonstre -= degatsJoueur;
                        if (pvActuelMonstre < 0)
                            pvActuelMonstre = 0;
                        printf(RED "{-} [ARCANE] Vous dechargez %d degats sur le %s !\n\n" RESET, degatsJoueur, monster);

                        // Contrecoup
                        int contrecoup = rand() % 100 + 80;
                        pvActuelJoueur -= contrecoup;
                        if (pvActuelJoueur < 0)
                            pvActuelJoueur = 0;
                        printf(RED "{!} [CONTRECOUP] L'energie vous dechire : -%d PV !\n\n" RESET, contrecoup);

                        printf(MAGENTA "{=} Puissance brute : %d degats infliges, %d subis.\n\n" RESET, degatsJoueur, contrecoup);

                        capaciteUtilise = 1;
                    }
                    else if (choix == 4 && capaciteUtilise == 0)
                    {
                        printf(YELLOW "[!] Vous chargez votre arc afin d'utiliser la capacite speciale {Flèche de Zénith}\n\n" RESET);
                        int degatsJoueur = rand() % 200 + 100;
                        pvActuelMonstre -= degatsJoueur;
                        if (pvActuelMonstre < 0)
                            pvActuelMonstre = 0;
                        printf(RED "{-} Vous avez inflige %d degats au %s !\n\n" RESET, degatsJoueur, monster);

                        capaciteUtilise = 1;
                    }
                }
                else if (action == 4)
                {
                    printf(CYAN "\n[~] Vous passez votre tour...\n\n" RESET);
                }
                else
                {
                    printf("\n[!] Action invalide ! Choisissez 1, 2, 3 ou 4.\n\n");
                    continue;
                }

                // Ici le monstre attaque si il est encore en vie (Si le bouclier du chevalier est actif, son attaque est parée)
                if (pvActuelMonstre > 0)
                {
                    if (bouclierActif && nbUtilisationBouclier > 0)
                    {
                        printf("[!] Le Bouclier Royal absorbe l'attaque du %s !\n\n", monster);
                        nbUtilisationBouclier--;

                        if (nbUtilisationBouclier <= 0)
                        {
                            bouclierActif = 0;
                            printf(YELLOW "[!] Le Bouclier Royal est brise !\n\n" RESET);
                        }
                    }
                    else
                    {
                        int degatsMonstre = rand() % 50 + 20;
                        pvActuelJoueur -= degatsMonstre;
                        if (pvActuelJoueur < 0)
                            pvActuelJoueur = 0;
                        printf(RED "{-} %s vous a inflige %d degats !\n\n" RESET, monster, degatsMonstre);
                    }
                }

                // Affichage d'un message de victoire ou de défaite
                if (pvActuelMonstre <= 0)
                {
                    printf(GREEN "+=================================+\n");
                    printf("|           VICTORY !!!           |\n");
                    printf("|  %-20s est vaincu|\n", monster);
                    printf("|  Tours : %-3d    |  PV : %-5d   |\n", nbTour, pvActuelJoueur);
                    printf("+=================================+\n\n" RESET);

                    char choixEnregistrer;

                    do
                    {
                        printf("Souhaitez-vous enregistrer votre partie ? (O/N) : ");
                        scanf(" %c", &choixEnregistrer);
                        viderBuffer();

                        if (choixEnregistrer == 'O' || choixEnregistrer == 'o')
                        {
                            FILE *fichier = NULL;

                            fichier = fopen("Scores.txt", "a");

                            if (fichier != NULL)
                            {
                                fprintf(fichier, "Joueur : %-15s | Classe : %-10s | Tours : %-3d | PV restants : %-5d\n", nomJoueur, classeJoueur, nbTour, pvActuelJoueur);

                                fclose(fichier);
                                printf(GREEN "[+] Partie enregistree avec succes !\n\n" RESET);

                                system("notepad.exe Scores.txt");
                            }
                            else
                            {
                                printf("[!] Erreur : impossible d'ouvrir le fichier.\n\n");
                            }
                        }
                        else if (choixEnregistrer == 'N' || choixEnregistrer == 'n')
                        {
                            printf("-> Merci d'avoir essayer notre jeu !");
                        }
                        else
                        {
                            printf("[!] Choix invalide. Veuillez entrer O ou N.\n\n");
                        }

                    } while (choixEnregistrer != 'O' && choixEnregistrer != 'o' && choixEnregistrer != 'N' && choixEnregistrer != 'n');

                    break;
                }

                if (pvActuelJoueur <= 0)
                {
                    int choixRejouer = 2;
                    printf(RED "+==================================+\n");
                    printf("|            GAME  OVER            |\n");
                    printf("|    Tu as survecu %-3d tours      |\n", nbTour);
                    printf("| %-15s avait %-4d PV |\n", monster, pvActuelMonstre);
                    printf("|    Rejouer ?  1.Oui   2.Non      |\n");
                    printf("+==================================+\n" RESET);

                    printf("Veuillez choisir : ");
                    if (scanf("%d", &choixRejouer) != 1)
                    {
                        viderBuffer();
                        choixRejouer = 2;
                    }
                    viderBuffer();

                    switch (choixRejouer)
                    {
                    case 1:
                        printf("La partie recommence\n\n");
                        break;

                    case 2:
                        rejouer = 0;
                        printf("Au revoir\n\n");
                        break;

                    default:
                        printf("Ce choix ne figure pas parmis les options disponibles. Au revoir\n\n");
                        rejouer = 0;
                        break;
                    }

                    break;
                }

                // L'écran s'efface avant que la boucle ne recommence
                pause();
                clearScreen();
                printf("\n---------------|GAME !|---------------\n\n");

                nbTour++;
            }

            pause();
            clearScreen();
        }

    } while (choix != 5 && rejouer == 1);

    return 0;
}
