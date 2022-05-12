#pragma once
#include "Movie.h"
typedef Movie TElement;
class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;
public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& v);
	~DynamicVector();
	DynamicVector& operator=(const DynamicVector& v);
	void add(const TElement& e);
	void remove(int index);
	int getSize() const;
	TElement* getAllElems() const;
private:
	void resize(double factor = 2);
};