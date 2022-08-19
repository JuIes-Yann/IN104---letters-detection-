#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "database.h"
#ifndef fonctions_h
#define fonctions_h 



// There are 25 inputs in our case, corresponding with the 25 pixels of a 5x5 image


typedef double weight_t ;

/* input x neuron -> weight. Hence size n_inputs x p_neurons. */
struct net_t {
  int n_inputs ;
  int p_neurons ;
  weight_t **weights ;
  weight_t *biases ; /* Size: p_neurons. */
};


struct training_item_t {
  double *input ;  /* Size : n_inputs. */
  double *output ; /* Size : p_neurons. */
};

struct training_set_t {
  int nb_items ;
  struct training_item_t **items ;
};


FILE *weights_hd = NULL ;
FILE *errs_hd = NULL ;




/* returns the value of the output neuron */
double compute_neuron_output (struct net_t *net,
                              struct training_item_t *training_item,
                              int neuron_id)
{
// output is firstly equal to this neuron's biais 
   double coutput = -net->biases[neuron_id];

//  compute doing the ponderate mean 
   for (int i=0; i <25 ;i++) {
	coutput= coutput +net->weights[i][neuron_id]*training_item->input[i];
  
}
// compute with the activation fonction which is the sigmoid one in our case
   coutput = 1/(1+exp(coutput));
   return coutput;
}


/* Trains once one neuron on all the training set items. */
// Wildrow-Hoff algorithm is used during the training
void train_neuron (struct net_t *net, double alpha,
                   struct training_set_t *training_set, int neuron_id)
{
  /* For eack training item... */
  for (int item_index = 0; item_index < training_set->nb_items; item_index++) {


    /* Compute the neuron output, s_example. */
    double coutput = compute_neuron_output(net, training_set->items[item_index],neuron_id);

    /* Update weights if the obtained value is different from the expected. */
    if ( coutput!= training_set->items[item_index]->output[neuron_id]) {
    	for (int i =0; i<25; i++) {
    		net->weights[i][neuron_id] = net->weights[neuron_id][i] + alpha * training_set->items[item_index]->input[i] * (training_set->items[item_index]->output[neuron_id] - coutput);
    }
    
    }
    
      /* Bias update. */
   double new_biais=0;
   for (int i =0; i<25; i++) {  
   	new_biais= new_biais +	net->weights[neuron_id][i]*training_set->items[item_index]->input[i];
   } 
   net->biases[neuron_id]=new_biais;
     
   
  }           /* End of for (int item_index). */
}



/* Train once all the neurons on all the training set items. */
void train_neurons (struct net_t *net, double alpha,
                    struct training_set_t *training_set)
{
// We train the four neurons associated with the classes A, B, C and E
  for (int neuron_id=0; neuron_id<4 ; neuron_id++) {
  	train_neuron (net, alpha, training_set, neuron_id);
  	
  } 
}



/* Create a single-layer perceptron with given numbers of inputs and
   neurons. */
struct net_t* mk_net (int n_inputs,int p_neurons)
{
  struct net_t *net = malloc (sizeof (struct net_t)) ;
 // indicate the numbers of input and neurons defining the perceptron
  net->n_inputs = n_inputs ;
  net->p_neurons = p_neurons ;
  
  
  // creating a double dimension table with malloc
  net->weights = malloc (p_neurons) ;
  
  for (int k=0; k<p_neurons; k++) {
  	net->weights[k]=malloc(n_inputs);
  }
  
   // perceptron firstly has 0.5 on all of its coefficients before training
  for (int i=0; i<n_inputs ;i++) {
  	for (int j=0; j<p_neurons;j++) {
  		net->weights[j][i]=0.5;
  	}
  
  }
  
  net->biases = malloc (p_neurons) ;
  for (int i=0; i<p_neurons; i++) {
  	net->biases[i]=0.5;
  }
  

  return net ; 
}



/* Print the weights and biases of a single-layer perceptron. */
void print_net (struct net_t *net)
{
  printf (" \n ");
  
  
 // for each neurons
  for (int j=0;j<net->p_neurons;j++) {
    printf( "\n The biais of neuron n°%d is %f ", j , net->biases[j]);
    printf(" \n The weights are : ");
  	for (int i=0; i< net->n_inputs;i++) {
  	  printf("\n %f ", net->weights[i][j]);
  	
  	
  	}
  	
  }
  
  
  
}



/* Output of the weights for Gnuplot.
   Use with:
     plot 'log.txt' u 1:2 w l, '' u 1:3 w l, '' u 1:4 w l, '' u 1:5 w l, '' u 1:6 w l ; */
void plot_net (struct net_t *net)
{
  static int it_num = 0 ;

  fprintf (weights_hd, "%d ", it_num) ;
  for (int i = 0; i < net->n_inputs; i++) {
    for (int j = 0; j < net->p_neurons; j++) {
      fprintf (weights_hd, "%lf ", net->weights[i][j]) ;
    }
  }
  /* Print biases. */
  for (int i = 0; i < net->p_neurons; i++)
    fprintf (weights_hd, "%lf\n", net->biases[i]) ;

  it_num++ ;
}



