#include "Stack.h"


Stack::Stack(): head(nullptr){}
Stack::~Stack(){
	Clear();
}

void Stack::Clear(){
	element *e, *eNext;
	e = head;
	while (e){
		eNext = e->next;
		delete e;
		e = eNext;
	}
	head = nullptr;
}

moveInfo Stack::Pop(){
	if (head != nullptr){
		element *t = head;
		head = head->next;
		moveInfo tInfo = t->info;
		delete t;
		return tInfo;
	}
	return{nullptr, nullptr, nullptr, nullptr, false };
}

bool Stack::IsEmpty(){
	if (!head) return true;
	return false;
}

Stack & Stack::operator +=(const moveInfo & _i){
	element* temp = new element;
	temp->info = _i;
	temp->next = head;
	head = temp;
	return *this;
}

