#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include "Doctor.h"
#include "TriageEntry.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class HospitalSystem{
private: 
    
    map <string,Doctor> doctors;
    priority_queue <TriageEntry, vector <TriageEntry> , Comparator> triageQueue;
    stack <TriageEntry> calledPatientStack;
    int triageOrderCounter;


public:

    HospitalSystem();

    void addDoctor(string id, string name, string speciality);

    void listDoctors() const;

    void viewDoctorSchedule(const string& doctorID) const;

    void scheduleAppointment(string pID, string pName, int pLevel, string dID, string timeSlot);
    
    void cancelAppointment(string doctorID, string timeSlot, string patientID);
    
    void listAppointmentsFor(const string& doctorID, const string& timeSlot) const;
    
    void callNextPatient();
    
    void undoLastCall();
    
    void findPatientAppointments(const string& patientID) const ;



};


#endif