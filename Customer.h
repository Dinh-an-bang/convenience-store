#pragma once
#include "convenient_store_library.h"
#include "Common.h"



// customers membership tiers
// enumration dat ten kieu du lieu theo bien int (thay vi 1 2 3 4 thi ta co brozen, sliver, ... )
typedef enum {
    BRONZE,
    SILVER,
    GOLD,
    PLATINUM
} MembershipTier;


// struct customer
typedef struct Customer{
	char ID[12];  // ma cua khach hang
	char Name[80]; // ten cua khach hang
	char email[50]; // email cua khach hang
	char phone[20]; // so dien thoai cua khach hang
	char address[100]; // dia chi cua khach hang
	int points; // so diem cua khach hang
	MembershipTier tier; // goi struct mt ra de dinh dang cho tier de sap xep bac khach hang
	Date join_date; // ngay khach hang gia nhap membership
	struct Customer *next;
} Customer;

void addCustomer(Customer **head);
void displaycustomer(Customer *pointer);
void displaycustomers(Customer *head);
Customer *findCustomerByID(Customer *head, const char *id);
Customer *findCustomerByPhone(Customer *head, const char *phone);
void updateCustomer(Customer *head, const char *id);
void deleteCustomer(Customer **head, const char *id);
void sortCustomersByTier(Customer **head, bool ascending);
void checkCustomerMembership(Customer *customer);

// File input/output
void saveCustomersToFile(Customer *head, const char *fileName);
void readCustomersFromFile(Customer **head, const char *fileName);
