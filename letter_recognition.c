#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"
#include "database.h"

// Github link : https://github.com/JuIes-Yann/Devoir-IN104---D-tection-A-B-C-E.git

int main ()
{




/* Learning rate. */
#define ALPHA (0.05)
/* Number of neurons. */
#define P_NEURONS (4)

  srand (time (NULL)) ;
  
			
			
  printf(" \n Début du programme : OK \n");
  struct training_set_t *ts = mk_training_set () ;
  printf(" \n Création du set d'entrainement : OK \n");
  struct net_t *net = mk_net (N_INPUTS, P_NEURONS) ;
  printf(" \n Création du Perceptron : OK \n");
  for (int i = 0; i < 500; i++) {
    
    train_neurons (net, ALPHA, ts) ;
    printf ("Iteration #%d done.\n", i) ;
    print_net (net) ;
    plot_net (net) ;
    
  }
  printf(" \n Session d'entrainement du Perceptron : OK \n");
  

  printf ("Predictions:\n") ;
  predict (net, ts->items[5]) ;
  predict (net, ts->items[0]) ;
  predict (net, ts->items[10]) ;
  predict (net, ts->items[15]) ;
  predict (net, ts->items[21]) ;
  return 0 ; 
}











