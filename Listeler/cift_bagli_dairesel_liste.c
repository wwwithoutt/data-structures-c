#include <stdio.h>
#include<stdlib.h>

struct node 
{ 
    int data; 
    struct node * next; 
    struct node * prev; 
}; 


void Listeler_Yaz(struct node * GelenHead)
{ 
    if(GelenHead == NULL)
    { 
        printf("Liste bos ! \n");
        return;
    }
    struct node * temp = GelenHead;
    do
    { 
       printf("%d\n",temp->data); 
       temp = temp->next;
        

    }while(temp != GelenHead);
}

struct node * basinaEkle(struct node * GelenHead, int gelenData)
{ 
    struct node * YeniDugum = malloc(sizeof(struct node));
    YeniDugum->data = gelenData;
    if(GelenHead == NULL)
    { 
        GelenHead = YeniDugum; 
        GelenHead->next = GelenHead;
        GelenHead->prev = GelenHead;
        return GelenHead;
    }

    struct node * SonEleman = GelenHead->prev; 


    YeniDugum->prev = SonEleman;
    YeniDugum->next = GelenHead;
    GelenHead->prev = YeniDugum;
    SonEleman->next = YeniDugum;
    GelenHead = YeniDugum;
    return YeniDugum; 


}
struct node * sonaEkleme(struct node * GelenHead, int gelenData)
{ 
    struct node * YeniDugum = malloc(sizeof(struct node));
    YeniDugum->data = gelenData;

    struct node * SonEleman = GelenHead->prev;

    YeniDugum->prev = SonEleman;
    YeniDugum->next = GelenHead;
    GelenHead->prev = YeniDugum;
    SonEleman->next = YeniDugum;
    SonEleman = YeniDugum;
    return GelenHead; 

}
struct node * BastanSil(struct node * GelenHead)
{ 
    if(GelenHead ==  NULL)
    { 
        printf("Liste zaten bos! \n");
        return NULL;
    }
    else if(GelenHead->next == GelenHead)
    { 
        free(GelenHead); 
        return NULL;
    }else{ 
        struct node * silinecek = GelenHead; 
        struct node * YeniHead = GelenHead->next; 
        struct node * sonEleman = GelenHead->prev; 
        sonEleman->next = YeniHead; 
        YeniHead->prev = sonEleman; 
        free(silinecek); 
        return YeniHead; 

    }
}


struct node * arananSil(struct node * GelenHead, int arananSayi)
{
    if(GelenHead == NULL)
    {
        printf("Liste bos\n");
        return NULL;
    }

    struct node * temp = GelenHead;
    struct node * silinecek = NULL;

    do
    {
        if(temp->data == arananSayi)
        {
            silinecek = temp;
            break;
        }
        temp = temp->next;
    } while(temp != GelenHead);

    if(silinecek == NULL)
    {
        printf("Sayi bulunamadi\n");
        return GelenHead;
    }

    if(silinecek->next == silinecek)
    {
        free(silinecek);
        return NULL;
    }

    struct node * onceki = silinecek->prev;
    struct node * sonraki = silinecek->next;

    onceki->next = sonraki;
    sonraki->prev = onceki;

    if(silinecek == GelenHead)
    {
        GelenHead = sonraki;
    }

    free(silinecek);
    return GelenHead;
}


struct node * sondanSilme(struct node * GelenHead)
{ 
        if(GelenHead ==  NULL)
    { 
        printf("Liste zaten bos! \n");
        return NULL;
    }
    else if(GelenHead->next == GelenHead)
    { 
        free(GelenHead); 
        return NULL;
    }else{ 
        struct node * silinecek = GelenHead->prev; 
        struct node * yeniSon = silinecek->prev;
        yeniSon->next = GelenHead; 
        GelenHead->prev = yeniSon;        
        return GelenHead; 

    }
}

int main()
{ 
    struct node * head = malloc(sizeof(struct node)); 
    head->data = 1;
    head->prev = NULL;

    head->next = malloc(sizeof(struct node )); 
    head->next->data = 2; 
    head->next->prev = head; 

    head->next->next = malloc(sizeof(struct node)); 
    head->next->next->data = 3; 
    head->next->next->prev = head->next;
    head->next->next->next = head;

    head->prev = head->next->next; 
    head = basinaEkle(head, 0); 
    head = sonaEkleme(head, 4);
    head = sonaEkleme(head, 5);
    head = sonaEkleme(head, 6);
    head = sonaEkleme(head, 7);
    head = sonaEkleme(head, 8);
    head = sonaEkleme(head, 9);
    // Listeler_Yaz(head);
    
    // struct node * head2 = NULL ;
    // head2 = BastanSil(head2);
    head = BastanSil(head);
    // Listeler_Yaz(head);
    head = sondanSilme(head); 
    // Listeler_Yaz(head);
    head = arananSil(head, 6);
    Listeler_Yaz(head);
     


    
}