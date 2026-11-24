#include "student.h"
#include <limits>
using namespace std;

void Student::setName(string n)
{
    name = n;
}

string Student::getName()
{
    return name;
}

void Student::setGrade(int i, double g)
{
    grades[i] = g;
}

double Student::getGrade(int i)
{
    return grades[i];
}

void collectGrades(Student &s)
{
    string name;
    double grade;

    cout << "Enter student name: ";
    getline(cin, name);
    s.setName(name);

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> grade;

        while (cin.fail() || grade < 0 || grade > 100)
        {
            cout << "ERROR! Enter a grade from 0 to 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> grade;
        }

        s.setGrade(i, grade);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double calculateAverage(Student s)
{
    double total = 0;

    for (int i = 0; i < 5; i++)
    {
        total += s.getGrade(i);
    }

    return total / 5;
}

char getLetterGrade(double average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

bool isPassing(double average)
{
    return average >= 60;
}

void displaySummary(Student s)
{
    double average = calculateAverage(s);

    cout << "\n===== STUDENT SUMMARY =====" << endl;
    cout << "Name: " << s.getName() << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Grade " << i + 1 << ": "
             << s.getGrade(i) << endl;
    }

    cout << "Average: " << average << endl;
    cout << "Letter Grade: " << getLetterGrade(average) << endl;

    if (isPassing(average))
        cout << "Result: PASS" << endl;
    else
        cout << "Result: FAIL" << endl;
}

void displaySummary(Student s, string message)
{
    cout << "\n" << message << endl;
    displaySummary(s);
}
