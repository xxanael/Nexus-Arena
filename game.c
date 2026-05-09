#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET   "\033[0m"


// Fonctions pour vider le buffer et mettre le code en pause en attendant une acion de l'utilisateur
void viderBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pause()
{
    printf("Appuyez sur la touche Entree pour continuer...");
    viderBuffer();
    getchar();
}

// Fonction pour effacer l'écran
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
#endif
}

// Fonction pour afficher un chevalier
void imageChevalier ()
{
    printf(GREEN "  ,   A           {}             \n");
    printf(" / \\, | ,        .--.           \n");
    printf("|    =|= >      /.--.\\          \n");
    printf(" \\ /` | `       |====|          \n");
    printf("  `   |         |`::` |         \n");
    printf("      |     .-;`\\..../`;_.-^-._ \n");
    printf("     /\\\\/  /  |...::..|`   :   `|\n");
    printf("     |:'\\ |   /'''::''|   .:.   |\n");
    printf("      \\ /\\;-,/\\   ::  |..:::::.|\n");
    printf("      |\\ <` >  >._::_.| ':::::' |\n");
    printf("      | `\"\"`  /   ^^  |   ':'   |\n");
    printf("      |       |       \\    :    /\n");
    printf("      |       |        \\   :   /\n");
    printf("      |       |___/\\___|`-.:.-` \n");
    printf("      |        \\_ || _/    `    \n");
    printf("      |        <_ >< _>         \n");
    printf("      |        |  ||  |         \n");
    printf("      |        |  ||  |         \n");
    printf("      |       _\\.:||:./_        \n");
    printf("      | jgs  /____/\\____\\       \n\n" RESET);
}

// Fonction pour afficher un assassin
void imageAssassin ()
{
    printf(GREEN "      .AMMMMMMMMMMA.          \n");
    printf("       .AV. :::.:.:.::MA.     \n");
    printf("      A' :..        : .:`A    \n");
    printf("     A'..              . `A.  \n");
    printf("    A' :.    :::::::::  : :`A \n");
    printf("    M  .    :::.:.:.:::  . .M \n");
    printf("    M  :   ::.:.....::.:   .M \n");
    printf("    V : :.::.:........:.:  :V \n");
    printf("   A  A:    ..:...:...:.   A A\n");
    printf("  .V  MA:.....:M.::.::. .:AM.M\n");
    printf(" A'  .VMMMMMMMMM:.:AMMMMMMMV: A\n");
    printf(":M .  .`VMMMMMMV.:A `VMMMMV .:M:\n");
    printf(" V.:.  ..`VMMMV.:AM..`VMV' .: V \n");
    printf("  V.  .:. .....:AMMA. . .:. .V  \n");
    printf("   VMM...: ...:.MMMM.: .: MMV   \n");
    printf("       `VM: . ..M.:M..:::M'     \n");
    printf("         `M::. .:.... .::M      \n");
    printf("          M:.  :. .... ..M      \n");
    printf(" VK       V:  M:. M. :M .V      \n");
    printf("          `V.:M.. M. :M.V'      \n\n" RESET);
}

// Fonction pour afficher un mage
void imageMage ()
{
    printf(GREEN"                  .'* *.'            \n");
    printf("               __/_*_*(_             \n");
    printf("              / _______ \\            \n");
    printf("             _\\_)/___\\(_/_           \n");
    printf("            / _((\\- -/))_ \\          \n");
    printf("            \\ \\())(-)(()/ /          \n");
    printf("             ' \\(((()))/ '           \n");
    printf("            / ' \\)).))/ ' \\          \n");
    printf("           / _ \\ - | - /_  \\         \n");
    printf("          (   ( .;''';. .'  )        \n");
    printf("          _\\\"__ /    )\\ __\"/_        \n");
    printf("            \\/  \\   ' /  \\/          \n");
    printf("             .'  '...' ' )           \n");
    printf("              / /  |  \\ \\            \n");
    printf("             / .   .   . \\           \n");
    printf("            /   .     .   \\          \n");
    printf("           /   /   |   \\   \\         \n");
    printf("         .'   /    b    '.  '.       \n");
    printf("     _.-'    /     Bb     '-. '-._   \n");
    printf(" _.-'       |      BBb       '-.  '-.\n");
    printf("(________mrf\\____.dBBBb.________)____)\n\n" RESET);
}

