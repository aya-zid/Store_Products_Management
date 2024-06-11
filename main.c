
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#include "new.h"
liste_p LP;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void addmenus(HWND);
void CreateBtt(HWND hwnd) ;

HWND hname ,hage,hout,hogo,Add,Finnish;
 HDC hdc;
HMENU hmenu ;

HBITMAP hlogoImage , hgenerateImage;
int intro=1 ;
char ch[30] ;
long p ;
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("my project");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+7;


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Gestion des produits d'un magasin par Zid Aya"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           1200,                 /* The programs width */
           768,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{static HBITMAP  hBmp;


   /* if(intro)
    {
        system("start test.exe") ;
        intro=0;
    }*/
    switch (message)                  /* handle the messages */
    {

        case WM_COMMAND:
        switch(wParam)
        {
        case 1:
                system("color F8");
                produit x;
                int pos,t,num;
                creer_liste(&LP);
                LP=creation(LP);
                system("cls");
                break;
        case 2:
                system("color F9");
                int n;
                n=taille_liste_produit(LP);
                if (n==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³      INSERE TETE PRODUIT       ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                x=saisie_produit(LP);
                LP=inserer_tete_produit(LP,x);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                }
                system("cls");
                break;
        case 3:
                system("color F9");
                n=taille_liste_produit(LP);
                if (n==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                produit y;
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³      INSERE QUEUE PRODUIT      ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                y=saisie_produit(LP);
                LP=inserer_queue_produit(LP,y);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);}
                system("cls");
                break;
        case 4:
                system("color F9");
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³     INSERE POSITION PRODUIT    ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(20,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(20,6);  printf("³Position        ³                ³");
                gotoxy(20,7);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

                do
                {
                    gotoxy(38,6);
                    scanf("%d",&pos);
                }while(!(pos>1 && pos<t+1));
                gotoxy(20,7);printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
                x=saisie_produit_pos(LP);
                insere_pos_produit(LP,pos,x);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);}
                system("cls");
                break;
        case 5:
                system("color F9");
                 n=taille_liste_produit(LP);
                if (n==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                LP=supprimer_tete_produit(LP);
                MessageBox(0,"Suppression effectuee avec succes ","Succes",0);
                }
                system("cls");
                break;

        case 6:
                system("color F9");
                 n=taille_liste_produit(LP);
                if (n==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                LP=supprimer_queue_produit(LP);
                MessageBox(0,"Suppression effectuee avec succes ","Succes",0);
                }
                system("cls");
                break;
        case 7:
                system("color F9");
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³  SUPPRESSION POSITION PRODUIT  ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(20,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(20,6);  printf("³Position        ³                ³");
                gotoxy(20,7);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(20,9);printf("                           ");
                do
                {
                    gotoxy(38,6);
                    scanf("%d",&pos);

                }while(!(pos>1 && pos<taille_liste_produit(LP)));
                getch();

                supprime_position( LP, pos );

                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                MessageBox(0,"Suppression effectuee avec succes ","Succes",0);
                }
                system("cls");
                break;
        case 8:
                system("color F9");
                int num1;
                int q;
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³  SUPPRESSION PRODUIT DONNE     ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(20,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(20,6);  printf("³Code            ³                ³");
                gotoxy(20,7);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

                do
                {
                    gotoxy(38,6);
                    scanf("%d",&num1);
                    q=num1/100;

                }while(!(q>0 && q<10));
                gotoxy(20,9); printf("            ");
                int yes=recherche_produit(LP,num1);
                if (yes==0)
                   MessageBox(0,"Produit introuvable ","Erruer",0);

                else{

                LP=SUPP_PRODUIT(LP,num1);
                MessageBox(0,"Suppression effectuee avec succes ","Succes",0);
                }
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);

                }
                system("cls");
                break;

        case 9:
                system("color F9");
                supprimer_produits_expires(LP,"01/05/2022");
                MessageBox(0,"Suppression effectuee avec succes ","Succes",0);

                system("cls");
                break;
        case 10:
                system("color F9");
                float newp;
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³      MODIFICATION DU PRIX      ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(20,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(20,6);  printf("³Code            ³                ³");
                gotoxy(20,7);  printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅ");
                gotoxy(20,8);  printf("³Prix            ³                ³");
                gotoxy(20,9);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

                do
                {
                    gotoxy(38,6);
                    scanf("%d",&num1);
                    q=num1/100;

                }while(!(q>0 && q<10));

                do
                {
                    gotoxy(38,8);
                    scanf("%f",&newp);

                }while(newp<0);
                gotoxy(20,11); printf("            ");
                int yes=recherche_produit(LP,num1);
                if (yes==0)
                   MessageBox(0,"Produit introuvable ","Erruer",0);

                else{

                modifier_prix (LP ,num1 ,newp);

                MessageBox(0,"Modification effectuee avec succes ","Succes",0);
                }
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);

                }
                system("cls");
                break;

        case 11:
                system("color F9");
                int newq;
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³      MODIFICATION DU PRIX      ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(20,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(20,6);  printf("³Code            ³                ³");
                gotoxy(20,7);  printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅ");
                gotoxy(20,8);  printf("³Quantité        ³                ³");
                gotoxy(20,9);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

                do
                {
                    gotoxy(38,6);
                    scanf("%d",&num1);
                    q=num1/100;

                }while(!(q>0 && q<10));

                do
                {
                    gotoxy(38,8);
                    scanf("%d",&newq);

                }while(newq<0);
                gotoxy(20,11); printf("            ");
                int yes=recherche_produit(LP,num1);
                if (yes==0)
                   MessageBox(0,"Produit introuvable ","Erruer",0);

                else{

                modifier_qt (LP ,num1 ,newq);

                MessageBox(0,"Modification effectuee avec succes ","Succes",0);
                }
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);

                }
                system("cls");
                break;

        case 12:
                system("color F9");
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                affiche(LP);
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);
                system("cls");
                break;
        case 13:
                system("color F9");
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(22,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(22,3); printf("³      RECHERCHE PAR CODE        ³");
                gotoxy(22,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(20,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(20,6);  printf("³Code            ³                ³");
                gotoxy(20,7);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

                do
                {
                    gotoxy(38,6);
                    scanf("%d",&num1);
                    q=num1/100;

                }while(!(q>0 && q<10));
                int yes=recherche_produit(LP,num1);
                if (yes==0){
                    gotoxy(20,9);printf("                  ");
                   MessageBox(0,"Produit introuvable ","Erruer",0);
                }
                else{
                gotoxy(20,7);printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
                recherche_code(LP,num1);}
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);}
                system("cls");
                break;

        case 14:
               system("color F9");
               char date[11];
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(38,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(38,3); printf("³  RECHERCHE PAR DATE DE PRODUCTION  ³");
                gotoxy(38,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(40,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(40,6);  printf("³Date            ³                ³");
                gotoxy(40,7);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

                do
                {
                    gotoxy(58,6);
                    scanf("%s",&date);


                }while(!(verif_date(date)));
                int yes=test_dp(LP,date);
                if (yes==0){
                    gotoxy(20,9);printf("                  ");
                   MessageBox(0,"Date introuvable ","Erruer",0);
                }
                else{

                recherche_dp(LP,date);}
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);}
                system("cls");
                break;
        case 15:
                system("color F9");

                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(38,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(38,3); printf("³  RECHERCHE PAR DATE D'EXPIRATION   ³");
                gotoxy(38,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(40,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(40,6);  printf("³Date            ³                ³");
                gotoxy(40,7);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

                do
                {
                    gotoxy(58,6);
                    scanf("%s",&date);


                }while(!(verif_date(date)));
                int yes=test_de(LP,date);
                if (yes==0){
                    gotoxy(20,9);printf("                  ");
                   MessageBox(0,"Produits introuvables ","Erruer",0);
                }
                else{

                recherche_de(LP,date);}
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);}
                system("cls");
                break;
        case 16:
                system("color F9");
                char date1[11],date2[11];
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                ShowWindow(hwnd,SW_HIDE);
                gotoxy(25,10);
                gotoxy(36,2); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(36,3); printf("³  RECHERCHE ENTRE 2 DATE DE PRODUCTION  ³");
                gotoxy(36,4); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
                gotoxy(40,5);  printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
                gotoxy(40,6);  printf("³Date 1          ³                ³");
                gotoxy(40,7);  printf("ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´");
                gotoxy(40,8);  printf("³Date 2          ³                ³");
                gotoxy(40,9);  printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");


                do
                {
                    gotoxy(58,6);
                    scanf("%s",&date1);


                }while(!(verif_date(date1)));
                do
                {
                    gotoxy(58,8);
                    scanf("%s",&date2);


                }while(!(verif_date(date2)));
                int yes=test_deuxp(LP,date1,date2);
                if (yes==0){
                    gotoxy(20,11);printf("                  ");
                   MessageBox(0,"Produits introuvables ","Erruer",0);
                }
                else{

                recherche_deuxp(LP,date1,date2);}
                system("pause");
                ShowWindow(hwnd,SW_NORMAL);}
                system("cls");
                break;
        case 17:
                system("color F9");
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                tri1(LP);
                MessageBox(0,"Tri effectué avec succés ","Succés",0);}
                system("cls");
                break;
        case 18:
                system("color F9");
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                tri2(LP);
                MessageBox(0,"Tri effectué avec succés ","Succés",0);}
                system("cls");
                break;
         case 19:
                system("color F9");
                t=taille_liste_produit(LP);
                if (t==0)
                {
                    MessageBox(0,"Vous avez oublié de faire le chargement ","Erreur",0);
                }
                else{
                enregistrement(LP);
                MessageBox(0,"Enregistrement effectué avec succés ","Succés",0);}
                system("cls");
                break;
         case 20:
                system("color F9");
                t=taille_liste_produit(LP);
                if (t!=0)
                {
                    MessageBox(0,"Vous pouvez pas faire le chargement une autre fois  ","Erreur",0);
                }
                else
               {

                LP=recuperation();
                MessageBox(0,"Chargement effectué avec succés ","Succés",0);}
                system("cls");
                break;
         case 22:
                system("color F9");
                ShellExecute(NULL, "open", "projet.pdf", NULL, NULL, SW_SHOWNORMAL);
                system("cls");
                break;
         case 23:
                system("color F9");
                ShellExecute(NULL, "open", "produit.txt", NULL, NULL, SW_SHOWNORMAL);
                system("cls");
                break;


        case 21:

                if (MessageBox(hwnd,"       Vous voulez quitter ?", "QUITTER", MB_YESNO | MB_ICONQUESTION ) == IDYES)
                {

                    DestroyWindow(hwnd);
                    system("cls");
                }
            break;



        }
    case WM_CREATE :
        addmenus(hwnd);
