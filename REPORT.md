*Auteurs : NOMS A INDIQUER*

# Compte rendu - Projet-Systeme-Avance

## Sujet choisi

Réaliser un interpréteur de commande simplifié similaire à bash en exploitant les connaissances et compétences acquises lors des cours et TP du module Systèmes d'exploitation avancés.

## Déroulement et gestion du projet

Nous avons choisi le gestionnaire de code source Github puisqu'il s'agit de l'outil que nous maitrisons le mieux.
Par la suite, nous avons décortiqué le sujet afin de comprendre les points essentiels et critiques du projet car c'était la première fois que nous faisions face à un projet si complexe en C.

Durant les premiers pas du projet, nous avons donc décidé de programmer majoritaiment ensemble afin de s'accorder sur l'architecture, les conventions et les tâches importantes à réaliser.

Finalement, nous avons établi une liste des différentes fonctions métiers, exigences et contraintes techniques que nous pourrions réaliser dans les meilleurs délais avant la deadline. 

## Fonctions métiers, exigences et contraintes abordées

Voici les fonctionnalités réalisées : 
- FM01
- FM02 mais pas entièrement (expliqué plus bas dans "Difficultés rencontrées")
- FM03
- FM04
- FM05
- FM06
- FM07

Voici les exigences techniques tenues : 
- CT01
- CT02
- CT03
- CT04
- CTO01 (doxy)

## Fonctionnement du mini-shell

- make all : compilation du projet
- make run : lancement du mini shell
- ./shell-project <cmd> : lancement du mini shell en mode batch
- make clean : supprime tous les fichiers.o

## Difficultés rencontrées

Nous avons rencontré des difficultés lors du développement de certaines fonctionnalités telles que : 
- Le langage C a posé problème pour certain membre du groupe. Il a fallu s'adapter.
- L'implémentation de la redirection de flux, on a réussi à la faire fonctionner avec '>' mais pas avec '<'.
- L'historisation des commandes dans un fichier history.log : les commandes ne s’écrivaient pas dans le bon fichier uniquement lorsqu’on changeait de répertoire. 
- La gestion du pipe a été compliqué à gérer pour nous.
- Le parcours de l'historique grâce aux flèches UP/DOWN : nous avions cherché plusieurs solutions ce qui nous a fait perdre du temps. Au final nous avons trouvé une librairie qui a une fonction qui nous a permis de le faire.
- La gestion des alias a posé problème également car nous n'avons pas su tout gérer en une seule ligne de commande directement. Pour palier à la gestion de l'alias / commande, nous avons fait une fonctionnalité qui découpe le processus avec des scanf.


## Points d'améliorations et conclusion

- Les opérateurs de contrôles. 
- La gestion des erreurs via le mécanisme proposés par errno : nous savons le faire mais nous l'avons vu trop tard dans le sujet. 
- Se familiariser davantage avec le langage C.

C'était intéressant d'appliquer la notion de pipe et fork dans le projet car ce n'était pas forcement quelque chose d'évident.