#pragma once
#include "Repository.h"
#include <vector>
#include <iostream>
using namespace std;
class ServiceException : public std::exception {
private:
	std::string message;
public:
	explicit ServiceException(std::string& _message);

	const char* what() const noexcept override;
};
class Service {
	Repository& repo;
	vector<Movie> watchlist;
public:
	Service(Repository& repo);
	void add(std::string title, std::string genre, int year_of_release, int number_of_likes, std::string link);
	void remove(std::string title);
	void update(std::string title, std::string genre, int year_of_release, int number_of_likes, std::string link);
	int return_length();
	vector<Movie> return_array();
	int return_length_of_deleted_movies();
	vector<Movie> return_list_of_deleted_movies();
	void add_movie_to_watchlist(const Movie& new_movie);
	Movie find_movie_by_title(std::string title);
	int return_index_of_movie(std::string title);
	int return_length_of_watchlist();
	vector<Movie> return_watchlist();
	void remove_movie_from_watchlist(std::string title);

};