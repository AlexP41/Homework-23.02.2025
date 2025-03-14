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
#include <sstream>
#include <regex>
#include <unordered_map>


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


#pragma	region For Ex 2


bool isWord(string& word);

void putCertainWordsToAnotherFile(string& str, string& language, string& fileToPutIn, vector<string> bannedWords);

//                  Планував ще додати трекінг розділових знаків і потім у файл переписувати збережені знаки, 
//                  але занадто позно про це подумав, і це трохи довго і віжко реалізувати. Але думки способу реалізації є.

//string removePunctuationAndTrackPositions(const string& str, vector<pair<int, char>>& positions);
//
//string restorePunctuation(const string& cleanedStr, const vector<pair<int, char>>& positions);

#pragma	endregion

#pragma	region For Ex 3


string transliterateFromUkrToEn(const string& text);

string reverseTransliterateFromEnToUkr(const string& text);


#pragma	endregion

#pragma endregion


int main()
{

	system("chcp 1251>null");

#pragma region Exercise 1
//
//
//	/*
//	№1
//		У текстовий файл порядково записати прізвище, ім'я студента та його оцінку за екзамен.
//		Вивести на екран усіх студентів, чиї оцінки менші за бал, який введе користувач і порахувати середній бал по групі.
//	*/
//	vector <Student> studentsData;
//
//	string fileName = "Exercise1_Database_of_students.txt";
//
//	resetFile(fileName);
//
//	Student s1 = { "Петренко", "Іван", 88.5 };
//	Student s2 = { "Коваленко", "Олена", 94.0 };
//	Student s3 = { "Шевчук", "Михайло", 76.0 };
//
//	studentsData.push_back(s1);
//	studentsData.push_back(s2);
//	studentsData.push_back(s3);
//	
//
//	pushDataToFileExOne(s1, fileName);
//	pushDataToFileExOne(s2, fileName);
//	pushDataToFileExOne(s3, fileName);
//
//	int choice;
//	Student newStudent;
//
//	do {
//		cout << endl << "\033[36m========== МЕНЮ ==========" << endl;
//		cout << "1. Додати студентів у файл" << endl;
//		cout << "2. Вивести студентів з балами нижче заданого" << endl;
//		cout << "3. Порахувати середній бал групи" << endl;
//		cout << "4. Вийти\033[0m" << endl;
//
//		cout << endl << endl << "\t\t\033[043m   Введення   \033[0m" << endl;
//		while (true) {
//			cout << "Введіть ваш вибір: ";
//			cin >> choice;
//
//			if (cin.fail()) {
//				cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
//				cin.clear(); 
//				cin.ignore(1000, '\n');
//				continue;
//			}
//
//			if (choice < 1 || choice > 4) {
//				cout << "\033[031m Помилка! Будь ласка, введіть числа від 1 до 4 (включно).\033[0m\n";
//				continue;
//			}
//			
//			break;
//		}
//		/*cin.ignore();*/
//
//
//
//		switch (choice) {
//
//		case 1:
//			inputDataAboutStudentAndPush(newStudent, studentsData);
//			pushDataToFileExOne(newStudent, fileName);
//			cout << endl << endl << "\033[042mСтудента додано у файл!\033[0m" << endl << endl;
//			break;
//		case 2: {
//			double threshold;
//		
//			while (true) {
//				cout << "Введіть пороговий бал: ";
//	
//				cin >> threshold;
//
//				if (cin.fail()) {
//					cout << "\033[031m Помилка! Будь ласка, спробуйте ще раз.\033[0m\n";
//					cin.clear();
//					cin.ignore(1000, '\n');
//					continue;
//				}
//				if (threshold < 0 || threshold > 100) {
//					cout << "\033[031m Помилка! Поріг повинен бути у межах від 0 до 100 включно! Будь ласка, спробуйте ще раз.\033[0m\n";
//					continue;
//				}
//
//				break;
//			}
//
//			vector<Student> studentsToShow = showStudentsResults(threshold, false, studentsData);
//
//			if (!studentsToShow.empty())
//			{
//				cout << endl << endl << "\033[043mСтуденти, чиї оцінки менші за " << threshold << ".\033[0m" << endl << endl;
//				for (size_t i = 0; i < studentsToShow.size(); i++)
//				{
//					cout << "\033[035mСтудент №" << i+1 << ": \033[0m";
//					cout << studentsToShow[i].surname << " " << studentsToShow[i].name << " - " << studentsToShow[i].grade << endl;
//				}
//			}
//			else {
//				cout << endl << endl << "\033[033mСтуденти, чиї оцінки менші за " << threshold << " \033[031mне існує!\033[0m" << endl << endl;
//			}
//
//			
//			
//			break;
//		}
//		case 3: {
//			double ariphmeticMean = calcAverage(studentsData);
//			cout << endl << endl << "\033[042mСередній бал по групі: " << ariphmeticMean << ".\033[0m" << endl;
//			break;
//		}
//		case 4:
//			cout << endl << endl << "\033[043mВихід з програми.\033[0m" << endl;
//			break;
//		}
//
//	} while (choice != 4);
// 
//
#pragma endregion 


#pragma region Exercise 2


	/*
	№2
		Дано текстовий файл. Необхідно створити новий файл, прибравши з нього всі неприйнятні слова.
		Список неприйнятних слів знаходиться в іншому файлі.
	*/

	//string  FileNameExercise2 = "Exercise2-text-to-modify.txt";

	//string bannedWordsFile = "Exercise2-banned-words.txt";

	//// ----------------------------------------           File 2 reset        -------------------------------------------

	//vector<string> textForFileExerciseTwo = {
	//	"This is a simple sample text file. It contains some words that might be considered inappropriate or unwanted.",
	//	"Some people use bad words in their writing, but this file should be cleaned from all such words.",
	//	"Let's make this file clean and friendly."
	//};

	//resetFile(FileNameExercise2);
	//resetFile(bannedWordsFile);
	//
	//ofstream fileToAdd2(FileNameExercise2, ios::app);
	//if (!fileToAdd2)
	//{
	//	cout << "Файл не знайдено." << endl;
	//	return 1;
	//}

	//for (const string& newLineToAdd: textForFileExerciseTwo)
	//{
	//	fileToAdd2 << newLineToAdd << "\n";
	//}
	//fileToAdd2.close();

	//// -------------------------------------------------------------------------------------------------------------------

	//vector<string>userWordsToPutIntoAnotherFile;
	//vector<pair<int, char>> positions;

	//int numberOfWords;

	//cout << endl << endl << "\033[45m Введення кількості слів \033[0m" << endl << endl;

	//while (true) {
	//	cout << "Кількість слів для вводу: ";
	//	cin >> numberOfWords;

	//	if (cin.fail()) {
	//		cout << "\033[031m Помилка! Будь ласка, спробуйте ще раз.\033[0m\n";
	//		cin.clear();
	//		cin.ignore(1000, '\n');
	//		continue;
	//	}
	//	if (numberOfWords < 1)
	//	{
	//		cout << "\033[031m Помилка! Будь ласка, Введіть кількість слов більше за 1.\033[0m\n";
	//		continue;
	//	}

	//	break;
	//}

	//cout << endl << endl << "\033[45m Введення слів \033[0m" << endl << endl;
	//for (size_t i = 0; i < numberOfWords; i++)
	//{
	//	string word;
	//	cout << (i + 1) << ". ";
	//	cin >> word;
	//	userWordsToPutIntoAnotherFile.push_back(word);
	//}

	//

	//ifstream file2(FileNameExercise2, ios::in);
	//if (!file2)
	//{
	//	cout << "Файл не знайдено." << endl;
	//	return 1;
	//}

	//string current_line;
	//string languageMode = "en"; // Assume English for now

	//// Process each line of the file
	//while (getline(file2, current_line)) {
	//	putCertainWordsToAnotherFile(current_line, languageMode, bannedWordsFile, userWordsToPutIntoAnotherFile);
	//}

	//file2.close();

#pragma endregion 


#pragma region Exercise 3


	/*
	№3
		Написати програму транслітерації з української на англійську. Дані для транслітерації беруться з файлу і записуються в інший файл.
	*/

string ukranianDataFile = "Exercise3-ukranian-data.txt";

string englishDataFile = "Exercise3-english-data.txt";

string fileToPushDataIn = "Exercise3-push-data.txt";

ifstream file1(ukranianDataFile, ios::in);
ifstream file2(englishDataFile, ios::in);
ofstream file3(fileToPushDataIn, ios::out);

if (!file1 || !file2 || !file3) {
	cerr << "Помилка відкриття файлу!" << endl;
	return 1;
}

string current_line1, current_line2;
int userChoice;

while (true) {
	cout << endl;
	cout << "\033[033mМеню:\n";
	cout << "1. З української на англійську \n";
	cout << "2. З англійської на україніську\n";
	cout << "3. Вихід\033[0m\n";
	cout << endl;
	while (true)
	{
		cout << endl;
		cout << "Введіть ваш вибір: ";
		cin >> userChoice;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
			cin.clear(); 
			cin.ignore(1000, '\n'); 
			continue;
		}

		if (userChoice != 1 && userChoice != 2 && userChoice != 3)
		{
			cout << "\033[031m Помилка! Будь ласка, введіть число 1, 2 або 3.\033[0m\n";
			continue;
		}

		break;

	}


	switch (userChoice)
	{
	case 1: 
			cout << endl;
			while (getline(file1, current_line1)) {
				file3 << transliterateFromUkrToEn(current_line1) << endl;
			}
			cout << endl;
			cout << "Транслітерація з української мови на англійську завершена!\nРезультат взятий із файлу \033[035m" << ukranianDataFile << "\033[0m збережений у файл з ім'ям \033[038m" << fileToPushDataIn << "\033[0m" << endl;
			cout << endl;
			break;
		
	case 2:
			cout << endl;
			while (getline(file2, current_line2)) {
				file3 << reverseTransliterateFromEnToUkr(current_line2) << endl;
			}
			cout << endl;
			cout << "Транслітерація з англійської мови на українську завершена!\nРезультат взятий із файлу \033[035m" << englishDataFile << "\033[0m збережений у файл з ім'ям \033[038m" << fileToPushDataIn << "\033[0m" << endl;
			cout << endl;
			break;
		
	case 3:
			cout << endl;
			file1.close();
			file2.close();
			file3.close();
			cout << "Вихід...\n";
			break;
	default:
		break;
	}


}


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

	file1.close();
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
	file1.close();
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


