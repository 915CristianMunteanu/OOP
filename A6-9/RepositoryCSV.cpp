#include "RepositoryCSV.h"
#include <fstream>
#include <iostream>
RepositoryCSV::RepositoryCSV(vector<Movie> watchlist, string userFilename)
{
	this->watchlist = watchlist;
	this->userFilename = userFilename;
}

vector<Movie> RepositoryCSV::get_elements_from_watchlist()
{
	return watchlist;
}

int RepositoryCSV::return_length_of_watchlist()
{
	return watchlist.size();
}

void RepositoryCSV::write_to_csv()
{
	std::ofstream fout(this->userFilename);
	if (!this->watchlist.empty())
		for (const Movie& m : this->watchlist)
			fout << m << "\n";
	fout.close();
}

void RepositoryCSV::add_movie_to_watchlist(const Movie& m)
{
	this->watchlist.push_back(m);
	this->write_to_csv();
}

string RepositoryCSV::getFileName()
{
	return this->userFilename;
}
