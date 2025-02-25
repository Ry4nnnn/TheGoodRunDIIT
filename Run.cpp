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
		cout << "Enter Participant name: ";
		cin >> name;
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

		displayPrice();

		cout << "Select Category (1 - 5): ";
		cin >> category;
		while (!(category >= 1 && category <= 5))
		{
			cout << "Invalid category! Enter a number between 1 - 5: ";
			cin >> category;
		}
		cout << "Enter Fee type (early/normal): ";
		cin >> feeType;
		while (feeType != "early" && feeType != "normal")
		{
			cout << "Invalid fee type! Enter 'early' or 'normal': ";
			cin >> feeType;
		}
		if (category == 1 || category == 2)
			fee = (feeType == "early") ? 60 : 70;
		else if (category == 3 || category == 4)
			fee = (feeType == "early") ? 50 : 60;
		else
		{
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
		totalFee += fee;
		cout << "Name: " << name << endl;
		cout << "IC/Passport.No: " << idNum << endl;
		cout << "Age: " << age << endl;
		cout << "Contact.No: " << contactNum << endl;
		cout << "Fee: RM" << fee << endl;
		cout << "Total Amount needed to pay: RM" << totalFee << endl;
		cout << "Do you want to add another participant? (y/n): ";
		char x;
		cin >> x;
		while (x != 'y' && x != 'n' && x != 'Y' && x != 'N')
		{
            cout << "Invalid input! Enter 'y' or 'n': ";
            cin >> x;
        }
        if (x == 'n' || x == 'N')
		{
            loop = false;
            cout << "\nFinal Total Fee: RM " << totalFee << endl;
            cout << "Thank you for registering!\n";
		}
	}
	return (0);
}