//         CreateBtt(hwnd) ;
            /*****************ajouter fond **********************/
            hBmp=LoadImage(NULL,"magasin.Bmp",IMAGE_BITMAP,1300,650,LR_LOADFROMFILE);


            break;

        case WM_PAINT :
            {



         PAINTSTRUCT ps;
            hdc = BeginPaint(hwnd, &ps);

            DrawState(hdc,NULL,NULL,(long)hBmp,0,0,0,0,0,DST_BITMAP);

            EndPaint(hwnd, &ps);}
        break;
        case WM_DESTROY:
            PostQuitMessage (0);        /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void addmenus(HWND hwnd)
{
    hmenu=CreateMenu();
    HMENU htp=CreateMenu();
    HMENU htp1=CreateMenu();
    HMENU hex3=CreateMenu();
    HMENU hex4=CreateMenu();
    HMENU hex5=CreateMenu();
    HMENU htp2=CreateMenu();
    HMENU htp3=CreateMenu();
    HMENU htp4=CreateMenu();

    //AppendMenu(hmenu,MF_STRING,0,"création du repertoire");
/*******************************************************/
    AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp,"Création");

    AppendMenu(htp,MF_STRING,1,"Creation");
/***************************************************************/

     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp1,"Mise à jour des produits");

     AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex3,"Ajouter un nouvel produit");
        AppendMenu(hex3,MF_STRING,2,"Ajout en tete"); /*Sous partie de l'ex3*/
        AppendMenu(hex3,MF_STRING,3,"Ajout en queue");
        AppendMenu(hex3,MF_STRING,4,"Ajout dans une position");
     AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex4,"Supprimer un produit");
        AppendMenu(hex4,MF_STRING,5,"suppression en tete"); /*Sous partie de l'ex3*/
        AppendMenu(hex4,MF_STRING,6,"suppression en queue");
        AppendMenu(hex4,MF_STRING,7,"suppression a partir d'une position");
        AppendMenu(hex4,MF_STRING,8,"suppression d'un produit donné");
        AppendMenu(hex4,MF_STRING,9,"suppression des produits expirés");
     AppendMenu(htp1,MF_POPUP,(UINT_PTR)hex5,"modifier les données d'un produit");
        AppendMenu(hex5,MF_STRING,10,"prix");
        AppendMenu(hex5,MF_STRING,11,"quantité");
