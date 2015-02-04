#include "ItemFactory.h"

ItemFactory::ItemFactory()
{
    //ctor
}

ItemFactory::~ItemFactory()
{
    //dtor
}

Weapon* ItemFactory::CreateWeapon(WeaponType type)
{
    switch(type)
    {
		case DAGGER:
		{
			Stats *stats = new Stats();
         	return new Weapon(stats, sf::String("dagger"), sf::String("This dagger will make your heart bleed."), true, 1, 2, 1000);
		}

        default:
            return 0;
    }
}

Armor* ItemFactory::CreateArmor(ArmorType type)
{
    switch(type)
    {
        //case :
        //    return new ;
        default:
            return 0;
    }
}

Accessory* ItemFactory::CreateAccessory(AccessoryType type)
{
    switch(type)
    {
        case BATFANG:
        {
            Stats *stats = new Stats(0,0,20,0,0,10);
            return new Accessory(stats,sf::String("Bat Fang"),sf::String("This is the fang of a ferocious giant bat you killed and scavenged."),true,500,600);
        }
        default:
            return 0;
    }
}
