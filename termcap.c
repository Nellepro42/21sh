

1.

1.Rechercher la description du type terminal = tgetent  Int tgetent (char *buffer, char *termtype);
echercher la description du type terminal = tgetent  Int tgetent (char *buffer, char *termtype);
Cette fonction trouve la description et la rappelle en interne pour connaitre la capacite du teminal.
L'argument termtype est une chaine qui est le nom du type terminal a rechercher> On l'obtient en general de la variable d'env en termutilisant g
etenv("TERM")
Version GNU ---- On peut demander a tgetent dallouer suffisamment d'espace> Passez un pointeur nul pour le tampon et tgetent alloue le stockage en utilisant malloc. Il n'y a aucun moyen d'obtenir l'adresse attribuee et vous ne devriez pas essayer de liberer le stockage.
Version UNIX ---- vous devez attribuer l'espace pour la description et passer l'adresse de l'espace en tant que memoire tampon d'argument, il n'y
a aucune maniere de savoir combien d'espace est necessaire = allouer un tampon de 2048c caracteres et supposer que ca soi suffisant.
termcap enregistre son adresse interne pour une utilisation lorsque vous interrogiez plus tard avec tgetnum, tgetstr ou tgetflag.


Si le tampon a ete attribue par termcap, il sera libere par termcap en appelant tgetent a nouveau. Si vous avez fourni le tampon, vous devez vous
assurer que son contenu reste inchange aussi longtemps que vous prevoyez d'interroger la description.


Interroger la description du terminal
----------------------------------------

Chaque info consignee dans une description de terminal est appelee une capacite. Chaque capacite de terminal definie possede un nom de code a deux lettres et une signification specifique.
Une fois que vous avez trouve la description appropriee du terminal avec tgetent, votre programme d
'application doit l'interroger pour diverses fonctions de terminal. Vous devez specifier le code a
deux lettres de la capacite dont vous recherchez la valeur.

Les valeurs de capacite peuvent etre numeriques, booleennes (la capacite est presente ou absente) ou les chaines. Toute capacite particuliere a toujours le meme type de valeur; par exemple 'co' a toujours une valeur numerique, alors que 'am' (enveloppe automatique a la marge) est toujours un drapeau, et 'cm' (commande de mouvement du curseur) a toujours une valeur de chaine.

Il existe trois fonctions a utiliser pour obtenir la valeur d'une capacite, en fonction du type de valeur que possede la capacite:

int tgetnum(char *name);
int	tgetflag(char *name);
char * tgetstr(char *name, char **area);

tgetnum:
-------
		Utilisez tgetnum pour obtenir une valeur de capacite qui est numerique. Le nom de l'argument est le nom de code a deux lettre de la capacite. Si la capacite est presente, tgetnum renvoie la valeur numerique(qui n'est pas negative). Si la fonctionnalite n'est pas mentionnee dans la descritpion du terminal, elle renvoie -1.

tgetflag:
--------
		Utilisez tgetflag pour obtenir une valeur booleenne. Si le nom de la capacite est present dans la description du terminal, tgetflag renvoi 1 sinon il renvoie 0.

tgetstr:
--------
		Utilisez tgetstr pour obtenir une valeur de chaine. Il renvoie un pointeur vers une chaine qui est la valeur de la capacite ou un pointeur nul si la capacite n'est pas presente dans la description du terminal. Il existe deux facon de trouver de l'espace pour stocker la valeur de chaine.
		-demander a tgetstr d'attribuer l'espace. Passez un pointeur nul pour la zone d'argument et tgetstr utiliserez malloc pour attribuer un stockage suffisamment grand pour la valeur. Termcap ne liberera jamais ce stockage ou ne le renverra plus, vous devriez le liberer lorsque vous l'avez termine----uniquement avec GNU
		-Fournir l'espace. Fournissez a la zone d'argument l'adresse d'une variable de pointeur de type char *. Avant d'appeler tgetstr, initialisez la variable pour localiser l'espace dispo. Ensuite tgetstr, stocke la valeur de chaine dans cet espace et augmentera la variable de pointeur pour pointer apres l'espace qui a ete utilise. Vous pouvez utiliser la meme variable de pointeur pour de nombreux appels tgetstr. Il n'existe aucun moyen de determiner la quantite d'espace necessaire a une seule chaine, et aucun moyen pour empecher ou gerer le debordement de la zone que vous avez fournie. Cependant, vous pouvez etre sur que la taille totale de toutes les valeurs de chaine que vous obtiendrez a partir de la description du terminal n'est pas superieure a la taille de la description (sauf si vous obtenez la meme capacite deux fois) strlen. Vous pouvez determiner cette taille avec le tampon que vous avez fourni tgetent.

Initialisation pour l'utilisation de Termcap
--------------------------------------------
Avant de commencer a envoyer des commandes a un terminal en utilisant termcap, un programme d'application devrait faire deux choses:
	-Initialiser diverses variables globales auxquelles se referent les fonctions de sortie de la bibliotheque. Ceux-ci incluent PCET ospeed pour le rembourrage et UPET BC pour le mouvement du curseur.
	- dites au noyau de desactiver la modification et le rembourrage des caracteres d'onglets horizontaux envoyes au terminal.

Pour desactiver le traitement de sortie dans Berkeley Unix, vous utilisez ioctl avec le code TIOCLSET pour definir le bit nomme LLITOUT et effeacer les bits en utilisant TIOCSETN.


		1. Trouver une description de terminal: tgetent
		----------------------------------------------

		Un programme d'application qui va utiliser termcap doit d'abord rechercher la description du type d
		e terminal utilise. Cela se fait en appelant tgetent: int tgetent(char *buffer, char *termtype);

		Cette fonction trouve la descritpion et la rappelle en interne afin que vous puissiez l'interroger
		sur les capacites de terminal specifiques. (voir : Interroger la description du terminal)

		L'argument termtype est une chaine qui est le nom du type de terminal a rechercher. Vous l'obtiendr
		ez de la variable d'environnement en termutilisant getenv("TERM")

		--------------------------------------


		Cette fonction trouve la description et la rappelle en interne pour connaitre la capacite du teminal.
		L'argument termtype est une chaine qui est le nom du type terminal a rechercher> On l'obtient en general de la variable d'env en termutilisant g
		etenv("TERM")
		Version GNU ---- On peut demander a tgetent dallouer suffisamment d'espace> Passez un pointeur nul pour le tampon et tgetent alloue le stockage en utilisant malloc. Il n'y a aucun moyen d'obtenir l'adresse attribuee et vous ne devriez pas essayer de liberer le stockage.
Version UNIX ---- vous devez attribuer l'espace pour la description et passer l'adresse de l'espace en tant que memoire tampon d'argument, il n'y
a aucune maniere de savoir combien d'espace est necessaire = allouer un tampon de 2048c caracteres et supposer que ca soi suffisant.
termcap enregistre son adresse interne pour une utilisation lorsque vous interrogiez plus tard avec tgetnum, tgetstr ou tgetflag.


Si le tampon a ete attribue par termcap, il sera libere par termcap en appelant tgetent a nouveau. Si vous avez fourni le tampon, vous devez vous
assurer que son contenu reste inchange aussi longtemps que vous prevoyez d'interroger la description.

----------------------------------------

Chaque info consignee dans une description de terminal est appelee une capacite. Chaque capacite de terminal definie possede un nom de code a deux lettres et une signification specifique
