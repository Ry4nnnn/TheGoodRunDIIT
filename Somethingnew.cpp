#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits.h>
#include <iomanip> //for setw()

using namespace	std;

//----------COLOURS----------//
//preset of color codes
# define RESET		"\033[0m"
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"

//a struct/template to store each player's data
struct player {
	string		name;
	string		idNum;
	string		feeType;
	string		contactNum;
	int			age;
	int			category;
	int			familyMember;
	double		fee;
};

//function to check if input is Number
//return true if input is a num else return false
bool isNum(string &input)
{
	int i = 0;
	if (input.empty())
		return (false);
	while (input[i] != '\0')
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

//function that takes in a string and converting it to uppercase
//also have a if statement for a special request to cope with my code :/
string toUpperCase(string input)
{
	size_t i = 0;

    while (i < input.length()) {
        input[i] = toupper(input[i]);
        i++;
    }
	if (input == "EARLY")
		input = "EARLY BIRD";
	return (input);
}

//func to display race categories and prices
static void displayRunInfo() {
	cout << YELLOW;
	cout << "----------------------------------------------------------------------\n";
	cout << "No Category            Distance   Fees \n";
	cout << "----------------------------------------------------------------------\n";
	cout << "1. 10km Men Open       10km       (Early Bird: RM 60, Normal: RM 70)\n";
	cout << "2. 10km Women Open     10km       (Early Bird: RM 60, Normal: RM 70)\n";
	cout << "3. 5km Men Open        5km        (Early Bird: RM 50, Normal: RM 60)\n";
	cout << "4. 5km Women Open      5km        (Early Bird: RM 50, Normal: RM 60)\n";
	cout << "5. 5km Family Fun Run  5km        (Early Bird: RM 200, Normal: RM 240)\n";
	cout << "----------------------------------------------------------------------\n";
	cout << RESET;
}

//function to get the run details be passing in category parameters
string	getRunDetails(int category)
{
	string runDetails;

	switch (category) {
		case 1:
			runDetails = ". 10km Men Open";
			break;
		case 2:
			runDetails = ". 10km Women Open";
			break;
		case 3:
			runDetails = ". 5km Men Open";
			break;
		case 4:
			runDetails = ". 5km Women Open";
			break;
		case 5:
			runDetails = ". 5km Family Fun Run";
			break;
		default://not necessary
			cout << "Error: Invalid category!" << endl;
			break;
		
	}
	return (runDetails);
}

static void displayRunFee(const player &p) {
	cout << YELLOW;
	cout << "----------------------------------------------\n";
	cout << "No Category               Fees      FeeType\n";
	cout << "----------------------------------------------\n";
	cout << p.category << setw(25) << left << getRunDetails(p.category)
	<< setw(10) << left << p.fee << toUpperCase(p.feeType) << endl;
	cout << RESET;
}

//func to calculate the fees
double getFee(int type, string feeType) {
    double fee = 0.0;
    if (type == 1 || type == 2) {
        fee = (feeType == "early") ? 60.00 : 70.00;
    } else if (type == 3 || type == 4) {
        fee = (feeType == "early") ? 50.00 : 60.00;
    } else if (type == 5) {
        fee = (feeType == "early") ? 200.00 : 240.00;
    }
    return fee;
}

static void printSummaryHeader() {
	cout << CYAN;
    cout << "------------------------------------------------------------------\n";
    cout << setw(15) << left << "Name" << setw(20) << left << "IC/Passport.No" 
         << setw(5)  << left << "Age" << setw(15) << left << "Contact.No" 
         << setw(10) << left << "Fee" << endl;
    cout << "------------------------------------------------------------------\n";
	cout << RESET;
}

//displays the participant details
static void	printSummary(const player &p)
{
	cout << CYAN;
    cout << setw(15) << left << p.name << setw(20) << left << p.idNum 
         << setw(5)  << left << p.age << setw(15) << left << p.contactNum 
         << setw(10) << left << p.fee << endl;
	cout << RESET;
}

int main()
{
	vector<player> players;
	char c = 'y';
	double totalFee = 0.0;
	
	while (c == 'y')
	{
		player p;
		string tempInput;

		//displays the Category and Price for the run
		displayRunInfo();

		cout << "Select category (1 - 5): ";
		cin >> tempInput;
		while (!isNum(tempInput) || stoi(tempInput) < 1 || stoi(tempInput) > 5)
		{
			cout << RED << "Error: Invalid Category!" << RESET << endl;
			cout << "Select category (1 - 5): ";
			cin >> tempInput;
		}
		p.category = stoi(tempInput);
		cout << "Enter fee type (early/normal): ";
		cin >> p.feeType;
		while (p.feeType != "early" && p.feeType != "normal")
		{
			cout << RED << "Error: Invalid fee type!" << RESET << endl;
			cout << "Enter again (early/normal): ";
			cin >> p.feeType;
		}
		p.fee = getFee(p.category, p.feeType);
		displayRunFee(p);
		p.familyMember = 1;
		if (p.category == 5)
		{
			cout << "How many family member are participating? (1 - 4): ";
			cin >> tempInput;
			while (!isNum(tempInput) || stoi(tempInput) < 1 || stoi(tempInput) > 4)
			{
                cout << RED << "Error: Invalid number!" << RESET << endl;
				cout << "Enter again (1 - 4): ";
                cin >> tempInput;
            }
			p.familyMember = stoi(tempInput);
		}
		for (int i = 0; i < p.familyMember; i++)
		{
            if (p.category == 5)
				cout <<"Enter details for Family Member " << i + 1 << ":" << endl;
            else
				cout << endl << "Enter Participant Details:" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, p.name);
            cout << "IC/Passport Number: ";
            cin >> p.idNum;
            cout << "Enter Age: ";
            cin >> tempInput;
            while (!isNum(tempInput) || stoi(tempInput) < 4 || stoi(tempInput) > 100)
			{
                cout << RED << "Error: Invalid age!" << RESET << endl;
				cout << "Enter again (4 - 100): ";
                cin >> tempInput;
            }
            p.age = stoi(tempInput);
            cout << "Enter Contact Number: ";
            cin >> p.contactNum;
            while (!isNum(p.contactNum) || p.contactNum.length() < 7 || p.contactNum.length() > 15)
			{
                cout << RED << "Error: Invalid contact number!" << RESET << endl;
				cout << "Enter again: ";
                cin >> p.contactNum;
            }
			cout << GREEN << "Participant Added." << RESET << endl << endl;
        }
		totalFee += p.fee;
		players.push_back(p);
		//check whether to add more participants
		cout << "Do you want to add another participant? (y/n): ";
		cin >> c;
		//check input is (n) or (y)
		while (c != 'y' && c != 'n') {
            cout << RED << "Error: Invalid input." << RESET << endl;
			cout << "Do you want to add another participant? (y/n): ";
			cin >> c;
		}
	}
	// display final summary
	printSummaryHeader();
	for (int i = 0; i < players.size(); i++)
	{
		cout << MAGENTA << "Participant " << i + 1 << RESET << endl;
		printSummary(players[i]);
	}
	cout << endl << "Your Total Registration Cost: RM " << totalFee << endl;
	return (0);
}
