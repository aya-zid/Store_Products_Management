
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"new.h"
#include<myconio.h>

/************** Fonction création *******************************/
void creer_liste(liste_p *LP)
{
    LP->premier=NULL ;
    LP->dernier=NULL ;
}
/********************** Fonction test *************************/
int recherche_produit (liste_p LP, int num)
{
    struct cellule *p=LP.premier;
   	while(p)
   	    if((p->info).code==num)
   	        return 1;
   	    else
   	        p=p->suivant;
   	return 0;
}
 /******************** Fonction taille *********************/
int taille_liste_produit (liste_p LP)
{
    struct cellule *p=LP.premier;
    int t=0;
   	while(p)
    {
        t++;
        p=p->suivant;
    }
   	return t;
}

/******************************************************/
int verif4(char ch[])
{
    int i;
    for(i=0;i<10;i++)
        if(i==2||i==5)
        {
            if(ch[i]!='/')
                return 0;
        }
        else
            if(ch[i]<'0'||ch[i]>'9')
                return 0;
    return 1;
}


/********FONCTION BISSEXTILE*******/
int BISSEXTILE(int a)
{
    if((a%4==0 && a%100!=0)|| (a%400==0))
        return 1;
    else
        return 0;

}
/********FONCTION JOUR_MAX**********/

int verif_date(char ch[])
{
    char jj[3],mm[3],aa[5];
    int j,k,i, m, a,jmax;
    for(i=0;i<2;i++)
        jj[i]=ch[i];
    jj[i]='\0';
    for(i++,k=0;i<5;i++)
        mm[k++]=ch[i];
    mm[k]='\0';
    for(i++,k=0;ch[i];i++)
        aa[k++]=ch[i];
    aa[k]='\0';
    j=atoi(jj);
    m=atoi(mm);
    a=atoi(aa);
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            jmax =31 ;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            jmax =30 ;
            break;
        case 2:
            if(BISSEXTILE(a))
                jmax=29;
            else
                jmax=28;
    }
     return j>=1 && j<=jmax && m>=1 && m<=12 && a>=1900 && verif4(ch) && strlen(ch)==10;
}


/*************************verife chaine**************************/
unsigned verife_chaine(char ch[])
{
    int i=0,ok=0,x;
    while (ch[i]!='\0')
    {
        x=ch[i];
        if((x>=97 && x<=122)||(x>=65 && x<=90)||x==95)
        {
            i++;
        }
        else
        {
            ok=1;
            break;
        }
    }return ok ;
}
                /***** Fonction saisie_produit *****/
produit saisie_produit(liste_p LP )
{
   gotoxy(20,6);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
   gotoxy(20,7);  printf("³Code            ³                ³");
   gotoxy(20,8);  printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,9);  printf("³Nom             ³                ³");
   gotoxy(20,10); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,11); printf("³Date production ³                ³");
   gotoxy(20,12); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,13); printf("³Date expiration ³                ³");
   gotoxy(20,14); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,15); printf("³Prix            ³                ³");
   gotoxy(20,16); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,17); printf("³Quantite        ³                ³");
   gotoxy(20,18); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

int q;
    produit p;

    do
    {
        gotoxy(38,7);printf("      ");
        gotoxy(38,7);
        scanf("%d",&p.code);
        q=p.code/100;

    }while(!((recherche_produit (LP, p.code)==0)&&(q>0 && q<10)));
