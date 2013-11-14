#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

// C++
#include <vector>

// cocos2dx
#include "cocos2d.h"

NS_CC_BEGIN
class Touch;
class Event;
class Sprite;
NS_CC_END

// template
#include "ListenerList.h"

class JoyStickListener
{
public:
	virtual void onJoyStickUpdate(cocos2d::Node* sender, float angle, cocos2d::Point direction, float power) = 0;
	virtual void onJoyStickActivated(cocos2d::Node* sender){ CC_UNUSED_PARAM(sender); }
	virtual void onJoyStickDeactivated(cocos2d::Node* sender) { CC_UNUSED_PARAM(sender); }
};

class JoyStick 
	: public cocos2d::Layer
	, public ListenerList<JoyStickListener*>
{
public:
	JoyStick();
	virtual ~JoyStick();

public: // cocos2dx
	static JoyStick* create(
		int ballRadius,
		int moveAreaRadius,
		bool isFollowTouch,
		bool isVisible,
		bool isAutoHide,
		bool hasAnimation);

	virtual bool initWithBallRadius(
		int ballRadius,
		int moveAreaRadius,
		bool isFollowTouch,
		bool isVisible,
		bool isAutoHide,
		bool hasAnimation);
	
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
	virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) override;

public:
	void setBallTexture(const char* imageName);
	void setBallTexutreWithFrameName(const char* spriteFrameName);

	void setStickTexture(const char* imageName);
	void setSitckTextureWithFrameName(const char* spriteFrameName);

	void setDockTexture(const char* imageName);
	void setDockTextureWithFrameName(const char* spriteFrameName);

	void setHitAreaWithRadius(int radius);
	void setHitAreaWithRect(cocos2d::Rect hitAreaRect); 

public: // getter
	int getPower() const;

private: 
	void _startTimer(); 
	void _stopTimer(); 
	void _timerUpdate(float dt);
	void _onTouchBegan(cocos2d::Point& touchPoint); 
	void _resetTexturePosition(); 
	bool _containsTouchLocation(cocos2d::Touch* touch); 
	void _updateTouchPoint(cocos2d::Point& touchPoint); 

protected:
	cocos2d::Sprite* _ball;
	cocos2d::Sprite* _stick;
	cocos2d::Sprite* _dock;

	float _angle;
	bool _autoHide;
	int _ballRadius;
	cocos2d::Point _currentPoint;
	cocos2d::Point _direction;
	bool _hasAnimation;
	float _power;
	bool _touching;

    // ���ƶ���Χ�İ뾶����Ϊ�����ֱ�Ĭ����Բ�Σ�
	int _moveAreaRadius;

	//  �Ƿ���Ҫ������������ҡ�ˣ�
	bool _followTouch; 

    /* @brief ��Ч����
     * @note �����ֱ������Χ�ǡ����Ρ�ʱ�õ����� m_nActiveRadius ���� */
	cocos2d::Rect _activeRect;

    /* @brief ��Ч����
     * @note �����ֱ������Χ�ǡ�Բ�Ρ�ʱ�õ����� m_tActiveRect ���� */
	int _activeRadius;

protected:

	/** @brief �ӽڵ�Tag */
	enum kTagChildren
	{
		kTagSprStick = 0,
	};
};


#endif // __JOYSTICK_H__