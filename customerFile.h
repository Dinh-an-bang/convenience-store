#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common.h"


// Save customers to file
void saveCustomersToFile(Customer *head, const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("\nCannot open file for writing!");
        return;
    }

    Customer *current = head;
    while (current != NULL) {
        fprintf(file, "%s,%s,%s,%s,%s,%d,%d,%02d/%02d/%04d\n",
                current->ID,
                current->Name,
                current->phone,
                current->email,
                current->address,
                current->points,
                current->tier,
                current->join_date.Day,
                current->join_date.Month,
                current->join_date.years);

        current = current->next;
    }

    fclose(file);
    printf("\nSaved file %s sucessfully!!!\n",fileName);
}

// Read customers from file
void readCustomersFromFile(Customer **head, const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("\nCannot open file for reading!");
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        Customer *newCustomer = (Customer*)malloc(sizeof(Customer));
        if (newCustomer == NULL) {
            printf("\nMemory allocation failed!");
            fclose(file);
            return;
        }

        // Parse the line
        int tier;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,   %d/%d/%d",
               newCustomer->ID,
               newCustomer->Name,
               newCustomer->phone,
               newCustomer->email,
               newCustomer->address,
               &newCustomer->points,
               &tier,
               &newCustomer->join_date.Day,
               &newCustomer->join_date.Month,
               &newCustomer->join_date.years);

        newCustomer->tier = (MembershipTier)tier;
        newCustomer->next = *head;
        *head = newCustomer;
    }

    fclose(file);
    printf("Reading the customer sucessfully: %s\n", fileName);
}
