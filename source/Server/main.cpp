#include "PacketReceiver.h"
#include "PlayerData.h"
#include "WorldData.h"

int main()
{	
	PacketReceiver receiver;
	PlayerData playerData(&receiver);
	WorldData worldData(&receiver);
	
	while(true)
	{
		receiver.run();
	}

	return 0;
}