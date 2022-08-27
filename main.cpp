// Mila Kuang COMP-200

#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>
using namespace std;

struct Student{
	string firstName;
	string lastName;
	string courseGrade;
	double quizScores[10];
};

int main()
{
	string temp, userInput, grade[5] = {"A","B","C","D","F"};
	int pos,pos2;
	vector<Student*> studentList;

	do {
		cout << "Enter q to quit or any character to continue.\n";
		cin >> userInput; //takes in input to determine whether or not to continue
		if (userInput == "q") {
			break; //breaks out of loop if input is q
		}
		cin.ignore(); //helps with the getline
		Student* current = new Student; //creates a new Student pointer and calls it current.

		cout << "Please enter their first name, last name, and course grade in this format: Jane Doe\n";
		getline(cin,temp);

		pos = temp.find(" "); //finds the first instance of a space
		current->firstName = temp.substr(0,0+pos); //sets the firstName variable in our struct to the first word in the string of temp.
		pos2 = temp.find(" ",pos+1); //finds the second instance of a space
		current->lastName = temp.substr((pos+1),((pos2-1) - pos)); //sets the lastName variable in our struct to the second word in the string of temp.
		
		double sum=0, score;
		for (int i = 0;i < 10;i++) { //Gets all 10 quiz scores.
			cout << "Quiz " << i+1 << " Grade: ";
			cin >> score;
			current->quizScores[i] = score; //Saves it to their struct.
			sum += score; //Gets the sum for evaluation.
		}

		if (sum >= 90) { //Assigns courseGrades.
			current->courseGrade = "A";
		}
		else if (sum >= 80) {
			current->courseGrade = "B";
		}
		else if (sum >= 70) {
			current->courseGrade = "C";
		}
		else if (sum >= 60) {
			current->courseGrade = "D";
		}
		else {
			current->courseGrade = "F";
		}

		studentList.push_back(current); //adds the Student pointer we made to the vector of Student pointers.
	} while (userInput != "q");

	for (int i = 0;i < 5;i++) { //Checks every grade array.
		cout << "\nPrinting all the students with an " << grade[i] << endl;
		for (int j = 0;j < studentList.size();j++) { //Checks every vector Student pointer.
			if (studentList.at(j)->courseGrade == grade[i]) { //If the Student has the same courseGrade as the grade we are testing from the array,
				cout << studentList.at(i)->firstName << " " << studentList.at(i)->lastName << endl; //then we print it out
			}
		}
	}
}
