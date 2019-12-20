#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#define MILLI_S 1000.0

//travaille de TP COMPLEXITE MIV
// AMINE GUENAOUI
// BLIDI FOUAD

void createFile(char  str[],char  f[], double time);
int fib(int a );
void fact(int n);
void createAssociatedFile(int n,char  name[], double tempExec);
void triPermutation(int n);
void rechercheDichotomique(int n);
void rechercheSequentiel(int n);
void deFusionner(int A[] , int deb , int fin);
void Fusioner(int  A[],int deb,int m,int fin);
void triFusion(int n);
void triBulle(int n);
void algoQueen(int n);
void sebset(int n);

double  matrice [12] [500000];
/*
0 = > fib
1 = > fact
2 = > recherche dichotomique
3 = >  //       sequentiel
4 = > tri permutation
5 = > tri insertion
6 = > tri fusion
7 = > tri bulle
8 = > tri rapide
9 = > sous ensemble
10 => queen finding
*/

char functions[12][80] = {"fibonacci.txt",
"factoriel.txt",
"recherche dichotomique.txt",
"recherche sequentiel.txt",
"tri permutation.txt",
"tri insertion.txt",
"tri fusion.txt",
"tri bulle.txt",
"tri rapide.txt",
"subset.txt",
"queen.txt"};

int main(){
    double deb,fin,tempExec,debP,finP,tempExecP;

    int n = 10;//taille par defaults
    char reponse;
    do{
    debP = clock();
    int func;
    printf("\n Choisissez la fonction que vous voulez appeler ?\n (ATTENTION ! N > 10 ve dire toutes les fonctions seront appeler ) \n le resultat des appelles vous le trouvies dans un fichier qui a le meme nom que la fonction\n");
    printf("0 = > fib n<40 \n 1 = > fact n<16 \n 2 = > recherche dichotomique\n 3 = >  //       sequentiel\n 4 = > tri permutation \n 5 = > tri insertion\n 6 = > tri fusion\n 7 = > tri bulle\n 8 = > tri rapide\n 9 = > sous ensemble n<16 \n 10 => queen finding n<35 \n");
    printf("11 => quitter !\n");
    scanf("%d",&func);
    if(func <=10 && func >= 0){
    printf("\n donnez la taille du tableaux ou la valeur initiale  N=%d ?\n" , n);
    scanf("%d",&n);
    }
    if(n>0 && n<50000){
    switch(func){
    case 0: if(n<45) {deb = clock();
            fib(n);
            fin = clock();
            tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
            matrice[0][n] = tempExec;// remplire matrice des temps des executions
            printf("\n temps d'execution de FIBONACCI(n = %d ) est  = %f \n",n,tempExec);
            } break;
    case 1: if(n<16){
            deb = clock(); // calculons pour factoriel
            fact(n);
            fin = clock();
            tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
            printf("\n temps d'execution de FACTORIEL(n = %d ) est  = %f \n",n,tempExec);
            matrice[1][n] = tempExec;
            } break;
    case 2:rechercheDichotomique(n); break;
    case 3:rechercheSequentiel(n);break;
    case 4:triPermutation(n);break;
    case 5:triInsertion(n);break;
    case 6:triBulle(n);break;
    case 7:triFusion(n);break;
    case 8:triRapide(n);break;
    case 9:sebset(n);break;
    case 10:algoQueen(n);break;
    case 11:exit(0);break;
    default:printf("donnez le nombre d'iterations que vous souhaitez faire ( tailles maximal des tableaux des tri < 50,000) a chaque iteration ?\n");
            int iteration;
            scanf("%d",&iteration);
            if(n>0){
                if(iteration<50000 && iteration>0){
                    do{
                        printf("\n TEST POUR n = %d \n",n);
                        if(n < 45 ){
                            //fibo
                            printf("fib de %d est %d ",n,fib(n));
                            deb = clock();
                            fib(n);
                            fin = clock();
                            tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
                            matrice[0][n] = tempExec;// remplire matrice des temps des executions
                            printf("\n temps d'execution de FIBONACCI(n = %d ) est  = %f \n",n,tempExec);

                            //factoriel
                            if(n<16){
                            deb = clock(); // calculons pour factoriel
                            fact(n);
                            fin = clock();
                            tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
                            printf("\n temps d'execution de FACTORIEL(n = %d ) est  = %f \n",n,tempExec);
                            matrice[1][n] = tempExec;
                            algoQueen(n);
                            sebset(n);
                            }
                        }
                        //createAssociatedFile(n,"testComplexite.txt",tempExec);
                        rechercheDichotomique(n);
                        rechercheSequentiel(n);
                        triPermutation(n);
                        triInsertion(n);
                        triFusion(n);
                        triBulle(n);
                        triRapide(n);

                        n+=100;
                     }while (n < 50000 && n > 0 );
                }
         }
         break;
         }
    }

    finP = clock();
    tempExecP = ((double)(finP-debP))/CLOCKS_PER_SEC;


    int j=0;//which function to print the graph of
    if(func > 10 ){
        for(j=0;j<11;j++){
            int k;
            FILE * fptr;
            fptr = fopen(functions[j],"w");
            for(k=10;k<n+1;k+=100){
                printf("temps execution de fonction %s , pour n=%d , est %f \n",functions[j],k,matrice[j][k]);
                printf("%f\n",matrice[j][k]);
                fprintf(fptr,"%f",matrice[j][k]);
                fprintf(fptr,"\n");


            }
            fclose(fptr);
        }
    }
    else {

        FILE * fptr;
        fptr = fopen(functions[func],"w");
            printf("temps execution de fonction %s , pour n=%d , est %f \n",functions[func],n,matrice[func][n]);
            printf("%f\n",matrice[func][n]);
            fprintf(fptr,"%f",matrice[func][n]);
            fprintf(fptr,"\n");

        fclose(fptr);
        }


    printf("le temps d'execution de toute le programme  en secondes est de : %f\n",tempExecP);
    printf("------------------------------------------------------");
    printf("\nvoulez vous faire autre chose ? O:oui, N:non \n");
    scanf("%c",&reponse);
    }while(reponse !='N' || reponse != 'n');
    return 0;
}

