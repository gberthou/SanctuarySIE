#include "Soul.h"

Soul::Soul(MobType mobType, SoulType soulType1):
	type(mobType),
	soulType(soulType1)
{
}

Soul::~Soul()
{
}

MobType Soul::GetType(void) const
{
	return type;
}

SoulType Soul::GetSoulType(void) const
{
	return soulType;
}

