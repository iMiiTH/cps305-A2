#include <stdlib.h>
#include <stdio.h>


typedef struct PondType {
   int **grid;
   int length;
} Pond;

Pond* initializePond(int size);
void printPond(Pond *P);
int insufficientMemory();

int main( int argc, char *argv[] )
{
   int size = atoi(argv[1]);
   int xPos = atoi(argv[2]);
   int yPos = atoi(argv[3]);

   printf("The grid will be %dX%d\n",size, size);
   printf("The starting position is: %d, %d\n", xPos, yPos); 

   Pond *pond;
   pond=initializePond(size);
   if(pond==NULL) return insufficientMemory();
   printPond(pond);
}

Pond* initializePond(int size)
{
   int i,j;
   Pond *P=malloc(sizeof(Pond));
   if(P==NULL) return NULL;
   P->length=size;
   P->grid=calloc(size, sizeof *P->grid);
   if(P->grid==NULL) return NULL;
   for(i=0; i<P->length; i++) {
      P->grid[i]=calloc(size, sizeof(int));
      if(P->grid[i]==NULL) return NULL;
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
int insufficientMemory()
{
   printf("Not enough memory.\n");
   return NULL;
}
