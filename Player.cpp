#include "Player.h"

Player::Player(SDL_Renderer* _renderer, const char* _spritePath)
	: Character(_renderer, _spritePath)
{
	input = new PlayerInputComponent(this);
}

Player::~Player()
{
	delete input;
	delete collider;
}

void Player::Attack(Vector2 dir)
{
	Projectile* bul = new Projectile(renderer, "assets/Projectile/FlintlockBullet.png", dir, GetPosition());
}

void Player::Deflect()
{
}

void Player::Dodge()
{
}

PlayerInputComponent* Player::GetInputComponent()
{
	return input;
}
