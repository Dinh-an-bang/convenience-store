#pragma once
#include "convenient_store_library.h"

// xao bo nho dem nhap
void cleanInputBuffer(){
    int c;
    // xoa cac ki tu du thua, ham doc va bo qua '\n'
    while ((c = getchar()) != '\n' && c != EOF);
}

// check email
// dung const chu yeu de chuoi email khong bi thay doi trong ham

bool check_Email(const char *email){
    // kiem tra con tro email NULL hoac la rong
    if (email == NULL || email[0] == '\0'){
        return false; // neu con tro la NULL hoac la rong thi tra ve false
    }

    // check ký tu @
    // su dung strchr de tim kiem ky tu @ dau tien trong chuoi
    const char *at = strchr(email, '@');
    if (at == NULL || at == email){
        return false; // Không có '@' hoac '@' o dau
    }

    // check ky tu '.' sau '@'
    // cho con tro chay tu sau @ tro di cho den khi thay '.' thi thoi
    const char *dot = strchr(at + 1, '.');
    if (dot == NULL || dot == at + 1){
        return false; // Không có '.' ho?c '.' ngay sau '@'
    }

    // Kiem tra khoang trong
    for (const char *p = email; *p != '\0'; p++){
        if (isspace(*p)) {
            return false;
        }
    }
    return true;
}

// check phone
// tuong tu dung const de khien cho phone trong ham main khong bi thay doi

bool check_Phone(const char *phone){
    if (phone == NULL || phone[0] == '\0') {
        return false;
    }
    
    // that ra co the dung size_t nhung no gay kho hieu
    unsigned int len = strlen(phone);
    if (len < 10 || len > 15) {
        return false;
    }
    
    bool seen_plus = false;
    
    for (const char *p = phone; *p != '\0'; p++){
        if (*p == '+') {
            if (p != phone){
                return false;
            }
            seen_plus = true;
        } else if (*p == '-'){
            if (p == phone || *(p + 1) == '\0'){
                return false;
            }
            // dung isdigit tai gai tri con tro p co phai la 1 so hay khong
        } else if (isdigit(*p) == false){
            return false;
        }
    }
    return true;
}


//khai bao cau truc Date dung de khai bao ngay thang nam
typedef struct{
	int Day;
	int Month;
	int years;
} Date;


// check date
	bool checkDate(int day, int month, int year){
		if(day < 1 || day > 31 || month < 1 || month > 12){
			return false;
		}
		if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
			return false;
		}
		
		if (month == 2) {
			bool is_leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
				if (is_leap_year && day > 29){
					return false;
				}
				if (!is_leap_year && day > 28){
					return false;
				}
		}
		return true;
	}

// check ngay thang duoc nhap
void input_day(int *day, int *month, int *year){
	// tao 1 mang ky chua ngay thang nam
    char input[20]; 
    // tao bien luu ngay thang nam
    int d,m,y;
    
    
    // tao 1 vong lap cho tden khi nhap hop le
    while (true){ 
        printf("Input date (dd/mm/yy): ");
        
        if (fgets(input, sizeof(input), stdin) == NULL){
            cleanInputBuffer();
            printf("Error for input value.Please Input again!\n");
            continue;
        }

        // xao ki tu xuong dong
        input[strcspn(input, "\n")] = '\0';

        // phan tich chuoi theo dinh dang d/d/d
        // dung sscanf de chuyen doi tu chuoi ky tu sang 3 so nguyen ngay thang nam
        if (sscanf(input, "%d/%d/%d", &d, &m, &y) != 3) {
            printf("Error. Please Input again(dd/mm/yy!\n");
            cleanInputBuffer();
            continue;
        }

        // dung ham check xem ngay thang nhap co hop le khong
        if (checkDate(d, m, y) == true){
            *day = d;
            *month = m;
            *year = y;
            break;
        } else{
            printf("Error. Please Input again!\n");
            cleanInputBuffer();
        }
    }
}
	
	// gan ngay co dinh la 21/4/2025
	Date get_date_now() {
		Date date_now;
		// lay ngay hien tai lam moc
		date_now.Day = 21;
		date_now.Month = 4;
		date_now.years = 2025;
		return date_now;
	}
