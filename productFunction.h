#include "Product.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common.h"


// them san pham moi vao danh sach
void addProduct(Product **head){
	
	Product *newProduct = (Product*)malloc(sizeof(Product));
	if (newProduct == NULL) {
		printf("/nout of memory!");
		return;
	}
	
	printf("\n-------------ADD A NEW PRODUCT TO YOUR CONVENIENT STORE-------------\n");
	
	printf("\nPlease input the product ID (maximum 9 charaters): ");
	fgets(newProduct->id,sizeof(newProduct->id),stdin);
	newProduct->id[strcspn(newProduct->id, "\n")] = '\0'; // bo ky tu \n neu co
	
	printf("\nPlease input the product Name (maximum 49 charaters): ");
	fgets(newProduct->name,sizeof(newProduct->name),stdin);
	newProduct->name[strcspn(newProduct->name, "\n")] = '\0';
	
	printf("\nPlease input the product category (maximum 29 charaters): ");
	fgets(newProduct->category,sizeof(newProduct->category),stdin);
	newProduct->category[strcspn(newProduct->category, "\n")] = '\0';
	
	printf("\nPlease input the product price: ");
	scanf("%f", &newProduct->price);
	while(getchar() != '\n');
	
	printf("\nplease input the product cost: ");
	scanf("%f", &newProduct->cost);
	while(getchar() != '\n');
	
	printf("\nPlease input the product quantity: ");
	scanf("%d", &newProduct->quantity);
	while(getchar() != '\n');
	
	printf("\nPlease input the product min_quantity: ");
	scanf("%d", &newProduct->min_quantity);
	while(getchar() != '\n');
	
	// expiry day
	input_day(&newProduct->expiry_date.Day, &newProduct->expiry_date.Month, &newProduct->expiry_date.years);
	
	// import day
	newProduct->import_date = get_date_now();
	
	//add new product into list
	newProduct->next = *head;
	*head = newProduct;
}

//hien thi 1 san pham
void displayProduct(Product *pointer){
	if(pointer == NULL){
		printf("\nproduct not found!!!");
		return;
	}
	
	printf("\n+================= PRODUCT INFORMATION =================+");
	printf("\n| %-20s : %-30s |","ID", pointer->id);
	printf("\n| %-20s : %-30s |","Name", pointer->name);
	printf("\n| %-20s : %-30s |","Category", pointer->category);
	printf("\n| %-20s : %-30.2f |","Product price", pointer->price);
    printf("\n| %-20s : %-30.2f |","Product cost", pointer->cost);
    printf("\n| %-20s : %-30d |","Quantity", pointer->quantity);
    printf("\n| %-20s : %-30d |","Min_Quantity", pointer->min_quantity);
	printf("\n| %-20s : %02d//%02d//%04d                |","Product expiry", pointer->expiry_date.Day, pointer->expiry_date.Month, pointer->expiry_date.years);
	printf("\n| %-20s : %02d//%02d//%04d                |","Product import", pointer->import_date.Day, pointer->import_date.Month, pointer->import_date.years);
	printf("\n+=====================================================+\n");
}

// hien thi tat ca san pham
void displayProducts(Product *head) {
    if (head == NULL) {
        printf("\nList product not found!!!\n");
        return;
    }

    printf("\n+------------+--------------------+-------------------+---------+---------+---------+---------+------------+------------+\n");
    printf("| %-10s | %-18s | %-17s | %-7s | %-7s | %-7s | %-7s | %-10s | %-10s |\n",
           "ID", "Name", "Category", "Price", "Cost", "Quantity", "Min Qty", "Expiry Date", "Import Date");
    printf("+------------+--------------------+-------------------+---------+---------+---------+---------+------------+------------+\n");

    Product *current = head;
    while(current != NULL){
               printf("| %-10s | %-14s | %-17s | %-7.2f | %-7.2f | %-7d | %-7d | %02d/%02d/%04d | %02d/%02d/%04d |\n", 
			   current->id,             
			   current->name,
               current->category,
               current->price,
               current->cost,
               current->quantity,
               current->min_quantity,
               current->expiry_date.Day, current->expiry_date.Month, current->expiry_date.years,
               current->import_date.Day, current->import_date.Month, current->import_date.years);

        current = current->next;
    }

    printf("+------------+----------------------+-----------------+--------------+-----------------+------------+---------------+------------------+------------------+\n");
}

// find product by ID
Product *findProductById(Product *head, const char *id){
	Product *current = head;
	while(current != NULL){
		if(strcmp(current->id, id) == 0){
			return current;
		}
		current = current->next;
	}
	return NULL;
}