void createFile(char  str[],char  f[], double time){
        printf("declaring file ");
        FILE * fptr;
        int i = 0 ;
        fptr = fopen(f, "w+a"); // "w" defines "writing mode" "a" appending mode
        printf("file opened");
        for (i = 0; str[i] != '/'; i++) {
            // write to file using fputc() function
            fprintf( fptr, str[i]);
        }
        printf("file writing... ");
        fprintf(fptr,"%f",time);
        fprintf(fptr," secondes.");
        printf("closing file");
        // a problem is here causing the program to crash
        fclose(fptr);
}

int fib(int a ){

    if(a == 1) return 1;
    if (a == 0) return 1;
    return fib(a-1)+fib(a-2);
}

void fact(int n){
    int f,i;
    f=1;
    for(i=2;i<=n;i++) f=f*i;
    printf("fact = %d ",f);


}

void createAssociatedFile(int n,char  name[], double tempExec){

        char str[] = "\n temps d'exectution pour n =  ";
        char arr[sizeof(n)];
        strcat(str, "est de : /");
        strcat(str, "are ");
        createFile(str ,name,tempExec );

}

void rechercheSequentiel(int n){


     int A[500000]; /* tableau donné */
     int val;   /* valeur à rechercher   */
     int pos;   /* position de la valeur */
     //int n;     /* dimension      */
     int i;     /* indice courant */


     printf("\nDimension du tableau RECHERCHE SEQUENTIEL (max.500000) : ");
     printf("\n n = %d \n", n );
     for (i=0; i<n; i++)
        {
          A[i] = rand() % 500000;
        }
     printf("\nDonnez l element a rechercher : ?");
     val = n;
     printf("\n %d \n ", val );
     /* Affichage du tableau
     printf("Tableau donné : \n");
     for (i=0; i<n; i++)
         printf(" %d, ", A[i]);
     */
     double debR = clock();
     pos = -1;
     for (i=0 ; (i<n)&&(pos==-1) ; i++)
           if (A[i]==val)
               pos=i;
      /* Edition du résultat */
     if (pos==-1)
         printf("\n La valeur recherchée ne se trouve pas "
                "dans le tableau.\n");
      else
         printf("\n La valeur %d se trouve à la position %d. \n",
     val, pos);
     double finR = clock();
     double tempsExec = (double)(finR-debR)/CLOCKS_PER_SEC;
     matrice[3][n] = tempsExec;
     printf(" \n temps estime a la recherche sequent dans le tableau de taille de %d \n est %f " ,n,tempsExec);

}

