#pragma once

struct Hitbox {
	int x;
	int y;
	int w;
	int h;

	Hitbox() {
		x = y = w = h = 0;
	}

	Hitbox(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	bool colisiona(Hitbox h) {
		return this->x < (h.x + h.w) &&
			(this->x + this->w) > h.x &&
			this->y < (h.y + h.h) &&
			(this->y + this->h) > h.y;
	}
};