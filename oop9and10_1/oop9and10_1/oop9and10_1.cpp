#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>
#include <deque>
#include <string>
#include <iterator>
#include <initializer_list>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "rus");
	multimap<string, long, less<string>> lst;

	lst.insert(pair<string, float>("a", 1.2));
	lst.insert(pair<string, float>("b", 2.3));
	lst.insert(pair<string, float>("c", 3.4));
	lst.insert(pair<string, float>("d", 4.5));
	lst.insert(pair<string, float>("d", 5.6));

	cout << " ��������� lst: " << endl;
	for (auto el : lst)
	{
		cout << el.first << ":" << el.second << " ";
	}
	
	cout << endl << " �������� ��������� �������� �� �� ������ � ���������� ����� " << endl;

	lst.erase("d");
	lst.erase("c");
	lst.insert(pair<string, float>("c", 7));

	cout << " ��������� lst: " << endl;
	for (auto el : lst)
	{
		cout << el.first << ":" << el.second << endl;
	}

	cout << " ����� ��� ������ ����������: " << endl;

	map<string, long>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}

	cout << " ����� ��� ������ revers ����������: " << endl;

	map<string, long>::reverse_iterator rit;
	for (rit = lst.rbegin(); rit != lst.rend(); rit++)
	{
		cout << rit->first << ":" << rit->second << endl;
	}

	cout << " ����� ��� ������ const ����������: " << endl;

	map<string, long>::const_iterator cit;
	for (cit = lst.cbegin(); cit != lst.cend(); cit++)
	{
		cout << cit->first << ":" << cit->second << endl;
	}

	cout << " ������� ������� � ��������� � " << endl;
	deque<float> deq;
	for (int i = 0; i < 3; i++)
		deq.push_back(i + 5);	
	
	cout << "������� deq: ";
	for (auto el : deq)
	{
		cout << el << " ";
	}
	cout << endl;

	cout << "����������� �����������";

	deque<float>::iterator list_begin = deq.begin();
	deque<float>::iterator list_end = deq.end();

	for (auto list_iter = list_begin; list_iter != list_end; list_iter++)
	{
		lst.insert(pair<string, float>("other", *list_iter));
	}

	cout << " ��������� lst: " << endl;
	for (auto el : lst)
	{
		cout << el.first << ":" << el.second << endl;
	}
}