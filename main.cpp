#include <iostream>
#include "Node.h"
#include "MovieRentalSystem.h"
#include "SortedLinkedList.h"
#include "fstream"
using namespace std;
int main() {

    /*
     * //sortedLink insert tests
    SortedLinkedList<int, int>* list = new SortedLinkedList<int, int>();
    cout << list->insert(1,10 ) << endl;
    cout << list->insert(3,30 ) << endl;
    cout << list->insert(2,20 ) << endl;

    SortedLinkedList<int, int>* list2 = new SortedLinkedList<int, int>();
    cout << list2->insert(4,10 ) << endl;

    delete list;
    delete list2;
    */

    /*
     *
    //remove tests
    cout << list->remove(4) << endl;
    cout << list->remove(2) << endl;
    cout << list->remove(3) << endl;
    cout << list->remove(1) << endl;
    cout << list->remove(2) << endl;

    //get item tests
    cout << list->getNode(1)->getItem1() << " "
    << list->getNode(1)->getItem2() << endl;

    cout << list->getNode(2)->getItem1() << " "
         << list->getNode(2)->getItem2() << endl;

    //getNode tests
    if(list->getNode(3)){
        cout << "didnt delete" << endl;
    }
    else{
        cout << "did delete" << endl;
    }

    cout << list->getLength() << endl;
    */

    /*
    //file reading tests
    MovieRentalSystem MRS(" "," ");

    //showing linkedLists test
    MRS.showAllSubscribers();
    MRS.showAllMovies();
    cout << endl;
    cout << endl;
    //add and remove Movie, Subscriber tests without transaction logic
    MRS.addMovie(900, 4);
    MRS.addMovie(100, 4);
    MRS.showAllMovies();
    MRS.removeMovie(54);
    MRS.removeMovie(100);
    MRS.showAllMovies();
    MRS.removeSubscriber(4);
    MRS.removeSubscriber(1111);
    MRS.showAllSubscribers();

    //rent tests
    cout << endl;
    cout << endl;
    MRS.rentMovie(1,1);
    MRS.rentMovie(4444,1);
    MRS.rentMovie(1,50);
    MRS.rentMovie(4444,40);
    MRS.rentMovie(4444,40);
    MRS.rentMovie(4444,40);

    //return tests
    MRS.returnMovie(132, 4124);
    MRS.returnMovie(4444, 647);
    MRS.returnMovie(5234, 40);
    MRS.returnMovie(4444, 40);
    MRS.returnMovie(4444, 40);
    MRS.returnMovie(4444, 40);


    //remove Movie tests with transaction logic
    cout << endl;
    MRS.rentMovie(6666, 70);
    MRS.removeMovie(3534);
    MRS.removeMovie(70);
    MRS.returnMovie(6666,70);
    MRS.removeMovie(70);

    //remove Subscriber
    cout << endl;
    MRS.rentMovie(8888, 10);
    MRS.rentMovie(8888, 10);
    MRS.rentMovie(8888, 200);

    cout << endl;
    MRS.removeSubscriber(8888);
    MRS.returnMovie(8888, 10);
    MRS.removeSubscriber(8888);
    MRS.returnMovie(8888, 200);
    MRS.removeSubscriber(8888);
    MRS.returnMovie(8888, 10);
    MRS.removeSubscriber(8888);


    //show movies rented by tests
    cout << endl;
    MRS.rentMovie(7777, 10);
    MRS.rentMovie(7777, 10);
    MRS.rentMovie(5555, 20);

    MRS.returnMovie(7777, 10);
    MRS.returnMovie(7777, 10);
    MRS.removeMovie(10);

    MRS.showMoviesRentedBy(7777);
    MRS.showMoviesRentedBy(5555);
    MRS.showMoviesRentedBy(8888);
    MRS.showMoviesRentedBy(6666);
    MRS.showMoviesRentedBy(4444);
    MRS.showMoviesRentedBy(12412);
    MRS.showMoviesRentedBy(9999);


    //show subscribers who rented movie tests
    cout << endl;
    MRS.showSubscribersWhoRentedMovie(124);
    MRS.showSubscribersWhoRentedMovie(300);
    MRS.showSubscribersWhoRentedMovie(10);
    MRS.showSubscribersWhoRentedMovie(20);
    MRS.showSubscribersWhoRentedMovie(40);

    cout << endl;
    */

    cout << endl;
    MovieRentalSystem MRS( "my_movies.txt", "subscribers.txt" );
    cout << endl;
    MRS.showAllMovies();
    cout << endl;
    MRS.showAllSubscribers();
    cout << endl;
    MRS.removeMovie( 600 );
    MRS.removeMovie( 600 );
    MRS.removeMovie( 70 );

    cout << endl;
    MRS.addMovie( 99, 3 );
    cout << endl;
    MRS.showAllMovies();
    cout << endl;
    MRS.rentMovie( 1111, 10 );
    MRS.rentMovie( 1111, 20 );
    MRS.rentMovie( 7777, 10 );
    MRS.rentMovie( 6666, 10 );
    MRS.rentMovie( 7777, 80 );
    MRS.rentMovie( 6666, 100 );
    MRS.rentMovie( 4444, 40 );
    MRS.rentMovie( 4444, 50 );
    MRS.rentMovie( 1234, 30 );
    MRS.rentMovie( 1111, 33 );
    MRS.rentMovie( 1234, 33 );
    cout << endl;
    MRS.returnMovie( 7777, 80 );
    MRS.returnMovie( 6666, 100 );
    MRS.returnMovie( 1111, 20 );
    MRS.returnMovie( 4444, 10 );
    MRS.returnMovie( 1111, 20 );
    cout << endl;
    MRS.rentMovie( 3333, 80 );
    MRS.rentMovie( 8888, 100 );
    MRS.rentMovie( 1111, 100 );
    MRS.rentMovie( 1111, 100 );
    cout << endl;
    MRS.rentMovie( 1111, 20 );
    MRS.returnMovie( 1111, 20 );
    MRS.rentMovie( 1111, 20 );
    cout << endl;
    MRS.showMoviesRentedBy( 1111 );
    MRS.showMoviesRentedBy( 8888 );
    MRS.showMoviesRentedBy( 2222 );
    MRS.showMoviesRentedBy( 1234 );
    cout << endl;
    MRS.showSubscribersWhoRentedMovie( 10 );
    MRS.showSubscribersWhoRentedMovie( 100 );
    MRS.showSubscribersWhoRentedMovie( 30 );
    MRS.showSubscribersWhoRentedMovie( 70 );
    cout << endl;
    MRS.removeMovie( 100 );
    cout << endl;
    MRS.removeSubscriber( 1111 );
    cout << endl;
    MRS.removeSubscriber( 5555 );
    cout << endl;
    MRS.removeSubscriber( 6666 );
    cout << endl;

    MRS.showAllSubscribers();
    cout << endl;
    MRS.showAllMovies();
    cout << endl;
    return 0;
}


