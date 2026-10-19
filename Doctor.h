#ifndef DOCTOR_H
#define DOCTOR_H

#include "TimeSlotInfo.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;



class Doctor{
private:

    string doctorID;
    string name;
    string specialty;
    map <string,TimeSlotInfo> schedule;

public:

    Doctor();

    Doctor(string dID, string n,string s);

    string getName() const;

    string getSpecialty() const;

    const map<string, TimeSlotInfo>& getSchedule() const;

    void addTimeSlot(const string& timeSlot, int capacity);

    const TimeSlotInfo* getTimeSlot(const string& timeSlot) const;

    TimeSlotInfo* getTimeSlot(const string& timeSlot);

    void printSchedule() const;
};


#endif