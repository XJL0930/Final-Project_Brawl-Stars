#ifndef _HEROMESSAGE_H_
#define _HEROMESSAGE_H_
#include <string>
using namespace std;
class HeroMessage {
public:
	int id;
	string name;
	string png;
	string plist;
	int offset_x;
	int offset_y;
	int hp;
	int atk;
	int def;
	int speed;
	string bullet;
};
#endif