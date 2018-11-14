#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

using namespace std;

bool checkValid(char arr[50]);
void translateToPigLatin(char arr[50]);
void lowercaseIt(char arr[50]);

int main()
{
	char word[50];
	char *ptr = word;

	char answer = 'N';

	int count = 0;
	bool result = false;
	
	do
	{

		do {
			result = false;

			cout << "Enter a word to translate: " << endl;
			scanf("%49s", word);
			//cin.getline(word, 50);


			lowercaseIt(word);
			
			// after I added scanf this commented portion no longer is needed 

			// scanf will not allow a user to enter a space or null
			//if (word[0] == '\0' || word[0] == ' ')
			//{
			//	result = true;
			//	cout << "Empty string! - Nothing to Translate. " << endl;
			//}
			
			// this only executes when word is between 47 and 49 --- if its greater than 49 it terminates
			if (strlen(word) > 47)
			{
				result = true;
				cout << "Word cannot be translated. Word is too long. " << endl;
			}
			
			if (result == false)
			{
				if (checkValid(word) == true)
				{
					result = true;
					cout << "Word cannot be translated. Word contains non-alpha characters. " << endl;
				}
			}
			cout << "\n";

		} while (result == true);
		
		if (result == false)
		translateToPigLatin(word);

		cout << "\n";
		cout << "Need to translate another word? enter Y to continue " << endl;

		cin >> answer;

		cout << "\n";
		// need to clear the input buffer before asking for another word
		cin.ignore();
		cin.clear();


	} while (answer == 'Y' || answer == 'y');

	cout << "Good Bye!" << endl;

}


// function to check for numbers
bool checkValid(char arr[50])
{
	bool result = false;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		// if already recognized a non-alpha value, break out of loop
		if (result == true)
			break;

		if (isalpha(arr[i]) == 0)
			result = true;

		if (isalpha(arr[i]) != 0)
			result = false;
	}

	return result;
}


// function to convert word to lowercase
void lowercaseIt(char arr[50])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		arr[i] = tolower(arr[i]);
	}
}



// function to translate to pig latin
void translateToPigLatin(char arr[50])
{
	// 2 demensional array
	char unchanged[6][4] = { "the","and","but","for","nor","yet" };
	// array for vowels
	char vowels[6] = "aeiou";
	char temp;

	char *ptr = arr;
	char *ptr2 = vowels;
	int j;

	bool result = false;

	// if character count is <= two don't need to translate
	if (strlen(arr) <= 2)
		result = true;

	// loop to check for articles and conjunctions
	// if word is an artivle or conjunction don't need to translate
	for (int i = 0; i < 6; i++)
	{
		if (result == true)
			break;
		if (strcmp(unchanged[i], arr) == 0)
			result = true;
		else
			result = false;
	}

	// loop checks if word starts with a consonant or vowel

	if (result == false)
	{
		while (*ptr2 != '\0')
		{
			if (*ptr != *ptr2)
			{
				ptr2 = ptr2++;
			}
			else if (*ptr == *ptr2)
			{
				break;
			}
		}
		if (*ptr2 == '\0')
		{
			j = strlen(arr) - 1;
			for (int i = 0; i < j; i++)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			strcat(arr, "ay");
		}

		// if word starts with vowel append with an 'ay'
		else
		{
			strcat(arr, "ay");
		}

	}

	cout << "Translation: " << arr << endl;
}



