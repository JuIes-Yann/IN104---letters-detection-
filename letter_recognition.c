#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"
#include "database.h"

// Used the article here : https://alp.developpez.com/tutoriels/intelligence-artificielle/reseaux-de-neurones/

// Github link : https://github.com/JuIes-Yann/IN104---letters-detection-

int main ()
{




/* Learning rate. */
#define ALPHA (0.05)
/* Number of neurons. */
#define P_NEURONS (4)

 
  
			
			
  printf(" \n Début du programme : OK \n");
  struct training_set_t *ts = mk_training_set () ;
  printf(" \n Création du set d'entrainement : OK \n");
  struct net_t *net = mk_net (N_INPUTS, P_NEURONS) ;
  printf(" \n Création du Perceptron : OK \n");
  for (int i = 0; i < 500; i++) {
    
    train_neurons (net, ALPHA, ts) ;
    printf ("\n Entrainement #%d effectué.\n", i) ;
    print_net (net) ;
   
   
    
  }
  printf("\nSession d'entrainement du Perceptron : OK \n");
  

  printf ("\nPredictions:\n") ;
  

  
  printf ("\n #A \n");
  
  ecrire(letter_A1);
  predict (net, ts->items[0]) ;
  ecrire(letter_A2);
  predict (net, ts->items[1]) ;
  ecrire(letter_A3);
  predict (net, ts->items[2]) ;
  ecrire(letter_A4);
  predict (net, ts->items[3]) ;
  ecrire(letter_A5);
  predict (net, ts->items[4]) ;
  
 
  printf ("\n #Inconnue \n");
  ecrire(unknown5);
  predict (net, ts->items[5]) ;
  
 
 


  
  return 0 ; 
}











