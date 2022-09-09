#include "Player.h"
#include "Sprite.h"
#include "ColliderComponent2D.h"
#include "VelocityComponent.h"

Player::Player(SDL_Renderer* _renderer, int _layer)
	: Character(_renderer, _layer)
{
	anims =
	{
		SpriteAnimInfo("assets/Character/Player/idle.png", 4, 200, 200, 145, 16),
		SpriteAnimInfo("assets/Character/Player/run.png", 4, 200, 200, 145, 24),
	};

	SetName("Player");
	speed = 7;
	acceleration = 3;
	deceleration = 5;
	defaultSpritePath = "assets/Character/Player/idle_0.png";

	sprite = &AddComponent<Sprite>(renderer, defaultSpritePath);
	collider = &AddComponent<ColliderComponent2D>(sprite);
	velComp = &AddComponent<VelocityComponent>(speed, acceleration, deceleration);
	input = new PlayerInputComponent(this);
	//health = &AddComponent<PlayerHealthComponent>();

	// initialise with idle anim
	sprite->Set(&anims[0]);
}

Player::~Player()
{
	delete input;
	delete health;
}

void Player::Move(Vector2 dir)
{
	if (!moving)
		sprite->Set(&anims[1]);

	Character::Move(dir);
}

void Player::StopMoving()
{
	sprite->Set(&anims[0]);
	Character::StopMoving();
}

void Player::Attack(Vector2 dir)
{
	Vector2 bulSpawnPos = GetPosition() + bulSpawnOffset;
	Projectile* bul = new Projectile(renderer, dir, bulSpawnPos, 2);
}

void Player::Deflect()
{
}

void Player::Dodge()
{
}