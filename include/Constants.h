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
	const std::string rocketship_str {gResPath + "images/rocketship.png"}   //ger etiketter på bilderna som ska nås
	const std::string alien1_str {gResPath + "image/deafult.png"}
	const std::string alien2_str {gResPath + "images/32280-8-space-invaders-file.png"}
	const std::string background_str {gResPath + "baclground-alternativ-1.jpg"} 
}

#endif