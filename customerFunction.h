#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common.h"


// add new customer
void addCustomer(Customer **head){
	Customer *new_customer = (Customer*)malloc(sizeof(Customer));
	
	if (new_customer == NULL){
		printf("\nOut of memory!!!");
		return;
	}
	
	printf("\n-------------ADD NEW CUSTOMER TO YOUR LIST-------------\n");

    // nhap ID khach hang
    {
    	// creat mot ID tam de check ID 
    	char temp_ID[80];
    printf("\nPlease input your customer ID (maximum 11 characters): ");
    
    while(true){
        fgets(temp_ID, sizeof(temp_ID), stdin);
        temp_ID[strcspn(temp_ID, "\n")] = '\0'; // xoa bo nho dem

        if (strlen(temp_ID) > 11){
            printf("Customer ID about 11 characters! Please try again (maximum 11 characters): ");
            continue;
        }
        
        // nhap ID tam vao Id chinh
        strcpy(new_customer->ID, temp_ID);
        break;
    }
}

    // nhap ten cho khach hang
   {
    	// creat mot Name tam de check Name co nhap hop ly hay khon
    	char temp_Name[200];
    printf("\nPlease input your customer NAME (maximum 79 charaters): ");
    
    while(true){
        fgets(new_customer->Name, sizeof(new_customer->Name), stdin);
	    new_customer->Name[strcspn(new_customer->Name, "\n")] = '\0'; // xoa bo nho dem

        if (strlen(temp_Name) > 79){
            printf("Customer Name about 79 characters! \n Please try again (maximum 79 characters): ");
            continue;
        }
        
        // nhap ten tam vao ten chinh
        strcpy(new_customer->Name, temp_Name);
        break;
    }
}
    
    
     // nhap emai cho khach hang
   {
    	// creat mot email tam de check email co nhap hop ly hay khon
    	char temp_email[100];
	printf("\nPlease input your customer EMAIL (maximum 49 charaters): ");
	    
    while(true){
        fgets(new_customer->email, sizeof(new_customer->email), stdin);
     	new_customer->email[strcspn(new_customer->email, "\n")] = '\0'; // xoa bo nho dem

        if (strlen(temp_email) > 49){
            printf("Customer email about 49 characters! \n Please try again (maximum 49 characters): ");
            continue;
        }
        
        // nhap email tam vao email chinh
        strcpy(new_customer->email, temp_email);
        break;
    }
}


     // nhap ten cho khach hang
   {
    	// creat mot PHONE_NUMER tam de check PHONE_NUMER co nhap hop ly hay khon
    	char temp_PHONE_NUMER[50];
    printf("\nPlease input your customer PHONE_NUMER (maximum 19 charaters): ");
    
    while(true){
        fgets(new_customer->phone, sizeof(new_customer->phone), stdin);
	    new_customer->phone[strcspn(new_customer->phone, "\n")] = '\0'; // xoa bo nho dem

        if (strlen(temp_PHONE_NUMER) > 19){
            printf("Customer Name about 19 characters! \n Please try again (maximum 19 characters): ");
            continue;
        }
        
        // nhap ten tam vao ten chinh
        strcpy(new_customer->phone, temp_PHONE_NUMER);
        break;
    }
}

     // nhap address cho khach hang
   {
    	// creat mot address tam de check address co nhap hop ly hay khon
    	char temp_address[200];
    printf("\nPlease input your customer ADDRESS (maximum 79 charaters): ");
    
    while(true){
       fgets(new_customer->address, sizeof(new_customer->address), stdin);
	   new_customer->address[strcspn(new_customer->address, "\n")] = '\0';// xoa bo nho dem

        if (strlen(temp_address) > 79){
            printf("Customer adddress about 79 characters! \n Please try again (maximum 79 characters): ");
            continue;
        }
        
        // nhap address tam vao address chinh
        strcpy(new_customer->address, temp_address);
        break;
    }
}
	
	printf("\nPlease input your customer POINTS: ");
	scanf("%d", &new_customer->points);
	while(getchar() != '\n');
	
	// setting membership tiers
    if(new_customer->points >= 1000){
        new_customer->tier = PLATINUM;
    } else if(new_customer->points >= 500){
        new_customer->tier = GOLD;
    } else if(new_customer->points >= 100){
        new_customer->tier = SILVER;
    } else {
        new_customer->tier = BRONZE;
    }
	
	// setting date customer join 
	new_customer->join_date = get_date_now();
	
	// add your list
	new_customer->next = *head;
	*head = new_customer;
}

