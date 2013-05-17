#ifndef FANCY_NETWORK_DATA
#define FANCY_NETWORK_DATA

#include <SFML/Network.hpp>
#include <list>
#include <string.h>

#define MAX_PACKET_SIZE 10000

enum PacketTypes {
	// Client types
    INIT_CONNECTION = 0,
	REGISTER_PLAYER,
	REQUEST_NEW_LOBBY,
	JOIN_LOBBY,
    ACTION_EVENT,

	// Server types
	REGISTER_SUCCES,
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

struct PlayerDataPacket : FancyPacket
{

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