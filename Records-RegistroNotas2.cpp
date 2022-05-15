#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#define STUDENTS 20

using namespace std;

struct studentType
{
	string first_name;
	string last_name;
	int testscore1, testscore2, testscore3;
	char grade;
	double average;

}student[STUDENTS];

void readFile();
void calculateGrade(studentType arr[]);
void printEstudiantes(studentType arr[]);
int highestScore(studentType arr[]);
void printHighestScoreNames(int score, studentType arr[]);
void createFile(int score, studentType arr[]);

int main()
{
	readFile();
	calculateGrade(student);
	printEstudiantes(student);
	printHighestScoreNames(highestScore(student), student);

	//Creates output file
	createFile(highestScore(student), student);

	return 0;
}

void readFile()
{
	ifstream inFile;

	inFile.open("students.txt");

	for (int i = 0; i < STUDENTS; i++)
		inFile >> student[i].first_name
		>> student[i].last_name
		>> student[i].testscore1
		>> student[i].testscore2
		>> student[i].testscore3;
}

void printEstudiantes(studentType arr[])
{
	int lenght = 55;
	string fullname;
	//Header
	cout << "Student Name" << fixed << setw(28) << "Test Score" << fixed << setw(15) << "Grade" << endl;

	for (int i = 0; i <= lenght; i++)
		cout << "-";

	cout << endl;

	//Prints name of students and its scores
	for (int i = 0; i < STUDENTS; i++)
	{
		fullname = arr[i].last_name + ", " + arr[i].first_name;
		cout << left << setw(31) << fullname;
		cout << arr[i].testscore1 << " " << arr[i].testscore2 << " " << setw(15) << arr[i].testscore3;
		cout << arr[i].grade;
		cout << endl;

	}
	for (int i = 0; i <= lenght; i++)
		cout << "-";
}

void calculateGrade(studentType arr[])
{	
	for (int i = 0; i < STUDENTS; i++)
	{
		arr[i].average = (arr[i].testscore1 + arr[i].testscore2 + arr[i].testscore3) / 3;
		
		if (arr[i].average >= 90)
			arr[i].grade = 'A';
		else if (arr[i].average >= 80)
			arr[i].grade = 'B';
		else if (arr[i].average >= 70)
			arr[i].grade = 'C';
		else if (arr[i].average >= 60)
			arr[i].grade = 'D';
		else
			arr[i].grade = 'F';
	}
}

int highestScore(studentType arr[])
{
	int r = 0;

	for (int i = 0; i < STUDENTS; i++)
	{
		if (arr[i].average > r)
			r = arr[i].average;
	}

	return r;
}

void printHighestScoreNames(int score, studentType arr[])
{
	cout << endl;
	cout << "Highest average test score: " << score << endl;
	cout << "Student with the highest average test score:" << endl;
	for (int i = 0; i < STUDENTS; i++)
	{
		if (arr[i].average == score)
			cout << arr[i].average << ", " << arr[i].first_name << endl;
	}
}
void createFile(int score, studentType arr[])
{
	ofstream outfile("students_output.txt");
	string fullname;

	outfile << "Student Name" << fixed << setw(28) << "Test Score" << fixed << setw(15) << "Grade" << endl;

	for (int i = 0; i < STUDENTS; i++)
	{
		//List of students
		for (int i = 0; i < STUDENTS; i++)
		{
			fullname = arr[i].last_name + ", " + arr[i].first_name;
			outfile << left << setw(31) << fullname;
			outfile << arr[i].testscore1 << " " << arr[i].testscore2 << " " << setw(15) << arr[i].testscore3;
			outfile << arr[i].grade;
			outfile << endl;

		}

		//Prints highest score
		outfile << endl;
		outfile << "Highest average test score: " << score << endl;
		outfile << "Student with the highest average test score:" << endl;
		for (int i = 0; i < STUDENTS; i++)
		{
			if (arr[i].average == score)
				outfile << arr[i].last_name << ", " << arr[i].first_name << endl;
		}

		outfile.close();
	}
}
