#include <stdlib.h>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
 
#define PAGE_SIZE 256

struct Element
{
    int value;
    Element *prev = nullptr;
    Element *next = nullptr;
};

extern stack<set<Element *>> occupancy; 

extern struct Element *my_memory;
extern int memeory_length;
extern int page_count;
extern int max_page;

extern set<Element *> free_pages;

void createMem(int size);

Element *createList(int length, Element *&listName);

int assignVal(Element *listName, int offset, int value);

Element *accessElem(Element *listName, int offset);

void freeElem(Element *listName=nullptr);

void funcinit();