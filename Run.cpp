#include <iostream>
using namespace std;

//func to display race categories and prices
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

int main()
{
	bool loop = true;
	double totalFee = 0.0;
	std::string name;
	std::string idNum;
	int	age;
	std::string contactNum;
	int category;
	int fee;
	std::string feeType;

	while (loop == true)
	{
		// prompts the user to input name
		cout << "Enter Participant name: ";
		cin >> name;
		// prompts the user to input id number
		cout << "Enter IC/Passport Number: ";
		cin >> idNum;
		// prompts the user to input age
		cout << "Enter Age: ";
		cin >> age;
		// checks if the age is between 4 and 100
		while (age < 4 || age > 100)
		{
			cout << "Invalid age! Enter a valid age between 4 - 100: ";
			cin >> age;
		}
		//prompts the user to input contact number
		cout << "Enter Contact Number: ";
		cin >> contactNum;

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
		//prompts the user to select the feeType
		cout << "Enter Fee type (early/normal): ";
		cin >> feeType;
		//what if the user input other than early or normal
		while (feeType != "early" && feeType != "normal")
		{
			cout << "Invalid fee type! Enter 'early' or 'normal': ";
			cin >> feeType;
		}
		if (category == 1 || category == 2)
		{
			//catergory is equals to 1 or 2
			fee = (feeType == "early") ? 60 : 70;
		}
		else if (category == 3 || category == 4)
		{
			//category is equals to 3 or 4
			fee = (feeType == "early") ? 50 : 60;
		}
		else
		{
			//if the program enters here than means category has to be equals to 5
			fee = (feeType == "early") ? 200 : 240;
			 // If category 5 (Family Run), prompt for 3 more family members
			 cout << "Category 5 requires 4 participants. Enter details for 3 more family members:\n";
			 for (int i = 1; i <= 3; i++)
			 {
				 int familyAge;
				 cout << "Family Member " << i << " - Enter Age: ";
				 cin >> familyAge;
				 while (familyAge < 4 || familyAge > 100)
				 {
					 cout << "Invalid age! Minimum age for Family Run is 4 and Maximum age is 100. Enter again: ";
					 cin >> familyAge;
				 }
			}
		}
		//calculates the total fee formula(totalFee = totalFee + fee)
		totalFee += fee;
		//prints the user details (name, idnum, contactnum, fee, totalfee)
		cout << "Name: " << name << endl;
		cout << "IC/Passport.No: " << idNum << endl;
		cout << "Age: " << age << endl;
		cout << "Contact.No: " << contactNum << endl;
		cout << "Fee: RM" << fee << endl;
		cout << "Total Amount needed to pay: RM" << totalFee << endl;
		//prompts the user to add more participants(y or n)
		cout << "Do you want to add another participant? (y/n): ";
		char x;
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