///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2000-2014 Ericsson Telecom AB
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v1.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v10.html
///////////////////////////////////////////////////////////////////////////////
// This Test Port skeleton header file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version 1.4.pl3
// for Gabor Tatarka (tmpgta@duna127) on Wed Jul  9 16:13:51 2003


// You may modify this file. Add your attributes and prototypes of your
// member functions here.

#ifndef ExtProcPort_HH
#define ExtProcPort_HH

#include "ProcPort.hh"

#ifndef OLD_NAMES
namespace ProcPort {
#endif

class ExtProcPort : public ExtProcPort_BASE {
public:
	ExtProcPort(const char *par_port_name);
	~ExtProcPort();

	void set_parameter(const char *parameter_name,
		const char *parameter_value);

	void Event_Handler(const fd_set *read_fds,
		const fd_set *write_fds, const fd_set *error_fds,
		double time_since_last_call);

protected:
	void user_map(const char *system_port);
	void user_unmap(const char *system_port);

	void user_start();
	void user_stop();

	void outgoing_call(const MyProc5_call& call_par);
	void outgoing_reply(const MyProc5_reply& reply_par);
	void outgoing_raise(const MyProc5_exception& raise_exception);
};

#ifndef OLD_NAMES
} /* end of namespace */
#endif

#endif
