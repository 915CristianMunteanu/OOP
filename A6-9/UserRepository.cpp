#include "UserRepository.h"


UserException::UserException(std::string& _message) : message(_message) {}

const char* UserException::what() const noexcept {
    return message.c_str();
}



UserRepository::UserRepository()
{
}

void UserRepository::add_movie_to_watchlist(const Movie & new_movie)
{
	if (find_movie_by_title(new_movie.get_title()) == Movie()) {
		this->watchlist.insert(watchlist.begin(), new_movie);
	}
	else {
		string error;
		error += string("The movie already exists!");
		throw UserException(error);
	}
}

void UserRepository::remove_movie_from_watchlist(std::string title)
{
	if (find_movie_by_title(title) == Movie()) {
		string error;
		error += string("The movie doesnt exists!");
		throw UserException(error);
	}
	else {
		
		this->watchlist.erase(watchlist.begin() + return_index_of_movie(title));
	}
}

vector<Movie> UserRepository::get_elements_from_watchlist()
{

	return watchlist;
}

int UserRepository::return_length_of_watchlist()
{
	return watchlist.size();
}

Movie UserRepository::find_movie_by_title(std::string title)
{
	for (auto i = watchlist.begin(); i != watchlist.end(); ++i) {
		Movie m = *i;
		if (m.get_title() == title)
			return m;
	}
	return Movie();
}

int UserRepository::return_index_of_movie(std::string title)
{
	int counter = 0;
	for (auto i = watchlist.begin(); i != watchlist.end(); ++i) {
		Movie m = *i;
		if (m.get_title() == title)
			return counter;
		counter += 1;
	}
	return -1;
}

string UserRepository::getFileName()
{
	return string();
}
