#include "UserService.h"
#include "RepositoryCSV.h"
#include "HTMLRepository.h"
UserService::UserService(Repository& repo, UserRepository* user_repo):repo(repo){
	this->user_repo = user_repo;
}



vector<Movie> UserService::get_all()
{
	if (this->user_repo->return_length_of_watchlist() == 0) {
		string error;
		error += string("The watchlist is empty");
		throw UserException(error);
	}
	else
		return user_repo->get_elements_from_watchlist();
}

int UserService::get_elems()
{
	if (this->user_repo->return_length_of_watchlist() == 0) {
		string error;
		error += string("The watchlist is empty");
		throw UserException(error);
	}
	else
		return this->user_repo->return_length_of_watchlist();
}


void UserService::add_user_service(const Movie& m)
{
	user_repo->add_movie_to_watchlist(m);
}

void UserService::delete_user_service(const string title)
{
	user_repo->remove_movie_from_watchlist(title);
}

string& UserService::get_file()
{
	string error;
	error += string("Ceva");
	return error;
}

void UserService::fileType(string fileType)
{
	if (fileType == "csv") {
		string userFile = R"(C:\Users\munte\source\repos\Project1\Project1\watchlist.csv)";
		vector<Movie> watchlist;
		auto * repo1 = new RepositoryCSV{ watchlist,userFile };
		this->user_repo = repo1;
	}
	else if (fileType == "html") {
		string userFile = R"(C:\Users\munte\source\repos\Project1\Project1\watchlist.html)";
		vector<Movie> watchlist;
		auto* repo2 = new HTMLRepository{ watchlist,userFile };
		this->user_repo = repo2;
	}
}

string UserService::get_file_name()
{
	return this->user_repo->getFileName();
}
