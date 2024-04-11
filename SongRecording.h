// Copyright ksakers
#ifndef SONGRECORDING_H_
#define SONGRECORDING_H_

#include <iostream>
#include <string>
namespace csce240_programming_assignment_5 {
    class SongRecording {
    private:
        std::string songTitle;
        std::string* artistNames;
        int numArtists;
        int trackLengthSeconds;

    public:
        SongRecording(std::string title = "untitled",
            std::string primaryArtist = "unknown",
            int numArtists = 0, int trackLengthSeconds = 1);

        explicit SongRecording(const SongRecording& existingSongRecording);

        ~SongRecording();

        SongRecording& operator=(const SongRecording& other);

        std::string GetTitle();
        int GetNumArtists();
        int GetTrackLength();

        void SetTitle(const std::string& title);
        void SetNumArtists(int num);
        void SetArtist(const std::string& artist, int index = 1);
        std::string GetArtist(int index = 1);
        void SetTrackLength(int length);
    };
}

#endif
