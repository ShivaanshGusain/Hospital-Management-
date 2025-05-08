#include <stdio.h>
#include <string.h>
#include "records.h"

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0, doctorCount = 0;

void manageRecords() {
    int choice;
    printf("1. Add Patient\n2. Add Doctor\n3. View Patients\n4. View Doctors\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        Patient p;
        printf("Enter patient name: ");
        fgets(p.name, sizeof(p.name), stdin);
        p.name[strcspn(p.name, "\n")] = 0;

        printf("Enter age: ");
        scanf("%d", &p.age);
        getchar();
        patients[patientCount++] = p;
        printf("Patient added.\n");

    } else if (choice == 2) {
        Doctor d;
        printf("Enter doctor name: ");
        fgets(d.name, sizeof(d.name), stdin);
        d.name[strcspn(d.name, "\n")] = 0;

        printf("Enter specialization: ");
        fgets(d.specialization, sizeof(d.specialization), stdin);
        d.specialization[strcspn(d.specialization, "\n")] = 0;

        doctors[doctorCount++] = d;
        printf("Doctor added.\n");

    } else if (choice == 3) {
        for (int i = 0; i < patientCount; i++) {
            printf("Patient: %s | Age: %d\n", patients[i].name, patients[i].age);
        }

    } else if (choice == 4) {
        for (int i = 0; i < doctorCount; i++) {
            printf("Doctor: %s | Specialization: %s\n", doctors[i].name, doctors[i].specialization);
        }

    } else {
        printf("Invalid choice!\n");
    }
}