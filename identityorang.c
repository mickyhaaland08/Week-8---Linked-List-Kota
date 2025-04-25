#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "identityorang.h"

// Fungsi untuk menambahkan orang di akhir list
void tambahOrang(Kota *p, string nama) {
    insertAkhir(p, nama); // cukup panggil insert akhir
}

void tambahKota(KotaPTR *head, string nama) {
    KotaPTR baru = (KotaPTR)malloc(sizeof(Kota));
    baru->namaKota = strdup(nama);
    baru->daftarOrang = NULL;
    baru->nextKota = *head;
    *head = baru;
}

// Fungsi untuk insert orang di awal list
void insertAwal(Kota *p, string nama) {
    OrangPTR baru = (OrangPTR) malloc(sizeof(Orang));
    baru->nama = strdup(nama);
    baru->nextOrang = p->daftarOrang;
    p->daftarOrang = baru;
}

// Fungsi untuk insert orang di akhir list
void insertAkhir(Kota *p, string nama) {
    OrangPTR baru = (OrangPTR) malloc(sizeof(Orang));
    baru->nama = strdup(nama);
    baru->nextOrang = NULL;

    if (p->daftarOrang == NULL) {
        p->daftarOrang = baru;
    } else {
        OrangPTR temp = p->daftarOrang;
        while (temp->nextOrang != NULL) {
            temp = temp->nextOrang;
        }
        temp->nextOrang = baru;
    }
}

// Fungsi untuk insert tengah
void insertTengah(Kota *p, string nama) {
    OrangPTR baru = (OrangPTR)malloc(sizeof(Orang));
    baru->nama = strdup(nama);
    baru->nextOrang = NULL;

    // Hitung panjang list orang
    int count = 0;
    OrangPTR temp = p->daftarOrang;
    while (temp != NULL) {
        count++;
        temp = temp->nextOrang;
    }

    int tengah = count / 2;

    if (p->daftarOrang == NULL || tengah == 0) {
        // Insert di awal
        baru->nextOrang = p->daftarOrang;
        p->daftarOrang = baru;
        return;
    }

    // Traverse ke node sebelum posisi tengah
    temp = p->daftarOrang;
    for (int i = 0; i < tengah - 1; i++) {
        temp = temp->nextOrang;
    }

    // Sisipkan node baru
    baru->nextOrang = temp->nextOrang;
    temp->nextOrang = baru;
}

// Hapus semua orang dari sebuah kota
void hapusKota(Kota *p) {
    OrangPTR current = p->daftarOrang;
    while (current != NULL) {
        OrangPTR hapus = current;
        current = current->nextOrang;
        free(hapus->nama);
        free(hapus);
    }
    p->daftarOrang = NULL;
}

// Hapus semua orang dari kota berdasarkan nama kota
void hapusKotaSesuaiNama(KotaPTR *head, string nama) {
    KotaPTR current = *head;
    KotaPTR prev = NULL;

    while (current != NULL) {
        if (strcmp(current->namaKota, nama) == 0) {
            // Hapus semua orang dulu
            hapusKota(current);

            // Lepas node kota dari linked list
            if (prev == NULL) {
                // Kepala list
                *head = current->nextKota;
            } else {
                prev->nextKota = current->nextKota;
            }

            free(current->namaKota);
            free(current);
            printf("Data kota '%s' berhasil dihapus.\n", nama);
            return;
        }

        prev = current;
        current = current->nextKota;
    }

    printf("Kota dengan nama '%s' tidak ditemukan.\n", nama);
}

void tampilkanKota(KotaPTR head) {
    if (head == NULL) {
        printf("Tidak ada kota yang terdaftar.\n");
        return;
    }

    KotaPTR kota = head;
    while (kota != NULL) {
        printf("Kota: %s\n", kota->namaKota);
        OrangPTR orang = kota->daftarOrang;
        int no = 1;

        while (orang != NULL) {
            printf("  %d. %s\n", no++, orang->nama);
            orang = orang->nextOrang;
        }

        if (no == 1) {
            printf("  (Tidak ada orang)\n");
        }

        kota = kota->nextKota;
    }
}
