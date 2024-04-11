// Copyright ksakers

#include <iostream>
#include <string>
#include "StreamingTrack.h"
using csce240_programming_assignment_5::StreamingTrack;
int StreamingTrack::GetStreams() {
  return this->timesStreamed;
}
void StreamingTrack::SetStreams(int streams) {
  if (streams > 0)
    this->timesStreamed = streams;
}
void StreamingTrack::AddStreams(int streams) {
  if (streams > 0)
    this->timesStreamed += streams;
}
int StreamingTrack::GetNumGenres() {
  return this->numGenres;
}
std::string StreamingTrack::GetGenre(int genre) {
  return this->genres[genre];
}
bool StreamingTrack::IsGenre(std::string genre) {
  // iterate genres
  for (int i = 0; i < GetNumGenres(); i++) {
    if (this->genres[i] == genre)
      return true;
  }
  return false;
}
void StreamingTrack::AddGenre(std::string genre) {
  bool genreExists = false;

  // check if already in
  for (int i = 0; i < GetNumGenres(); i++) {
    // if not, add
    if (this->genres[i] == genre) {
      genreExists = true;
      break;
    }
  }

  // updating the pointer data member and the number of genres data
  // member
  if (!genreExists) {
    this->numGenres++;

    // update pointer
    if (this->genres != nullptr)
      delete[] this->genres;  // remove old genres

    this->genres = new std::string[this->numGenres];

  }

}
void StreamingTrack::RemoveGenre(std::string genre) {
    bool genreExists = false;

    // check if already in
    for (int i = 0; i < GetNumGenres(); i++) {
        // if not, add
        if (this->genres[i] == genre) {
            genreExists = true;
            break;
        }
    }
    int indexToRemove = 0;

    if (genreExists) {
        // find index of genre
        for (int i = 0; i < GetNumGenres(); i++) {
            if (this->genres[i] == genre) {
                indexToRemove = i;
                break;
            }

            std::string* newGenreArray = new std::string[numGenres - 1];
            // copy beginning to genre being removed
            for (int i = 0; i < indexToRemove; i++) {
                newGenreArray[i] = genres[i];
            }
            // copy genre being removed to end
            for (int i = indexToRemove + 1; i < numGenres; i++) {
                newGenreArray[i - 1] = genres[i];
            }

            delete[] genres;

            genre = *newGenreArray;

            // update count
            this->numGenres--;
        }
    }
}