// Fonction pour afficher un archer
void imageArcher ()
{
    printf(GREEN "                                                        |\n");
    printf("                                                        \\.\n");
    printf("                                                        /|.\n");
    printf("                                                      /  `|.\n");
    printf("                                                    /     |.\n");
    printf("                                                  /       |.\n");
    printf("                                                /         `|.\n");
    printf("                                              /            |.\n");
    printf("                                            /              |.\n");
    printf("                                          /                |.\n");
    printf("     __                                 /                  `|.\n");
    printf("      -\\                              /                     |.\n");
    printf("        \\\\                          /                       |.\n");
    printf("          \\\\                      /                         |.\n");
    printf("           \\|                   /                           |\\\n");
    printf("             \\#####\\          /                             ||\n");
    printf("         ==###########>     /                               ||\n");
    printf("          \\##==      \\    /                                 ||\n");
    printf("     ______ =       =|__/___                                ||\n");
    printf(" ,--' ,----`-,__ ___/'  --,-`-==============================##==========> \n");
    printf("\\               '        ##_______ ______   ______,--,____,=##,__\n");
    printf(" `,    __==    ___,-,__,--'#'  ==='      `-'              | ##,-/\n");
    printf("   `-,____,---'       \\####\\              |        ____,--\\_##,/\n");
    printf("       #_              |##   \\  _____,---==,__,---'         ##\n");
    printf("        #              ]===--==\\                            ||\n");
    printf("        #,             ]         \\                          ||\n");
    printf("         #_            |           \\                        ||\n");
    printf("          ##_       __/'             \\                      ||\n");
    printf("           ####='     |                \\                    |/\n");
    printf("            ###       |                  \\                  |.\n");
    printf("            ##       _'                    \\                |.\n");
    printf("           ###=======]                       \\              |.\n");
    printf("          ///        |                         \\           ,|.\n");
    printf("          //         |                           \\         |.\n");
    printf("                                                   \\      ,|.\n");
    printf("                                                     \\    |.\n");
    printf("                                                       \\  |.\n");
    printf("                                                         \\|.\n");
    printf("                                                         /.\n");
    printf("                                                        |\n\n" RESET);
}


// Fonction pour l'apparition du monstre
void apparitionMonster(char monsterApparition[25])
{
    printf("\nVous entrez dans l'arene...\n");
                printf("Un rugissement terrifiant retentit !\n\n");

               printf(RED);
               printf("\t         ___====-_  _-====___\n");
               printf("           _--^^^#####//      \\\\#####^^^--_\n");
               printf("        _-^##########// (    ) \\\\##########^-_\n");
               printf("       -############//  |\\^^/|  \\\\############-\n");
               printf("     _/############//   (@::@)   \\\\############\\_\n");
               printf("    /#############((     \\\\//     ))#############\\\n");
               printf("   -###############\\\\    (oo)    //###############-\n");
               printf("  -#################\\\\  / VV \\  //#################-\n");
               printf(" -###################\\\\/      \\//##################-\n");
               printf("_#/|##########/\\######(   /\\   )######/\\##########|\\#_\n");
               printf("|/ |#/\\#/\\#/\\/  \\#/\\##\\  |  |  /##/\\#/  \\/\\#/\\#/\\#| \\|\n");
               printf("`  |/  V  V  `   V  \\#\\| |  | |/#/  V   '  V  V  \\|  '\n");
               printf("   `   `  `      `   / | |  | | \\   '      '  '   '\n");
               printf("                    (  | |  | |  )\n");
               printf("                   __\\ | |  | | /__\n");
               printf("                  (vvv(VVV)(VVV)vvv)\n");
               printf(RESET);
                printf("\nLe %s se dresse devant vous !\n\n", monsterApparition);
}
