#include "Player.h"
#include "PlayerHealthComponent.h"

Player::Player(SDL_Renderer* _renderer, const char* _spritePath, int _layer)
	: Character(_renderer, _spritePath, _layer)
{
	input = new PlayerInputComponent(this);
	health = &AddComponent<PlayerHealthComponent>();
}

Player::Player(SDL_Renderer* _renderer, const char* _spritePath, SpriteAnimInfo* _animInfo, int _layer)
	: Character(_renderer, _spritePath, _animInfo, _layer)
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
	bul->SetName("Bullet");
}

void Player::Deflect()
{
}

void Player::Dodge()
{
}