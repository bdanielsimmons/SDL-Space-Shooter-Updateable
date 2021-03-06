#pragma once
#include <SDL.h>
#include "Constants.h"
#include "Projectiles.h"
#include <vector>

class Player {
private:
	int now, timepass, health;
	SDL_Texture* image;
public:
	static int x, y, w, h;
	Player(static int x, static int y, SDL_Texture* image, int h = BASE_HEALTH) {
		this->image = image;
		this->x = x;
		this->y = y;
		SDL_QueryTexture(image, NULL, NULL, &this->w, &this->h);
		this->health = h;
	}
	void Update(const Uint8* keys);
	void Draw(SDL_Renderer* ren);

};

int Player::x; int Player::y; int Player::w; int Player::h;


void Player::Update(const Uint8* keys) {
	if (keys[SDL_SCANCODE_UP]) y -= 10;
	if (keys[SDL_SCANCODE_DOWN]) y += 10;
	if (keys[SDL_SCANCODE_LEFT]) x -= 10;
	if (keys[SDL_SCANCODE_RIGHT]) x += 10;
	if (keys[SDL_SCANCODE_SPACE]) {
		now = SDL_GetTicks();
		if (now > timepass + 50) {
			Projectile::createProjectile(x + w, y + (h - PROJ_H) / 2);
		}
		timepass = now;
	}
	if (x < 0) x = 0;
	if (x > (SCREEN_WIDTH - w)) x = SCREEN_WIDTH - w;
	if (y < 0) y = 0;
	if (y > SCREEN_HEIGHT - h) y = SCREEN_HEIGHT - h;
}

void Player::Draw(SDL_Renderer *ren) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, image, NULL, &dst);
}