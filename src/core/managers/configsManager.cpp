#include "configsManager.hpp"
#include "../../utilities/utilities.hpp"

#include <fstream>
#include <iostream>

bool ConfigsManager::init(std::string configFile) {
    _configFilePath = configFile;
    _version = "0.0.0";
    _screenWidth = 800;
    _screenHeight = 600;
    _mainFontPath = "./assets/fonts/disposabledroid-bb.regular.ttf";
    _titleImagePath = "./assets/images/title_screen.png";
    _verticalSync = true;
    _showFPS = false;

    if (configFile == "") {
        return true;
    }

    std::ifstream infile(_configFilePath);
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            if (line == "") continue;
            int len = line.length();
            std::string tag = "";
            std::string value = "";
            bool flag = false;
            for (int i = 0; i < len; i ++) {
                if (line[i] == '#') {
                    break;
                } else if (line[i] == '=') {
                    flag = true;
                } else {
                    if (flag) {
                        value += line[i];
                    } else {
                        tag += line[i];
                    }
                }
            }
            tag = Utilities::trim(tag);
            value = Utilities::trim(value);
            if (tag == "VERSION") {
                _version = value;
            } else if (tag == "SCREEN_WIDTH" && Utilities::isNat(value)) {
                _screenWidth = std::stoi(value);
            } else if (tag == "SCREEN_HEIGHT" && Utilities::isNat(value)) {
                _screenHeight = std::stoi(value);
            } else if (tag == "MAIN_FONT") {
                _mainFontPath = value;
            } else if (tag == "TITLE_IMAGE") {
                _titleImagePath = value;
            } else if (tag == "VERTICAL_SYNC") {
                _verticalSync = Utilities::toBool(value);
            } else if (tag == "SHOW_FPS") {
                _showFPS = Utilities::toBool(value);
            }
        }
    } else {
        std::cerr << "Unable to open config file: " << _configFilePath << std::endl;
        return false;
    }

    return true;
}