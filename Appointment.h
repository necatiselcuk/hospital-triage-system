#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>

using namespace std;

class Appointment{
private:

    string doctorID;
    string patientID;
    string patientName;
    string timeSlot;
    int priorityLevel;

public:

    Appointment();

    Appointment(string dID, string pID, string name, string time, int level);
    
    string getPatientID() const;
    
    string getDoctorID() const;

    string getPatientName() const;

    int getLevel() const;
    
    string getTimeSlot() const;

    void displayAppointment() const;

};


#endif