#include "PacketReceiver.h"

int main()
{	
	CallbackMediator mediator;
	PacketReceiver receiver = PacketReceiver(&mediator);
	
	while(true)
	{
		receiver.run();
	}

	return 0;
}