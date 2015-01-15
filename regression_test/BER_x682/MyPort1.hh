///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2000-2014 Ericsson Telecom AB
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v1.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v10.html
///////////////////////////////////////////////////////////////////////////////
// This Test Port skeleton header file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version 1.3.pl0
// for Matyas Forstner (tmpmfr@saussure) on Thu Apr 10 16:06:07 2003


// You may modify this file. Add your attributes and prototypes of your
// member functions here.

#ifndef MyPort1_HH
#define MyPort1_HH

#include "X.hh"

#ifndef OLD_NAMES
#define X682NS X682::
namespace X {
#else
#define X682NS
#endif

class MyPort1 : public MyPort1_BASE {
public:
	MyPort1(const char *par_port_name);
	~MyPort1();

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

	void outgoing_send(const X682NS ErrorReturn& send_par);
};

#ifndef OLD_NAMES
}
#endif

#endif
