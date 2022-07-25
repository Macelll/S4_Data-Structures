#include "Source.h"
#include "Functions.h"

void login() {
	string inpPass;

	cout << "Welcome to Tutors Management System\n" << string(36, '=') << endl;
	while (inpPass != ::userPass) {
		cout << "*Accessable only by admins*" << endl;
		cout << "Enter Admin Password : "; cin >> inpPass;
		if (inpPass != ::userPass) {
			cout << "\nIncorrect Password, Please try again or enter 0 to exit." << endl;
		}
		else if (inpPass == "0") {
			exit(0);
		}
	}
	mainMenu();
}
void tutors() {

	head = NULL;

	Tutor* tutor;
	
	tutor = addTutor(2, "Macel", "13 October 2001",
		"18 January 2022", 40, "123456789", "Parkhill Residensi",
		"A01", "Ampang", "MT", "Math", 1);
	insertTutor(tutor);

	tutor = addTutor(1, "Ros", "13 October 2001",
		"18 October 2022", 3, "987654321", "Parkhill Residensi",
		"C01", "Cheras", "ENG", "English", 5);
	insertTutor(tutor);

	tutor = addTutor(3, "Modi", "13 October 2001",
		"18 October 2022", 10, "01169696969", "Parkhill Residensi",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.3);
	insertTutor(tutor);

	tutor = addTutor(4, "Celin", "13 October 2001",
		"18 April 2022", 69.6, "123123123", "Endah Promenade",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.5);
	insertTutor(tutor);

	tutor = addTutor(5, "Mingsen", "13 January 2001",
		"18 February 2021", 21, "222222222", "APU Apartment",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4);
	insertTutor(tutor);

	tutor = addTutor(6, "Leon", "13 February 2003",
		"18 June 2022", 53, "333333333", "Pavilion",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.5);
	insertTutor(tutor);

	tutor = addTutor(8, "Jeffrey", "13 March 2006",
		"18 January 2022", 40, "01169696969", "APU Apartment",
		"A01", "Ampang", "MT", "Math", 0.1);
	insertTutor(tutor);

	tutor = addTutor(7, "Chong", "13 April 2002",
		"18 May 2022", 78, "01169696969", "Pinnacle",
		"C01", "Cheras", "ENG", "English", 5);
	insertTutor(tutor);

	tutor = addTutor(9, "Tanveer", "13 May 2011",
		"18 April 2022", 99, "01169696969", "Parkhill Residensi",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.9);
	insertTutor(tutor);

	tutor = addTutor(10, "Dhason", "13 June 2012",
		"18 May 2022", 10000, "01169696969", "Parkhill Residensi",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 3.4);
	insertTutor(tutor);
	
}
void mainMenu() {

	cout << "\nMain Menu" << endl << string(10, '=');
	int opt = 69;

	while (opt < 0 || opt > 9) {
		cout << endl <<
			"0. To Exit Program\n" <<
			"1. Add Tutor Records\n" <<
			"2. Display Tutor Records\n" <<
			"3. Search a Tutor by Tutor ID\n" <<
			"4. Search Tutors by Rating\n" <<
			"5. Sort and Display by Tutors ID [Ascending]\n" <<
			"6. Sort and Display by Tutors Pay Rate [Ascending]\n" <<
			"7. Sort and Display by Tutors Rating [Ascending]\n" <<
			"8. Modify a Tutor Record\n" <<
			"9. Delete a Tutor Record\n";
		cout << "Enter your option: "; cin >> opt;
	}
	switch (opt) {
	case 0:
		cout << "Thank You~" << endl;
		exit(0); break;
	case 1:
		inputTutor(); break;
	case 2:
		displayTutor(); break;
	case 3:
		searchTutorID(); break;
	case 4:
		searchTutorRating(); break;
	case 5:
		sortTutorID(); break;
	case 6:
		sortTutorPay(); break;
	case 7:
		sortTutorRating(); break;
	case 8:
		modifyTutor(); break;
	case 9:
		deleteTutor(); break;
	default:
		cout << "Invalid Option, Please Try Again" << endl << endl;
	}

	return;
}
Tutor* addTutor(int id, string name, string dateJoined, string dateTerminated, double hourlyRate, string phone, string address, string tcCode, string tcName, string subjectCode, string subjectName, double rating) {

	Tutor* newTutor = new Tutor;

	newTutor->id = id;
	newTutor->name = name;
	newTutor->dateJoined = dateJoined;
	newTutor->dateTerminated = dateTerminated;
	newTutor->hourlyRate = hourlyRate;
	newTutor->phone = phone;
	newTutor->address = address;
	newTutor->tcCode = tcCode;
	newTutor->tcName = tcName;
	newTutor->subjectCode = subjectCode;
	newTutor->subjectName = subjectName;
	newTutor->rating = rating;
	newTutor->next = NULL;

	return newTutor;
}
void insertTutor(Tutor* tutor) { //Insert into front of linked list
	if (head == NULL) {
		head = tutor;
	}
	else {
		Tutor* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = tutor;
	}
}

