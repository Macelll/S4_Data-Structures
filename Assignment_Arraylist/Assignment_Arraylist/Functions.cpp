#include "Source.h"
#include "Functions.h"


string userPass = "123";
int insertingIndex = 0;

struct Tutor allTutor[100];

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

	struct Tutor tutor;

	tutor = { 11, "Marsha and the Bear", "13 October 2001",
		"18 April 2022", 40, "01169696969", "Parkhill Residensi",
		"A01", "Ampang", "MT", "Math", 2 };
	insertTutor(tutor);

	tutor = {2, "Macel", "13 October 2001",
		"18 January 2022", 40, "123456789", "Parkhill Residensi",
		"A01", "Ampang", "MT", "Math", 1};
	insertTutor(tutor);

	tutor = {1, "Ros The Conqueror", "13 October 2001",
		"18 October 2022", 3, "987654321", "Parkhill Residensi",
		"C01", "Cheras", "ENG", "English", 5};
	insertTutor(tutor);

	tutor = {3, "Modi Cumberbatch", "13 October 2001",
		"18 October 2022", 10, "01169696969", "Parkhill Residensi",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.3};
	insertTutor(tutor);

	tutor = {4, "Celin Teydayy", "13 October 2001",
		"18 April 2022", 69.6, "123123123", "Endah Promenade",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.5};
	insertTutor(tutor);

	tutor = {5, "Mingsen Wahyudi", "13 January 2001",
		"18 February 2021", 21, "222222222", "APU Apartment",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4};
	insertTutor(tutor);

	tutor = {6, "Leon Amos", "13 February 2003",
		"18 June 2022", 53, "333333333", "Pavilion",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.5};
	insertTutor(tutor);

	tutor = {8, "Jeffrey Agung", "13 March 2006",
		"18 January 2022", 40, "01169696969", "APU Apartment",
		"A01", "Ampang", "MT", "Math", 0.1};
	insertTutor(tutor);

	tutor = {7, "Ching", "13 April 2002",
		"18 May 2022", 78, "01169696969", "Pinnacle",
		"C01", "Cheras", "ENG", "English", 5};
	insertTutor(tutor);

	tutor = {9, "Johnie Depp", "13 May 2011",
		"18 April 2022", 99, "01169696969", "Parkhill Residensi",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 4.9};
	insertTutor(tutor);

	tutor = {10, "Superman", "13 June 2012",
		"18 May 2022", 10000, "01169696969", "Parkhill Residensi",
		"C01", "Asia Pacific University", "ENG", "Computer Science", 3.4};
	insertTutor(tutor);
}

