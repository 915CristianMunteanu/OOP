//
// Created by munte on 06.03.2022.
//

#ifndef A3_4_915CRISTIANMUNTEANU_REPOSITORY_H
#define A3_4_915CRISTIANMUNTEANU_REPOSITORY_H


#include "Repository.h"
#include "../DOMAIN/Estate.h"
typedef struct{
    Estate* list_of_estates[100];
    int length;
}Repository;
Repository* create_repository();
/// This function creates the repository
/// \param repository object of struct Repository
/// \param estate object of struct Estate
/// \return Returns the Repository created.
Estate* find_estate(Repository* repository,Estate* estate);
/// The function returns the Estate if it is found, and NULL if nothing was found.
/// \param repository object of struct Repository
/// \param estate object of struct Estate
/// \return
int add(Repository* repository, Estate* estate);
/// The function is searching for the estate given in the list. If it finds one, then returns 0.
/// If it doesnt find the estate, it is added at the end of the list, then 1 is returned.
/// \param repository
void destroy_repository(Repository* repository);
/// Frees the memory
/// \param repository
/// \param address
/// \return
int removee(Repository* repository, char* address);
/// The function is searching for the estate given in the list. If it doesnt find one, then returns 0.
/// If the estate is found, then it is deleted from the list, then 1 is returned.
int find_estate_by_address(Repository* repository,char* address);
/// This function is used to parse the list and get the exact index of the estate with the given address.
/// If the address is found, then the index is returned. Otherwise -1 is returned.
/// \param repository object of struct Repository

int update(Repository* repository,char* type, char* address, int price, int surface);
/// This function returns 1 if a update was, made, if the address was found, 0 otherwise.
/// \param repository object of struct Repository
/// \param type string
/// \param address string
/// \param price int
/// \param surface int
/// \return
Estate* return_estate_by_address(Repository* repository,char* address);

/// This function just sorts the list in ascending order after the price
/// \param repository
void sort_list_of_estates(Repository* repository);
/// This is a function that returns the current state of the list.
/// \param repository
/// \return
Estate** return_list(Repository* repository);
/// This is a function that returns the current length of the list
/// \param repository
/// \return
int return_length(Repository* repository);
/// Filters the list_of_estates into the filtered_list, by the type_sub string.
/// \param repository object of struct Repository
/// \param type_sub string
/// \param filtered_list list of estates.
void return_filter_list(Repository* repository,char* type_sub, Estate** filtered_list);
/// Returns the length of the filtered list.
/// \param repository object of struct Repository
/// \param type_sub string
/// \return returns an int value.
int return_filter_length(Repository* repository,char* type_sub);
#endif //A3_4_915CRISTIANMUNTEANU_REPOSITORY_H
