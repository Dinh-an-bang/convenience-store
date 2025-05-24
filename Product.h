#pragma once
#include "convenient_store_library.h"

// khai bao cau truc Product de thuc hien cac chuc nang cho nguoi dung
typedef struct Product{
	char id[12]; // ma san pham toi da 12 ky tu + NULL
	char name[50]; // ten san pham toi da 50 ky tu
	char category[30]; // nhom san pham, danh muc san pham
	float price; //gia ban
	float cost; // gia ca
	int quantity; //so luong trong kho cua san pham
	int min_quantity; // so luong toi thieu
	Date  expiry_date; // ngay het han
	Date import_date; // ngay ngap san pham
	struct Product* next; // con tro tro den san pham tiep theo cua link list
} Product;

// product Function
void addProduct(Product **head);
void displayProduct(Product *pointer);
void displayProducts(Product *head);
Product *findProductById(Product *head, const char *id);
Product *findProductByName(Product *head, const char *name);
void updateProduct(Product *head, const char *id);
void deleteProduct(Product **head, const char *id);
void sortProductsByPrice(Product **head, bool ascending);
void checkLowStock(Product *head);

// file input/output
void saveProductsToFile(Product *head, const char *fileName);
void readProductsFromFile(Product **head, const char *fileName);
