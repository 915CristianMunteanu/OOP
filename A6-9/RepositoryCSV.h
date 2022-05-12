#pragma once
#include "UserRepository.h"
class RepositoryCSV : public UserRepository {
public:
	RepositoryCSV(vector<Movie> watchlist,string userFilename);
	vector<Movie> get_elements_from_watchlist() override;
	int return_length_of_watchlist() override;
	void write_to_csv();
	void add_movie_to_watchlist(const Movie& m) override;
	string getFileName() override;
};