void rechercheDichotomique(int n){

     int A[199999]; /* tableau donné */
     int val;   /* valeur à rechercher   */
     int pos;   /* position de la valeur */
     // int n;     /* dimension      */
     int i,j;     /* indice courant */
     int inf, mil, sup; /* limites du champ de recherche */
     int temp,FIN;

     printf("\n Dimension du tableau POUR RECHERCHER DICHOTOMIQUE (max.500000) : ");
     printf("\n n= %d \n ", n );
     for (i=0; i<n; i++)
        {
          A[i] = rand() % 1000000;
        }
     printf("\n Donnez l element a rechercher RD : ?");
     val = rand() % n;
     printf("\n %d \n ", val );
     /* Affichage du tableau
     printf("Tableau donné : \n");
     for (i=0; i<n; i++)
         printf(" %d, ", A[i]);
     */
     // trier
     for (i=n-1 ; i>0 ; i=FIN)
         {
          FIN=0;
          for (j=0; j<i; j++)
                if (A[j]>A[j+1])
                {
                 FIN=j;
                 temp=A[j];
                 A[j]=A[j+1];
                 A[j+1]=temp;
                }
         }

     inf=0;
     sup=n-1;
     /* debut recherche  */
     double debR = clock();
     //Sleep(1);
     pos=-1;
     while ((inf<=sup) && (pos==-1))
            {
             mil=(sup+inf)/2;
             if (val < A[mil])
                   sup=mil-1;
             else if (val > A[mil])
                   inf=mil+1;
             else
                   pos=mil;
            }

      /* Edition du résultat */
     if (pos==-1)
         printf("\n La valeur recherchée ne se trouve pas "
                "dans le tableau.\n");
     else
         printf(" \n La valeur %d se trouve à la position %d. \n",
     val, pos);
     double finR = clock();
     double tempsExec = (double)(finR-debR)/CLOCKS_PER_SEC;
     matrice[2][n] = tempsExec;
     printf("\n temps estime a la recherche dichotomique dans le tableau de taille de %d est %f \n" ,n,tempsExec);

}

void triPermutation(int n){
        /* Déclarations */
     int A[500000]; /* tableau donné */
     int i;     /* rang à partir duquel A est trié */
     int j;     /* indice courant      */
     int temp;  /* pour la permutation */
     int fin;   /* position où la dernière permutation a eu lieu. */
            /* permet de ne pas trier un sous-ensemble déjà trié. */

     /* Saisie des données */
     printf("\n Dimension du tableau Pour Tri PAR PERMUTATION (max.500000) : ");
     printf(" %d ", n );
     for (j=0; j<n; j++)
         A[j] = rand() % 500000;

     /* Affichage du tableau
     printf("\nTableau donné :\n");
     for (j=0; j<n; j++)
        printf("%d ,", A[j]);
     printf("\n");
     */
     /* Tri du tableau par propagation de l'élément maximal. */
     double debT = clock();
     for (i=n-1 ; i>0 ; i=fin)
         {
          fin=0;
          for (j=0; j<i; j++)
                if (A[j]>A[j+1])
                {
                 fin=j;
                 temp=A[j];
                 A[j]=A[j+1];
                 A[j+1]=temp;
                }
         }

     double finT = clock();
     double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
     matrice[4][n] = tempsExec;
     printf("\n temps estime de tri par permutation dans le tableau de taille de %d est %f \n" ,n,tempsExec);


}
// pour le tri fusion
typedef int * Tableau;
     Tableau A;
     Tableau Tmp;

void triFusion(int n){

     /* Déclarations */

     A =(int *)malloc(n*sizeof(int));
     Tmp =(int *)malloc(n*sizeof(int));
     int j;
     /* Saisie des données */
     printf("\n Dimension du tableau Pour Tri PAR Fusion (max.500000) : \n");
     printf(" %d \n", n );

     for (j=0; j<n-1; j++)
         A[j] = rand() % 50000;
     printf("\nTableau donné :\n");
     for (j=0; j<n-1; j++)
        printf("%d ,", A[j]);
     printf("\n");

        //call


        double debT = clock();
        fusionTri(A,0,n-1);
        double finT = clock();
         double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
         matrice[6][n] = tempsExec;
         printf("%f \n",tempsExec);

     printf("\nTableau tri apres fusion :\n");
     for (j=0; j<n-1; j++)
        printf("%d ,", A[j]);
     printf("\n");



}