bool isWord(string& word)
{
	if (word.length() == 1)
	{
		return isalpha(word[0]);
	}

	for (size_t i = 0; i < word.length(); i++)
	{
		if (i == 0 || i == word.length() - 1)
		{
			if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '-')
			{
				return false;
			}
		}
		else
		{
			if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '-')
			{
				return false;
			}
		}
	}

	return true;
}


//                  Планував ще додати трекінг розділових знаків і потім у файл переписувати збережені знаки, 
//                  але занадто позно про це подумав, і це трохи довго і віжко реалізувати. Але думки способу реалізації є.

//string removePunctuationAndTrackPositions(const string& str, vector<pair<int, char>>& positions) {
//	string cleanStr = str;
//	regex punctuation("[^a-zA-Z0-9]+"); // Задаємо регулярний вираз для видалення пунктуації
//
//	// Шукаємо і зберігаємо місця пунктуації
//	for (int i = 0; i < cleanStr.size(); i++) {
//		if (!isalnum(cleanStr[i])) {  // Якщо символ не є буквою чи цифрою
//			positions.push_back({ i, cleanStr[i] });  // Зберігаємо позицію і символ
//		}
//	}
//
//	// Видаляємо пунктуацію
//	cleanStr = regex_replace(cleanStr, punctuation, " ");
//	return cleanStr;
//}
//
//
//string restorePunctuation(const string& cleanedStr, const vector<pair<int, char>>& positions) {
//	string result = cleanedStr;
//	for (const auto& pos : positions) {
//		result.insert(pos.first, 1, pos.second);  // Вставляємо пунктуацію назад
//	}
//	return result;
//}

