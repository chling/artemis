#include "TerrainRenderSystem.h"


// artemis
#include "Entity.h"
#include "EntitySystem.h"
#include "SystemManager.h"
#include "World.h"

// cocos2dx
#include "cocos2d.h"

// game
#include "CameraSystem.h"
#include "Constants.h"
#include "Container.h"

TerrainRenderSystem::TerrainRenderSystem(Container* container)
{
	CCAssert(container, "container should not be nullptr.");
	_container = container;
}

void TerrainRenderSystem::initialize()
{
	_cameraSystem = (CameraSystem*)world->getSystemManager()->getSystem<CameraSystem>();
	this->setPassive(true);

	_map = cocos2d::TMXTiledMap::create("stage.tmx");
	_container->getGraphics()->addChild(_map, (int)Constants::ZOrder::TerrainRenderSystem);
}

void TerrainRenderSystem::processEntities(artemis::ImmutableBag<artemis::Entity*>& bag)
{
}

bool TerrainRenderSystem::checkProcessing()
{
	return false;
}