do {
    fflush(stdin);
    gotoxy(38,9);printf("             ");
    gotoxy(38,9);
    scanf("%s",p.nom);}while(verife_chaine(p.nom));
    do
    {
        fflush(stdin);
        gotoxy(38,11);
        printf("             ");
        gotoxy(38,11);
        scanf("%s",&p.dp);
    }while(!(verif_date(p.dp)));
    do
    {

        fflush(stdin);
        gotoxy(38,13);printf("             ");

        gotoxy(38,13);
        scanf("%s",&p.de);
    }while(!(verif_date(p.de)));

    do{
    fflush(stdin);
    gotoxy(38,15);printf("           ");
     gotoxy(38,15);
    scanf("%f",&p.prix);
    }while(p.prix<0);

    do{
    fflush(stdin);
    gotoxy(38,17);printf("           ");
    gotoxy(38,17);
    scanf("%d",&p.qte);}while(p.qte<0);

    gotoxy(20,20); printf("         ");
   return p;
}


                /***** Fonction saisie_produit *****/
produit saisie_produit_pos(liste_p LP )
{

   gotoxy(20,8);  printf("³Code            ³                ³");
   gotoxy(20,9);  printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,10); printf("³Nom             ³                ³");
   gotoxy(20,11); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,12); printf("³Date production ³                ³");
   gotoxy(20,13); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,14); printf("³Date expiration ³                ³");
   gotoxy(20,15); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,16); printf("³Prix            ³                ³");
   gotoxy(20,17); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,18); printf("³Quantite        ³                ³");
   gotoxy(20,19); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

int q;
    produit p;

    do
    {
        gotoxy(38,8);
        scanf("%d",&p.code);
        q=p.code/100;
    }while(!((recherche_produit (LP, p.code)==0)&&(q>0 && q<10)));
    fflush(stdin);
    gotoxy(38,10);
    scanf("%s",p.nom);
    do
    {
        fflush(stdin);
        gotoxy(38,12);
        scanf("%s",&p.dp);
    }while(!(verif_date(p.dp)));
    do
    {

        fflush(stdin);
        gotoxy(38,14);
        scanf("%s",&p.de);
    }while(!(verif_date(p.de)));

    do{
    fflush(stdin);
    gotoxy(38,16);
    scanf("%f",&p.prix);
    }while(p.prix<0);

    do{
    fflush(stdin);
    gotoxy(38,18);
    scanf("%d",&p.qte);}while(p.qte<0);

    gotoxy(20,21); printf("         ");
   return p;
}


 /******************** Fonction inserer_queue_produit ***************/

liste_p inserer_queue_produit(liste_p LP,produit x)
{

    struct cellule *q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = NULL ;
    if(LP.dernier==NULL)
        LP.premier=q;
    else
        (LP.dernier)->suivant=q;
    LP.dernier = q;
    return LP;
}
/*************** Fonction inserer_tete_produit ***********************/
liste_p inserer_tete_produit(liste_p LP,produit x)
{
    struct cellule * q;
    q = (struct cellule*)malloc(sizeof(struct cellule));
    q->info = x;
    q->suivant = LP.premier ;
    if(LP.premier==NULL)
        LP.dernier=q;
    LP.premier = q;
    return LP;
}
/***********************INSERE POS****************************/

