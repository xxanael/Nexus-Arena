🏰 NEXUS-ARENA - Jeu de combat tour par tour en C 🎮
Je vous présente mon tout premier programme en C
📜 DESCRIPTION
Nexus-Arena est un jeu de combat en mode texte où le joueur incarne un héros (🛡️ Chevalier, 🗡️ Assassin, 🔮 Mage ou 🏹 Archer) et affronte des monstres dans une arène. Le jeu propose un système de combat tour par tour avec des mécaniques uniques et des événements aléatoires.

🎯 MÉCANIQUES PRINCIPALES
1. 🛡️🗡️🔮🏹 Système de classes
🛡️ Chevalier : PV élevés (2000), dégâts modérés (30), capacité "Bouclier Royal" (bloque 2 attaques du monstre).

🗡️ Assassin : PV moyens (1500), dégâts élevés (55), capacité "Frappe des doubles lames" (2 attaques consécutives).

🔮 Mage : PV bas (1400), dégâts très élevés (60), capacité "Jugement céleste" (dégâts massifs avec contrecoup).

🏹 Archer : PV équilibrés (1700), dégâts moyens (40), capacité "Flèche de Zénith" (dégâts élevés en une seule attaque).

2. ⚔️ Combat tour par tour
Le joueur et le monstre s'affrontent à tour de rôle.

Actions disponibles : ⚔️ Attaquer, 💖 Se soigner, ✨ Capacité spéciale, ⏭️ Passer son tour.

Le monstre attaque automatiquement à la fin de chaque tour (sauf si bloqué par le bouclier du Chevalier).

3. 🎲 Événements aléatoires (10% de chance par tour)
🌍 Tremblement de terre : le monstre perd 80 PV.

☔ Pluie acide : le joueur perd 60 PV.

🌿 Herbe médicinale : le joueur gagne 100 PV.

4. 💾 Sauvegarde
Le joueur peut enregistrer ses scores dans un fichier scores.txt.

📂 STRUCTURE DU CODE
Variables globales
nomJoueur, pvMaxJoueur, pvActuelJoueur, degatBaseJoueur, classeJoueur : Infos du joueur.

monster, pvMaxMonstre, pvActuelMonstre : Infos du monstre.

Fonctions utilitaires
viderBuffer() : Nettoie le buffer d'entrée pour éviter les bugs.

pause() : Attend une confirmation de l'utilisateur pour continuer.

clearScreen() : Efface la console (compatible Windows/Linux).

Fonctions d'affichage
imageChevalier(), imageAssassin(), imageMage(), imageArcher() : Affiche l'ASCII Art de la classe choisie.

apparitionMonster() : Affiche l'ASCII Art du monstre.

Boucle principale
Saisie du nom et choix de la classe.

Initialisation des PV et des statistiques.

Boucle de combat : gestion des tours, des actions, des événements aléatoires, et des attaques du monstre.

Gestion de la victoire/défaite et enregistrement des scores.

🖥️ COMPATIBILITÉ
Fonctionne sur Windows (via system("cls")) et Linux/Mac (via codes ANSI).

Utilise des fonctions standard de C (stdio.h, stdlib.h, string.h, time.h).

👨‍💻 AUTEUR
Anaël SINGBO

🚀 AMÉLIORATIONS POSSIBLES
Ajouter un système de niveaux et d'expérience (XP).

Implémenter un inventaire pour stocker et utiliser des objets.

Ajouter plusieurs vagues de monstres (ex: Sorcier → 2 monstres → Nexus_Monster).

Sauvegarder/Charger l'état complet de la partie (pas seulement les scores).

Équilibrer les statistiques des classes et des monstres.

Ajouter un système de récompense après chaque combat.# Nexus-Arena
