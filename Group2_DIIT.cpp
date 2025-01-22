#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace	std;

//a struct/template to store each player's data
struct player {
	string		name;
	string		idNum;
	int			age;
	string		contactNum;
	string		type;
	string		feeType;
	double		fee;
};

//func to display race categories and prices
static void displayPrice() {
	cout << "Sunway The Good Run 2025 Categories:" << endl;
    cout << "1. 10km Men Open (Early Bird: RM 60.00, Normal: RM 70.00)\n";
    cout << "2. 10km Women Open (Early Bird: RM 60.00, Normal: RM 70.00)\n";
    cout << "3. 5km Men Open (Early Bird: RM 50.00, Normal: RM 60.00)\n";
    cout << "4. 5km Women Open (Early Bird: RM 50.00, Normal: RM 60.00)\n";
    cout << "5. 5km Family Fun Run (Early Bird: RM 200.00, Normal: RM 240.00)\n";
}

//func to calculate the fees
double calculateFee(int type, string feeType) {

	return (0);
}

//func to convert string to integer
int ft_atoi(char *str) {
	int result;
	int sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str >= 48 && *str <= 57) && *str != '\0')
	{
		result = (*str - 48) + (result * 10);
		str++;
	}
	return (result);
}

int main() {
	vector<player> players;
	char c = 'Y';
	double totalFee = 0.0;
	
	while (toupper(c) == 'Y') {
		player p;
		int type;
		string feeType;

		cout << "Enter participant name: ";
		getline(cin, p.name);
		cout << "Enter IC or Passport Number: ";
		getline(cin, p.idNum);
		cout << "Enter age: ";
        cin >> p.age;
        cout << "Enter contact number: ";
        getline(cin, p.contactNum);

		displayPrice();
		cout << "Select category (1 - 5): ";
		cin >> type;
		cout << "Enter fee type (early/normal): ";
		cin >> feeType;

		cout << "Do you want to add another participant? (y/n): ";
		cin >> c;
		if (toupper(c) != 'N' || toupper(c) != 'Y')
			cout << "Error! Invalid Input" << endl;
	}
	return (0);
}