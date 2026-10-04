#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Review {
    float rating;
    string comment;
    Review *next;
};

class Movie {
    string title;
    Review *head;

    public:
    void addReview(float, string);
    void printReviews();
    Movie() {title = " "; head = nullptr;}
    Movie(string t) {title = t; head = nullptr; }
    ~Movie();
};

float randomRating() {
    float num = rand() % 51; // random number between 0 and 50;
    num /= 10; // divide by 10 to get a number with one decimal place between 0.0 and 5.0;
    return num;
}

void Movie::addReview(float rating, string comment) {
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

void Movie::printReviews() {
    cout << "Movie Title: " << this->title << endl;
    if (this->head == nullptr) {
        cout << "  > No reviews available for this movie\n\n";
    } else {
        Review *current = this->head;
        int count = 1;
        float sum = 0;
        while (current != nullptr) {
            cout << "  > Review #" << count << ": ";
            cout << setprecision(2) << current->rating << ": " << current->comment << endl;
            sum += current->rating;
            count++;
            current = current->next;
        }
        cout << "  > Average: " << setprecision(2) << (sum / count) << endl << endl;
    }
}

// we don't start at head because it is in the Movie class and thus part of stack
Movie::~Movie() {
    Review *current = this->head->next;
    current = this->head->next;
    while (current) {
        this->head = current->next;
        nullptr;
        current = this->head;
    }
    this->head = nullptr;
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