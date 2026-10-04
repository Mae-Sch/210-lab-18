#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

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

float randomRating() {
    float num = rand() % 51; // random number between 0 and 50;
    num /= 10; // divide by 10 to get a number with one decimal place between 0.0 and 5.0;
    return num;
}

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
    cout << "Movie Title: " << this->title << endl;
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
        cout << "  > Average: " << (sum / count) << endl << endl;
    }
}

Movie::~Movie() {
    Review *current = this->head;
    Review *next = newReview;
    if (this->head) {
        current = this->head;
        while (current) {
            next = current->next;
            delete current;
            current = next;
        }
    }
}

int main() {
    const int NUM_MOVIES = 4;
    const int NUM_REVIEWS = 3;
    string titles[NUM_MOVIES] = {"Lord of the Rings", "The Godfather", "High School Musical", "Star Wars"};
    ifstream inFile("input.txt");

    if (!inFile.is_open()) {
        cout << "File open failed";
        return 0;
    }

    vector<Movie> movies;
    for (int i = 0; i < NUM_MOVIES; ++i) {
        Movie newMovie(titles[i]);
        for (int j = 0; j < NUM_REVIEWS; ++j) {
            string newReview;
            getline(inFile, newReview);
            newMovie.addReview(randomRating(), newReview);
        }
        movies.push_back(newMovie);
    }

    inFile.close();

    for (int i = 0; i < movies.size(); ++i) {
        movies.at(i).printReviews();
    }

    return 1;
}