//i. Add a Tutor Record;
void inputTutor() {

	int id; string name; string dateJoined; string dateTerminated; double hourlyRate; string phone; string address; string tcCode; string tcName; string subjectCode; string subjectName; double rating;

	cout << "\nAdd Tutor Record\n" << string(18, '=') << endl;

	cout << "Tutor ID            : "; cin >> id;
	cout << "Name                : "; cin >> name;
	cout << "Date Joined         : "; cin >> dateJoined;	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Date Terminated     : "; cin >> dateTerminated;	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Hourly Rate         : "; cin >> hourlyRate;
	cout << "Phone               : "; cin >> phone;
	cout << "Address             : "; cin >> address;
	cout << "Tuition Centre Code : "; cin >> tcCode;
	cout << "Tuition Centre Name : "; cin >> tcName;
	cout << "Subject Code        : "; cin >> subjectCode;
	cout << "Subject Name        : "; cin >> subjectName;
	cout << "Rating              : "; cin >> rating;
	cout << endl << endl;

	Tutor* tutor = addTutor(id, name, dateJoined, dateTerminated, hourlyRate, phone, address, tcCode, tcName, subjectCode, subjectName, rating);
	insertTutor(tutor);

	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}

//ii. Display All Records
void displayTutor() {
	Tutor* current = head;

	cout << "\nDisplaying All Tutors~\n" << string(22, '-') << endl;

	while (current != NULL) {
		for (int i = 0; i < 5; i++) {
		cout
			<<   "Tutor ID            : " << current->id
			<< "\nName                : " << current->name
			<< "\nDate Joined         : " << current->dateJoined
			<< "\nDate Terminated     : " << current->dateTerminated
			<< "\nHourly Rate         : " << current->hourlyRate
			<< "\nPhone               : " << current->phone
			<< "\nAddress             : " << current->address
			<< "\nTuition Centre Code : " << current->tcCode
			<< "\nTuition Centre Name : " << current->tcName
			<< "\nSubject Code        : " << current->subjectCode
			<< "\nSubject Name        : " << current->subjectName
			<< "\nRating              : " << current->rating
			<< endl << endl;

		current = current->next;
		}
		break;
	} 

	cout
		<< string(12, '=') << endl
		<< "End of List" << endl
		<< string(12, '=') << endl << endl;

	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}

//iii. Search a Tutor by Tutor ID
void searchTutorID() {
	Tutor* current = head;
	int id;
	bool found = false;
	int input;

	cout << "\nSearch a Tutor by Tutor ID\n" << string(29, '=') << endl;

	cout << "Enter Tutor ID : "; cin >> id;

	while (current != NULL) {
		if (current->id == id) {
			cout
				<<   "Tutor ID            : " << current->id
				<< "\nName                : " << current->name
				<< "\nDate Joined         : " << current->dateJoined
				<< "\nDate Terminated     : " << current->dateTerminated
				<< "\nHourly Rate         : " << current->hourlyRate
				<< "\nPhone               : " << current->phone
				<< "\nAddress             : " << current->address
				<< "\nTuition Centre Code : " << current->tcCode
				<< "\nTuition Centre Name : " << current->tcName
				<< "\nSubject Code        : " << current->subjectCode
				<< "\nSubject Name        : " << current->subjectName
				<< "\nRating              : " << current->rating
				<< endl << endl;
			found = true;
			break;
		}
		else if (current->id != id) {
			current = current->next;
		}
	}
	if (found == false) {
		cout << "Unable to find tutor ID, press 1 to try again, or any to go back : ";
		cin >> input;
		if (input == 1) {
			searchTutorID();
		}
		else {
			return;
		}
	}
	else if (found == true) {
		cout << "Tutor Found, Returning to Main Menu~" << endl;
		mainMenu();
	}
}

