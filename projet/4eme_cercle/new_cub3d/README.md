This project has been created as part of the 42 curriculum by amkhelif

Le but de cub3D est de créer un jeux en 3D a partir d'une  map en 2D . 
Pour realiser ce projet  nous utilisons lalgoritme Raycasting.

1. Le Raycasting 

L'écran de notre ordinateur fait 1920 pixels. Le Raycasting consiste à envoyer 1920 rayons depuis la position du joueur.

    Le rayon part du joueur, avance, et s'arrête dès qu'il touche un mur.
    On calcule la distance parcourue par le rayon.
     Plus le mur est loin, plus on le dessine petit. Plus il est près, plus on le dessine grand.

2. Le DDA

C'est l'algorithme qui fait avancer notre rayon. Au lieu d'avancer le rayon petit a petit  le DDA  fait sauter le rayon de case en case sur la grille de la carte  jusqu'à heurter un '1'.

Étape 1 : Le Parsing
    Vérification du nom du fichier : On s'assure que l'extension est bien .cub .

    Extraction des données : On lit le fichier ligne par ligne pour trouver les textures et on vérifie que les fichiers .xpm existent bien.

    Extraction des couleurs : On récupère les couleurs du sol  on vérifie qu'il n'y a pas de lettres que les chiffres sont entre 0 et 255  

    Extraction et vérification de la carte :
    on verifie qu'il n'y a qu'un seul joueur  et on sauvegarde sa position .

        Que la carte est totalement fermée par des murs grâce à notre algorithme

Étape 2 : L'Initialisation 

Si la carte est valide, on prépare le moteur de jeu.

    Le Joueur  : On place le joueur au centre de sa case (+ 0.5). on initialise deux vecteurs:

        dir_x / dir_y : La direction vers laquelle il regarde.

        plane_x / plane_y : Le plan de la caméra 

Étape 3 : Le Moteur 3D (Le Game Loop)

C'est le coeur battant du jeu. La MLX boucle à l'infini sur la fonction draw_map. Pour chaque frame (image) :

    Lancer de rayons : On fait une boucle 0 à  1920 Pour chaque x on calcule la direction exacte du rayon

    L'algorithme DDA : Le rayon avance de case en case tant quil na pas touche de mur

    Calcul de la hauteur On calcule la distance entre le joueur et le mur  À partir de cette distance, on calcule à quel pixel ou le mur doit commencer et se terminer .

Étape 4 : Mouvements et Événements (Jouabilité)

Fichiers concernés : move.c, player_move.c, player_move_utils.c

     On calcule le prochain pas  en multipliant notre vecteur de direction ou notre plan de caméra par une vitesse .

    Gestion des collisions  Avant de modifier la position réelle du joueur on simule son prochain pas si la prochaine case contient un 1 un espace ou \t le joueur ne peut plus avancer

    Rotation du regard : Si on appuie sur les flèches directionnelles on utilise une matrice de rotation mathématique  pour faire tourner nos vecteurs dir et plane.

Instructions
Compilation

To compile the project, run the following command at the root of the repository:

Execution

Run the program by passing a .cub file as an argument:
./cub3D map/your_map.cub

Resources


    Lodev Raycasting Tutorial - The standard reference for raycasting.

    MiniLibX Documentation - Essential for graphical functions.