#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
    struct node * prev;
};
void ListeyiYazdir(struct node * GelenHead)
{ 
    if(GelenHead == NULL)
    {
        return; 
    }

    while(GelenHead != NULL)
    {

    }
}
void ListeyiYazdirreq(struct node *GelenHead)
{ 
    if(GelenHead == NULL){
        return; // Просто выходим из функции, если дошли до конца списка
    }

    printf("%d\n", GelenHead->data);
    ListeyiYazdirreq(GelenHead->next);    
}
void BasinaEkle(struct node ** GelenHead , int GelenData)
{ 
    //создадин новый узел
    struct node *YeniEl = malloc(sizeof(struct node));
    YeniEl->data = GelenData; 
    YeniEl->next = *GelenHead; 
    YeniEl->prev = NULL;
    *GelenHead = YeniEl;



}
void SonaEkle(struct node **GelenHead, int GelenData)
{ 
    struct node * temp = *GelenHead;
    struct node * Yeniel = malloc(sizeof(struct node));
    while( temp->next != NULL)
    {   
            temp = temp->next;
    }
    temp->next = Yeniel;
    Yeniel->data = GelenData; 
    Yeniel->next = NULL;
    Yeniel->prev = temp;
}
void BasindanSil(struct node ** GelenHead)
{ 
    if(*GelenHead == NULL)
    { 
        return; 

    }else if((*GelenHead)->next == NULL)
    {
        free(*GelenHead); 
        return;
    }

    struct node * silinicekEl = *GelenHead; 
    *GelenHead = silinicekEl->next; 
    free(silinicekEl);
    (*GelenHead)->prev = NULL; 

}
void SonundanSil(struct node ** GelenHead)
{
    struct node * silinicekEl = *GelenHead;
    while(silinicekEl->next != NULL)
    { 
        silinicekEl = silinicekEl->next;
    }
    silinicekEl->prev->next = NULL; 
    free(silinicekEl); 


}
void arananEleamniSil(struct node **GelenHead, int Data)
{

    if (*GelenHead == NULL) {
        return;
    }

    struct node *aranan = *GelenHead;


    if (aranan->data == Data) {
        BasindanSil(GelenHead);
        return;
    }


    while (aranan != NULL && aranan->data != Data) {
        aranan = aranan->next;
    }


    if (aranan == NULL) {
        printf("Eleman bulunamadi!\n");
        return;
    }


    aranan->prev->next = aranan->next;

    if (aranan->next != NULL) {

        aranan->next->prev = aranan->prev;
    }


    free(aranan);
}
float aritmetikOrt(struct node *Gelennode)
{ 

    if (Gelennode == NULL) {
        return 0.0f;
    }


    float data_sum = 0.0f; 
    int el_sum = 0; 

    struct node *current = Gelennode;

    while (current != NULL)
    {
        data_sum += current->data; 
        el_sum++; 
        current = current->next;
    } 

    // printf("%.2f \n", data_sum);
    // printf("%d \n", el_sum);

    return data_sum / el_sum;
}

void enBuyukveEnKucuk(struct node *head)
{

    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }


    int enBuyuk = head->data;
    int enKucuk = head->data;
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data > enBuyuk) {
            enBuyuk = current->data;
        }
        if (current->data < enKucuk) {
            enKucuk = current->data;
        }
        current = current->next;
    }

    printf("En buyuk: %d\n", enBuyuk);
    printf("En kucuk: %d\n", enKucuk);
}
int enBugukBul(struct node * gelenHead)
{
    int enBuyuk = gelenHead->data;
    while(gelenHead != NULL)
    { 
        if(enBuyuk < gelenHead->data)
        {
            enBuyuk = gelenHead->data;
        }
        gelenHead = gelenHead->next;
    }
}
struct node * BKSiralama(struct node *  eskiListe)
{
    struct node * yenieListe = NULL;
    int eb;
    while(eskiListe != NULL)
    {
        eb = enBugukBul(eskiListe);
        arananEleamniSil(&(*eskiListe), eb);
        SonaEkle(&(*yenieListe), eb);
    }
}

int main()
{
    struct node * head = malloc(sizeof(struct node));//birinci dugum
    head->prev = NULL;
    head->data = 1 ;
    head->next = malloc(sizeof(struct node));// ikinci dugum
    head->next->prev = head; 
    head->next->data = 2; 
    head->next->next = malloc(sizeof(struct node));// ucuncu dugum
    head->next->next->prev = head->next;
    head->next->next->next = NULL; 
    head->next->next->data = 3; 
    BasinaEkle(&head, 0);
    SonaEkle(&head, 4);
    SonaEkle(&head, 5); 
    // BasindanSil(&head);

    // SonundanSil(&head);
    // arananEleamniSil(&head, 3);
    ListeyiYazdirreq(head);
    printf("%.2f\n", aritmetikOrt(&head));
    enBuyukveEnKucuk(head);

}