void triBulle(int n){

    /* Déclarations */
     int A[500000]; /* tableau donné */
     int j,i,tmp,flag;
     /* Saisie des données */
     //printf("\n Dimension du tableau Pour Tri Bulle (max.500000) : ");
     //printf(" %d ", n );
     for (j=0; j<n; j++)
         A[j] = rand() % 500000;
    /* Affichage du tableau */
     /*printf("Tableau donné :\n");
     for (j=0; j<n; j++)
        printf("%d ", A[j]);
     printf("\n");
    */
    /* Tri du tableau par sélection directe du maximum. */
     double debT = clock();
    for(i=0; i<n; i++){
        flag=0;
        for(j=0; j<n-i-1; j++){
           if( A[j] > A[j+1]){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                flag = 1;         //setting flag as 1, if swapping occurs
           }
        }
        if(!flag){             //breaking out of for loop if no swapping takes place
           break;
        }
     }
     double finT = clock();
     double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
     matrice[7][n] = tempsExec;
     printf("%f \n",tempsExec);
     //printf("\n temps estime de tri Bulle dans le tableau de taille de %d est %f \n" ,n,tempsExec);


}



void triInsertion(int n){
    /* Déclarations */
     int A[50000]; /* tableau donné */
     int i;     /* rang à partir duquel A n'est pas trié */
     int j;     /* indice courant      */
     int temp;  /* pour la permutation */
     int max;  /* indique la position de l'élément */
                /* maximal à droite de A[I]         */

     /* Saisie des données */
     printf(" tableau tri insertion (max.50000) : n = %d \n ",n);
     for (j=0; j<n; j++)
        {
         A[j] = rand() % n;
        }
     /* Affichage du tableau */
     /*printf("Tableau donné :\n");
     for (j=0; j<n; j++)
        printf("%d ", A[j]);
     printf("\n");
    */
    /* Tri du tableau par sélection directe du maximum. */
     double debT = clock();
     for (i=0; i<n-1; i++)
         {//printf("recherche %d \n",i);
          /* Recherche du maximum à droite de A[I] */
          max=i;//printf(" max = %d\n",i);
          for (j=i+1; j<n; j++){
              if (A[j]>A[max]) max=j;
              //printf("permutation %d\n",i);
              }
              //printf("%d\n",i);
          /* Echange de A[I] avec le maximum */
          temp=A[i];
          A[i]=A[max];
          A[max]=temp;
         }
     double finT = clock();
     double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
     matrice[5][n]= tempsExec;
     /* Edition du résultat */
     /*printf("Tableau trié :\n");
     for (j=0; j<n; j++)
         printf("%d ", A[j]);
     printf("\n");
    */
}

Tableau B;
void triRapide(int n){
    /* Déclarations */
     int i;     /* rang à partir duquel A n'est pas trié */
     int j;     /* indice courant      */
     int temp;  /* pour la permutation */
     int max;  /* indique la position de l'élément */
                /* maximal à droite de A[I]         */
     B=(long *)malloc(n*sizeof(int));
     /* Saisie des données */
     printf(" tableau tri insertion (max.50000) : n = %d \n ",n);
     for (j=0; j<n-1; j++)
        {
         B[j] = rand() % n;
        }
     /* Affichage du tableau */
     printf("Tableau donné :\n");
     for (j=0; j<n-1; j++)
        printf("%d ", B[j]);
     printf("\n");

    /* Tri du tableau par sélection directe du maximum. */
     double debT = clock();

     quickSort(B,0,n-1);

     double finT = clock();
     double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
     matrice[8][n]= tempsExec;
     /* Edition du résultat */
     printf("Tableau trié :\n");
     for (j=0; j<n-1; j++)
         printf("%d ", B[j]);
     printf("\n");

}

//fusion
fusion(Tableau A, int deb1,int fin1,int deb2,int fin2){
   int i = deb1;
   int j = deb2;
   int  k = 0;
   while (i<=fin1 && j<=fin2){
   	if (A[i] < A[j]){
	   Tmp[k] = A[i];
	   i++;
	   k++;
	   }
	else{
	   Tmp[k] = A[j];
	   k++;
	   j++;}
    }
   while (i<=fin1) {Tmp[k] = A[i]; k++;i++;}
   while (j<=fin2) {Tmp[k] = A[j]; k++; j++;}

   for (j=0; j<k; j++)
	A[deb1+j] = Tmp[j];
}

