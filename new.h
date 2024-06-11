#ifndef NEW_H_INCLUDED
#define NEW_H_INCLUDED
typedef struct
{
    int j,m,a;

}date;


typedef struct
{
    int code;
    char nom[20];
    char dp[11];
    char de[11];
    float prix;
    int qte;
}produit;

struct cellule
{
    produit info;
    struct cellule *suivant;
};

struct liste
{
    struct cellule * premier ;
    struct cellule * dernier ;
} ;
typedef struct liste liste_p;


void creer_liste(liste_p *);
int recherche_produit (liste_p , int);
int taille_liste_produit (liste_p );
produit saisie_produit(liste_p  );
produit saisie_produit_pos(liste_p  );
liste_p inserer_queue_produit(liste_p ,produit );
liste_p inserer_tete_produit(liste_p ,produit );
void affiche(liste_p );
liste_p creation(liste_p );
liste_p supprimer_tete_produit( liste_p );
liste_p supprimer_queue_produit( liste_p );
void  supprime_position( liste_p , int  );
liste_p  SUPP_PRODUIT(liste_p ,int );
int BISSEXTILE(int );
int verif4(char ch[]);
int verif_date(char ch[] );
unsigned verife_chaine(char []);
void enregistrement(liste_p );
liste_p recuperation();
int comparer_date (char [], char []);
void affiche_produits_expires(liste_p );
void insere_pos_produit(liste_p , int ,produit );
void supprimer_produits_expires(liste_p , char []);
void  recherche_code( liste_p, int );
void  recherche_dp( liste_p,char[] );
int test_dp(liste_p,char[]);
void  recherche_de( liste_p,char[] );
int test_de(liste_p,char[]);
void  recherche_deuxp( liste_p,char[] ,char[]);
int test_deuxp(liste_p,char[],char[]);
void tri1( liste_p );
void tri2( liste_p );
void modifier_prix (liste_p , int ,float );
void modifier_qt (liste_p ,int ,int );
#endif // NEW_H_INCLUDED
