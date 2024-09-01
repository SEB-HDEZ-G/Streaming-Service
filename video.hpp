#ifndef _VIDEO_HPP_
#define _VIDEO_HPP_
#include <iostream>
#include <string>
#include <vector>

class Video
{
  public:
    virtual void show_info(); //method that I've set as virtual
    virtual void show_general();
    std::string get_title();
    int get_id();
    std::string get_genre();
    void show_rating();
    double get_rating();
    void set_rating();
    void calc_mean();
    friend bool operator > (const Video object1, const Video object2);
    friend bool operator < (const Video object1, const Video object2);
    friend bool operator == (const Video object1, const Video object2);

    Video(int id = 0, std::string title = "none", std::string year = "none", std::string genre = "none", int duration = 0, float rating = 0);
    ~Video();
  protected:
    int id_ = 0;
    std::string title_ = "";
    std::string year_ = "";
    std::string genre_ = "";
    int duration_ = 0;
    float rating_ = 0;
    int num_ratings_ = 0;
    std::vector <float> ratings_;
};

#endif