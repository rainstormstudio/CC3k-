/**
 * @file configsManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the configs manager
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>

class ConfigsManager {
private:
    std::string _configFilePath;

    std::string _version;
    const std::string _author = "DiamondSlug";
    const std::string _authorEmail = "rainstormstudio@yahoo.com";
    const std::string _copyright = "Copyright (c) 2021";
    int _screenWidth;
    int _screenHeight;

    std::string _mainFontPath;

    std::string _whiteTexturePath;
    std::string _titleImagePath;

    std::string _titleVShaderPath;
    std::string _titleFShaderPath;

    bool _verticalSync;

    bool _showFPS;

    ConfigsManager() {}

public:
    ConfigsManager(ConfigsManager const&) = delete;
    void operator=(ConfigsManager const&) = delete;

    static ConfigsManager& getInstance() {
        static ConfigsManager instance;
        return instance;
    }

    bool init(std::string configFile = "");

    std::string version() const {
        return _version;
    }

    std::string author() const {
        return _author;
    }

    std::string authorEmail() const {
        return _authorEmail;
    }

    std::string copyRight() const {
        return _copyright;
    }

    int screenWidth() const {
        return _screenWidth;
    }

    int screenHeight() const {
        return _screenHeight;
    }

    std::string mainFontPath() const {
        return _mainFontPath;
    }

    std::string whiteTexturePath() const {
        return _whiteTexturePath;
    }

    std::string titleImagePath() const {
        return _titleImagePath;
    }

    std::string titleVShaderPath() const {
        return _titleVShaderPath;
    }

    std::string titleFShaderPath() const {
        return _titleFShaderPath;
    }

    bool verticalSync() const {
        return _verticalSync;
    }

    bool showFPS() const {
        return _showFPS;
    }
};

#endif