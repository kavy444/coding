#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
};

struct Doctor {
    int id;
    char name[50];
    char specialization[50];
};

struct Appointment {
    int patientId;
    int doctorId;
    char date[20];
    char time[10];
};

struct Bill {
    int patientId;
    float consultationFee;
    float medicineCost;
    float total;
};

// Function declarations
void registerPatient();
void viewPatients();
void addDoctor();
void viewDoctors();
void scheduleAppointment();
void viewAppointments();
void generateBill();
void viewBills();
void recordDiagnosis();
void updatePatient();
void updateDoctor();
void updateAppointment();

int main() {
    int choice;
    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Register Patient\n");
        printf("2. View Patients\n");
        printf("3. Add Doctor\n");
        printf("4. View Doctors\n");
        printf("5. Schedule Appointment\n");
        printf("6. View Appointments\n");
        printf("7. Record Diagnosis\n");
        printf("8. Generate Bill\n");
        printf("9. View Bills\n");
        printf("10. Update Patient Details\n");
        printf("11. Update Doctor Details\n");
        printf("12. Update Appointment\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: registerPatient(); break;
            case 2: viewPatients(); break;
            case 3: addDoctor(); break;
            case 4: viewDoctors(); break;
            case 5: scheduleAppointment(); break;
            case 6: viewAppointments(); break;
            case 7: recordDiagnosis(); break;
            case 8: generateBill(); break;
            case 9: viewBills(); break;
            case 10: updatePatient(); break;
            case 11: updateDoctor(); break;
            case 12: updateAppointment(); break;
            case 13: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void registerPatient() {
    struct Patient p;
    FILE *fp = fopen("patients.txt", "ab");
    printf("\n--- Register Patient ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf("%s", p.gender);
    strcpy(p.diagnosis, "Not recorded");
    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("Patient registered successfully.\n");
}

void viewPatients() {
    struct Patient p;
    FILE *fp = fopen("patients.txt", "rb");
    if (!fp) {
        printf("No patient records found.\n");
        return;
    }
    printf("\n--- Patient Records ---\n");
    while (fread(&p, sizeof(p), 1, fp)) {
        printf("ID: %d | Name: %s | Age: %d | Gender: %s | Diagnosis: %s\n",
               p.id, p.name, p.age, p.gender, p.diagnosis);
    }
    fclose(fp);
}

void addDoctor() {
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "ab");
    printf("\n--- Add Doctor ---\n");
    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", d.name);
    printf("Enter Specialization: ");
    scanf(" %[^\n]", d.specialization);
    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
    printf("Doctor added successfully.\n");
}

void viewDoctors() {
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "rb");
    if (!fp) {
        printf("No doctor records found.\n");
        return;
    }
    printf("\n--- Doctor List ---\n");
    while (fread(&d, sizeof(d), 1, fp)) {
        printf("ID: %d | Name: %s | Specialization: %s\n", d.id, d.name, d.specialization);
    }
    fclose(fp);
}

void scheduleAppointment() {
    struct Appointment a;
    FILE *fp = fopen("appointments.txt", "ab");
    printf("\n--- Schedule Appointment ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &a.patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctorId);
    printf("Enter Date (DD-MM-YYYY): ");
    scanf("%s", a.date);
    printf("Enter Time (HH:MM): ");
    scanf("%s", a.time);
    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
    printf("Appointment scheduled successfully.\n");
}

void viewAppointments() {
    struct Appointment a;
    FILE *fp = fopen("appointments.txt", "rb");
    if (!fp) {
        printf("No appointment records found.\n");
        return;
    }
    printf("\n--- Appointments ---\n");
    while (fread(&a, sizeof(a), 1, fp)) {
        printf("Patient ID: %d | Doctor ID: %d | Date: %s | Time: %s\n",
               a.patientId, a.doctorId, a.date, a.time);
    }
    fclose(fp);
}

void generateBill() {
    struct Bill b;
    FILE *fp = fopen("bills.txt", "ab");
    printf("\n--- Generate Bill ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &b.patientId);
    printf("Enter Consultation Fee: ");
    scanf("%f", &b.consultationFee);
    printf("Enter Medicine Cost: ");
    scanf("%f", &b.medicineCost);
    b.total = b.consultationFee + b.medicineCost;
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    printf("Bill generated. Total amount: %.2f\n", b.total);
}

void viewBills() {
    struct Bill b;
    FILE *fp = fopen("bills.txt", "rb");
    if (!fp) {
        printf("No bills found.\n");
        return;
    }
    printf("\n--- Bills ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("Patient ID: %d | Consultation Fee: %.2f | Medicine Cost: %.2f | Total: %.2f\n",
               b.patientId, b.consultationFee, b.medicineCost, b.total);
    }
    fclose(fp);
}

void recordDiagnosis() {
    struct Patient p;
    int id, found = 0;
    FILE *fp = fopen("patients.txt", "rb+");
    if (!fp) {
        printf("Patient file not found.\n");
        return;
    }
    printf("\n--- Record Diagnosis ---\n");
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("Enter Diagnosis: ");
            scanf(" %[^\n]", p.diagnosis);
            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);
            found = 1;
            printf("Diagnosis updated successfully.\n");
            break;
        }
    }

    if (!found)
        printf("Patient ID not found.\n");

    fclose(fp);
}

