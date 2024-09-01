#include "video.hpp"
#include "series.hpp"
#include "episode.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<Video> movies; std::vector<Series> series;
std::vector<Episode> Fallout_episodes; std::vector<Episode> LOKI_episodes; std::vector<Episode> Arcane_episodes;
std::vector<Episode> Daredevil_episodes; std::vector<Episode> Parasyte_episodes;

int choice;
std::string exitChoice = "N";
std::string movie_or_series = "";
Video movie_to_search; Series series_to_search;
int series_input = 0; int movie_input = 0;
std::string by_genre = "";
std::vector<Video> highest_rated_movies;
std::vector<Series> highest_rated_series;

void exit_program() {
  std::cout << "\n===== Are you sure you want to exit? (Y/N) =====" << std::endl;
  std::cout << "\n> ";
  std::cin >> exitChoice;
  if (exitChoice == "Y" || exitChoice == "y") {
    std::cout << "\n> Program ended." << std::endl;
    exit(0); //Use 'return' instead of 'break' to exit the function
  }
  else {
    exitChoice = "N";
    //return;
  }
}

void show_main_menu() {
  std::cout << "\n===== Menu =====" << std::endl;
  std::cout << "Show all available content [1]" << std::endl;
  std::cout << "Go to movies [2]" << std::endl;
  std::cout << "Go to series [3]" << std::endl;
  std::cout << "Search content [4]" << std::endl;
  std::cout << "Show by genre [5]" << std::endl;
  std::cout << "Exit [6]" << std::endl;
  std::cout << "\n> "; std::cin >> choice;
}

void additional_general_menu() {
  std::cout << "\n===== Additional commands =====" << std::endl;
  std::cout << "Go to movies [1]" << std::endl;
  std::cout << "Go to series [2]" << std::endl;
  std::cout << "Show highest rated content [3]" << std::endl;
  std::cout << "Go back to main menu [4]" << std::endl;
  std::cout << "Exit [5]" << std::endl;
  std::cout << "\n> "; std::cin >> choice;
}

void additional_movies_menu() {
  std::cout << "\n===== Additional commands =====" << std::endl;
  std::cout << "Select movie [1]" << std::endl;
  std::cout << "Show highest rated movies [2]" << std::endl;
  std::cout << "Show all movies general information [3]" << std::endl;
  std::cout << "Go back to main menu [4]" << std::endl;
  std::cout << "Exit [5]" << std::endl;
  std::cout << "\n> "; std::cin >> choice;
}

void additional_series_menu() {
  std::cout << "\n===== Additional commands =====" << std::endl;
  std::cout << "Select series [1]" << std::endl;
  std::cout << "Show highest rated series [2]" << std::endl;
  std::cout << "Show all series general information [3]" << std::endl;
  std::cout << "Go back to main menu [4]" << std::endl;
  std::cout << "Exit [5]" << std::endl;
  std::cout << "\n> "; std::cin >> choice;
}

void show_all_movies() {
  for(Video &movie: movies) {
    movie.show_general();
  }
}

void show_all_series() {
  for(Series &serie: series) {
    serie.show_general();
  }
}

void show_all_movies_info() {
  for(Video &movie: movies) {
    movie.show_info();
  }
}

void show_all_series_info() {
  for(Series &serie: series) {
    serie.show_info();
  }
}

void show_by_genre() {
  bool actual_genre = false;
  std::cout << "\n===== Genre =====" << std::endl;
  std::cout << "\n> "; std::cin >> by_genre;
  for(Video &movie: movies) {
    if (by_genre == movie.get_genre()) {
      movie.show_general();
      actual_genre = true;
    }
  }
  for(Series &serie: series) {
    if (by_genre == serie.get_genre()) {
      serie.show_general();
      actual_genre = true;
    }
  }
  if (actual_genre != true) {
    std::cout << "\n> There are no movies or series with the specified genre." << std::endl;
    return;
  }
}

std::vector<Video> get_highest_rated_movies() { //These methods return vectors
    double highest_rating = 0;
    highest_rated_movies.clear();
    for (Video &movie : movies) {
        if (movie.get_rating() > highest_rating) {
            highest_rating = movie.get_rating();
            highest_rated_movies.clear();
            highest_rated_movies.push_back(movie);
        }
        else if (movie.get_rating() == highest_rating) {
            highest_rated_movies.push_back(movie);
        }
    }
    return highest_rated_movies;
}

std::vector<Series> get_highest_rated_series() {
    double highest_rating = 0;
    highest_rated_series.clear();
    for (Series &serie : series) {
        if (serie.get_rating() > highest_rating) {
            highest_rating = serie.get_rating();
            highest_rated_series.clear();
            highest_rated_series.push_back(serie);
        } else if (serie.get_rating() == highest_rating) {
            highest_rated_series.push_back(serie);
        }
    }
    return highest_rated_series;
}

void show_highest_rated_movies() {
  get_highest_rated_movies();
  std::cout << "\n===== Highest rated movies =====" << std::endl;
  for (Video &movie: highest_rated_movies) {
    movie.show_info();
  }
}

