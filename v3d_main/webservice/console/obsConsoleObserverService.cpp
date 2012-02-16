/* obsConsoleObserverService.cpp
   Generated by gSOAP 2.8.3 from obsModHeader.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "obsConsoleObserverService.h"

namespace obs {

ConsoleObserverService::ConsoleObserverService()
{	ConsoleObserverService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

ConsoleObserverService::ConsoleObserverService(const struct soap &_soap) : soap(_soap)
{ }

ConsoleObserverService::ConsoleObserverService(soap_mode iomode)
{	ConsoleObserverService_init(iomode, iomode);
}

ConsoleObserverService::ConsoleObserverService(soap_mode imode, soap_mode omode)
{	ConsoleObserverService_init(imode, omode);
}

ConsoleObserverService::~ConsoleObserverService()
{ }

void ConsoleObserverService::ConsoleObserverService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"fw", "http://ws.FlyWorkstation.it.janelia.org/", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
};

void ConsoleObserverService::destroy()
{	soap_destroy(this);
	soap_end(this);
}

#ifndef WITH_PURE_VIRTUAL
ConsoleObserverService *ConsoleObserverService::copy()
{	ConsoleObserverService *dup = SOAP_NEW_COPY(ConsoleObserverService(*(struct soap*)this));
	return dup;
}
#endif

int ConsoleObserverService::soap_close_socket()
{	return soap_closesock(this);
}

int ConsoleObserverService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this, string, detailXML);
}

int ConsoleObserverService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this, subcodeQName, string, detailXML);
}

int ConsoleObserverService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this, string, detailXML);
}

int ConsoleObserverService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this, subcodeQName, string, detailXML);
}

void ConsoleObserverService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void ConsoleObserverService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *ConsoleObserverService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

void ConsoleObserverService::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *ConsoleObserverService::soap_header()
{	return this->header;
}

int ConsoleObserverService::run(int port)
{	if (soap_valid_socket(bind(NULL, port, 100)))
	{	for (;;)
		{	if (!soap_valid_socket(accept()))
				return this->error;
			(void)serve();
			soap_destroy(this);
			soap_end(this);
		}
	}
	else
		return this->error;
	return SOAP_OK;
}

SOAP_SOCKET ConsoleObserverService::bind(const char *host, int port, int backlog)
{	return soap_bind(this, host, port, backlog);
}

SOAP_SOCKET ConsoleObserverService::accept()
{	return soap_accept(this);
}

int ConsoleObserverService::serve()
{
#ifndef WITH_FASTCGI
	unsigned int k = this->max_keep_alive;
#endif
	do
	{

#ifndef WITH_FASTCGI
		if (this->max_keep_alive > 0 && !--k)
			this->keep_alive = 0;
#endif

		if (soap_begin_serve(this))
		{	if (this->error >= SOAP_STOP)
				continue;
			return this->error;
		}
		if (dispatch() || (this->fserveloop && this->fserveloop(this)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this);
#else
			return soap_send_fault(this);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(this);
		soap_end(this);
	} while (1);
#else
	} while (this->keep_alive);
#endif
	return SOAP_OK;
}

static int serve_fw__ontologySelected(ConsoleObserverService*);
static int serve_fw__ontologyChanged(ConsoleObserverService*);
static int serve_fw__entityOutlineSelected(ConsoleObserverService*);
static int serve_fw__entityOutlineDeselected(ConsoleObserverService*);
static int serve_fw__entitySelected(ConsoleObserverService*);
static int serve_fw__entityDeselected(ConsoleObserverService*);
static int serve_fw__entityChanged(ConsoleObserverService*);
static int serve_fw__entityViewRequested(ConsoleObserverService*);
static int serve_fw__annotationsChanged(ConsoleObserverService*);
static int serve_fw__sessionSelected(ConsoleObserverService*);
static int serve_fw__sessionDeselected(ConsoleObserverService*);

int ConsoleObserverService::dispatch()
{	soap_peek_element(this);
	if (!soap_match_tag(this, this->tag, "fw:ontologySelected"))
		return serve_fw__ontologySelected(this);
	if (!soap_match_tag(this, this->tag, "fw:ontologyChanged"))
		return serve_fw__ontologyChanged(this);
	if (!soap_match_tag(this, this->tag, "fw:entityOutlineSelected"))
		return serve_fw__entityOutlineSelected(this);
	if (!soap_match_tag(this, this->tag, "fw:entityOutlineDeselected"))
		return serve_fw__entityOutlineDeselected(this);
	if (!soap_match_tag(this, this->tag, "fw:entitySelected"))
		return serve_fw__entitySelected(this);
	if (!soap_match_tag(this, this->tag, "fw:entityDeselected"))
		return serve_fw__entityDeselected(this);
	if (!soap_match_tag(this, this->tag, "fw:entityChanged"))
		return serve_fw__entityChanged(this);
	if (!soap_match_tag(this, this->tag, "fw:entityViewRequested"))
		return serve_fw__entityViewRequested(this);
	if (!soap_match_tag(this, this->tag, "fw:annotationsChanged"))
		return serve_fw__annotationsChanged(this);
	if (!soap_match_tag(this, this->tag, "fw:sessionSelected"))
		return serve_fw__sessionSelected(this);
	if (!soap_match_tag(this, this->tag, "fw:sessionDeselected"))
		return serve_fw__sessionDeselected(this);
	return this->error = SOAP_NO_METHOD;
}

static int serve_fw__ontologySelected(ConsoleObserverService *soap)
{	struct fw__ontologySelected soap_tmp_fw__ontologySelected;
	struct fw__ontologySelectedResponse _param_1;
	soap_default_fw__ontologySelectedResponse(soap, &_param_1);
	soap_default_fw__ontologySelected(soap, &soap_tmp_fw__ontologySelected);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__ontologySelected(soap, &soap_tmp_fw__ontologySelected, "fw:ontologySelected", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->ontologySelected(soap_tmp_fw__ontologySelected.rootId, _param_1);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__ontologySelectedResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__ontologySelectedResponse(soap, &_param_1, "fw:ontologySelectedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__ontologySelectedResponse(soap, &_param_1, "fw:ontologySelectedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__ontologyChanged(ConsoleObserverService *soap)
{	struct fw__ontologyChanged soap_tmp_fw__ontologyChanged;
	struct fw__ontologyChangedResponse _param_2;
	soap_default_fw__ontologyChangedResponse(soap, &_param_2);
	soap_default_fw__ontologyChanged(soap, &soap_tmp_fw__ontologyChanged);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__ontologyChanged(soap, &soap_tmp_fw__ontologyChanged, "fw:ontologyChanged", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->ontologyChanged(soap_tmp_fw__ontologyChanged.rootId, _param_2);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__ontologyChangedResponse(soap, &_param_2);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__ontologyChangedResponse(soap, &_param_2, "fw:ontologyChangedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__ontologyChangedResponse(soap, &_param_2, "fw:ontologyChangedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__entityOutlineSelected(ConsoleObserverService *soap)
{	struct fw__entityOutlineSelected soap_tmp_fw__entityOutlineSelected;
	struct fw__entityOutlineSelectedResponse _param_3;
	soap_default_fw__entityOutlineSelectedResponse(soap, &_param_3);
	soap_default_fw__entityOutlineSelected(soap, &soap_tmp_fw__entityOutlineSelected);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__entityOutlineSelected(soap, &soap_tmp_fw__entityOutlineSelected, "fw:entityOutlineSelected", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->entityOutlineSelected(soap_tmp_fw__entityOutlineSelected._uniqueId, soap_tmp_fw__entityOutlineSelected._clearAll, _param_3);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__entityOutlineSelectedResponse(soap, &_param_3);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__entityOutlineSelectedResponse(soap, &_param_3, "fw:entityOutlineSelectedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__entityOutlineSelectedResponse(soap, &_param_3, "fw:entityOutlineSelectedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__entityOutlineDeselected(ConsoleObserverService *soap)
{	struct fw__entityOutlineDeselected soap_tmp_fw__entityOutlineDeselected;
	struct fw__entityOutlineDeselectedResponse _param_4;
	soap_default_fw__entityOutlineDeselectedResponse(soap, &_param_4);
	soap_default_fw__entityOutlineDeselected(soap, &soap_tmp_fw__entityOutlineDeselected);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__entityOutlineDeselected(soap, &soap_tmp_fw__entityOutlineDeselected, "fw:entityOutlineDeselected", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->entityOutlineDeselected(soap_tmp_fw__entityOutlineDeselected.uniqueId, _param_4);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__entityOutlineDeselectedResponse(soap, &_param_4);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__entityOutlineDeselectedResponse(soap, &_param_4, "fw:entityOutlineDeselectedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__entityOutlineDeselectedResponse(soap, &_param_4, "fw:entityOutlineDeselectedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__entitySelected(ConsoleObserverService *soap)
{	struct fw__entitySelected soap_tmp_fw__entitySelected;
	struct fw__entitySelectedResponse _param_5;
	soap_default_fw__entitySelectedResponse(soap, &_param_5);
	soap_default_fw__entitySelected(soap, &soap_tmp_fw__entitySelected);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__entitySelected(soap, &soap_tmp_fw__entitySelected, "fw:entitySelected", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->entitySelected(soap_tmp_fw__entitySelected._entityId, soap_tmp_fw__entitySelected._clearAll, _param_5);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__entitySelectedResponse(soap, &_param_5);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__entitySelectedResponse(soap, &_param_5, "fw:entitySelectedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__entitySelectedResponse(soap, &_param_5, "fw:entitySelectedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__entityDeselected(ConsoleObserverService *soap)
{	struct fw__entityDeselected soap_tmp_fw__entityDeselected;
	struct fw__entityDeselectedResponse _param_6;
	soap_default_fw__entityDeselectedResponse(soap, &_param_6);
	soap_default_fw__entityDeselected(soap, &soap_tmp_fw__entityDeselected);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__entityDeselected(soap, &soap_tmp_fw__entityDeselected, "fw:entityDeselected", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->entityDeselected(soap_tmp_fw__entityDeselected.entityId, _param_6);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__entityDeselectedResponse(soap, &_param_6);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__entityDeselectedResponse(soap, &_param_6, "fw:entityDeselectedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__entityDeselectedResponse(soap, &_param_6, "fw:entityDeselectedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__entityChanged(ConsoleObserverService *soap)
{	struct fw__entityChanged soap_tmp_fw__entityChanged;
	struct fw__entityChangedResponse _param_7;
	soap_default_fw__entityChangedResponse(soap, &_param_7);
	soap_default_fw__entityChanged(soap, &soap_tmp_fw__entityChanged);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__entityChanged(soap, &soap_tmp_fw__entityChanged, "fw:entityChanged", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->entityChanged(soap_tmp_fw__entityChanged.entityId, _param_7);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__entityChangedResponse(soap, &_param_7);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__entityChangedResponse(soap, &_param_7, "fw:entityChangedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__entityChangedResponse(soap, &_param_7, "fw:entityChangedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__entityViewRequested(ConsoleObserverService *soap)
{	struct fw__entityViewRequested soap_tmp_fw__entityViewRequested;
	struct fw__entityViewRequestedResponse _param_8;
	soap_default_fw__entityViewRequestedResponse(soap, &_param_8);
	soap_default_fw__entityViewRequested(soap, &soap_tmp_fw__entityViewRequested);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__entityViewRequested(soap, &soap_tmp_fw__entityViewRequested, "fw:entityViewRequested", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->entityViewRequested(soap_tmp_fw__entityViewRequested.entityId, _param_8);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__entityViewRequestedResponse(soap, &_param_8);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__entityViewRequestedResponse(soap, &_param_8, "fw:entityViewRequestedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__entityViewRequestedResponse(soap, &_param_8, "fw:entityViewRequestedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__annotationsChanged(ConsoleObserverService *soap)
{	struct fw__annotationsChanged soap_tmp_fw__annotationsChanged;
	struct fw__annotationsChangedResponse _param_9;
	soap_default_fw__annotationsChangedResponse(soap, &_param_9);
	soap_default_fw__annotationsChanged(soap, &soap_tmp_fw__annotationsChanged);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__annotationsChanged(soap, &soap_tmp_fw__annotationsChanged, "fw:annotationsChanged", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->annotationsChanged(soap_tmp_fw__annotationsChanged.entityId, _param_9);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__annotationsChangedResponse(soap, &_param_9);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__annotationsChangedResponse(soap, &_param_9, "fw:annotationsChangedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__annotationsChangedResponse(soap, &_param_9, "fw:annotationsChangedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__sessionSelected(ConsoleObserverService *soap)
{	struct fw__sessionSelected soap_tmp_fw__sessionSelected;
	struct fw__sessionSelectedResponse _param_10;
	soap_default_fw__sessionSelectedResponse(soap, &_param_10);
	soap_default_fw__sessionSelected(soap, &soap_tmp_fw__sessionSelected);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__sessionSelected(soap, &soap_tmp_fw__sessionSelected, "fw:sessionSelected", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->sessionSelected(soap_tmp_fw__sessionSelected.sessionId, _param_10);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__sessionSelectedResponse(soap, &_param_10);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__sessionSelectedResponse(soap, &_param_10, "fw:sessionSelectedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__sessionSelectedResponse(soap, &_param_10, "fw:sessionSelectedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_fw__sessionDeselected(ConsoleObserverService *soap)
{	struct fw__sessionDeselected soap_tmp_fw__sessionDeselected;
	struct fw__sessionDeselectedResponse _param_11;
	soap_default_fw__sessionDeselectedResponse(soap, &_param_11);
	soap_default_fw__sessionDeselected(soap, &soap_tmp_fw__sessionDeselected);
	soap->encodingStyle = NULL;
	if (!soap_get_fw__sessionDeselected(soap, &soap_tmp_fw__sessionDeselected, "fw:sessionDeselected", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->sessionDeselected(_param_11);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_fw__sessionDeselectedResponse(soap, &_param_11);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_fw__sessionDeselectedResponse(soap, &_param_11, "fw:sessionDeselectedResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_fw__sessionDeselectedResponse(soap, &_param_11, "fw:sessionDeselectedResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

} // namespace obs

/* End of server object code */
