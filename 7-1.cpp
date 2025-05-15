
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{

    char word[1000];
    char WORD[1000];
    cout << "Enter string : ";
    cin.getline(word, 1000);

    for (int i = 0; i < word[i] != '\0'; i++)
    {
        WORD[i] = tolower(word[i]);
    }

    char *token = strtok(WORD, " ");
    int wordcount = 0;
    char Word[100][20];
    while (token != NULL)
    {
        strcpy(Word[wordcount], token);
        wordcount++;
        token = strtok(NULL, " ");
    }
    int count = 1;
    for (int i = 0; i < wordcount; i++)
    {
        for (int j = i + 1; j < wordcount; j++)
        {
            if (strcmp(Word[i], Word[j]) == 0)
            {
                count++;
            }
            else
            {

            }
        }
    }

    cout << "frequency of the words are : " << endl;

    for (int i = 0; i < wordcount; i++)
    {
        cout << Word[i] << " -> " << count << endl;
    }
    return 0;
}
