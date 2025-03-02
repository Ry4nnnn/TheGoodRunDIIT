#include "Somethingnew.hpp"

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

//func to calculate the fees
double getFee(int type, string feeType)
{
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