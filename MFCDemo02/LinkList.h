#pragma once
#define T int
class LinkList
{
private:
	typedef struct {
		T data;
		T *next;
	}LNode;
	LNode *head;
public:
	LinkList();
	~LinkList();

	bool insertData(int loca,T m);
	bool insertHead(T m);
	bool insertTail(T m);

	bool deleteData(int i,T &e);
	bool deleteData(int i);
	bool deleteHead(T &e);
	bool deleteHead();
	bool deleteTail(T &e);
	bool deleteTail();

};