//tri fusion;
void fusionTri(Tableau A, int deb, int fin)
{
   int mil,i,j;
   if (deb>=fin) return;
   mil = (deb+fin)/2;
   fusionTri(A,deb,mil);
   fusionTri(A,mil+1,fin);
   fusion(A,deb,mil,mil+1,fin);
}


void sebset(int n){

//right answer = {1, 2, 7, 98, 343, 686, 2409, 17206, 117705}
    int target = rand()%n;
    int ROW = n;
	int i, j, l, COLOMN = pow(2, ROW);

    char d[ROW][COLOMN];
    int e[ROW];
    for (i = 0; i < ROW; i++){
        e[i]=rand()%n;
    }

    double debT = clock();
     for (i = 0; i < ROW; i++){
        for (j = 0; j < COLOMN; j++){
            strcpy(d[i], "");
        }
    }

    i = 0;
    while (i < ROW){
        int j, c = pow(2, i); // C is a counter for 0 || 1 output, and J is for the loop

        for (j = 0; j < COLOMN; j++){
            if (c > 0){
                strcat(d[i], "0"); //The resulted ROW array is something like this: "01010101" on first bit

                c--;
                if (c == 0) c = -pow(2, i);
            }
            else if(c < 0){
                strcat(d[i], "1");

                c++;
                if (c == 0) c = pow(2, i);
            }
        }

        i++;
    }

    // Outputting the resulted Matrix and Sub-sets

    printf("S = {");
    for(i = 0; i < ROW; i++){
        if(i == ROW - 1){ printf("%d", e[i]); }
        else{ printf("%d, ", e[i]); }
    };
    printf("}\n\n");

    printf("t = %d\n\n", target); // target t = 138457
   // printf("Subset solutions: \n\n");

    int found = 0, solution[14]; // Found indicates whether a valid solution has been found, and solution is an array that hold the subset solution
    for (j = 0; j < COLOMN; j++){ // ROWs and COLOMNs are inverted in this algorithm for C Language string operation limits

        // Outputting 0/1 Matrix
//        printf("{");
//            for (i = 0; i < ROW; i++){
//                printf("%c", d[i][j]);
//            }
//        printf("}\n");

//         Sub-sets

        int sum = 0; // Reset sum each time j changes in value (meaning, next iteration)
        found = 0;
        // using the 0/1 Matrix to determine the items of potential solutions
        for (i = 0; i < ROW; i++){
            if(d[i][j] == '1'){ // 1 means append that item to the list
                sum = sum + e[i]; // Sum up the items of the potential solution
                solution[i] = e[i]; // Append each item to the solution array
                if (sum > target){ break; } // break if the sum of the items currently on the solution array is > than target
            }
            else{
                solution[i] = 0; // Append 0 if the current bit is "0"
            }

        }
//        printf("}\n");

        if (sum == target){
            found = 1; // Solution is found
            printf("t  trouve\n");
            //Output Solution
            /*if (found){
                printf("S' = { ");
                for (i = 0; i <= ROW - 1; i++){
                    if(solution[i] != 0){
                        printf("| %d |", solution[i]);
                    }
                }
                printf("}\n\n");

            }*/
        }

    }
    double finT = clock();
    double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
    matrice[9][n]= tempsExec;

}




void quickSort(Tableau a, int first, int last)
{

//     printf("partition !\n");
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quickSort(a,first,j-1);
      quickSort(a,j+1,last);

   }


}


//queen
int FOUND = 0;
void algoQueen(int n){

    int m = 2*n - 1; // number of diagonals in (SIZE, SIZE0 board
    int board[n][n], diag1[2*n- 1], diag2[2*n- 1], col[n];
    // COL: columns of the board
    // diag1, diag2: hold the diagonals of each board cell

    int (*boardTemp)[n];
    boardTemp = board;

    int (*pmat)[n];
    pmat = board;

    double debT = clock();
    queen(0, col, diag1, diag2,n,boardTemp); // res: whether or not a solution found 0/1
    if (FOUND == 0){
        printf("No solution was found for this board of size %d\n", n);
    }
    else
    printf("There are %d solutions for this board of size %dx%d\n", FOUND, n, n);

    double finT = clock();
    double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
    matrice[10][n]= tempsExec;


}


