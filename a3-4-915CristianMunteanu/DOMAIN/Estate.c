//
// Created by munte on 06.03.2022.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#endif
#include "Estate.h"
#include <stdlib.h>
#include <string.h>

Operation* createOperation( char* type, Estate * e) {
    Operation* op = malloc(sizeof(Operation));
    op->type = (char*)malloc(sizeof(char) * 7);
    strcpy(op->type,type);

    Estate * copy = copy_estate(e);
    op->e = copy;

    return op;
}
Operation* copyOperation(Operation* op) {
    if (op == NULL)
        return NULL;
    return createOperation(getOpType(op), getOpObject(op));
}
void destroyOperation(Operation* o) {
    if (o == NULL)
        return;
    destroy_estate(o->e);
    free(o->type);

    free(o);
}

char* getOpType(Operation* o) {
    if (o == NULL)
        return "0";
    return o->type;
}

Estate * getOpObject(Operation* o) {
    if (o == NULL)
        return NULL;
    return o->e;
}

Estate* create_estate(char* type, char* address, int surface, int price){
    Estate* estate=(Estate*)malloc(sizeof(Estate));
    estate ->type=(char*)malloc(sizeof (char)*(strlen(type)+1));
    strcpy(estate->type,type);
    estate ->address=(char*) malloc(sizeof (char)*(strlen(address)+1));
    strcpy(estate->address,address);
    estate->surface=surface;
    estate->price=price;

    return estate;

}

void destroy_estate(Estate* estate){
    free(estate->address);
    free(estate->type);
    free(estate);
}
char* get_type(Estate* estate){
    return estate->type;
}
char* get_address(Estate* estate){
    return estate->address;
}
int get_price(Estate* estate){
    return estate->price;
}
int get_surface(Estate* estate){
    return estate->surface;
}
void set_type(Estate* estate, char* new_type){
    free(estate->type);
    estate->type=(char*)malloc(sizeof (char)*(strlen(new_type)+1));
    strcpy(estate->type,new_type);
}
void set_address(Estate* estate, char* new_address){
    free(estate->address);
    estate->address=(char*)malloc(sizeof (char)*(strlen(new_address)+1));
    strcpy(estate->address,new_address);
}
void set_price(Estate* estate,int new_price){
    estate->price=new_price;
}
void set_surface(Estate* estate,int new_surface){
    estate->surface=new_surface;
}
Estate* copy_estate(Estate* estate){
    if(estate==NULL)
        return NULL;

    return create_estate(estate->type,estate->address,estate->surface,estate->price);
}

DynamicArrayv2* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct)
{
    DynamicArrayv2* da = (DynamicArrayv2*)malloc(sizeof(DynamicArrayv2));
    // make sure that the space was allocated
    if (da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;

    // allocate space for the elements
    da->elems = (TElement*)malloc(capacity * sizeof(TElement));
    if (da->elems == NULL)
        return NULL;

    // initialize the function pointer
    da->destroyElemFct = destroyElemFct;

    return da;
}

void destroy(DynamicArrayv2* arr)
{
    if (arr == NULL)
        return;

    // deallocate each of the elements - if we decide that the dynamic array is responsible with this
    for (int i = 0; i < arr->length; i++)
        arr->destroyElemFct(arr->elems[i]);

    // free the space allocated for the elements
    free(arr->elems);
    arr->elems = NULL;

    // free the space allocated for the dynamic array
    free(arr);
    arr = NULL;
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArrayv2* arr)
{
    if (arr == NULL)
        return -1;

    arr->capacity *= 2;

    // version 1 - using realloc
    //TElement* aux = (TElement*)realloc(arr->elems, arr->capacity * sizeof(TElement));
    //if (aux == NULL)
    //	return - 1;
    //arr->elems = aux;

    // version 2 - allocate new memory, copy everything and deallocate the old memory
    TElement* aux = (TElement*)malloc(arr->capacity * sizeof(TElement));
    if (aux == NULL)
        return -1;
    for (int i = 0; i < arr->length; i++)
        aux[i] = arr->elems[i];
    free(arr->elems);
    arr->elems = aux;

    return 0;
}

void add_to_array(DynamicArrayv2* arr, TElement t)
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;

    // resize the array, if necessary
    if (arr->length == arr->capacity)
        resize(arr);
    arr->elems[arr->length++] = t;
}

void delete(DynamicArrayv2* arr, int pos)
{
    if (arr == NULL || pos < 0 || pos >= arr->length)
        return;

    arr->destroyElemFct(arr->elems[pos]);

    if (pos != arr->length - 1)
        arr->elems[pos] = arr->elems[arr->length - 1];
    arr->length--;

}

int getLength(DynamicArrayv2* arr)
{
    if (arr == NULL)
        return -1;

    return arr->length;
}

TElement get(DynamicArrayv2* arr, int pos)
{
    if (arr == NULL || pos < 0)
        return NULL;
    return arr->elems[pos];
}

// ------------------------------------------------------------------------------------------------------------