void show_highest_rated_series() {
  get_highest_rated_series();
  std::cout << "\n===== Highest rated series =====" << std::endl;
  for (Series &serie: highest_rated_series) {
    serie.show_info();
  }
}

void select_movie() {
  std::cout << "\n===== Search content by ID ===== " << std::endl;
  std::cout << "\n> "; std::cin >> movie_input;
  bool found = false;
  for(Video &movie: movies) {
    if (movie_input == movie.get_id()) {
      movie.show_info();
      movie_to_search = movie;
      found = true;
      break;
    }
  }
  if (found != true) {
    std::cout << "\n> Movie not found." << std::endl;
    return;
  }
}

void select_series() {
  std::cout << "\n=====  Search content by ID ===== " << std::endl;
  std::cout << "\n> "; std::cin >> series_input;
  bool found = false;
  for(Series &serie: series) {
    if (series_input == serie.get_id()) {
      serie.show_info();
      series_to_search = serie;
      found = true;
      break;
    }
  }
  if (found != true) {
    std::cout << "\n> Series not found." << std::endl;
    return;
  }
}

void show_episodes() {
  switch (series_input)
  {
  case 6:
    for (Episode episode:Fallout_episodes) {
      episode.show_info();
    }
    break;
  case 7:
    for (Episode episode:LOKI_episodes) {
      episode.show_info();
    }
    break;
  case 8:
    for (Episode episode:Arcane_episodes) {
      episode.show_info();
    }
    break;
  case 9:
    for (Episode episode:Daredevil_episodes) {
      episode.show_info();
    }
    break;
  case 10:
    for (Episode episode:Parasyte_episodes) {
      episode.show_info();
    }
    break;
  default:
    std::cout << "\n> No series selected." << std::endl;
    break;
  }
}

void movie_search_menu() {
  std::cout << "\n===== Actions =====" << std::endl;
  std::cout << "Rate movie [1]" << std::endl;
  std::cout << "Go back to main menu [2]" << std::endl;
  std::cout << "Exit [3]" << std::endl;
  std::cout << "\n> "; std::cin >> choice;
}

void series_search_menu() {
  std::cout << "\n===== Actions =====" << std::endl;
  std::cout << "Rate series [1]" << std::endl;
  std::cout << "Show episodes [2]" << std::endl;
  std::cout << "Go back to main menu [3]" << std::endl;
  std::cout << "Exit [4]" << std::endl;
  std::cout << "\n> "; std::cin >> choice;
}

void handle_series_search_menu() {
  bool rate = false;
  switch (choice) {
    case 1:
      for(Series &serie: series) {
        if (series_input == serie.get_id()) {
          serie.set_rating();
          rate = true;
          break;
        }
      }
      if (rate != true) {
        std::cout << "\n> No series selected." << std::endl;
      }
      series_search_menu();
      handle_series_search_menu();
      break;
    case 2:
      show_episodes();
      series_search_menu();
      handle_series_search_menu();
    case 3:
      break;
    case 4:
      exit_program();
    default:
      std::cout << "\n> Invalid command prompt." << std::endl;
      break;
  }
}

void handle_movie_search_menu() {
  bool rate = false;
  switch (choice) {
    case 1:
      for(Video &movie: movies) {
        if (movie_input == movie.get_id()) {
          movie.set_rating();
          rate = true;
          break;
        }
      }
      if (rate != true) {
        std::cout << "\n> No movie selected." << std::endl;
      }
      movie_search_menu();
      handle_movie_search_menu();
      break;
    case 2:
      break;
    case 3:
      exit_program();
    default:
      std::cout << "\n> Invalid command prompt." << std::endl;
      break;
  }
}

void handle_additional_series_menu() {
  switch (choice) {
    case 1:
      select_series();
      series_search_menu();
      handle_series_search_menu();
      break;
    case 2:
      show_highest_rated_series();
      series_search_menu();
      handle_series_search_menu();
    case 3:
      show_all_series_info();
      additional_series_menu();
      handle_additional_series_menu();
      break;
    case 4:
      break;
    case 5:
      exit_program();
    default:
      std::cout << "\n> Invalid command prompt." << std::endl;
      break;
  }
}

void handle_additional_movies_menu() {
  switch (choice) {
    case 1:
      select_movie();
      movie_search_menu();
      handle_movie_search_menu();
      break;
    case 2:
      show_highest_rated_movies();
      movie_search_menu();
      handle_movie_search_menu();
    case 3:
      show_all_movies_info();
      additional_movies_menu();
      handle_additional_movies_menu();
      break;
    case 4:
      break;
    case 5:
      exit_program();
    default:
      std::cout << "\n> Invalid command prompt." << std::endl;
      break;
  }
}

void handle_additional_general_menu() {
  switch (choice) {
    case 1:
      show_all_movies();
      additional_movies_menu();
      handle_additional_movies_menu();
      break;
    case 2:
      show_all_series();
      additional_series_menu();
      handle_additional_series_menu();
      break;
    case 3:
      show_highest_rated_movies();
      show_highest_rated_series();
      additional_general_menu();
      handle_additional_general_menu();
    case 4:
      break;
    case 5:
      exit_program();
    default:
      std::cout << "\n> Invalid command prompt." << std::endl;
      break;
  }
}

