#ifndef TIMESLOTINFO_H
#define TIMESLOTINFO_H

#include "Patient.h"
#include "Appointment.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class TimeSlotInfo{
private:

    string timeSlot;
    int capacity;
    vector <Appointment> appointments;
    queue <Patient> waitingList;

public:

    TimeSlotInfo();

    TimeSlotInfo(string time, int cap);

    string getTimeSlot() const;

    int getCapacity() const;

    const vector <Appointment>& getAppointments() const;

    queue <Patient> getWaitingList() const;

    bool isFull() const;

    bool addAppointment(const Appointment& a);

    bool removeAppointmentByPatientID(const string& patientID);

    void addToWaitingList(const Patient& p);

    bool hasWaitingList() const;

    Patient popFromWaitingList();
};


#endif