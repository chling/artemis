#ifndef __TURN_FACTOR_H__
#define __TURN_FACTOR_H__

// artemis
#include "Component.h"

// ���ƣ�������
class TurnFactor : public artemis::Component
{
public:
	TurnFactor();

public:
	void setFactor(float factor);
	float getFactor() const;

private:
	float _factor;
};


#endif // __TURN_FACTOR_H__