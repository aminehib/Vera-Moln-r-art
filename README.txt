Nom : HIBAOUI	
Prénom : Mohammed Amine	


Séance 3-4

Séance 3 : 

Il y a donc 8 fichier (5 .cpp et 3 .hpp)



Pour le format des fichier txt, on peut y indiqué :
	* Pour tous :
		- la couleur
		- la couleur des côtés 
	* Pour circle :
		- le nom de la forme 
		- le rayon
		- le centre du cercle (cx et cy)
		- ordre : nom - cx - cy - r - couleur - couleur côté
	* Pour le rectangle :
		- le nom de la forme
		- la longueur
		- la largeur
		- ordre : nom - height - width - couleur - couleur côté
	* Et pour le polygon :
		- La nombre de coordonnées (exemple : x,y , il y a deux coordonnées, la coordonées x et la coordonnées y)
		- les points sachant que le premier et deuxième point que vous mettez sera les coordonées x et y du point (exe : polygon 3 5 8 7 ici il y a deux point 3,5 et 8,7 x,y x,y)
		- ordre : nom - nombre de coordonnées - points - couleur - couleur côté
Pour l'execution du programme il faut faire make dans le répertoire 'buil' puis soit faire ' ./src/main ... ' ou entré dans le répertoire 'src' et faire './main ... ',
 les petits points signifie le nom du fichier d'entré (qui contient les paramètre de la forme) et le nom du fichier de sortie (qui contient le nom du fichier à crée) 

Séance 4 :

Pour le TP4, il y a 10 fichier (5 .cpp et 3 .hpp)

Pour la lecture de fichier 'txt', il faut faire comme dans le TP3 juste à la fin d'une forme revenir à la ligne pour que se soit plus lisible.

Afin d'éxecuter les programmes, il y a d'abord l'executable 'main_multiple' (qui ce se trouve dans le fichier 'src' de 'build') qui contient les fonctions la question A4.a,
 si vous vouler faire un make pour ce fichier il faut donc changer dans le 'CMajeFile.txt' le nom de l'executable puis le nom du fichier à mettre en éxecutable qui est :
'test_draw_multiple_object.cpp'

Pour le programme des question suivantes, il faut juste executer le programme 'main_multiple_files' (qui ce trouve dans le fichier 'src' de 'build') qui contient le reste des questions.
Comme avant si le make ne fonctionne pas alors il faut juste changer dans le CMakefiles.txt dans le fichuer l'autre fichier 'src' qui ce trouve dans le fichier Seance 4, il faut le 
remplacé par 'test_draw_multiple_object_from_files.cpp' .  


Séance 5 - 6 - 7 :

il y a 17 fichier ( 13 .cpp et 4 .hpp)

Il y a plusieur fichier à exécuter :
	- canvas qui proviens du fichier test_draw_none_canvas.cpp
	- transform canvas qui proviens du fichier test_draw_transform_canvas.cpp qui fait 2 tableau
	- ListTrans qui proviens du fichier test_draw_trait_Vera.cpp qui transforme un object grâce à une liste de transformation
	- tab_james qui proviens du fichier Tab_james_bond.cpp qui crée normalement un tableau avec comme style le generique james bond
Il faut changer le CMakeFile si on veut compiler les fichier 

il y a quelques fonctions en plus comme la fonction qui change la couleur, qui crée un tableau  et pour l'aléatoire.

Pour le tableau james_bond j'ai essayer de mettre du hasard pour les couleurs, a chaque fois que vous executer le programmes les couleur changes .
