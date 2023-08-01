#include "Minecraft.h"

Minecraft Minecraft::getTheMinecraft()
{
	return Minecraft(Ripterms::p_env->GetStaticObjectField(MinecraftClass.javaClass, MinecraftClass.fields["theMinecraft"]));
}

EntityPlayerSP Minecraft::getThePlayer()
{
	if (!this->instance) return EntityPlayerSP();
	return EntityPlayerSP(Ripterms::p_env->GetObjectField(this->instance, MinecraftClass.fields["thePlayer"]));
}

WorldClient Minecraft::getTheWorld()
{
	if (!this->instance) return WorldClient();
	return WorldClient(Ripterms::p_env->GetObjectField(this->instance, MinecraftClass.fields["theWorld"]));
}

bool Minecraft::init()
{
	return MinecraftClass.fill("net/minecraft/client/Minecraft");
}