#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Student {
    int id;
    char name[50];
    int libraryDues;
    int hostelDues;
    int labDues;
    int accountsDues;
    char dateAdded[20];
    char clearanceDate[20];
};

void addStudent() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        // If file doesn't exist yet, create it
        fp = fopen("students.dat", "wb");
        if (fp == NULL) {
            printf("Error initializing file.\n");
            return;
        }
        fclose(fp);
        fp = fopen("students.dat", "rb");
    }

    struct Student s;
    int newId;
    printf("\nEnter Student ID: ");
    scanf("%d", &newId);
    getchar(); // clear newline

    // Check for duplicate ID
    int duplicate = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == newId) {
            duplicate = 1;
            break;
        }
    }
    fclose(fp);

    if (duplicate) {
        printf("Error: Student ID %d already exists. Cannot add duplicate ID.\n", newId);
        return;
    }

    fp = fopen("students.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    s.id = newId;

    printf("Enter Name: ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    // Initialize all dues to 100000
    s.libraryDues = 100000;
    s.hostelDues = 100000;
    s.labDues = 100000;
    s.accountsDues = 100000;

    // Set current date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(s.dateAdded, sizeof(s.dateAdded), "%Y-%m-%d", t);

    // Initialize clearance date
    strcpy(s.clearanceDate, "");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully on %s with all dues set to 100000.\n", s.dateAdded);
}

void viewStudents() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student s;
    printf("\n%-5s %-20s %-10s %-10s %-10s %-14s %-12s %-15s\n", 
           "ID", "Name", "Library", "Hostel", "Lab", "Accounts", "Added", "Clearance");
    printf("---------------------------------------------------------------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%-5d %-20s %-10d %-10d %-10d %-14d %-12s %-15s\n",
               s.id, s.name, s.libraryDues, s.hostelDues, s.labDues, s.accountsDues,
               s.dateAdded, strlen(s.clearanceDate) > 0 ? s.clearanceDate : "Not Cleared");
    }

    fclose(fp);
}

void viewStudentById() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Student s;
    int id, found = 0;
    printf("\nEnter Student ID to View: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("\n%-5s %-20s %-10s %-10s %-10s %-14s %-12s %-15s\n", 
                   "ID", "Name", "Library", "Hostel", "Lab", "Accounts", "Added", "Clearance");
            printf("---------------------------------------------------------------------------------------------\n");
            printf("%-5d %-20s %-10d %-10d %-10d %-14d %-12s %-15s\n",
                   s.id, s.name, s.libraryDues, s.hostelDues, s.labDues, s.accountsDues,
                   s.dateAdded, strlen(s.clearanceDate) > 0 ? s.clearanceDate : "Not Cleared");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
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

            // Check for clearance
            if (s.libraryDues == 0 && s.hostelDues == 0 && s.labDues == 0 && s.accountsDues == 0) {
                time_t now = time(NULL);
                struct tm *t = localtime(&now);
                strftime(s.clearanceDate, sizeof(s.clearanceDate), "%Y-%m-%d", t);
            } else {
                strcpy(s.clearanceDate, ""); // Reset if not cleared anymore
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
                printf("Clearance Date: %s\n", strlen(s.clearanceDate) > 0 ? s.clearanceDate : "Unknown");