/*
Question 10: Create a multimedia management system with base class MediaFile and derived classes Audio, Video, Image. 
Override displayMetadata() and add format-specific logic.
*/

#include <iostream>
using namespace std;

class MediaFile {
protected:
    string fileName;
    double fileSize;  // in MB
    string format;
public:
    MediaFile(string name, double size, string fmt) 
        : fileName(name), fileSize(size), format(fmt) {}
    
    virtual void displayMetadata() {
        cout << "File: " << fileName << ", Size: " << fileSize << "MB, Format: " << format;
    }
    
    virtual void play() = 0;
};

class Audio : public MediaFile {
private:
    int duration;  // in seconds
    string artist;
public:
    Audio(string name, double size, string fmt, int dur, string art) 
        : MediaFile(name, size, fmt), duration(dur), artist(art) {}
    
    void displayMetadata() override {
        cout << "[AUDIO] ";
        MediaFile::displayMetadata();
        cout << ", Duration: " << duration << "s, Artist: " << artist << endl;
    }
    
    void play() override {
        cout << "Playing audio: " << fileName << " by " << artist << endl;
    }
};

class Video : public MediaFile {
private:
    string resolution;
    int duration;  // in seconds
public:
    Video(string name, double size, string fmt, string res, int dur) 
        : MediaFile(name, size, fmt), resolution(res), duration(dur) {}
    
    void displayMetadata() override {
        cout << "[VIDEO] ";
        MediaFile::displayMetadata();
        cout << ", Resolution: " << resolution << ", Duration: " << duration << "s" << endl;
    }
    
    void play() override {
        cout << "Playing video: " << fileName << " at " << resolution << endl;
    }
};

class Image : public MediaFile {
private:
    string resolution;
    string colorDepth;
public:
    Image(string name, double size, string fmt, string res, string color) 
        : MediaFile(name, size, fmt), resolution(res), colorDepth(color) {}
    
    void displayMetadata() override {
        cout << "[IMAGE] ";
        MediaFile::displayMetadata();
        cout << ", Resolution: " << resolution << ", Color: " << colorDepth << endl;
    }
    
    void play() override {
        cout << "Displaying image: " << fileName << endl;
    }
};

int main() {
    Audio a("song.mp3", 4.5, "MP3", 180, "The Beatles");
    Video v("movie.mp4", 1200.0, "MP4", "1920x1080", 7200);
    Image i("photo.jpg", 2.8, "JPEG", "4000x3000", "24-bit");
    
    cout << "Multimedia Library:\n\n";
    
    a.displayMetadata();
    a.play();
    
    cout << "\n";
    
    v.displayMetadata();
    v.play();
    
    cout << "\n";
    
    i.displayMetadata();
    i.play();
    
    return 0;
}