void putCertainWordsToAnotherFile(string& str, string& language, string& fileToPutIn, vector<string> bannedWords) {

	regex punctuation;

	// Регулярний вираз для української та англійської мови
	if (language == "ukr") {
		punctuation = regex("[^a-zA-ZА-Яа-яЄєІіЇїҐґ0-9'’-]+");
	}
	else if (language == "en") {
		punctuation = regex("[^a-zA-Z0-9'’-]+");
	}
	else {
		return;
	}

	str = regex_replace(str, punctuation, " ");



	stringstream sin(str);
	string currentWord;


	ofstream outFile(fileToPutIn, ios::app); 

	if (!outFile.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}

	while (sin >> currentWord) {
		currentWord = regex_replace(currentWord, regex("[^a-zA-Z0-9]+$"), "");

		if (isWord(currentWord) && find(bannedWords.begin(), bannedWords.end(), currentWord) == bannedWords.end()) {
			outFile << currentWord << " ";
		}
	}
	outFile << ".\n";

	outFile.close();
}


#pragma	endregion


#pragma	region Functions for Ex 3

string transliterateFromUkrToEn(const string& text) {
	unordered_map<char, string> translit = {
		{'А', "A"}, {'Б', "B"}, {'В', "V"}, {'Г', "H"}, {'Ґ', "G"}, {'Д', "D"}, {'Е', "E"}, {'Є', "Ye"},
		{'Ж', "Zh"}, {'З', "Z"}, {'И', "Y"}, {'І', "I"}, {'Ї', "Yi"}, {'Й', "Y"}, {'К', "K"}, {'Л', "L"},
		{'М', "M"}, {'Н', "N"}, {'О', "O"}, {'П', "P"}, {'Р', "R"}, {'С', "S"}, {'Т', "T"}, {'У', "U"},
		{'Ф', "F"}, {'Х', "Kh"}, {'Ц', "Ts"}, {'Ч', "Ch"}, {'Ш', "Sh"}, {'Щ', "Shch"}, {'Ь', ""}, {'Ю', "Yu"}, {'Я', "Ya"},
		{'а', "a"}, {'б', "b"}, {'в', "v"}, {'г', "h"}, {'ґ', "g"}, {'д', "d"}, {'е', "e"}, {'є', "ie"},
		{'ж', "zh"}, {'з', "z"}, {'и', "y"}, {'і', "i"}, {'ї', "i"}, {'й', "i"}, {'к', "k"}, {'л', "l"},
		{'м', "m"}, {'н', "n"}, {'о', "o"}, {'п', "p"}, {'р', "r"}, {'с', "s"}, {'т', "t"}, {'у', "u"},
		{'ф', "f"}, {'х', "kh"}, {'ц', "ts"}, {'ч', "ch"}, {'ш', "sh"}, {'щ', "shch"}, {'ь', ""}, {'ю', "iu"}, {'я', "ia"}
	};

	string result;
	for (char c : text) {
		if (translit.count(c)) {
			result += translit[c];
		}
		else {
			result += c;
		}
	}
	return result;
}


