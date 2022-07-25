
// Written by PR0PH3CY on 24-07-2022 Licensed under the GNU General Public License

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <sys/ioctl.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <net/if_arp.h>

#include <net/if.h>

#include <unistd.h>


int main(int argc, char *argv[]) {

	struct ifreq ifr;

	int sock;

	char macAddress[] = "12:34:56:78:12:3a"; //specify the mac address

	sscanf(macAddress, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", //6 hexadecimal pairs

	&ifr.ifr_hwaddr.sa_data[0],
        &ifr.ifr_hwaddr.sa_data[1],
        &ifr.ifr_hwaddr.sa_data[2],
        &ifr.ifr_hwaddr.sa_data[3],
        &ifr.ifr_hwaddr.sa_data[4],
        &ifr.ifr_hwaddr.sa_data[5]

        );

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	strcpy(ifr.ifr_name, "wlp10s0"); //interface to change it's mac address

	ifr.ifr_hwaddr.sa_family = ARPHRD_ETHER;

	int macChangingResult = ioctl(sock, SIOCSIFHWADDR, &ifr);

	if(macChangingResult != -1) {

		printf("%s\n", "MAC Address Changed Successfully!");

		return 0;

	}

	else {

		perror("");

		exit(0);

	}

}
