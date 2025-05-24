#include "Product.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common.h"


// luu danh sach product vao file
void saveProductsToFile(Product *head, const char *fileName){
	FILE *file = fopen(fileName, "w");
	if(file == NULL){
		printf("\nCannot open file for writing");
		return;
	}
	
	Product *current = head;
	while(current){
		fprintf(file, "%s,%s,%s,%.2f,%.2f,%d,%d,   %02d/%02d/%04d,    %02d/%02d/%04d\n",
		current->id,
		current->name,
		current->category,
		current->price,
		current->cost,
		current->quantity,
		current->min_quantity,
		current->expiry_date,
		current->import_date);
		
		current = current->next;
		
	}
	fclose(file);
	printf("\nSaved file %s sucessfully!!!\n",fileName);
}


//doc file product vua in
void readProductsFromFile(Product **head, const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Cannot open file for reading!\n");
        return;
    }

    char line[512];
    // doc tung dong trong file
    while (fgets(line, sizeof(line), file)) {
    	// sau khi doc no se tao mot hop chua san pham moi va dua line do vao
        Product *newProduct = (Product*)malloc(sizeof(Product));
        if (newProduct == NULL) {
            printf("Not enough memory!\n");
            fclose(file);
            return;
        }
        // den day phan tich tung cai trong file va gan du lieu vao cac truong tuong ung
        sscanf(line, "%[^,],%[^,],%[^,],%f,%f,%d,  %d,%d/%d/%d,   %d/%d/%d",
               newProduct->id,
               newProduct->name,
               newProduct->category,
               &newProduct->price,
               &newProduct->cost,
               &newProduct->quantity,
               &newProduct->min_quantity,
               &newProduct->expiry_date.Day,
               &newProduct->expiry_date.Month,
               &newProduct->expiry_date.years,
               &newProduct->import_date.Day,
               &newProduct->import_date.Month,
               &newProduct->import_date.years);

        newProduct->next = *head;
        *head = newProduct;
    }

    fclose(file);
    printf("Reading the product sucessfully: %s\n", fileName);
}



