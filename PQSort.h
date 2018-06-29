#if !defined PQSORT_H
#define PQSORT_H

#include "PQAVL.h"

template < class T >
class PQSort
{
private:
	T** items;
	int numItems;
	bool min_or_max;
	int (*compare_item)(T* one, T* two);
	int (*compare_key)(String* sk, T* one);

	static void _pqSort(T** items, int num_items, bool min_or_max, int (*compare_item) (T* one, T* two), int (*compare_key)(String* sk, T* one));

public:
	PQSort(T** items, int num_items, bool min_or_max, int (*compare_item) (T* one, T* two), int (*compare_key)(String* sk, T* one));
	~PQSort();
	static T** pqSort(T** items, int num_items, bool min_or_max, int (*compare_item) (T* one, T* two), int (*compare_key)(String* sk, T* one));


};

template < class T >
PQSort<T>::PQSort(T** items, int num_items, bool min_or_max, int (*compare_item) (T* one, T* two), int (*compare_key)(String* sk, T* one))
{
	items = items;
	numItems = num_items;
	min_or_max = min_or_max;
	compare_item = compare_item;
	compare_key = compare_key;
}

template < class T >
PQSort<T>::~PQSort()
{

}

template < class T >
static T** PQSort<T>::pqSort(T** items, int num_items, bool min_or_max, bool allow_dupes, bool dupes_on_left, int (*compare_item) (T* one, T* two), int (*compare_key)(String* sk, T* one))
{
	_pqSort(items, num_items, min_or_max, allow_dupes, dupes_on_left, compare_item, compare_key);
	return items;
}

template < class T >
static void PQSort<T>::_pqSort(T** items, int num_items, bool min_or_max, bool allow_dupes, bool dupes_on_left, int (*compare_item) (T* one, T* two), int (*compare_key)(String* sk, T* one))
{
	PQAVL<T>* pqAVL = new PQAVL<T>(min_or_max, allow_dupes, dupes_on_left, compare_item, compare_key);

	for (int i = 0; i < num_items; i++)
	{
		pqAVL->pqInsert(items[i]);
	}

	for int j = 0; j < num_items; j++)
	{
		items[j] = pqAVL->pqRemove();
	}
}

#endif