#include <stdio.h>
#include <stdlib.h>

struct node  { 
    int data ;  /* 4 byte */
    struct node * next ;/* 8 byte */

};
/* ====================== EKRANA YAZDIRMA ======================*/
void printNodes(struct node * simdekiListe, struct node * head)
{

    if(simdekiListe == NULL)
        return;

    printf("%d\n",simdekiListe->data);

    if(simdekiListe->next != head)
    {
        printNodes(simdekiListe->next, head);
    }
}
/* ====================== BASINA EKLEME ======================*/
void BasinaEkleme(struct node ** GelenListe, int sayi)
{
    struct node * headOlanEL = *GelenListe;
    struct node * YineDugum = malloc(sizeof(struct node));
    YineDugum->data = sayi; 
    if(*GelenListe == NULL)
    { 
        *GelenListe = YineDugum;
        YineDugum->next = YineDugum; 
    }
    
   
    YineDugum->next = *GelenListe;

    while ( headOlanEL->next != *GelenListe)
    {
        headOlanEL = headOlanEL->next;
    }
    *GelenListe = YineDugum;
    headOlanEL->next = *GelenListe;
}
/* ====================== BASINDAN SILME ======================*/
void BasindanSilme(struct node **GelenListe)
{  
    struct node *silinecek = *GelenListe; 
    struct node * bironceki = *GelenListe; 

    if(*GelenListe == NULL)
    {
        printf("Bos Liste");
        return;
    }
    if ((*GelenListe)->next == *GelenListe)
    {
        free(*GelenListe);
        GelenListe = NULL;
        return;
    }
    


    while(bironceki->next != *GelenListe )
    {
        bironceki = bironceki->next;
    }
    *GelenListe = silinecek->next;
    bironceki->next = *GelenListe;

    free(silinecek);
}
/* ====================== SONUNA EKLEME ======================*/
void SonunaEkleme(struct node **GelenListe, int Sayi)
{
    struct node * bironceki = *GelenListe;
    struct node * YeniDugum = malloc(sizeof(struct node));

    YeniDugum->data = Sayi;
    if(*GelenListe == NULL)
    {
        *GelenListe = YeniDugum;
        YeniDugum->next = YeniDugum;      
    }

    while(bironceki->next != *GelenListe)
    { 
        bironceki = bironceki->next;
    }
    bironceki->next = YeniDugum; 
    YeniDugum->next = *GelenListe;
}
/* ====================== SONUNDAN SILME ======================*/
void SonundanSilme(struct node **GelenListe)
{
    if(*GelenListe == NULL){
        printf("Bos Liste");
        return;
    }

    if((*GelenListe)->next == *GelenListe)
    {
        free(*GelenListe);
        *GelenListe = NULL;
        return;
    }

    struct node *bironceki = *GelenListe; 

    while(bironceki->next->next != *GelenListe){
        bironceki = bironceki->next;
    }
    free(bironceki->next);
    bironceki->next = *GelenListe;
    
    
}
/* ====================== ARANAN SILME ======================*/
void aranansil(struct node ** GelenListe, int sayi)
{
    struct node * silinecekBirOncekiListe = *GelenListe;
    struct node  * silinecek = *GelenListe;
    if(*GelenListe == NULL)
    {
        printf("Bos Liste"); 
        return;
    }
    else if ((*GelenListe)->next == *GelenListe && (*GelenListe)->data == sayi)
    {
        free(*GelenListe);
        *GelenListe = NULL;
    }

    while(silinecekBirOncekiListe->next->data != sayi)
    {
        if(silinecekBirOncekiListe->next == *GelenListe)
        {
            printf("Error");
            return;
        }
        silinecekBirOncekiListe = silinecekBirOncekiListe->next;
    }
    silinecek = silinecekBirOncekiListe->next;
    silinecekBirOncekiListe->next = silinecek->next;
    free(silinecek);
}
/* ====================== IkI LISTE BIRLESMESMEK ======================*/
void ikiListeBirlesmek (struct node **BirinciListe , struct node **IkinciListe)
{
    struct node * BirinciListeninSonELeman = *BirinciListe;
    struct node * IkinciListeninSonEleman = *IkinciListe;
    while(BirinciListeninSonELeman->next != *BirinciListe)
    {
        BirinciListeninSonELeman = BirinciListeninSonELeman->next;
    }
    BirinciListeninSonELeman->next = *IkinciListe;


    while (IkinciListeninSonEleman->next != *IkinciListe)
    {
        IkinciListeninSonEleman = IkinciListeninSonEleman->next;
    }
    IkinciListeninSonEleman->next = *BirinciListe;
    
    
    
}
//parametre olarak gönderilen tek bağlı dairesel bir listenin
//ardışık elemanlardan olusup glusmadığını kontrol edin
//ardısık- ardışık değil yazın
void ardisik(struct node ** GelenHead)
{
    struct node * temp  = *GelenHead;

    while(temp->next != *GelenHead)
    {
        if(temp->data  != temp->next->data - 1)
        {
            printf("Ardisik Degil");
            return;
        }
        temp = temp->next;

    }
    printf("Ardisik");
    

}

int main () 
{
    struct node * head = malloc(sizeof(struct node)); 
    head->data = 10; 
    head->next = malloc(sizeof(struct node));
    head->next->data = 20; 
    head->next->next = malloc(sizeof(struct node)); 
    head->next->next->data = 30;
    head->next->next->next = head;


    
    BasinaEkleme(&head,5);
    BasinaEkleme(&head,2);
    BasinaEkleme(&head,1);
    BasinaEkleme(&head,0);
    SonunaEkleme(&head,40);
    SonunaEkleme(&head,50);
    /*
        0
        1
        2
        5
        10
        20
        30
        40
        50
    */
    // BasindanSilme(&head);
    // SonundanSilme(&head);
    // aranansil(&head, 2);
    //printNodes(head, head);


    /*======== IKINCI LISTE OLUSTURUYORYZ ========*/
    struct node * head2 = malloc(sizeof(struct node)); 
    head2->data = 60; 
    head2->next = malloc(sizeof(struct node));
    head2->next->data = 70; 
    head2->next->next = malloc(sizeof(struct node)); 
    head2->next->next->data = 80;
    head2->next->next->next = head2;


    //ikiListeBirlesmek(&head, &head2);

    //printNodes(head, head);

    struct node * head3 = malloc(sizeof(struct node)); 
    head3->data = 1; 
    head3->next = malloc(sizeof(struct node));
    head3->next->data = 2; 
    head3->next->next = malloc(sizeof(struct node)); 
    head3->next->next->data = 3;
    head3->next->next->next = head3;
    ardisik(&head);

}