void mainMenu() {

	cout << "\nMain Menu" << endl << string(10, '=') << endl;
	int opt = 69;

	while (opt < 0 || opt > 9) {
		cout <<
			"\n0. To Exit Program\n" <<
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
		cout << "Thank You~";
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

void insertTutor(struct Tutor tutor) { //Insert where there are space in arraylist
	::allTutor[::insertingIndex] = tutor;
	::insertingIndex++;
}

//i.Add a Tutor Record;
void inputTutor() {

	int id; string name; string dateJoined; string dateTerminated; double hourlyRate; string phone; string address; string tcCode; string tcName; string subjectCode; string subjectName; double rating;

	cout << "\nAdd Tutor Record\n" << string(18, '=') << endl;

	cout << "Tutor ID            : "; cin >> id;					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Name                : "; getline(cin,name);
	cout << "Date Joined         : "; getline(cin,dateJoined);	   
	cout << "Date Terminated     : "; getline(cin,dateTerminated);
	cout << "Hourly Rate         : "; cin >> hourlyRate;
	cout << "Phone               : "; cin >> phone;					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Address             : "; getline(cin, address);
	cout << "Tuition Centre Code : "; cin >> tcCode;
	cout << "Tuition Centre Name : "; cin >> tcName;
	cout << "Subject Code        : "; cin >> subjectCode;
	cout << "Subject Name        : "; cin >> subjectName;
	cout << "Rating              : "; cin >> rating;
	cout << endl << endl;

	struct Tutor tutor = { id, name, dateJoined, dateTerminated, hourlyRate, phone, address, tcCode, tcName, subjectCode, subjectName, rating };
	insertTutor(tutor);

	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}

//ii.Display All Records
void displayTutor() {
	cout << "\nDisplaying All Tutors~\n" << string(22, '-') << endl;
	int count = 1;
	int confirm = 1;
	int i = 0;

	while (true) {
		if (confirm == 1 || confirm == 2) {
			if (confirm == 2) {
				i -= 10;
				count -= 10;
			}
			for (int j = 0; j < 5; j++) {
				cout
					<< "[" << count << "]"
					<< "\nTutor ID            : " << ::allTutor[i].id
					<< "\nName                : " << ::allTutor[i].name
					<< "\nDate Joined         : " << ::allTutor[i].dateJoined
					<< "\nDate Terminated     : " << ::allTutor[i].dateTerminated
					<< "\nHourly Rate         : " << ::allTutor[i].hourlyRate
					<< "\nPhone               : " << ::allTutor[i].phone
					<< "\nAddress             : " << ::allTutor[i].address
					<< "\nTuition Centre Code : " << ::allTutor[i].tcCode
					<< "\nTuition Centre Name : " << ::allTutor[i].tcName
					<< "\nSubject Code        : " << ::allTutor[i].subjectCode
					<< "\nSubject Name        : " << ::allTutor[i].subjectName
					<< "\nRating              : " << ::allTutor[i].rating
					<< endl << endl;
				i++;
				count++;
			}
			cout << string(61, '~') << "\n'1' = Next Page | '2' = Previous Page | 'any' = End Function: ";
			cin >> confirm;
			cout << endl << endl;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
			}
		}
		else {
		cout << string(61, '~') << "\n\n'1' = Next Page | '2' = Previous Page | 'any' = End Function: ";
		cin >> confirm;
		}
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
	int id;
	bool found = false;
	int input;

	cout << "\nSearch a Tutor by Tutor ID\n" << string(29, '=') << endl;

	cout << "Enter Tutor ID : "; cin >> id;

	for (int i = 0; ::allTutor[i].id != 0; i++) {
		if (::allTutor[i].id == id) {
			cout
				<<   "Tutor ID            : " << allTutor[i].id
				<< "\nName                : " << allTutor[i].name
				<< "\nDate Joined         : " << allTutor[i].dateJoined
				<< "\nDate Terminated     : " << allTutor[i].dateTerminated
				<< "\nHourly Rate         : " << allTutor[i].hourlyRate
				<< "\nPhone               : " << allTutor[i].phone
				<< "\nAddress             : " << allTutor[i].address
				<< "\nTuition Centre Code : " << allTutor[i].tcCode
				<< "\nTuition Centre Name : " << allTutor[i].tcName
				<< "\nSubject Code        : " << allTutor[i].subjectCode
				<< "\nSubject Name        : " << allTutor[i].subjectName
				<< "\nRating              : " << allTutor[i].rating
				<< endl << endl;
			found = true;
			break;
		}
	}
	if (found == false) {
		cout << "Unable to find tutor ID, press 1 to try again, or any to go back : ";
		cin >> input;
		if (input == 1) {
			searchTutorID();
		}
		else {
			mainMenu();
		}
	}
	else if (found == true) {
		cout << "Tutor Found, Returning to Main Menu" << endl << endl;
		mainMenu();
	}
}

//iv. Search Tutors by overall performance (Rating)
void searchTutorRating() {
	bool found = false;
	int rating;
	int input;

	cout << "\nSearch a Tutor by Tutor Rating\n" << string(29, '=') << endl;

	cout << "Enter Tutor Rating : "; cin >> rating;

	for (int i = 0; ::allTutor[i].id != 0; i++) {
		if (::allTutor[i].rating == rating) {
			cout
				<< "\nTutor ID            : " << allTutor[i].id
				<< "\nName                : " << allTutor[i].name
				<< "\nDate Joined         : " << allTutor[i].dateJoined
				<< "\nDate Terminated     : " << allTutor[i].dateTerminated
				<< "\nHourly Rate         : " << allTutor[i].hourlyRate
				<< "\nPhone               : " << allTutor[i].phone
				<< "\nAddress             : " << allTutor[i].address
				<< "\nTuition Centre Code : " << allTutor[i].tcCode
				<< "\nTuition Centre Name : " << allTutor[i].tcName
				<< "\nSubject Code        : " << allTutor[i].subjectCode
				<< "\nSubject Name        : " << allTutor[i].subjectName
				<< "\nRating              : " << allTutor[i].rating
				<< endl;
			found = true;
		}
	}
	if (found == false) {
		cout << "Unable to find tutor ID, press 1 to try again, or any to go back : ";
		cin >> input;
		if (input == 1) {
			searchTutorRating();
		}
		else {
			mainMenu();
		}
	}
	else if (found == true) {
		cout << "\nTutor Found, Returning to Main Menu~" << endl;
		mainMenu();
	}
}

//v. Sort and display by Tutors ID in ascending order
void sortTutorID() {
	struct Tutor temp;

	cout << "\nSort and display by Tutors ID in ascending order\n" << string(50, '=') << endl;
	cout << "Sorting Tutors by Tutor ID[Ascending]" << endl;

	for (int i = 0; i < ::insertingIndex; i++) {
		for (int j = i; j < ::insertingIndex - 1; j++) {
			if (::allTutor[i].id > ::allTutor[j + 1].id) {
				temp = ::allTutor[j + 1];
				::allTutor[j + 1] = ::allTutor[i];
				::allTutor[i] = temp;
			}
		}
	}
	displayTutor();
	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}

//vi. Sort and display by Tutors Hourly Pay Rate in ascending order
void sortTutorPay() {
	struct Tutor temp;

	cout << "\nSort and display by Tutors Hourly Pay Rate in ascending order\n" << string(64, '=') << endl;
	cout << "Sorting Tutors by Hourly Pay Rate[Ascending]" << endl;

	for (int i = 0; i < ::insertingIndex; i++) {
		for (int j = i; j < ::insertingIndex - 1; j++) {
			if (::allTutor[i].hourlyRate > ::allTutor[j + 1].hourlyRate) {
				temp = ::allTutor[j + 1];
				::allTutor[j + 1] = ::allTutor[i];
				::allTutor[i] = temp;
			}
		}
	}
	displayTutor();
	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}

//vii. Sort and display by Tutors Overall Performance in ascending order
void sortTutorRating() {
	struct Tutor temp;

	cout << "\nSort and display by Tutors Overall Performance in ascending order\n" << string(68, '=') << endl;
	cout << "Sorting Tutors by Rating [Ascending]" << endl;

	for (int i = 0; i < ::insertingIndex; i++) {
		for (int j = i; j < ::insertingIndex - 1; j++) {
			if (::allTutor[i].rating > ::allTutor[j + 1].rating) {
				temp = ::allTutor[j + 1];
				::allTutor[j + 1] = ::allTutor[i];
				::allTutor[i] = temp;
			}
		}
	}
	displayTutor();
	cout << "\nReturning to Main Menu" << endl << endl;
	return;
}

//viii. Modify a Tutor Record
void modifyTutor() {
	int inpID, input, i;
	bool found = false;

	cout << "\nModify a Tutor Record\n" << string(24, '=') << endl;
	cout << "Enter Tutor ID : "; cin >> inpID;

	for (i = 0; i < ::insertingIndex; i++) {
		if (::allTutor[i].id == inpID) {
			cout
				<< "\nCurrent Tutor Information\n" << string(26, '-')
				<< "\nTutor ID            : " << allTutor[i].id
				<< "\nName                : " << allTutor[i].name
				<< "\nDate Joined         : " << allTutor[i].dateJoined
				<< "\nDate Terminated     : " << allTutor[i].dateTerminated
				<< "\nHourly Rate         : " << allTutor[i].hourlyRate
				<< "\nPhone               : " << allTutor[i].phone
				<< "\nAddress             : " << allTutor[i].address
				<< "\nTuition Centre Code : " << allTutor[i].tcCode
				<< "\nTuition Centre Name : " << allTutor[i].tcName
				<< "\nSubject Code        : " << allTutor[i].subjectCode
				<< "\nSubject Name        : " << allTutor[i].subjectName
				<< "\nRating              : " << allTutor[i].rating
				<< endl << endl;
			found = true;
			break;
		}
	}
	if (found) {
		/*cout << "New Tutor Information\n" << string(22, '-');
		cout << "\nTutor ID            : "; cin >> allTutor[i].id;
		cout << "Name                : ";   cin >> allTutor[i].name;
		cout << "Date Joined         : ";   cin >> allTutor[i].dateJoined;			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Date Terminated     : ";   cin >> allTutor[i].dateTerminated;		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Hourly Rate         : ";   cin >> allTutor[i].hourlyRate;*/
		cout << "Phone               : ";   cin >> allTutor[i].phone;				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Address             : ";   getline(cin, allTutor[i].address);
		/*cout << "Tuition Centre Code : ";   cin >> allTutor[i].tcCode;
		cout << "Tuition Centre Name : ";   cin >> allTutor[i].tcName;
		cout << "Subject Code        : ";   cin >> allTutor[i].subjectCode;
		cout << "Subject Name        : ";   cin >> allTutor[i].subjectName;
		cout << "Rating              : ";   cin >> allTutor[i].rating;*/

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

	int inpID, input, i;
	bool found = false;
	struct Tutor temp;

	cout << "\nDelete a Tutor Record\n" << string(24, '=') << endl;

	cout << "Enter Tutor ID : "; cin >> inpID;

	for (i = 0; i < ::insertingIndex; i++) {
		if (::allTutor[i].id == inpID) {
			cout
				<< "\nTutor Information\n" << string(26, '-')
				<< "\nTutor ID            : " << allTutor[i].id
				<< "\nName                : " << allTutor[i].name
				<< "\nDate Joined         : " << allTutor[i].dateJoined
				<< "\nDate Terminated     : " << allTutor[i].dateTerminated
				<< "\nHourly Rate         : " << allTutor[i].hourlyRate
				<< "\nPhone               : " << allTutor[i].phone
				<< "\nAddress             : " << allTutor[i].address
				<< "\nTuition Centre Code : " << allTutor[i].tcCode
				<< "\nTuition Centre Name : " << allTutor[i].tcName
				<< "\nSubject Code        : " << allTutor[i].subjectCode
				<< "\nSubject Name        : " << allTutor[i].subjectName
				<< "\nRating              : " << allTutor[i].rating
				<< endl << endl;
			found = true;

			cout << "Confirm deletion (1 for yes, any number for no) : "; cin >> input;
			if (input == 1) {
				while (::allTutor[i + 1].id != 0) {
					::allTutor[i] = ::allTutor[i + 1];
					i++;
				}
				::insertingIndex--;
				cout << "\n*Record Successfully Deleted*";
				cout << "\n\nReturning to Main Menu" << endl << endl;
				mainMenu();
			}
			else {
				cout << "\nDeletion Cancelled, Returning to Main Menu\n";
			}
			break;
		}
	}
	cout << "\nReturning to Main Menu" << endl << endl;
	mainMenu();
}