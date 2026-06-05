#include <stdio.h>
#include <string.h>
#include <stdlib.h>
		
#define NULLKEY -1
#define M 10 // Do lai M cua bang bam = 10

// Khai bao cau truc du lieu bang bam
typedef struct sv {
    int khoa;       // Truong khoa
    char hoten[50]; // Truong ho ten
} sv;

typedef struct {
    sv info[M];
    int N; // So phan tu hien tai trong bang bam
} bangbam;
		
// Khai bao cac ham hoat dong
int hb(int k);
void init(bangbam *ht);
void nhapmang(sv a[M], int n);
void xuatmang(sv a[M], int n);
int isFull(bangbam ht);
int isEmpty(bangbam ht);
int search(bangbam ht, int x);
void insert(bangbam *ht, sv a);

// =================== HAM MAIN ===================
int main() {
    sv b[M];      // Khai bao mang du lieu (toi da M-1)
    bangbam tta;  // Khai bao bang bam
    int n; 
    
    // 1. Nhap n (voi n < M)
    do {
        printf("Nhap so luong sinh vien n (n < %d): ", M);
        scanf("%d", &n);
    } while(n <= 0 || n >= M);
    
    // 2. Nhap n phan tu vao mang du lieu
    printf("\n--- NHAP MANG DU LIEU ---\n");
    nhapmang(b, n);
    
    // 3. Xuat n phan tu mang du lieu vua nhap
    printf("\n--- MANG DU LIEU VUA NHAP ---");
    xuatmang(b, n);
    
    // 4. Khoi tao bang bam
    init(&tta);
    
    // 5. Them THU 1 phan tu bat ky tu mang vao bang bam de kiem tra
    printf("\n\n>>> Them thu phan tu dau tien cua mang vao bang bam...");
    insert(&tta, b[0]);
    
    printf("\n--- KET QUA BANG BAM SAU KHI THEM 1 PHAN TU ---");
    xuatmang(tta.info, M);
    
    // 6. Them lan luot tat ca cac phan tu con lai tu mang vao bang bam
    printf("\n\n>>> Them tat ca cac phan tu con lai vao bang bam...");
    for(int i = 1; i < n; i++) {
        insert(&tta, b[i]);
    }
    
    // 7. Xuat ket qua bang bam cuoi cung de kiem tra
    printf("\n--- KET QUA BANG BAM CUOI CUNG ---");
    xuatmang(tta.info, M);
    printf("\nTong so phan tu thuc te trong bang bam: N = %d\n", tta.N);
    
    return 0;
}

// ================= DINH NGHIA HAM =================

// Ham bam: h(k) = k mod M
int hb(int k) {
    return (k % M);
}
		
// Ham khoi tao bang bam
void init(bangbam *ht) {
    for (int i = 0; i < M; i++) {
        ht->info[i].khoa = NULLKEY; // Gan tat ca khoa cua cac phan tu = rong (-1)
    }
    ht->N = 0; // Gan N = 0
}
	
// Ham nhap mang sinh vien
void nhapmang(sv a[M], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap khoa (so nguyen) [%d]: ", i);
        scanf("%d", &a[i].khoa);
        
        // Xoa bo nho dem de tranh troi lenh khi nhap chuoi
        while (getchar() != '\n'); 
        
        printf("Nhap ho ten [%d]: ", i);
        fgets(a[i].hoten, sizeof(a[i].hoten), stdin);
        a[i].hoten[strcspn(a[i].hoten, "\n")] = '\0'; // Xoa ky tu '\n' do fgets tao ra
    }
}
	
// Ham xuat du lieu theo dinh dang yeu cau
void xuatmang(sv a[M], int n) {
    printf("\nVi tri:\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", i);
    }
    printf("\nKhoa:\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i].khoa);
    }
}

// Ham kiem tra bang bam day (Day khi N = M - 1)
int isFull(bangbam ht) {
    if (ht.N == M - 1) 
        return 1; // Bang bam day
    return -1;    // Bang bam chua day
}

// Ham kiem tra bang bam rong
int isEmpty(bangbam ht) {
    if (ht.N == 0) 
        return 1; // Bang bam rong
    return -1;    // Bang bam khong rong
}

// Ham tim kiem khoa x tren bang bam bang do tuyen tinh
int search(bangbam ht, int x) {
    int i = hb(x); // Gan i = hb(x)
    
    // Trong khi vi tri i co khoa khac x va khac rong thi tinh vi tri tiep theo
    while (ht.info[i].khoa != x && ht.info[i].khoa != NULLKEY) {
        i = (i + 1) % M;
    }
    
    // Kiem tra neu vi tri dung lai co khoa bang x
    if (ht.info[i].khoa == x) {
        return i; // Tim thay x tai vi tri i
    }
    return -1; // Khong tim thay x
}

// Ham them phan tu vao bang bam bang do tuyen tinh
void insert(bangbam *ht, sv a) {
    // 1. Neu bang bam day thi thong bao va dung
    if (isFull(*ht) == 1) {
        printf("\n[Loi] Khong the them vi bang bam da day!");
        return;
    }
    
    // 2. Neu tim thay khoa cua a da ton tai thi thong bao va dung
    if (search(*ht, a.khoa) != -1) {
        printf("\n[Loi] Khoa %d da ton tai trong bang bam!", a.khoa);
        return;
    }
    
    // 3. Gan i = hb(khoa cua a)
    int i = hb(a.khoa);
    
    // 4. Trong khi vi tri i khac rong thi tim vi tri ke tiep
    while (ht->info[i].khoa != NULLKEY) {
        i = (i + 1) % M;
    }
    
    // 5. Do cho trong tai i, gan gia tri va tang N
    ht->info[i] = a;
    ht->N++;
    printf("\n[Thanh cong] Da them khoa %d vao vi tri %d", a.khoa, i);
}
