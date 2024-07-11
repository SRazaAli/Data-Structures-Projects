#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct course {
	string courseName;
	int courseCreditHours;
	string grade;
	float gradePoints;
};
course courseList[10];

//vars being used globally 
string studentName, enrolmentId;
int noOfCourses;

float totalCreditHours = 0;
float earnedGradePoints = 0;
float gpa = 0;

float gradePoints(string grade) {

	float gradePoints = 0;
	
	if (grade == "A")
		gradePoints = 4;
	else if(grade == "A-")
		gradePoints = 3.7;
	else if (grade == "B+")
		gradePoints = 3.3;
	else if (grade == "B")
		gradePoints = 3;
	else if (grade == "B-")
		gradePoints = 2.7;
	else if (grade == "C+")
		gradePoints = 2.3;
	else if (grade == "C")
		gradePoints = 2;
	else if (grade == "C-")
		gradePoints = 1.7;
	else if (grade == "D+")
		gradePoints = 1.3;
	else if (grade == "D")
		gradePoints = 1;
	else if (grade == "D-")
		gradePoints = 0.7;
	else if (grade == "F")
		gradePoints =0 ;
	else
		cout << "Invalid input...";
	
	return gradePoints;
}

void gradesInput() {
	
	cout << "Enter your name : ";
	getline(cin, studentName);
	cout << "Enter your enrolment id : ";
	getline(cin, enrolmentId);
	cout << "Enter the number of courses : ";
	cin >> noOfCourses;

	cout << "\n";
	for (int i = 0; i < noOfCourses; i++) {
		cout << "Course Name : ";
		cin.ignore();
		getline(cin, courseList[i].courseName);
		cout << "Credit Hours : ";
		cin >> courseList[i].courseCreditHours;
		cout << "Grade Earned : ";
		cin >> courseList[i].grade;
		courseList[i].gradePoints = gradePoints(courseList[i].grade) * courseList[i].courseCreditHours;
		cout << "\n";
	}
}

void printResult() {
	ofstream MyFile("report_card.txt");

	MyFile << "Student Name : " << studentName << endl
		<< "Enrolment Id : " << enrolmentId << endl;
	for (int i = 0; i < noOfCourses; i++) {
		MyFile << courseList[i].courseName << "\t" << courseList[i].courseCreditHours << "\t" << courseList[i].grade << "\t" <<
			courseList[i].gradePoints << endl;
	}
	MyFile << "Total grade points -- " << earnedGradePoints << endl
		<< "Total credit hours -- " << totalCreditHours << endl
		<< "Overall GPA -- " << gpa << endl;


	MyFile.close();
}

void gpaCalculator() {
	char choice;
	

	for (int i = 0; i < noOfCourses; i++) {
		earnedGradePoints += courseList[i].gradePoints;
		totalCreditHours += courseList[i].courseCreditHours;
	}
	gpa = earnedGradePoints / totalCreditHours;

	for (int i = 0; i < noOfCourses; i++) {
		cout << courseList[i].courseName << "\t" << courseList[i].courseCreditHours << "\t" << courseList[i].grade << "\t" <<
			courseList[i].gradePoints << endl;
	}
	cout << "Total grade points -- " << earnedGradePoints << endl
		<< "Total credit hours -- " << totalCreditHours << endl
		<< "Overall GPA -- " << gpa << "\n\n";

	cout << "Do you want to print your result (Y/N) ";
	cin >> choice;
	if (choice == 'y' or choice == 'Y') {
		printResult();
		cout << "-> Report card has been printed successfully...";
	}
	
}



int main() {
	

	cout << "------------- CGPA Calculator -------------" << endl;

	gradesInput();
	gpaCalculator();

	return 0;
}