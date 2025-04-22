#include "header.h"
#include <limits.h>
#include <malloc.h>
#include "boolean.h"


address Alokasi(infotype X){
	address Orang = (address) malloc(sizeof(ElmtList));
	if (Orang != NULL)
	{
		Orang->Nm = X;
		Orang->q = NULL;
	}else printf("Alokasi Gagal\n");

	return Orang;
}

void DeAlokasi (address Orang)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	if (Orang == NULL)
	{
		printf("Dealokasi Gagal\n");
	}
	free(Orang);
	
	
}

void InitKota(Kota *A[], int size) {
    for (int i = 0; i < size; i++) {
	A[i] = malloc(sizeof(Kota));
        A[i]->kt = NULL;
        A[i]->p = NULL;
    }
}


void InsertKota(Kota * A[], int index, char* NamaKota){
	A[index-1]->kt = strdup(NamaKota);
}

void InsertNamaAwal(Kota * A[], int index, char * NamaOrang){
	address Orang;
	Orang = Alokasi(NamaOrang);
	if (Orang != NULL)
	{
		InsertFirst(A, index - 1, Orang);
	}
	
}


void InsertFirst(Kota * A[], int index, address Orang){
	Orang->q = A[index]->p;
	A[index]->p = Orang;
	
}


void InsertNamaAkhir(Kota * A[], int index, char * NamaOrang){
	address Orang;
	Orang = Alokasi(NamaOrang);
	if (Orang != NULL)
	{
		InsertLast(A, index - 1, Orang);
	}
	
}

void InsertLast(Kota * A[], int index, address Orang){
		/* Kamus Lokal */
		address Last;
		/* Algoritma */
		if (A[index]->p == NULL)
		{
			A[index]->p = Orang;
	   }else{
		   
		   Last = A[index]->p;
		   while (Last->q != NULL)
		   {
			   Last = Last->q;
			}
			Last->q = Orang;
		}
		
		
		//Buatkan algoritma sesuai spesifikasi modul ini
		
	}
	
	address SearchPrec(Kota * A[], int index, infotype X)
/* index sesuai urutan kota, bukan index array C 0-based */
{
    address Prec = NULL, Temp = A[index - 1]->p;
    boolean found = false;

    while ((Temp != NULL) && (!found)) {
        if (strcmp(Temp->Nm, X) == 0) {
            found = true;
        } else {
            Prec = Temp;
            Temp = Temp->q;
        }
    }

		if (found && Prec != NULL) {
			return Prec;
		} else {
			return NULL;  // Jika elemen pertama atau tidak ketemu
		}
}


	void InsertAfter (address Orang, address Prec){
		Orang->q = Prec->q;
		Prec->q = Orang;
	
	}
	
	void DelKota(Kota * A[], int index){
		if (A[index - 1] != NULL)
	{
		address temp = A[index - 1]->p;
		while (temp != NULL)
		{
			temp = temp->q;
			A[index - 1]->p->q = NULL;
			DeAlokasi(A[index - 1]->p);
			A[index - 1]->p = temp;
		}
		A[index - 1]->kt = NULL;
		A[index - 1]->p = NULL;
	}
	
}


void PrintKota(Kota *A[], int max) {
    for (int i = 0; i < max; i++) {
        if (A[i] != NULL && A[i]->kt != NULL) {
            printf("%d. %s\n", i + 1, A[i]->kt);
        } else {
            printf("%d. [Kosong]\n", i + 1);
        }
    }
}

void PrintList(Kota *A[], int index) {
    if (A[index - 1] == NULL || A[index - 1]->kt == NULL) {
        printf("Kota di posisi %d belum diinisialisasi.\n", index);
        return;
    }else{

		printf("Di Kota %s:\n", A[index - 1]->kt);
		address p = A[index - 1]->p;
		int i = 1;
		while (p != NULL) {
			printf("%d. %s\n", i++, p->Nm);  // asumsi field-nya bernama `nm`
			p = p->q;
		}
	}

}
