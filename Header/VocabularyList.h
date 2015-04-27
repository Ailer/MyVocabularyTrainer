/*
 * VocabularyList.h
 *
 *  Created on: 19.04.2015
 *      Author: nkunkel
 */

#ifndef VOCABULARYLIST_H_
#define VOCABULARYLIST_H_

#include "../Header/VocabularyEntity.h"
#include <iostream>

using namespace std;

class VocabularyList
{
private:
	VocabularyEntity* _firstElement;
	VocabularyEntity* _currentElement;
	int _size;

public:
	void Begin();
	void Next();
	void Add(VocabularyEntity* vocabulary);
	void Remove(VocabularyEntity* vocabulary);
	VocabularyEntity* GetVocabulary();
	int GetSize();
	VocabularyList();
};

#endif /* VOCABULARYLIST_H_ */