void insere_pos_produit(liste_p LP, int pos,produit x )
{
    struct cellule * p2;
    struct cellule *p1=LP.premier;
    int i=1;
    while(i<pos-1)
    {
        p1=p1->suivant;
        i++;
    }
    p2=(struct cellule*)malloc(sizeof(struct cellule));
    p2->info=x;
    p2->suivant=p1->suivant;
    p1->suivant=p2;
}
/************************** Fonction affiche ****************************/
void affiche(liste_p LP)
{
    struct cellule *P=LP.premier;
    gotoxy(10,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(10,3); printf("³Code            ³Nom             ³Date production ³Date expiration ³Prix            ³Quantite        ³");
    gotoxy(10,4); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
int n;
int j;
    int i =5;
    while(P)
    {n=strlen((P->info).nom);

    j=n;
   while (j<=15)
    {

       strcat(((P->info).nom)," ");
       j++;
    }
gotoxy(10,i);   printf("³%d             ³%s³%s      ³%s      ³%6.3f          ³%3d             ³",(P->info).code,(P->info).nom,(P->info).dp,(P->info).de,P->info.prix,P->info.qte);
   //gotoxy(10,i+1); cprintf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
       P=P->suivant;
       i++;
    }
    gotoxy(10,i);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    gotoxy(10,i+1);printf("                    ");

  }
/************************Recherche par code****************************/

void  recherche_code( liste_p LP, int  c )
{
    struct cellule * P;
    P=LP.premier;
    while(P)
    {
        if ((P->info).code==c)
            {
   gotoxy(20,8);  printf("³Nom             ³                ³");
   gotoxy(20,9);  printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,10); printf("³Date production ³                ³");
   gotoxy(20,11); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,12); printf("³Date expiration ³                ³");
   gotoxy(20,13); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,14); printf("³Prix            ³                ³");
   gotoxy(20,15); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
   gotoxy(20,16); printf("³Quantite        ³                ³");
   gotoxy(20,17); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   gotoxy(38,8);printf("%s",(P->info).nom);
   gotoxy(38,10);printf("%s",(P->info).dp);
   gotoxy(38,12);printf("%s",(P->info).de);
   gotoxy(38,14);printf("%.3f",(P->info).prix);
   gotoxy(38,16);printf("%d",(P->info).qte) ;
   gotoxy(20,19);printf("                  ");
   break;
            }
        else
            P=P->suivant;
    }

}
/*****************************create***********************************/
liste_p creation(liste_p LP)
{
    int rep,pos ,t;
    produit x;
    do
    {
        t=taille_liste_produit(LP);
        do
        {
            printf("Donner la position entre 1 et %d: ",t+1);
            scanf("%d",&pos);
        }while(!(pos>=1 && pos<=t+1));
        x=saisie_produit(LP);
        if(pos==1)
            LP=inserer_tete_produit(LP,x);
        else
            if(pos==t+1)
                LP=inserer_queue_produit(LP,x);
            else
                insere_pos_produit(LP,pos,x);
        do
        {
            printf("Voulez vous ajouter un autre produit 1/0 » (1 pour Oui, 0 pour Non):");
            scanf("%d",&rep);
        }while(!(rep==1 || rep==0));
    }while(rep);
    return LP;
}
/***********************Fonction suppression tete********************/
liste_p supprimer_tete_produit( liste_p LP)
{
    struct cellule * s;
    s= LP.premier;
    LP.premier = s->suivant;
    free(s);
    /* exception une liste formée d’un seul élément */
    if(LP.premier ==NULL)
        LP.dernier=NULL;
    return LP;
}
/*********************Fonction suppression queue*************************/
liste_p supprimer_queue_produit( liste_p LP)
{
    struct cellule * p; /*pour parcourir ll */
    if(LP.premier==LP.dernier) /* liste formé d’un seul élément*/
        LP=supprimer_tete_produit(LP);
    else
    {
        p=LP.premier;
        while(p->suivant!= LP.dernier)
            p=p->suivant;
        p->suivant=NULL; /* mise à jour */
        free(LP.dernier); /* libérer de dernier */
        LP.dernier=p; /* mise à jour */

    }
    return LP;
}
/*********************supprime position**************************/
void  supprime_position( liste_p LP, int  pos )
{
    struct cellule * p1=LP.premier;
    struct cellule *p2 ;
    int  i =1;
    while(i<pos-1)
    {
        i ++;
        p1=p1->suivant ;
    }
    p2=p1->suivant ;
    p1->suivant=p2->suivant ;
    free (p2) ;
}
/**********************Suppression produit donné**********************/
liste_p  SUPP_PRODUIT(liste_p LP,int num)
{
    struct cellule *p=LP.premier,*q;
    int ok=0;
    if((p->info).code==num)
    {   LP.premier=p->suivant;
        free(p);
    }
    else
    {    while(p->suivant)
            if((p->suivant)->info.code==num)
            {
                ok=1;
                break;
            }
            else
                p=p->suivant;
        if(ok)
        {   q=p->suivant;
            if(q==LP.dernier)
                LP.dernier=p;
            p->suivant=q->suivant;
            free(q);
        }

    }
    return LP;
}
/************supprimer produits expires ******************/