string reverseTransliterateFromEnToUkr(const string& text) {
	unordered_map<string, char> reverseTranslit = {
		{"A", 'А'}, {"B", 'Б'}, {"V", 'В'}, {"H", 'Г'}, {"G", 'Ґ'}, {"D", 'Д'}, {"E", 'Е'}, {"Ye", 'Є'},
		{"Zh", 'Ж'}, {"Z", 'З'}, {"Y", 'И'}, {"I", 'І'}, {"Yi", 'Ї'}, {"K", 'К'}, {"L", 'Л'},
		{"M", 'М'}, {"N", 'Н'}, {"O", 'О'}, {"P", 'П'}, {"R", 'Р'}, {"S", 'С'}, {"T", 'Т'}, {"U", 'У'},
		{"F", 'Ф'}, {"Kh", 'Х'}, {"Ts", 'Ц'}, {"Ch", 'Ч'}, {"Sh", 'Ш'}, {"Shch", 'Щ'}, {"Yu", 'Ю'}, {"Ya", 'Я'},
		{"a", 'а'}, {"b", 'б'}, {"v", 'в'}, {"h", 'г'}, {"g", 'ґ'}, {"d", 'д'}, {"e", 'е'}, {"ie", 'є'},
		{"zh", 'ж'}, {"z", 'з'}, {"y", 'и'}, {"i", 'і'}, {"i", 'ї'}, {"k", 'к'}, {"l", 'л'},
		{"m", 'м'}, {"n", 'н'}, {"o", 'о'}, {"p", 'п'}, {"r", 'р'}, {"s", 'с'}, {"t", 'т'}, {"u", 'у'},
		{"f", 'ф'}, {"kh", 'х'}, {"ts", 'ц'}, {"ch", 'ч'}, {"sh", 'ш'}, {"shch", 'щ'}, {"iu", 'ю'}, {"ia", 'я'}
	};

	string result, temp;
	for (size_t i = 0; i < text.size(); ++i) {
		temp += text[i];

		if (i + 1 < text.size()) {
			temp += text[i + 1];
		}

		if (reverseTranslit.count(temp)) {
			result += reverseTranslit[temp];
			if (temp.size() == 2) i++;
			temp.clear();
		}
		else if (reverseTranslit.count(string(1, text[i]))) {
			result += reverseTranslit[string(1, text[i])];
			temp.clear();
		}
		else if (temp.size() == 2) {
			result += temp[0];
			temp.erase(0, 1);
		}
	}
	result += temp;
	return result;
}


#pragma	endregion


#pragma endregion

