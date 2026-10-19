# Hospital Appointment & Triage System

A console-based hospital management system written in **C++**. It simulates real hospital operations — doctor scheduling, waiting lists and priority-based patient triage — using **STL data structures**.

## Features

- **Doctor management:** Add doctors with unique IDs, names and specialties; list all doctors.
- **Dynamic scheduling:** Time slots (e.g. `09:00`) are created on demand, each with a capacity of 3 patients.
- **Waiting list (FIFO):** When a slot is full, the patient is added to that slot's waiting list.
- **Automatic promotion:** When an appointment is cancelled, the first patient on the waiting list is moved into the confirmed list.
- **Priority triage:** Patients are called by urgency (1 = Emergency … 5 = Routine). Equal priorities follow first-come-first-served order.
- **Lazy deletion:** Cancelled patients are skipped when calling the next patient instead of being removed from the heap.
- **Undo last call:** The most recently called patient can be put back into the triage queue.
- **Patient search:** Find all confirmed appointments of a patient across every doctor.

## Data Structures

| Structure | Used for |
|---|---|
| `std::map` | Doctors by ID, and each doctor's schedule by time slot (fast lookup) |
| `std::vector` | Confirmed appointments in a time slot |
| `std::queue` | Waiting list for full time slots (FIFO) |
| `std::priority_queue` | Triage queue, ordered by a custom `Comparator` (priority, then arrival order) |
| `std::stack` | "Undo last call" history (LIFO) |

## Class Overview

| Class | Responsibility |
|---|---|
| `Patient` | Patient ID, name and priority level |
| `Appointment` | A confirmed appointment (doctor, patient, time slot, priority) |
| `TimeSlotInfo` | Capacity, appointments and waiting list of a single time slot |
| `Doctor` | Doctor details and their schedule |
| `TriageEntry` | Entry in the triage priority queue |
| `HospitalSystem` | Main class that coordinates the whole system |

## Build & Run

Requires a C++11 (or newer) compiler.

```bash
g++ -std=c++17 -o hospital *.cpp
./hospital
```

On Windows (MinGW):

```bash
g++ -std=c++17 -o hospital.exe *.cpp
hospital.exe
```

## Menu

```
1. Add doctor
2. List all doctors
3. View doctor schedule
4. Schedule appointment
5. Cancel appointment
6. List appointments for a doctor and time slot
7. Call next patient
8. Undo last call
9. Find patient appointments
0. Exit
```

## Example

```
Appointments (3/3):
P1 - Ali (priority 5)
P2 - Veli (priority 1)
P3 - Can (priority 3)
Waiting List:
P4 - Ece (priority 2)

> Cancel P2  →  Ece moved from waiting list to confirmed appointment at 09:00.
> Call next  →  P4 Ece (priority 2)
> Call next  →  P3 Can (priority 3)
> Undo       →  Can (P3) pushed back into waiting queue.
```

## Project Structure

```
├── main.cpp
├── HospitalSystem.h / .cpp
├── Doctor.h / .cpp
├── TimeSlotInfo.h / .cpp
├── Appointment.h / .cpp
├── Patient.h / .cpp
└── TriageEntry.h / .cpp
```
