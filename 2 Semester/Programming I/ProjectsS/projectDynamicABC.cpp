// Author: reDragonCoder

// LIBRARIES
#include <iostream>
#include <stdlib.h>
#include <string.h>

//GLOBAL CONSTANTS
const int MAX = 30;

//NAMESPACE
using namespace std;

//STRCTURES
struct Date{
    int dd;
    int mm;
    int yy;
};

struct Student{
    int id;
    char name[MAX];
    char major[MAX];
    float grades[3];
    float tuition;
    Date enrollment;
    Student *node;
};

//TYPE DEFINITION
typedef struct Student *Tlist;

//PROTOTYPES
void menu();
Student* capture();
void addStudent(Tlist&, Student*);
bool verifyDate(Student*);
bool validateMonth_Day(Student*);
int getId();
void deleteStudent(Tlist&, int);
void showList(Tlist);
void showListNodes(Tlist);
void modify(Tlist, int, Student*);
void modifyMenu(Tlist, Student*);
void findStudent(Tlist,int);
void extras(Tlist);
void gpa(Tlist, int);
void totalTuition(Tlist);
void enrollmentList(Tlist, int&);
void sortList(Tlist, Student[], int);
void showEnrollment(Student[], int);
void captureModify(Student*);

//MAIN
int main(){
    menu();
    return 0;
}

//IMPLEMENTATIONS
void menu(){
    int opt = 0, id = 0;
    Tlist list = NULL;
    Student *data;
    do {
        cout << "      MENU     " << endl;
        cout << "Add...........1" << endl;
        cout << "Delete........2" << endl;
        cout << "Modify........3" << endl;
        cout << "Find student..4" << endl;
        cout << "Extras........5" << endl;
        cout << "Exit..........6" << endl;
        cin >> opt;
        switch (opt) {
            case 1:
                data = capture();
                if (verifyDate(data)) {
                    addStudent(list, data);
                    cout << "The student information has been successfully added." << endl;
                    cout << endl;
                } else {
                    delete data;
                    cout << "Some of your data is incorrect! Please verify and try again \n";
                }
                break;
            case 2:
                id = getId();
                deleteStudent(list, id);
                showListNodes(list);
                break;
            case 3:
                id = getId();
                modifyMenu(list, data);
                break;
            case 4:
                id = getId();
                findStudent(list, id);
                break;
            case 5:
                extras(list);
                break;
        }
    } while (opt != 6);
}

Student* capture (){
    Student *aux;
    cout << endl;
    aux = new struct Student;
    cout << "Please enter the student info: " << endl;
    cout << "ID: ";
    cin >> aux->id;
    fflush(stdin);
    cout << "Name: ";
    cin.ignore();
    cin.getline(aux->name, 15);
    fflush(stdin);
    cout << "Major: ";
    cin.getline(aux->major, 15);
    cout << "Grades: "<<endl;
    for(int g = 0; g < 3; g++){
        cout << "Grade " << (g+1) << ": ";
        cin >> aux->grades[g];
    }
    cout << "Tuition: ";
    cin >> aux->tuition;
    cout << "Enrollment date: " << endl;
    cout << "Day: ";
    cin >> aux->enrollment.dd;
    cout << "Month: ";
    cin >> aux->enrollment.mm;
    cout << "Year: ";
    cin >> aux->enrollment.yy;
    return aux;
}

bool verifyDate(Student* data){
    bool verification = false;
    int leap = 0;
    if((data->enrollment.yy > 1949) && (data->enrollment.yy < 2101)){
        if((data->enrollment.mm > 0) && (data->enrollment.mm < 13)){
            if((data->enrollment.dd > 0) && (data->enrollment.dd < 32)){
                if((data->enrollment.mm == 2) && (data->enrollment.dd > 28)){
                    if(data->enrollment.dd == 29){
                        if(((data->enrollment.yy % 4 != 0) && (data->enrollment.yy % 400 != 0)) || (data->enrollment.yy % 100 == 0)){
                            if(data->enrollment.dd < 30){
                                verification = true;
                                leap = 1;
                            }
                        } else {
                            leap = 0;
                        }
                    } else {
                        if(data->enrollment.dd > 29){
                            cout << "That's not a valid date! Please try again." << endl;
                            verification = false;
                        }
                    }
                }
                if(leap == 0){
                    if(validateMonth_Day(data) == true){
                        verification = true;
                    } else {
                        cout << "Some of your data is incorrect! Please verify and try again." << endl;
                        verification = false;
                    }
                }
            } else {
                verification = false;
            }
        } else {
            verification = false;
        }
    } else {
        verification = false;
    }
    return verification;
}

