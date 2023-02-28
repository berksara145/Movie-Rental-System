//
// Created by PC on 1.12.2022.
// Name: Berk Sara
// Student Number: 22102354
// Section 2
//

#include "MovieRentalSystem.h"
#include "fstream"
#include "iostream"
/* This method initializes the subscribers and movies
 * Also checks if filenames exists if not then it doesn't load anything
 * */
MovieRentalSystem::MovieRentalSystem(const string movieInfoFileName, const string subscriberInfoFileName) {

    movies = new SortedLinkedList<int,int>();
    subscribers = new SortedLinkedList<int, SortedLinkedList<int, bool>* >();
    movieCounts = new SortedLinkedList<int,int>();

    //string movieTxt = "C:\\Users\\PC\\Desktop\\my_movies.txt";
    //string subscribersTxt = "C:\\Users\\PC\\Desktop\\subscribers.txt";

    int number = -1;
    int number2 = -1;
    ifstream inputFile;
    int movieSize = -1;
    int subscriberSize = -1;

    if( !(checkFile(movieInfoFileName)) ){
        cout << "Input file " << movieInfoFileName <<" does not exist" <<endl;
        return;
    }
    if( !(checkFile(subscriberInfoFileName)) ){
        cout << "Input file " << subscriberInfoFileName <<" does not exist" <<endl;
        return;
    }

    inputFile.open( movieInfoFileName.c_str(), ios_base::in );
    //Continue until the end of the file
    while ( inputFile.eof() == false ) {
        if(movieSize == -1){
            inputFile >> movieSize;
        }
        //Read a number from the file stream just like reading from cin
        inputFile >> number;
        inputFile >> number2;
        movies->insert(number, number2, 0);
        movieCounts->insert(number, number2, 0);
        /*
        cout << number << "  ";
        cout << number2 << endl;
         */
    }
    //Close the input file stream
    inputFile.close();
    inputFile.open( subscriberInfoFileName.c_str(), ios_base::in);
    while ( inputFile.eof() == false ) {
        if(subscriberSize == -1){
            inputFile >> subscriberSize;
        }
        //Read a number from the file stream just like reading from cin
        inputFile >> number;
        SortedLinkedList<int,bool>* transactions = new SortedLinkedList<int,bool>();
        subscribers->insert(number, transactions, 0);
        /*
        cout << number << endl;
         */
        transactions = nullptr;
    }
    inputFile.close();
    cout << subscriberSize << " subscribers and "<< movieSize <<" movies have been loaded" << endl;
}
bool MovieRentalSystem::checkFile(const string fileName) {
    ifstream f(fileName.c_str());
    return f.good();
}
/* must check if movie exists
 * must check if the movie is borrowed from anyone and not returned
 * else removes the movie (and all the transactions maybe ask at forum)
 * */
void MovieRentalSystem::removeMovie(const int movieId) {
    if( !(checkIfMovieExists(movieId)) ){
        cout << "Movie " << movieId << " does not exist" << endl;
        return;
    }
    for (int i = 1; i < subscribers->getLength() + 1; ++i) {
        SortedLinkedList<int,bool>* tempList = subscribers->getNodeByPosition(i)->getItem2();
        for (int j = 1; j < tempList->getLength() + 1; ++j) {
            if( movieId == tempList->getNodeByPosition(j)->getItem1() &&  !(tempList->getNodeByPosition(j)->getItem2())  ){
                cout << "Movie "<< movieId <<" cannot be removed -- at least one copy has not been returned" << endl;
                return;
            }
        }
    }
    movies->remove(movieId);
    movieCounts->remove(movieId);
    cout << "Movie "<< movieId <<" has been removed" << endl;
    //maybe remove transactions
}
/* must check if exists. if it exists then doesn't add
 * if not exists then adds to the movies (done)
 * */
