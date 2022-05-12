#include "Repository.h"
#include <fstream>
#include <algorithm>
Repository::Repository(string filename): filename(filename)
{
}

vector<Movie> Repository::get_elements() const
{

	return this->arr;
}

void Repository::load_from_file()
{
	if (!filename.empty()) {
		Movie movie_from_file;
		std::ifstream fin(filename);
		while (fin >> movie_from_file) {
			if (find(this->arr.begin(), this->arr.end(), movie_from_file) == this->arr.end())
				this->arr.push_back(movie_from_file);
			
		}
		fin.close();
	}
}

void Repository::write_to_file()
{
	if (!filename.empty()) {
		std::ofstream fout(filename);
		for (const Movie& movie : this->arr) {
			fout << movie << '\n';
		}
		fout.close();
	}
}

void Repository::init()
{
	load_from_file();
}

void Repository::add_movie(const Movie& new_movie)
{
	if (find_movie_by_title(new_movie.get_title()) == Movie()) {
		this->arr.insert(arr.begin(), new_movie);
		write_to_file();
	}
	else {
		string error;
		error += string("The movie already exists!");
		throw RepositoryException(error);
	}
}

void Repository::remove_movie(std::string title)
{

	if (find_movie_by_title(title) == Movie()) {
		string error;
		error += string("The movie doesnt exists!");
		throw RepositoryException(error);
	}
	else {
		this->list_of_deleted_movies.insert(list_of_deleted_movies.begin(), find_movie_by_title(title));
		this->arr.erase(arr.begin()+return_index_of_movie(title));
		write_to_file();
	}
}

void Repository::update_movie(std::string title, std::string genre, int year_of_release, int number_of_likes, std::string link)
{

	if (find_movie_by_title(title) == Movie()) {
		string error;
		error += string("The movie doesnt exists!");
		throw RepositoryException(error);
	}
	else {
		int index = return_index_of_movie(title);
		arr[index].set_genre(genre);
		arr[index].set_year_of_release(year_of_release);
		arr[index].set_number_of_likes(number_of_likes);
		arr[index].set_link(link);
	}
}

Movie Repository::find_movie_by_title(std::string title)
{
	for (auto i = arr.begin(); i != arr.end(); ++i) {
		Movie m = *i;
		if (m.get_title() == title)
			return m;
	}
	return Movie();
}

int Repository::return_index_of_movie(std::string title)
{
	int counter = 0;
	for (auto i = arr.begin(); i != arr.end(); ++i) {
		Movie m = *i;
		if (m.get_title() == title)
			return counter;
		counter += 1;
	}
	return -1;
}

int Repository::return_length()
{
	return this->arr.size();
}

vector<Movie> Repository::return_array()
{
	return this->arr;
}

vector<Movie> Repository::return_deleted_array()
{
	return this->list_of_deleted_movies;
}

int Repository::return_length_of_deleted_array()
{
	return this->list_of_deleted_movies.size();
}

Movie* Repository::return_address(std::string title)
{
	for (auto i = arr.begin(); i != arr.end(); ++i) {
		Movie m = *i;
		if (m.get_title() == title)
			return &m;
	}
	return NULL;
}

RepositoryException::RepositoryException(std::string& _message):message(_message)
{
}

const char* RepositoryException::what() const noexcept
{
	return message.c_str();
}