int queen(int q, int *col[], int *diag1[], int *diag2[], int n,int *board[][n]){
    //q: queen
    int res;
    // array pointers to preserve state until success
    int *d1, *d2, *c;
    int (*b)[n]; // b: board

    b = board;
    d1 = diag1;
    d2 = diag2;
    c = col;

    //printf("//////////// QUEEN FUNCTION //////////\n\n");

//    printf("This is D1\n");
//    printArray(d1, 2*SIZE - 1);
//    printf("This is D2\n");
//    printArray(d2, 2*SIZE -1);
//    printf("This is Column\n");
//    printArray(c, SIZE);
//    printf("This is Board\n");
//    printBoard(b, SIZE);
//    printf("\n\n");

    if ( q < n){
        res = placeQueen(q, c, d1, d2,n, b);
        if (res) return 1;
        else{
            //printf("ERROR: Queen = %d\n", q);

            return 0;
        }

    } else return 1;
//    board = b;
//    diag1 = d1;
//    diag2 = d2;
//    col = c;
}


int placeQueen(int q, int *column[], int *diagonal1[], int *diagonal2[], int n,int *board[][n]){
    int j, d1, d2, c, res;
    int *diag1, *diag2, *col;
    int (*b)[n]; // b: board
    b = board;
    diag1 = diagonal1;
    diag2 = diagonal2;
    col = column;

//    printArray(diag1, 15);
//
//    printBoard(board, 8);

    //printf("////////////// PLACE QUEEN FUNCTION ////////////////\n\n");

    for (j = 0; j < n; j++){
        // We check the diagonal arrays to determine if a given cell is occupied
        d1 = diag1[q+j];
        d2 = diag2[q -j+n-1]; //descending diagonal
        c = col[j]; // column number j

        if((d1 == 0)&&(d2 == 0)&&(c == 0)){ // if cell is empty
            b[q][j] = q + 1; // place queen number q at cell (q, j)

//            printf("\nd1[q+j=%2d+%2d=%2d] = %2d\nd2[q-j+SIZE-1=%2d-%2d+%d-%d=%2d] = %2d\nc[j=%2d] = %d\n",q, j, q+j, d1, q, j, SIZE, 1, q-j+SIZE-1, d2, j, c);
//            printf("q = %d j = %d\n", q, j);
//            printf("board[%d][%d] = %d\n\n", q, j, *(*(b + q) + j));
//
            //printf("NOW NOW %d\n", b[q][j]);
            diag1[q+j] = diag2[q-j+n-1] = col[j] = 1;
            res = queen(q+1, column, diagonal1, diagonal2, n,board);

            if(res) {
                //printf("res = %2d || Queen = %2d\n\n", res, q);

                board = b;
                diagonal1 = diag1;
                diagonal2 = diag2;
                column = col;
                if((q == n-1)){
                    FOUND++;
//                    printf("------------------------\nSOLUTION %d Q = %2d | J = %2d\n------------------------\n\n", FOUND, q+1, j);
//                    printBoard(board, SIZE);
//                    printf("\n\n");
                    memset(b[q], 0, sizeof(b[q])); // reset array when solution not found
                    diag1[q+j] = 0;
                    diag2[q-j+n-1] = 0;
                    col[j] = 0;
                    return 0;
                }
                else if(q==0){
                    memset(board, 0, sizeof(board[0][0])*n*n); // reset array when solution not found
                    memset(diagonal1, 0, sizeof(diagonal1[0])*(2*n- 1)); // reset array when solution not found
                    memset(diagonal2, 0, sizeof(diagonal2[0])*(2*n- 1)); // reset array when solution not found
                    memset(column, 0, sizeof(column[0])*n); // reset array when solution not found
                }
                else{ return 1;}
            } else{
//                printf("----------------------------\nNOT GONNA WORK\nQueen = %2d\n\n", q+1);
//                printf("\nd1[q+j=%2d+%2d=%2d] = %2d\nd2[q-j+SIZE-1=%2d-%2d+%d-%d=%2d] = %2d\nc[j=%2d] = %d\n",q, j, q+j, d1, q, j, SIZE, 1, q-j+SIZE-1, d2, j, c);
//                printf("q = %2d j = %2d\n", q, j);
//                printf("----------------------------\n");
//
                memset(b[q], 0, sizeof(b[q])); // reset array when solution not found
                diag1[q+j] = 0;
                diag2[q-j+n-1] = 0;
                col[j] = 0;
            }
        }
    }
    return 0;
}
