#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

enum CharacterStateJump
{
	NOJUMP,
	JUMP,
	JUMP2,
	FALL,
	FALL2
};

enum CharacterStateWalk
{
	IDLE,
	WALK,
	BACKDASH,
	BACKDASH_TIMEOUT,
	BACKDASH_DEACTIVATED
};

enum CharacterStateAttack
{
	NOATTACK,
	ATTACK
};

enum CharacterStateRedSoul
{
	NORSOUL,
	RSOUL
};

enum CharacterStateBlueSoul
{
	NOBSOUL,
	BSOUL_ACTIVATING,
	BSOUL_ACTIVATED,
	BSOUL_DEACTIVATING,
	BSOUL_HELD
};

#endif // CHARACTERSTATE_H