void MovieRentalSystem::addMovie(const int movieId, const int numCopies) {
    if(checkIfMovieExists(movieId)){
        //there is no example for this one so I write the warning message myself
        cout << "Movie " << movieId << " already exists"<< endl;
        return;
    }
    movies->insert(movieId, numCopies, 0);
    movieCounts->insert(movieId, numCopies, 0);
    cout << "Movie " << movieId << " has been added"<< endl;
}
/* checks if exists (there is no example for this in the test file ask at forum)
 * checks if there is any unreturned transaction
 * removes the subscriber and his transactions
 * */
void MovieRentalSystem::removeSubscriber(const int subscriberId) {
    //Subscriber 5555 has been removed
    if( !(checkIfSubscriberExists(subscriberId)) ){
        cout << "Subscriber "<< subscriberId<<" does not exists" << endl;
        return;
    }
    SortedLinkedList<int,bool>* tempList = subscribers->getNode(subscriberId)->getItem2();
    for (int i = 1; i < tempList->getLength() + 1; ++i) {
        //checks if returned boolean is false
        if( !(tempList->getNodeByPosition(i)->getItem2()) ){
            cout << "Subscriber "<< subscriberId
            << " cannot be removed -- at least one movie has not been returned" << endl;
            return;
        }
    }
    delete tempList;
    subscribers->remove(subscriberId);
    cout << "Subscriber "<< subscriberId <<" has been removed" << endl;

}
/* checks if subscriber exists
 * checks if movie exists
 * check if both does not exists
 * checks if there are available copies by changing movieCounts list
 * */
void MovieRentalSystem::rentMovie(const int subscriberId, const int movieId) {
    if( !(checkIfMovieExists(movieId)) || !(checkIfSubscriberExists(subscriberId)) ){
        if( !(checkIfSubscriberExists(subscriberId)) && !(checkIfMovieExists(movieId))){
            cout << "Subscriber "<<  subscriberId <<" and movie "
            <<  movieId <<" do not exist" << endl;
        }
        else if(!(checkIfMovieExists(movieId))){
            cout <<  "Movie "<< movieId <<" does not exist"<<  endl;
        }
        else{
            cout <<  "Subscriber "<< subscriberId <<" does not exist"<<  endl;
        }
        return;
    }
    Node<int,int>* temp = movieCounts->getNode(movieId);
    int movieCount = temp->getItem2();
    if(movieCount == 0){
        cout << "Movie "<< movieId <<" has no available copy for renting" << endl;
    }
    else{
        temp->setItem2(--movieCount);
        SortedLinkedList<int, bool>* tempList2 = subscribers->getNode(subscriberId)->getItem2();
        tempList2->insert(movieId, false, 1);

        cout << "Movie "<< movieId<<" has been rented by subscriber " << subscriberId <<endl;
    }
}
/* checks if there is a transaction with the name subscriber and movie movieID if there are no transactions
 * says no transact
 * returns the movie and makes the transaction boolean returned 'true'
 * also increments movieCount by 1
 * */
void MovieRentalSystem::returnMovie(const int subscriberId, const int movieId) {
    if(!checkIfMovieExists(movieId) || !checkIfSubscriberExists(subscriberId)){
        cout << "No rental transaction for subscriber "<<subscriberId <<" and movie "<< movieId <<endl;
        return;
    }
    SortedLinkedList<int, bool>* tempList = subscribers->getNode(subscriberId)->getItem2();
    for (int i = 1; i < tempList->getLength() + 1 ; ++i) {
        Node<int, bool>* temp = tempList->getNodeByPosition(i);
        if(temp->getItem1() == movieId && !temp->getItem2() ){
            temp->setItem2(true);
            int availableMovieCount = movieCounts->getNode(movieId)->getItem2();
            movieCounts->getNode(movieId)->setItem2(++availableMovieCount);
            cout << "Movie "<< movieId <<" has been returned by subscriber "<< subscriberId <<endl;
            return;
        }
    }
    cout << "No rental transaction for subscriber "<<subscriberId <<" and movie "<< movieId <<endl;
}
/* checks if subscriber exists
 * checks if are there any transaction
 * displays the movies rented and if they are returned or not
 * */
