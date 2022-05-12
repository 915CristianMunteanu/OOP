#pragma once
#include "Service.h"
#include "Movie.h"
#include "../../../source/repos/Project1/Project1/UserService.h"
#include "../../../source/repos/Project1/Project1/Validators.h"
class UI {
	Service& service;
	UserService& user_service;
	Validator& val;
public:
	UI(Service& service,UserService& user_service,Validator& val);
	void print_menu();
	void start_UI();
	int read_command();
	void print_movies();
	void add_movie();
	void remove_movie();
	void update_movie();
	void print_deleted_movies();
	void start_user_mode();
	void go_through_filtered_movies(std::string genre);
	void open_watchlist();
};