bool validateMonth_Day(Student *data){
    bool validation = false;
    if(data->enrollment.mm == 4 || data->enrollment.mm == 6 || data->enrollment.mm == 9 || data->enrollment.mm == 11){ // 30 days
        if((data->enrollment.dd > 0) && (data->enrollment.dd < 31)){
            validation = true;
        } else {
            validation = false;
        }
    } else {
        if(data->enrollment.mm == 1 || data->enrollment.mm == 3 || data->enrollment.mm == 5 || data->enrollment.mm == 7 || data->enrollment.mm == 8 || data->enrollment.mm == 10 || data->enrollment.mm == 12){ // 31 days
            if((data->enrollment.dd > 0) && (data->enrollment.dd < 32)){
                validation = true;
            } else {
                validation = false;
            }
        } else {
            validation = false;
        }
    }
    return validation;
}

void addStudent(Tlist &list, Student *data){
    Tlist niu;
    niu = new(struct Student);
    niu->id = data->id;
    strcpy(niu->name, data->name);
    strcpy(niu->major, data->major);
    for(int g = 0; g < 3; g++){
        niu->grades[g] = data->grades[g];
    }
    niu->tuition = data->tuition;
    niu->enrollment.dd = data->enrollment.dd;
    niu->enrollment.mm = data->enrollment.mm;
    niu->enrollment.yy = data->enrollment.yy;
    niu->node = list;
    list = niu;
}

int getId(){
    cout << endl;
    int id;
    cout << "Enter the student ID: ";
    cin >> id;
    return id;
}

void deleteStudent(Tlist& list, int id){
    Tlist aux = NULL;
    Tlist actual = list;
    bool flag = false;
    
    if (list == NULL){
        cout << "The list is empty \n\n";
    } else {
        while(actual != NULL){
            if(actual->id == id){
                if (aux == NULL){
                    list = actual->node; // if the student is first in the list
                    flag = true;
                } else {
                    aux->node = actual->node; // if the student is at the middle or at the end of the list
                    flag = true;
                }
                delete actual;
                cout << "The student has been deleted successfully \n\n";
                break;
            }
            aux = actual;
            actual = actual->node;
        }
        if (flag == false)
            cout << "Student " << id << " not found \n\n";
    }
}

void findStudent(Tlist list, int id){
    bool found = false;
    Tlist aux = NULL;
    if (list == NULL){
        cout << "The list is empty \n\n";
    } else {
        while (list != NULL) {
            if (list->id == id) {
                aux = list;
                found = true;
                break;
            }
            list = list->node;
        }
    }
    if (found == false) {
        cout << "The given ID is not found within our system" << endl;
    } else {
        cout << "Student found! " << endl;
        showList(aux);
    }
}

void showListNodes(Tlist list){
    int tot = 0;
    while(list != NULL){
        cout << list->id << endl;
        list = list->node;
        tot++; // count nodes
    }
    cout << "Your list has " << tot << " nodes \n";
}

void extras(Tlist list){
    int opt = 0, id = 0, totNodes = 0;
    do {
        cout << "      EXTRAS MENU     " << endl;
        cout << "GPA.....................1" << endl;
        cout << "Total Tuition...........2" << endl;
        cout << "Enrollment Dates........3" << endl;
        cout << "Back to Main Menu.......4" << endl;
        cin >> opt;
        switch (opt){
            case 1:
                id = getId();
                gpa(list, id);
                cout << " ";
                break;
            case 2:
                totalTuition(list);
                break;
            case 3:
                enrollmentList(list, totNodes);
                break;
        }
    } while(opt != 4);
}

void gpa(Tlist list, int id){
    float gpa = 0;
    bool found = false;
    Tlist aux = NULL;
    if (list == NULL){
        cout << "The list is empty \n\n";
    } else {
        while (list != NULL) {
            if (list->id == id) {
                aux = list;
                found = true;
                break;
            }
            list = list->node;
        }
    }
    if (found == false) {
        cout << "The given ID is not found within our system" << endl;
    } else {
        for(int g = 0; g < 3; g++){
            gpa += aux->grades[g];
        }
        gpa /= 3;
        cout << "This student has a " << gpa << " grade point average" << endl;
    }
}

void totalTuition(Tlist list){
    float tuition = 0;
    if(list == NULL){
        cout << "The list is empty \n\n";
    } else {
        while(list != NULL){
            tuition += list->tuition;
            list = list->node; // moves to the next spot
        }
    }
    cout << "The total tuition fee is $" << tuition << endl;
}

