/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/


#include "NewRendererTest.h"

static int sceneIdx = -1;

Layer* nextSpriteTestAction();
Layer* backSpriteTestAction();
Layer* restartSpriteTestAction();

static std::function<Layer*()> createFunctions[] =
{
    CL(NewSpriteTest),
    CL(NewSpriteBatchTest),
    CL(NewClippingNodeTest),
    CL(NewDrawNodeTest),
    CL(NewCullingTest),
};

#define MAX_LAYER    (sizeof(createFunctions) / sizeof(createFunctions[0]))

Layer* nextTest()
{
    sceneIdx++;
    sceneIdx = sceneIdx % MAX_LAYER;

    auto layer = (createFunctions[sceneIdx])();
    return layer;
}

Layer* prevTest()
{
    sceneIdx--;
    int total = MAX_LAYER;
    if( sceneIdx < 0 )
        sceneIdx += total;

    auto layer = (createFunctions[sceneIdx])();

    return layer;
}

Layer* restartTest()
{
    auto layer = (createFunctions[sceneIdx])();

    return layer;
}

void NewRendererTestScene::runThisTest()
{
    auto layer = nextTest();
    addChild(layer);

    Director::getInstance()->replaceScene(this);
}

MultiSceneTest::MultiSceneTest()
{

}

MultiSceneTest::~MultiSceneTest()
{

}

std::string MultiSceneTest::title() const
{
    return BaseTest::title();
}

std::string MultiSceneTest::subtitle() const
{
    return BaseTest::subtitle();
}

void MultiSceneTest::onEnter()
{
    BaseTest::onEnter();
}

void MultiSceneTest::restartCallback(Object *sender)
{
    auto s = new NewRendererTestScene();
    s->addChild(restartTest());

    Director::getInstance()->replaceScene(s);
    s->release();
}

void MultiSceneTest::nextCallback(Object *sender)
{
    auto s = new NewRendererTestScene();
    s->addChild(nextTest());

    Director::getInstance()->replaceScene(s);
    s->release();
}

void MultiSceneTest::backCallback(Object *sender)
{
    auto s = new NewRendererTestScene();
    s->addChild(prevTest());

    Director::getInstance()->replaceScene(s);
    s->release();
}

NewSpriteTest::NewSpriteTest()
{
    auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesEnded = CC_CALLBACK_2(NewSpriteTest::onTouchesEnded, this);

    createSpriteTest();
    createNewSpriteTest();
}

NewSpriteTest::~NewSpriteTest()
{

}

void NewSpriteTest::createSpriteTest()
{
    Size winSize = Director::getInstance()->getWinSize();

    Sprite* parent = Sprite::create("Images/grossini.png");
    parent->setPosition(winSize.width/4, winSize.height/2);
    Sprite* child1 = Sprite::create("Images/grossinis_sister1.png");
    child1->setPosition(0.0f, -20.0f);
    Sprite* child2 = Sprite::create("Images/grossinis_sister2.png");
    child2->setPosition(20.0f, -20.0f);
    Sprite* child3 = Sprite::create("Images/grossinis_sister1.png");
    child3->setPosition(40.0f, -20.0f);
    Sprite* child4 = Sprite::create("Images/grossinis_sister2.png");
    child4->setPosition(60.0f, -20.0f);
    Sprite* child5 = Sprite::create("Images/grossinis_sister2.png");
    child5->setPosition(80.0f, -20.0f);
    Sprite* child6 = Sprite::create("Images/grossinis_sister2.png");
    child6->setPosition(100.0f, -20.0f);
    Sprite* child7 = Sprite::create("Images/grossinis_sister2.png");
    child7->setPosition(120.0f, -20.0f);

    parent->addChild(child1);
    parent->addChild(child2);
    parent->addChild(child3);
    parent->addChild(child4);
    parent->addChild(child5);
    parent->addChild(child6);
    parent->addChild(child7);
    addChild(parent);
}

void NewSpriteTest::createNewSpriteTest()
{
    Size winSize = Director::getInstance()->getWinSize();

    Sprite* parent = Sprite::create("Images/grossini.png");
    parent->setPosition(winSize.width*2/3, winSize.height/2);
    Sprite* child1 = Sprite::create("Images/grossinis_sister1.png");
    child1->setPosition(0.0f, -20.0f);
    Sprite* child2 = Sprite::create("Images/grossinis_sister2.png");
    child2->setPosition(20.0f, -20.0f);
    Sprite* child3 = Sprite::create("Images/grossinis_sister1.png");
    child3->setPosition(40.0f, -20.0f);
    Sprite* child4 = Sprite::create("Images/grossinis_sister2.png");
    child4->setPosition(60.0f, -20.0f);
    Sprite* child5 = Sprite::create("Images/grossinis_sister2.png");
    child5->setPosition(80.0f, -20.0f);
    Sprite* child6 = Sprite::create("Images/grossinis_sister2.png");
    child6->setPosition(100.0f, -20.0f);
    Sprite* child7 = Sprite::create("Images/grossinis_sister2.png");
    child7->setPosition(120.0f, -20.0f);

    parent->addChild(child1);
    parent->addChild(child2);
    parent->addChild(child3);
    parent->addChild(child4);
    parent->addChild(child5);
    parent->addChild(child6);
    parent->addChild(child7);
    addChild(parent);
}

