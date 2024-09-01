#include "video.hpp"
#include "series.hpp"
#include <iostream>
#include <string>

Series::Series(int id, std::string title, std::string year, std::string genre, float rating,
              int seasons, int episodes):Video(id, title, year, genre, 0, rating) { //I´ve added 0 as a placeholder for 'duration'. Else, the rating for a series won't show.
                seasons_ = seasons;
                episodes_ = episodes;
              }

Series::~Series() {}

void Series::show_info() { //redefining overriden method
    std::cout << "\nID: " << id_ << std::endl;
    std::cout << "Title: " << title_ << std::endl;
    std::cout << "Release date: " << year_ << std::endl;
    std::cout << "Genre: " << genre_ << std::endl;
    Video::show_rating();
    std::cout << "Seasons: " << seasons_ << std::endl;
    std::cout << "Episodes: " << episodes_ << std::endl;
}

void Series::show_general() {
  std::cout << "\n> [" << id_ << "] " << title_ << std::endl;
}

void Series::show_rating() {
  std::cout << "Rating: " << rating_ << std::endl;
}

void Series::set_rating() {
  float new_rating = 0;

  std::cout << "\nCurrently rating: " << title_ << std::endl;
  std::cout << "Set new rating: ";
  std::cin >> new_rating;
  if (new_rating >= 1 && new_rating <= 5) {
    ratings_.push_back(new_rating);
    Video::calc_mean();
    std::cout << "\n> Rating set." << std::endl;
    std::cout << "\n> New average rating for " << title_ << ": " << rating_ << std::endl;
  }
  else {
    std::cout << "Invalid rating." << std::endl;
  }
}

void Series::calc_mean() {
  float sum = 0;
  for (float element: ratings_) {
    sum += element;
  }
  rating_ = sum / ratings_.size();
}

std::string Series::get_title() {
  return title_;
}

double Series::get_rating() {
  return rating_;
}

int Series::get_id() {
  return id_;
}

std::string Series::get_genre() {
  return genre_;
}