#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data; 
    struct node * next;
    // создается
};
struct bos_node 
{ 
    int data; 
    struct node * next;
};

/* ======== KONTROL ETME FONKSIYONU ======== */
int NULLListTest(struct node * GelenNode)
{ 
    if(GelenNode == NULL)
        return 1;
    return 0;
}

/* ======== LISTELER EKRANA YAZDIR (REQURSIVE) ======== */
void printNodes(struct node *GelenNode)
{ 
    if(GelenNode == NULL){
        return; // Просто выходим из функции, если дошли до конца списка
    }

    printf("%d\n", GelenNode->data);
    printNodes(GelenNode->next);    
}


/* ======== TOPLAM LISTE SAYISI (REQUSRSIVE) ======== */
int sayi(struct node * GelenNode)
{
    int toplam;

    if(GelenNode == NULL)
        return 0; 
    return toplam = 1 + sayi(GelenNode->next);



    
    
}

/* ======== LISTENIN BASINA ELEMAN EKLEME ======== */
void BasinaEkleme(struct node ** GelenNode, int GelenSayi)
{
    struct node *YeniEleman = malloc(sizeof(struct node));
    if (YeniEleman == NULL) {
        printf("Yetersiz memory!\n");
        return;
    }
    YeniEleman->data = GelenSayi;
    YeniEleman->next = *GelenNode; 
    *GelenNode = YeniEleman;

}

/* ======== LISTENIN SONUNA ELEMAN EKLEME ======== */
void SonunaEkleme(struct node **GelenNode ,int GelenSayi)
{ 
    /* === CODE === */
}
int main ()
{
    struct node * head;
    head = malloc(sizeof(struct node));
    head->data = 10; 
    head->next = malloc(sizeof(struct node));

    head->next->data = 20;
    head->next->next = malloc(sizeof(struct node));

    head->next->next->data = 30;
    head->next->next->next = NULL;


    BasinaEkleme(&head, 5);

    printNodes(head);

    printf("Toplam listelerin  sayisi %d", sayi(head));


    
}