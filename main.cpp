#include <iostream>

using namespace std;

class Review {
    float rating;
    string comment;
    Review *next;
};

class Movie {
    string title;
    Review *head;

    public:
    addReview(float, string);
    printReviews();
    Movie() {title = " ", head = nullptr};
    Movie(string t) {title = t, head = nullptr};
};