#include "Patient.h"

Patient::Patient(){

    patientID="";
    name="";
    priorityLevel=5;

}


Patient::Patient(string id, string n, int level){

    patientID=id;
    name=n;
    priorityLevel=level;

}


string Patient::getPatientID() const{
        
    return patientID;

}

string Patient::getPatientName() const{
        
    return name;

}

int Patient::getLevel() const{
        
    return priorityLevel;

}

