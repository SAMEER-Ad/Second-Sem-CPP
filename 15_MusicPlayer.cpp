/*
Question 15: Simulate a music player where MediaFile is an abstract class with method play(). 
Derived classes MP3, WAV, FLAC each load and play files differently. 
Use runtime polymorphism to handle different media types in a playlist.
*/

#include <iostream>
#include <vector>
using namespace std;

class MediaFile {
protected:
    string fileName;
    string artist;
    int duration;  // in seconds
public:
    MediaFile(string name, string art, int dur) 
        : fileName(name), artist(art), duration(dur) {}
    
    virtual void play() = 0;  // Pure virtual method
    
    virtual void showInfo() {
        cout << "File: " << fileName << " by " << artist 
             << " (" << duration << "s)" << endl;
    }
    
    string getFileName() { return fileName; }
    
    virtual ~MediaFile() {}
};

class MP3 : public MediaFile {
private:
    int bitrate;
public:
    MP3(string name, string art, int dur, int br) 
        : MediaFile(name, art, dur), bitrate(br) {}
    
    void play() override {
        cout << "[MP3 PLAYER]" << endl;
        showInfo();
        cout << "Bitrate: " << bitrate << " kbps" << endl;
        cout << "Loading MP3 decoder..." << endl;
        cout << "Decompressing audio stream..." << endl;
        cout << "♪ Now playing MP3 file ♪" << endl;
    }
};

class WAV : public MediaFile {
private:
    int sampleRate;
public:
    WAV(string name, string art, int dur, int sr) 
        : MediaFile(name, art, dur), sampleRate(sr) {}
    
    void play() override {
        cout << "[WAV PLAYER]" << endl;
        showInfo();
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
        cout << "Loading uncompressed audio..." << endl;
        cout << "High quality playback mode" << endl;
        cout << "♪ Now playing WAV file ♪" << endl;
    }
};

class FLAC : public MediaFile {
private:
    string compression;
public:
    FLAC(string name, string art, int dur, string comp) 
        : MediaFile(name, art, dur), compression(comp) {}
    
    void play() override {
        cout << "[FLAC PLAYER]" << endl;
        showInfo();
        cout << "Compression: " << compression << endl;
        cout << "Loading FLAC decoder..." << endl;
        cout << "Lossless decompression in progress..." << endl;
        cout << "♪ Now playing FLAC file ♪" << endl;
    }
};

class MusicPlayer {
private:
    vector<MediaFile*> playlist;
    int currentTrack;
public:
    MusicPlayer() : currentTrack(0) {}
    
    void addToPlaylist(MediaFile* media) {
        playlist.push_back(media);
        cout << "Added to playlist: " << media->getFileName() << endl;
    }
    
    void showPlaylist() {
        cout << "\n=== PLAYLIST ===" << endl;
        for (size_t i = 0; i < playlist.size(); i++) {
            cout << (i + 1) << ". ";
            playlist[i]->showInfo();
        }
        cout << endl;
    }
    
    void playAll() {
        cout << "Playing entire playlist:\n" << endl;
        for (size_t i = 0; i < playlist.size(); i++) {
            cout << "Track " << (i + 1) << ":" << endl;
            playlist[i]->play();  // Polymorphic call
            cout << "\n";
        }
    }
    
    void playTrack(int index) {
        if (index >= 0 && index < playlist.size()) {
            cout << "Playing track " << (index + 1) << ":" << endl;
            playlist[index]->play();
        } else {
            cout << "Invalid track number!" << endl;
        }
    }
    
    ~MusicPlayer() {
        for (MediaFile* media : playlist) {
            delete media;
        }
    }
};

int main() {
    MusicPlayer player;
    
    // Create different media files
    MP3* mp3File = new MP3("Song1.mp3", "Artist A", 210, 320);
    WAV* wavFile = new WAV("Song2.wav", "Artist B", 195, 44100);
    FLAC* flacFile = new FLAC("Song3.flac", "Artist C", 240, "Lossless");
    MP3* mp3File2 = new MP3("Song4.mp3", "Artist D", 180, 256);
    
    cout << "Music Player - Polymorphic Media Handling\n" << endl;
    
    // Add to playlist
    player.addToPlaylist(mp3File);
    player.addToPlaylist(wavFile);
    player.addToPlaylist(flacFile);
    player.addToPlaylist(mp3File2);
    
    // Show playlist
    player.showPlaylist();
    
    // Play specific track
    player.playTrack(1);  // Play WAV file
    cout << "\n";
    
    // Play entire playlist
    player.playAll();
    
    return 0;
}
