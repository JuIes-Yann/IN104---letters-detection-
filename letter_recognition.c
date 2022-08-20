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
  for (int i = 0; i < 150; i++) {
    
    train_neurons (net, ALPHA, ts) ;
    printf ("\n Entrainement #%d effectué.\n", i) ;
    print_net (net) ;
   
    
  }
  printf("\nSession d'entrainement du Perceptron : OK \n");
  

  printf ("\nPredictions:\n") ;
  
  printf ("\n #B ");
  predict (net, ts->items[5]) ;
  
  printf ("\n #A ");
  predict (net, ts->items[0]) ;
  
  printf ("\n #C ");
  predict (net, ts->items[10]) ;
  
  printf ("\n #E ");
  predict (net, ts->items[15]) ;
  
  printf ("\n #Inconnue ");
  predict (net, ts->items[21]) ;
  
  return 0 ; 
}











