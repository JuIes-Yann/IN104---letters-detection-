#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#ifndef database_h
#define database_h 

// Data Base composed with letters 
#define N_INPUTS (5 * 5)

//Letter A made in different ways.

const char letter_A1[] =
  "  *  "                                       \
  " * * "                                       \
  " *** "                                       \
  " * * "                                       \
  " * * " ;
  
  const char letter_A2[] =
  " *** "                                       \
  " * * "                                       \
  " *** "                                       \
  " * * "                                       \
  " * * " ;
  
  const char letter_A3[] =
  "  *  "                                       \
  " * * "                                       \
  " *** "                                       \
  " * * "                                       \
  "     " ;
  
  const char letter_A4[] =
  " *** "                                       \
  " * * "                                       \
  " *** "                                       \
  " * * "                                       \
  "     " ;
  
    const char letter_A5[] =
  "  *  "                                       \
  " * * "                                       \
  " *** "                                       \
  " * * "                                       \
  " *   " ;
  
  
// Letter B made in different ways. 
const char letter_B1[] =
  "***  "                                       \
  "*  * "                                       \
  "***  "                                       \
  "*  * "                                       \
  "***  " ;
  
  const char letter_B2[] =
  "**** "                                       \
  "*  * "                                       \
  "***  "                                       \
  "*  * "                                       \
  "**** " ;
  
  const char letter_B3[] =
  "***  "                                       \
  "*  * "                                       \
  "**** "                                       \
  "*  * "                                       \
  "***  " ;
  
  const char letter_B4[] =
  "**** "                                       \
  "*  * "                                       \
  "**** "                                       \
  "*  * "                                       \
  "**** " ;
  
  const char letter_B5[] =
  "**** "                                       \
  "*   *"                                       \
  "**** "                                       \
  "*   *"                                       \
  "**** " ;
  
  
// Letter C made in different ways.
const char letter_C1[] =
  " *** "                                       \
  "*    "                                       \
  "*    "                                       \
  "*    "                                       \
  " *** " ;
  
const char letter_C2[] =
  " ****"                                       \
  "*    "                                       \
  "*    "                                       \
  "*    "                                       \
  " ****" ;
  
const char letter_C3[] =
  "**** "                                       \
  "*    "                                       \
  "*    "                                       \
  "*    "                                       \
  "**** " ;
  
const char letter_C4[] =
  "*****"                                       \
  "*    "                                       \
  "*    "                                       \
  "*    "                                       \
  "*****" ;
  
const char letter_C5[] =
  " *** "                                       \
  "*    "                                       \
  "*    "                                       \
  "*    "                                       \
  " ****" ;      


// Letter E made in different ways.    
const char letter_E1[] =
  "**** "                                       \
  "*    "                                       \
  "**** "                                       \
  "*    "                                       \
  "**** " ;
  
const char letter_E2[] =
  " *** "                                       \
  "*    "                                       \
  "**** "                                       \
  "*    "                                       \
  " *** " ;
  
const char letter_E3[] =
  "*****"                                       \
  "*    "                                       \
  "**** "                                       \
  "*    "                                       \
  "*****" ;
  
 const char letter_E4[] =
  "***  "                                       \
  "*    "                                       \
  "***  "                                       \
  "*    "                                       \
  "***  " ;
  
const char letter_E5[] =
  "**** "                                       \
  "*    "                                       \
  "***  "                                       \
  "*    "                                       \
  "**** " ;       


// Unknown letters.
const char unknown1[] =
  "     "                                        \
  "     "                                        \
  "     "                                        \
  "     "                                        \
  "     " ;
  
const char unknown2[] =
  "     "                                        \
  "  *  "                                        \
  "  *  "                                        \
  "     "                                        \
  "*  * " ;
  
const char unknown3[] =
  "    *"                                        \
  "    *"                                        \
  "    *"                                        \
  "    *"                                        \
  "    *" ;
const char unknown4[] =
  "     "                                        \
  "     "                                        \
  "  ***"                                        \
  "  * *"                                        \
  "  ***" ;
const char unknown5[] =
  " * * "                                        \
  "* * *"                                        \
  "*   *"                                        \
  " * * "                                        \
  "  *  " ;        



void ecrire(const char* lettre) {
  printf("\n");
  
  for (int i=0;i<25;i++) {
    printf("%c",lettre[i]);
  
  if ((i+1)%5==0) {
    printf("\n");
  } 
  }
  printf("\n");



}



#endif