// hien thi mot customer
void displaycustomer(Customer *pointer){
	if (pointer == NULL){
		printf("\nCustomer not found!!!");
		return;
	}
	
	// chuyen doi int thanh string de goi customer
	// dung const de co dinh
	const char *tier_string;
    switch(pointer->tier) {
        case BRONZE: tier_string = "Bronze";
		break;
        case SILVER: tier_string = "Silver";
		break;
        case GOLD: tier_string = "Gold";
		break;
        case PLATINUM: tier_string = "Platinum";
		break;
}
	printf("\n+================= PRODUCT INFORMATION =================+");
	printf("\n| %-20s : %-20s |","ID", pointer->ID);
	printf("\n| %-20s : %-20s |","Name", pointer->Name);
	printf("\n| %-20s : %-20s |","EMAIL", pointer->email);
	printf("\n| %-20s : %-20s |","PHONE_NUMBER", pointer->phone);
	printf("\n| %-20s : %-20s |","ADDRESS", pointer->address);
	printf("\n| %-20s : %-20d |","POINTS", pointer->points);
	printf("\n| %-20s : %-20s |","MEMBERSHIP_TIERS", tier_string);
	printf("\n| %-20s : %02d//%02d//%04d                |","JION_DAY_CUSTOMER",
	pointer->join_date.Day, pointer->join_date.Month, pointer->join_date.years);
	printf("\n+=====================================================+\n");
   }

//hien thi all list customer
void displaycustomers(Customer *head){
    if(head == NULL){
        printf("\nList customer is not found!");
        return;    
    }
    
    // hien thi bang customer
    printf("\n+------------+--------------------+----------------------+---------------+--------------------+----------+-----------------+---------------+\n");
    printf("| %-10s | %-14s | %-20s | %-13s | %-18s | %-8s | %-15s | %-17s |\n",
           "ID", "Join Day", "Email", "Phone Number", "Address", "Points", "Membership Tier", "Name");
    printf("+------------+--------------------+----------------------+---------------+--------------------+----------+-----------------+---------------+\n");

    Customer *current = head;
    while(current){
        const char *tier_string;
        switch(current->tier){
            case BRONZE: tier_string = "Bronze"; break;
            case SILVER: tier_string = "Silver"; break;
            case GOLD: tier_string = "Gold"; break;
            case PLATINUM: tier_string = "Platinum"; break;
        }
        
        printf("| %-10s | %02d/%02d/%04d     | %-20s | %-13s | %-18s | %-8d | %-15s | %-17s |\n",
               current->ID,
               current->join_date.Day, current->join_date.Month, current->join_date.years,
               current->email,
               current->phone,
               current->address,
               current->points,
               tier_string,
               current->Name);
               
        current = current->next;
    }
    printf("+------------+--------------------+----------------------+---------------+--------------------+----------+-----------------+---------------+\n");    
}
                     
// find customer by id
Customer *findCustomerByID(Customer *head, const char *id){
	Customer *currrent = head;
	while (currrent != NULL){
		if(strcmp(currrent->ID, id) == 0){
			return currrent;
		}
		currrent = currrent->next;
	}
	return NULL;
}

// find customer by name
Customer *findCustomerByPhone(Customer *head, const char *phone){
	Customer *current = head;
	
	while(current != NULL){
		if( strcmp(current->phone, phone) == 0){
			return current;
		}
	current = current->next;
	}
	return NULL;
}


// them thong tin cach hang thong qua id cua khach hang
void updateCustomer(Customer *head, const char *id){
	Customer *new_customer = findCustomerByID(head, id);
	if(new_customer == NULL){
		printf("\nCustomer ID not found!!!");
		return;
	}
	
	printf("\n-------------UPDATE THE NEW ID FOR THE CUSTOMER TO YOUR CONVENIENT STORE-------------\n");
	
	printf("\nPlease input your customer new ID (maximum 11 charaters): ");
	fgets(new_customer->ID, sizeof(new_customer->ID), stdin);
	new_customer->ID[strcspn(new_customer->ID, "\n")] = '\0';
	
	printf("\nPlease input your customer new NAME (maximum 79 charaters): ");
	fgets(new_customer->Name, sizeof(new_customer->Name), stdin);
	new_customer->Name[strcspn(new_customer->Name, "\n")] = '\0';
	
	printf("\nPlease input your customer new EMAIL (maximum 49 charaters): ");
	fgets(new_customer->email, sizeof(new_customer->email), stdin);
	new_customer->email[strcspn(new_customer->email, "\n")] = '\0';
	
	printf("\nPlease input your customer new PHONE_NUMER (maximum 19 charaters): ");
	fgets(new_customer->phone, sizeof(new_customer->phone), stdin);
	new_customer->phone[strcspn(new_customer->phone, "\n")] = '\0';
	
	printf("\nPlease input your customer new ADDRESS (maximum 79 charaters): ");
	fgets(new_customer->address, sizeof(new_customer->address), stdin);
	new_customer->address[strcspn(new_customer->address, "\n")] = '\0';
	
	printf("\nPlease input your customer new POINTS: ");
	scanf("%d", &new_customer->points);
	while(getchar() != '\n');
	
	// cap nhat diem moi cho khach hang
	if(new_customer->points >= 1000){
        new_customer->tier = PLATINUM;
    }else if(new_customer->points >= 500){
        new_customer->tier = GOLD;
    }else if(new_customer->points >= 100){
        new_customer->tier = SILVER;
    }else{
        new_customer->tier = BRONZE;
    }
	
	printf("\nProduct updated successfully!!!");
}

