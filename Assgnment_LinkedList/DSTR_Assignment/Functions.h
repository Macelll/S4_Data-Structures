#pragma once
#include "Source.h"

string userPass = "123";

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

	Tutor* next;
	Tutor* prev;
}*head, *tail;

void login();
void mainMenu();
void tutors();
Tutor* addTutor(int id, string name, string dateJoined, string dateTerminated, double hourlyRate, string phone, string address, string tcCode, string tcName, string subjectCode, string subjectName, double rating);
void insertTutor(Tutor* tutor);
void inputTutor();
void displayTutor();
void searchTutorID();
void searchTutorRating();
void sortTutorID();
void sortTutorPay();
void sortTutorRating();
void modifyTutor();
void deleteTutor();