void NewSpriteTest::onTouchesEnded(const std::vector<Touch *> &touches, Event *event)
{

}

std::string NewSpriteTest::title() const
{
    return "NewRender";
}

std::string NewSpriteTest::subtitle() const
{
    return "SpriteTest";
}

//-------- New Sprite Batch Test

NewSpriteBatchTest::NewSpriteBatchTest()
{
    auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesEnded = CC_CALLBACK_2(NewSpriteBatchTest::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    auto BatchNode = SpriteBatchNode::create("Images/grossini_dance_atlas.png", 50);
    addChild(BatchNode, 0, kTagSpriteBatchNode);
}

NewSpriteBatchTest::~NewSpriteBatchTest()
{

}

std::string NewSpriteBatchTest::title() const
{
    return "NewRender";
}

std::string NewSpriteBatchTest::subtitle() const
{
    return "SpriteBatchTest";
}

void NewSpriteBatchTest::onTouchesEnded(const std::vector<Touch *> &touches, Event *event)
{
    for (auto &touch : touches)
    {
        auto location = touch->getLocation();
        addNewSpriteWithCoords(location);
    }
}

void NewSpriteBatchTest::addNewSpriteWithCoords(Point p)
{
    auto BatchNode = static_cast<SpriteBatchNode*>( getChildByTag(kTagSpriteBatchNode) );

    int idx = (int) (CCRANDOM_0_1() * 1400 / 100);
    int x = (idx%5) * 85;
    int y = (idx/5) * 121;


    auto sprite = Sprite::createWithTexture(BatchNode->getTexture(), Rect(x,y,85,121));
    BatchNode->addChild(sprite);

    sprite->setPosition( Point( p.x, p.y) );

    ActionInterval* action;
    float random = CCRANDOM_0_1();

    if( random < 0.20 )
        action = ScaleBy::create(3, 2);
    else if(random < 0.40)
        action = RotateBy::create(3, 360);
    else if( random < 0.60)
        action = Blink::create(1, 3);
    else if( random < 0.8 )
        action = TintBy::create(2, 0, -255, -255);
    else
        action = FadeOut::create(2);

    auto action_back = action->reverse();
    auto seq = Sequence::create(action, action_back, NULL);

    sprite->runAction( RepeatForever::create(seq));
}

NewClippingNodeTest::NewClippingNodeTest()
{
    auto s = Director::getInstance()->getWinSize();

    auto clipper = ClippingNode::create();
    clipper->setTag( kTagClipperNode );
    clipper->setContentSize(  Size(200, 200) );
    clipper->setAnchorPoint(  Point(0.5, 0.5) );
    clipper->setPosition( Point(s.width / 2, s.height / 2) );

    clipper->runAction(RepeatForever::create(RotateBy::create(1, 45)));
    this->addChild(clipper);

    //TODO Fix draw node as clip node
//    auto stencil = NewDrawNode::create();
//    Point rectangle[4];
//    rectangle[0] = Point(0, 0);
//    rectangle[1] = Point(clipper->getContentSize().width, 0);
//    rectangle[2] = Point(clipper->getContentSize().width, clipper->getContentSize().height);
//    rectangle[3] = Point(0, clipper->getContentSize().height);
//
//    Color4F white(1, 1, 1, 1);
//    stencil->drawPolygon(rectangle, 4, white, 1, white);
//    clipper->setStencil(stencil);

    //Test with alpha Test
    clipper->setAlphaThreshold(0.05f);
    auto stencil = Sprite::create("Images/grossini.png");
    stencil->setPosition(s.width/2, s.height/2);
    clipper->setStencil(stencil);

    auto content = Sprite::create("Images/background2.png");
    content->setTag( kTagContentNode );
    content->setAnchorPoint(  Point(0.5, 0.5) );
    content->setPosition( Point(clipper->getContentSize().width / 2, clipper->getContentSize().height / 2) );
    clipper->addChild(content);

    _scrolling = false;

    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(NewClippingNodeTest::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(NewClippingNodeTest::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(NewClippingNodeTest::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

NewClippingNodeTest::~NewClippingNodeTest()
{

}

std::string NewClippingNodeTest::title() const
{
    return "New Render";
}

std::string NewClippingNodeTest::subtitle() const
{
    return "ClipNode";
}

void NewClippingNodeTest::onTouchesBegan(const std::vector<Touch *> &touches, Event *event)
{
    Touch *touch = touches[0];
    auto clipper = this->getChildByTag(kTagClipperNode);
    Point point = clipper->convertToNodeSpace(Director::getInstance()->convertToGL(touch->getLocationInView()));
    auto rect = Rect(0, 0, clipper->getContentSize().width, clipper->getContentSize().height);
    _scrolling = rect.containsPoint(point);
    _lastPoint = point;
}

void NewClippingNodeTest::onTouchesMoved(const std::vector<Touch *> &touches, Event *event)
{
    if (!_scrolling) return;
    Touch *touch = touches[0];
    auto clipper = this->getChildByTag(kTagClipperNode);
    auto point = clipper->convertToNodeSpace(Director::getInstance()->convertToGL(touch->getLocationInView()));
    Point diff = point - _lastPoint;
    auto content = clipper->getChildByTag(kTagContentNode);
    content->setPosition(content->getPosition() + diff);
    _lastPoint = point;
}

void NewClippingNodeTest::onTouchesEnded(const std::vector<Touch *> &touches, Event *event)
{
    if (!_scrolling) return;
    _scrolling = false;
}

/**
* NewDrawNode
*/
NewDrawNodeTest::NewDrawNodeTest()
{
    auto s = Director::getInstance()->getWinSize();

    auto parent = Node::create();
    parent->setPosition(s.width/2, s.height/2);
    addChild(parent);

    auto rectNode = DrawNode::create();
    Point rectangle[4];
    rectangle[0] = Point(-50, -50);
    rectangle[1] = Point(50, -50);
    rectangle[2] = Point(50, 50);
    rectangle[3] = Point(-50, 50);

    Color4F white(1, 1, 1, 1);
    rectNode->drawPolygon(rectangle, 4, white, 1, white);
    parent->addChild(rectNode);
}

NewDrawNodeTest::~NewDrawNodeTest()
{

}

std::string NewDrawNodeTest::title() const
{
    return "New Render";
}

std::string NewDrawNodeTest::subtitle() const
{
    return "DrawNode";
}

NewCullingTest::NewCullingTest()
{
    auto s = Director::getInstance()->getWinSize();
    
    std::vector<std::string> images;
    images.push_back("Images/grossini_dance_01.png");
    images.push_back("Images/grossini_dance_02.png");
    images.push_back("Images/grossini_dance_03.png");
    images.push_back("Images/grossini_dance_04.png");
    images.push_back("Images/grossini_dance_05.png");
    images.push_back("Images/grossini_dance_06.png");
    images.push_back("Images/grossini_dance_07.png");
    images.push_back("Images/grossini_dance_08.png");
    images.push_back("Images/grossini_dance_09.png");
    images.push_back("Images/grossini_dance_10.png");
    images.push_back("Images/grossini_dance_11.png");
    images.push_back("Images/grossini_dance_12.png");
    images.push_back("Images/grossini_dance_13.png");
    images.push_back("Images/grossini_dance_14.png");
    images.push_back("Images/grossini.png");
    auto parent = Node::create();
    parent->setPosition(s.width/2, s.height/2);
    addChild(parent);
    for(int index = 0; index < 500; ++index)
    {
        auto parent2 = Node::create();
        parent2->setPosition(0,0);
        parent->addChild(parent2);
        parent2->setPosition(-50,0);
        parent2->runAction(RepeatForever::create((JumpBy::create(10, Point(0,0), 400, 1))));
        Sprite* sprite = Sprite::create(images[index % images.size()].c_str());
        sprite->setPosition(Point(0,0));
        //sprite->runAction(RepeatForever::create(RotateBy::create(3, 360)));
        sprite->runAction(RepeatForever::create(Sequence::createWithTwoActions(ScaleBy::create(2, 2), ScaleBy::create(2,0.5))));
        parent2->addChild(sprite);
    }
    
    for(int index = 0; index < 500; ++index)
    {
        auto parent2 = Node::create();
        parent->addChild(parent2);
        parent2->setPosition(50,0);
        parent2->runAction(RepeatForever::create((JumpBy::create(7, Point(0,0), 400, 1))));
        Sprite* sprite = Sprite::create(images[index % images.size()].c_str());
        sprite->setPosition(Point(0,0));
        //sprite->runAction(RepeatForever::create(RotateBy::create(3, 360)));
        sprite->runAction(RepeatForever::create(Sequence::createWithTwoActions(ScaleBy::create(2, 2), ScaleBy::create(2,0.5))));
        parent2->addChild(sprite);
    }

}

NewCullingTest::~NewCullingTest()
{
    
}

std::string NewCullingTest::title() const
{
    return "New Render";
}

std::string NewCullingTest::subtitle() const
{
    return "Culling";
}

