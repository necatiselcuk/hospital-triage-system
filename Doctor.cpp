#include "Doctor.h"

Doctor::Doctor(){

    doctorID="";
    name="";
    specialty="";

}


Doctor::Doctor(string dID, string n,string s){

    doctorID=dID;
    name=n;
    specialty=s;


}


string Doctor::getName() const {return name;}

string Doctor::getSpecialty() const {return specialty;}

const map<string, TimeSlotInfo>& Doctor::getSchedule() const{return schedule;}


void  Doctor::addTimeSlot(const string& timeSlot, int capacity){

    if(schedule.count(timeSlot) == 0){

        schedule[timeSlot] = TimeSlotInfo(timeSlot,capacity);

    }


}


const TimeSlotInfo* Doctor::getTimeSlot(const string& timeSlot) const{

    if(schedule.count(timeSlot) !=0){

        return &schedule.at(timeSlot);

    }

    return nullptr;

}

TimeSlotInfo* Doctor::getTimeSlot(const string& timeSlot){

    if(schedule.count(timeSlot) !=0){

        return &schedule.at(timeSlot);

    }

    return nullptr;

}

void Doctor::printSchedule() const{

    cout<<endl<<"Doctor: "<<doctorID<<", Speciality: "<<specialty<<", ";

    if(schedule.empty() == true){

        cout<<"Schedule is empty!"<<endl;
        return;
    }


    for(const auto& it : schedule){

        string time = it.first;
        const TimeSlotInfo& slot =it.second;

        const vector <Appointment>& appointments2 = slot.getAppointments();

        int capacity = slot.getCapacity();

        cout<<"Time: "<<time<<endl;
        cout<<"Appointments ("<<appointments2.size()<<"/"<<capacity<<"):"<<endl;

        if(appointments2.empty() == true){

            cout<<"There is not any appointments!"<<endl;

        }
        else{

            for(int i=0 ; i < appointments2.size() ; i++){

                appointments2[i].displayAppointment();
                cout<<endl;
            }

        }

        queue <Patient> waitList2 = slot.getWaitingList();

        if(waitList2.empty() == true ){

            cout<<"Wait List is empty!"<<endl<<endl;
        }
            
        else{

        cout<<"Waiting List: "<<endl;

        while(waitList2.empty() != true){

            Patient p= waitList2.front();

            cout<<p.getPatientID()<<" - "<<p.getPatientName()<<" (priority "<<p.getLevel()<<")"<<endl;

            waitList2.pop();


        }
        }
    }
}