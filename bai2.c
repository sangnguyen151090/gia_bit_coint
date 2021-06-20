#include<stdint.h>
#include"Socket.h"
char buffer[4069] = { 0 };
void main()
{
	Socket_Client_Init("54.192.22.61", 80);
	Send("GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\n\r\n");

	Recv(buffer, sizeof(buffer));
	char* keystart = "\"rate_float\":";
	char* startpos = strstr(buffer, keystart);
	startpos += strlen(keystart);
	char bitcoinprice[32] = { 0 };
	int index = 0;
	while (startpos[index] != '}')
	{
		bitcoinprice[index] = startpos[index];
		index++;
	}
	printf("gia bitcoint la : %s USD", bitcoinprice);
}