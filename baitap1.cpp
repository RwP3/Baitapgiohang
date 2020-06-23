#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct st_sp
	{
    	char tensp[30];
    	int soluong;
    	int gia;
    	};
struct giohang_st 
{
    char tenkhachhang[30];
    char diachi[50];
    int sosanpham;
    st_sp dssp[30];
};
// tao thong tin nguoi dung
void Taogiohang(giohang_st *a){
		printf("\n____________________________________\n");
		printf("Nhap ten khach hang: \n");fflush(stdin);gets(a->tenkhachhang);
		printf("Nhap dia chi: \n");fflush(stdin);	gets(a->diachi);
		a->sosanpham=0;
		printf("\n***GIO CUA BAN DA DUOC KHOI TAO***\n");
}
//nhap san pham
void Chonhang(giohang_st *a){
	a->sosanpham++;
	printf("\nNhap ten san pham: ");fflush(stdin);gets(a->dssp[a->sosanpham-1].tensp);
	printf("\nNhap so luong: ");fflush(stdin);scanf("%d", &a->dssp[a->sosanpham-1].soluong);
	printf("\nNhap gia: ");fflush(stdin);scanf("%d", &a->dssp[a->sosanpham-1].gia);
	printf("\n***NHAP SAN PHAM THANH CONG***\n");
}
// sap xep gio hang theo thu tu A-> Z
void sapxep(giohang_st *a){
	st_sp temp;
	for(int i= 0; i < a->sosanpham-1; i++){
		if(a->dssp[i].tensp[0] > a->dssp[i+1].tensp[0]){
			temp = a->dssp[i];
			a->dssp[i] = a->dssp[i+1];
			a->dssp[i+1] = temp;
		}
	}
}
// Loai bo 1 san pham trong gio hang
void loaibomotmathang(giohang_st *a){
	int sanpham;
	printf("\nCan loai bo san pham thu may: ");
	scanf("%d",&sanpham);
	fflush(stdin);
	if(sanpham<= 0||sanpham>a->sosanpham){
		printf("***GIO KHONG TON TAI STT NAY VUI LONG BAN NHAP LAI!***");
	}
	else{
	for(int i=sanpham-1;i<a->sosanpham-1; i++ ){
			a->dssp[i] = a->dssp[i+1];
		}
	printf("***LOAI BO SAN PHAM THANH CONG***");
	a->sosanpham--;
	}
}
// ghi toan bo noi dung vao tep nhi phan cart.dat
void ghitepnhiphan(giohang_st a,FILE *p){
	p = fopen("cart.dat", "w+b");
	fwrite(&a.tenkhachhang, sizeof(giohang_st), 1, p);
	fwrite(&a.diachi, sizeof(giohang_st), 1, p);
	fwrite(&a.sosanpham, sizeof(giohang_st), 1, p);
	for(int i = 0; i < a.sosanpham; i++){
		fwrite(&a.dssp[i], sizeof(giohang_st), 1, p);
	}
	fclose(p);
}

void xemchitietgiohang(giohang_st a){
	int Tonggia=0;
printf("\n*********************CHI TIET GIO HANG**********************\n");
	printf("| Ten Khach hang : %-41s |\n", a.tenkhachhang);
	printf("| Dia chi: %-49s |\n", a.diachi);
	printf("| So san pham: %-46d|\n", a.sosanpham);
	printf("|------------------------------------------------------------|\n");
	printf("||%-5s|%-30s|%-10s|%-10s||\n", "STT", "Ten san pham", "So luong","Gia");
	printf("|------------------------------------------------------------|\n");
	for(int i=0;i<a.sosanpham;i++){
		printf("||%-5d|%-30s|%-10d|%-10d||\n", i+1, a.dssp[i].tensp, a.dssp[i].soluong,a.dssp[i].gia);
		Tonggia=Tonggia+(a.dssp[i].gia*a.dssp[i].soluong);
		printf("|------------------------------------------------------------|\n");
	}
		printf("||%-45s", "                                    Tong gia:");
		printf("   %-12d||",Tonggia);
	printf("\n**************************************************************\n\n");
}				
	
void menu(){
giohang_st giocuatoi;
FILE *p;
int chon=0;
int chonn=0;
{
	do
	{
		system("cls");
        printf("\t\t ========================M E N U==============================\n");
        printf("\t\t |1. Tao gio hang                                            |\n");
        printf("\t\t |2. Chon san pham                                           |\n");
        printf("\t\t |3. Xem chi tiet gio hang                                   |\n");
		printf("\t\t |4. Loai bo 1 mat hang                                      |\n");
        printf("\t\t |5. Ghi toan bo noi dung gio hang vao tep nhi phan cart.dat |\n");
        printf("\t\t |6. Thoat                                                   |\n");
        printf("\t\t =============================================================\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
		switch(chon){
			case 1:
				printf("\nBan da chon Tao gio hang ");
				Taogiohang(&giocuatoi);
				printf("\n____________________________________\n");
				printf("\nnhan ENTER de chon lai menu\n");
				getch();
				break;
			case 2:
				printf("Ban da chon 'Chon hang'");
				Chonhang(&giocuatoi);
				printf("\n____________________________________\n");
				printf("\nnhan ENTER de chon lai menu\n");
				getch();
				break;
			case 3:
				printf("Ban da chon xem chi tiet gio hang");
				if(giocuatoi.sosanpham >0){	
					sapxep(&giocuatoi);
					xemchitietgiohang(giocuatoi);
				}
				 else{	
				printf("\n***GIO CUA BAN HIEN DANG TRONG VUI LONG CHON SAN PHAM CUA MINH***");
				}
				printf("\n____________________________________\n");
				printf("\nnhan ENTER de chon lai menu\n");
				getch();
				break;
			case 4:
				printf("Ban da chon Loai bo 1 mat hang");
				loaibomotmathang(&giocuatoi);
				printf("\n____________________________________\n");
				printf("\nnhan ENTER de chon lai menu\n");
				getch();
				break;
			case 5:
				printf("Ban da chon Ghi toan bo noi dung gio hang vao tep nhi phan cart.dat'");
				ghitepnhiphan(giocuatoi,p);
				printf("\n***GHI VAO THANH CONG!***");
				printf("\n____________________________________\n");
				printf("\nnhan ENTER de chon lai menu\n");
				getch();
				break;
			case 6:
				printf("Ban co chac la muon thoat chuong trinh khong ");
				{
				
				do
				{
					system("cls");
					printf("1.YES\t");
					printf("2.NO\t");
					printf("\nBan chon:");
					scanf("%d",&chonn);
					switch(chonn){
									case 1 : 
									exit(0);
									case 2 :
									printf("Ban chon NO\n");
									printf("Moi ban nhan Enter de tro lai menu");
									getch();
									menu();
									default:
									printf("\nBan chon sai. Moi ban nhan ENTER de chon lai!\n");
								}
				}
				while(chonn!=2);
			}
			default:
				printf("Ban chon sai. Moi ban nhan ENTER de chon lai MENU!\n");
				getch();		
		}
	}while(chon!=6);
}
}
int main(){
giohang_st giocuatoi;
FILE *p;
menu();
}






	

