
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string_view>


using namespace std;

class student
{
private:
    string name, roll_no, course, address, email_id;
    long long int contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
// Project Menu
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "-" << endl;
    cout << "| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "-" << endl;
    cout << " 1. Enter New Record" << endl;
    cout << " 2. Display Record" << endl;
    cout << " 3. Modify Record" << endl;
    cout << " 4. Search Record" << endl;
    cout << " 5. Delete Record" << endl;
    cout << " 6. Exit"
         << endl;

    cout << "............................" << endl;
    cout << "Choose Options:[1/2/3/4/5/6]" << endl;
    cout << "............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << " Add Another Student Record (Y, N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        cout << " Program Is Exit";
        exit(0);
    default:
        cout << " Invalid Choice... Please Try Again...";
    }
     getch();
    goto menustart;
} 

void student::insert() // Add student details
{
    system("cls");
    fstream file;
        cout << "************************* Add Student Details *************************-" << endl;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Roll No.: ";
    cin >> roll_no;
    cout << "Enter Course: ";
    cin >> course;
email:
    cout << "Enter Email Id(name@gmail.com): ";
    cin >> email_id;
   
contact:
    cout << "Enter Contact No(9639xxxxxx): ";
    cin >> contact_no;
    if (contact_no < 1000000000 || contact_no > 9999999999)
    {
        cout << " Please Enter Only 10 Digits..." << endl;
        goto contact;
    }
    cout << "Enter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "";
    file.close();
}
void student::display() // Display data of student
{
    system("cls");
    fstream file;
    int total = 1;
        cout << "************************* Student Record Table *************************" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "No Data is found... ";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "Student No.: " << total++ << endl;
            cout << "Name: " << name << "";
            cout << "Roll No.: " << roll_no << "";
            cout << "Course: " << course << "";
            cout << "Email Id: " << email_id << "";
            cout << "Contact No.: " << contact_no << "";
            cout << "Address: " << address << "";
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {

            cout << "No Data is Present..." << endl;
        }
    }

    file.close();
}
void student::modify() // Modify details of student
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
        cout << "************************* Student Modify Details *************************-----" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "No Data is Present..";
        file.close();
    }
    else
    {
        cout << "Enter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "";
            else
            {
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Roll No.: ";
                cin >> roll_no;
                cout << "Enter Course: ";
                cin >> course;
            email:
                cout << "Enter Email Id(name@gmail.com): ";
                cin >> email_id;
                
        contact:
                cout << "Enter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                if (contact_no < 1000000000 || contact_no > 9999999999)
                {
                    cout << " Please Enter Only 10 Digits..." << endl;
                    goto contact;
                }
                cout << "Enter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << " Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
                cout << "************************* Student Search Data *************************" << endl;
        cout << "No Data is Present... " << endl;
    }
    else
    {
        string rollno;
                cout << "************************* Student Search Data *************************" << endl;
        cout << "Enter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "Name: " << name << "";
                cout << "Roll No.: " << roll_no << "";
                cout << "Course: " << course << "";
                cout << "Email Id: " << email_id << "";
                cout << "Contact No.: " << contact_no << "";
                cout << "Address: " << address << "";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << " Student Roll NO. Not Found....";
            }
        }
        file.close();
    }
}
void student::deleted() // ddeleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
        cout << "************************* Delete Student Details *************************" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "No Data is Present..";
        file.close();
    }
    else
    {
        cout << "Enter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "";
            }
            else
            {
                found++;
                cout << "Successfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << " Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
int main()
{
    student project; // object
    project.menu();  //object calling
    return 0;
}