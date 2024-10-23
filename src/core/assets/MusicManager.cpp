#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <dirent.h>
#include <cstring>
#include "MusicManager.hpp"

using namespace std;
using namespace sf;


void MusicManager::loadMusics(const string& directory) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                string fileName = ent->d_name;
                musicsPathes.push_back(directory + "/" + ent->d_name);       
            }
        }
        closedir(dir);
    }
}

Music& MusicManager::loadSingleMusic(const string& pathToSound){
    singleMusic.openFromFile(pathToSound);
    return singleMusic;
}

void MusicManager::playSingleMusic() {
    singleMusic.play();
}

void MusicManager::playRandomMusic() {
    if (musicsPathes.empty()) {
        std::cout << "No musics loaded yet!" << std::endl;
        return;
    }

    std::srand(std::time(0));
    int randomIndex = std::rand() % musicsPathes.size();

    singleMusic.openFromFile(musicsPathes[randomIndex]);
    playSingleMusic();
}