/*
 * VocabularyTemplate.cpp
 *
 *  Created on: 18.04.2015
 *      Author: nkunkel
 */

#include "../Header/VocabularyEntity.h"

string VocabularyEntity::GetGermanWord()
{
	return this->_germanWord;
}

string VocabularyEntity::GetEnglishWord()
{
	return this->_englishWord;
}

VocabularyEntity* VocabularyEntity::GetNext()
{
	return this->_next;
}

void VocabularyEntity::SetGermanWord(string germanWord)
{
	this->_germanWord = germanWord;
}

void VocabularyEntity::SetEnglishWord(string englishWord)
{
	this->_englishWord = englishWord;
}

void VocabularyEntity::SetNext(VocabularyEntity* nextElement)
{
	this->_next = nextElement;
}

VocabularyEntity::VocabularyEntity(string germanWord, string englishWord)
{
	this->_germanWord = germanWord;
	this->_englishWord = englishWord;
	this->_next = NULL;
}

VocabularyEntity::VocabularyEntity()
{
	this->_next= NULL;
}


