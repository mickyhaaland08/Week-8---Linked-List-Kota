#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "identityorang.h"

int main() {
    KotaPTR kotaList = NULL;
    int pilihan;
    char namaKota[100];
    char namaOrang[100];

    do {
        printf("\n=== MENU MANAJEMEN KOTA & ORANG ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Orang (Awal)\n");
        printf("3. Tambah Orang (Akhir)\n");
        printf("4. Tambah Orang (Tengah - urut abjad)\n");
        printf("5. Tampilkan Semua Kota dan Orang\n");
        printf("6. Hapus Semua Orang dari Kota\n");
        printf("7. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar(); // buang newline

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                tambahKota(&kotaList, namaKota);
                printf("Kota '%s' ditambahkan.\n", namaKota);
                break;

            case 2:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;

                for (KotaPTR kota = kotaList; kota != NULL; kota = kota->nextKota) {
                    if (strcmp(kota->namaKota, namaKota) == 0) {
                        insertAwal(kota, namaOrang);
                        printf("Orang '%s' ditambahkan ke awal kota '%s'.\n", namaOrang, namaKota);
                        break;
                    }
                }
                break;

            case 3:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;

                for (KotaPTR kota = kotaList; kota != NULL; kota = kota->nextKota) {
                    if (strcmp(kota->namaKota, namaKota) == 0) {
                        insertAkhir(kota, namaOrang);
                        printf("Orang '%s' ditambahkan ke akhir kota '%s'.\n", namaOrang, namaKota);
                        break;
                    }
                }
                break;

            case 4:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;

                for (KotaPTR kota = kotaList; kota != NULL; kota = kota->nextKota) {
                    if (strcmp(kota->namaKota, namaKota) == 0) {
                        insertTengah(kota, namaOrang);
                        printf("Orang '%s' ditambahkan ke kota '%s' secara terurut.\n", namaOrang, namaKota);
                        break;
                    }
                }
                break;

            case 5:
                {
                    int count = 0;
                    for (KotaPTR temp = kotaList; temp != NULL; temp = temp->nextKota) count++;
                    tampilkanKota(kotaList);
                }
                break;

            case 6:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                for (KotaPTR kota = kotaList; kota != NULL; kota = kota->nextKota) {
                    if (strcmp(kota->namaKota, namaKota) == 0) {
                        hapusKota(kota);
                        printf("Semua orang di kota '%s' telah dihapus.\n", namaKota);
                        break;
                    }
                }
                break;

            case 7:
                printf("Terima kasih. Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 7);

    // Bebaskan memori kota dan orang
    while (kotaList != NULL) {
        KotaPTR kota = kotaList;
        kotaList = kotaList->nextKota;
        hapusKota(kota);
        free(kota->namaKota);
        free(kota);
    }

    return 0;
}