//iv. Search Tutors by overall performance (Rating)
void searchTutorRating() {
	Tutor* current = head;
	double rating;
	bool found = false;
	int input;

	cout << "\nSearch a Tutors by Overall Performance (Rating)\n" << string(50, '=') << endl;
	cout << "Enter Tutor Rating : "; cin >> rating;

	while (current != NULL) {
		if (current->rating == rating) {
			cout
				<<   "Tutor ID            : " << current->id
				<< "\nName                : " << current->name
				<< "\nDate Joined         : " << current->dateJoined
				<< "\nDate Terminated     : " << current->dateTerminated
				<< "\nHourly Rate         : " << current->hourlyRate
				<< "\nPhone               : " << current->phone
				<< "\nAddress             : " << current->address
				<< "\nTuition Centre Code : " << current->tcCode
				<< "\nTuition Centre Name : " << current->tcName
				<< "\nSubject Code        : " << current->subjectCode
				<< "\nSubject Name        : " << current->subjectName
				<< "\nRating              : " << current->rating
				<< endl << endl;
			found = true;
			current = current->next;
		}
		else if (current->rating != rating) {
			current = current->next;
		}
	}
	if (found == false) {
		cout << "Unable to find tutor ID, press 1 to try again, or any to go back : ";
		cin >> input;
		if (input == 1) {
			searchTutorRating();
		}
		else {
			return;
		}
	}
	else if (found == true) {
		cout << "Tutors Found, Returning to Main Menu~" << endl;
		mainMenu();
	}
}

