#include "Service.h"

Service::Service(Repository& repo):repo(repo)
{
}

void Service::add(std::string title, std::string genre, int year_of_release, int number_of_likes, std::string link)

{
	Movie new_movie(title, genre, year_of_release, number_of_likes, link);
	
	repo.add_movie(new_movie);
}

void Service::remove(std::string title)
{
	repo.remove_movie(title);
}

void Service::update(std::string title, std::string genre, int year_of_release, int number_of_likes, std::string link)
{
	repo.update_movie(title,genre,year_of_release,number_of_likes,link);
}

int Service::return_length()
{
	return this->repo.return_length();
}

vector<Movie> Service::return_array()
{
	return this->repo.return_array();
}

int Service::return_length_of_deleted_movies()
{
	return this->repo.return_length_of_deleted_array();
}

vector<Movie> Service::return_list_of_deleted_movies()
{
	return this->repo.return_deleted_array();
}

void Service::add_movie_to_watchlist(const Movie& new_movie)
{
	if (find_movie_by_title(new_movie.get_title()) == Movie()) {
		this->watchlist.insert(watchlist.begin(),new_movie);
		
	}
	else {
		string error;
		error += string("The movie already exists!");
		throw ServiceException(error);
	}
}

Movie Service::find_movie_by_title(std::string title)
{
	int size = watchlist.size();
	for (auto i = watchlist.begin(); i != watchlist.end(); ++i) {
		Movie m = *i;
		if (m.get_title() == title)
			return m;
	}
	return Movie();

}

int Service::return_index_of_movie(std::string title)
{
	int counter = 0;
	for (auto i = watchlist.begin(); i != watchlist.end(); i++) {
		Movie m = *i;
		if (m.get_title() == title)
			return counter;
		counter += 1;
	}
	return -1;
}

int Service::return_length_of_watchlist()
{
	return watchlist.size();
}

vector<Movie> Service::return_watchlist()
{
	return watchlist;
}

void Service::remove_movie_from_watchlist(std::string title)
{

	if (find_movie_by_title(title) == Movie()) {
		string error;
		error += string("The movie doesnt exists!");
		throw ServiceException(error);
	}
	else {
		this->watchlist.erase(watchlist.begin()+return_index_of_movie(title));
		
	}
}

ServiceException::ServiceException(std::string& _message):message(_message)
{
}

const char* ServiceException::what() const noexcept
{
	return message.c_str();
}
