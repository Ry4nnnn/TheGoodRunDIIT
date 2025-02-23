#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace	std;

//----------COLOURS----------//
/* Regular */
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
	int			age;
	string		contactNum;
	string		category;
	string		feeType;
	double		fee;
};

//function to check if input is Number
bool isNum(std::string &ageInput)
{
	int i = 0;
	while (ageInput[i] != '\0')
	{
		if (!isdigit(ageInput[i]))
			return (false);
		i++;
	}
	return (true);
}

//func to display race categories and prices
static void displayPrice() {
	cout << YELLOW;
	cout << "------------------------------------------------------------------\n";
	cout << "       Category        Distance   Fees \n";
	cout << "------------------------------------------------------------------\n";
	cout << "1. 10km Men Open       10km   (Early Bird: RM 60, Normal: RM 70)\n";
	cout << "2. 10km Women Open     10km   (Early Bird: RM 60, Normal: RM 70)\n";
	cout << "3. 5km Men Open        5km    (Early Bird: RM 50, Normal: RM 60)\n";
	cout << "4. 5km Women Open      5km    (Early Bird: RM 50, Normal: RM 60)\n";
	cout << "5. 5km Family Fun Run  5km    (Early Bird: RM 200, Normal: RM 240)\n";
	cout << "------------------------------------------------------------------\n";
	cout << RESET;
}

//func to calculate the fees
double calculateFee(int type, string feeType) {
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

//displays the participant details
static void	printSummary(const player &p)
{
	cout << CYAN << "Name: " << RESET << p.name << endl;
	cout << CYAN << "IC / Passport Number: " << RESET << p.idNum << endl;
	cout << CYAN << "Age: " << RESET << p.age << endl;
	cout << CYAN << "Contact Number: " << RESET << p.contactNum << endl;
	cout << CYAN << "Fee: RM " << p.fee << RESET << endl;
}

int main() {
	vector<player> players;
	char c = 'y';
	double totalFee = 0.0;
	
	while (c == 'y') {
		player p;
		int category;
		string feeType;
		std::string name;
		std::string tempInput;

		cout << "Enter participant name: ";
		cin >> ws;
		getline(cin, p.name);
		cout << "Enter IC or Passport Number: ";
		cin >> p.idNum;
		// getline(cin, p.idNum);
		cout << "Enter age: ";
        cin >> tempInput;
		while (!isNum(tempInput) || stoi(tempInput) <= 0 || stoi(tempInput) > 100)
		{
			cout << RED << "Invalid age number!" << RESET << endl;
			cout << "Enter age: ";
			tempInput = '\0';//resets input so it will not reloop
			cin >> tempInput;
		}
		p.age = stoi(tempInput);
		tempInput = '\0';//resets for contact number input
        cout << "Enter contact number: ";
		cin >> tempInput;
		while (!isNum(tempInput))
		{
			cout << RED << "Invalid contact number!" << RESET << endl;
			cout << "Enter contact number: ";
			tempInput = '\0';//resets input so it will not reloop
			cin >> tempInput;
		}
		p.contactNum = stoi(tempInput);
		// cin.ignore();
        // getline(cin, p.contactNum);

		//displays the Category and Price for the run
		displayPrice();

		cout << "Select category (1 - 5): ";
		cin >> category;
		while (!(category >= 1 && category <= 5))
		{
			cout << RED << "Invalid Category!" << RESET << endl;
			cout << "Select category (1 - 5): ";
			cin >> category;
		}

		cout << "Enter fee type (early/normal): ";
		cin >> feeType;
		while (feeType != "early" && feeType != "normal")
		{
			cout << RED << "Invalid fee type!" << RESET << endl;
			cout << "Enter fee type (early/normal): ";
			cin >> feeType;
		}
		p.fee = calculateFee(category, feeType);
		totalFee += p.fee;
		players.push_back(p);
		printSummary(p);
		//check whether to add more participants
		cout << BLUE << "Do you want to add another participant? (y/n): " << RESET;
		cin >> c;
		//check input is (n) or (y)
		while (c != 'y' && c != 'n') {
            cout << RED << "Error! Invalid input." << RESET << endl;
			cout << BLUE << "Do you want to add another participant? (y/n): " << RESET;
			cin >> c;
        }

		if (c == 'n')
		{
			cout << "Registration Summary" << endl;
			for (int i = 0; i < players.size(); i++) {
				cout << MAGENTA << "Participant " << i + 1 << RESET << endl;
				printSummary(players[i]);
			}
			cout << endl << "Your Total Registration Cost: RM " << totalFee << endl;
		}
	}
	return (0);
}