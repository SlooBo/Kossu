#pragma once

class Bullet
{
public:
	Bullet(void);
	~Bullet(void);

	void BulletMove();
	void BulletShoot();

private:
	int x,y;
};

