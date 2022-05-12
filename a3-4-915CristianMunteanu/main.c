//
// Created by munte on 06.03.2022.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#endif

#include "REPOSITORY/Repository.h"
#include "SERVICE/Controller.h"
#include "UI/UI.h"
int main(){
    Repository* repo=create_repository();
    Controller * controller= create_controller(repo);
    UI* ui= create_UI(controller);
    start_UI(ui);
    destroy_UI(ui);
    //_CrtDumpMemoryLeaks();
    return 0;
}