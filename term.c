/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 04:09:34 by neprocur          #+#    #+#             */
/*   Updated: 2017/07/18 08:49:50 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"


3.1 Caractéristiques de base	  	Caractéristiques de base.
3.2 Taille de l'écran	  	La taille de l'écran et ce qui se passe quand il change.
3.3 Mouvement du curseur	  	Différentes manières de déplacer le curseur.
3.4 Emballage	  	Que se passe-t-il si vous écrivez un caractère dans la dernière colonne.
3.5 Défilement	  	Pousser le texte vers le haut et vers le bas sur l'écran.
3.6 Fenêtres	  	Limiter la partie de la fenêtre que la sortie affecte.
3.7 Effacement des parties de l'écran	  	Effacement d'une ou plusieurs lignes.
3.8 Insérer / supprimer la ligne	  	Création de nouvelles lignes vierges au milieu de l'écran; Suppression de lignes.
3.9 Insérer / Supprimer le caractère	  	Insertion et suppression de caractères dans une ligne.
3.10 Modes de mise en avant et d'apparence	  	Mettre en surbrillance une partie du texte.
3.11 Sous-jacent	  	Soulignant une partie du texte.
3.12 Visibilité du curseur	  	Rendre le curseur plus ou moins facile à repérer.
3.13 Bell	  	Attire l'attention de l'utilisateur; Non localisé sur l'écran.
3.14 Clavier et touches de fonction	  	Reconnaissant lorsque les touches de fonction ou les flèches sont tapées.
3.15 Meta Key	  	META Agit comme une clé de changement supplémentaire.
3.16 Initialisation	  	Commandes utilisées pour initialiser ou réinitialiser le terminal.
3.17 Capacités de rembourrage	  	Info pour le noyau sur la quantité de rembourrage nécessaire.
3.18 Ligne de statut	  	Une ligne d'état affiche des informations "en arrière-plan".
3.19 Demi-ligne de mouvement	  	Déplacement par demi-lignes, pour les supermarchés et les indices.
3.20 Contrôle des imprimantes attachées aux bornes	  	Contrôle des imprimantes auxiliaires des bornes d'affichage.

tgoto

Unix termcap n'a pas tparam.
Pour le `Cm ', Car tgotoune fonction spéciale permet d'éviter des problèmes avec des caractères nuls, des onglets et des nouvelles lignes sur certains types de terminaux anciens qui utilisent`%. ' Codage pour cette capacité.


Exemple padding
Char * tparam (char * ctlstring , char * buffer , int size , int parm1 , ...)

{ 
	Char * buf; 
	Char buffer [40]; 

	Buf = tparam (commande, tampon, 40, parm); 
	Les entrées (buf, 1, fputchar); 
	Si (buf! = Buffer) 
		free (buf); 
}
	
Char * tgoto (char * cstring , int hpos , int vpos )

Notez que cela tgotorenverse l'ordre de ses opérandes: la position horizontale vient avant la position verticale dans les arguments tgoto, bien que la position verticale soit antérieure à l'horizontale dans les paramètres de la`Cm 'chaîne. Si vous utilisez tgotoavec une commande telle que`AL 'Cela prend un paramètre, vous devez passer le paramètre tgotocomme "position verticale".



oici un exemple d'interrogation d'une description de terminal pour différentes fonctionnalités, avec des conditionnels pour sélectionner entre les méthodes Unix et GNU pour fournir un espace de mémoire tampon.


Char * tgetstr (); 

Char * cl_string, * cm_string; 
Int height; 
Int width; 
Int auto_wrap; 

Char PC; / * Pour les entrées. * / 
Char * BC; / * Pour tgoto. * / 
Char * UP; 

Interrogate_terminal () 
{ 
#ifdef UNIX 
	/ * Ici, nous supposons qu'un term_buffer explicite a 
		été fourni à tgetent. * / 
		Char * buffer 
		= (char *) malloc (strlen (terme_buffer)); 


#define BUFFADDR & buffer 
#else 
#define BUFFADDR 0 
#endif 

	char * temp; 

	/ * Extraire les informations que nous utiliserons. * / 
		Cl_string = tgetstr ("cl", BUFFADDR); 
	Cm_string = tgetstr ("cm", BUFFADDR); 
	Auto_wrap = tgetflag ("



			init_terminal_data ()
			{
			char *termtype = getenv ("TERM");
			int success;

			if (termtype == 0)
			fatal ("Specify a terminal type with `setenv TERM <yourtype>'.\n");

			success = tgetent (term_buffer, termtype);
			if (success < 0)
			fatal ("Could not access the termcap data base.\n");
			if (success == 0)
			fatal ("Terminal type `%s' is not defined.\n", termtype);
			}
