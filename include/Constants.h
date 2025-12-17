#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants
{
    // Constants
   	constexpr int gScreenWidth     { 640 };
   	constexpr int gScreenHeight    { 480 };
   	// PATH TO YOUR RESOURCE FOLDER 'resources', 'gResPath'
   	const std::string gResPath { "./resources/" };
	// PATH'S TO ALL YOUR EXTERNAL RESOURCES using 'gResPath'
	//const std::string bg_str  { gResPath + "images/bg.jpg" };
    //const std::string sample_str { gResPath + "sounds/sample.wav"};
	
	const std::string rocketship_str {gResPath + "images/rocketship.png"};  //ger etiketter på bilderna som ska nås
	const std::string rocketship2_str {gResPath + "images/rocketship-2.png"};
	const std::string alien_str {gResPath + "images/enemy.png"}; // fixed typo
	const std::string alien2_str {gResPath + "images/enemy-1.png"}; // added ; in the end each line
	const std::string background_str {gResPath + "images/background-alternativ-1.jpg"}; 
	const std::string background2_str {gResPath + "images/background-alternativ-2.png"};
	const std::string bullet_str {gResPath + "images/bullet.png"};
}

#endif