int main() {

  Video Baby_Driver(1, "Baby Driver", "2017", "Action", 115, 5); movies.push_back(Baby_Driver);
  Video Upgrade(2, "Upgrade", "2018", "Action", 100, 4.7); movies.push_back(Upgrade);
  Video Tron_Legacy(3, "Tron Legacy", "2010", "Sci-Fi", 125, 4.3); movies.push_back(Tron_Legacy);
  Video The_Dark_Knight( 4, "The Dark Knight","2008", "Action", 152, 5); movies.push_back(The_Dark_Knight);
  Video District_9(5, "District 9", "2009", "Action", 112, 4); movies.push_back(District_9);

  Series Fallout(6, "Fallout", "2024", "Sci-Fi", 4.9, 1, 8); series.push_back(Fallout);
  Series LOKI(7, "LOKI", "2021", "Sci-Fi", 4.6, 2, 12); series.push_back(LOKI);
  Series Arcane(8, "Arcane", "2021", "Action", 5, 1, 10); series.push_back(Arcane);
  Series Daredevil(9, "Daredevil", "2015", "Action", 5, 3, 39); series.push_back(Daredevil);
  Series Parasyte(10, "Parasyte", "2024", "Horror", 4, 1, 6); series.push_back(Parasyte);

  Episode Fallout_1("The End", 1, 1, 1); Fallout_episodes.push_back(Fallout_1);
  Episode Fallout_2("The Target", 1, 2, 1); Fallout_episodes.push_back(Fallout_2);
  Episode Fallout_3("The Head", 1, 3, 1); Fallout_episodes.push_back(Fallout_3);

  Episode LOKI_1("Glorious Purpose", 1, 1, 1); LOKI_episodes.push_back(LOKI_1);
  Episode LOKI_2("The Variant", 1, 2, 1); LOKI_episodes.push_back(LOKI_2);
  Episode LOKI_3("Lamentis", 1, 3, 1); LOKI_episodes.push_back(LOKI_3);

  Episode Arcane_1("Welcome to the Playground", 1, 1, 1); Arcane_episodes.push_back(Arcane_1);
  Episode Arcane_2("Some Mysteries Are Better Left Unsolved", 1, 2, 1); Arcane_episodes.push_back(Arcane_2);
  Episode Arcane_3("The Base Violence Necessary for Change", 1, 3, 1); Arcane_episodes.push_back(Arcane_3);

  Episode Daredevil_1("Into the Ring", 1, 1, 1); Daredevil_episodes.push_back(Daredevil_1);
  Episode Daredevil_2("Cut Man", 1, 2, 1); Daredevil_episodes.push_back(Daredevil_2);
  Episode Daredevil_3("Rabbit in a Snow Storm", 1, 3, 1); Daredevil_episodes.push_back(Daredevil_3);

  Episode Parasyte_1("Episode 1", 1, 1, 1); Parasyte_episodes.push_back(Parasyte_1);
  Episode Parasyte_2("Episode 2", 1, 2, 1); Parasyte_episodes.push_back(Parasyte_2);
  Episode Parasyte_3("Episode 3", 1, 3, 1); Parasyte_episodes.push_back(Parasyte_3);

  std::cout << "\nWelcome! Use the assigned command numbers to use the menu." << std::endl;

  do 
  {
    show_main_menu();

    switch (choice)
    {
    case 1: //Show all available content
      std::cout << "\n===== Movies & Series =====" << std::endl;
      show_all_movies();
      show_all_series();
      additional_general_menu();
      handle_additional_general_menu();
      break;

    case 2: //Go to movies
      std::cout << "\n===== Movies =====" << std::endl;
      show_all_movies();
      additional_movies_menu();
      handle_additional_movies_menu();
      break;

    case 3: //Go to series
      std::cout << "\n===== Series =====" << std::endl;
      show_all_series();
      additional_series_menu();
      handle_additional_series_menu();
      break;

    case 4: //Search content
      std::cout << "\n Search Movie or Series?: " << std::endl;
      std::cout << "\n> "; std::cin >> movie_or_series;
      if (movie_or_series == "Movie" || movie_or_series == "movie" || movie_or_series == "MOVIE") {
        select_movie();
        movie_search_menu();
        handle_movie_search_menu();
        break;
      }
      else if (movie_or_series == "Series" || movie_or_series == "series" || movie_or_series == "SERIES") {
        std::cout << "\n Search content by Name or by ID?: " << std::endl;
        select_series();
        series_search_menu();
        handle_series_search_menu();
        break;
      }
      else {
        std::cout << "Invalid content type." << std::endl;
        break;
      }
      break;
    case 5:
      show_by_genre();
      break;
    case 6: //Exit program
      exit_program();
    default:
      std::cout << "\nInvalid command prompt." << std::endl;
      break;
    }
  } while (exitChoice == "N" || exitChoice == "n");

  return 0;
}