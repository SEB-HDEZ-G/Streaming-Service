#include "video.hpp"
#include "series.hpp"
#include "episode.hpp"
#include <iostream>
#include <string>

Episode::Episode(std::string episode_title, int season, int episode, int episode_duration):Video(0, "", "", "", 0, 0) {
                episode_title_ = episode_title;
                season_ = season;
                episode_ = episode;
                episode_duration_ = episode_duration;
              }

Episode::~Episode() {}

void Episode::show_info() { //redefining overriden method
    std::cout << "\nEpisode title: " << episode_title_ << std::endl;
    std::cout << "Season: " << season_ << std::endl;
    std::cout << "Episode: " << episode_ << std::endl;
    std::cout << "Episode duration: " << episode_duration_ << " hour" << std::endl;
}