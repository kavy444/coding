#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    int libraryDues;
    int hostelDues;
    int labDues;
    int accountsDues;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student s;
    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    getchar(); // clear newline after ID input

    printf("Enter Name: ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    // Initialize all dues to 100000
    s.libraryDues = 100000;
    s.hostelDues = 100000;
    s.labDues = 100000;
    s.accountsDues = 100000;

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully with all dues set to 100000.\n");
}

void viewStudents() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student s;
    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nID: %d\nName: %s\nLibrary Dues: %d\nHostel Dues: %d\nLab Dues: %d\nAccounts Dues: %d\n",
               s.id, s.name, s.libraryDues, s.hostelDues, s.labDues, s.accountsDues);
    }

    fclose(fp);
}

void updateDues() {
    FILE *fp = fopen("students.dat", "rb+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student s;
    int id, dept, amount;
    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    printf("Select Department:\n1. Library\n2. Hostel\n3. Lab\n4. Accounts\nChoice: ");
    scanf("%d", &dept);

    printf("Enter Dues Amount: ");
    scanf("%d", &amount);

    int found = 0;

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            fseek(fp, -sizeof(s), SEEK_CUR);

            switch (dept) {
                case 1: s.libraryDues = amount; break;
                case 2: s.hostelDues = amount; break;
                case 3: s.labDues = amount; break;
                case 4: s.accountsDues = amount; break;
                default:
                    printf("Invalid department.\n");
                    fclose(fp);
                    return;
            }

            fwrite(&s, sizeof(s), 1, fp);
            printf("Dues updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

void checkClearance() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student s;
    int id;
    printf("\nEnter Student ID to Check Clearance: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            found = 1;
            if (s.libraryDues == 0 && s.hostelDues == 0 && s.labDues == 0 && s.accountsDues == 0) {
                printf("Student %s (ID: %d) is CLEARED.\n", s.name, s.id);
            } else {
                printf("Student %s (ID: %d) is NOT CLEARED.\n", s.name, s.id);
                printf("Remaining Dues:\nLibrary: %d\nHostel: %d\nLab: %d\nAccounts: %d\n",
                       s.libraryDues, s.hostelDues, s.labDues, s.accountsDues);
            }
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n--- No Dues Management ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Dues\n");
        printf("4. Check Clearance\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateDues(); break;
            case 4: checkClearance(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}