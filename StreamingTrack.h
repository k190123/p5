// Copyright ksakers
#ifndef STREAMINGTRACK_H_
#define STREAMINGTRACK_H_

#include <iostream>
#include <string>
#include "SongRecording.h"
namespace csce240_programming_assignment_5 {
    class StreamingTrack : public SongRecording {
    private:
        int timesStreamed;
        std::string* genres;
        int numGenres;

    public:
        StreamingTrack(std::string title = "untitled",
            std::string primaryArtist = "unknown",
            int numArtists = 0, int trackLengthSeconds = 1,
            std::string primaryGenre = "pop",
            int timesStreamed = 0);

        explicit StreamingTrack(const StreamingTrack& existingSongRecording);

        ~StreamingTrack();

        StreamingTrack& operator=(const StreamingTrack& other);

        std::string getTitle() const;
        int GetStreams();
        void SetStreams(int streams);
        void AddStreams(int streams);

        int GetNumGenres();
        std::string GetGenre(int genre = 1);
        bool IsGenre(std::string genre);
        void AddGenre(std::string genre);
        void RemoveGenre(std::string genre);
    };
}

#endif
