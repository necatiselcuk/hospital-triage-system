#include "TimeSlotInfo.h"

TimeSlotInfo::TimeSlotInfo(){

    timeSlot="";
    capacity=3;

}

TimeSlotInfo::TimeSlotInfo(string time, int cap){

    timeSlot=time;
    capacity=cap;

}

string TimeSlotInfo::getTimeSlot() const{

    return timeSlot;

}

int TimeSlotInfo::getCapacity() const{

    return capacity;

}

const vector <Appointment>& TimeSlotInfo::getAppointments() const{

    return appointments;

}

queue <Patient> TimeSlotInfo::getWaitingList() const{

    return waitingList;

}

bool TimeSlotInfo::isFull() const{

    return appointments.size() >= capacity;

}

bool TimeSlotInfo::addAppointment(const Appointment& a){

    if(isFull() != true){
    
        appointments.push_back(a);
        return true;
    }

    return false;

}

bool TimeSlotInfo::removeAppointmentByPatientID(const string& patientID){

    for(int i=0; i<appointments.size(); i++){

        if(appointments[i].getPatientID() == patientID){
                
            appointments.erase(appointments.begin() + i);
            return true;
        } 
            
    }
    return false;

}

void TimeSlotInfo::addToWaitingList(const Patient& p){

    waitingList.push(p);

}

bool TimeSlotInfo::hasWaitingList() const{

    if(waitingList.empty() != true){

        return true;

    }
    return false;

}

Patient TimeSlotInfo::popFromWaitingList(){

    if(waitingList.empty() != true){
            
        Patient temp;
        temp=waitingList.front();
        waitingList.pop();
        return temp;

    }
        
    return Patient();

}
