#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

enum CharacterState
{
    WAIT = 0,
    RUNN = 1,
    JUMP = 2,
    ATTACK = 4,
    ATTACK_SOUL_1 = 8,
    ATTACK_SOUL_2 = 16
};

#endif // CHARACTERSTATE_H
