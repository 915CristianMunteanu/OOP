#include "UI.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

UI::UI(Service& service,UserService& user_service,Validator& val):service(service),user_service(user_service),val(val)
{
}

void UI::print_menu()
{
	cout << " 1 - print all the movies\n";
	cout << " 2 - add a movie\n";
	cout << " 3 - remove a movie\n";
	cout << " 4 - update a movie\n";
	cout << " 5 - print the deleted movies\n";
	cout << " 0 - Exit\n";
}

void UI::start_UI()
{
	cout << "What is the mode of the app?" << endl;
	cout << "1 - Administrator mode" << endl;
	cout << "2 - User mode" << endl;
	int mode;
	cin >> mode;
	if (mode == 2)
		start_user_mode();
	else {
		while (1) {
			this->print_menu();
			int command = this->read_command();
			if (command == 1) {
				this->print_movies();
			}
			if (command == 0)
				break;
			if (command == 2)
				this->add_movie();
			if (command == 3)
				this->remove_movie();
			if (command == 4)
				this->update_movie();
			if (command == 5)
				this->print_deleted_movies();
		}
	}


}

int UI::read_command()
{
	int command;
	cout << "What do you want to do?";
	cin >> command;

	return command;
}

void UI::print_movies()
{
	vector<Movie> movies = this->service.return_array();
	for (auto it = movies.begin(); it !=movies.end(); ++it) {
		Movie m = *it;
		cout << m.get_title() << " " << m.get_genre() << " " << m.get_year_of_release() << " " << m.get_number_of_likes() << " " <<m.get_link();
		cout << endl;
	}
}

void UI::add_movie()
{
	string title, genre, link,year,likes;
	
	cout << "Whats the title of the movie that you want to add?";
	cin.get();
	getline(cin, title);

	cout << "Whats the genre of the movie that you want to add?";
	getline(cin, genre);

	cout << "Whats the year of release of the movie that you want to add?" ;
	getline(cin, year);
	cout << "Whats the number of likes of the movie that you want to add?" ;
	getline(cin, likes);
	cout << "Whats the link of the trailer of the movie that you want to add?";
	cin.get();
	getline(cin, link);
	try {
		val.validate_number(likes);
		val.validate_year(year);
		int like = stoi(likes);
		int years = stoi(year);
		val.validate_number_int(like);
		val.validate_year_int(years);
		try {
			this->service.add(title, genre, years, like, link);
		}
		catch (RepositoryException& er) {
			cout << er.what() << endl;
		}
	}
	catch (ValidationException& er) {
		cout << er.what() << endl;
		return;
	}
	
	
	
}

void UI::remove_movie()
{
	string title;
	cout << "Whats the title of the movie that you want to remove? ";
	cin.get();
	getline(cin,title);
	try {
		this->service.remove(title);
	}
	catch (RepositoryException& er) {
		cout << er.what() << endl;
	}
}

void UI::update_movie()
{
	string title, genre, link, year, likes;
	cout << "Whats the title of the movie that you want to update?";
	cin.get();
	getline(cin, title);

	cout << "Whats the new genre of the movie that you want to update?";
	getline(cin, genre);

	cout << "Whats the new year of release of the movie that you want to add?";
	getline(cin, year);
	cout << "Whats the new number of likes of the movie that you want to add?";
	getline(cin, likes);
	cout << "Whats the new link of the trailer of the movie that you want to add?";
	cin.get();
	getline(cin, link);
	try {
		val.validate_number(likes);
		val.validate_year(year);
		int like = stoi(likes);
		int years = stoi(year);
		val.validate_number_int(like);
		val.validate_year_int(years);
		try {
			this->service.add(title, genre, years, like, link);
		}
		catch (RepositoryException& er) {
			cout << er.what() << endl;
		}
	}
	catch (ValidationException& er) {
		cout << er.what() << endl;
		return;
	}
}
void UI::print_deleted_movies()
{
	vector<Movie> movies = this->service.return_list_of_deleted_movies();
	for (auto it = movies.begin(); it != movies.end(); ++it) {
		Movie m = *it;
		cout << m.get_title() << " " << m.get_genre() << " " << m.get_year_of_release() << " " << m.get_number_of_likes() << " " << m.get_link();
		cout << endl;
	}
}

void UI::go_through_filtered_movies(std::string genre)
{
	int size = this->service.return_length_of_watchlist();
	vector<Movie> movies = this->service.return_array();
	int counter = 0;
	for (auto it = movies.begin(); it !=movies.end(); ++it) {
		Movie m = *it;
		int command = 1;
		if (m.get_genre() == genre || genre=="0") {
			cout << m.get_title() << " " << m.get_genre() << " " << m.get_year_of_release() << " " << m.get_number_of_likes() << " ";
			cout << endl;
			ShellExecuteA(NULL, NULL, "chrome.exe", m.get_link().c_str(), NULL, SW_SHOWMAXIMIZED);
			cout << "Did you liked the trailer? Want to add the movie to the watchlist?\n";
			cout << "1-yes\n 2-no.\n";
			cin >> command;
			if (command == 1)
			{
				try { this->user_service.add_user_service(m); }
				catch (UserException& er) {
					cout << er.what() << endl;
				}
			}
			cout << "Want to go to the next movie?\n";
			cout << "1-yes\n 2-no.\n";
			cin >> command;
			if (command == 2)
				counter = size;
		}
		if (command == 1 && counter == size - 1)
			counter = 0;
		counter += 1;
	}
}

void UI::open_watchlist()
{
	cout << "acum";
	string link=string("start ").append(this->user_service.get_file_name());
	system(link.c_str());
}



void UI::start_user_mode()
{
	int command;
	string mode;
	cout << "csv or html?\n";
	cin.get();
	getline(cin, mode);
	this->user_service.fileType(mode);
	while (1) {
		cout << " 1 - Show the movies of a given genre.\n";
		cout << " 2 - Remove a movie from the watchlist.\n";
		cout << " 3 - See the watchlist.\n";
		cout << " 4 - Open the watchlist.\n";
		cout << " 0 - exit\n";
		cin >> command;
		if (command == 0)
			break;
		if (command == 1) {
			std::string genre;
			cout << "What is the genre of the movies that you want to filter?\n";
			cin.get();
			getline(cin, genre);
			go_through_filtered_movies(genre);
		}
		if (command == 2) {
			std::string title;
			cout << "What is the title of the movie that you want to delete from the watchlist\n";
			cin.get();
			getline(cin, title);
			Movie movie = this->service.find_movie_by_title(title);
			try {
				this->user_service.delete_user_service(title);
				cout << "Do you want to appreciate the movie?\n1-yes\n2-no";
				int command;
				cin >> command;
				if (command == 1)
					this->service.update(title, movie.get_genre(), movie.get_year_of_release(), movie.get_number_of_likes() + 1, movie.get_link());
			}
		
			catch (UserException& er) {
				cout << er.what() << endl;
			}

		}
		if (command == 3) {
			try {
				int size = this->user_service.get_elems();
				vector<Movie> movies = this->user_service.get_all();
				for (int i = 0; i < size; i++) {
					cout << movies[i].get_title() << " " << movies[i].get_genre() << " " << movies[i].get_year_of_release() << " " << movies[i].get_number_of_likes() << " " << movies[i].get_link();
					cout << endl;
				}
			}
			catch (UserException& er) {
				string error;
				error += string("The watchlist is empty!");
				cout << er.what() << endl;
			}
		}
		if (command == 4) {
			open_watchlist();
		
		}
	}
}

