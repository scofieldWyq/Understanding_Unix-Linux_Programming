/*
 * konwFileAttr.c - list the file attribute from parameters.
 *
 * example: cmd <para1>[<para2|3>]
 *
 */

/**
  head file included.

 */
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
  let's go start.

*/
int main(int arg, char av[])
{
     /* check parameters */
     if ( arg == 1) {
          fprintf(stderr, "no parameter! you should use `cmd filename1`");
          exit(1);
     }

    /* start to read the file attribute */
  

     
  