/***************************************************************/
     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp2,"Recherche, affichage et Tri");

      AppendMenu(htp2,MF_STRING,12,"Contenu de la liste des produits");
      AppendMenu(htp2,MF_STRING,13,"Recherche par code produit");
      AppendMenu(htp2,MF_STRING,14,"Recherche par date de production");
      AppendMenu(htp2,MF_STRING,15,"Recherche par date d'expiration");
      AppendMenu(htp2,MF_STRING,16,"Recherche des produits entre 2 dates de production");
      AppendMenu(htp2,MF_STRING,17,"Tri 1");
      AppendMenu(htp2,MF_STRING,18,"Tri 2");

/***************************************************************/
     AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp3,"Enregistrement et chargement dans un fichier");

      AppendMenu(htp3,MF_STRING,19,"Enregistrement");
      AppendMenu(htp3,MF_STRING,20,"Chargement");

/***************************************************************/
AppendMenu(hmenu,MF_POPUP,(UINT_PTR)htp4,"ouvrir un fichier");

    AppendMenu(htp4,MF_STRING,22,"ennoncé");
    AppendMenu(htp4,MF_STRING,23,"produit.txt");

/****************************************************************/

AppendMenu(hmenu,MF_STRING,21,"Quitter");
    SetMenu(hwnd,hmenu);

}
