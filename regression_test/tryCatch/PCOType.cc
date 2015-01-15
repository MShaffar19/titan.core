///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2000-2014 Ericsson Telecom AB
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v1.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v10.html
///////////////////////////////////////////////////////////////////////////////
// This Test Port skeleton source file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version 1.5.pl7
// for Janos Zoltan Szabo (ejnosza@balisea) on Mon Sep 13 09:35:21 2004

// You may modify this file. Complete the body of empty functions and
// add your member functions here.

#include <stdio.h>

#include "PCOType.hh"
#include "memory.h"

namespace  tryCatch__Testcases {

PCOType::PCOType(const char *par_port_name)
: PCOType_BASE(par_port_name)
{

}

PCOType::~PCOType()
{

}

void PCOType::set_parameter(const char *parameter_name,
const char *parameter_value)
{

}

void PCOType::Event_Handler(const fd_set *read_fds,
const fd_set *write_fds, const fd_set *error_fds,
double time_since_last_call)
{
size_t buf_len = 0, buf_size = 32;
char *buf = (char*)Malloc(buf_size);
for ( ; ; ) {
int c = getc(stdin);
if (c == EOF) {
if (buf_len > 0) incoming_message(CHARSTRING(buf_len, buf));
Uninstall_Handler();
break;
} else if (c == '\n') {
incoming_message(CHARSTRING(buf_len, buf));
break;
} else {
if (buf_len >= buf_size) {
buf_size *= 2;
buf = (char*)Realloc(buf, buf_size);
}
buf[buf_len++] = c;
}
}
Free(buf);
}

void PCOType::user_map(const char *system_port)
{
fd_set readfds;
FD_ZERO(&readfds);
FD_SET(fileno(stdin), &readfds);
Install_Handler(&readfds, NULL, NULL, 0.0);
}

void PCOType::user_unmap(const char *system_port)
{
Uninstall_Handler();
}

void PCOType::user_start()
{

}

void PCOType::user_stop()
{

}

void PCOType::outgoing_send(const CHARSTRING& send_par)
{
puts((const char*)send_par);
fflush(stdout);
}

} /* end of namespace */

