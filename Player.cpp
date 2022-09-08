#include "Player.h"
#include "PlayerHealthComponent.h"

Player::Player(SDL_Renderer* _renderer, const char* _spritePath)
	: Character(_renderer, _spritePath)
{
	input = new PlayerInputComponent(this);
	health = &AddComponent<PlayerHealthComponent>();
}

Player::Player(SDL_Renderer* _renderer, const char* _spritePath, SpriteAnimInfo* _animInfo)
	: Character(_renderer, _spritePath, _animInfo)
{
	input = new PlayerInputComponent(this);
	health = &AddComponent<PlayerHealthComponent>();
}

Player::~Player()
{
	delete input;
	delete health;
}

void Player::Attack(Vector2 dir)
{
	Vector2 bulSpawnPos = GetPosition() + bulSpawnOffset;
	Projectile* bul = new Projectile(renderer, bulSpritePath, dir, bulSpawnPos, 2);
}

void Player::Deflect()
{
}

void Player::Dodge()
{
}