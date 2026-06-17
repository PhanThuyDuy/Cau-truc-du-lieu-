#include <stdio.h>

int main() {
    long long n;
    
    // Mang luu cac menh gia tien theo thu tu giam dan (tu 500k den 10k)
    int menh_gia[] = {500000, 200000, 100000, 50000, 20000, 10000};
    int so_loai_tien = sizeof(menh_gia) / sizeof(menh_gia[0]);
    
    // Mang luu so to tuong ung voi tung menh gia
    int so_to[6] = {0}; 
    
    printf("Nhap so tien can doi (phai chia het cho 10.000): ");
    scanf("%lld", &n);
    
    // Kiem tra dieu kien so tien hop le
    if (n <= 0 || n % 10000 != 0) {
        printf("So tien khong hop le! Phai la so duong va la boi so cua 10.000.\n");
        return 1;
    }
    
    long long so_tien_goc = n; // Giu lai so tien ban dau de in ket qua
    
    // Ap dung thuat toan tham lam (Greedy) de doi tien
    for (int i = 0; i < so_loai_tien; i++) {
        so_to[i] = n / menh_gia[i];  // Lay so to toi da co the doi cua menh gia hien tai
        n = n % menh_gia[i];         // So tien con lai can doi tiep
    }
    
    // Hien thi ket qua
    printf("\n--- Ket qua doi %lld dong ---\n", so_tien_goc);
    printf("Chi tiet cac loai tien nhan duoc:\n");
    
    int tong_so_to = 0;
    for (int i = 0; i < so_loai_tien; i++) {
        if (so_to[i] > 0) {
            printf("- %d to menh gia %d dong\n", so_to[i], menh_gia[i]);
            tong_so_to += so_to[i];
        }
    }
    
    printf("------------------------------------\n");
    printf("=> Tong so to tien nhan duoc: %d to.\n", tong_so_to);
    
    return 0;
}
