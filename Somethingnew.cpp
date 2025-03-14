#include "Somethingnew.hpp"

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

static void displayRunFee(const Participants &p) {
	cout << YELLOW;
	cout << "----------------------------------------------\n";
	cout << "No Category               Fees      FeeType\n";
	cout << "----------------------------------------------\n";
	cout << p.category << setw(25) << left << getRunDetails(p.category)
	<< setw(10) << left << p.fee << toUpperCase(p.feeType) << endl;
	cout << RESET;
}

void printSummary(const vector<Participants> &players) {
    cout << CYAN;
    cout << "------------------------------------------------------------------\n";
    cout << setw(15) << left << "Name" 
         << setw(20) << left << "IC/Passport.No"
         << setw(5)  << left << "Age"
         << setw(15) << left << "Contact.No"
         << setw(10) << left << "Fee" << endl;
    cout << "------------------------------------------------------------------\n";

    int participantCount = 1;  // Keep track of participant numbering

    for (const auto &p : players)
    {
        if (p.familyDetails.empty())
        { 
            // Print Individual Participant
            cout << "Participant: " << participantCount++ << endl;
            cout << setw(15) << left << p.name 
                 << setw(20) << left << p.idNum
                 << setw(5)  << left << p.age
                 << setw(15) << left << p.contactNum
                 << "RM " << p.fee << endl;
            cout << endl;
        }
        else
        {
            // Print Family Run - First Member as "Participant"
            cout << "Participant: " << participantCount++ << endl;
            cout << setw(15) << left << p.familyDetails[0].name
                 << setw(20) << left << p.familyDetails[0].idNum
                 << setw(5)  << left << p.familyDetails[0].age
                 << setw(15) << left << p.familyDetails[0].contactNum
                 << "RM " << p.fee << endl;  
            // cout << endl;

            // Print the rest as "Family Member"
            for (size_t i = 1; i < p.familyDetails.size(); i++)
            {
                cout << "Family Member: " << i << endl;
                cout << setw(15) << left << p.familyDetails[i].name
                     << setw(20) << left << p.familyDetails[i].idNum
                     << setw(5)  << left << p.familyDetails[i].age
                     << setw(15) << left << p.familyDetails[i].contactNum
                     << "Shared" << endl;
            }
            cout << endl;
        }
    }
}

void	getParticipantDetails(Participants &p, bool isFamilyMember)
{
	string tempInput;
	
	if (!isFamilyMember)
		cout << "\nEnter Participant Details:\n";

	cin.ignore();
	cout << "Name: ";
    getline(cin, p.name);

    cout << "IC/Passport Number: ";
    cin >> p.idNum;

    cout << "Enter Age: ";
    cin >> tempInput;
    while (!isNum(tempInput) || stoi(tempInput) < 4 || stoi(tempInput) > 100) {
        cout << RED << "Error: Invalid age!" << RESET << endl;
        cout << "Enter again (4 - 100): ";
        cin >> tempInput;
    }
    p.age = stoi(tempInput);

    cout << "Enter Contact Number: ";
    cin >> p.contactNum;
    while (!isNum(p.contactNum) || p.contactNum.length() < 7 || p.contactNum.length() > 15) {
        cout << RED << "Error: Invalid contact number!" << RESET << endl;
        cout << "Enter again: ";
        cin >> p.contactNum;
    }

}

int main()
{
	vector<Participants> players;
	char c = 'y';
	double totalFee = 0.0;
	
	while (c == 'y')
	{
		Participants p;
		string tempInput;

		//displays the Category and Price for the run
		displayRunInfo();

		cout << "Select category (1 - 5): ";
        cin >> tempInput;
        while (!isNum(tempInput) || stoi(tempInput) < 1 || stoi(tempInput) > 5) {
			cout << RED << "Error: Invalid Category!" << RESET << endl;
            cout << "Select category (1 - 5): ";
            cin >> tempInput;
        }
        p.category = stoi(tempInput);
		
        // Select fee type
        cout << "Enter fee type (early/normal): ";
        cin >> p.feeType;
        while (p.feeType != "early" && p.feeType != "normal") {
			cout << RED << "Error: Invalid fee type!" << RESET << endl;
            cout << "Enter again (early/normal): ";
            cin >> p.feeType;
        }
        p.fee = getFee(p.category, p.feeType);
		displayRunFee(p);
		
        // If category 5, get family members' details
        if (p.category == 5) {
            cout << "How many family members are participating? (1 - 4): ";
            cin >> tempInput;
            while (!isNum(tempInput) || stoi(tempInput) < 1 || stoi(tempInput) > 4)
			{
                cout << RED << "Error: Invalid number!" << RESET << endl;
                cout << "Enter again (1 - 4): ";
                cin >> tempInput;
            }
            int familySize = stoi(tempInput);
            for (int i = 0; i < familySize; i++)
			{
                Participants familyMember;
                cout << "Enter details for Family Member " << i + 1 << ":\n";
                getParticipantDetails(familyMember, true);
                p.familyDetails.push_back(familyMember);
            }
        }
		else
            getParticipantDetails(p, false);

        totalFee += p.fee;
        players.push_back(p);
		
		// Ask to add another participant
        cout << "Do you want to add another participant? (y/n): ";
        cin >> c;
		while (c != 'y' && c != 'n') {
			cout << RED << "Error: Invalid input." << RESET << endl;
			cout << "Do you want to add another participant? (y/n): ";
			cin >> c;
		}
	}
	// Display summary
    printSummary(players);
	cout << CYAN << "Your Total Registration Cost: RM " << setw(50) << left << totalFee << RESET << endl;
	return (0);
}
