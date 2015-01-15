///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2000-2014 Ericsson Telecom AB
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v1.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v10.html
///////////////////////////////////////////////////////////////////////////////
// This Test Port skeleton source file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version 1.7.pre0 build 8
// for edmdeli (edmdeli@EGNA8004JPBUT7R) on Thu Mar  1 14:45:21 2007


// You may modify this file. Complete the body of empty functions and
// add your member functions here.

#include <stdio.h>

#include "PCOType.hh"
#include "TimplicitEnc.hh"

#include <memory.h>

#ifndef OLD_NAMES
namespace TimplicitEnc {
#endif

PCOType_PROVIDER::PCOType_PROVIDER(const char *par_port_name)
	: PORT(par_port_name)
{

}

PCOType_PROVIDER::~PCOType_PROVIDER()
{

}

void PCOType_PROVIDER::set_parameter(const char *parameter_name,
	const char *parameter_value)
{

}

void PCOType_PROVIDER::Event_Handler(const fd_set *read_fds,
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

void PCOType_PROVIDER::user_map(const char *system_port)
{
  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  Install_Handler(&readfds, NULL, NULL, 0.0);

  //start with sending an octetstring that cannot be decoded to MyPDU
  const OCTETSTRING myBadOctets = str2oct("FFFFFFFFFFFFFF");
  incoming_message(myBadOctets);
}

void PCOType_PROVIDER::user_unmap(const char *system_port)
{
  Uninstall_Handler();
}

void PCOType_PROVIDER::user_start()
{

}

void PCOType_PROVIDER::user_stop()
{

}

void PCOType_PROVIDER::outgoing_send(const CHARSTRING& send_par)
{
  incoming_message(send_par);
}

void PCOType_PROVIDER::outgoing_send(const OCTETSTRING& send_par)
{
  incoming_message(send_par);
}

#ifndef OLD_NAMES
} /* end of namespace */
#endif
