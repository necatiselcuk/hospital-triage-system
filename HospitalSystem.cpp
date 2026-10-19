#include "HospitalSystem.h"

HospitalSystem::HospitalSystem(){

   triageOrderCounter = 0 ;

}


void HospitalSystem::addDoctor(string id, string name, string specialty){

    if(doctors.count(id) > 0){

        cout<<endl<<"Doctor with ID: "<<id<<" already exists. Not added."<<endl;
        return;

    }

    Doctor d(id, name, specialty); 
    doctors[id]=d;

    cout<<endl<<"Added Doctor:"<<endl;
    cout<<"ID: "<<id;
    cout<<" || Name: "<<name;
    cout<<" || Specialty: "<<specialty<<endl;     

}


void HospitalSystem::listDoctors() const{

    if(doctors.empty() == true){

        cout<<endl<<"There is not any doctor"<<endl;
        return;
    }    

    for(const auto& it : doctors){

        const Doctor& d =it.second;

        cout<<"ID: "<<it.first<<" || Name: "<<d.getName()<<" || Specialty: "<<d.getSpecialty()<<endl;
        cout<<"------------------------------"<<endl;

    }

}


void HospitalSystem::viewDoctorSchedule(const string& doctorID) const{

    if(doctors.count(doctorID) == 0){

        cout<<endl<<"Doctor was not found!"<<endl;
        return;

    }

    const Doctor& d=doctors.at(doctorID);
    d.printSchedule();
}


void HospitalSystem::scheduleAppointment(string pID, string pName, int pLevel, string dID, string timeSlot){

    if(doctors.count(dID) == 0){

        cout<<endl<<"Doctor was not found!"<<endl;
        return;

    }

    Doctor& d=doctors.at(dID);

    d.addTimeSlot(timeSlot,3);

    TimeSlotInfo* slot= d.getTimeSlot(timeSlot);

    if(slot->isFull() != true){

        Appointment a(dID,pID,pName,timeSlot,pLevel);

        slot->addAppointment(a);
        triageOrderCounter++;
        TriageEntry entry(pLevel,pID,pName,dID,timeSlot,triageOrderCounter);
        triageQueue.push(entry);

        cout<<endl<<endl<<"Appointment scheduled for "<<pName<<" with Dr."<<d.getName()<<" at "<<timeSlot<<"."<<endl;

    }

    else{

        Patient p(pID,pName,pLevel);

        slot->addToWaitingList(p);

        cout<<endl<<pName<<" added waiting list because Dr."<<d.getName()<<" is full at "<<timeSlot<<"."<<endl;

    }

}


void HospitalSystem::cancelAppointment(string doctorID, string timeSlot, string patientID){

    if(doctors.count(doctorID) == 0){

        cout<<endl<<"Doctor was not found!"<<endl;
        return;

    }    

    Doctor& d=doctors.at(doctorID);
    TimeSlotInfo* slot= d.getTimeSlot(timeSlot);
    
    if(slot == nullptr){
        cout<<endl<<"The time slot not found!"<<endl;
        return;
    }

    bool removed = slot->removeAppointmentByPatientID(patientID);
    
    if(removed == true){

        cout<<endl<<"Appointment for "<<patientID<<" with Dr."<<d.getName()<<" at "<<timeSlot<<" cancelled."<<endl;

        if(slot->hasWaitingList() == true){

            Patient p = slot->popFromWaitingList();

            Appointment newApp(doctorID,p.getPatientID(),p.getPatientName(),timeSlot,p.getLevel());

            slot->addAppointment(newApp);

        triageOrderCounter++;
        TriageEntry entry(p.getLevel(),p.getPatientID(),p.getPatientName(),doctorID,timeSlot,triageOrderCounter);
        triageQueue.push(entry);

        cout<<endl<<p.getPatientName()<<" moved from waiting list to confirmed appointment at "<<timeSlot<<"."<<endl; 

        }

        else{

            cout<<endl<<"Waiting list is empty at "<<timeSlot<<endl;

        }

    }

    else{

        cout<<endl<<"No appointment found for "<<patientID<<" at "<<timeSlot<<endl;

    }


}


