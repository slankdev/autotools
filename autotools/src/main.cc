#include <stdio.h>
#include <slankdev/extra/pcap.h>
#include <slankdev/hexdump.h>

void callback(uint8_t* user, const struct pcap_pkthdr* h, const uint8_t* byte)
{
  slankdev::hexdump(stdout, byte, h->len);
}

int main()
{
  printf("hello world \n");
  slankdev::pcap pcap;
  pcap.open_offline("src/in.pcap");
  pcap.loop(0, callback, nullptr);
}
