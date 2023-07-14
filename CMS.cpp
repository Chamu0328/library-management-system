#include <iostream>
#include <queue>
using namespace std;


struct Complaint {
    int id;
    string complainantDetails;
    string complaintDetails;
    string severity;
    string date;
};

struct Node {
    Complaint complaint;
    Node* next;
};


class ComplaintList {
private:
    Node* head;
    
public:
    
    ComplaintList() {
        head = nullptr;
    }
    Node* getHead()
        {
                return head;
        }
    

    void addComplaint(const Complaint& newComplaint) {
        Node* newNode = new Node;
        newNode->complaint = newComplaint;
        newNode->next = nullptr;
        
        if (head == nullptr || newComplaint.id < head->complaint.id) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->complaint.id < newComplaint.id) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        
        cout << "Your complaint has been added successfully!" << endl;
    }

    void removeComplaint(int complaintID, queue<Complaint>& removedComplaints) {
        if (head == nullptr) {
            cout << "No complaints found !!!." << endl;
            return;
        }
        
        if (head->complaint.id == complaintID) {
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            removedComplaints.push(temp->complaint);
            delete temp;
            
            cout << "Complaint has been removed successfully!" << endl;
            return;
        }
        
        Node* current = head;
        while (current->next != nullptr && current->next->complaint.id != complaintID) {
            current = current->next;
        }
        
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            temp->next = nullptr;
            removedComplaints.push(temp->complaint);
            delete temp;
            
            cout << " Your Complaint has been removed successfully!" << endl;
        } else {
            cout << "Invalid complaint ID!!!  Please enter a valid complaint ID to proceed." << endl;
        }
    }

    void updateComplaint(int complaintID) {
        Node* current = head;
        while (current != nullptr && current->complaint.id != complaintID) {
            current = current->next;
        }
        
        if (current != nullptr) {
            // Update complaint details
            cout << "Enter updated complainant details: ";
            cin.ignore();
            getline(cin, current->complaint.complainantDetails);
            cout << "Enter updated complaint details: ";
            getline(cin, current->complaint.complaintDetails);
            cout << "Enter updated severity: ";
            getline(cin, current->complaint.severity);
            cout << "Enter updated date: ";
            getline(cin, current->complaint.date);
            
            cout << "Complaint details updated successfully!" << endl;
        } else {
            cout << "Invalid complaint ID. No such complaint found." << endl;
        }
    }

    void showComplaintDetails(int complaintID) {
        Node* current = head;
        while (current != nullptr && current->complaint.id != complaintID) {
            current = current->next;
        }
        
        if (current != nullptr) {
  
            cout << "Complaint ID: " << current->complaint.id << endl;
            cout << "Complainant Details: " << current->complaint.complainantDetails << endl;
            cout << "Complaint Details: " << current->complaint.complaintDetails << endl;
            cout << "Severity: " << current->complaint.severity << endl;
            cout << "Date: " << current->complaint.date << endl;
        } else {
            cout << "Invalid complaint ID. No such complaint found." << endl;
        }
    }

    void showComplainantDetails(const string& complainantName) {
        Node* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->complaint.complainantDetails == complainantName) {
                found = true;
         
                cout << "Complaint ID: " << current->complaint.id << endl;
                cout << "Complainant Details: " << current->complaint.complainantDetails << endl;
                cout << "Complaint Details: " << current->complaint.complaintDetails << endl;
                cout << "Severity: " << current->complaint.severity << endl;
                cout << "Date: " << current->complaint.date << endl;
                cout << "-----------------------" << endl;
            }
            current = current->next;
        }
        
        if (!found) {
            cout << "No complaints found for the given complainant." << endl;
        }
    }

    void showAllComplaints() {
        Node* current = head;
        if(head==NULL)
            {
                cout<<"\n Complain List is Empty";
            }else
            {
              
                while (current != nullptr) {
              
                    cout << "Complaint ID: " << current->complaint.id << endl;
                    cout << "Complainant Details: " << current->complaint.complainantDetails << endl;
                    cout << "Complaint Details: " << current->complaint.complaintDetails << endl;
                    cout << "Severity: " << current->complaint.severity << endl;
                    cout << "Date: " << current->complaint.date << endl;
                    cout << "-----------------------" << endl;
                    current = current->next;
        }
     }
    }
};

