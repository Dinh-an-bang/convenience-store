#include "convenient_store_library.h"
#include "Customer.h"
#include "Product.h"
#include "Common.h"
#include "productFunction.h"
#include "productFile.h"
#include "customerFunction.h"
#include "customerFile.h"


void menu_show(){ 
    printf("\n||=================== CUA HANG TIEN LOI ====================||\n");
    printf("||        #           1. Quan ly khach hang         #       ||\n");
    printf("||         #          2. Quan ly san pham          #        ||\n");
    printf("||          #              3. Thoat               #         ||\n");
    printf("||=================||=======================================||\n");
    printf("|| Chon chuc nang: ||\n");
    printf("||=================||\n");
}

void Customer_show(){
    printf("\n||================= QUAN LY KHACH HANG ================||\n");
    printf("||      @         1. Them khach hang moi        @      ||\n");
    printf("||      @    2. Hien thi tat ca khach hang      @      ||\n");
    printf("||      @         3. Tim kiem khach hang        @      ||\n");
    printf("||      @         4. Cap nhat thong tin         @      ||\n");
    printf("||      @          5. Xoa khach hang            @      ||\n");
    printf("||      @         6. Sap xep khach hang         @      ||\n");
    printf("||      @    7. Kiem tra thong tin thanh vien   @      ||\n");
    printf("||      @             8. Quay lai               @      ||\n");
    printf("||=================||==================================||\n");
    printf("|| Chon chuc nang: ||\n");
    printf("||=================||\n");
}

void Product_show(){
    printf("\n||================== QUAN LY SAN PHAM ==================||\n");
    printf("||      *          1. Them san pham moi         *       ||\n");
    printf("||      *     2. Hien thi tat ca san pham       *       ||\n");
    printf("||      *         3. Tim kiem san pham          *       ||\n");
    printf("||      *         4. Cap nhat thong tin         *       ||\n");
    printf("||      *           5. Xoa san pham             *       ||\n");
    printf("||      *         6. Sap xep san pham           *       ||\n");
    printf("||      *         7. Kiem tra ton kho           *       ||\n");
    printf("||      *             8. Quay lai               *       ||\n");
    printf("||=================||===================================||\n");
    printf("|| Chon chuc nang: ||\n");
    printf("||=================||\n");
}

int main() {
    Customer *customers = NULL;
    Product *products = NULL;
    int choice;
    
    // doc du lieu tu file khi nhap
    readCustomersFromFile(&customers, "customers.txt");
    readProductsFromFile(&products, "products.txt");
    
    while (true){
        menu_show();
        if (scanf("%d", &choice) != 1) {
        printf("Nhap sai! Vui long nhap so.\n");
        cleanInputBuffer();
        continue;
    }
        cleanInputBuffer();
        
        if (choice == 3){
            // luu du lieu sau khi nhap va thoat ra
            saveCustomersToFile(customers, "customers.txt");
            saveProductsToFile(products, "products.txt");
            printf("\nLUU DU LIEU THANH CONG!\n");
            
             printf("\n||====================||\n");
             printf("||                    ||\n");
             printf("|| TRAN THANH CAM ON  ||\n");
             printf("||                    ||\n");
             printf("||====================||\n");
            break;
        }
        
        switch (choice){
            case 1: // maneger customer-----
    while (true) {
        Customer_show();
        scanf("%d", &choice);
        cleanInputBuffer();
        
        if (choice == 8){
            break;	
        }
        
        char id[12], phone[20];
        Customer *foundCustomer;
        
        switch (choice){
            case 1:
                addCustomer(&customers);
                break;
            case 2:
                displaycustomers(customers);
                break;
            case 3:
                printf("Nhap ID hoac SDT (1-ID, 2-SDT): ");
                int searchType;
                scanf("%d", &searchType);
                cleanInputBuffer();
                
                if (searchType == 1){
                    printf("Nhap ID: ");
                    fgets(id, sizeof(id), stdin);
                    id[strcspn(id, "\n")] = '\0';
                    foundCustomer = findCustomerByID(customers, id);
                }else{
                    printf("Nhap SDT: ");
                    fgets(phone, sizeof(phone), stdin);
                    phone[strcspn(phone, "\n")] = '\0';
                    foundCustomer = findCustomerByPhone(customers, phone);
                }
                
                if (foundCustomer) {
                    displaycustomer(foundCustomer);
                }else{
                    printf("Khong tim thay khach hang!\n");
                }
                break;
            case 4:
                printf("Nhap ID khach hang can cap nhat: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0';
                updateCustomer(customers, id);
                break;
            case 5:
                printf("Nhap ID khach hang can xoa: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0';
                deleteCustomer(&customers, id);
                break;
            case 6:
                printf("Sap xep tang dan (1) hay giam dan (0): ");
                bool ascending;
                scanf("%d", &ascending);
                cleanInputBuffer();
                sortCustomersByTier(&customers, ascending);
                break;
            case 7: 
                printf("Nhap ID khach hang can kiem tra: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = '\0';
                foundCustomer = findCustomerByID(customers, id);
                if (foundCustomer) {
                    checkCustomerMembership(foundCustomer);
                } else {
                    printf("Khong tim thay khach hang!\n");
                }
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    break;
                
            case 2: // maneger product---------
                while (true){
                    Product_show();
                    scanf("%d", &choice);
                    cleanInputBuffer();
                    
                    if (choice == 8){
                        break;	
					}
                    
                    char id[12], name[50];
                    Product *foundProduct;
                    
                    switch (choice){
                        case 1:
                            addProduct(&products);
                            break;
                        case 2:
                            displayProducts(products);
                            break;
                        case 3:
                            printf("Nhap ID hoac ten (1-ID, 2-Ten): ");
                            int searchType;
                            scanf("%d", &searchType);
                            cleanInputBuffer();
                            
                            if (searchType == 1){
                                printf("Nhap ID: ");
                                fgets(id, sizeof(id), stdin);
                                id[strcspn(id, "\n")] = '\0';
                                foundProduct = findProductById(products, id);
                            }else{
                                printf("Nhap ten: ");
                                fgets(name, sizeof(name), stdin);
                                name[strcspn(name, "\n")] = '\0';
                                foundProduct = findProductByName(products, name);
                            }
                            
                            if (foundProduct){
                                displayProduct(foundProduct);
                            } else {
                                printf("Khong tim thay san pham!\n");
                            }
                            break;
                        case 4:
                            printf("Nhap ID san pham can cap nhat: ");
                            fgets(id, sizeof(id), stdin);
                            id[strcspn(id, "\n")] = '\0';
                            updateProduct(products, id);
                            break;
                        case 5:
                            printf("Nhap ID san pham can xoa: ");
                            fgets(id, sizeof(id), stdin);
                            id[strcspn(id, "\n")] = '\0';
                            deleteProduct(&products, id);
                            break;
                        case 6:
                            printf("Sap xep tang dan (1) hay giam dan (0): ");
                            bool ascending;
                            scanf("%d", &ascending);
                            cleanInputBuffer();
                            sortProductsByPrice(&products, ascending);
                            break;
                        case 7:
                            checkLowStock(products);
                            break;
                        default:
                            printf("Lua chon khong hop le!\n");
                    }
                }
                break;
                
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
    
    return 0;
}
