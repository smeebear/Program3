#include "PQAVL.h"
#include "CD.h"
using CSC1310::CD;
#include "ListArray.h"
using CSC1310::ListArray;

#include <iostream>
using namespace std;

enum MINMAX {max = 0, min}
enum DUPES {no = 0, yes}

int main()
{
	ListArray<CD>* cds = CD::readCDs("cds.txt");
	CD** CDArray = cds->toArray();
	int size = cds->size();

	bool min_or_max;
	bool allow_dupes;
	bool dupes_on_left;

	cout << "Would you like to sort by max or min? : ";
	cin >> min_or_max;

	cout << "Would you like to allow dupes? (yes/no) : ";
	cin >> allow_dupes;

	cout << "Would you like to place dupes on left? If no dupes, enter 'yes' : ";
	cin >> dupes_on_left;


	PQSort<CD>* pqSort = new PQSort<CD>(CDArray, size, min_or_max, &CD::compare_item, &CD::compare_keys);

	CD** sortedCDs = pqSort->pqSort();

	for (int i = 0; i < size; i++)
	{
		sortedCDs[i]->displayCD();
	}
	
	return 0;
}