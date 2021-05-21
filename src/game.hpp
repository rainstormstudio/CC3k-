/**
 * @file game.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This is the main game class
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef GAME_HPP
#define GAME_HPP

class Game {
private:
    bool _looping;
public:
    bool init();
    void run();
};

#endif
