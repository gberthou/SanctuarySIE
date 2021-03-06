#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum ItemType
{
    PICKUP,
    //TRADABLE,
    //PERMANENT,
    WEAPON,
    ARMOR,
    ACCESSORY
    //STUFF,
    //CONSUMABLE
};

enum WeaponType
{
	DAGGER
};

enum ArmorType
{
    // insert some armor name here
};

enum AccessoryType
{
    BATFANG
};

enum PickUpType
{
    GOLD,
    MANA
};

enum ConsumableType
{
    
};

enum PermanentType
{
    
};

struct ItemDesc
{
	ItemType type;
	union
	{
		WeaponType weapon;
		ArmorType armor;
		AccessoryType accessory;
		PickUpType pickup;
        ConsumableType consumable;
        PermanentType permanent;
	};
};

union ItemSubtype
{
    int id;
    WeaponType weapon;
    ArmorType armor;
    AccessoryType accessory;
    PickUpType pickup;
    ConsumableType consumable;
    PermanentType permanent;
};

#endif // ITEMTYPE_H
