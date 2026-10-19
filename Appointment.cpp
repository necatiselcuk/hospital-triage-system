#include "Appointment.h"

Appointment::Appointment(){

    patientID="";
    patientName="";
    priorityLevel=5;
    doctorID="";
    timeSlot="";

}


Appointment::Appointment(string dID, string pID, string name, string time, int level){

    doctorID=dID;
    patientID=pID;
    patientName=name;
    timeSlot=time;
    priorityLevel=level;

}

string Appointment::getPatientID() const{
    
    return patientID;

}

string Appointment::getDoctorID() const{
        
    return doctorID;
    
}

string Appointment::getPatientName() const{
    
    return patientName;

}

int Appointment::getLevel() const{
        
    return priorityLevel;

}

string Appointment::getTimeSlot() const{
        
    return timeSlot;

}


void Appointment::displayAppointment() const{
        
    cout<<getPatientID()<<" - "<<getPatientName();
    cout<<" (priority "<<getLevel()<<")"<<endl;

}
