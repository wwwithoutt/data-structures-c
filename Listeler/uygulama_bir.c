#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arac
{
    char plaka[10];
    char tip[20];
    int girisSaati ;
    int saatlikUcret;
    struct arac * next;
    struct arac * prev;
};

struct arac * giris ( struct arac  * head)
{
    char girilenPlaka[10];
    int aracsecim;

    printf("\n--- ARAC GIRISI ---\n");
    printf("Plaka giriniz: ");
    scanf("%9s", girilenPlaka);

    struct arac * temp  = head;
    while (temp != NULL)
    {
        if(strcmp(girilenPlaka, temp->plaka) == 0)
        {
            printf("Hata: Bu plaka sistemde zaten kayitli!\n");
            return head;
        }
        temp = temp->next;
    }

    struct arac * yeniArac = malloc(sizeof(struct arac));
    strcpy(yeniArac->plaka, girilenPlaka);

    printf("\nArac Tipini Seciniz:\n");
    printf("1 - Otomobil\n");
    printf("2 - Motor\n");
    printf("3 - Kamyonet\n");
    printf("Seciminiz: ");

    scanf("%d", &aracsecim);

    if(aracsecim == 1)
    {
        strcpy(yeniArac->tip, "Otomobil");
        yeniArac->saatlikUcret = 50;
    }
    else if( aracsecim == 2)
    {
        strcpy(yeniArac->tip, "Motor");
        yeniArac->saatlikUcret = 30;
    }
    else if( aracsecim == 3)
    {
        strcpy(yeniArac->tip, "Kamyonet");
        yeniArac->saatlikUcret = 200;
    }
    else{
        printf("Hata: Gecersiz secim yapildi!\n");
        free(yeniArac);
        return head;
    }

    printf("Giris saati (0-23): ");
    scanf("%d", &yeniArac->girisSaati);
    if(yeniArac->girisSaati < 0 || yeniArac->girisSaati > 23)
    {
        printf("Hata: Gecersiz saat girdiniz!\n");
        free(yeniArac);
        return head;
    }

    if(head == NULL)
    {
        yeniArac->prev = NULL;
        yeniArac->next = NULL;
        printf("Basariyla kaydedildi.\n");
        return yeniArac;
    }else
    {
        yeniArac->next = head;
        head->prev = yeniArac;
        yeniArac->prev = NULL;
        printf("Basariyla kaydedildi.\n");
        return yeniArac;
    }
}

struct arac * cikis(struct arac * head)
{
    int cikissaati;
    int toplamUcret;
    struct arac * temp = head;
    if(head == NULL)
    {
        printf("\nOtopark bos!\n");
        return NULL;
    }
    char girilenPlaka[10];
    printf("\n--- ARAC CIKISI ---\n");
    printf("Cikis yapacak aracin plakasi: ");
    scanf("%9s", girilenPlaka);

    while(strcmp(temp->plaka,  girilenPlaka) != 0)
    {
        temp = temp->next;
        if(temp == NULL)
        {
            printf("Hata: Aranan plaka bulunamadi!\n");
            return head;
        }
    }

    printf("Cikis saati (0-23): ");
    scanf("%d", &cikissaati);
    if(cikissaati < 0 || cikissaati > 23)
    {
        printf("Hata: Gecersiz saat girdiniz!\n");
        return head;
    }

    if(cikissaati > temp->girisSaati)
    {
        toplamUcret = (cikissaati - temp->girisSaati)* temp->saatlikUcret;
    }else
    {
        toplamUcret = ((24 - temp->girisSaati) + cikissaati) * temp->saatlikUcret;
    }

    printf("Toplam odenecek tutar: %d TL\n", toplamUcret);

    if(temp == head )
    {
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
    }else
    {
        struct arac * onceki = temp->prev;
        struct arac * sonraki = temp->next;

        onceki->next = sonraki;
        if(sonraki != NULL)
        {
            sonraki->prev = onceki;
        }
        free(temp);
        printf("Arac basariyla cikis yapti.\n");
        return head;
    }
    return head;
}

void listeler(struct arac * head)
{
    if(head == NULL)
    {
        printf("\nOtoparkta arac bulunamadi!\n");
    }
    else
    {
        printf("\n--- OTOPARKTAKİ ARACLAR ---\n");
        struct arac * temp = head;
        while(temp != NULL)
        {
            printf("--------------------------\n");
            printf("Plaka         : %s\n", temp->plaka);
            printf("Arac Tipi     : %s\n", temp->tip);
            printf("Giris Saati   : %02d:00\n", temp->girisSaati);
            printf("Saatlik Ucret : %d TL\n", temp->saatlikUcret);
            temp = temp->next;
        }
        printf("--------------------------\n");
    }
}

int main()
{
    struct arac * otoparkHead = NULL;
    int secim;

    while(1)
    {
        printf("\n=============================\n");
        printf("   OTOPARK YONETIM SISTEMI   \n");
        printf("=============================\n");
        printf(" 1 - Arac Girisi\n");
        printf(" 2 - Arac Cikisi\n");
        printf(" 3 - Araclar Listesi\n");
        printf(" 0 - Cikis\n");
        printf("-----------------------------\n");
        printf("Seciminizi yapiniz [0 - 3]: ");

        scanf("%d", &secim);

        switch(secim)
        {
            case 1 :
                otoparkHead = giris(otoparkHead);
                break;
            case 2 :
                otoparkHead = cikis(otoparkHead);
                break;
            case 3 :
                listeler(otoparkHead);
                break;
            case  0 :
                printf("Sistemden cikiliyor...\n");
                exit(0);
            default :
                printf("Hata: Gecersiz secim yapildi!\n");
                break;
        }
    }
}