int main() {
    ComplaintList complaints;
    queue<Complaint> removedComplaints;
    queue<string> complaintStatus;
    
    int option;
    do {
        cout << "----------- Welcome to the Complaint Management System -----------" << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "------------------------------- Menu ------------------------------" << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "*Select a number to intiate a required action*" << endl;
        cout << " " << endl;
        cout << "1. Add New Complaint" << endl;
        cout << " " << endl;
        cout << "2. Remove Complaint" << endl;
        cout << " " << endl;
        cout << "3. Update Complaint Details" << endl;
        cout << " " << endl;
        cout << "4. Show Complaint Details" << endl;
        cout << " " << endl;
        cout << "5. Show Complaints by Complainant" << endl;
        cout << " " << endl;
        cout << "6. Show All Complaints" << endl;
        cout << " " << endl;
        cout << "7. Store Complaint Status" << endl;
        cout << " " << endl;
        cout << "8. Show Closed Complaints" << endl;
        cout << " " << endl;
        cout << "9. Show Removed Complaints" << endl;
        cout << " " << endl;
        cout << "0. Exit" << endl;
        cout << " " << endl;
        cout << "Enter your option: ";
        cin >> option;
        cout << "-----------------------------" << endl;
        
        switch (option) {
            case 1: {
                Complaint newComplaint;
                cout << "Enter complaint ID: ";
                cin >> newComplaint.id;
                
              
                
                Node* current = complaints.getHead();
                bool complaintExists = false;
                while (current != nullptr) {
                    if (current->complaint.id == newComplaint.id) {
                        complaintExists = true;
                        break;
                    }
                    current = current->next;
                }
                
                if (complaintExists) {
                    cout << "This Enquiry is already registered in the system." << endl;
                } else {
                    cout << "Enter complainant details: ";
                    cin.ignore();
                    getline(cin, newComplaint.complainantDetails);
                    cout << "Enter complaint details: ";
                    getline(cin, newComplaint.complaintDetails);
                    cout << "Enter severity: ";
                    getline(cin, newComplaint.severity);
                    cout << "Enter date: ";
                    getline(cin, newComplaint.date);
                    
                    complaints.addComplaint(newComplaint);
                }
                
                break;
            }
            case 2: {
                int complaintID;
                cout << "Enter complaint ID to remove: ";
                cin >> complaintID;
                
                complaints.removeComplaint(complaintID, removedComplaints);
                break;
            }
            case 3: {
                int complaintID;
                cout << "Enter complaint ID to update details: ";
                cin >> complaintID;
                
                complaints.updateComplaint(complaintID);
                break;
            }
            case 4: {
                int complaintID;
                cout << "Enter complaint ID to show details: ";
                cin >> complaintID;
                
                complaints.showComplaintDetails(complaintID);
                break;
            }
            case 5: {
                string complainantName;
                cout << "Enter complainant name to show details: ";
                cin.ignore();
                getline(cin, complainantName);
                
                complaints.showComplainantDetails(complainantName);
                break;
            }
            case 6: {
                complaints.showAllComplaints();
                break;
            }
            case 7: {
                int complaintID;
                cout << "Enter complaint ID to store status: ";
                cin >> complaintID;
                

                Node* current = complaints.getHead();
                bool complaintExists = false;
                while (current != nullptr) {
                    if (current->complaint.id == complaintID) {
                        complaintExists = true;
                        break;
                    }
                    current = current->next;
                }
                
                if (complaintExists) {
                    string status;
                    cout << "Enter status (closed/open/cannot address): ";
                    cin >> status;
                    
                    string statusDetails = "Complaint ID: " + to_string(complaintID) + ", Status: " + status;
                    complaintStatus.push(statusDetails);
                    cout << "Status stored successfully!" << endl;
                } else {
                    cout << "Invalid complaint ID. No such complaint found." << endl;
                }
                
                break;
            }
            case 8: {
                cout << "Closed Complaints:" << endl;
                if(complaintStatus.empty()){
                    cout<<"\n Complain List is Empty";
                }
                while (!complaintStatus.empty()) {
                    string statusDetails = complaintStatus.front();
                    if (statusDetails.find("Status: closed") != string::npos) {
                        cout << statusDetails << endl;
                    }
                    complaintStatus.pop();
                }
                break;
            }
            case 9: {
                cout << "Removed Complaints:" << endl;
                if(removedComplaints.empty()){
                    cout<<"\n Complain List is Empty";
                }
                while (!removedComplaints.empty()) {
                    Complaint removedComplaint = removedComplaints.front();
                    cout << "Complaint ID: " << removedComplaint.id << endl;
                    cout << "Complainant Details: " << removedComplaint.complainantDetails << endl;
                    cout << "Complaint Details: " << removedComplaint.complaintDetails << endl;
                    cout << "Severity: " << removedComplaint.severity << endl;
                    cout << "Date: " << removedComplaint.date << endl;
                    cout << "-----------------------" << endl;
                    removedComplaints.pop();
                }
                break;
            }
            case 0: {
                cout << "Thank You for using the Complaint Management System" << endl;
                cout<<" "<<endl;
                cout << "You will now be Exited from System..." << endl;
                cout<<" "<<endl;
                cout<<"Exiting...... "<<endl;
                break;
            }
            default: {
                cout << "Invalid option !!! . Please try a different option and try again." << endl;
                break;
            }
        }
        
        cout << endl;
    } while (option != 0);

    return 0;
}