void MovieRentalSystem::showMoviesRentedBy(const int subscriberId) const {
    if(!checkIfSubscriberExists(subscriberId)){
        cout << "Subscriber "<< subscriberId <<" does not exist" <<endl;
        return;
    }
    SortedLinkedList<int,bool>* tempList= subscribers->getNode(subscriberId)->getItem2();
    if(tempList->getLength() == 0){
        cout << "Subscriber "<< subscriberId <<" has not rented any movies" << endl;
    }
    else{
        cout << "Subscriber "<< subscriberId <<" has rented the following movies:" << endl;
        for (int i = 1; i < tempList->getLength() + 1; ++i) {
            Node<int, bool>* temp = tempList->getNodeByPosition(i);
            cout << temp->getItem1() << " ";
            if(temp->getItem2()){
                cout << "returned" << endl;
            }
            else{
                cout << "not returned" << endl;
            }
        }
    }
}
/* checks if movie exists
 * checks if are there any transaction
 * displays the subscribers who rented and if they are returned or not
 * */
void MovieRentalSystem::showSubscribersWhoRentedMovie(const int movieId) const {
    if( !checkIfMovieExists(movieId)){
        cout << "Movie "<< movieId <<" does not exist" << endl;
        return;
    }
    bool isRented = false;
    string outputStr;
    //traversing all transactions
    for (int i = 1; i < subscribers->getLength() + 1; ++i) {
        SortedLinkedList<int, bool>* tempList = subscribers->getNodeByPosition(i)->getItem2();
        //traversing the transaction of one subscriber
        for (int j = 1; j < tempList->getLength() + 1; ++j) {
            Node<int, bool>* temp = tempList->getNodeByPosition(j);
            //adding the matched movies to string
            if(temp->getItem1() == movieId){
                outputStr += to_string(subscribers->getNodeByPosition(i)->getItem1());
                outputStr += " ";
                if(temp->getItem2()){
                    outputStr += "returned";
                }
                else{
                    outputStr += "not returned" ;
                }
                outputStr += "\n";
                isRented = true;
            }
        }
    }
    if(isRented){
        cout << "Movie "<< movieId <<" has been rented by the following subscribers:" <<endl;
        cout << outputStr;
    }
    else{
        cout << "Movie "<< movieId <<" has not been rented by any subscriber" << endl;
    }
}
/*
 * Basically shows all movie id and movie count (done)
 * */
void MovieRentalSystem::showAllMovies() const {
    cout << "Movies in the movie rental system:" << endl;
    for (int i = 1; i < movies->getLength() + 1; ++i) {
        Node<int,int>* temp = movies->getNodeByPosition(i);
        cout << temp->getItem1() << " " << temp->getItem2() << endl;
    }
}
/*  Basically shows all subscribers name (done)
 * */
void MovieRentalSystem::showAllSubscribers() const {
    cout << "Subscribers in the movie rental system:" << endl;
    for (int i = 1; i < subscribers->getLength() + 1; ++i) {
        Node<int,SortedLinkedList<int, bool>* >* temp = subscribers->getNodeByPosition(i);
        cout << temp->getItem1() << endl;
    }
}
/*  Deletes all the movies
 *  Deletes all the movies and their respective transactions
 * */
MovieRentalSystem::~MovieRentalSystem() {
    delete movies;
    delete movieCounts;
    for (int i = 1; i < subscribers->getLength() + 1; ++i) {
        delete subscribers->getNodeByPosition(i)->getItem2();
    }
    delete subscribers;
}

bool MovieRentalSystem::checkIfMovieExists(const int movieID) const{
    if(movies->doesExists(movieID)){
        return true;
    }
    else{
        return false;
    }
}

bool MovieRentalSystem::checkIfSubscriberExists(const int subscriberID) const{
    if(subscribers->doesExists(subscriberID)){
        return true;
    }
    else{
        return false;
    }
}





