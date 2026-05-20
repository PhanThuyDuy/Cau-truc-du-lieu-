#include <stdio.h>

// 1. Hàm ghi d? li?u t? bàn phím vào t?p tin f0
void ghiFile(char* filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) return;

    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        fwrite(&value, sizeof(int), 1, f);
    }
    fclose(f);
}

// 1. Hàm d?c d? li?u t? t?p tin và in ra màn hình
void docFile(char* filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) return;

    int value;
    printf("Du lieu trong file %s: ", filename);
    while (fread(&value, sizeof(int), 1, f) == 1) {
        printf("%d ", value);
    }
    printf("\n");
    fclose(f);
}

// 2. Hàm sao chép m ph?n t? t? f0 sang f1
void saoChepMPhanTu(char* f0, char* f1, int m) {
    FILE *src = fopen(f0, "rb");
    FILE *dest = fopen(f1, "wb");
    if (src == NULL || dest == NULL) return;

    int value, count = 0;
    while (count < m && fread(&value, sizeof(int), 1, src) == 1) {
        fwrite(&value, sizeof(int), 1, dest);
        count++;
    }

    fclose(src);
    fclose(dest);
    printf("Da sao chep %d phan tu sang %s.\n", count, f1);
}

// 3. Hàm d?m s? ph?n t? trên t?p tin f0
int demPhanTu(char* filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) return 0;

    fseek(f, 0, SEEK_END); // Nh?y d?n cu?i file
    long size = ftell(f);  // L?y t?ng s? byte
    fclose(f);

    return (int)(size / sizeof(int));
}

int main() {
    char *f0 = "f0";
    char *f1 = "f1";

    // Th?c hi?n ghi và d?c f0
    ghiFile(f0);
    docFile(f0);

    // Ð?m s? ph?n t?
    printf("So phan tu trong f0: %d\n", demPhanTu(f0));

    // Sao chép m ph?n t?
    int m;
    printf("Nhap so phan tu m muon sao chep: ");
    scanf("%d", &m);
    saoChepMPhanTu(f0, f1, m);

    // Ki?m tra k?t qu? ? f1
    docFile(f1);


    return 0;
}









