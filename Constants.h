#pragma once
#include <SDL.h>
static int rand_state;
int rand();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PROJ_W = 20;
const int PROJ_H = 2;
const int LSR_SPEED = 20;
const int ENEMY_W = 40;
const int ENEMY_H = 40;
const int ENEMY_S = -5;

int rand()
{
	rand_state = (rand_state * 1103515245 + 12345) & 0x7fffffff;
	return rand_state;
}