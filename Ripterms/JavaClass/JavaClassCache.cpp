#include "JavaClass.h"

Ripterms::JavaClassCache::JavaClassCache()
{
}

bool Ripterms::JavaClassCache::fillCache()
{
	return
		ObjectClass.fill("java/lang/Object") &&
		CollectionClass.fill("java/util/Collection") &&
		ListClass.fill("java/util/List") &&
		AbstractClientPlayerClass.fill("net/minecraft/client/entity/AbstractClientPlayer") &&
		EntityPlayerSPClass.fill("net/minecraft/client/entity/EntityPlayerSP") &&
		MinecraftClass.fill("net/minecraft/client/Minecraft") &&
		WorldClientClass.fill("net/minecraft/client/multiplayer/WorldClient") &&
		EntityClass.fill("net/minecraft/entity/Entity") &&
		EntityLivingBaseClass.fill("net/minecraft/entity/EntityLivingBase") &&
		EntityPlayerClass.fill("net/minecraft/entity/player/EntityPlayer") &&
		Vec3Class.fill("net/minecraft/util/Vec3") &&
		WorldClass.fill("net/minecraft/world/World");
}