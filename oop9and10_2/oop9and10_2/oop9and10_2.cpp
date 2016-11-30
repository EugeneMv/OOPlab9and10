#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>
#include <deque>
#include <string>
#include <iterator>
#include <initializer_list>
#include <memory>
#include "List.h"

using namespace std;

void main() {
	setlocale(LC_CTYPE, "rus");

	List* element1 = new List; element1->add(1);
	List* element2 = new List; element2->add(2);	
	List* element3 = new List; element3->add(3);
	List* element4 = new List; element4->add(4);

	unique_ptr<multimap<string, List*>> mmuptr(new multimap<string, List*>);

	mmuptr->insert(pair<string, List*>("el1", element1));
	mmuptr->insert(pair<string, List*>("el2", element2));
	mmuptr->insert(pair<string, List*>("el3", element3));
	mmuptr->insert(pair<string, List*>("el4", element4));


	cout << " контейнер lst: " << endl;
	for (auto el : *mmuptr)
	{
		cout << el.first << ":" << el.second;
	}

	cout << endl << " удаление некоторых элеметов по их ключам и добавление новых " << endl;

	mmuptr->erase("el3");
	mmuptr->insert(pair<string, List*>("el5", element1));

	cout << " контейнер lst: " << endl;
	for (auto el : *mmuptr)
	{
		cout << el.first << ":" << el.second << endl;
	}

	cout << " вывод при помощи итераторов: " << endl;

	map<string, List*>::iterator it;
	for (it = mmuptr->begin(); it != mmuptr->end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}

	cout << " вывод при помощи revers итераторов: " << endl;

	map<string, List*>::reverse_iterator rit;
	for (rit = mmuptr->rbegin(); rit != mmuptr->rend(); rit++)
	{
		cout << rit->first << ":" << rit->second << endl;
	}

	cout << " вывод при помощи const итераторов: " << endl;

	map<string, List*>::const_iterator cit;
	for (cit = mmuptr->cbegin(); cit != mmuptr->cend(); cit++)
	{
		cout << cit->first << ":" << cit->second << endl;
	}

	cout << " создаем очередь и заполняем её " << endl;
	shared_ptr<deque<List*>> dsptr(new deque<List*>);

	List *value1 = new List; value1->add(11);
	List *value2 = new List; value2->add(22);
	List *value3 = new List; value3->add(33);
	List *value4 = new List; value4->add(44);

		dsptr->push_back(value1);
		dsptr->push_back(value2);
		dsptr->push_back(value3);
		dsptr->push_back(value4);


	cout << "очередь deq: " << endl;
	for (auto el : *dsptr)
	{
		cout << el;
	}
	cout << endl;

	cout << "объединение контейнеров";

	deque<List*>::iterator _begin = dsptr->begin();
	deque<List*>::iterator _end = dsptr->end();

	for (auto _iter = _begin; _iter != _end; _iter++)
	{
		mmuptr->insert(pair<string, List*>("other", *_iter));
	}

	cout << " контейнер lst: " << endl;
	for (auto el : *mmuptr)
	{
		cout << el.first << ":" << el.second << endl;
	}
}