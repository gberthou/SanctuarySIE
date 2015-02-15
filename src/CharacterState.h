#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

enum CharacterStateJump
{
	NOJUMP,
	JUMP,
	JUMP_DEACTIVATED,
	JUMP2,
	JUMP2_DEACTIVATED,
	FALL,
	FALL_DEACTIVATED,
	FALL2,
	FALL2_DEACTIVATED,
	FALL_WAIT_DEACTIVATION
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
	ATTACK,
	ATTACK_DEACTIVATED,
	ATTACK_TIMEOUT
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

