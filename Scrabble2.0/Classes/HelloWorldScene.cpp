#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h" 
#include "ui/CocosGUI.h"
#include "ui\UIButton.h"
#include <stdlib.h>
#include <time.h>
#include <random>
//#include "Diccionario.h"
//#include "Jugador.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace std;
class Imagen{
public:
	Sprite *image;
	char type;
	float x, y;
	int puntos;
	Imagen(string n, char t){
		image = Sprite::create(n);
		char type = t;
	}
	void posicion(int x, int y){
		image->setPosition(Vec2(x, y));
	}
	void moveto(int a, int b)
	{
		image->setPosition(a, b);
	}
	void setpoints(int a){
		puntos = a;
	}
};
Sprite *a;
int x, y, z; 
//int tem = rand() % 25

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool j = true;

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	x = 380, y = 700, z = 525;
	bool j = true;
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	srand(time(NULL));
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music2.mp3", true);
	int tem;
	/*Sprite *sprite[28];
	sprite[0] = Sprite::create("a.png"), sprite[1] = Sprite::create("a.png"), sprite[2] = Sprite::create("a.png"), sprite[3] = Sprite::create("a.png");
	sprite[4] = Sprite::create("a.png"), sprite[5] = Sprite::create("a.png"), sprite[6] = Sprite::create("a.png"), sprite[7] = Sprite::create("a.png");
	sprite[8] = Sprite::create("a.png"), sprite[9] = Sprite::create("a.png"), sprite[10] = Sprite::create("a.png"), sprite[11] = Sprite::create("a.png");
	sprite[12] = Sprite::create("a.png"), sprite[13] = Sprite::create("a.png"), sprite[14] = Sprite::create("a.png"), sprite[15] = Sprite::create("a.png");
	sprite[16] = Sprite::create("a.png"), sprite[17] = Sprite::create("a.png"), sprite[18] = Sprite::create("a.png"), sprite[19] = Sprite::create("a.png");
	sprite[20] = Sprite::create("a.png"), sprite[21] = Sprite::create("a.png"), sprite[22] = Sprite::create("a.png"), sprite[23] = Sprite::create("a.png");
	sprite[24] = Sprite::create("a.png"), sprite[25] = Sprite::create("a.png"), sprite[26] = Sprite::create("a.png"), sprite[27] = Sprite::create("a.png");
	*/
	a = Sprite::create("arrow.png");
	a->setPosition(x, y);
	a->setScale(0.2);
	addChild(a, 1);

	Sprite *sprite[98];
	for (int t = 0; t < 98; t++){
		if (t < 9){//0-8
			sprite[t] = Sprite::create("a.png");
		}
		else if (t > 8 && t < 11){//9-10
			sprite[t] = Sprite::create("b.png");
		}
		else if (t > 10 && t < 13){//11-12
			sprite[t] = Sprite::create("c.png");
		}
		else if (t > 12 && t < 17){//13-16
			sprite[t] = Sprite::create("d.png");
		}
		else if (t > 16 && t < 29){//17-28
			sprite[t] = Sprite::create("e.png");
		}
		else if (t > 28 && t < 31){//29-30
			sprite[t] = Sprite::create("f.png");
		}
		else if (t > 30 && t < 34){//31-33
			sprite[t] = Sprite::create("g.png");
		}
		else if (t > 33 && t < 36){//34-35
			sprite[t] = Sprite::create("h.png");
		}
		else if (t > 35 && t < 45){//36-44
			sprite[t] = Sprite::create("i.png");
		}
		else if (t > 44 && t < 46){//45
			sprite[t] = Sprite::create("j.png");
		}
		else if (t > 45 && t < 47){//46
			sprite[t] = Sprite::create("k.png");
		}
		else if (t > 46 && t < 51){//47-50
			sprite[t] = Sprite::create("l.png");
		}
		else if (t > 50 && t < 53){//51-52
			sprite[t] = Sprite::create("m.png");
		}
		else if (t > 52 && t < 59){//53-58
			sprite[t] = Sprite::create("n.png");
		}
		else if (t > 58 && t < 67){//59-66
			sprite[t] = Sprite::create("o.png");
		}
		else if (t > 66 && t < 69){//67-68
			sprite[t] = Sprite::create("p.png");
		}
		else if (t > 68 && t < 70){//69
			sprite[t] = Sprite::create("q.png");
		}
		else if (t > 69 && t < 76){//70-75
			sprite[t] = Sprite::create("r.png");
		}
		else if (t > 75 && t < 80){//76-79
			sprite[t] = Sprite::create("s.png");
		}
		else if (t > 79 && t < 87){//80-86
			sprite[t] = Sprite::create("t.png");
		}
		else if (t > 86 && t < 91){//87-90
			sprite[t] = Sprite::create("u.png");
		}
		else if (t > 90 && t < 93){//91-92
			sprite[t] = Sprite::create("v.png");
		}
		else if (t > 92 && t < 95){//93-94
			sprite[t] = Sprite::create("w.png");
		}
		else if (t > 94 && t < 96){//95
			sprite[t] = Sprite::create("x.png");
		}
		else if (t > 95 && t < 98){//96-97
			sprite[t] = Sprite::create("y.png");
		}
		else{
			sprite[t] = Sprite::create("z.png");
		}
	}

	Sprite *tablero[98];
	for (int y = 0; y < 98; y++){
		tablero[y] = sprite[tem = rand() % 98];
	}

	// position the sprite on the screen
	tablero[0]->setPosition(360, 100), tablero[1]->setPosition(360, 270), tablero[2]->setPosition(360, 450), tablero[3]->setPosition(360, 620);
	tablero[4]->setPosition(400, 100), tablero[5]->setPosition(400, 270), tablero[6]->setPosition(400, 450), tablero[7]->setPosition(400, 620);
	tablero[8]->setPosition(440, 100), tablero[9]->setPosition(440, 270), tablero[10]->setPosition(440, 450), tablero[11]->setPosition(440, 620);
	tablero[12]->setPosition(480, 100), tablero[13]->setPosition(480, 270), tablero[14]->setPosition(480, 450), tablero[15]->setPosition(480, 620);
	tablero[16]->setPosition(520, 100), tablero[17]->setPosition(520, 270), tablero[18]->setPosition(520, 450), tablero[19]->setPosition(520, 620);
	tablero[20]->setPosition(560, 100), tablero[21]->setPosition(560, 270), tablero[22]->setPosition(560, 450), tablero[23]->setPosition(560, 620);
	tablero[24]->setPosition(600, 100), tablero[25]->setPosition(600, 270), tablero[26]->setPosition(600, 450), tablero[27]->setPosition(600, 620);

	/*sprite[0]->setPosition(360, 100), sprite[1]->setPosition(360, 270), sprite[2]->setPosition(360, 450), sprite[3]->setPosition(360, 620);
	sprite[4]->setPosition(400, 100), sprite[5]->setPosition(400, 270), sprite[6]->setPosition(400, 450), sprite[7]->setPosition(400, 620);
	sprite[8]->setPosition(440, 100), sprite[9]->setPosition(440, 270), sprite[10]->setPosition(440, 450), sprite[11]->setPosition(440, 620);
	sprite[12]->setPosition(480, 100), sprite[13]->setPosition(480, 270), sprite[14]->setPosition(480, 450), sprite[15]->setPosition(480, 620);
	sprite[16]->setPosition(520, 100), sprite[17]->setPosition(520, 270), sprite[18]->setPosition(520, 450), sprite[19]->setPosition(520, 620);
	sprite[20]->setPosition(560, 100), sprite[21]->setPosition(560, 270), sprite[22]->setPosition(560, 450), sprite[23]->setPosition(560, 620);
	sprite[24]->setPosition(600, 100), sprite[25]->setPosition(600, 270), sprite[26]->setPosition(600, 450), sprite[27]->setPosition(600, 620);
	*/
	// add the sprite as a child to this layer
	/*this->addChild(sprite.image, 3), addChild(sprite2.image, 3), addChild(sprite3.image, 3), addChild(sprite4.image, 3);
	addChild(sprite5.image, 2), addChild(sprite6.image, 1), addChild(sprite7.image, 1), addChild(sprite8.image, 1);
	addChild(sprite9.image, 2), addChild(sprite10.image, 1), addChild(sprite11.image, 1), addChild(sprite12.image, 1);
	addChild(sprite13.image, 2), addChild(sprite14.image, 1), addChild(sprite15.image, 1), addChild(sprite16.image, 1);
	addChild(sprite17.image, 2), addChild(sprite18.image, 1), addChild(sprite19.image, 1), addChild(sprite20.image, 1);
	addChild(sprite21.image, 2), addChild(sprite22.image, 1), addChild(sprite23.image, 1), addChild(sprite24.image, 1);
	addChild(sprite25.image, 2), addChild(sprite26.image, 1);
	addChild(sprite28, 10);*/
	//sprite28->addChild(sprite29);
	/*for (int d = 0; d < 7; d++){
		addChild(sprites[d].image, 1);
		}*/

	for (int u = 0; u < 28; u++){
		addChild(tablero[u], 1);
	}

	//Draw a rectangle with specific size
	/*auto rectNode = DrawNode::create();
	Vec2 rectangle[4];
	rectangle[0] = Vec2(-20, -20);//-50,-50
	rectangle[1] = Vec2(20, -20);//50,-50
	rectangle[2] = Vec2(20, 20);//50,50
	rectangle[3] = Vec2(-20, 20);//-50,50
	rectNode->setPosition(645,167);
	Color4F white(1, 1, 1, 1);
	rectNode->drawPolygon(rectangle, 4, white, 1, white);
	this->addChild(rectNode,0);*/

	auto rootNode = CSLoader::createNode("MainScene.csb");
	addChild(rootNode);

	auto abutton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_1"));
	if (abutton)
	{
		abutton->addClickEventListener([=](Ref *){
			z -= 75;
			CCLOG("Pressed Add");
		});
	}
	
	auto bbutton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_1_0"));
	if(bbutton)
	{
			bbutton->addClickEventListener([=](Ref *){
				if (y > 175){
					a->setPosition(x, y -= 175); 
					CCLOG("Pressed Next");
				}
				else if (y <= 175){
					a->setPosition(x, y = 700 );
					CCLOG("Pressed Next");
				}
			});
	}

	if (y < 200){
		a->setPosition(x, y = 700);
	}

	auto cbutton = static_cast<cocos2d::ui::Button*>(rootNode->getChildByName("Button_2"));
	if (cbutton)
	{
		cbutton->addClickEventListener([=](Ref *){
			Director::sharedDirector()->end();
			CCLOG("Pressed Exit");
		});
	}

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [](Touch* touch, Event* event){
		auto target = (event->getCurrentTarget());
		//Get the position of the current point relative to the button
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		//Check the click area
		if (rect.containsPoint(locationInNode))
		{
			log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			target->setOpacity(180);
			return true;
		}
		return false;
	};

	//Trigger when moving touch
	listener->onTouchMoved = [](Touch* touch, Event* event){
		auto target = (event->getCurrentTarget());
		//Move the position of current button sprite
		target->setPosition(target->getPosition() + touch->getDelta());
	};

	//Process the touch end event
	listener->onTouchEnded = [=](Touch* touch, Event* event){
		auto target = (event->getCurrentTarget());
		log("sprite onTouchesEnded.. ");
		target->setOpacity(255);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, tablero[0]);
	for (int i = 1; i < 98; i++){
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), tablero[i]);
	}
    return true;
}
