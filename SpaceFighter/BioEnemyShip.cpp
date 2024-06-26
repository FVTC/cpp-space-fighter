
#include "BioEnemyShip.h"
#include "Level.h"


BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void BioEnemyShip::Update(const GameTime *pGameTime)
{
	if (IsActive())
	{
		float x = sin(pGameTime->GetTotalTime() * Math::PI + GetIndex());
		x *= GetSpeed() * pGameTime->GetTimeElapsed() * 1.4f;
		TranslatePosition(x, GetSpeed() * pGameTime->GetTimeElapsed());

		if (!IsOnScreen()) Deactivate();
	}

	EnemyShip::Update(pGameTime);
}


void BioEnemyShip::Draw(SpriteBatch *pSpriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		pSpriteBatch->Draw(m_pTexture, GetPosition(), Color::White * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
