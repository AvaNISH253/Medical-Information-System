#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a patient
struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string medicalHistory;
};

// Structure to represent an appointment
struct Appointment {
    int patientId;
    string doctorName;
    string date;
    string time;
    string notes;
};

// Class to manage medical information system
class MedicalInformationSystem {
private:
    vector<Patient> patients;          // List of patients
    vector<Appointment> appointments;  // List of appointments
    int nextPatientId;                 // Incremental patient ID

public:
    // Constructor to initialize the system
    MedicalInformationSystem() {
        nextPatientId = 1;
    }

    // Function to add a new patient
    void addPatient() {
        Patient p;
        p.id = nextPatientId++;
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, p.name);
        cout << "Enter patient age: ";
        cin >> p.age;
        cout << "Enter patient gender: ";
        cin >> p.gender;
        cout << "Enter patient's medical history: ";
        cin.ignore();
        getline(cin, p.medicalHistory);

        patients.push_back(p);
        cout << "Patient added successfully with ID: " << p.id << endl;
    }

    // Function to view patient details
    void viewPatient(int id) {
        for (auto& p : patients) {
            if (p.id == id) {
                cout << "\nPatient ID: " << p.id << endl;
                cout << "Name: " << p.name << endl;
                cout << "Age: " << p.age << endl;
                cout << "Gender: " << p.gender << endl;
                cout << "Medical History: " << p.medicalHistory << endl;
                return;
            }
        }
        cout << "Patient not found!" << endl;
    }

    // Function to update patient's medical history
    void updateMedicalHistory(int id) {
        for (auto& p : patients) {
            if (p.id == id) {
                cout << "Current medical history: " << p.medicalHistory << endl;
                cout << "Enter new medical history: ";
                cin.ignore();
                getline(cin, p.medicalHistory);
                cout << "Medical history updated successfully." << endl;
                return;
            }
        }
        cout << "Patient not found!" << endl;
    }

    // Function to schedule an appointment
    void scheduleAppointment() {
        int patientId;
        Appointment a;
        cout << "Enter patient ID for the appointment: ";
        cin >> patientId;

        bool found = false;
        for (auto& p : patients) {
            if (p.id == patientId) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Patient ID not found!" << endl;
            return;
        }

        a.patientId = patientId;
        cout << "Enter doctor's name: ";
        cin.ignore();
        getline(cin, a.doctorName);
        cout << "Enter appointment date (YYYY-MM-DD): ";
        cin >> a.date;
        cout << "Enter appointment time (HH:MM): ";
        cin >> a.time;
        cout << "Enter additional notes: ";
        cin.ignore();
        getline(cin, a.notes);

        appointments.push_back(a);
        cout << "Appointment scheduled successfully." << endl;
    }

    // Function to view all appointments for a patient
    void viewAppointments(int patientId) {
        bool found = false;
        for (auto& a : appointments) {
            if (a.patientId == patientId) {
                cout << "\nAppointment with Dr. " << a.doctorName << endl;
                cout << "Date: " << a.date << endl;
                cout << "Time: " << a.time << endl;
                cout << "Notes: " << a.notes << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No appointments found for this patient!" << endl;
        }
    }

    // Main menu function
    void menu() {
        int choice, patientId;

        while (true) {
            cout << "\n=== Medical Information System ===" << endl;
            cout << "1. Add New Patient" << endl;
            cout << "2. View Patient Details" << endl;
            cout << "3. Update Medical History" << endl;
            cout << "4. Schedule Appointment" << endl;
            cout << "5. View Appointments" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addPatient();
                    break;
                case 2:
                    cout << "Enter patient ID to view details: ";
                    cin >> patientId;
                    viewPatient(patientId);
                    break;
                case 3:
                    cout << "Enter patient ID to update medical history: ";
                    cin >> patientId;
                    updateMedicalHistory(patientId);
                    break;
                case 4:
                    scheduleAppointment();
                    break;
                case 5:
                    cout << "Enter patient ID to view appointments: ";
                    cin >> patientId;
                    viewAppointments(patientId);
                    break;
                case 6:
                    cout << "Exiting the system." << endl;
                    return;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main() {
    MedicalInformationSystem system;
    system.menu();

    return 0;
}
