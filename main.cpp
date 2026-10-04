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
    Review *newReview = new Review;
    newReview->next = nullptr;
    newReview->rating = rating;
    newReview->comment = comment;
    if (!this->head) {
        this->head = newReview;
    } else {
        newReview->next = head;
        head = newReview;
    }
}

Movie::printReviews() {
    cout << "Movie Title: " << this.title << endl;
    if (!this->head) {
        cout << "  > No reviews available for this movie\n\n";
    } else {
        Review *current = this->head;
        int count = 1;
        int sum = 0;
        while (current) {
            cout << "  > Review #" << count << ": ";
            cout << current->rating << ": " << current->comment << endl;
            sum += current->rating;
            count++;
            current = current->next;
        }
        cout << "  > Average: " << (sum / count);
    }
}

Movie::~Movie() {
    Review *current = new Review;
    Review *next = newReview;
    if (head) {
        current = head;
        while (current) {
            next = current->next;
            delete current
            current = next;
        }
    }
}