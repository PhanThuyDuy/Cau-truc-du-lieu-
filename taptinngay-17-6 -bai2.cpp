#include <stdio.h>

// Dinh nghia cau truc cho mot loai do vat
typedef struct {
    char ten;          // Ten do vat (A, B, C, D...)
    float trong_luong; // Trong luong g_i
    float gia_tri;     // Gia tri v_i
    float don_gia;     // Don gia v_i / g_i
    int so_luong_chon; // So luong vat nay se duoc cho vao ba lo
} DoVat;

// Ham hoan vi 2 do vat khi sap xep
void hoan_vi(DoVat *x, DoVat *y) {
    DoVat temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int n = 4; // So luong loai do vat
    float W = 37; // Trong luong toi da cua ba lo
    
    // Khoi tao du lieu ban dau
    DoVat ds[4] = {
        {'A', 15, 30, 0, 0},
        {'B', 10, 25, 0, 0},
        {'C', 2,  2,  0, 0},
        {'D', 4,  6,  0, 0}
    };
    
    // BUOC 1: Tinh don gia cho tung loai do vat (don gia = gia tri / trong luong)
    for (int i = 0; i < n; i++) {
        ds[i].don_gia = ds[i].gia_tri / ds[i].trong_luong;
    }
    
    // BUOC 2: Sap xep do vat theo don gia tu CAO xuong THAP (Giam dan)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Neu don gia phia sau lon hon, hoan vi de dua don gia CAO len truoc
            if (ds[i].don_gia < ds[j].don_gia) {
                hoan_vi(&ds[i], &ds[j]);
            }
        }
    }
    
    // BUOC 3: Tien hanh thuat toan tham lam lua chon do vat
    float trong_luong_con_lai = W;
    float tong_gia_tri = 0;
    float tong_trong_luong = 0;
    
    for (int i = 0; i < n; i++) {
        // Lay so luong toi da cua do vat hien tai ma ba lo con chua duoc
        ds[i].so_luong_chon = (int)(trong_luong_con_lai / ds[i].trong_luong);
        
        // Cap nhat trong luong con lai va tinh tong gia tri, tong trong luong
        if (ds[i].so_luong_chon > 0) {
            trong_luong_con_lai -= ds[i].so_luong_chon * ds[i].trong_luong;
            tong_gia_tri += ds[i].so_luong_chon * ds[i].gia_tri;
            tong_trong_luong += ds[i].so_luong_chon * ds[i].trong_luong;
        }
    }
    
    // IN KET QUA RA MAN HINH (KHONG DAU)
    printf("--- DANH SACH DO VAT DA SAP XEP (DON GIA CAO -> THAP) ---\n");
    printf("%-10s %-12s %-10s %-10s %-15s\n", "Loai do", "Trong luong", "Gia tri", "Don gia", "So luong chon");
    for (int i = 0; i < n; i++) {
        printf("%-10c %-12.1f %-10.1f %-10.2f %-15d\n", 
               ds[i].ten, ds[i].trong_luong, ds[i].gia_tri, ds[i].don_gia, ds[i].so_luong_chon);
    }
    
    printf("\n--------------------------------------------------------\n");
    printf("Tong trong luong da dung: %.1f / %.1f\n", tong_trong_luong, W);
    printf("Tong gia tri lon nhat dat duoc: %.1f\n", tong_gia_tri);
    
    return 0;
} 