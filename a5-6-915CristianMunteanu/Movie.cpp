#include "Movie.h"
#include <iostream>
#include <sstream>
#include "../../../source/repos/Project1/Project1/Utils.h"
#include <string>
#include <vector>
#include <utility>
using namespace std;
Movie::Movie()
{
	this->genre = "";
	this->title = "";
	this->link = "";
	this->year_of_release = 0;
	this->number_of_likes = 0;
}

Movie::Movie(string title, string genre, int year_of_release, int number_of_likes, string link)
{
	this->genre = genre;
	this->title = title;
	this->link = link;
	this->year_of_release = year_of_release;
	this->number_of_likes = number_of_likes;
}




Movie::Movie(const Movie& copy)
	:title(copy.title),genre(copy.genre),year_of_release(copy.year_of_release),number_of_likes(copy.number_of_likes),link(copy.link)
{
}

string Movie::get_genre() const
{
	return this->genre;
}

string Movie::get_title() const
{
	return this->title;
}

int Movie::get_year_of_release()
{
	return this->year_of_release;
}

int Movie::get_number_of_likes()
{
	return this->number_of_likes;
}


string Movie::get_link() const
{
	return this->link;
}

void Movie::set_genre(string new_genre)
{
	this->genre = new_genre;
}

void Movie::set_title(string new_title)
{
	this->title = new_title;
}

void Movie::set_year_of_release(int new_year_of_release)
{
	this->year_of_release = new_year_of_release;
}

void Movie::set_number_of_likes(int new_number_of_likes)
{
	this->number_of_likes = new_number_of_likes;
}

void Movie::set_link(string new_link)
{
	this->link = new_link;
}



bool operator==(const Movie& rhs, const Movie& lfs)
{
	if (rhs.genre == lfs.genre)
		if (rhs.link == lfs.link)
			if (rhs.number_of_likes == lfs.number_of_likes)
				if (rhs.year_of_release == lfs.year_of_release)
					if (rhs.link == lfs.link)
						return true;
	return false;
}

istream & operator>>(istream & is, Movie & m)
{
	string line;
	getline(is, line);
	vector<string> tokens;
	if (line.empty())
		return is;
	tokens = tokenize(line, ',');
	m.title = tokens[0];
	m.genre = tokens[1];
	m.year_of_release = stoi(tokens[2]);
	m.number_of_likes = stoi(tokens[3]);
	m.link = tokens[4];
	return is;
}

ostream& operator<<(ostream& os, const Movie& m)
{
	os << m.title << ",";
	os << m.genre << ",";
	os << m.year_of_release << ",";
	os << m.number_of_likes << ",";
	os << m.link;
	return os;
}
