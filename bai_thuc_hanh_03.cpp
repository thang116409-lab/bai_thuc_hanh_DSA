#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;
typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
void initList(LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int emptyList(LList L) {
    return (L.spt == 0);
}
void nhap(Data *x) {
    printf("Nhap ma sinh vien (<=0 de huy): ");
    scanf("%d", &x->masv);
    if (x->masv > 0) {
        getchar();
        printf("Nhap ho ten: ");
        fgets(x->hoten, sizeof(x->hoten), stdin);
        printf("Nhap diem mon 1: ");
        scanf("%f", &x->d1);
        printf("Nhap diem mon 2: ");
        scanf("%f", &x->d2);
        printf("Nhap diem mon 3: ");
        scanf("%f", &x->d3);
    }
}

void in(Data x) {
    printf("Ma SV : %d\n", x.masv);
    printf("Ho ten: %s", x.hoten);
    printf("Diem 1: %.2f\n", x.d1);
    printf("Diem 2: %.2f\n", x.d2);
    printf("Diem 3: %.2f\n", x.d3);
}

void processList(LList L) {
    Node *pp = L.pHead;

    if (pp == NULL) {
        printf("\nDanh sach rong!\n");
        return;
    }

    while (pp != NULL) {
        in(pp->infor);
        pp = pp->link;
    }
}

void insert_Head(LList *L, Data x) {
    Node *pp = (Node*)malloc(sizeof(Node));

    pp->infor = x;
    pp->link = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    }
    else {
        pp->link = L->pHead;
        L->pHead = pp;
    }

    L->spt++;
}

void insert_Tail(LList *L, Data x) {
    Node *pp = (Node*)malloc(sizeof(Node));

    pp->infor = x;
    pp->link = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    }
    else {
        L->pTail->link = pp;
        L->pTail = pp;
    }

    L->spt++;
}

void insert_After(LList *L, Node *q, Data x) {
    if (q == NULL) return;

    Node *pp = (Node*)malloc(sizeof(Node));

    pp->infor = x;
    pp->link = q->link;
    q->link = pp;

    if (q == L->pTail)
        L->pTail = pp;

    L->spt++;
}

Node* search(LList L, int maCanTim) {
    Node *pp = L.pHead;

    while (pp != NULL) {
        if (pp->infor.masv == maCanTim)
            return pp;

        pp = pp->link;
    }

    return NULL;
}

void delete_Head(LList *L) {
    if (emptyList(*L)) {
        printf("Danh sach rong!\n");
        return;
    }

    Node *p = L->pHead;
    L->pHead = p->link;

    if (L->pHead == NULL)
        L->pTail = NULL;
    free(p);
    L->spt--;
    printf("Da xoa sinh vien dau danh sach!\n");
}
void delete_Tail(LList *L) {
    if (emptyList(*L)) {
        printf("Danh sach rong!\n");
        return;
    }
    if (L->pHead == L->pTail) {
        free(L->pHead);
        L->pHead = NULL;
        L->pTail = NULL;
    }
    else {
        Node *p = L->pHead;

        while (p->link != L->pTail)
            p = p->link;
        free(L->pTail);
        L->pTail = p;
        p->link = NULL;
    }
    L->spt--;
    printf("Da xoa sinh vien cuoi danh sach!\n");
}
void delete_ByID(LList *L, int maSV) {
    if (emptyList(*L)) {
        printf("Danh sach rong!\n");
        return;
    }
    Node *p = L->pHead;
    Node *truoc = NULL;
    while (p != NULL && p->infor.masv != maSV) {
        truoc = p;
        p = p->link;
    }
    if (p == NULL) {
        printf("Khong tim thay sinh vien!\n");
        return;
    }
    if (p == L->pHead) {
        L->pHead = p->link;

        if (L->pHead == NULL)
            L->pTail = NULL;
    }
    else {
        truoc->link = p->link;

        if (p == L->pTail)
            L->pTail = truoc;
    }
    free(p);
    L->spt--;

    printf("Da xoa sinh vien co ma %d\n", maSV);
}

int main() {
    LList L;
    Data x;
    int kt = 0;

    initList(&L);

    do {
        printf("\n1. Them vao dau");
        printf("\n2. Them vao cuoi");
        printf("\n3. Them sau mot sinh vien");
        printf("\n4. Tim sinh vien theo ma");
        printf("\n5. Xoa dau danh sach");
        printf("\n6. Xoa cuoi danh sach");
        printf("\n7. Xoa sinh vien theo ma");
        printf("\n8. Hien thi danh sach");
        printf("\n0. Thoat");
        printf("\nNhap lua chon: ");

        int chon;
        scanf("%d", &chon);

        switch (chon) {

        case 1:
            nhap(&x);
            if (x.masv > 0)
                insert_Head(&L, x);
            break;

        case 2:
            nhap(&x);
            if (x.masv > 0)
                insert_Tail(&L, x);
            break;

        case 3: {
            int ma;

            printf("Nhap ma sinh vien can chen sau: ");
            scanf("%d", &ma);
            Node *q = search(L, ma);
            if (q == NULL) {
                printf("Khong tim thay sinh vien!\n");
            }
            else {
                printf("Nhap thong tin sinh vien moi:\n");
                nhap(&x);

                if (x.masv > 0)
                    insert_After(&L, q, x);
            }
            break;
        }
        case 4: {
            int ma;
            printf("Nhap ma sinh vien can tim: ");
            scanf("%d", &ma);
            Node *p = search(L, ma);
            if (p == NULL)
                printf("Khong tim thay sinh vien!\n");
            else
                in(p->infor);
            break;
        }
        case 5:
            delete_Head(&L);
            break;
        case 6:
            delete_Tail(&L);
            break;
        case 7: {
            int ma;
            printf("Nhap ma sinh vien can xoa: ");
            scanf("%d", &ma);

            delete_ByID(&L, ma);
            break;
        }
        case 8:
            processList(L);
            break;
        case 0:
            printf("Tam biet!\n");
            kt = 1;
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (kt == 0);
    return 0;
}