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
	Vector2 bulSpawnPos = GetPosition() + bulSpawnOffset;
	Projectile* bul = new Projectile(renderer, bulSpritePath, dir, bulSpawnPos);
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
