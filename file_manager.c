#include <stdio.h>
#include <string.h>
#include "appointment.h"
#include "records.h"

void saveData() {
    FILE *fa = fopen("appointments.txt", "w");
    for (int i = 0; i < appointmentCount; i++) {
        fprintf(fa, "%s,%s,%s,%s\n", appointments[i].patientName, appointments[i].doctorName, appointments[i].date, appointments[i].time);
    }
    fclose(fa);

    FILE *fp = fopen("patients.txt", "w");
    for (int i = 0; i < patientCount; i++) {
        fprintf(fp, "%s,%d\n", patients[i].name, patients[i].age);
    }
    fclose(fp);

    FILE *fd = fopen("doctors.txt", "w");
    for (int i = 0; i < doctorCount; i++) {
        fprintf(fd, "%s,%s\n", doctors[i].name, doctors[i].specialization);
    }
    fclose(fd);
}

void loadData() {
    FILE *fa = fopen("appointments.txt", "r");
    if (fa) {
        while (fscanf(fa, "%[^,],%[^,],%[^,],%s\n", appointments[appointmentCount].patientName,
                      appointments[appointmentCount].doctorName,
                      appointments[appointmentCount].date,
                      appointments[appointmentCount].time) == 4) {
            appointmentCount++;
        }
        fclose(fa);
    }

    FILE *fp = fopen("patients.txt", "r");
    if (fp) {
        while (fscanf(fp, "%[^,],%d\n", patients[patientCount].name, &patients[patientCount].age) == 2) {
            patientCount++;
        }
        fclose(fp);
    }

    FILE *fd = fopen("doctors.txt", "r");
    if (fd) {
        while (fscanf(fd, "%[^,],%[^]\n", doctors[doctorCount].name, doctors[doctorCount].specialization) == 2) {
            doctorCount++;
        }
        fclose(fd);
    }
}