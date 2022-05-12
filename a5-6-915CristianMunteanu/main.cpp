#pragma once
#include <iostream>
#include "UI.h"
#include "Repository.h"
#include "Service.h"
#include "../../../source/repos/Project1/Project1/Tests.h"

int main()
{
    //Tests::test_all();
    string filename = R"(C:\Users\munte\source\repos\Project1\Project1\movies.txt)";
    Repository repo{filename};
    UserRepository* user_repo=new UserRepository;
    repo.init();
    Service service{ repo };
    Validator val;
    UserService user_service {repo, user_repo };
    UI ui{ service,user_service,val };
    ui.start_UI();
    return 0;
}
