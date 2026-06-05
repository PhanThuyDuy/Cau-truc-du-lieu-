#include <stdio.h>
#include <string.h>
#include <stdlib.h>
		
#define NULLKEY -1
#define M 10 // Dinh nghia do dai M cua bang bam = 10 [cite: 44]

// Khai bao cau truc du lieu bang bam [cite: 43]
typedef struct sv {
    int khoa;       // Truong khoa [cite: 45]
    char hoten[50]; // Truong ho ten [cite: 45]
} sv;

typedef struct {
    sv info[M]; // Bang bam chua M phan tu [cite: 46]
    int N;      // So phan tu N co trong bang bam [cite: 47]
} bangbam;
		
// Khai bao cac ham [cite: 48, 49, 50, 51, 52, 53, 54, 55, 64]
int hb(int k);
int hp(int k);
void init(bangbam *ht);
void nhapmang(sv a[M], int n);
void xuatmang(sv a[M], int n);
int isFull(bangbam ht);
int isEmpty(bangbam ht);
int search(bangbam ht, int x);
void insert(bangbam *ht, sv a);

// =================== HAM MAIN =================== [cite: 74]
int main() {
    sv b[M];      // Khai bao mang du lieu [cite: 75]
    bangbam tta;  // Khai bao bang bam
    int n; 
    
    // Nhap so luong phan tu nhap vao mang du lieu
    do {
        printf("Nhap so luong phan tu n (n < %d): ", M);
        scanf("%d", &n);
    } while(n <= 0 || n >= M);
    
    // Nhap mang du lieu [cite: 76]
    printf("\n--- NHAP MANG DU LIEU ---\n");
    nhapmang(b, n);
    
    // Khoi tao bang bam [cite: 77]
    init(&tta);
    
    // Them lan luot cac phan tu tu mang du lieu vao bang bam [cite: 78]
    printf("\n--- TIEN HANH BAM KEP VAO BANG BAM ---");
    for(int i = 0; i < n; i++) {
        insert(&tta, b[i]);
    }
    
    // Kiem tra ket qua: Xuat bang bam [cite: 79]
    printf("\n\n--- KET QUA BANG BAM CUOI CUNG ---");
    xuatmang(tta.info, M);
    printf("\nTong so phan tu thuc te trong bang bam: N = %d\n", tta.N);
    
    return 0;
}

// ================= DINH NGHIA HAM =================

// Vietham bam chinh hb(k) = (tong cac chu so cua k) % M 
int hb(int k) {
    int tong = 0;
    int temp = abs(k); // Dam bao thuat toan chay dung ca voi so am
    while (temp > 0) {
        tong += temp % 10;
        temp /= 10;
    }
    return (tong % M);
}

// Viet ham bam phu hp(k) = 9 - (k % 5) 
int hp(int k) {
    return (9 - (k % 5));
}
		
// Viet ham khoi tao [cite: 52]
void init(bangbam *ht) {
    for (int i = 0; i < M; i++) {
        ht->info[i].khoa = NULLKEY; // Gan tat ca khoa cua cac phan tu = rong [cite: 52]
    }
    ht->N = 0; // Gan N = 0 [cite: 52]
}
	
// Vietham nhap n phan tu [cite: 48]
void nhapmang(sv a[M], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap khoa [%d]: ", i);
        scanf("%d", &a[i].khoa);
        
        // Xoa bo nho dem truoc khi doc chuoi
        while (getchar() != '\n'); 
        
        printf("Nhap ho ten [%d]: ", i);
        fgets(a[i].hoten, sizeof(a[i].hoten), stdin);
        a[i].hoten[strcspn(a[i].hoten, "\n")] = '\0'; // Xoa ky tu xuong dong
    }
}
	
// Viet ham xuat n phan tu (gom 3 dong: chi so, khoa va ho ten) 
void xuatmang(sv a[M], int n) {
    // Dong 1: Chi so (Vi tri)
    printf("\nChi so:\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
    }
    // Dong 2: Khoa
    printf("\nKhoa:\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i].khoa);
    }
    // Dong 3: Ho ten
    printf("\nHo ten:\t");
    for (int i = 0; i < n; i++) {
        if (a[i].khoa == NULLKEY) {
            printf("[Rong]\t");
        } else {
            printf("%s\t", a[i].hoten);
        }
    }
    printf("\n");
}

// Viet ham kiem tra bang bam day [cite: 53]
int isFull(bangbam ht) {
    if (ht.N == M - 1) 
        return 1; // Bang bam day [cite: 53]
    return -1;    // Bang bam chua day [cite: 53]
}

// Viet ham kiem tra rong [cite: 54]
int isEmpty(bangbam ht) {
    if (ht.N == 0) 
        return 1; // Bang bam rong [cite: 54]
    return -1;    // Bang bam khong rong [cite: 54]
}

// Viet ham tim phan tu khoa x tren bang bam theo phuong phap bam kep [cite: 55]
int search(bangbam ht, int x) {
    int i = hb(x);   // Gan i=hb(x) [cite: 56]
    int j = hp(x);   // Gan j=hp(x) [cite: 57]
    int dem = 0;     // Gan dem=0 (so lan do) [cite: 58]
    
    // Trong khi (vi tri i bang bam co khoa khac x va khoa khac rong) va dem < M [cite: 59]
    while (ht.info[i].khoa != x && ht.info[i].khoa != NULLKEY && dem < M) {
        i = (i + j) % M; // gan i = (i+j)%M [cite: 60]
        dem = dem + 1;   // dem = dem + 1 [cite: 61]
    }
    
    // Neu vi tri i co khoa x thi tra ve vi tri i (tim thay x), dung [cite: 62]
    if (ht.info[i].khoa == x) {
        return i;
    }
    return -1; // nguoc lai tra ve -1 (khong tim thay x), dung [cite: 63]
}

// Viet ham them phan tu a vao bang bam theo phuong phap bam kep [cite: 64]
void insert(bangbam *ht, sv a) {
    // Neu ham bam day thi in thong bao va dung [cite: 65]
    if (isFull(*ht) == 1) {
        printf("\n[Loi] Khong the them khoa %d vi bang bam da day!", a.khoa);
        return;
    }
    
    // Neu tim thay khoa cua a thi in thong bao va dung [cite: 66]
    if (search(*ht, a.khoa) != -1) {
        printf("\n[Loi] Khoa %d da ton tai trong bang bam!", a.khoa);
        return;
    }
    
    int i = hb(a.khoa); // Gan i=hb(khoa cua a) [cite: 67]
    int j = hp(a.khoa); // Gan j=hp(khoa cua a) [cite: 68]
    int dem = 1;        // Gan Dem=1 (so len do) [cite: 69]
    
    // Trong khi vi tri i bang bam khac rong va dem < M [cite: 70]
    while (ht->info[i].khoa != NULLKEY && dem < M) {
        i = (i + j) % M; // gan i=(i+j)%M [cite: 71]
        dem = dem + 1;   // dem = dem+1 [cite: 72]
    }
    
    // Neu vi tri i cua bang bam la rong: Gan vi tri i cua bang bam = a va tang N [cite: 73]
    if (ht->info[i].khoa == NULLKEY) {
        ht->info[i] = a;
        ht->N++;
        printf("\n[Thanh cong] Da them khoa %d vao vi tri %d (Qua %d lan do)", a.khoa, i, dem);
    } else {
        printf("\n[Loi] Khong tim duoc vi tri trong phu hop cho khoa %d sau %d lan do!", a.khoa, dem);
    }
}
