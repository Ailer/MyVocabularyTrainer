/*
 * VocabularyTrainer.cpp
 *
 *  Created on: 19.04.2015
 *      Author: nkunkel
 */

#include "../Header/VocabularyTrainer.h"
#include <iostream>
#include <fstream>

using namespace std;

//TODO: Liste nach häufig beantworteten Vokabeln sortieren

void VocabularyTrainer::AddWord(string germanWord, string englishWord)
{
	VocabularyEntity* tmp = new VocabularyEntity(germanWord, englishWord);
	this->_vocabularyList.Add(tmp);
}

void VocabularyTrainer::RemoveWord(string germanWord, string englishWord)
{
	VocabularyEntity* tmp = new VocabularyEntity(germanWord, englishWord);
	this->_vocabularyList.Remove(tmp);
}

int VocabularyTrainer::GetPoints()
{
	return this->_points;
}

void VocabularyTrainer::AskGermanWords(int wordsToAsk)
{
	this->_vocabularyList.Begin();
	VocabularyEntity* vocabulary;
	string answer;

	for(int i=0; i < wordsToAsk; i++)
	{

		if(i >= this->_vocabularyList.GetSize())
		{
			break;
		}

		vocabulary = this->_vocabularyList.GetVocabulary();

		cout << "Englisches Wort für? " << vocabulary->GetGermanWord() << endl;
		cin >> answer;

		if (vocabulary->GetEnglishWord() == answer)
		{
			cout << "Richtig!" << endl;
			this->_points++;
		}
		else
		{
			cout << "Falsch richtige Antwort: " << vocabulary->GetEnglishWord() << endl;
		}

		this->_vocabularyList.Next();
	}

	cout << endl << "Geschafft erreichte Punkte: " << this->_points << endl;
}

void VocabularyTrainer::AskEnglishWords(int vordsToAsk)
{
	this->_vocabularyList.Begin();
	VocabularyEntity* vocabulary;
	string answer;

	for(int i=0; i < vordsToAsk; i++)
	{
		if(i >= this->_vocabularyList.GetSize())
		{
			break;
		}

		vocabulary = this->_vocabularyList.GetVocabulary();

		cout << "Deutsches Wort für? " << vocabulary->GetGermanWord() << endl;
		cin >> answer;

		if (vocabulary->GetEnglishWord() == answer)
		{
			cout << "Richtig!" << endl;
			this->_points++;
		}
		else
		{
			cout << "Falsch richtige Antwort: " << vocabulary->GetEnglishWord() << endl;
		}

		this->_vocabularyList.Next();
	}

	cout << endl << "Geschafft erreichte Punkte: " << this->_points << endl;
}

void VocabularyTrainer::SaveListInFile()
{
	fstream stream;
	stream.open(VocabularyTrainer::fileName, ios::out);
	this->_vocabularyList.Begin();

	while(this->_vocabularyList.GetVocabulary() != NULL)
	{
		VocabularyEntity* tmp = this->_vocabularyList.GetVocabulary();

		if (tmp->GetEnglishWord().size() == 0
			|| tmp->GetGermanWord().size() == 0)
		{
			break;
		}

		stream << tmp->GetEnglishWord() << ";" << tmp->GetGermanWord() <<endl;
		this->_vocabularyList.Next();
	}

	stream.close();
}

void VocabularyTrainer::LoadListFromFile()
{
	   fstream stream;
	   char cstring[256];
	   string splitInput;
	   int indexSeparator;
	   stream.open(VocabularyTrainer::fileName, ios::in);

	   if(!stream)
	   {
		   cout << "Datei wurde nicht gefunden" << endl;
		   return;
	   }

	   while (!stream.eof())
	   {
		   stream.getline(cstring, sizeof(cstring));

	       splitInput = cstring;

	       if(splitInput.size() == 0)
	       {
	    	   break;
	       }

	       indexSeparator = splitInput.find(';');
	       this->AddWord(splitInput.substr(0, indexSeparator),
	        			 splitInput.substr(indexSeparator+1, splitInput.size()));
	   }

	   stream.close();
}

VocabularyTrainer::VocabularyTrainer()
{
	this->_points = 0;
}
