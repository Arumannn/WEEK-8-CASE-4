#ifndef HEADER_H
#define HEADER_H


typedef char* infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype Nm;
	 address  q;
	 } ElmtList;

typedef struct {
    infotype kt;
    address p;
}Kota;

address Alokasi(infotype X);
void DeAlokasi (address Orang);
void InitKota(Kota *A[], int size);
void PrintKota(Kota * A[], int max);
void InsertNamaAwal(Kota * A[], int index, char * NamaOrang);
void InsertNamaAkhir(Kota * A[], int index, char * NamaOrang);
void InsertFirst(Kota * A[], int index, address Orang);
void InsertLast(Kota * A[], int index, address Orang);
void InsertKota(Kota * A[], int index, char* NamaKota);
void PrintList(Kota * A[], int index);
void DelVFirst(Kota * A[], int index, infotype Nama);
address SearchPrec (Kota * A[], int index, infotype X);
void InsertAfter (address Orang, address Prec);
#endif