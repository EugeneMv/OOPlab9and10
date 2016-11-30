#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>
#include <deque>
#include <algorithm>
#include <string>
#include <iterator>
#include <initializer_list>
#include <memory>
#include "List.h"

using namespace std;

bool sort_function_ubiv(List* object1, List* object2)
{
	return (object1->showFirst()>object2->showFirst());
}

bool sort_function_vosrast(List* object1, List* object2)
{
	return (object1->showFirst()<object2->showFirst());
}

void main() {
	setlocale(LC_CTYPE, "rus");

	List* element1 = new List; element1->add(1);
	List* element2 = new List; element2->add(2);
	List* element3 = new List; element3->add(3);
	List* element4 = new List; element4->add(4);

	list<List*> lst;
	list<List*>::iterator it = lst.begin();
	lst.insert(it, element1);
	lst.insert(it, element2);
	lst.insert(it, element3);
	lst.insert(it, element4);
	cout << "_______����� ������_________";
	for (auto el : lst)
	{
		cout << endl << el << endl;
	}

	lst.sort(sort_function_ubiv);
	cout << "_______��������� ���� �� ��������_________";
	for (auto el : lst)
	{
		cout << endl << el << endl;
	}
	cout << "______�������� ������ ������� � ���� �� � multimap__________" << endl;

	multimap<string, List*> mmap;
	int val; string key_val;
	while (true) {
		cout << "�������� �������� �������(��� ����� 0 ���� ������������): "; cin >> val;
		if (val == 0)
			break;
		list<List*>::iterator for_ = lst.begin();

		while (for_ != lst.end())
		{
			for_ = find_if(for_, lst.end(), [&](List* object) {return object->showFirst() == val; });
			if (for_ != lst.end())
			{
				_itoa(val, const_cast<char*>(key_val.c_str()), 10);
				mmap.insert(pair<string, List*>(const_cast<char*>(key_val.c_str()), *for_));
				for_++;
			}
		}
	}

	cout << "_______����� ���������� � �����_________" << endl;
	multimap<string,List*>::iterator begin_from_end = mmap.end();
	multimap<string, List*>::iterator iter = mmap.begin();
	do{ 
		begin_from_end--;
		cout << begin_from_end->first << ":" << begin_from_end->second << endl;

	} while ( begin_from_end != iter);

	cout << "_________��������� �� ����������� � ������� �-�� �������_______" << endl;

	lst.sort(sort_function_vosrast);
	for (auto el : lst)
	{
		cout << endl << el << endl;
	}
	list<List*>::iterator for_k = lst.begin();

	int k;

	cout << "������� k: "; cin >> k;

	for (int i = 1; i < k; i++)
	{
		for_k++;
	}

	cout << "���������� �-�� ��������: " << endl << *for_k << endl;
	cout << "_________���������� ��� ����������_______" << endl;

	deque<List*> deq;
	for (auto it2 = lst.begin(); it2 != lst.end(); it2++) {
		deq.push_back(*it2);
	}
	for (auto it3 = mmap.begin(); it3 != mmap.end(); it3++) {
		deq.push_back(it3->second);
	}
	for (auto el : deq)
	{
		cout << endl << el << endl;
	}
	cout << "________���������� �������� � ����� �� ����������________" << endl;
	
	int kol_in_deq = 0;

	while (true) {
		kol_in_deq = 0;
		cout << "�������� �������� �������(��� ����� 0 ���� ������������): "; cin >> val;
		if (val == 0)
			break;
		deque<List*>::iterator for_2 = deq.begin();
		while (for_2 != deq.end())
		{
			for_2 = find_if(for_2, deq.end(), [&](List* object) {return object->showFirst() == val; });
			if (for_2 != deq.end())
			{
				kol_in_deq++;
				for_2++;
			}
		}
		cout << kol_in_deq << "\n";
	}

	cout << "_______string_________" << endl;

	string s_param("lococb");
	string copyr(s_param);
	string bez_param;
	string s_ciklom(5, 'H');

	cout << "��� ����������: " << 
		bez_param << endl
		<< "� �����������: " << 
		s_param << endl 
		<< "�����������: " <<
		copyr << endl 
		<< "� ������������� ���������: " << 
		s_ciklom << endl;

	cout << typeid(s_param.c_str()).name() << endl;
	if (bez_param.empty())
		cout << "����" << endl;
	cout << "����� copyr " << copyr.size() << endl;

	cout << "_______������ �������_________" << endl;

	struct FirstFunk
	{
		void operator() (list<List*> obj)
		{
			for(auto itr = obj.begin(); itr != obj.end(); itr++)
			cout << *itr << endl;
		}
	}showAll;
	//
	showAll(lst);

	list<List*> lst2;
	List* element5 = new List; element5->add(5);
	list<List*>::iterator head = lst2.begin();
	lst2.insert(head,element5);
	lst2.insert(head, element1);
	cout << "_______������ �������_________" << endl;

	struct SecondFunk
	{
		bool operator() (list<List*> obj, list<List*> obj2)
		{
			list<List*>::iterator it = obj.begin();
			list<List*>::iterator it2 = obj2.begin();
			bool answer = true;

			for (; it != obj.end() && it2 != obj2.end(); it++, it2++) {
				if (*it != *it2)
					answer = false;
				
			}
			return answer;
		}
	}Compare;
	
	cout << "��������� �������: " << Compare(lst, lst);

}


