#pragma once
#include <vector>
#include "../../../../Documents/GitHub/a5-6-915CristianMunteanu/Movie.h"

class UserRepository {
protected:
    std::vector<Movie> watchlist;
    std::string userFilename;
public:
    UserRepository();
    virtual void add_movie_to_watchlist(const Movie& new_movie);
    void remove_movie_from_watchlist(std::string title);
    virtual vector<Movie> get_elements_from_watchlist();
    virtual int return_length_of_watchlist();
    virtual Movie find_movie_by_title(std::string title);
    int return_index_of_movie(std::string title);
    virtual string getFileName();
};

class UserException : public std::exception {
private:
    std::string message;
public:
    explicit UserException(std::string& _message);

    const char* what() const noexcept override;
};