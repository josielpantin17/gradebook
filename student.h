#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    double grades[5];

public:
    void setName(string n);
    string getName();

    void setGrade(int i, double g);
    double getGrade(int i);
};

void collectGrades(Student &s);
double calculateAverage(Student s);
char getLetterGrade(double average);
bool isPassing(double average);
void displaySummary(Student s);
void displaySummary(Student s, string message);

#endif
