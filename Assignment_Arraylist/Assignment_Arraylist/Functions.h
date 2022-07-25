#pragma once
#include "Source.h"

struct Tutor {
	int id;
	string name;
	string dateJoined;
	string dateTerminated;
	double hourlyRate;
	string phone; //String so 0 can be written
	string address;
	string tcCode;
	string tcName;
	string subjectCode;
	string subjectName;
	double rating;
}; 

void login();
void tutors();
void mainMenu();
void insertTutor(struct Tutor tutor);
void inputTutor();
void displayTutor();
void searchTutorID();
void searchTutorRating();
void sortTutorID();
void sortTutorPay();
void sortTutorRating();
void modifyTutor();
void deleteTutor();