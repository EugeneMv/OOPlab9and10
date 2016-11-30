
#include "stdafx.h"
#include <iostream>
#include "List.h"

using namespace std;

void List::add(int value){
	List* ls = new List;
	if(!head){
		ls->element = value;
		this->head = ls;
	}
	else{
		List* last = new List;
		last->element = value;
		ls = this->head;
		while(ls->next != NULL){
			ls = ls->next;
		}
		ls->next = last;
	}
}

void List::show(){
	List *lst = head;
	while(lst){
		std::cout << lst->element << " ";
		lst = lst->next;
	}
}

int List::showFirst() {
	List *lst = head;
		return lst->element;
}

bool List::IsEmpty(){
	if(this->head)
		return false;
	else 
		return true;
}

void List::operator+ (List &ls2){
	List* ls = head;
	while(ls->next != NULL){
			ls = ls->next;
		}
		ls->next = ls2.head;
}

void List::operator--(){
	List* ls = head;
	head = head->next;
}

bool List::operator==(List &l){
	bool b = true;
	List* ls1 = head;
	List* ls2 = l.head;
	while(ls1 != NULL && ls2 != NULL){
		if(ls1->element == ls2->element)
		{
			ls1 = ls1->next;
			ls2 = ls2->next;
		}
		else
		{
			b = false;
			break;
		}
	}
	return b;
}

std::ostream& operator<<(std::ostream& ostm, List* object)
{
	ostm << object->showFirst() << endl;
	return ostm;
}
