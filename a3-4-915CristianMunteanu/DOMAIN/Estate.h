//
// Created by munte on 06.03.2022.
//

#ifndef A3_4_915CRISTIANMUNTEANU_ESTATE_H
#define A3_4_915CRISTIANMUNTEANU_ESTATE_H


typedef struct {
    char* type;
    char* address;
    int price, surface;
} Estate;
typedef struct {
    char* type;
    Estate* e;
} Operation;

Operation* createOperation(char* type, Estate* e);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* op);
char* getOpType(Operation* o);
Estate * getOpObject(Operation* o);
Estate* create_estate(char* type, char* address, int surface, int price);
void destroy_estate(Estate* estate);
char* get_type(Estate* estate);
char* get_address(Estate* estate);
int get_price(Estate* estate);
int get_surface(Estate* estate);
void set_type(Estate* estate, char* new_type);
void set_address(Estate* estate, char* new_address);
void set_price(Estate* estate,int price);
void set_surface(Estate* estate,int surface);
Estate* copy_estate(Estate* estate);

typedef void* TElement;
typedef void (*DestroyElementFunctionType)(void*);

typedef struct
{
    TElement* elems;
    int length;			// actual length of the array
    int capacity;		// maximum capacity of the array
    DestroyElementFunctionType destroyElemFct; // function pointer to the function responsible with deallocating the elements stored in the array
} DynamicArrayv2;

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <param name="destroyElemFct">Function pointer, of type DestroyElementFunctionType. The function that deals with deallocating the elements of the array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArrayv2* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct);

/// <summary>
/// Destroys the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array to be destoyed.</param>
/// <returns>A pointer the the created dynamic array.</returns>
void destroy(DynamicArrayv2* arr);

/// <summary>
/// Adds a generic to the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="p">The planet to be added.</param>
void add_to_array(DynamicArrayv2* arr, TElement t);

/// <summary>
/// Deletes an element from a given position in the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="pos">The position from which the element must be deleted. The position must be valid.</param>
void delete(DynamicArrayv2* arr, int pos);

/// <summary>
/// Returns the length of the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
int getLength(DynamicArrayv2* arr);

/// <summary>
/// Returns the element on a given position.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="pos">The position - must be a valid position.</param>
/// <returns>The element on the given position.</returns>
TElement get(DynamicArrayv2* arr, int pos);
#endif //A3_4_915CRISTIANMUNTEANU_ESTATE_H