void enrollmentList(Tlist list, int &totNodes){
    Tlist temp = list;
    while(temp != NULL){
        totNodes++;
        temp = temp->node;
    }
    if (totNodes > 0){
        Student array[totNodes];
        sortList(list, array, totNodes);
    } else {
        cout << "The list is empty \n\n";
    }
}

void showList(Tlist list){
    cout << "ID: " << list->id << endl;
    cout << "Name: " << list->name << endl;
    cout << "Major: " << list->major << endl;
    cout << "Grades: " << endl;
    for(int g = 0; g < 3; g++){
        cout << "Grade " << (g+1) << ": " << list->grades[g] << endl;
    }
    cout << "Tuition: " << list->tuition << endl;
    cout << "Enrollment date: " << endl;
    cout << "Day: " << list->enrollment.dd << endl;
    cout << "Month: " << list->enrollment.mm << endl;
    cout << "Year: " << list->enrollment.yy << endl;
}

void sortList(Tlist list, Student array[], int totNodes){
    int k = 0;
    while(list != NULL && k < totNodes){
        array[k] = *list;
        list = list->node;
        k++;
    }

    for (int i = 0; i < totNodes - 1; i++) {
        for (int j = 0; j < totNodes - i - 1; j++) {
            if (array[j].enrollment.yy > array[j + 1].enrollment.yy ||
                (array[j].enrollment.yy == array[j + 1].enrollment.yy && array[j].enrollment.mm > array[j + 1].enrollment.mm) ||
                (array[j].enrollment.yy == array[j + 1].enrollment.yy && array[j].enrollment.mm == array[j + 1].enrollment.mm && array[j].enrollment.dd > array[j + 1].enrollment.dd)) {
                swap(array[j], array[j + 1]);
            }
        }
    }
    showEnrollment(array, totNodes);
}

void swap(Student &a, Student &b){
    Student temp = a;
    a = b;
    b = temp;
}

void showEnrollment(Student array[], int totNodes){
    cout << "ID\t\tEnrollment Date" << endl;
    for(int i = 0; i < totNodes; i++){
        cout << array[i].id << "\t\t" << array[i].enrollment.mm << "/" << array[i].enrollment.dd << "/" << array[i].enrollment.yy << endl;
    }
}

void modifyMenu(Tlist list, Student *data){
    int opt;
    do {
        cout << "WHAT DO YOU WANT TO MODIFY?" << endl;
        cout << "ID............1" << endl;
        cout << "Name..........2" << endl;
        cout << "Major.........3" << endl;
        cout << "Grades........4" << endl;
        cout << "Tuition.......5" << endl;
        cout << "Enrollment....6" << endl;
        cout << "All...........7" << endl;
        cout << "Exit..........8" << endl;
        cin >> opt;
        switch (opt) {
            case 1:
                cout << "ID: ";
                cin >> list->id;
                break;
            case 2:
                cout << "New name: ";
                fflush(stdin);
                cin.getline(list->name, 15);
                break;
            case 3:
                cout << "Major: ";
                fflush(stdin);
                cin.ignore();
                cin.getline(list->major, 15);
                break;
            case 4:
                cout << "Grades: \n";
                for (int i = 0; i < 3; i++) {
                    cout << "Grade [" << (i+1) << "]: " << endl;
                    cin >> list->grades[i];
                }
                break;
            case 5:
                cout << "Tuition: ";
                cin >> list->tuition;
                break;
            case 6:
                cout << "Day: ";
                cin >> list->enrollment.dd;
                cout << "Month: ";
                cin >> list->enrollment.mm;
                cout << "Year: ";
                cin >> list->enrollment.yy;
                break;
            case 7:
                captureModify(data);
                break;
        }
    } while (opt != 8);
}

void captureModify(Student *data){
    Student *aux;
    aux = data;
    cout << "Please enter the student info: " << endl;
    cout << "ID: ";
    cin >> aux->id;
    fflush(stdin);
    cout << "Name: ";
    cin.getline(aux->name, 15);
    fflush(stdin);
    cout << "Major: ";
    cin.getline(aux->major, 15);
    cout << "Grades: "<<endl;
    for(int g = 0; g < 3; g++){
        cout << "Grade: " << (g+1) << ": ";
        cin >> aux->grades[g];
    }
    cout << "Tuition: ";
    cin >> aux->tuition;
    cout << "Enrollment date: "<<endl;
    cout << "Day: ";
    cin >> aux->enrollment.dd;
    cout << "Month: ";
    cin >> aux->enrollment.mm;
    cout << "Year: ";
    cin >> aux->enrollment.yy;
}
