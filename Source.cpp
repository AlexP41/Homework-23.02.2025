/*
РОБОТА З ФАЙЛАМИ
================

Результат роботи: посилання на GitHub
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdarg>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>


using namespace std;


typedef struct {

	string surname;
	string name;
	double grade;

} Student;


#pragma region Functions prototypes 

#pragma	region For Ex 1

void inputDataAboutStudentAndPush(Student& infoAboutStudent, vector <Student>& dataToPushWhere);

void pushDataToFileExOne(Student& infoAboutStudent, string& fileName);

void resetFile(string& fileName);

vector<Student> showStudentsResults(double& threshold, bool showBiggerGradesThanThreshold, vector <Student>& dataOfStudents);

double calcAverage(vector<Student>& students);

void trim(string& str);

#pragma	endregion


#pragma	region For Ex 1
#pragma	endregion

#pragma	region For Ex 1
#pragma	endregion

#pragma endregion


int main()
{

	system("chcp 1251>null");

#pragma region Exercise 1


	/*
	№1
		У текстовий файл порядково записати прізвище, ім'я студента та його оцінку за екзамен.
		Вивести на екран усіх студентів, чиї оцінки менші за бал, який введе користувач і порахувати середній бал по групі.
	*/
	vector <Student> studentsData;

	string fileName = "Exercise1_Database_of_students.txt";

	resetFile(fileName);

	Student s1 = { "Петренко", "Іван", 88.5 };
	Student s2 = { "Коваленко", "Олена", 94.0 };
	Student s3 = { "Шевчук", "Михайло", 76.0 };

	studentsData.push_back(s1);
	studentsData.push_back(s2);
	studentsData.push_back(s3);
	

	pushDataToFileExOne(s1, fileName);
	pushDataToFileExOne(s2, fileName);
	pushDataToFileExOne(s3, fileName);

	int choice;
	Student newStudent;

	do {
		cout << endl << "\033[36m========== МЕНЮ ==========" << endl;
		cout << "1. Додати студентів у файл" << endl;
		cout << "2. Вивести студентів з балами нижче заданого" << endl;
		cout << "3. Порахувати середній бал групи" << endl;
		cout << "4. Вийти\033[0m" << endl;

		cout << endl << endl << "\t\t\033[043m   Введення   \033[0m" << endl;
		while (true) {
			cout << "Введіть ваш вибір: ";
			cin >> choice;

			if (cin.fail()) {
				cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
				cin.clear(); 
				cin.ignore(1000, '\n');
				continue;
			}

			if (choice < 1 || choice > 4) {
				cout << "\033[031m Помилка! Будь ласка, введіть числа від 1 до 4 (включно).\033[0m\n";
				continue;
			}
			
			break;
		}
		/*cin.ignore();*/



		switch (choice) {

		case 1:
			inputDataAboutStudentAndPush(newStudent, studentsData);
			pushDataToFileExOne(newStudent, fileName);
			cout << endl << endl << "\033[042mСтудента додано у файл!\033[0m" << endl << endl;
			break;
		case 2: {
			double threshold;
		
			while (true) {
				cout << "Введіть пороговий бал: ";
	
				cin >> threshold;

				if (cin.fail()) {
					cout << "\033[031m Помилка! Будь ласка, спробуйте ще раз.\033[0m\n";
					cin.clear();
					cin.ignore(1000, '\n');
					continue;
				}
				if (threshold < 0 || threshold > 100) {
					cout << "\033[031m Помилка! Поріг повинен бути у межах від 0 до 100 включно! Будь ласка, спробуйте ще раз.\033[0m\n";
					continue;
				}

				break;
			}

			vector<Student> studentsToShow = showStudentsResults(threshold, false, studentsData);

			if (!studentsToShow.empty())
			{
				cout << endl << endl << "\033[043mСтуденти, чиї оцінки менші за " << threshold << ".\033[0m" << endl << endl;
				for (size_t i = 0; i < studentsToShow.size(); i++)
				{
					cout << "\033[035mСтудент №" << i+1 << ": \033[0m";
					cout << studentsToShow[i].surname << " " << studentsToShow[i].name << " - " << studentsToShow[i].grade << endl;
				}
			}
			else {
				cout << endl << endl << "\033[033mСтуденти, чиї оцінки менші за " << threshold << " \033[031mне існує!\033[0m" << endl << endl;
			}

			
			
			break;
		}
		case 3: {
			double ariphmeticMean = calcAverage(studentsData);
			cout << endl << endl << "\033[042mСередній бал по групі: " << ariphmeticMean << ".\033[0m" << endl;
			break;
		}
		case 4:
			cout << endl << endl << "\033[043mВихід з програми.\033[0m" << endl;
			break;
		}

	} while (choice != 4);


