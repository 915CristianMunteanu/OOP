#include "HTMLRepository.h"
#include <fstream>
#include <iostream>
HTMLRepository::HTMLRepository(vector<Movie> watchlist, string userFilename)
{
	this->watchlist = watchlist;
	this->userFilename = userFilename;
}

vector<Movie> HTMLRepository::get_elements_from_watchlist()
{
	return this->watchlist;
}

int HTMLRepository::return_length_of_watchlist()
{
	return watchlist.size();
}

void HTMLRepository::write_to_html()
{
	ofstream fout(userFilename);
	cout << "ceva";
	if (!this->watchlist.empty()) {
		fout << "<!DOCTYPE html>\n<html>\n	<head>\n		<title>Watchlist</title>\n	</head>\n	<body>\n		<table border=""1"">\n		<tr>\n			<td>Title</td>\n			<td>Genre</td>\n			<td>Year Of Release</td>\n			<td>Number Of Likes</td>\n			<td>Link</td>\n";
		for ( Movie& m : watchlist) {
			fout << "		<tr>";
			fout << "			<td>"<<m.get_title()<<"</td>\n" << "			<td>" << m.get_genre() << "</td>\n" << "			<td>" << to_string(m.get_year_of_release()) << "</td>\n" << "			<td>" << to_string(m.get_number_of_likes()) << "</td>\n" << "			<td><a href = " << m.get_link() << ">Link</a></td>\n";
			fout << "		</tr>";
		}
		fout << "		</table>\n	</body>\n</html>";

	}
}

void HTMLRepository::add_movie_to_watchlist(const Movie& m)
{
	this->watchlist.push_back(m);
	write_to_html();
}

string HTMLRepository::getFileName()
{
	return this->userFilename;
}