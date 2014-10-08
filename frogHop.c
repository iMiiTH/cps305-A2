#include <stdlib.h>
#include <stdio.h>


typedef struct PondType {
   int **grid;
   int length;
} Pond;

Pond* initializePond(int size);
void printPond(Pond *P);

int main( int argc, char *argv[] )
{
   if(argv[1]==NULL || argv[2]==NULL || argv[3]==NULL) {
      printf("Invalid arguments... exiting.\n");
      return 1;
   }
   int size = atoi(argv[1]);
   int xPos = atoi(argv[2]);
   int yPos = atoi(argv[3]);
   
   printf("The grid will be %dX%d\n",size, size);
   printf("The starting position is: %d, %d\n", xPos, yPos); 

   Pond *pond;
   printf("%p\n", pond);
   pond=initializePond(size);
   printPond(pond);
   return 0;
}

Pond* initializePond(int size)
{
   int i,j;
   Pond *P=malloc(sizeof(Pond));
   P->length=size;
   P->grid=calloc(size, sizeof *P->grid);
   for(i=0; i<P->length; i++) {
      P->grid[i]=calloc(size, sizeof(int));
   }
   return P;
}

void printPond(Pond *P)
{
   int i,j;
   for(i=0; i<P->length; i++) {
      for(j=0; j<P->length; j++) {
         printf("%d ", P->grid[i][j]);
      }
      putchar('\n');
   }
}
