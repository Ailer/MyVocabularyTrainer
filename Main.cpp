/*
 * Main.cpp
 *
 *  Created on: 18.04.2015
 *      Author: nkunkel
 */
//#include <stdlib.h>
#include <iostream>
#include "Header/VocabularyTrainer.h"

using namespace std;

int main()
{
	char command;
	VocabularyTrainer vocabularyTrainer;
	cout << "Willkommen" << endl;
	vocabularyTrainer.LoadListFromFile();

	while(true)
	{
		cout <<	"- a Zum hinzufügen eines neuen Wortes drücken"
			 << endl << "- r Zum entfernen eines Wortes"
			 << endl << "- d Zum Abfragen von Deutsch zu Englisch"
			 << endl << "- e zum Abfragen von Englisch zu Deutsch"
			 << endl << "- q beendet das Programm"
			 << endl;
		cin >> command;

		switch(command)
		{
			case 'a':
			{
				string german;
				string english;

				cout << "Bitte deutsches Wort eingeben:" << endl;
				cin >> german;
				cout << "Bitte englisches Wort eingeben:" << endl;
				cin >> english;

				vocabularyTrainer.AddWord(german, english);
				break;
			}
			case 'r':
			{
				string german;
				string english;

				cout << "Bitte deutsches Wort eingeben:" << endl;
				cin >> german;
				cout << "Bitte englisches Wort eingeben:" << endl;
				cin >> english;

				vocabularyTrainer.RemoveWord(german, english);
				break;
			}
			case 'd':
			{
				cout << "Deutsche Wörter?" << endl;
				int wordsToAsk;
				cout << "Anzahl der zu fragenden Wörter eingeben:" << endl;
				cin >> wordsToAsk;
				vocabularyTrainer.AskGermanWords(wordsToAsk);

				break;
			}
			case 'e':
			{
				cout << "Englische Wörter?" << endl;
				int wordsToAsk;
				cout << "Anzahl der zu fragenden Wörter eingeben:" << endl;
				cin >> wordsToAsk;
				vocabularyTrainer.AskEnglishWords(wordsToAsk);

				break;
			}
			case 'q':
			{
				cout << "Vokabeltrainer wird beendet. Liste speichern? (y/n)" << endl;
				char save;
				cin >> save;

				if(save == 'y')
				{
					vocabularyTrainer.SaveListInFile();
				}

				cout << "Vokabeltrainer beendet";

				return 0;
			}
		}
	}
}

