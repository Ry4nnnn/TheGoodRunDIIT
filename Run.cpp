#include <iostream>
#include <iomanip>//for setprecision() func

using namespace std;

// function to display race categories and prices
static void displayPrice() {
	cout << "------------------------------------------------------------------\n";
	cout << "       Category        Distance   Fees \n";
	cout << "------------------------------------------------------------------\n";
	cout << "1. 10km Men Open       10km   (Early Bird: RM 60, Normal: RM 70)\n";
	cout << "2. 10km Women Open     10km   (Early Bird: RM 60, Normal: RM 70)\n";
	cout << "3. 5km Men Open        5km    (Early Bird: RM 50, Normal: RM 60)\n";
	cout << "4. 5km Women Open      5km    (Early Bird: RM 50, Normal: RM 60)\n";
	cout << "5. 5km Family Fun Run  5km    (Early Bird: RM 200, Normal: RM 240)\n";
	cout << "------------------------------------------------------------------\n";
}

// function to determine the fee based on category and fee type
double getFee(std::string feeType, int category)
{
	double fee;

	fee = 0;
	if (category == 1 || category == 2)
	{
		//category is equals to 1 or 2
		if (feeType == "early")
			fee = 60;
		else
			fee = 70;
	}
	else if (category == 3 || category == 4)
	{
		//category is equals to 3 or 4
		if (feeType == "early")
			fee = 50;
		else
			fee = 60;
	}
	else
	{
		//if the program enters here than means category has to be equals to 5
		if (feeType == "early")
			fee = 200;
		else
			fee = 240;
	}
	return (fee);
}

//function to get the run details be passing in category parameters
std::string	getRunDetails(int category)
{
	std::string runDetails;

	switch (category) {
		case 1:
			runDetails = ". 10km Men Open [";
			break;
		case 2:
			runDetails = ". 10km Women Open [";
			break;
		case 3:
			runDetails = ". 5km Men Open [";
			break;
		case 4:
			runDetails = ". 5km Women Open [";
			break;
		case 5:
			runDetails = ". 5km Family Fun Run Malaysian (2Adults + 2Kids 4yrs & above) [";
			break;
		default://not necessary
			cout << "Error: Invalid category!" << endl;
			break;
		
	}
	return (runDetails);
}

int main()
{
	bool		loop;
	double		totalFee;
	double		fee;
	int			age;
	int			category;
	int			familyMember;
	std::string name;
	std::string idNum;
	std::string contactNum;
	std::string feeType;
	std::string runDetails;

	loop = true;
	totalFee = 0;
	fee = 0;
	while (loop) 
	{
		//this line will call displayPrice() function and prints the price and categories for the run
		displayPrice();
		//prompts the user to select the categories
		cout << "Select Category (1 - 5): ";
		cin >> category;
		//checks if the user enters category between 1-5
		while (!(category >= 1 && category <= 5))
		{
			cout << "Invalid category! Enter a number between 1 - 5: ";
			cin >> category;
		}
		cout << "Enter Fee type (early/normal): ";
		cin >> feeType;
		//what if the user input other than early or normal
		while (feeType != "early" && feeType != "normal")
		{
			cout << "Invalid fee type! Enter 'early' or 'normal': ";
			cin >> feeType;
		}
		fee = getFee(feeType, category);//calls getFee function to get the fee respectively
		//prompts the user to select category
		cout << endl << "Category:" << endl;
		cout << category << getRunDetails(category) << feeType << "]" << endl;
		cout << fixed << setprecision(2); // Ensure 2 decimal place and will be fixed for every double cout
		cout << "Fee is RM" << fee << endl;
		if (category == 5)
		{
			cout << "How many family member are participating? (1-4): ";
			cin >> familyMember;
			while (familyMember < 1 || familyMember > 4)
			{
                cout << "Invalid number! Enter between 1 and 4: ";
                cin >> familyMember;
            }
			for (int i = 1; i <= familyMember; i++) {
                cout << "Enter details for Family Member " << i << ":\n";
                cout << "Name: ";
				cin.ignore();
                getline(cin, name);
                cout << "IC/Passport Number: ";
                cin >> idNum;
                cout << "Enter Age: ";
                cin >> age;
                while (age < 4 || age > 100) {
                    cout << "Invalid age! Enter a valid age between 4 - 100: ";
                    cin >> age;
                }
                cout << "Contact Number: ";
                cin >> contactNum;
                cout << endl << "Family Member " << i << " Details Recorded.\n";
            }
		}
		else
		{
			cout << "Enter Participant name: ";
			cin.ignore();
			getline(cin, name);;
			cout << "Enter IC/Passport Number: ";
			cin >> idNum;
			cout << "Enter Age: ";
			cin >> age;
			while (age < 4 || age > 100)
			{
				cout << "Invalid age! Enter a valid age between 4 - 100: ";
				cin >> age;
  			}
			cout << "Enter Contact Number: ";
			cin >> contactNum;
			cout << endl << "Participant Details Added." << endl;
		}
		//calculates the total fee formula(totalFee = totalFee + fee)
		totalFee += fee;
		cout << "Fee: RM" << fee << endl;
		//prompts the user to add more participants(y or n)
		char x;
		cout << "Do you want to add another participant? (y/n): ";
		cin >> x;
		//what if the user inputs other than x or y
		while (x != 'y' && x != 'n' && x != 'Y' && x != 'N')
		{
            cout << "Invalid input! Enter 'y' or 'n': ";
            cin >> x;
        }
		//checks if the user input (n or N) and  loop = false to stop the main while loop
        if (x == 'n' || x == 'N')
		{
            loop = false;
            cout << "\nFinal Total Fee: RM " << totalFee << endl;
            cout << "Thank you for registering!\n";
		}
	}
	return (0);
}