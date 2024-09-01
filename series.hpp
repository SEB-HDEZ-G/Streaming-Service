#ifndef SERIES_HPP
#define SERIES_HPP
#include "video.hpp"

class Series : public Video { //class inherited from Video class
    public:
        void show_info() override; //overriden method
        void show_general() override;
        std::string get_title();
        std::string get_genre();
        double get_rating();
        int get_id();
        void show_rating();
        void set_rating();
        void calc_mean();
        
        Series(int id = 0, std::string title = "none", std::string year = "none", std::string genre = "none", float rating = 0,
              int seasons = 0, int episodes = 0);
        ~Series();
    private:
        int seasons_ = 0;
        int episodes_ = 0;
};

#endif

//notes: the overriden method acts exactly the same as if it was redefined
//(although the way in which they have been written is logically different)
//It may not be noticeable right now, but for the inherited classes that
//I will do next, using the virtual method is gonna be useful.