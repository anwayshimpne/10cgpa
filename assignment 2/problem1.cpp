#include<iostream>
using namespace std;

struct student{
    string name;
    int rollNo;
    string div;
    string year; 
};

int main(){

    int n;
    cout<<"Enter number of students :";
    cin>>n;

    student s[n];

    cout << "\nEnter student details (Name RollNo Division Year):\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].rollNo >> s[i].div >> s[i].year;
    }

    string searchName = "Yashraj";
    int searchRoll = 17;
    string searchDiv = "B";
    string searchYear = "SY";

    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (s[i].name == searchName &&
            s[i].rollNo == searchRoll &&
            s[i].div == searchDiv &&
            s[i].year == searchYear) {
            
            cout << "\nStudent Found!" << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Roll No: " << s[i].rollNo << endl;
            cout << "Division: " << s[i].div << endl;
            cout << "Year: " << s[i].year << endl;
            
            flag = true;
            break;
        }
    }

    if(!flag){
        cout<<"Student not found !!";
    }


return 0;
}