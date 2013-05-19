#ifndef FANCY_NETWORK_DATA
#define FANCY_NETWORK_DATA

#include <SFML/Network.hpp>
#include <list>
#include <string>

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
	REGISTER_FAIL,
	PLAYER_LIST
};

struct PlayerPacket
{
	std::string userName;
	std::string ipAdress;
	unsigned short port;
};

struct Players
{
	std::list<PlayerPacket> p_list;
};

struct FancyPacket {
    unsigned int packet_type;
	std::string userName;
	std::string ipAdress;
	unsigned short port;
	std::size_t p_listSize;
	std::list<PlayerPacket> p_list;	
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

inline sf::Packet& operator <<(sf::Packet &out, PlayerPacket& in)
{
	return out << in.userName << in.ipAdress << in.port;
}

inline sf::Packet& operator >>(sf::Packet& in, PlayerPacket& out)
{
	return in >> out.userName >> out.ipAdress >> out.port;
}

inline sf::Packet& operator <<(sf::Packet &out, FancyPacket& in)
{
	in.p_listSize = in.p_list.size();
	out << in.packet_type << in.userName << in.ipAdress << in.port << in.p_listSize;	

	for(std::list<PlayerPacket>::iterator i=in.p_list.begin(); i!=in.p_list.end(); ++i)
	{
		out << *i;
	}

	return out;
}

inline sf::Packet& operator >>(sf::Packet& in, FancyPacket& out)
{
	in >> out.packet_type >> out.userName >> out.ipAdress >> out.port >> out.p_listSize;

	for(unsigned int i = 0; i < out.p_listSize; i++) {
		PlayerPacket p_data;
		in >> p_data;
		out.p_list.push_back(p_data);
	}
	return in;
}

#endif