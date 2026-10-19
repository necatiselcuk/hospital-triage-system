#include "TriageEntry.h"

TriageEntry::TriageEntry(int level, string pID, string name, string dID, string time, int ord){
   
    priorityLevel = level;
    patientID = pID;
    patientName = name;
    doctorID = dID;
    timeSlot = time;
    order = ord;      

}

bool Comparator::operator()(const TriageEntry& a, const TriageEntry& b) const{

   if(a.priorityLevel != b.priorityLevel){

    return a.priorityLevel > b.priorityLevel;

   }

   return a.order > b.order;

}