void updatePatient() {
    struct Patient p;
    int id, found = 0;
    FILE *fp = fopen("patients.txt", "rb+");
    if (!fp) {
        printf("Patient file not found.\n");
        return;
    }

    printf("\n--- Update Patient Details ---\n");
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", p.name);
            printf("Enter new age: ");
            scanf("%d", &p.age);
            printf("Enter new gender: ");
            scanf("%s", p.gender);

            fseek(fp, -sizeof(p), SEEK_CUR);
            fwrite(&p, sizeof(p), 1, fp);
            found = 1;
            printf("Patient details updated.\n");
            break;
        }
    }

    if (!found)
        printf("Patient ID not found.\n");

    fclose(fp);
}

void updateDoctor() {
    struct Doctor d;
    int id, found = 0;
    FILE *fp = fopen("doctors.txt", "rb+");
    if (!fp) {
        printf("Doctor file not found.\n");
        return;
    }

    printf("\n--- Update Doctor Details ---\n");
    printf("Enter Doctor ID to update: ");
    scanf("%d", &id);

    while (fread(&d, sizeof(d), 1, fp)) {
        if (d.id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", d.name);
            printf("Enter new specialization: ");
            scanf(" %[^\n]", d.specialization);

            fseek(fp, -sizeof(d), SEEK_CUR);
            fwrite(&d, sizeof(d), 1, fp);
            found = 1;
            printf("Doctor details updated.\n");
            break;
        }
    }

    if (!found)
        printf("Doctor ID not found.\n");

    fclose(fp);
}

void updateAppointment() {
    struct Appointment a;
    int pid, did, found = 0;
    FILE *fp = fopen("appointments.txt", "rb+");
    if (!fp) {
        printf("Appointment file not found.\n");
        return;
    }

    printf("\n--- Update Appointment ---\n");
    printf("Enter Patient ID to update appointment: ");
    scanf("%d", &pid);
    printf("Enter Doctor ID of the appointment: ");
    scanf("%d", &did);

    while (fread(&a, sizeof(a), 1, fp)) {
        if (a.patientId == pid && a.doctorId == did) {
            printf("Enter new date (DD-MM-YYYY): ");
            scanf("%s", a.date);
            printf("Enter new time (HH:MM): ");
            scanf("%s", a.time);

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);
            found = 1;
            printf("Appointment updated.\n");
            break;
        }
    }

    if (!found)
        printf("Appointment not found.\n");

    fclose(fp);
}