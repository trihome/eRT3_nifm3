/**
 * @file relayio.h
 * @author myasu (you@domain.com)
 * @brief API Drivers for Relay
 * @version 0.1
 * @date 2020-08-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef RELAYIO_H
#define RELAYIO_H

int ReadInRelayCommon(int , int , int , int , int*);
unsigned int ReadOutRelayCommon(int , int , int , int , unsigned int*);
unsigned int WriteOutRelay1(int unit, int slot, int pos, unsigned short data);
unsigned int WriteOutRelay(int unit, int slot, int pos, unsigned int data, unsigned int mask);
int errcommon(char *func, int line, int result);

#endif