#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string> 

using namespace std;


class Patient{
private:

    string patientID;
    string name;
    int priorityLevel;

public:

    Patient();

    Patient(string id, string n, int level);

    string getPatientID() const;

    string getPatientName() const;

    int getLevel() const;

};

#endif