//v. Sort and display by Tutors ID in ascending order
void sortTutorID() {
	//Node current will point to head
	Tutor* current = head;
	Tutor* index = NULL;

	int id;
	string name;
	string dateJoined;
	string dateTerminated;
	double hourlyRate;
	string phone;
	string address;
	string tcCode;
	string tcName;
	string subjectCode;
	string subjectName;
	double rating;

	cout << "\nSort and display by Tutors ID in ascending order\n" << string(50, '=') << endl;
	cout << "Sorting Tutors by Tutor ID[Ascending]" << endl;

	if (head == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			//Node index will point to node next to current
			index = current->next;
			while (index != NULL) {
				//If current node's data is greater than index's node data, swap the data between them
				if (current->id > index->id) {
					id = current->id;		current->id = index->id;index->id = id;
					name = current->name;current->name = index->name;index->name = name;
					dateJoined = current->dateJoined;current->dateJoined = index->dateJoined;index->dateJoined = dateJoined;
					dateTerminated = current->dateTerminated;current->dateTerminated = index->dateTerminated;index->dateTerminated = dateTerminated;
					hourlyRate = current->hourlyRate;current->hourlyRate = index->hourlyRate;index->hourlyRate = hourlyRate;
					address = current->address;current->address = index->address;index->address = address;
					tcCode = current->tcCode;current->tcCode = index->tcCode;index->tcCode = tcCode;
					tcName = current->tcName;current->tcName = index->tcName;index->tcName = tcName;
					subjectCode = current->subjectCode;current->subjectCode = index->subjectCode;index->subjectCode = subjectCode;
					subjectName = current->subjectName;current->subjectName = index->subjectName;index->subjectName = subjectName;
					rating = current->rating;current->rating = index->rating;index->rating = rating;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
	displayTutor();
	cout << "\nReturning to Main Menu" << endl << endl;
	return;
}

//vi. Sort and display by Tutors Hourly Pay Rate in ascending order
void sortTutorPay() {
	//Node current will point to head
	Tutor* current = head;
	Tutor* index = NULL;
	
	int id;
	string name;
	string dateJoined;
	string dateTerminated;
	double hourlyRate;
	string phone;
	string address;
	string tcCode;
	string tcName;
	string subjectCode;
	string subjectName;
	double rating;

	cout << "\nSort and display by Tutors Hourly Pay Rate in ascending order\n" << string(64, '=') << endl;
	cout << "Sorting Tutors by Hourly Pay Rate[Ascending]" << endl;

	if (head == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			//Node index will point to node next to current
			index = current->next;
			while (index != NULL) {
				//If current node's data is greater than index's node data, swap the data between them
				if (current->hourlyRate > index->hourlyRate) {
					id = current->id; current->id = index->id; index->id = id;
					name = current->name; current->name = index->name; index->name = name;
					dateJoined = current->dateJoined; current->dateJoined = index->dateJoined; index->dateJoined = dateJoined;
					dateTerminated = current->dateTerminated; current->dateTerminated = index->dateTerminated; index->dateTerminated = dateTerminated;
					hourlyRate = current->hourlyRate; current->hourlyRate = index->hourlyRate; index->hourlyRate = hourlyRate;
					address = current->address; current->address = index->address; index->address = address;
					tcCode = current->tcCode; current->tcCode = index->tcCode; index->tcCode = tcCode;
					tcName = current->tcName; current->tcName = index->tcName; index->tcName = tcName;
					subjectCode = current->subjectCode; current->subjectCode = index->subjectCode; index->subjectCode = subjectCode;
					subjectName = current->subjectName; current->subjectName = index->subjectName; index->subjectName = subjectName;
					rating = current->rating; current->rating = index->rating; index->rating = rating;

				}
				index = index->next;
			}
			current = current->next;
		}
	}
	displayTutor();
	cout << "\nReturning to Main Menu" << endl << endl;
	return;
}

//vii. Sort and display by Tutors Overall Performance in ascending order
void sortTutorRating() {
	//Node current will point to head
	Tutor* current = head;
	Tutor* index = NULL;
	
	int id;
	string name;
	string dateJoined;
	string dateTerminated;
	double hourlyRate;
	string phone;
	string address;
	string tcCode;
	string tcName;
	string subjectCode;
	string subjectName;
	double rating;

	cout << "\nSort and display by Tutors Overall Performance in ascending order\n" << string(68, '=') << endl;
	cout << "Sorting Tutors by Rating [Ascending]" << endl;

	if (head == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			//Node index will point to node next to current
			index = current->next;
			while (index != NULL) {
				//If current node's data is greater than index's node data, swap the data between them
				if (current->rating > index->rating) {
					id = current->id; current->id = index->id; index->id = id;
					name = current->name; current->name = index->name; index->name = name;
					dateJoined = current->dateJoined; current->dateJoined = index->dateJoined; index->dateJoined = dateJoined;
					dateTerminated = current->dateTerminated; current->dateTerminated = index->dateTerminated; index->dateTerminated = dateTerminated;
					hourlyRate = current->hourlyRate; current->hourlyRate = index->hourlyRate; index->hourlyRate = hourlyRate;
					address = current->address; current->address = index->address; index->address = address;
					tcCode = current->tcCode; current->tcCode = index->tcCode; index->tcCode = tcCode;
					tcName = current->tcName; current->tcName = index->tcName; index->tcName = tcName;
					subjectCode = current->subjectCode; current->subjectCode = index->subjectCode; index->subjectCode = subjectCode;
					subjectName = current->subjectName; current->subjectName = index->subjectName; index->subjectName = subjectName;
					rating = current->rating; current->rating = index->rating; index->rating = rating;

				}
				index = index->next;
			}
			current = current->next;
		}
	}
	displayTutor();
	cout << "\nReturning to Main Menu" << endl << endl;
	return;
}

//viii. Modify a Tutor Record
void modifyTutor() {
	Tutor* current = head;
	int inpID;
	bool found = false;
	int input;
	int id; string name; string dateJoined; string dateTerminated; double hourlyRate; string phone; string address; string tcCode; string tcName; string subjectCode; string subjectName; double rating;

	cout << "\nModify a Tutor Record\n" << string(24, '=') << endl;

	cout << "Enter Tutor ID : "; cin >> inpID;

	while (current != NULL) {
		if (current->id == inpID) {
			cout
				<< "Current Tutor Information\n" << string(26, '-')
				<< "\nTutor ID            : " << current->id
				<< "\nName                : " << current->name
				<< "\nDate Joined         : " << current->dateJoined
				<< "\nDate Terminated     : " << current->dateTerminated
				<< "\nHourly Rate         : " << current->hourlyRate
				<< "\nPhone               : " << current->phone
				<< "\nAddress             : " << current->address
				<< "\nTuition Centre Code : " << current->tcCode
				<< "\nTuition Centre Name : " << current->tcName
				<< "\nSubject Code        : " << current->subjectCode
				<< "\nSubject Name        : " << current->subjectName
				<< "\nRating              : " << current->rating
				<< endl << endl;
			found = true;
			break;
		}
		else if (current->id != inpID) {
			current = current->next;
		}
	}
	if (found) {
		cout << "New Tutor Information\n" << string(22, '-');
		cout << "\nTutor ID            : "; cin >> current->id;
		cout << "Name                : ";   cin >> current->name;
		cout << "Date Joined         : ";   cin >> current->dateJoined;      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Date Terminated     : ";   cin >> current->dateTerminated;	 cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Hourly Rate         : ";   cin >> current->hourlyRate;
		cout << "Phone               : ";   cin >> current->phone;
		cout << "Address             : ";   cin >> current->address;
		cout << "Tuition Centre Code : ";   cin >> current->tcCode;
		cout << "Tuition Centre Name : ";   cin >> current->tcName;
		cout << "Subject Code        : ";   cin >> current->subjectCode;
		cout << "Subject Name        : ";   cin >> current->subjectName;
		cout << "Rating              : ";   cin >> current->rating;

		cout << "Successfully Updated" << endl;
	}
	else {
		cout << "\nUnable to find tutor ID, press 1 to try again, or any to go back : ";
		cin >> input;
		if (input == 1) {
			modifyTutor();
		}
		else {
			cout << "\nReturning to Main Menu" << endl << endl;
			mainMenu();
		}
	}
	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}

//ix. Delete a Tutor Record
void deleteTutor() {
	Tutor* current = head;
	Tutor* previous = NULL;
	int inpID;
	bool found = false;
	int input;
	int id; string name; string dateJoined; string dateTerminated; double hourlyRate; string phone; string address; string tcCode; string tcName; string subjectCode; string subjectName; double rating;

	cout << "\nModify a Tutor Record\n" << string(24, '=') << endl;

	cout << "Enter Tutor ID : "; cin >> inpID;

	while (current != NULL) {
		if (current->id == inpID) {
			cout
				<< "Tutor Information\n" << string(26, '-')
				<< "\nTutor ID            : " << current->id
				<< "\nName                : " << current->name
				<< "\nDate Joined         : " << current->dateJoined
				<< "\nDate Terminated     : " << current->dateTerminated
				<< "\nHourly Rate         : " << current->hourlyRate
				<< "\nPhone               : " << current->phone
				<< "\nAddress             : " << current->address
				<< "\nTuition Centre Code : " << current->tcCode
				<< "\nTuition Centre Name : " << current->tcName
				<< "\nSubject Code        : " << current->subjectCode
				<< "\nSubject Name        : " << current->subjectName
				<< "\nRating              : " << current->rating
				<< endl << endl;
			found = true;

			cout << "Confirm deletion (1 for yes, any for no) : "; cin >> input;
			if (input == 1) {
				if (previous == NULL) {
					head = current->next;
					delete current;
					cout << "\nRecord Successfully Deleted";
					cout << "\nReturning to Main Menu" << endl << endl;
					mainMenu();
				}
				previous->next = current->next;
				delete current;
				cout << "\nReturning to Main Menu" << endl << endl;
				mainMenu();
			}
			else {
				cout << "\nDeletion Cancelled, Returning to Main Menu\n";
			}
			break;
		}
		else if (current->id != inpID) {
			previous = current;
			current = current->next;
		}
	}
	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}
