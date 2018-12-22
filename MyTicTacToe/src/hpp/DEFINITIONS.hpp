#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1136

#define SPLASH_STATE_SHOW_TIME 3
#define SPLASH_SCENE_BACKGROUND_FILEPATH "res/res/Splash Background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "res/res/Main Menu Background.png"
#define MAIN_MENU_TITLE_PATH "res/res/Game Title.png"
#define MAIN_MENU_PLAY_BUTTON "res/res/Play Button.png"
#define MAIN_MENU_1P_PLAY_BUTTON "res/edit/1P Play Button.png"
#define MAIN_MENU_2P_PLAY_BUTTON "res/edit/2P Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "res/res/Play Button Outer.png"

#define GAME_BACKGROUND_FILEPATH "res/res/Main Menu Background.png"
#define PAUSE_BUTTON "res/res/Pause Button.png"

#define X_PIECE_FILEPATH "res/res/X.png"
#define O_PIECE_FILEPATH "res/res/O.png"
#define X_WINNING_PIECE_FILEPATH "res/res/X Win.png"
#define O_WINNING_PIECE_FILEPATH "res/res/O Win.png"

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define PAUSE_BACKGROUND_FILEPATH "res/res/Pause Background.png"
#define RESUME_BUTTON "res/edit/Resume Button.png"
#define HOME_BUTTON "res/edit/Home Button.png"

#define RETRY_BUTTON "res/edit/Retry Button.png"

#define GRID_SPRITE_FILEPATH "res/res/grid.png"

#define TIME_BEFORE_SHOWING_GAMEOVER 3

#define GAME_OVER_X_WON_FILEPATH "res/edit/Game Over X Won.png"
#define GAME_OVER_O_WON_FILEPATH "res/edit/Game Over O Won.png"
#define GAME_OVER_DRAW_FILEPATH "res/edit/Game Over Draw.png"

#define START_GAME_CLICK_SOUND_FILEPATH "res/snd/Start Game.wav"
#define GRID_CLICK_SOUND_FILEPATH "res/snd/Grid Click Sound.wav"
#define CLICK_SOUND_1_FILEPATH "res/snd/Click1.wav"
#define CLICK_SOUND_2_FILEPATH "res/snd/Click2.wav"