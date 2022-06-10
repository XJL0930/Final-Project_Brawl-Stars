#include "PauseBox.h"
#include "ui/CocosGUI.h"

PauseBox::PauseBox()
{

}
PauseBox::~PauseBox()
{

}
bool PauseBox::init()
{
	if (Layer::init()==false)
	{
		return false;
	}
	
	auto viewsize = Director::getInstance()->getVisibleSize();
	auto background = LayerColor::create(Color4B(0,0,0,200));
	auto box = ui::Button::create("bg.jpg");
	auto continueButton = ui::Button::create("continueGame.png");
	auto exitButton = ui::Button::create("exitGame.png");

	////box->setContentSize(Size(100, 100));
	box->setScale(0.1f);
	box->setPosition(Vec2(viewsize.width / 2, viewsize.height / 2));

	continueButton->setPosition(Vec2(viewsize.width / 2, viewsize.height / 2+30));
	exitButton->setPosition(Vec2(viewsize.width / 2, viewsize.height / 2 - 30));

	this->setContentSize(viewsize);

	this->addChild(background);
	this->addChild(box);
	this->addChild(continueButton);
	this->addChild(exitButton);
	continueButton->addClickEventListener([this](Ref* ref) {
		if (_continueCallBack != nullptr)
		{
			_continueCallBack();
		}
		});
	exitButton->addClickEventListener([this](Ref* ref) {
		if (_endGameCALLbACK != nullptr)
		{
			_endGameCALLbACK();
		}

		});

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* t, Event* e) {return true; };
	listener->setSwallowTouches(true);
	
	background->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, background);
	return true;
}

void PauseBox::registerCallBack(std::function<void()>continueCallBack,
	std::function<void()>endGameCALLbACK)
{
	_continueCallBack = continueCallBack;
	_endGameCALLbACK = endGameCALLbACK;
}