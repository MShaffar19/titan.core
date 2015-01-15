///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2000-2014 Ericsson Telecom AB
// All rights reserved. This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v1.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v10.html
///////////////////////////////////////////////////////////////////////////////
// This Test Port skeleton header file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version 1.8.pre3 build 3
// for  (ecsardu@tcclab2) on Thu Apr 29 16:57:07 2010


// You may modify this file. Add your attributes and prototypes of your
// member functions here.

#ifndef PT1_HH
#define PT1_HH

#include <TTCN3.hh>

// Note: Header file dual.hh must not be included into this file!
// (because dual.hh already includes PT1.hh)
// Please add the declarations of message types manually.

#ifndef OLD_NAMES
namespace dual {
#endif

class ControlRequest;
class ControlRequest_template;
class ControlResponse;
class ControlResponse_template;
class ErrorSignal;
class PDUType1;

class PT1_PROVIDER : public PORT {
public:
	PT1_PROVIDER(const char *par_port_name);
	~PT1_PROVIDER();

	void set_parameter(const char *parameter_name,
		const char *parameter_value);

private:
	/* void Handle_Fd_Event(int fd, boolean is_readable,
		boolean is_writable, boolean is_error); */
	void Handle_Fd_Event_Error(int fd);
	void Handle_Fd_Event_Writable(int fd);
	void Handle_Fd_Event_Readable(int fd);
	/* void Handle_Timeout(double time_since_last_call); */
protected:
	void user_map(const char *system_port);
	void user_unmap(const char *system_port);

	void user_start();
	void user_stop();

	void outgoing_send(const ControlRequest& send_par);
	void outgoing_send(const OCTETSTRING& send_par);
	void outgoing_send(const PDUType1& send_par);
	virtual void incoming_message(const ControlResponse& incoming_par) = 0;
	virtual void incoming_message(const ErrorSignal& incoming_par) = 0;
	virtual void incoming_message(const OCTETSTRING& incoming_par) = 0;
};

#ifndef OLD_NAMES
} /* end of namespace */
#endif

#endif
