#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;
int const m = 200;
struct Employes {
    int rollnumb;
    char name[20];
    char middlename[20];
    char surname[30];
    int numshop;
    char occupation[20];
    char address[20];
    int salary;
    int child;
    char buff[20];
    float salaryF;
};
void writeToFile(Employes* text, int n) {
    ofstream fout("t.txt");
    for (int i = 0; i < n; i++) {
        fout << "Personnel number:" << text[i].rollnumb << endl;
        fout << "Name:" << text[i].name << endl;
        fout << "Department number:" << text[i].numshop << endl;
        fout << "Occupation:" << text[i].occupation << endl;
        fout << "Address:" << text[i].address << endl;
        fout << "Salary:" << text[i].salary << endl;
        fout << "Children:" << text[i].child << endl;
    }
    fout.close();
}
void init(Employes* dbase, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n Worker number " << i + 1;
        cout << "\nEnter personnel number:\n";
        cin >> dbase[i].rollnumb;
        cout << "Enter name:\n";
        cin >> dbase[i].name;
        cout << "Enter department number:\n";
        cin >> dbase[i].numshop;
        cout << "Enter occupation:\n";
        cin >> dbase[i].occupation;
        cout << "Enter address:\n";
        cin >> dbase[i].address;
        cout << "Enter salary:\n";
        cin >> dbase[i].salary;
        cout << "Enter child:\n";
        cin >> dbase[i].child;

    }
}
void show(Employes* dbase, int n) {

    for (int i = 0; i < n; i++) {
        cout << "Personnel number:" << dbase[i].rollnumb << "\n";
        cout << "Name:" << dbase[i].name << "\n";
        cout << "Department number:" << dbase[i].numshop << "\n";
        cout << "Occupation:" << dbase[i].occupation << "\n";
        cout << "Address:" << dbase[i].address << "\n";
        cout << "Salary:" << dbase[i].salary << "\n";
        cout << "Children:" << dbase[i].child << "\n";

    }
}
void add(Employes*& text, int& n) {
    Employes* text2 = new Employes[n + 1];
    for (int i = 0; i < n; i++) {
        text2[i] = text[i];
    }
    ifstream fin("t.txt");
    if (!fin.is_open())
        cout << "Error\n";
    ofstream fout("t.txt", ios_base::app);
    cout << "\nEnter personnel number:\n";
    cin >> text2[n].rollnumb;
    fout << "\nPersonnel number:" << text2[n].rollnumb << endl;
    cout << "Enter name:\n";
    cin >> text2[n].name;
    fout << "Name:" << text2[n].name << endl;
    cout << "Enter department number:\n";
    cin >> text2[n].numshop;
    fout << "Department number:" << text2[n].numshop << endl;
    cout << "Enter occupation:\n";
    cin >> text2[n].occupation;
    fout << "Occupation:" << text2[n].occupation << endl;
    cout << "Enter address:\n";
    cin >> text2[n].address;
    fout << "Address:" << text2[n].address << endl;
    cout << "Enter salary:\n";
    cin >> text2[n].salary;
    fout << "Salary:" << text2[n].salary << endl;
    cout << "Enter child:\n";
    cin >> text2[n].child;
    fout << "Children:" << text2[n].child << endl;
    fout.close();

    delete[] text;
    text = text2;
    n++;
}
void readFromFile() {
    ifstream fin("t.txt");
    char s[m] = {};
    cout << "Information about workers\n";
    while (!fin.eof()) {
        fin.getline(s, m);
        cout << s << endl;
    }
}
void sortE(Employes* dbase, int n)
{
    int w;
    cout << "Enter department number to sort:" << endl;
    cin >> w;
    Employes temp;
    ifstream fin("t.txt");
    if (!fin.is_open())
        cout << "Error\n";
    ofstream fout("t.txt", ios_base::app);
    for (int i = 0; i < n; i++) {
        if (dbase[i].numshop == w) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (strcmp(dbase[j].name, dbase[j + 1].name) > 0) {
                        temp = dbase[j];
                        dbase[j] = dbase[j + 1];
                        dbase[j + 1] = temp;
                    }
                }
            }
            cout << dbase[i].name << endl;
            fout << dbase[i].name << endl;

            int summ = 0;
            for (int j = 0; j < n; j++) {
                summ += dbase[j].salary;
            }
            dbase[i].salaryF = summ;
            dbase[n].salaryF = dbase[i].salaryF;
        }

    }
    cout << "\nSalary fond:" <<dbase[n].salaryF;
    fout <<dbase[n].salaryF<< endl;
    fout.close();
}


int main()
{
    enum Menu{INIT,SHOWING,SORTING,WRITING,READING,ADDING};
    int n = 3;
    Employes* dbase = new Employes[n];
    int  chNum = 0;
    while (true){
        cout << " 0 initilization\n  1-showing\n 2-sorting worker\n 3-writing\n 4 reading\n 5-addingnan element\n";
        int k;
        cin >> k;
        cout << endl;
        switch (k){
        case INIT:
            init(dbase, n);
            break;
        case SHOWING:
            show(dbase, n);
            break;
        case SORTING:
            sortE(dbase, n);
            break;
        case WRITING:
            writeToFile(dbase, n);
            break;
        case READING:
            readFromFile();
            break;
        case ADDING:
            add(dbase, n);
            break;
        default:
            cout << "Wrong input";
        }
    }
    system("cls");

}
