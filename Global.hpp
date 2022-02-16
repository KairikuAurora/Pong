#pragma once

constexpr unsigned short SCREEN_WIDTH = 800;
constexpr unsigned short SCREEN_HEIGHT = 600;

constexpr char BALL_SIZE = 10;

constexpr char RACKET_WIDTH = 15;
constexpr char RACKET_HEIGHT = 90;

constexpr unsigned short LEFT_RACKET_X = 5;
constexpr unsigned short RIGHT_RACKET_X = SCREEN_WIDTH - RACKET_WIDTH - 5;

struct Position
{
	short x;
	short y;
};