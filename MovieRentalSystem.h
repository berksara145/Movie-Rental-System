//
// Created by PC on 1.12.2022.
// Name: Berk Sara
// Student Number: 22102354
// Section 2
//

#ifndef CS_HW_MOVIERENTALSYSTEM_H
#define CS_HW_MOVIERENTALSYSTEM_H

#include <string>
#include "SortedLinkedList.h"

using namespace std;

class MovieRentalSystem {
public:
    MovieRentalSystem( const string movieInfoFileName,
                       const string subscriberInfoFileName );
    ~MovieRentalSystem();
    bool checkFile(const string fileName);
    void removeMovie( const int movieId );
    void addMovie( const int movieId, const int numCopies );
    void removeSubscriber( const int subscriberId );
    void rentMovie( const int subscriberId, const int movieId );
    void returnMovie( const int subscriberId, const int movieId ) ;
    void showMoviesRentedBy( const int subscriberId ) const;
    void showSubscribersWhoRentedMovie( const int movieId ) const;
    void showAllMovies() const;
    void showAllSubscribers() const;
    bool checkIfMovieExists(const int movieID) const;
    bool checkIfSubscriberExists(const int subscriberID) const;
private:
    /*int is the movieId and the boolean is true if book is returned
    SortedLinkedList<int, bool>* will be the parameter of subscribers*/
    //it has subscriberID and all of the transactions made
    SortedLinkedList<int, SortedLinkedList<int, bool>* >* subscribers;
    //it has movieID and MovieCount rentalSystem owns
    SortedLinkedList<int,int>* movies;
    //same as movies but movieCount is count of rentable books
    SortedLinkedList<int,int>* movieCounts;
};
#endif //CS_HW_MOVIERENTALSYSTEM_H
