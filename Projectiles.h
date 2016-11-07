#pragma once
#include "Constants.h"
#include "Player.h"
#include "Box.h"
#include "Enemy.h"
#include <SDL.h>
#include <vector>

class Projectile{
public:
	int x, y, w, h;
	static std::vector<Projectile> Bullets;
	Projectile(int x, int y, int w = PROJ_W, int h = PROJ_H) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	static void createProjectile(int, int,int,int); 
	static void Draw(SDL_Renderer* ren);
	static void Update();

};

std::vector<Projectile> Projectile::Bullets;


void Projectile::createProjectile(int x, int y, int w = PROJ_W, int h = PROJ_H) {
	Bullets.push_back(Projectile(x, y, w, h));
}

void Projectile::Draw(SDL_Renderer* ren) {
	SDL_SetRenderDrawColor(ren, 255, 255,0, 255);
	for (Projectile &p : Bullets) {
		SDL_Rect rect;
		rect.x = p.x;
		rect.y = p.y;
		rect.w = p.w;
		rect.h = p.h;
		SDL_RenderFillRect(ren, &rect);
	}
}

void Projectile::Update() {
	std::vector<Projectile>present;
	for (Projectile &p : Bullets) {
		p.x += LSR_SPEED;
		if (p.x < SCREEN_WIDTH) {
			present.push_back(p);
		}
	}
	Bullets = present;
}