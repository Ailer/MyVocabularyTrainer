/*
 * VocabularyEntity.h
 *
 *  Created on: 18.04.2015
 *      Author: nkunkel
 */

#ifndef CLASSES_VOCABULARYTEMPLATE_H_
#define CLASSES_VOCABULARYTEMPLATE_H_

#include <string>

using namespace std;


class VocabularyEntity
{
	private:
		string _germanWord;
		string _englishWord;
		VocabularyEntity* _next;
	public:
		void SetGermanWord(string germanWord);
		void SetEnglishWord(string englishWord);
		void SetNext(VocabularyEntity* nextElement);
		string GetGermanWord();
		string GetEnglishWord();
		VocabularyEntity* GetNext();
		VocabularyEntity(string germanWord, string englishWord);
		VocabularyEntity();
};

#endif /* CLASSES_VOCABULARYTEMPLATE_H_ */
