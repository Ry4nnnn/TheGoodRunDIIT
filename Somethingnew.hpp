#ifndef SOMETHINGNEW_HPP
#define SOMETHINGNEW_HPP

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
struct Participants {
	string		name;
	string		idNum;
	string		feeType;
	string		contactNum;
	int			age;
	int			category;
	int			familyMember;
	double		fee;
	vector<Participants> familyDetails;
};

bool isNum(string &input);
string toUpperCase(string input);
string	getRunDetails(int category);
double getFee(int type, string feeType);


#endif

