#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Character.h"

enum EventSource
{
	ES_KEYBOARD,
	ES_JOYSTICK
};

enum KeyMapping
{
    KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT,
    KEY_A, KEY_B,
    KEY_L, KEY_R,
    KEY_START, KEY_SELECT,
    KEY_COUNT // must be the last
};

extern sf::Keyboard::Key keys_mapping[];
extern unsigned int joystick_mapping[];

class InputController
{
    public:
        InputController(Character* c);
        void Update(sf::Event const& event);

		void SetEventSource(EventSource source, unsigned int joystickId = 0);

    protected:
		void keyboardAction();
		void joystickAction();

        void actionLeftPressed();
        void actionLeftReleased();
        void actionRightPressed();
        void actionRightReleased();
        void actionUp();
        void actionDown();
        void actionAPressed();
		void actionAReleased();
        void actionBPressed();
        void actionBReleased();
		void actionRPressed();
		void actionRReleased();
		void actionLPressed();
		void actionLReleased();

        Character* character;
		EventSource eventSource;
		unsigned int joystickId;

    private:

};

#endif // INPUT_CONTROLLER_H
