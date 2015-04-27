/*
 * VocabularyTrainer.h
 *
 *  Created on: 19.04.2015
 *      Author: nkunkel
 */

#ifndef CLASSES_VOCABULARYTRAINER_H_
#define CLASSES_VOCABULARYTRAINER_H_

#include "../Header/VocabularyList.h"

class VocabularyTrainer
{
private:
	VocabularyList _vocabularyList;
	int _points;
	const char* fileName ="Vocabularys";
public:
	void AddWord(string germanWord, string englishWord);
	void RemoveWord(string germanWord, string englishWord);
	int GetPoints();
	void AskGermanWords(int wordsToAsk);
	void AskEnglishWords(int wordsToAsk);
	VocabularyTrainer();
	void SaveListInFile();
	void LoadListFromFile();
};


#endif /* CLASSES_VOCABULARYTRAINER_H_ */
