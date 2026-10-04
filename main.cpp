#include <iostream>
#include <vector>

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
    ~Movie();
};

Movie::addReview(float rating, string comment) {
    Review newReview = new Review;
    newReview->next = nullptr;
    newReview->rating = rating;
    newReview->comment = comment;
    if (!this.head) {
        this.head = newReview;
    } else {
        newReview->next = head;
        head = newReview;
    }
}