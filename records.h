#ifndef RECORDS_H
#define RECORDS_H

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50

typedef struct {
    char name[50];
    int age;
} Patient;

typedef struct {
    char name[50];
    char specialization[50];
} Doctor;

extern Patient patients[];
extern Doctor doctors[];
extern int patientCount, doctorCount;

void manageRecords();

#endif