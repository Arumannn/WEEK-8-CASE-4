#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "body.c" // pastikan header & boolean juga disertakan

int main(){
    Kota *array[3];
    int panjang = sizeof(array) / sizeof(array[0]);
    address Prec, P;
    InitKota(array, panjang);

    boolean loop = false;
    int choice, subChoice, posisi;
    char Nama[20], DepanNama[20];

    while (!loop) {
        printf("\nMENU:\n");
        printf("1. Print\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("1. Print Semua Kota\n");
            printf("2. Print List Orang dalam Kota\n");
            printf("Pilih: ");
            scanf("%d", &subChoice);

            if (subChoice == 1) {
                PrintKota(array, panjang);
            } else if (subChoice == 2) {
                PrintKota(array, panjang);
                printf("Di posisi berapa: ");
                scanf("%d", &posisi);
                PrintList(array, posisi);
            }
            break;

        case 2:
            printf("0. Insert Kota\n");
            printf("1. Insert Awal\n");
            printf("2. Insert After \n");
            printf("3. Insert Akhir\n");
            printf("Pilih: ");
            scanf("%d", &subChoice);

            if (subChoice == 0) {
                printf("Nama Kota: ");
                scanf("%s", Nama);
                PrintKota(array, panjang);
                printf("Posisi (1-10): ");
                scanf("%d", &posisi);
                InsertKota(array, posisi, Nama);
            } else if (subChoice == 1) {
                printf("Nama Orang: ");
                scanf("%s", Nama);
                PrintKota(array, panjang);
                printf("Posisi Kota: ");
                scanf("%d", &posisi);
                InsertNamaAwal(array, posisi, strdup(Nama));
            }else if(subChoice == 2){
                printf("Nama Orang: ");
                scanf("%s", Nama);
                P = Alokasi(Nama);
                if (P != NULL){
                    PrintKota(array, panjang);
                    printf("Posisi Kota: ");
                    scanf("%d", &posisi);
                    PrintList(array, posisi);
                    printf("Di depan nama siapa: ");
                    scanf("%s", DepanNama);
                    Prec = SearchPrec(array, posisi, DepanNama);
                    if (Prec != NULL)
                    {
                        InsertAfter(P, Prec);
                        
                    }else printf("Tidak ada penyisipan tersebut");
                    
                }
            } else if (subChoice == 3) {
                printf("Nama Orang: ");
                scanf("%s", Nama);
                PrintKota(array, panjang);
                printf("Posisi Kota: ");
                scanf("%d", &posisi);
                InsertNamaAkhir(array, posisi, strdup(Nama));
            }
            break;
        case 3:
            printf("Kota (1-10) mana yang mau didelete :\n");
            PrintKota(array, panjang);
            printf("Posisi Kota: ");
            scanf("%d", &posisi);
            DelKota(array, posisi);
            break;
        case 4:
            loop = true;
            break;

        default:
            printf("Pilihan tidak tersedia.\n");
            break;
        }
    }

    return 0;
}
