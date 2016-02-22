#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <stdlib.h>
#include <string>
#include "cocos2d.h"

using namespace std;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	/*virtual void onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);*/
};

#endif // __HELLOWORLD_SCENE_H__