// find product by Name
Product *findProductByName(Product *head, const char *name){
	Product *current = head;
	while(current){
		if(strcmp(current->name,name) == 0){
			return current;
		}
		current = current->next;
	}
	return NULL;
}

// cap nhat thong tin theo ID
void updateProduct(Product *head, const char *id){
	Product *newProduct = findProductById(head, id);
	if(newProduct == NULL){
		printf("\nProduct ID not found!!!");
		return;
	}
	
	printf("\n-------------UPDATE THE NEW ID FOR THE PRODUCT TO YOUR CONVENIENT STORE-------------\n");
	
	printf("\nPlease input the new ID for the product (maximum 9 charaters): ");
	fgets(newProduct->id,sizeof(newProduct->id),stdin);
	newProduct->id[strcspn(newProduct->id, "\n")] = '\0'; // bo ky tu \n neu co
	
	printf("\nPlease input the new Name for the product (maximum 49 charaters): ");
	fgets(newProduct->name,sizeof(newProduct->name),stdin);
	newProduct->name[strcspn(newProduct->name, "\n")] = '\0';
	
	printf("\nPlease input the new Category for the product (maximum 29 charaters): ");
	fgets(newProduct->category,sizeof(newProduct->category),stdin);
	newProduct->category[strcspn(newProduct->category, "\n")] = '\0';
	
	printf("\nPlease input the new price for the product: ");
	scanf("%f", &newProduct->price);
	while(getchar() != '\n');
	
	
	printf("\nplease input the new cost for the product: ");
	scanf("%f", &newProduct->cost);
	while(getchar() != '\n');
	
	printf("\nPlease input the new quantity for the product: ");
	scanf("%d", &newProduct->quantity);
	while(getchar() != '\n');
	
	printf("\nPlease input the new min_quantity for the product: ");
	scanf("%d", &newProduct->min_quantity);
	while(getchar() != '\n');
	
	
	// expiry day
	printf("\nInput new expiry day: ");
	input_day(&newProduct->expiry_date.Day, &newProduct->expiry_date.Month, &newProduct->expiry_date.years);
	
	// import day
	printf("\nInput new import day: ");
	newProduct->import_date = get_date_now();
	
	printf("\nProduct updated successfully!!!");
}

// delete san pham bang id 
void deleteProduct(Product **head, const char *id){
	Product *temp = *head;
	Product *pointer = NULL;
	
	while(temp != NULL){
		if(strcmp(temp->id,id) == 0){
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

// sap xep san pham tang giam theo bubble sort
void sortProductsByPrice(Product **head, bool ascending){
	if(head == NULL || *head == NULL){
		return;
	}
	
	for(Product *i = *head; i != NULL; i = i->next){
		for(Product *j = i->next; j != NULL; j = j->next ){
			// check ascending hay khong ascending
			bool should_ascending = ascending ? (i->price > j->price) : (i->price < j->price); 
			if(should_ascending){
				// hoan doi i va j neu i > j
				float tempPrice = i->price;
				i->price = j->price;
				j->price = tempPrice;
				
				float tempCost = i->cost;
				i->cost = j->cost;
				j->cost = tempCost;
				
				int tempQuantity = i->quantity;
				i->quantity = j->quantity;
				j->quantity = tempQuantity;
				
				int tempMin_quantity = i->min_quantity;
				i->min_quantity = j->min_quantity;
				j->min_quantity = tempMin_quantity;
				
				char tempID[12], tempName[50], tempCategory[30];
				// swap id
				strcpy(tempID, i->id); strcpy(i->id, j->id); strcpy(j->id, tempID);
				// swap name
				strcpy(tempName, i->name); strcpy(i->name, j->name); strcpy(j->name, tempName);
				// swap category
				strcpy(tempCategory, i->category); strcpy(i->category, j->category); strcpy(j->category, tempCategory);
				
				Date tempExpiry = i->expiry_date;
				i->expiry_date = j->expiry_date;
				j->expiry_date = tempExpiry;
				
				Date tempImport = i->import_date;
				i->import_date = j->import_date;
				j->import_date = tempImport;
				
			}
		}
	}
	printf("\nSorting %s sucessfully!!!", ascending ? "ascending" : "not ascending");
}

// check xem no con hang hay khong
void checkLowStock(Product *head){
	bool checkLow = true;
	printf("\n================= LOW STOCK PROFUCT ==================\n");
	
	for (Product *poin = head; poin != NULL; poin = poin->next){
		if(poin->quantity <= poin->min_quantity){
			displayProduct(poin);
			checkLow = false;
		}
	}
	if(checkLow){
		printf("\nThe product expiry not found!!!");
	}
}
