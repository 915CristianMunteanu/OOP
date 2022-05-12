#pragma once
#include "Movie.h"
#include "../../../source/repos/Project1/Project1/Template.h"
#include <vector>
#include <iostream>
using namespace std;
class RepositoryException : public std::exception {
private:
	std::string message;
public:
	explicit RepositoryException(std::string& _message);

	const char* what() const noexcept override;
};
class Repository {
private:
	vector<Movie> arr;
	vector<Movie> list_of_deleted_movies;
	string filename;
public:
	Repository(string filename);
	vector<Movie> get_elements() const;
	void load_from_file();
	void write_to_file();
	void init();
	void add_movie(const Movie& new_movie);
	void remove_movie(std::string title);
	void update_movie(std::string title, std::string genre, int year_of_release, int number_of_likes, std::string link);
	Movie find_movie_by_title(std::string title);
	int return_index_of_movie(std::string title);
	int return_length();
	vector<Movie> return_array();
	vector<Movie> return_deleted_array();
	int return_length_of_deleted_array();
	Movie* return_address(std::string title);
};