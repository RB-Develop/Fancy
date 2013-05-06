#ifndef FANCY_NETWORK_DATA
#define FANCY_NETWORK_DATA

#include <SFML/Network.hpp>
#include <list>
#include <string.h>

#define MAX_PACKET_SIZE 1000000

enum PacketTypes {
    INIT_CONNECTION = 0,
	REQUEST_NEW_LOBBY = 1,
	JOIN_LOBBY = 2,
    ACTION_EVENT = 3,
}; 

struct FancyPacket {
    unsigned int packet_type;
	std::string userName;

    void serialize(char * data) {
        memcpy(data, this, sizeof(FancyPacket));
    }

    void deserialize(char * data) {
        memcpy(this, data, sizeof(FancyPacket));
    }
};

/*
* Player.
*/
struct Player
{
	std::string name, adress;
	int team;
};

/*
* Team struct.
*/
struct Team
{
	std::list<Player> players;
};

/*
* Lobby struct.
*/
struct Lobby
{
	int size;
	std::list<Player> players;
	std::list<Team> teams;
};

#endif