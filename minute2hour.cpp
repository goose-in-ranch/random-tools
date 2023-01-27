// Version 1.0
// A program to convert integer minutes to hours and minutes

//TODO add Days functionality for hours >=24
//TODO refactor input verification into its own function for cleaner error handling

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void minutesToHours(int input)
{
	cout << input / 60 << "H " << input % 60 << "M\n";
}

int main(int argc, char *argv[])
{
string help = "This program takes one integer (minutes) and converts it to hours and minutes.\nNegative numbers are not allowed";

	//This if statement catches if the user supplies an incorrect amount of arguments (not 1).
	//If more or less than the correct amount of arguments is supplied, it prints the appropriate
	//error and exits with a return code of 1.
	if(argc != 2)
	{
		switch (argc)
		{
			case 1:
				//If no arguments are given, print help.
				cout << help << "\n\nERROR: No arguments supplied dummy.\n";
				break;
			
			default:
				//Too many arguments have been supplied. Print help and tell user
				//they have supplied too many arguments
				cout << help << "\n\nERROR: Too many arguments! Only one allowed, plebian.\n";
				break;	
		}
		

	return 1;
	}

	//Check input for valid integer
	string input = argv[1];

	//This if statement checks for a negative sign and reminds users of the NO NEGATIVE NUMBERS rule
	if (input[0] =='-')
	{
		cout << help << "\n\nERROR: Negative numbers are NOT allowed.\n";
		return 2;
	}
	
	for (int i=0; i<input.length(); i++)
	{
		if(!isdigit(input[i]))
		{
		cout << help << "\n\nERROR: Non-integer detected buffoon!\n";
		return 3;
		}
	}
	
	//End of checking input. If all checks passed, call conversion function.
	minutesToHours(stoi(input));
	

return 0;
}

/*
 * 	RETURN VALUE CHEAT SHEET
 * 	Return 0 success
 * 	Return 1 incorrect number of arguments
 * 	Return 2 negative number detected
 * 	Return 3 non integer detected
 */
