/*
 * VocabularyList.cpp
 *
 *  Created on: 19.04.2015
 *      Author: nkunkel
 */

#include "../Header/VocabularyList.h"

void VocabularyList::Add(VocabularyEntity* vocabulary)
{
	vocabulary->SetNext(this->_firstElement);
	this->_firstElement = vocabulary;
	this->_size++;
}

void VocabularyList::Remove(VocabularyEntity* vocabulary)
{
	this->Begin();
	VocabularyEntity* current = this->_currentElement;
	VocabularyEntity* nextElement = NULL;

	while (current != NULL)
	{
		if(nextElement != NULL)
		{
			this->Next();
		}

		nextElement = this->_currentElement;

		if(nextElement->GetEnglishWord() == vocabulary->GetEnglishWord()
			&& nextElement->GetGermanWord() == vocabulary->GetGermanWord())
		{
			current->SetNext(nextElement->GetNext());
			delete nextElement;
			this->_size--;
			cout << "Vokabel entfernt" << endl;
			break;
		}

		current = this->_currentElement;
	}
}

void VocabularyList::Begin()
{
	this->_currentElement = this->_firstElement;
}

void VocabularyList::Next()
{
	this->_currentElement = this->_currentElement->GetNext();
}

int VocabularyList::GetSize()
{
	return this->_size;
}

VocabularyEntity* VocabularyList::GetVocabulary()
{
	return this->_currentElement;
}

VocabularyList::VocabularyList()
{
	this->_firstElement = NULL;
	this->_currentElement = NULL;
	this->_size = 0;
}
