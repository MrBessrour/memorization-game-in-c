#include<stdio.h>
#include<windows.h>

char mat[4][4];
char mat_n[4][4];

void Remplir(char mat[4][4])
{
int i,x,l,c,n = 0;
char ch;
    for (i=0;i<8;i++)
    {
        x=rand()%25 + 65 + 1;
        n = 0 ;
        do
        {
            l = rand()%4  ; c = rand()%4 ;
            if(mat[l][c] ==  ' ')
            {
                 ch=(char)x;
                 mat[l][c]=ch;
                 n += 1 ;
            }

        }while(n < 2);
    }
}

void afficher(char mat[4][4])
{
 int i,j,x;
 for(i=0;i<4;i++)
    {

    for (j=0;j<4;j++)
    {
        printf("%c |",mat[i][j]);
    }
        printf("\n");
        printf("------------\n");
    }
}

int comparaison(char mat[4][4],char mat_n[4][4],int i,int j,int i1,int j1)
{
  if (mat[i-1][j-1] == mat[i1-1][j1-1])
  {
      if(mat_n[i-1][j-1] == ' ' && mat_n[i1-1][j1-1] == ' ')
        return(1);
  }
  else
        return(0);
}

void Format(char mat_n[4][4])
{
    int i,j;
 for(i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            mat_n[i][j] = ' ' ;
        }
    }
}

int winner(char mat_n[4][4])
{
    int i,j,x = 0;
 for(i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            if(mat_n[i][j] != ' ')
                x += 1 ;
        }
    }
    if(x == 15)
        return (1);
    else
        return (0);

}

void saisir(char mat[4][4],char mat_n[4][4])
{
    int ij,i,i1,j,j1,com,joueur = 1,s1 = 0,s2 = 0;

    while(winner(mat_n) == 0)
    {
            if(joueur == 1)
        {
            printf("joueur 1\n");
            do
                {
                printf("donner la case 1:");
                scanf ("%d",&ij);
                i = ij / 10 ;
                j = ij % 10 ;

                printf("donner la case 2:");
                scanf ("%d",&ij);
                i1 = ij / 10 ;
                j1 = ij % 10 ;

                com=comparaison(mat,mat_n,i,j,i1,j1);

                if (com==1)
                {
                    system("cls");
                    s1 += 1 ;
                    printf("Bravo!!!joueur 1 gagne un point\n");
                    printf("Score %d - %d \n",s1,s2);
                    mat_n[i-1][j-1] = mat[i-1][j-1];
                    mat_n[i1-1][j1-1] = mat[i1-1][j1-1];
                    afficher(mat_n);
                }

            } while(com==1 && winner(mat_n) == 0) ;
            printf ("les deux lettres ne correspondent pas\n");
            joueur = 2;
            Sleep(1500);system("cls");
        }

        else
        {
           printf("joueur 2\n");
            do
                {
                    printf("donner la case 1:");
                    scanf ("%d",&ij);
                    i = ij / 10 ;
                    j = ij % 10 ;
                    printf("donner la case 2:");
                    scanf ("%d",&ij);
                    i1 = ij / 10 ;
                    j1 = ij % 10 ;

                    com=comparaison(mat,mat_n,i,j,i1,j1);

                    if (com==1)
                        {
                            system("cls");
                            s2 += 1 ;
                            printf("Bravo!!!joueur 2 gagne un point\n");
                            printf("Score %d - %d \n",s1,s2);
                            mat_n[i-1][j-1] = mat[i-1][j-1];
                            mat_n[i1-1][j1-1] = mat[i1-1][j1-1];
                            afficher(mat_n);
                        }
                } while(com==1 && winner(mat_n) == 0) ;
                printf ("les deux lettres ne correspondent pas\n");
                joueur = 1 ;
                Sleep(1500);system("cls");
        }
    }
    system("cls");
    printf("%d - %d",s1,s2);

}

void main()
{
    Format(mat); Format(mat_n);
    system("color A");
    Remplir(mat);
    afficher(mat);
    printf("Vous avez 10 secondes pour memoriser toutes les lettres\n");
    Sleep(10000);
    system("cls");
    saisir(mat,mat_n);
}
