// Copyright ksakers
#include <iostream>
#include <string>
#include "SongRecording.h"

using std::string;
using csce240_programming_assignment_5::SongRecording;
    SongRecording::SongRecording(string title,
        string primaryArtist,
        int numArtists,
        int trackLengthSeconds) {
        SetTitle(title);
        SetNumArtists(numArtists);
        SetArtist(primaryArtist);
        SetTrackLength(trackLengthSeconds);
    }
    SongRecording::~SongRecording() {
        if (this->artistNames != nullptr)
            delete[] this->artistNames;
    }
    SongRecording& SongRecording::operator=(const SongRecording& other) {
        if (this != &other)
            *this = other;
        return *this;
    }
    SongRecording::SongRecording(
        const SongRecording& existingSongRecording) {
        *this = existingSongRecording;
    }
    string SongRecording::GetTitle() {
        return this->songTitle;
    }
    int SongRecording::GetNumArtists() {
        return this->numArtists;
    }
    int SongRecording::GetTrackLength() {
        return this->trackLengthSeconds;
    }

    void SongRecording::SetTitle(const std::string& title) {
        if (title.size() > 0)
            this->songTitle = title;
    }
    void SongRecording::SetNumArtists(int num) {
        if (num > 0)
            this->numArtists = num;
        // Manages memory for the string pointer data member.
        this->artistNames = new string[this->numArtists];

    }
    void SongRecording::SetArtist(const std::string& artist, int index) {
        if (artist.size() > 0 && (index > 0 && index <= this->numArtists)) {
            artistNames[index] = artist;
        }
    }
    std::string SongRecording::GetArtist(int index) {
        if (index > this->numArtists)
            return "out of bounds";

        return this->artistNames[index];
    }
    void SongRecording::SetTrackLength(int length) {
        if (length > 0)
            this->trackLengthSeconds = length;
    }
