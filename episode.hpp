#ifndef EPISODE_HPP
#define EPISODE_HPP
#include "video.hpp"
#include "series.hpp"

class Episode : public Video { //class inherited from Series class
    public:
        void show_info() override; //overriden method
        
        Episode(std::string episode_title = "none", int season = 0, int episode = 0, int episode_duration = 0);
        ~Episode();
    private:
        std::string episode_title_ = "";
        int season_ = 0;
        int episode_ = 0;
        int episode_duration_ = 0;
};

#endif