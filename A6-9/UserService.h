#pragma once
#include "../../../../Documents/GitHub/a5-6-915CristianMunteanu/Repository.h"
#include "UserRepository.h"

class UserService {
private:
	Repository& repo;
	UserRepository* user_repo;
public:
	UserService(Repository& repo, UserRepository* user_repo);
	vector<Movie> get_all();
	int get_elems();
	void add_user_service(const Movie& m);
	void delete_user_service(const string title);
	string& get_file();
	void fileType(string fileType);
	string get_file_name();
};