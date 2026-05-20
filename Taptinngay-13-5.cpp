	#include <stdio.h>
	
	void ghiFile(char* filename);
	void docFile(char* filename);
	int demPhanTu(char* filename);
	void phanBo(const char* f0, const char* f1, const char* f2, int m);
	void tronRun(const char* f0, const char* f1, const char* f2, int m);
	
	int main() {
	
	    char *f0 = "f0.dat";
	    char *f1 = "f1.dat";
	    char *f2 = "f2.dat";
	
	    int m;
	
	    // Ghi du lieu vao file f0
	    ghiFile(f0);
	
	    // Doc file f0
	    printf("\nNoi dung file f0:\n");
	    docFile(f0);
	
	    // Dem so phan tu
	    printf("So phan tu trong file f0: %d\n", demPhanTu(f0));
	
	    // Nhap m
	    printf("Nhap m: ");
	    scanf("%d", &m);
	
	    // Phan bo du lieu tu f0 sang f1 va f2
	    phanBo(f0, f1, f2, m);
	
	    // Doc file f1
	    printf("\nNoi dung file f1:\n");
	    docFile(f1);
	
	    // Doc file f2
	    printf("\nNoi dung file f2:\n");
	    docFile(f2);
	
	    // Tron du lieu tu f1 va f2 vao f0
	    tronRun(f0, f1, f2, m);
	
	    // Doc lai file f0
	    printf("\nNoi dung file f0 sau khi tron:\n");
	    docFile(f0);
	
	    return 0;
	}
	
	// Ham ghi du lieu vao file
	void ghiFile(char* filename) {
	
	    FILE *f = fopen(filename, "wb");
	
	    if (f == NULL) {
	        printf("Khong mo duoc file!\n");
	        return;
	    }
	
	    int n, x;
	
	    printf("Nhap so luong phan tu: ");
	    scanf("%d", &n);
	
	    for (int i = 0; i < n; i++) {
	
	        printf("Nhap phan tu thu %d: ", i + 1);
	        scanf("%d", &x);
	
	        fwrite(&x, sizeof(int), 1, f);
	    }
	
	    fclose(f);
	}
	
	// Ham doc du lieu tu file
	void docFile(char* filename) {
	
	    FILE *f = fopen(filename, "rb");
	
	    if (f == NULL) {
	        printf("Khong mo duoc file!\n");
	        return;
	    }
	
	    int x;
	
	    printf("Du lieu trong file %s: ", filename);
	
	    while (fread(&x, sizeof(int), 1, f) == 1) {
	        printf("%d ", x);
	    }
	
	    printf("\n");
	
	    fclose(f);
	}
	
	// Ham dem so phan tu trong file
	int demPhanTu(char* filename) {
	
	    FILE *f = fopen(filename, "rb");
	
	    if (f == NULL) {
	        return 0;
	    }
	
	    fseek(f, 0, SEEK_END); //dua con tro toi cuoi file 
	
	    long size = ftell(f);
	
	    fclose(f);
	
	    return size / sizeof(int);
	}
	
		// Ham phan bo m phan tu tu f0 sang f1 va f2
	void phanBo(const char* f0, const char* f1, const char* f2, int m) {
	
	    FILE *fp0 = fopen(f0, "rb");
	    FILE *fp1 = fopen(f1, "wb");
	    FILE *fp2 = fopen(f2, "wb");
	
	    if (fp0 == NULL || fp1 == NULL || fp2 == NULL) {
	        printf("Khong mo duoc file!\n");
	        return;
	    }
	
	    int x;
	
	    while (fread(&x, sizeof(int), 1, fp0) == 1) {
	
	        // Ghi phan tu dau tien vao f1
	        fwrite(&x, sizeof(int), 1, fp1);
	
	        // Ghi them m-1 phan tu vao f1
	        for (int i = 1; i < m; i++) {
	
	            if (fread(&x, sizeof(int), 1, fp0) == 1) {
	                fwrite(&x, sizeof(int), 1, fp1);
	            }
	        }
	
	        // Ghi m phan tu vao f2
	        for (int i = 0; i < m; i++) {
	
	            if (fread(&x, sizeof(int), 1, fp0) == 1) {
	                fwrite(&x, sizeof(int), 1, fp2);
	            }
	        }
	    }
	
	    fclose(fp0);
	    fclose(fp1);
	    fclose(fp2);
	}
		
	// Ham tron m phan tu tu f1 va f2 vao f0
	void tronRun(const char* f0, const char* f1, const char* f2, int m) {
	
	    FILE *fp0 = fopen(f0, "wb");
	    FILE *fp1 = fopen(f1, "rb");
	    FILE *fp2 = fopen(f2, "rb");
	
	    if (fp0 == NULL || fp1 == NULL || fp2 == NULL) {
	        printf("Khong mo duoc file!\n");
	        return;
	    }
	
	    int x1, x2;
	    int c1, c2;
	
	    while (1) {
	
	        c1 = fread(&x1, sizeof(int), 1, fp1);
	        c2 = fread(&x2, sizeof(int), 1, fp2);
	
	        if (c1 != 1 && c2 != 1) {
	            break;
	        }
	
	        if (c1 == 1) {
	            fwrite(&x1, sizeof(int), 1, fp0);
	        }
	
	        if (c2 == 1) {
	            fwrite(&x2, sizeof(int), 1, fp0);
	        }
	    }
	
	    fclose(fp0);
	    fclose(fp1);
	    fclose(fp2);
	}
