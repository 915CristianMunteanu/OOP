//
// Created by munte on 06.03.2022.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#endif
#include "Repository.h"
#include "../DOMAIN/Estate.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
Repository* create_repository(){
    Repository* repository=(Repository*)malloc(sizeof (Repository));
    if(repository==NULL){
        return NULL;
    }
    repository->length=0;
    return repository;
}
void destroy_repository(Repository* repository){
    if(repository==NULL)
        return;
    for(int i=0;i<repository->length;i++){
        destroy_estate(repository->list_of_estates[i]);
    }
    free(repository);
}
Estate* find_estate(Repository* repository,Estate* estate){
    for(int i=0;i<repository->length;i++){
        if(strcmp(estate->address,repository->list_of_estates[i]->address)==0)
            return repository->list_of_estates[i];
    }
    return NULL;
}
int find_estate_by_address(Repository* repository,char* address){
    for(int i=0;i<repository->length;i++){
        if(strcmp(address,repository->list_of_estates[i]->address)==0)
            return i;
    }
    return -1;
}
int add(Repository* repository, Estate* estate){
    if(find_estate(repository,estate)!=NULL)
        return 0;
    repository->list_of_estates[repository->length]=estate;
    repository->length+=1;
    return 1;
}
int removee(Repository* repository, char* address){
    int index=find_estate_by_address(repository,address);
    if(index==-1)
        return 0;
    destroy_estate(repository->list_of_estates[index]);
    for (int i=index;i<repository->length-1;i++)
        repository->list_of_estates[i]=repository->list_of_estates[i+1];
    repository->length-=1;
    return 1;
}
int update(Repository* repository,char* type, char* address, int price, int surface){
    int index= find_estate_by_address(repository,address);
    if (index==-1)
        return 0;
    strcpy(repository->list_of_estates[index]->type,type);
    repository->list_of_estates[index]->price=price;
    repository->list_of_estates[index]->surface=surface;
    return 1;
}
void sort_list_of_estates(Repository* repository){
    for (int i=0;i<repository->length;i++){
        for (int j=0;j< repository->length-i-1;j++){
            if(repository->list_of_estates[j]->price > repository->list_of_estates[j+1]->price){
                Estate* aux=repository->list_of_estates[j];
                repository->list_of_estates[j]=repository->list_of_estates[j+1];
                repository->list_of_estates[j+1]=aux;
            }
        }
    }
}
Estate** return_list(Repository* repository){
    sort_list_of_estates(repository);
    return repository->list_of_estates;
}
int return_length(Repository* repository){
    return repository->length;
}

void return_filter_list(Repository* repository,char* type_sub, Estate** filtered_list){
    sort_list_of_estates(repository);
    int length=0;
    for(int i=0;i<repository->length;i++){
        if(strstr(repository->list_of_estates[i]->address,type_sub)) {
            filtered_list[length] = repository->list_of_estates[i];
            length += 1;
        }
    }
}
int return_filter_length(Repository* repository,char* type_sub){
    Estate* filtered_list[100];
    int length=0;
    for(int i=0;i<repository->length;i++){
        if(strstr(repository->list_of_estates[i]->address,type_sub)) {

            length += 1;
        }
    }
    return length;
}
Estate* return_estate_by_address(Repository* repository,char* address){
    for(int i=0;i<repository->length;i++){
        if(strcmp(address,repository->list_of_estates[i]->address)==0)
            return repository->list_of_estates[i];
    }
    return NULL;
}
void test_add(){
    Repository* repo=create_repository();
    Estate* estate= create_estate("House","Caisului,2",100000,120);
    add(repo,estate);
    assert(return_length(repo)==1);
    Estate* estate_1= create_estate("House","Caisului,12",90000,140);
    add(repo,estate_1);
    assert(return_length(repo)==2);
    assert(add(repo,estate)==0);
    destroy_repository(repo);
}
void test_remove(){
    Repository* repo=create_repository();
    Estate* estate= create_estate("House","Caisului,2",100000,120);
    Estate* estate_1= create_estate("House","Caisului,12",90000,140);
    add(repo,estate);
    add(repo,estate_1);
    removee(repo,"Caisului,12");
    assert(return_length(repo)==1);
    assert(removee(repo,"Caisului,12")==0);
    destroy_repository(repo);
}
void test_update(){
    Repository* repo=create_repository();
    Estate* estate= create_estate("House","Caisului,2",100000,120);
    Estate* estate_1= create_estate("House","Caisului,12",90000,140);
    add(repo,estate);
    add(repo,estate_1);
    int index= find_estate_by_address(repo,"Caisului,2");
    update(repo,"Apartament","Caisului,2",12,300);
    assert(repo->list_of_estates[index]->price==12);
    assert(repo->list_of_estates[index]->surface==300);
    assert(strcmp("Apartament",repo->list_of_estates[index]->type)==0);
    assert(strcmp("Caisului,2",repo->list_of_estates[index]->type)==0);
    destroy_repository(repo);

}
void tests_repository(){
    test_add();
    test_remove();
    test_update();
}