#pragma endregion 


#pragma region Exercise 2


	/*
	№2
		Дано текстовий файл. Необхідно створити новий файл, прибравши з нього всі неприйнятні слова.
		Список неприйнятних слів знаходиться в іншому файлі.
	*/


#pragma endregion 


#pragma region Exercise 3


	/*
	№3
		Написати програму транслітерації з української на англійську. Дані для транслітерації беруться з файлу і записуються в інший файл.
	*/


#pragma endregion 

	return 0;
}


#pragma region Functions Region


#pragma	region Functions for Ex 1

// Функція для видалення пробілів на початку та кінці рядка
void trim(string& str) {
	// Видаляємо пробіли з початку рядка
	str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !isspace(ch);
		}));

	// Видаляємо пробіли з кінця рядка
	str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !isspace(ch);
		}).base(), str.end());
}


// Функція для капіталізації першої літери та приведення решти до малих літер
void capitalize(string& str) {
	if (!str.empty()) {
		// Створення локалі для правильного оброблення українських символів
		locale loc("");

		// Перша літера - велика
		str[0] = toupper(str[0], loc);

		// Інші літери - малі
		for (size_t i = 1; i < str.length(); ++i) {
			str[i] = tolower(str[i], loc);
		}
	}
}


void inputDataAboutStudentAndPush(Student& infoAboutStudent, vector<Student>& dataToPushWhere) {
	string Surname, Name;
	double Grade;

	cout << endl << endl << "\t\t\t\033[033mВведення даних про студента: \033[0m" << endl << endl;
	while (true) {
		cout << "Введіть прізвище: ";
		cin >> Surname;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, спробуйте ще раз.\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n');
			continue;
		}

		break;
	}

	while (true) {
		cout << "Введіть Ім'я: ";
		cin >> Name;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, спробуйте ще раз.\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n'); 
			continue;
		}

		break;
	}

	while (true) {
		cout << "Введіть оцінку за екзамен: ";
		cin >> Grade;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, спробуйте ще раз.\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n'); 
			continue;
		}

		if (Grade < 0 || Grade > 100) {
			cout << "\033[031m Помилка! Оцінка повинна бути у межах від 0 до 100 включно! Будь ласка, спробуйте ще раз.\033[0m\n";
			continue;
		}

		break;
	}

	trim(Surname);
	trim(Name);

	capitalize(Surname);
	capitalize(Name);

	cout << endl << "\033[045mСтудент: " << Surname << " " << Name << " з оцінкою: " << Grade << "\033[0m" << endl;


	infoAboutStudent = {Surname, Name, Grade};
	dataToPushWhere.push_back(infoAboutStudent);
}


void pushDataToFileExOne(Student& infoAboutStudent, string& fileName)
{
	ofstream file1(fileName, ios::app);

	if (!file1)
	{
		cout << "Файл не знайдено." << endl;
		return;
	}

	file1 << infoAboutStudent.surname << "  "
		  << infoAboutStudent.name << " - " 
		  << infoAboutStudent.grade << endl;
}


void resetFile(string& fileName)
{
	ofstream file1(fileName, ios::out);

	if (!file1)
	{
		cout << "Файл не знайдено." << endl;
		return;
	}

	file1 << "";
}


vector<Student> showStudentsResults(double& threshold, bool showBiggerGradesThanThreshold, vector <Student>& dataOfStudents)
{
	vector<Student> studentsToShow;

	for (const Student& student: dataOfStudents)
	{
		showBiggerGradesThanThreshold ? 
			(student.grade > threshold ? studentsToShow.push_back(student) : void()) :
			(student.grade < threshold ? studentsToShow.push_back(student) : void());
	}

	return studentsToShow;
}


double calcAverage(vector<Student>& students) {
	double sum = 0;

	for (const Student& student : students)
	{
		sum += student.grade;
	}

	return sum / students.size();
}

#pragma	endregion

#pragma	region Functions for Ex 2
#pragma	endregion

#pragma	region Functions for Ex 3
#pragma	endregion

#pragma endregion