#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants
{
    // Constants
   	inline int gScreenWidth = 640;
   	inline int gScreenHeight = 480;

	const std::string gResPath {"resources/"};
   	// PATH TO YOUR RESOURCE FOLDER 'resources', 'gResPath'
   	const std::string rocketship_str {gResPath + "images/rocketship.png"};  //ger etiketter på bilderna som ska nås
	const std::string rocketship2_str {gResPath + "images/rocketship-2.png"};
	const std::string alien_str {gResPath + "images/enemy.png"}; // fixed typo
	const std::string alien2_str {gResPath + "images/enemy-1.png"}; // added ; in the end each line
	const std::string background_str {gResPath + "images/background-alternativ-1.jpg"}; 
	const std::string background2_str {gResPath + "images/background-alternativ-2.png"};
	const std::string bullet_str {gResPath + "images/bullet.png"};
	const std::string explosion_str {gResPath + "images/explosion.png"};

	//PATH'S TO SOUNDS
	const std::string shoot_sound_str {gResPath + "sounds/shoot.wav"};
	const std::string explosion_sound_str {gResPath + "sounds/invaderkilled.wav"};
}

#endif