void supprimer_produits_expires(liste_p LP, char da[])
{
    struct cellule *P=LP.premier;
    while (P)
    {
       if(comparer_date (P->info.de,da)==-1)

           LP=SUPP_PRODUIT( LP,(P->info).code);

       P=P->suivant;

    }

}
/*********************Fonction COMPARER DATE ***********************/

int comparer_date (char t1[], char t2[])
{int num;

char a1[5];char a2[5];
char m1[3];char m2[3];
char j1[3];char j2[3];

j1[0]=t1[0];j1[1]=t1[1];j1[2]='\0';

m1[0]=t1[3];m1[1]=t1[4];m1[2]='\0';

a1[0]=t1[6];a1[1]=t1[7];a1[2]=t1[8];a1[3]=t1[9];a1[4]='\0';

j2[0]=t2[0];j2[1]=t2[1];j2[2]='\0';

m2[0]=t2[3];m2[1]=t2[4];m2[2]='\0';

a2[0]=t2[6];a2[1]=t2[7];a2[2]=t2[8];a2[3]=t2[9];a2[4]='\0';

num =strcmp(a1,a2);
if (num==0)
{
    num=strcmp(m1,m2);
    if (num==0)
    num=strcmp(j1,j2);


} return num;

}

/***************** enregistrement ******************************/
void enregistrement(liste_p LP)
{
    FILE *f;
     struct cellule *p=LP.premier;
    f=fopen("produit.txt","w");
    while(p)
    {
        fprintf(f,"%d|%s|%s|%s|%f|%d\n",p->info.code,p->info.nom,p->info.dp,p->info.de,p->info.prix,p->info.qte);
        p=p->suivant;
    }
    fclose(f);
}
/*******************chargement******************************/
liste_p recuperation()
{
    FILE * f;
    f = fopen("produit.txt", "r");
    produit prod;
    liste_p LP;
    creer_liste(&LP);
    while(!feof(f))
    {
        fscanf(f,"%d|%[^|]|%[^|]|%[^|]|%f|%d\n", &prod.code, prod.nom, prod.dp, prod.de,&prod.prix,&prod.qte);
        LP=inserer_queue_produit(LP,prod);
    }
    fclose(f);
    return LP;

}
/***********************recherche date expire**********************/
void  recherche_de( liste_p LP, char da[] )
{
    gotoxy(10,10); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(10,11); printf("³Code            ³Nom             ³Date production ³Date expiration ³Prix            ³Quantite        ³");
    gotoxy(10,12); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
int n;
int j;
int i =13;
    struct cellule * P=LP.premier;
    while(P)
    {
        if ( comparer_date((P->info).de , da)==-1)
          {


          n=strlen((P->info).nom);j=n;
         while (j<=15)
    {

       strcat(((P->info).nom)," ");
       j++;
    }
gotoxy(10,i);   printf("³%d             ³%s³%s      ³%s      ³%6.3f          ³%3d             ³",(P->info).code,(P->info).nom,(P->info).dp,(P->info).de,P->info.prix,P->info.qte);


       i++;
    }
     P=P->suivant;

          }
gotoxy(10,i);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    gotoxy(10,i+1);printf("                    ");



    }