// xoa khach hang khoi list bang id
void deleteCustomer(Customer **head, const char *id){
	Customer *temp = *head;
	Customer *pointer = NULL;
	
	while(temp != NULL){
		if(strcmp(temp->ID,id) == 0){
			//neu la node dau thi pointer = NULL
			if(pointer == NULL){
				// cap nhat lai node dau
				*head = temp->next;
			}else{
				// check node giua den cuoi
				// noi truc tiep node truoc den node can xoa
				pointer->next = temp->next;
			}
			free(temp);
            printf("\nDelete %s successfully!!!", id);
            return;
		}
		
		pointer = temp;
		temp = temp->next;
	}
	printf("\n%s not found to delete!!!",id);
}

// sap sep customer theo tier
void sortCustomersByTier(Customer **head, bool ascending) {
    if (head == NULL || *head == NULL) {
        return;
    }

    for (Customer *i = *head; i != NULL; i = i->next) {
        for (Customer *j = i->next; j != NULL; j = j->next) {
            bool shouldSwap = ascending ? (i->tier > j->tier) : (i->tier < j->tier);
            if (shouldSwap) {
                // Swap tier
                MembershipTier tempTier = i->tier;
                i->tier = j->tier;
                j->tier = tempTier;

                // Swap points
                int tempPoints = i->points;
                i->points = j->points;
                j->points = tempPoints;

                // Swap join_date
                Date tempDate = i->join_date;
                i->join_date = j->join_date;
                j->join_date = tempDate;

                // Swap id, name, phone, email, address
                char tempID[12], tempName[80], tempPhone[20], tempEmail[50], tempAddress[100];
                //id
                strcpy(tempID, i->ID); strcpy(i->ID, j->ID); strcpy(j->ID, tempID);
                //name
                strcpy(tempName, i->Name); strcpy(i->Name, j->Name); strcpy(j->Name, tempName);
                //phone
                strcpy(tempPhone, i->phone); strcpy(i->phone, j->phone); strcpy(j->phone, tempPhone);
                //email
                strcpy(tempEmail, i->email); strcpy(i->email, j->email); strcpy(j->email, tempEmail);
                //address
                strcpy(tempAddress, i->address); strcpy(i->address, j->address); strcpy(j->address, tempAddress);
            }
        }
    }

    printf("\nSorting %s sucessfully!!!", ascending ? "ascending" : "not ascending");
}

// Check and display customer membership information
void checkCustomerMembership(Customer *customer) {
    if (customer == NULL) {
        printf("\nCustomer not found!");
        return;
    }

    //chuyen tu dang enum sang dang string
    const char *tier_string;
    switch(customer->tier) {
        case BRONZE: tier_string = "Bronze";
		break;
        case SILVER: tier_string = "Silver"; 
		break;
        case GOLD: tier_string = "Gold"; 
		break;
        case PLATINUM: tier_string = "Platinum"; 
		break;
    }
    
    // in ra thong tin khach hang khi duoc tim thay
    printf("\n+=============== MEMBERSHIP INFORMATION ====================+");
    printf("\n|   %-20s : %-29s    |", "Customer ID", customer->ID);
    printf("\n|   %-20s : %-29s    |", "Name", customer->Name);
    printf("\n|   %-20s : %-29s    |", "Current Tier", tier_string);
	printf("\n|   %-20s : %-29d    |", "Points", customer->points);

    
    // tinh toan luong diem can de khach hang len cap do tiep theo
    int pointsNeeded = 0;
    const char *nextTier = "Max tier!!!!";
    if (customer->tier < PLATINUM) {
        switch(customer->tier) {
            case BRONZE: 
                pointsNeeded = 100 - customer->points;
                nextTier = "Silver (100 points to upgrade)";
                break;
            case SILVER: 
                pointsNeeded = 500 - customer->points;
                nextTier = "Gold (500 points to upgrade)";
                break;
            case GOLD: 
                pointsNeeded = 1000 - customer->points;
                nextTier = "Platinum (1000 points to upgrade)";
                break;
        }
        printf("\n| %-20s   : %-32d |", "Points to next tier", pointsNeeded);
        printf("\n| %-20s   : %-32s |", "Next tier", nextTier);
    } else {
        printf("\n| %-20s   : %-32s |", "Next tier", nextTier);
    }
    
    printf("\n+===========================================================+\n");
}
