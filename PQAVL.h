#if !defined PQAVL_H
#define PQAVL_H
#include "AVLTree.h"

template < class T >
class PQAVL
{
private:
	AVLTree<T>* avl;
	bool min_or_max;
	int (*compare_item)(T* one, T* two);
	int (*compare_key)(String* sk, T* one);

public:
	PQAVL(bool min_or_max, int (*compare_item) (T* item_1, T* item_2), int (*compare_key)(String* sk, T* one));
	~PQAVL();
	bool pqIsEmpty();
	void pqInsert(T* item);
	T* pqRemove();
};

template < class T >
PQAVL<T>::PQAVL(bool min_or_max, int (*compare_item) (T* item_1, T* item_2), int (*compare_key)(String* sk, T* one))
{
	min_or_max = min_or_max;
	compare_item = compare_item;
	compare_key = compare_key;
	avl = new AVLTree<T>*(min_or_max, false, true, compare_item, compare_key);
}

template < class T >
PQAVL<T>::~PQAVL()
{
	delete avl;
}

template < class T >
bool PQAVL<T>::pqIsEmpty()
{
	return avl->IsEmpty();
}

template < class T >
void PQAVL<T>::pqInsert(T* item)
{
	avly->insert(item);
}

template < class T >
T* PQAVL<T>::pqRemove()
{
	T* item = avl->remove();
	return item;
}


#endif