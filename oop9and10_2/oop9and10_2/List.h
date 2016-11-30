#pragma once

class List{
	public:
	List* head;
	int element;
	List* next;

	List(){head = NULL;}

	void add(int v);
	void show();
	bool IsEmpty();

	friend std::ostream& operator<<(std::ostream&, List*);
	void operator --();	 
	void operator +(List &);
	bool operator ==(List &);
	
	int showFirst();
};

