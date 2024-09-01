#include "video.hpp"
#include <iostream>
#include <string>

Video::Video(int id, std::string title, std::string year, std::string genre, int duration, float rating) {
  id_ = id;
  title_ = title;
  year_ = year;
  genre_ = genre;
  duration_ = duration;
  rating_ = rating;
  ratings_.push_back(rating);
}

Video::~Video() {}

bool operator > (const Video object1, const Video object2)  {
  if (object1.rating_ > object2.rating_) {
    return true;
  }
  else {
    return false;
  }
}

bool operator < (const Video object1, const Video object2)  {
  if (object1.rating_ < object2.rating_) {
    return true;
  }
  else {
    return false;
  }
}

bool operator == (const Video object1, const Video object2)  {
  if (object1.rating_ == object2.rating_) {
    return true;
  }
  else {
    return false;
  }
}

void Video::show_info() {
  std::cout << "\nID: " << id_ << std::endl;
  std::cout << "Title: " << title_ << std::endl;
  std::cout << "Release date: " << year_ << std::endl;
  std::cout << "Duration (min): " << duration_ << std::endl;
  std::cout << "Genre: " << genre_ << std::endl;
  Video::show_rating();
}

void Video::show_general() {
  std::cout << "\n> [" << id_ << "] " << title_ << std::endl;
}

void Video::show_rating() {
  std::cout << "Rating: " << rating_ << std::endl;
}

void Video::set_rating() {
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

void Video::calc_mean() {
  float sum = 0;
  for (float element: ratings_) {
    sum += element;
  }
  rating_ = sum / ratings_.size();
}

double Video::get_rating() {
  return rating_;
}

std::string Video::get_title() {
  return title_;
}

int Video::get_id() {
  return id_;
}

std::string Video::get_genre() {
  return genre_;
}