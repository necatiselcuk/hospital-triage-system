#ifndef TRIAGEENTRY_H
#define TRIAGEENTRY_H

#include <iostream>
#include <string>

using namespace std;


struct TriageEntry{
  
   int priorityLevel;
   string patientID;
   string patientName;
   string doctorID;
   string timeSlot;
   int order;

   TriageEntry(int level, string pID, string name, string dID, string time, int ord);

};


struct Comparator{

   bool operator()(const TriageEntry& a, const TriageEntry& b) const;

};


#endif
