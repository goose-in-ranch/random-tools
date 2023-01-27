//version 1.1
//TODO: add an option (through command like flag i.e. -s) to allow
//a character besides - to be chosen. (- will still be the default)
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{

	if(argc < 2)
	{
		puts("You must supply at least one filename");
	}

	else
	{
		for(int i = 1; i < argc; i++) //loop args
		{
			int nameLen = strlen(argv[i]);
			char oldName[nameLen] = "";
			char newName[nameLen] = "";

			strcpy(oldName, argv[i]); //fill oldname with filename placed in args

			for(int j = 0; j < nameLen; j++) //loop letters in working arg
			{
				if(oldName[j] == ' ') strcat(newName, "-"); //if current char is space, replace with '-'
				else strncat(newName, &oldName[j], 1); //else ignore and copy char to new filename
			}

		int result = rename(oldName, newName); //rename file and store return value in result for error checking
			//If rename fails, create and print an error message
			if(result != 0){
			char errorMessage[28+strlen(oldName)] = "Oops.. Error renaming file: ";
			strcat(errorMessage, oldName);
			perror(errorMessage);
			}
//		puts(newName); //for testing
		}

	}

return 0;
}