int test_de(liste_p LP,char da[])
{
    struct cellule * P=LP.premier;
    while(P)
    {
        if ( comparer_date((P->info).de , da)==-1)
           return 1;
        else
            P=P->suivant;

    }
    return 0;

}
/************************recherche date produit********************/
void  recherche_dp( liste_p LP, char da[] )
{
    gotoxy(10,10); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(10,11); printf("³Code            ³Nom             ³Date production ³Date expiration ³Prix            ³Quantite        ³");
    gotoxy(10,12); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
int n;
int j;
int i =13;
    struct cellule * P=LP.premier;
    while(P)
    {
        if ( strcmp((P->info).dp , da)==0)
          {


          n=strlen((P->info).nom);j=n;
         while (j<=15)
    {

       strcat(((P->info).nom)," ");
       j++;
    }
gotoxy(10,i);   printf("³%d             ³%s³%s      ³%s      ³%6.3f          ³%3d             ³",(P->info).code,(P->info).nom,(P->info).dp,(P->info).de,P->info.prix,P->info.qte);
gotoxy(10,i+1); cprintf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");

       i++;
    }
     P=P->suivant;

          }
gotoxy(10,i);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    gotoxy(10,i+1);printf("                    ");



    }


int test_dp(liste_p LP,char da[])
{
    struct cellule * P=LP.premier;
    while(P)
    {
        if ( strcmp((P->info).dp , da)==0)
           return 1;
        else
            P=P->suivant;

    }
    return 0;

}
/**********************recherche deux date production*******************/
void  recherche_deuxp( liste_p LP, char da1[] ,char da2[])
{
    gotoxy(10,10); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(10,11); printf("³Code            ³Nom             ³Date production ³Date expiration ³Prix            ³Quantite        ³");
    gotoxy(10,12); printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
int n;
int j;
int i =13;
    struct cellule * P=LP.premier;
    while(P)
    {
        if (( comparer_date((P->info).dp , da1)==1)&&( comparer_date((P->info).dp , da2)==-1))
          {


          n=strlen((P->info).nom);j=n;
         while (j<=15)
    {

       strcat(((P->info).nom)," ");
       j++;
    }
gotoxy(10,i);   printf("³%d             ³%s³%s      ³%s      ³%6.3f          ³%3d             ³",(P->info).code,(P->info).nom,(P->info).dp,(P->info).de,P->info.prix,P->info.qte);
gotoxy(10,i+1); cprintf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");

       i++;
    }
     P=P->suivant;

          }
gotoxy(10,i);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    gotoxy(10,i+1);printf("                    ");



    }


int test_deuxp(liste_p LP,char da1[],char da2[])
{
    struct cellule * P=LP.premier;
    while(P)
    {
        if (( comparer_date((P->info).dp , da1)==1)&&( comparer_date((P->info).dp , da2)==-1))
           return 1;
        else
            P=P->suivant;

    }
    return 0;

}

/*******************tri***********************/
void tri2(liste_p lp)
{
    struct cellule *p1, *p2;
    produit aux;
    p1=lp.premier;
    while(p1->suivant!=NULL)
    {
        p2=p1->suivant;
        while(p2!=NULL)
        {
            if(comparer_date((p1->info).de , (p2->info).de)>=1)
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
            p2=p2->suivant;
        }
        p1=p1->suivant;
    }
}
void tri1(liste_p lp)
{
    struct cellule *p1, *p2;
    produit aux;
    p1=lp.premier;
    while(p1->suivant!=NULL)
    {
        p2=p1->suivant;
        while(p2!=NULL)
        {
            if((p1->info).qte < (p2->info).qte )
            {
                aux=p1->info;
                p1->info=p2->info;
                p2->info=aux;
            }
            p2=p2->suivant;
        }
        p1=p1->suivant;
    }
}

void modifier_prix (liste_p LP, int num,float price)
{
    struct cellule *p=LP.premier;

       	while(p)
   	    {if((p->info).code==num)
   	        {(p->info).prix=price;
   	        break;}
   	    else
   	        p=p->suivant;

        }

}
void modifier_qt (liste_p LP, int num,int quantite)
{
    struct cellule *p=LP.premier;
   	while(p)
   	    if((p->info).code==num)
   	      {

   	        (p->info).qte=quantite;
   	        break;}
   	    else
   	        p=p->suivant;

}
