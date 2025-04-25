// identityorang.h
#ifndef IDENTITYORANG_H
#define IDENTITYORANG_H

typedef char* string;
typedef struct Orang *OrangPTR;
typedef struct Kota *KotaPTR;

typedef struct Orang {
    string nama;
    OrangPTR nextOrang;
} Orang;

typedef struct Kota {
    string namaKota;
    KotaPTR nextKota;
    OrangPTR daftarOrang;
} Kota; 

void tambahOrang(Kota *p, string nama);
void hapusKota(Kota *p);
void tambahKota(KotaPTR *head, string nama);
void hapusOrang(KotaPTR p);
void tampilkanKota(KotaPTR head);
void hapusKotaSesuaiNama(KotaPTR *head, string nama);
void insertAwal(Kota *p, string nama);
void insertAkhir(Kota *p, string nama);
void insertTengah(Kota *p, string nama);


#endif
