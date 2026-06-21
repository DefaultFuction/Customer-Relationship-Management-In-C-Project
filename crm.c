#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CUSTOMERS 10
#define NAME_LEN 64
#define PHONE_LEN 20
#define EMAIL_LEN 64

typedef struct {
    int id;
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
    int age;
} Customer;

Customer database[MAX_CUSTOMERS];
int customer_count = 0;

void clear_screen() {
    system("clear");
}

void show_header() {
    clear_screen();
    printf("\n");
    printf("  +=====================================================+\n");
    printf("  |            CUSTOMER RELATIONSHIP MANAGEMENT         |\n");
    printf("  |                   CRM SYSTEM v2.0                   |\n");
    printf("  +=====================================================+\n");
    printf("\n");
}


void win(void)
{
    system("/bin/sh");
}


void show_menu() {
    printf("  +-----------------------------------------------------+\n");
    printf("  |  1. Add new customer                                |\n");
    printf("  |  2. View all customers                              |\n");
    printf("  |  3. Search customer                                 |\n");
    printf("  |  4. Delete customer                                 |\n");
    printf("  |  5. Bulk import customers                           |\n");
    printf("  |  6. Advanced search                                 |\n");
    printf("  |  7. Exit system                                     |\n");
    printf("  +-----------------------------------------------------+\n");
    printf("  > ");
}

void add_customer() {
    Customer c;
    char buffer[256];
    
    if (customer_count >= MAX_CUSTOMERS) {
        printf("\n  [!] Customer database is full!\n");
        return;
    }
    
    printf("\n  --- Add New Customer ---\n");
    c.id = customer_count + 1;
    
    printf("  Customer name: ");
    gets(buffer);
    strcpy(c.name, buffer);
    
    printf("  Phone number: ");
    gets(buffer);
    strcpy(c.phone, buffer);
    
    printf("  Email address: ");
    gets(buffer);
    strcpy(c.email, buffer);
    
    printf("  Customer age: ");
    gets(buffer);
    c.age = atoi(buffer);
    
    database[customer_count] = c;
    customer_count++;
    
    printf("\n  [✓] Customer #%d added successfully!\n", c.id);
}

void view_customers() {
    printf("\n  --- Customer List ---\n");
    printf("  +----+----------+------------+------------------+-----+\n");
    printf("  | ID | Name     | Phone      | Email            | Age |\n");
    printf("  +----+----------+------------+------------------+-----+\n");
    
    for (int i = 0; i < customer_count; i++) {
        printf("  | %2d | %-8s | %-10s | %-16s | %3d |\n",
               database[i].id,
               database[i].name,
               database[i].phone,
               database[i].email,
               database[i].age);
    }
    
    printf("  +----+----------+------------+------------------+-----+\n");
    printf("  Total: %d customers\n", customer_count);
}

void search_customer() {
    char name[64];
    int found = 0;
    
    printf("\n  --- Search Customer ---\n");
    printf("  Enter customer name: ");
    gets(name);
    
    for (int i = 0; i < customer_count; i++) {
        if (strstr(database[i].name, name) != NULL) {
            printf("\n  [✓] Customer found:\n");
            printf("      ID: %d\n", database[i].id);
            printf("      Name: %s\n", database[i].name);
            printf("      Phone: %s\n", database[i].phone);
            printf("      Email: %s\n", database[i].email);
            printf("      Age: %d\n", database[i].age);
            found = 1;
        }
    }
    
    if (!found) {
        printf("  [!] No matching customer found.\n");
    }
}

void delete_customer() {
    int id;
    char confirm[10];
    
    printf("\n  --- Delete Customer ---\n");
    printf("  Enter customer ID to delete: ");
    scanf("%d", &id);
    getchar();
    
    if (id < 1 || id > customer_count) {
        printf("  [!] Invalid customer ID!\n");
        return;
    }
    
    printf("  Confirm delete customer #%d? (yes/no): ", id);
    gets(confirm);
    
    if (strcmp(confirm, "yes") != 0) {
        printf("  Operation cancelled.\n");
        return;
    }
    
    for (int i = id - 1; i < customer_count - 1; i++) {
        database[i] = database[i + 1];
        database[i].id = i + 1;
    }
    
    customer_count--;
    printf("  [✓] Customer deleted successfully.\n");
}

void bulk_import() {
    char input[512];
    int count = 0;
    
    printf("\n  --- Bulk Import Customers ---\n");
    printf("  Format: name,phone,email,age (one per line)\n");
    printf("  Enter data (type 'END' to finish):\n");
    
    while (1) {
        if (customer_count >= MAX_CUSTOMERS) {
            printf("  [!] Database is full!\n");
            break;
        }
        
        gets(input);
        
        if (strcmp(input, "END") == 0) {
            break;
        }
        
        Customer c;
        c.id = customer_count + 1;
        
        char *token = strtok(input, ",");
        if (token) strcpy(c.name, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(c.phone, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(c.email, token);
        
        token = strtok(NULL, ",");
        if (token) c.age = atoi(token);
        
        database[customer_count] = c;
        customer_count++;
        count++;
    }
    
    printf("  [✓] Successfully imported %d customers!\n", count);
}

void advanced_search() {
    char pattern[256];
    int age_min, age_max;
    int found = 0;
    
    printf("\n  --- Advanced Search ---\n");
    printf("  Search keyword: ");
    gets(pattern);
    
    printf("  Minimum age: ");
    scanf("%d", &age_min);
    getchar();
    
    printf("  Maximum age: ");
    scanf("%d", &age_max);
    getchar();
    
    printf("\n  --- Search Results ---\n");
    
    for (int i = 0; i < customer_count; i++) {
        int age_ok = (database[i].age >= age_min && database[i].age <= age_max);
        int name_ok = strstr(database[i].name, pattern) != NULL;
        
        if (age_ok && name_ok) {
            printf("  %2d | %-8s | %-10s | %-16s | %3d\n",
                   database[i].id,
                   database[i].name,
                   database[i].phone,
                   database[i].email,
                   database[i].age);
            found = 1;
        }
    }
    
    if (!found) {
        printf("  [!] No matching customers found.\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        show_header();
        show_menu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                add_customer();
                break;
            case 2:
                view_customers();
                break;
            case 3:
                search_customer();
                break;
            case 4:
                delete_customer();
                break;
            case 5:
                bulk_import();
                break;
            case 6:
                advanced_search();
                break;
            case 7:
                printf("\n  [*] Thank you for using CRM System!\n");
                return 0;
            default:
                printf("  [!] Invalid option. Please try again.\n");
        }
        
        printf("\n  Press Enter to continue...");
        getchar();
    }
    
    return 0;
}
