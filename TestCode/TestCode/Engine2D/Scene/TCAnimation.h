#ifndef __TC_ANIMATION_H__
#define __TC_ANIMATION_H__
#include "BaseComponent.h"
#include "Animation/TCAnimationCurve.h"
#include "BaseNode.h"
NS_TC_BEGIN

class AnimationContainer;

class Animation:public AutoReleaseObject{
	friend class AnimationContainer;
protected:
	virtual bool invokeUpdate(BaseNode* target)=0;
	virtual void reset()=0;
};

class TranslateAnimation:public Animation{
private:
	AnimationCurve _xCurve;
	AnimationCurve _yCurve;
	float _time;
	float _currentTime;
public:
	TranslateAnimation(const AnimationCurve& x,const AnimationCurve& y,float time){
		_xCurve=x;
		_yCurve=y;
		_time=time;
		_currentTime=0;
	}

	bool invokeUpdate(BaseNode* target);
	
	void reset();

	static TranslateAnimation* alloc(const AnimationCurve& x,const AnimationCurve& y,float time);

};
class AnimationContainer:public BaseComponent{
	friend class BaseNode;
private:
	Animation* _animation;

	void invokeUpdate(BaseNode* target);

	bool _isPlaying;

	AnimationContainer();
	~AnimationContainer();
public:
	inline enum ComponentType type(){
		return ComponentAnimation;
	}
	void play(Animation* anim);

	void play();

	void stop();

	void pause();

	static AnimationContainer* alloc();

};

NS_TC_END
#endif