#include "HospitalSystem.h"

#include <iostream>
#include <string>

using namespace std;

void displayMenu(){

    cout<<endl<<"--------HOSPITAL SYSTEM--------"<<endl<<endl;
    cout<<"1. Add doctor"<<endl;
    cout<<"2. List all doctors"<<endl;
    cout<<"3. View doctor schedule"<<endl;
    cout<<"4. Schedule appointment"<<endl;
    cout<<"5. Cancel appointment"<<endl;
    cout<<"6. List appointments for a doctor and time slot"<<endl;
    cout<<"7. Call next patient"<<endl;
    cout<<"8. Undo Last call"<<endl;
    cout<<"9. Find patient appointments"<<endl;
    cout<<"0. Exit"<<endl;

    cout<<endl<<"Enter your choice: ";

}


int main(){

    HospitalSystem hospital;

    int choice;
    string dID, pID, dName, pName, timeSlot, specialty;
    int priority;

    while(true){

        displayMenu();

        if(!(cin >> choice)){

            cout<<endl<<"Invalid Value! Please enter number."<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;

        }

        cin.ignore(1000,'\n');

        if(choice == 0){

            cout<<endl<<"You are exiting to system!"<<endl<<endl;
            break;
        }

        switch(choice){

            case 1: 
                cout<<endl<<endl<<">>>Add Doctor<<<"<<endl<<endl;
                
                cout<<"Enter doctor ID: ";
                getline(cin,dID);
                cout<<"Enter doctor name: ";
                getline(cin,dName);
                cout<<"Enter specialty: ";
                getline(cin,specialty);

                hospital.addDoctor(dID,dName,specialty);
                break;
            
            case 2: 
                cout<<endl<<endl<<">>>List all doctors<<<"<<endl<<endl;
                
                hospital.listDoctors();
                break; 

            case 3: 
                cout<<endl<<endl<<">>>View doctor schedule<<<"<<endl<<endl;
                
                cout<<"Enter doctor ID:";
                getline(cin,dID);

                hospital.viewDoctorSchedule(dID);
                break;
            
            case 4:
                cout<<endl<<endl<<">>>Schedule appointment<<<"<<endl<<endl;
                
                cout<<"Enter patient ID: ";
                getline(cin,pID);
                cout<<"Enter patient name: ";
                getline(cin,pName);
                cout<<"Enter priority level (1=Emergency, 5=Routine): ";
                cin>>priority;
                if(priority <1 || priority >5){

                    cout<<"Invalid Value! Priority must be between 1-5!"<<endl;
                    cin.ignore(1000,'\n');
                    break;
                }
                cin.ignore(1000,'\n');
                cout<<"Enter doctor ID: ";
                getline(cin,dID);
                cout<<"Enter time slot (e.g., 09:00): ";
                getline(cin,timeSlot);

                hospital.scheduleAppointment(pID,pName,priority,dID,timeSlot);
                break;

            case 5:
                cout<<endl<<endl<<">>>Cancel appointment<<<"<<endl<<endl;
                
                cout<<"Enter doctor ID: ";
                getline(cin,dID);
                cout<<"Enter patient ID: ";
                getline(cin,pID);
                cout<<"Enter time slot (e.g., 09:00): ";
                getline(cin,timeSlot);


                hospital.cancelAppointment(dID,timeSlot,pID);
                break;

            case 6:
                cout<<endl<<endl<<">>>List appointments for a doctor and time slot<<<"<<endl<<endl;
                
                cout<<"Enter doctor ID: ";
                getline(cin,dID);
                cout<<"Enter time slot (e.g., 09:00): ";
                getline(cin,timeSlot);

                hospital.listAppointmentsFor(dID,timeSlot);
                break;

            case 7:
                cout<<endl<<endl<<">>>Call next patient<<<"<<endl<<endl;     

                hospital.callNextPatient();
                break;

            case 8:
                cout<<endl<<endl<<">>>Undo Last call<<<"<<endl<<endl;

                hospital.undoLastCall();
                break;

            case 9:
                cout<<endl<<endl<<">>>Find patient appointments<<<"<<endl<<endl;

                cout<<"Enter patient ID: ";
                getline(cin,pID);  
                
                hospital.findPatientAppointments(pID);
                break;

            default:
                cout<<endl<<endl<<"INVALID VALUE! Please try again."<<endl;
                break;

        }


    }


    return 0;

}


