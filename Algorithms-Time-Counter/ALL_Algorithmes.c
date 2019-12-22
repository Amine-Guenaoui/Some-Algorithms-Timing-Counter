#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define MILLI_S 1000.0

//travaille de TP COMPLEXITE MIV
// AMINE GUENAOUI
// BLIDI FAROUK

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

double  matrice [12][500000];
/*
0 = > fib
1 = > fact
2 = > recherche dichomotique
3 = >  //       sequentiel
4 = > tri permutation
5 = > tri insertion
6 = > tri fusion
7 = > tri bulle
8 = > tri rapide
9 = > sous ensemble
10 => queen finding
*/

char functions[12][80] = {
    "fibonacci.txt",
    "factoriel.txt",
    "recherche dichotomique.txt",
    "recherche sequentiel.txt",
    "tri permutation.txt",
    "tri insertion.txt",
    "tri fusion.txt",
    "tri bulle.txt",
    "tri rapide.txt",
    "subset.txt",
    "queen.txt"
};

int main(){
    double deb,fin,tempExec,debP,finP,tempExecP;

    int n = 10;//taille par defaults

    debP = clock();
    int func;
    printf("\nChoisissez la fonction que vous voulez appeler.\n\n");
    printf("ATTENTION !\n"
           "-----------\n"
           "N > 10 veut dire que toutes les fonctions seront appellees\n"
           "Le resultat des appelles vous le trouvrez dans un fichier qui a le meme nom que la fonction.\n"
           "--------------------------------------------------------------------------------------------\n\n");

    printf("0 = > Fibonacci (N < 40)\n"
           "1 = > Factoriel (N < 16) \n"
           "2 = > Recherche Dichomotique\n"
           "3 = >  // Sequentiel\n"
           "4 = > Tri-Permutation \n"
           "5 = > Tri-Insertion\n"
           "6 = > Tri-Fusion\n"
           "7 = > Tri-Bulle\n"
           "8 = > Tri-Rapide\n"
           "9 = > Sous-Ensemble (N < 16)\n"
           "10 => Problème des 8-Reines (N < 35)\n");
    printf("\n--------------\n");
    printf("11 => Quitter.\n");
    scanf("%d",&func);
    if((func < 9) || (func == 10)){
        printf("\nDonnez la taille du tableaux ou la valeur initiale: N = %d ?\nN = ", n);
        scanf("%d", &n);
    }
    switch(func){
    case 0: if(n < 45) {
        printf("\n\n//////////////////////////////////////////////////////////////////////////////////////////////\n"
           "///////////////////////////////////////// FIBONACCI //////////////////////////////////////////\n"
           "/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n\n");
        deb = clock();
        int res = fib(n);
        printf("Fibonacci(%d) = %5d\n", n, res);
        fin = clock();
        tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
        matrice[0][n] = tempExec;// remplire matrice des temps des executions
        printf("\n  - Temps d'execution de FIBONACCI(N = %d) est  = %f \n\n", n, tempExec);

        printf("\n"
            "///////////////////////////////////////// FIBONACCI //////////////////////////////////////////\n"
            "//////////////////////////////////////////// FIN /////////////////////////////////////////////\n"
            "//////////////////////////////////////////////////////////////////////////////////////////////\n"
            "\n\n");
        } break;
    case 1: if(n<16){
        printf("\n\n//////////////////////////////////////////////////////////////////////////////////////////////\n"
           "///////////////////////////////////////// FACTORIEL //////////////////////////////////////////\n"
           "/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n\n");

        deb = clock(); // calculons pour factoriel
        fact(n);
        fin = clock();
        tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
        printf("\n  - Temps d'execution de FACTORIEL(N = %d) est  = %f \n\n", n, tempExec);
        matrice[1][n] = tempExec;
        printf("\n"
            "///////////////////////////////////////// FACTORIEL //////////////////////////////////////////\n"
            "//////////////////////////////////////////// FIN /////////////////////////////////////////////\n"
            "//////////////////////////////////////////////////////////////////////////////////////////////\n"
            "\n\n");
        } break;
    case 2:rechercheDichotomique(n); break;
    case 3:rechercheSequentiel(n);break;
    case 4:triPermutation(n);break;
    case 5:triInsertion(n);break;
    case 6:triFusion(n);break;
    case 7:triBulle(n);break;
    case 8:triRapide(n);break;
    case 9:sebset(14);break;
    case 10:algoQueen(n);break;
    case 11:exit(0);break;
    default:printf("donnez le nombre d'iterations que vous souhaitez faire (La tailles maximal des tableaux des tri est < 50,000) a chaque iteration.\n"
                   "Nombre d'iteration = ");
            int iteration;
            scanf("%d",&iteration);
            if(iteration<50000){
            do{
            printf("\nTEST POUR n = %d \n",n);
            if(n < 45 ){
                // Fiboonacci
                printf("Fibonacci de %d est %d ", n, fib(n));
                deb = clock();
                fib(n);
                fin = clock();
                tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
                matrice[0][n] = tempExec;// remplire matrice des temps des executions
                printf("\n  - Temps d'execution de FIBONACCI(N = %d) est  = %f \n\n", n, tempExec);

                // Factoriel
                if(n<16){
                deb = clock(); // calculons pour factoriel
                fact(n);
                fin = clock();
                tempExec = ((double)(fin-deb))/CLOCKS_PER_SEC;
                printf("\n  - Temps d'execution de FACTORIEL(N = %d) est  = %f \n\n", n, tempExec);
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

            n += 100;
         }while (n < 50000 && n != -1 ); }
         break;
         }

    finP = clock();
    tempExecP = ((double)(finP-debP))/CLOCKS_PER_SEC;


    int j=0;//which function to print the graph of
    if(func > 10 ){
        for(j=0;j<11;j++){
            int k;
            FILE * fptr;
            fptr = fopen(functions[j],"w");
            for(k=10; k<n+1 ; k+=100){
                printf("Temps execution de la fonction %s, pour N = %d, est %f \n\n", functions[j], k, matrice[j][k]);
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
        printf("  - Temps execution de la fonction %s, pour N = %d, est %f \n\n", functions[func], n, matrice[func][n]);
//        printf("%f\n",matrice[func][n]);
        fprintf(fptr, "%f", matrice[func][n]);
        fprintf(fptr,"\n");

        fclose(fptr);
    }

    printf(
        "\n//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "//////// Le temps d'execution de toute le programme en secondes est de : %10f //////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n\n\n", tempExecP);

    printf("1 => Menu Pricipale\n"
           "0 => Quitter\n\n"
           "Votre choix: ");
    scanf("%d",&func);
    switch(func){
        case 0:
            exit(0);
        case 1:
             system("cls");
            main();
        default:
            exit(0);
    }
    return 0;
}

void createFile(char  str[],char  f[], double time){
        printf("File declaration");
        FILE * fptr;
        int i = 0 ;
        fptr = fopen(f, "w+a"); // "w" defines "writing mode" "a" appending mode
        printf("File Opened");
        for (i = 0; str[i] != '/'; i++) {
            // write to file using fputc() function
            fprintf( fptr, str[i]);
        }
        printf("Writing... ");
        fprintf(fptr,"%f",time);
        fprintf(fptr,"Seconds.");
        printf("File closed");
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
    f = 1;
    for(i = 2;i <= n; i++) f=f*i;
    printf("%d! = %5d\n",n, f);
}

void createAssociatedFile(int n,char  name[], double tempExec){
        char str[] = "\nTemps d'exectution pour n =  ";
//        char arr[sizeof(n)];
        strcat(str, "est de : /");
        strcat(str, "are ");
        createFile(str ,name,tempExec );

}

void rechercheSequentiel(int n){
    printf("\n\n//////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("/////////////////////////////////// RECHERCHE SEQUENTIELLE ///////////////////////////////////\n");
    printf("/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n\n");
     int A[500000]; /* tableau donné */
     int val;   /* valeur à rechercher   */
     int pos;   /* position de la valeur */
     //int n;     /* dimension      */
     int i;     /* indice courant */

    printf("\nDimension du tableau RECHERCHE SEQUENTIEL (max.500000) : ");
    printf("\nN = %d \n", n);
    for (i=0; i<n; i++)
        A[i] = rand() % 500000;

    val = n;
    // Affichage du valeur recherchee
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 27)/2; i++) printf(" ");
    printf("L'element recherche: %6d", val);
    for (i=0; i<(8*n - 27)/2; i++) printf(" ");
    printf("|\n");

    // TITRE DU TABLEAU
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("Tableau donne");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");


     double debR = clock();
     pos = -1;
     for (i=0 ; (i<n)&&(pos==-1) ; i++)
           if (A[i]==val)
               pos=i;
      /* Edition du résultat */
     if (pos==-1)
         printf("\n  - La valeur recherchée ne se trouve pas dans le tableau.\n");
      else
         printf("\n  - La valeur %d se trouve à la position %d. \n",
     val, pos);
     double finR = clock();
     double tempsExec = (double)(finR-debR)/CLOCKS_PER_SEC;
     matrice[3][n] = tempsExec;
     printf("\n  - Temps estime a la recherche sequentielle dans le tableau de taille de %d est %f \n" , n, tempsExec);

    printf("\n\n/////////////////////////////////// RECHERCHE SEQUENTIELLE ///////////////////////////////////\n");
    printf("/////////////////////////////////////////// FIN //////////////////////////////////////////////\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");
}

void rechercheDichotomique(int n){
    printf("\n\n//////////////////////////////////////////////////////////////////////////////////////////////\n"
           "/////////////////////////////////// RECHERCHE DICHOTOMIQUE ///////////////////////////////////\n"
           "/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n\n");
    int A[199999]; /* tableau donné */
    int val;   /* valeur à rechercher   */
    int pos;   /* position de la valeur */
    // int n;     /* dimension      */
    int i,j;     /* indice courant */
    int inf, mil, sup; /* limites du champ de recherche */
    int temp,FIN;

    printf("\nDimension du tableau POUR RECHERCHER DICHOTOMIQUE (max.500000) : ");
    printf("N = %d\n\n", n );
    for (i=0; i<n; i++)
        A[i] = rand() % 1000000;

    val = rand() % 1000000; // Val: Valeur recherchee au tableau crie

    printf(
        "-----------------------------------------------------------\n"
        "| NOTICE:                                                 |\n"
        "|--------                                                 |\n"
        "| L'element a rechercher en RD est choisit aleatoirement. |\n"
        "-----------------------------------------------------------\n\n");

    // Affichage du valeur recherchee
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 27)/2; i++) printf(" ");
    printf("L'element recherche: %6d", val);
    for (i=0; i<(8*n - 27)/2; i++) printf(" ");
    printf("|\n");

    // TITRE DU TABLEAU
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("Tableau donne");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

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
        printf("\n  . La valeur recherchee ne se trouve pas dans le tableau.\n");
    else
        printf("\n  - La valeur %d se trouve à la position: %d. \n", val, pos);

    double finR = clock();
    double tempsExec = (double)(finR-debR)/CLOCKS_PER_SEC;
    matrice[2][n] = tempsExec;
    printf("\n  - Temps estime a la Recherche Dichotomique dans le tableau de taille de %d est %f\n" , n, tempsExec);

    printf("\n\n/////////////////////////////////// RECHERCHE DICHOTOMIQUE ///////////////////////////////////\n");
    printf("/////////////////////////////////////////// FIN //////////////////////////////////////////////\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");
}

void triPermutation(int n){
    printf("\n\n//////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////// TRI PAR PERMUTATION ////////////////////////////////////\n");
    printf("/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n\n");

        /* Déclarations */
     int A[500000]; /* tableau donné */
     int i;     /* rang à partir duquel A est trié */
     int j;     /* indice courant      */
     int temp;  /* pour la permutation */
     int fin;   /* position où la dernière permutation a eu lieu. */
            /* permet de ne pas trier un sous-ensemble déjà trié. */

     /* Saisie des données */
     printf("\nDimension du tableau Pour TRI PAR PERMUTATION (max.500000) : ");
     printf(" %d ", n );
     for (j=0; j<n; j++)
         A[j] = rand() % 500000;

    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("Tableau donne");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

     /* Tri du tableau par propagation de l'élément maximal. */
     double debT = clock();
     for (i=n-1 ; i>0 ; i=fin){
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

     // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 12)/2; i++) printf(" ");
    printf("Tableau Trie");
    for (i=0; i<(8*n - 12)/2 - 1; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

    printf("\n  - Temps estime de tri par permutation dans le tableau de taille de %d est %f \n" ,n,tempsExec);

    printf("\n\n//////////////////////////////// TRI PAR PERMUTATION /////////////////////////////////////////\n");
    printf("/////////////////////////////////////////// FIN //////////////////////////////////////////////\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");
}
// pour le tri fusion
typedef int * Tableau;
     Tableau A;
     Tableau Tmp;

void triFusion(int n){
    printf("\n\n"
        "//////////////////////////////////////// TRI PAR FUSION //////////////////////////////////////\n"
        "/////////////////////////////////////////// FIN //////////////////////////////////////////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n\n");
    /* Déclarations */

    A =(int *)malloc(n*sizeof(int));
    Tmp =(int *)malloc(n*sizeof(int));
    int j;
    /* Saisie des données */
    printf("\nDimension du tableau Pour Tri PAR Fusion (max.500000) : %d\n", n);

    for (j=0; j<n; j++)
        A[j] = rand() % 50000;

    int i;
    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("Tableau donne");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

    //call
    double debT = clock();
    fusionTri(A,0,n-1);
    double finT = clock();
    double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
    matrice[6][n] = tempsExec;


    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 12)/2; i++) printf(" ");
    printf("Tableau Trie");
    for (i=0; i<(8*n - 12)/2 - 1; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

    printf("\n  - Temps estime de tri par permutation dans le tableau de taille de %d est %f \n" ,n,tempsExec);

    printf("\n\n"
        "//////////////////////////////////////// TRI PAR FUSION //////////////////////////////////////\n"
        "/////////////////////////////////////////// FIN //////////////////////////////////////////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n\n");
}

void triBulle(int n){
    printf("\n\n"
        "/////////////////////////////////////// TRI PAR BULLE ////////////////////////////////////////\n"
        "/////////////////////////////////////////// FIN //////////////////////////////////////////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n\n");
    /* Déclarations */
    int A[500000]; /* tableau donné */
    int j,i,tmp,flag;
    /* Saisie des données */
    //printf("\n Dimension du tableau Pour Tri Bulle (max.500000) : ");
    //printf(" %d ", n );
    for (j=0; j<n; j++)
        A[j] = rand() % 500000;


    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("Tableau donne");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");


    /* Tri du tableau par sélection directe du maximum. */
    double debT = clock();
    for(i=0; i<n; i++){
        flag=0;
        for(j=0; j<n-i-1; j++){
           if( A[j] > A[j+1]){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                flag = 1;           //setting flag as 1, if swapping occurs
           }
        }
        if(!flag) break;            //breaking out of for loop if no swapping takes place

    }
    double finT = clock();
    double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
    matrice[7][n] = tempsExec;

    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 12)/2; i++) printf(" ");
    printf("Tableau Trie");
    for (i=0; i<(8*n - 12)/2 - 1; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

    printf("\n  - Temps estime de tri Bulle dans le tableau de taille de %d est %f \n" , n, tempsExec);

    printf("\n\n"
        "/////////////////////////////////////// TRI PAR BULLE ////////////////////////////////////////\n"
        "/////////////////////////////////////////// FIN //////////////////////////////////////////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n\n");
}



void triInsertion(int n){
    printf("\n\n//////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("//////////////////////////////////// TRI PAR INSERTION ///////////////////////////////////////\n");
    printf("/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n\n");
    /* Déclarations */
     int A[50000]; /* tableau donné */
     int i;     /* rang à partir duquel A n'est pas trié */
     int j;     /* indice courant      */
     int temp;  /* pour la permutation */
     int max;  /* indique la position de l'élément */
                /* maximal à droite de A[I]         */

     /* Saisie des données */
     printf("Tableau tri insertion (max.50000) : N = %d \n ",n);
     for (j=0; j<n; j++)
         A[j] = rand() % n;


    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("Tableau donne");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");


    /* Tri du tableau par sélection directe du maximum. */
     double debT = clock();
     for (i=0; i<n-1; i++){
        //printf("recherche %d \n",i);
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

    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 12)/2; i++) printf(" ");
    printf("Tableau Trie");
    for (i=0; i<(8*n - 12)/2 - 1; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=n-1; i>=0; i--) printf("%6d |", A[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

    printf("\n  - Temps estime de tri Bulle dans le tableau de taille de %d est %f \n" , n, tempsExec);

    printf("\n\n///////////////////////////////////// TRI PAR INSERTION //////////////////////////////////////\n");
    printf("/////////////////////////////////////////// FIN //////////////////////////////////////////////\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");
}

Tableau B;
void triRapide(int n){
    printf("\n\n//////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////// TRI RAPIDE /////////////////////////////////////////\n");
    printf("/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n\n");
    /* Déclarations */
    int i;     /* rang à partir duquel A n'est pas trié */
    int j;     /* indice courant      */
    int temp;  /* pour la permutation */
    int max;  /* indique la position de l'élément */
            /* maximal à droite de A[I]         */
    B = (long *)malloc(n*sizeof(int));

    printf("Tableau Rapide (max.50000) : N = %d \n ",n);
    /* Saisie des données */
    for (j=0; j<n; j++)
        B[j] = rand() % n;

    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("Tableau donne");
    for (i=0; i<(8*n - 13)/2; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", B[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");


    /* Tri du tableau par sélection directe du maximum. */
    double debT = clock();

    quickSort(B,0,n-1);

    double finT = clock();
    double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
    matrice[8][n]= tempsExec;

    // TITRE DU TABLEAU
    printf("\n");
    for (i=0; i<8*n + 1; i++) printf("-");
    printf("\n|");
    for (i=0; i<(8*n - 12)/2; i++) printf(" ");
    printf("Tableau Trie");
    for (i=0; i<(8*n - 12)/2 - 1; i++) printf(" ");
    printf("|\n");

    // Affichage du tableau
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n|");
    for (i=0; i<n; i++) printf("%6d |", B[i]);
    printf("\n");
    for (i=0; i<n; i++) printf("+-------");
    printf("+\n");

    printf("\n\n"
        "//////////////////////////////////////// TRI RAPIDE //////////////////////////////////////////\n"
        "/////////////////////////////////////////// FIN //////////////////////////////////////////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n\n");
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
    printf("\n\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "////////////////////////////////////// SOUS-ENSEMBLE /////////////////////////////////////////\n"
        "////////////////////////////////////////// DEBUT /////////////////////////////////////////////\n"
        "\n\n");
    //right answer = {1, 2, 7, 98, 343, 686, 2409, 17206, 117705}
    int target = 138457;
    int ROW = n;
	int i, j, l, COLUMN = pow(2, ROW);

    char d[ROW][COLUMN];
    int e[14] = {1, 2, 7, 14, 49, 98, 343, 686, 2409, 2793, 16808, 17206, 117705, 117993};

    double debT = clock();
    memset(d, 0, sizeof(char)*ROW*COLUMN); // reset array when solution not found

    i = 0;
    while (i < ROW){
        int j, c = pow(2, i); // C is a counter for 0 || 1 output, and J is for the loop

        for (j = 0; j < COLUMN; j++){
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
        if(i == ROW - 1) printf("%d", e[i]);
        else printf("%d, ", e[i]);
    };
    printf("}\n\n");

    //printf("t = %d\n\n", target); // target t = 138457

    printf("Please enter the value of t = ");
    scanf("%d", &target);
    printf("\n");

   // printf("Subset solutions: \n\n");
    int solNum = 0;
    int found = 0, solution[14]; // Found indicates whether a valid solution has been found, and solution is an array that hold the subset solution
    for (j = 0; j < COLUMN; j++){ // ROWs and COLOMNs are inverted in this algorithm for C Language string operation limits

        // Outputting 0/1 Matrix
//        printf("{");
//            for (i = 0; i < ROW; i++){
//                printf("%c", d[i][j]);
//            }
//        printf("}\n");

//         Sub-sets

        int sum = 0; // Reset sum each time j changes in value (meaning, next iteration)
        // using the 0/1 Matrix to determine the items of potential solutions
        for (i = 0; i < ROW; i++){
            if(d[i][j] == '1'){ // 1 means append that item to the list
                sum = sum + e[i]; // Sum up the items of the potential solution
                solution[i] = e[i]; // Append each item to the solution array
                if (sum > target) break;  // break if the sum of the items currently on the solution array is > than target
            }
            else{
                solution[i] = 0; // Append 0 if the current bit is "0"
            }

        }
//        printf("}\n");

        if (sum == target){ // Solution is found
            found = 1;
            if(found){
                solNum++;
                //Output Solution
                printf("S%d = {", solNum);
                for (i = 0; i < ROW - 1; i++){
                    if(solution[i] != 0){
                        printf(" %d ", solution[i]);
                    }
                }
                if (solution[ROW - 1] != 0) printf(" %d }\n\n", solution[ROW - 1]);
                else printf("}\n\n");
            }
        }

    }
    if(!found) printf("  - No solutions found for target = %d\n\n", target);

    double finT = clock();
    double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
    matrice[9][n]= tempsExec;

    printf("\n\n"
        "/////////////////////////////////////// SOUS-ENSEMBLE ////////////////////////////////////////\n"
        "/////////////////////////////////////////// FIN //////////////////////////////////////////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n\n");
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


// Probleme des 8 Reines
void algoQueen(int n){
    printf("\n\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "///////////////////////////////////////// 8 QUEENS ///////////////////////////////////////////\n"
        "/////////////////////////////////////////// DEBUT ////////////////////////////////////////////\n"
        "\n\n");

    int board[n][n],
        diag1[2*n-1],
        diag2[2*n-1],   // diag1, diag2: hold the diagonals of each board cell
        col[n];         // COL: columns of the board

    memset(board, 0, sizeof(board[0][0])*n*n); // reset array when solution not found
    memset(diag1, 0, sizeof(diag1[0])*(2*n - 1)); // reset array when solution not found
    memset(diag2, 0, sizeof(diag2[0])*(2*n - 1)); // reset array when solution not found
    memset(col, 0, sizeof(col[0])*n); // reset array when solution not found

    int (*boardTemp)[n];
    boardTemp = board;


    double debT = clock();

    int FOUND = queen(0, col, diag1, diag2, n, boardTemp); // res: whether or not a solution found 0/1

    double finT = clock();
    double tempsExec = (double)(finT-debT)/CLOCKS_PER_SEC;
    matrice[10][n]= tempsExec;

    if (FOUND){
        // For GUI purposes
            int i;
            printf("\n+");
            for(i = 0; i < 4*n-1; i++) printf("-");
            printf("+\n|");
            for(i = 0; i < (4*n - 14)/2; i++) printf(" ");
            printf("FIRST SOLUTION");
            for(i = 0; i < (4*n - 14)/2 - 1; i++) printf(" ");
            printf("|\n");
        //////////////////////////////////////////////

        printBoard(n, boardTemp);
        printf("\n");
    }
    else printf("No solution was found for this board of size %d\n\n", n);

    printf("\n  - Temps estime d'execution pour taille de matrice (%d, %d) est %f \n" , n, n, tempsExec);
    printf("\n\n"
        "//////////////////////////////////////// 8 QUEENS ////////////////////////////////////////////\n"
        "/////////////////////////////////////////// FIN //////////////////////////////////////////////\n"
        "//////////////////////////////////////////////////////////////////////////////////////////////\n"
        "\n\n");
}

int queen(int q, int *col[], int *diag1[], int *diag2[], int n, int *board[][n]){
    //q: queen
    int res;
    // array pointers to preserve state until success
    int *d1, *d2, *c;
    int (*b)[n]; // b: board

    b = board;
    d1 = diag1;
    d2 = diag2;
    c = col;

    if (q < n){
        res = placeQueen(q, c, d1, d2, n, b);

        if (res) return 1;
        else return 0;
    }
    else return 1;
}

int placeQueen(int q, int *column[], int *diagonal1[], int *diagonal2[], int n, int *board[][n]){
    int j, d1, d2, c, res;
    int *diag1, *diag2, *col;
    int (*b)[n]; // b: board
    b = board;
    diag1 = diagonal1;
    diag2 = diagonal2;
    col = column;

    for (j = 0; j < n; j++){
        // We check the diagonal arrays to determine if a given cell is occupied
        d1 = diag1[q+j];
        d2 = diag2[q -j+n-1]; //descending diagonal
        c = col[j]; // column number j

        if((d1 == 0)&&(d2 == 0)&&(c == 0)){ // if cell is empty and meets all the conditions
            b[q][j] = q + 1; // place queen number q at cell (q, j)

            diag1[q+j] = diag2[q-j+n-1] = col[j] = 1;
            res = queen(q+1, column, diagonal1, diagonal2, n, board);

            if(res) {
                //printf("res = %2d || Queen = %2d\n\n", res, q);

                board = b;
                diagonal1 = diag1;
                diagonal2 = diag2;
                column = col;

                return 1;

            } else{
                memset(b[q], 0, sizeof(b[q])); // reset array when solution not found
                diag1[q+j] = 0;
                diag2[q-j+n-1] = 0;
                col[j] = 0;
            }
        }
    }
    return 0;
}

// Probleme des 8 Reines: Impression des solutions
void printBoard(int size, int *board[][size]){
    int i, j, m;
    int (*pmat)[size];
    pmat = board;

    for (i = 0; i < size; i++){
        for (m = 0; m < size; m++) printf("+---");
        printf("+\n|");

        for (j = 0; j < size; j++){
            if(*(*(pmat + i) + j) == 0) printf("   |");
            else printf("%2d |", *(*(pmat + i) + j));
        }
        printf("\n");
    }

    for (i = 0; i < size; i++) printf("+---");
    printf("+\n");

}
void printArray(int array[], int size){
    int i;
    for (i = 0; i < size; i++) printf("+---");
    printf("+\n|");

    for (i = 0; i < size; i++){
        if(*(array + i) == 0) printf("   |");
        else printf("%2d |", *(array + i));
    }

    printf("\n");
    for (i = 0; i < size; i++) printf("+---");
    printf("+\n");
}
