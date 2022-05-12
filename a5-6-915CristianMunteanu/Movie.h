#pragma once
#include <string>
using namespace std;
class Movie {
private:
	string genre;
	string title;
	int year_of_release;
	int number_of_likes;
	string link;
public:
	Movie();
	Movie(string title, string genre, int year_of_release, int number_of_likes, string link);
	Movie(const Movie& copy);
	string get_genre() const;
	string get_title() const;
	int get_year_of_release();
	int get_number_of_likes();
	string get_link() const;
	void set_genre(string new_genre);
	void set_title(string new_title);
	void set_year_of_release(int new_year_of_release);
	void set_number_of_likes(int new_number_of_likes);
	void set_link(string new_link);
	friend bool operator ==(const Movie& rhs, const Movie& lfs);
	friend istream& operator>>(istream& is, Movie& m);
	friend ostream& operator<<(ostream& os,const Movie& m);
};