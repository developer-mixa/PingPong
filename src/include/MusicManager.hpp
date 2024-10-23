#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <dirent.h>
#include <cstring>

using namespace std;
using namespace sf;

class MusicManager {
public:
    void loadMusics(const string& directory);
    Music& loadSingleMusic(const string& pathToMusic);
    void playSingleMusic();
    void playRandomMusic();
    
private:
    std::vector<string> musicsPathes;
    Music singleMusic;
};