/* Print the score of outputs of the network on an example. */
void predict (struct net_t *net, struct training_item_t *item)
{
  char* alphabet="ABCE";
  int indice =-1;
  double valeur=0.5;
  double coutput;
  for (int neuron_id = 0; neuron_id < net->p_neurons; neuron_id++) {
  	coutput = compute_neuron_output(net, item,neuron_id);
  	if (coutput > valeur) {
  	valeur = coutput;
  	indice = neuron_id;
  	}
  }
  if (valeur >0.5) {
  printf ("\n On prédit la lettre %c avec une valeur de : %f \n ", alphabet[indice], valeur ); 
  }
  else {
  printf ("\n La lettre est inconnue ici. \n");
  }
}



/* Create a training item from a string (assumed 5x5) and the value it
   represents. */
struct training_item_t* mk_training_item (const char *data, char expected)
{
  struct training_item_t *ti = malloc (sizeof (struct training_item_t)) ;
  ti->input=malloc(sizeof(double)*25);
  ti->output=malloc(sizeof(double)*4);
  
  // fill the training item with 1 for * and 0 for void.
  for (int i=0; i<25; i++) {
 	if (data[i]=='*') {
 	  ti->input[i]=1;
 	
 	}
 	else {
 	  ti->input[i]=0;
 	}
 }
   for (int k =0; k<4; k++) {
 	ti->output[k]=0;
 	}	
 //1 at first position in output(ex: [1,0,0,0]) if it's an A, second position if it's a B, etc 
 // Only 0 in output if the letter is not A, B, C or E.
 
  if (expected=='A') {
 	ti->output[0]=1;
 }

  if (expected=='B') {
 	ti->output[1]=1;
 }

  if (expected=='C') {
 	ti->output[2]=1;
 }

  if (expected=='E') {
 	ti->output[3]=1;
 }

  return ti ;
}



/* Create the training set from the string defined in the database */
struct training_set_t* mk_training_set ()
{
  struct training_set_t *ts = malloc (sizeof (struct training_set_t)) ;
  
  ts->nb_items = 25;
  ts->items = malloc (sizeof(struct training_item_t)*25) ;
 
//creating the 25 items
  struct training_item_t *ti1 = mk_training_item (letter_A1, 'A') ;
  ts->items[0] = ti1 ;
  struct training_item_t *ti2 = mk_training_item (letter_A2, 'A') ;
  ts->items[1] = ti2 ;
  struct training_item_t *ti3 = mk_training_item (letter_A3, 'A') ;
  ts->items[2] = ti3 ;
  struct training_item_t *ti4 = mk_training_item (letter_A4, 'A') ;
  ts->items[3] = ti4 ;
  struct training_item_t *ti5 = mk_training_item (letter_A5, 'A') ;
  ts->items[4] = ti5 ;
  
  struct training_item_t *ti6 = mk_training_item (letter_B1, 'B') ;
  ts->items[5] = ti6 ;
  struct training_item_t *ti7 = mk_training_item (letter_B2, 'B') ;
  ts->items[6] = ti7 ;
  struct training_item_t *ti8 = mk_training_item (letter_B3, 'B') ;
  ts->items[7] = ti8 ;
  struct training_item_t *ti9 = mk_training_item (letter_B4, 'B') ;
  ts->items[8] = ti9 ;
  struct training_item_t *ti10 = mk_training_item (letter_B5, 'B') ;
  ts->items[9] = ti10 ;
  
  struct training_item_t *ti11 = mk_training_item (letter_C1, 'C') ;
  ts->items[10] = ti11 ;
  struct training_item_t *ti12 = mk_training_item (letter_C2, 'C') ;
  ts->items[11] = ti12 ;
  struct training_item_t *ti13 = mk_training_item (letter_C3, 'C') ;
  ts->items[12] = ti13 ;
  struct training_item_t *ti14 = mk_training_item (letter_C4, 'C') ;
  ts->items[13] = ti14 ;
  struct training_item_t *ti15 = mk_training_item (letter_C5, 'C') ;
  ts->items[14] = ti15 ;
  
  struct training_item_t *ti16 = mk_training_item (letter_E1, 'E') ;
  ts->items[15] = ti16 ;
  struct training_item_t *ti17 = mk_training_item (letter_E2, 'E') ;
  ts->items[16] = ti17 ;
  struct training_item_t *ti18 = mk_training_item (letter_E3, 'E') ;
  ts->items[17] = ti18 ;
  struct training_item_t *ti19 = mk_training_item (letter_E4, 'E') ;
  ts->items[18] = ti19 ;
  struct training_item_t *ti20 = mk_training_item (letter_E5, 'E') ;
  ts->items[19] = ti20 ;
  
  struct training_item_t *ti21 = mk_training_item (unknown1, 'x') ;
  ts->items[20] = ti21 ;    
  struct training_item_t *ti22 = mk_training_item (unknown2, 'x') ;
  ts->items[21] = ti22 ; 
  struct training_item_t *ti23 = mk_training_item (unknown3, 'x') ;
  ts->items[22] = ti23 ; 
  struct training_item_t *ti24 = mk_training_item (unknown4, 'x') ;
  ts->items[23] = ti24 ; 
  struct training_item_t *ti25 = mk_training_item (unknown5, 'x') ;
  ts->items[24] = ti25 ; 

  
  


  return ts ;
}







#endif