void HospitalSystem::listAppointmentsFor(const string& doctorID, const string& timeSlot) const{

    if(doctors.count(doctorID) == 0){

        cout<<"Doctor was not found!"<<endl;
        return;

    }
    
    const Doctor& d = doctors.at(doctorID);

    const TimeSlotInfo* slot = d.getTimeSlot(timeSlot);

    if(slot == nullptr){

        cout<<"The time slot not found!"<<endl;
        return;

    }

    cout<<endl<<"Doctor: "<<doctorID<<", Time: "<<timeSlot<<endl;

    const vector <Appointment>& apps= slot->getAppointments();

    cout<<"Appointments ("<<apps.size()<<"/"<<slot->getCapacity()<<"):"<<endl<<endl;

    if(apps.empty()==true){

        cout<<"There is no any appointment!"<<endl;

    }

    else{

        for(int i=0 ; i<apps.size() ; i++){
            
            apps[i].displayAppointment();
            cout<<endl;
        }

    }

    cout<<"Waiting List:"<<endl<<endl;

    if(slot->hasWaitingList()== true){

        queue <Patient> wList = slot->getWaitingList();

        while(wList.empty() != true){

            Patient p = wList.front();

            cout<<p.getPatientID()<<" - "<<p.getPatientName()<<" (priority "<<p.getLevel()<<")"<<endl;

            wList.pop();

        }
        

    }

    else{

        cout<<"Wait list is empty!"<<endl;


    }

}


void HospitalSystem::callNextPatient(){

    bool foundValidPatient = false;

    while(triageQueue.empty() != true){

        TriageEntry candidate = triageQueue.top();
        triageQueue.pop();

        bool isStillScheduled = false;

        if(doctors.count(candidate.doctorID) > 0){

            Doctor& d = doctors.at(candidate.doctorID);

            TimeSlotInfo* slot = d.getTimeSlot(candidate.timeSlot);

            if(slot != nullptr){

                const vector<Appointment>& apps = slot->getAppointments();

                for(const auto& app : apps){

                    if(app.getPatientID() == candidate.patientID){

                        isStillScheduled=true;
                        break;

                    }
                }
            }
        }
    
    if(isStillScheduled == true ){

        calledPatientStack.push(candidate);
        cout<<">>>Calling Next Patient<<<"<<endl<<endl;
        cout<<"Patient Id: "<<candidate.patientID<<endl;
        cout<<"Name: "<<candidate.patientName<<endl;
        cout<<"Priority Level: "<<candidate.priorityLevel<<endl;
        cout<<"Doctor Id: "<<candidate.doctorID<<endl;
        cout<<"Time Slot: "<<candidate.timeSlot<<endl<<endl;

        foundValidPatient = true;
        return;

    }

}
    
    if(foundValidPatient == false){

        cout<<"No patients waiting."<<endl;
    
    }
    

}


void HospitalSystem::undoLastCall(){

    if(calledPatientStack.empty() == true){

        cout<<"No calls to undo!"<<endl;
        return;

    }

    TriageEntry last = calledPatientStack.top();
    calledPatientStack.pop();

    triageQueue.push(last);

    cout<<"Undo successful!"<<endl;
    cout<<last.patientName<<"("<<last.patientID<<") pushed back into waiting queue."<<endl;

}


void HospitalSystem::findPatientAppointments(const string& patientID) const{

    cout<<endl<<"Searching Appointments for Patient: "<<patientID<<endl;
    bool found=false;

    for(const auto& it : doctors){

        const Doctor& d = it.second;

        const map<string,TimeSlotInfo>& dSchedule=d.getSchedule();

        for(const auto& slot : dSchedule){

            const TimeSlotInfo& timeSlot = slot.second;

            const vector<Appointment>& apps = timeSlot.getAppointments();

            for(const auto& app : apps){

                if(app.getPatientID() == patientID){

                    cout<<endl<<">>>FOUND<<<"<<endl<<endl;
                    cout<<"Dr Name: "<<d.getName();
                    cout<<", Id: "<<it.first<<"  at "<<timeSlot.getTimeSlot()<<endl;

                    found=true;

                }

            }

        }

    }

    if(found == false){

        cout<<"Appointments not found for this patient."<<endl;

    }

}
