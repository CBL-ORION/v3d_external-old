/* soapH.h
   Generated by gSOAP 2.8.1 from ../webservice/v3dwebserver.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   The generated code is released under one of the following licenses:
   GPL OR Genivia's license for commercial use.
*/

#ifndef soapH_H
#define soapH_H
#include "soapStub.h"
#ifndef WITH_NOIDREF

#ifdef __cplusplus
extern "C" {
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_markelement(struct soap*, const void*, int);
SOAP_FMAC3 int SOAP_FMAC4 soap_putelement(struct soap*, const void*, const char*, int, int);
SOAP_FMAC3 void *SOAP_FMAC4 soap_getelement(struct soap*, int*);

#ifdef __cplusplus
}
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_putindependent(struct soap*);
SOAP_FMAC3 int SOAP_FMAC4 soap_getindependent(struct soap*);
#endif
SOAP_FMAC3 int SOAP_FMAC4 soap_ignore_element(struct soap*);

SOAP_FMAC3 void * SOAP_FMAC4 soap_instantiate(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 int SOAP_FMAC4 soap_fdelete(struct soap_clist*);
SOAP_FMAC3 void* SOAP_FMAC4 soap_class_id_enter(struct soap*, const char*, void*, int, size_t, const char*, const char*);

#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_byte(struct soap*, char *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_byte(struct soap*, const char*, int, const char *, const char*);
SOAP_FMAC3 char * SOAP_FMAC4 soap_in_byte(struct soap*, const char*, char *, const char*);

#ifndef soap_write_byte
#define soap_write_byte(soap, data) ( soap_begin_send(soap) || soap_put_byte(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_byte(struct soap*, const char *, const char*, const char*);

#ifndef soap_read_byte
#define soap_read_byte(soap, data) ( soap_begin_recv(soap) || !soap_get_byte(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char * SOAP_FMAC4 soap_get_byte(struct soap*, char *, const char*, const char*);

#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_int(struct soap*, int *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_int(struct soap*, const char*, int, const int *, const char*);
SOAP_FMAC3 int * SOAP_FMAC4 soap_in_int(struct soap*, const char*, int *, const char*);

#ifndef soap_write_int
#define soap_write_int(soap, data) ( soap_begin_send(soap) || soap_put_int(soap, data, "int", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_int(struct soap*, const int *, const char*, const char*);

#ifndef soap_read_int
#define soap_read_int(soap, data) ( soap_begin_recv(soap) || !soap_get_int(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 int * SOAP_FMAC4 soap_get_int(struct soap*, int *, const char*, const char*);

#ifndef SOAP_TYPE_long
#define SOAP_TYPE_long (12)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_long(struct soap*, long *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_long(struct soap*, const char*, int, const long *, const char*);
SOAP_FMAC3 long * SOAP_FMAC4 soap_in_long(struct soap*, const char*, long *, const char*);

#ifndef soap_write_long
#define soap_write_long(soap, data) ( soap_begin_send(soap) || soap_put_long(soap, data, "long", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_long(struct soap*, const long *, const char*, const char*);

#ifndef soap_read_long
#define soap_read_long(soap, data) ( soap_begin_recv(soap) || !soap_get_long(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 long * SOAP_FMAC4 soap_get_long(struct soap*, long *, const char*, const char*);

#ifndef SOAP_TYPE_float
#define SOAP_TYPE_float (9)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_float(struct soap*, float *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_float(struct soap*, const char*, int, const float *, const char*);
SOAP_FMAC3 float * SOAP_FMAC4 soap_in_float(struct soap*, const char*, float *, const char*);

#ifndef soap_write_float
#define soap_write_float(soap, data) ( soap_begin_send(soap) || soap_put_float(soap, data, "float", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_float(struct soap*, const float *, const char*, const char*);

#ifndef soap_read_float
#define soap_read_float(soap, data) ( soap_begin_recv(soap) || !soap_get_float(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 float * SOAP_FMAC4 soap_get_float(struct soap*, float *, const char*, const char*);

#ifndef SOAP_TYPE_ns__V3DMSG
#define SOAP_TYPE_ns__V3DMSG (13)
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__V3DMSG(struct soap*, const char*, int, const ns__V3DMSG *, const char*);
SOAP_FMAC3 ns__V3DMSG * SOAP_FMAC4 soap_in_ns__V3DMSG(struct soap*, const char*, ns__V3DMSG *, const char*);

#ifndef soap_write_ns__V3DMSG
#define soap_write_ns__V3DMSG(soap, data) ( soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "ns:V3DMSG", NULL) || soap_end_send(soap) )
#endif


#ifndef soap_read_ns__V3DMSG
#define soap_read_ns__V3DMSG(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__V3DMSG(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 ns__V3DMSG * SOAP_FMAC4 soap_get_ns__V3DMSG(struct soap*, ns__V3DMSG *, const char*, const char*);

#define soap_new_ns__V3DMSG(soap, n) soap_instantiate_ns__V3DMSG(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__V3DMSG(soap, p) soap_delete(soap, p)

SOAP_FMAC1 ns__V3DMSG * SOAP_FMAC2 soap_instantiate_ns__V3DMSG(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__V3DMSG(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__LOAD_RES
#define SOAP_TYPE_ns__LOAD_RES (11)
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__LOAD_RES(struct soap*, const char*, int, const ns__LOAD_RES *, const char*);
SOAP_FMAC3 ns__LOAD_RES * SOAP_FMAC4 soap_in_ns__LOAD_RES(struct soap*, const char*, ns__LOAD_RES *, const char*);

#ifndef soap_write_ns__LOAD_RES
#define soap_write_ns__LOAD_RES(soap, data) ( soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "ns:LOAD-RES", NULL) || soap_end_send(soap) )
#endif


#ifndef soap_read_ns__LOAD_RES
#define soap_read_ns__LOAD_RES(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__LOAD_RES(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 ns__LOAD_RES * SOAP_FMAC4 soap_get_ns__LOAD_RES(struct soap*, ns__LOAD_RES *, const char*, const char*);

#define soap_new_ns__LOAD_RES(soap, n) soap_instantiate_ns__LOAD_RES(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__LOAD_RES(soap, p) soap_delete(soap, p)

SOAP_FMAC1 ns__LOAD_RES * SOAP_FMAC2 soap_instantiate_ns__LOAD_RES(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__LOAD_RES(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_std__string
#define SOAP_TYPE_std__string (8)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_std__string(struct soap*, std::string *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_std__string(struct soap*, const std::string *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_std__string(struct soap*, const char*, int, const std::string*, const char*);
SOAP_FMAC3 std::string * SOAP_FMAC4 soap_in_std__string(struct soap*, const char*, std::string*, const char*);

#ifndef soap_write_std__string
#define soap_write_std__string(soap, data) ( soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "string", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_std__string(struct soap*, const std::string *, const char*, const char*);

#ifndef soap_read_std__string
#define soap_read_std__string(soap, data) ( soap_begin_recv(soap) || !soap_get_std__string(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 std::string * SOAP_FMAC4 soap_get_std__string(struct soap*, std::string *, const char*, const char*);

#define soap_new_std__string(soap, n) soap_instantiate_std__string(soap, n, NULL, NULL, NULL)


#define soap_delete_std__string(soap, p) soap_delete(soap, p)

SOAP_FMAC1 std::string * SOAP_FMAC2 soap_instantiate_std__string(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_std__string(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__LOAD_MSG
#define SOAP_TYPE_ns__LOAD_MSG (7)
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__LOAD_MSG(struct soap*, const char*, int, const ns__LOAD_MSG *, const char*);
SOAP_FMAC3 ns__LOAD_MSG * SOAP_FMAC4 soap_in_ns__LOAD_MSG(struct soap*, const char*, ns__LOAD_MSG *, const char*);

#ifndef soap_write_ns__LOAD_MSG
#define soap_write_ns__LOAD_MSG(soap, data) ( soap_begin_send(soap) || ((data)->soap_serialize(soap), 0) || (data)->soap_put(soap, "ns:LOAD-MSG", NULL) || soap_end_send(soap) )
#endif


#ifndef soap_read_ns__LOAD_MSG
#define soap_read_ns__LOAD_MSG(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__LOAD_MSG(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 ns__LOAD_MSG * SOAP_FMAC4 soap_get_ns__LOAD_MSG(struct soap*, ns__LOAD_MSG *, const char*, const char*);

#define soap_new_ns__LOAD_MSG(soap, n) soap_instantiate_ns__LOAD_MSG(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__LOAD_MSG(soap, p) soap_delete(soap, p)

SOAP_FMAC1 ns__LOAD_MSG * SOAP_FMAC2 soap_instantiate_ns__LOAD_MSG(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__LOAD_MSG(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (35)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Fault(struct soap*, const char*, int, const struct SOAP_ENV__Fault *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_in_SOAP_ENV__Fault(struct soap*, const char*, struct SOAP_ENV__Fault *, const char*);

#ifndef soap_write_SOAP_ENV__Fault
#define soap_write_SOAP_ENV__Fault(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Fault(soap, data), 0) || soap_put_SOAP_ENV__Fault(soap, data, "SOAP-ENV:Fault", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Fault(struct soap*, const struct SOAP_ENV__Fault *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Fault
#define soap_read_SOAP_ENV__Fault(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Fault(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Fault * SOAP_FMAC4 soap_get_SOAP_ENV__Fault(struct soap*, struct SOAP_ENV__Fault *, const char*, const char*);

#define soap_new_SOAP_ENV__Fault(soap, n) soap_instantiate_SOAP_ENV__Fault(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Fault(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Fault(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (34)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Reason(struct soap*, const char*, int, const struct SOAP_ENV__Reason *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_in_SOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason *, const char*);

#ifndef soap_write_SOAP_ENV__Reason
#define soap_write_SOAP_ENV__Reason(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Reason(soap, data), 0) || soap_put_SOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Reason(struct soap*, const struct SOAP_ENV__Reason *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Reason
#define soap_read_SOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason * SOAP_FMAC4 soap_get_SOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *, const char*, const char*);

#define soap_new_SOAP_ENV__Reason(soap, n) soap_instantiate_SOAP_ENV__Reason(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Reason(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Reason(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (31)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Detail(struct soap*, const char*, int, const struct SOAP_ENV__Detail *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_in_SOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail *, const char*);

#ifndef soap_write_SOAP_ENV__Detail
#define soap_write_SOAP_ENV__Detail(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Detail(soap, data), 0) || soap_put_SOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Detail(struct soap*, const struct SOAP_ENV__Detail *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Detail
#define soap_read_SOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail * SOAP_FMAC4 soap_get_SOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *, const char*, const char*);

#define soap_new_SOAP_ENV__Detail(soap, n) soap_instantiate_SOAP_ENV__Detail(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Detail(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Detail(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (29)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Code(struct soap*, const char*, int, const struct SOAP_ENV__Code *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_in_SOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code *, const char*);

#ifndef soap_write_SOAP_ENV__Code
#define soap_write_SOAP_ENV__Code(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Code(soap, data), 0) || soap_put_SOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Code(struct soap*, const struct SOAP_ENV__Code *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Code
#define soap_read_SOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code * SOAP_FMAC4 soap_get_SOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *, const char*, const char*);

#define soap_new_SOAP_ENV__Code(soap, n) soap_instantiate_SOAP_ENV__Code(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Code(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Code(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (28)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_SOAP_ENV__Header(struct soap*, const char*, int, const struct SOAP_ENV__Header *, const char*);
SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_in_SOAP_ENV__Header(struct soap*, const char*, struct SOAP_ENV__Header *, const char*);

#ifndef soap_write_SOAP_ENV__Header
#define soap_write_SOAP_ENV__Header(soap, data) ( soap_begin_send(soap) || (soap_serialize_SOAP_ENV__Header(soap, data), 0) || soap_put_SOAP_ENV__Header(soap, data, "SOAP-ENV:Header", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_SOAP_ENV__Header(struct soap*, const struct SOAP_ENV__Header *, const char*, const char*);

#ifndef soap_read_SOAP_ENV__Header
#define soap_read_SOAP_ENV__Header(soap, data) ( soap_begin_recv(soap) || !soap_get_SOAP_ENV__Header(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Header * SOAP_FMAC4 soap_get_SOAP_ENV__Header(struct soap*, struct SOAP_ENV__Header *, const char*, const char*);

#define soap_new_SOAP_ENV__Header(soap, n) soap_instantiate_SOAP_ENV__Header(soap, n, NULL, NULL, NULL)


#define soap_delete_SOAP_ENV__Header(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_SOAP_ENV__Header(struct soap*, int, int, void*, size_t, const void*, size_t);

#endif

#ifndef SOAP_TYPE_ns__v3dopenfile3d
#define SOAP_TYPE_ns__v3dopenfile3d (27)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__v3dopenfile3d(struct soap*, struct ns__v3dopenfile3d *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__v3dopenfile3d(struct soap*, const struct ns__v3dopenfile3d *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__v3dopenfile3d(struct soap*, const char*, int, const struct ns__v3dopenfile3d *, const char*);
SOAP_FMAC3 struct ns__v3dopenfile3d * SOAP_FMAC4 soap_in_ns__v3dopenfile3d(struct soap*, const char*, struct ns__v3dopenfile3d *, const char*);

#ifndef soap_write_ns__v3dopenfile3d
#define soap_write_ns__v3dopenfile3d(soap, data) ( soap_begin_send(soap) || (soap_serialize_ns__v3dopenfile3d(soap, data), 0) || soap_put_ns__v3dopenfile3d(soap, data, "ns:v3dopenfile3d", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__v3dopenfile3d(struct soap*, const struct ns__v3dopenfile3d *, const char*, const char*);

#ifndef soap_read_ns__v3dopenfile3d
#define soap_read_ns__v3dopenfile3d(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__v3dopenfile3d(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ns__v3dopenfile3d * SOAP_FMAC4 soap_get_ns__v3dopenfile3d(struct soap*, struct ns__v3dopenfile3d *, const char*, const char*);

#define soap_new_ns__v3dopenfile3d(soap, n) soap_instantiate_ns__v3dopenfile3d(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__v3dopenfile3d(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ns__v3dopenfile3d * SOAP_FMAC2 soap_instantiate_ns__v3dopenfile3d(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__v3dopenfile3d(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__v3dopenfile
#define SOAP_TYPE_ns__v3dopenfile (24)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__v3dopenfile(struct soap*, struct ns__v3dopenfile *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__v3dopenfile(struct soap*, const struct ns__v3dopenfile *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__v3dopenfile(struct soap*, const char*, int, const struct ns__v3dopenfile *, const char*);
SOAP_FMAC3 struct ns__v3dopenfile * SOAP_FMAC4 soap_in_ns__v3dopenfile(struct soap*, const char*, struct ns__v3dopenfile *, const char*);

#ifndef soap_write_ns__v3dopenfile
#define soap_write_ns__v3dopenfile(soap, data) ( soap_begin_send(soap) || (soap_serialize_ns__v3dopenfile(soap, data), 0) || soap_put_ns__v3dopenfile(soap, data, "ns:v3dopenfile", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__v3dopenfile(struct soap*, const struct ns__v3dopenfile *, const char*, const char*);

#ifndef soap_read_ns__v3dopenfile
#define soap_read_ns__v3dopenfile(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__v3dopenfile(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ns__v3dopenfile * SOAP_FMAC4 soap_get_ns__v3dopenfile(struct soap*, struct ns__v3dopenfile *, const char*, const char*);

#define soap_new_ns__v3dopenfile(soap, n) soap_instantiate_ns__v3dopenfile(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__v3dopenfile(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ns__v3dopenfile * SOAP_FMAC2 soap_instantiate_ns__v3dopenfile(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__v3dopenfile(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__v3dopenfileResponse
#define SOAP_TYPE_ns__v3dopenfileResponse (23)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__v3dopenfileResponse(struct soap*, struct ns__v3dopenfileResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__v3dopenfileResponse(struct soap*, const struct ns__v3dopenfileResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__v3dopenfileResponse(struct soap*, const char*, int, const struct ns__v3dopenfileResponse *, const char*);
SOAP_FMAC3 struct ns__v3dopenfileResponse * SOAP_FMAC4 soap_in_ns__v3dopenfileResponse(struct soap*, const char*, struct ns__v3dopenfileResponse *, const char*);

#ifndef soap_write_ns__v3dopenfileResponse
#define soap_write_ns__v3dopenfileResponse(soap, data) ( soap_begin_send(soap) || (soap_serialize_ns__v3dopenfileResponse(soap, data), 0) || soap_put_ns__v3dopenfileResponse(soap, data, "ns:v3dopenfileResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__v3dopenfileResponse(struct soap*, const struct ns__v3dopenfileResponse *, const char*, const char*);

#ifndef soap_read_ns__v3dopenfileResponse
#define soap_read_ns__v3dopenfileResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__v3dopenfileResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ns__v3dopenfileResponse * SOAP_FMAC4 soap_get_ns__v3dopenfileResponse(struct soap*, struct ns__v3dopenfileResponse *, const char*, const char*);

#define soap_new_ns__v3dopenfileResponse(soap, n) soap_instantiate_ns__v3dopenfileResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__v3dopenfileResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ns__v3dopenfileResponse * SOAP_FMAC2 soap_instantiate_ns__v3dopenfileResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__v3dopenfileResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__msghandler
#define SOAP_TYPE_ns__msghandler (21)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__msghandler(struct soap*, struct ns__msghandler *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__msghandler(struct soap*, const struct ns__msghandler *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__msghandler(struct soap*, const char*, int, const struct ns__msghandler *, const char*);
SOAP_FMAC3 struct ns__msghandler * SOAP_FMAC4 soap_in_ns__msghandler(struct soap*, const char*, struct ns__msghandler *, const char*);

#ifndef soap_write_ns__msghandler
#define soap_write_ns__msghandler(soap, data) ( soap_begin_send(soap) || (soap_serialize_ns__msghandler(soap, data), 0) || soap_put_ns__msghandler(soap, data, "ns:msghandler", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__msghandler(struct soap*, const struct ns__msghandler *, const char*, const char*);

#ifndef soap_read_ns__msghandler
#define soap_read_ns__msghandler(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__msghandler(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ns__msghandler * SOAP_FMAC4 soap_get_ns__msghandler(struct soap*, struct ns__msghandler *, const char*, const char*);

#define soap_new_ns__msghandler(soap, n) soap_instantiate_ns__msghandler(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__msghandler(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ns__msghandler * SOAP_FMAC2 soap_instantiate_ns__msghandler(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__msghandler(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__helloworld
#define SOAP_TYPE_ns__helloworld (17)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__helloworld(struct soap*, struct ns__helloworld *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__helloworld(struct soap*, const struct ns__helloworld *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__helloworld(struct soap*, const char*, int, const struct ns__helloworld *, const char*);
SOAP_FMAC3 struct ns__helloworld * SOAP_FMAC4 soap_in_ns__helloworld(struct soap*, const char*, struct ns__helloworld *, const char*);

#ifndef soap_write_ns__helloworld
#define soap_write_ns__helloworld(soap, data) ( soap_begin_send(soap) || (soap_serialize_ns__helloworld(soap, data), 0) || soap_put_ns__helloworld(soap, data, "ns:helloworld", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__helloworld(struct soap*, const struct ns__helloworld *, const char*, const char*);

#ifndef soap_read_ns__helloworld
#define soap_read_ns__helloworld(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__helloworld(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ns__helloworld * SOAP_FMAC4 soap_get_ns__helloworld(struct soap*, struct ns__helloworld *, const char*, const char*);

#define soap_new_ns__helloworld(soap, n) soap_instantiate_ns__helloworld(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__helloworld(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ns__helloworld * SOAP_FMAC2 soap_instantiate_ns__helloworld(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__helloworld(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef SOAP_TYPE_ns__helloworldResponse
#define SOAP_TYPE_ns__helloworldResponse (16)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_ns__helloworldResponse(struct soap*, struct ns__helloworldResponse *);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_ns__helloworldResponse(struct soap*, const struct ns__helloworldResponse *);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_ns__helloworldResponse(struct soap*, const char*, int, const struct ns__helloworldResponse *, const char*);
SOAP_FMAC3 struct ns__helloworldResponse * SOAP_FMAC4 soap_in_ns__helloworldResponse(struct soap*, const char*, struct ns__helloworldResponse *, const char*);

#ifndef soap_write_ns__helloworldResponse
#define soap_write_ns__helloworldResponse(soap, data) ( soap_begin_send(soap) || (soap_serialize_ns__helloworldResponse(soap, data), 0) || soap_put_ns__helloworldResponse(soap, data, "ns:helloworldResponse", NULL) || soap_end_send(soap) )
#endif


SOAP_FMAC3 int SOAP_FMAC4 soap_put_ns__helloworldResponse(struct soap*, const struct ns__helloworldResponse *, const char*, const char*);

#ifndef soap_read_ns__helloworldResponse
#define soap_read_ns__helloworldResponse(soap, data) ( soap_begin_recv(soap) || !soap_get_ns__helloworldResponse(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct ns__helloworldResponse * SOAP_FMAC4 soap_get_ns__helloworldResponse(struct soap*, struct ns__helloworldResponse *, const char*, const char*);

#define soap_new_ns__helloworldResponse(soap, n) soap_instantiate_ns__helloworldResponse(soap, n, NULL, NULL, NULL)


#define soap_delete_ns__helloworldResponse(soap, p) soap_delete(soap, p)

SOAP_FMAC1 struct ns__helloworldResponse * SOAP_FMAC2 soap_instantiate_ns__helloworldResponse(struct soap*, int, const char*, const char*, size_t*);
SOAP_FMAC3 void SOAP_FMAC4 soap_copy_ns__helloworldResponse(struct soap*, int, int, void*, size_t, const void*, size_t);

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (37)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Reason(struct soap*, const char *, int, struct SOAP_ENV__Reason *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Reason(struct soap*, const char*, struct SOAP_ENV__Reason **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Reason
#define soap_write_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Reason(soap, data), 0) || soap_put_PointerToSOAP_ENV__Reason(soap, data, "SOAP-ENV:Reason", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Reason
#define soap_read_PointerToSOAP_ENV__Reason(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Reason(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Reason ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Reason(struct soap*, struct SOAP_ENV__Reason **, const char*, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (36)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Detail(struct soap*, const char *, int, struct SOAP_ENV__Detail *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Detail(struct soap*, const char*, struct SOAP_ENV__Detail **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Detail
#define soap_write_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Detail(soap, data), 0) || soap_put_PointerToSOAP_ENV__Detail(soap, data, "SOAP-ENV:Detail", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Detail
#define soap_read_PointerToSOAP_ENV__Detail(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Detail(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Detail ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Detail(struct soap*, struct SOAP_ENV__Detail **, const char*, const char*);

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (30)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerToSOAP_ENV__Code(struct soap*, const char *, int, struct SOAP_ENV__Code *const*, const char *);
SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_in_PointerToSOAP_ENV__Code(struct soap*, const char*, struct SOAP_ENV__Code **, const char*);

#ifndef soap_write_PointerToSOAP_ENV__Code
#define soap_write_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerToSOAP_ENV__Code(soap, data), 0) || soap_put_PointerToSOAP_ENV__Code(soap, data, "SOAP-ENV:Code", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code *const*, const char*, const char*);

#ifndef soap_read_PointerToSOAP_ENV__Code
#define soap_read_PointerToSOAP_ENV__Code(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerToSOAP_ENV__Code(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 struct SOAP_ENV__Code ** SOAP_FMAC4 soap_get_PointerToSOAP_ENV__Code(struct soap*, struct SOAP_ENV__Code **, const char*, const char*);

#endif

#ifndef SOAP_TYPE_PointerTons__V3DMSG
#define SOAP_TYPE_PointerTons__V3DMSG (25)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTons__V3DMSG(struct soap*, ns__V3DMSG *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTons__V3DMSG(struct soap*, const char *, int, ns__V3DMSG *const*, const char *);
SOAP_FMAC3 ns__V3DMSG ** SOAP_FMAC4 soap_in_PointerTons__V3DMSG(struct soap*, const char*, ns__V3DMSG **, const char*);

#ifndef soap_write_PointerTons__V3DMSG
#define soap_write_PointerTons__V3DMSG(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerTons__V3DMSG(soap, data), 0) || soap_put_PointerTons__V3DMSG(soap, data, "ns:V3DMSG", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTons__V3DMSG(struct soap*, ns__V3DMSG *const*, const char*, const char*);

#ifndef soap_read_PointerTons__V3DMSG
#define soap_read_PointerTons__V3DMSG(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTons__V3DMSG(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 ns__V3DMSG ** SOAP_FMAC4 soap_get_PointerTons__V3DMSG(struct soap*, ns__V3DMSG **, const char*, const char*);

#ifndef SOAP_TYPE_PointerTons__LOAD_RES
#define SOAP_TYPE_PointerTons__LOAD_RES (19)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTons__LOAD_RES(struct soap*, ns__LOAD_RES *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTons__LOAD_RES(struct soap*, const char *, int, ns__LOAD_RES *const*, const char *);
SOAP_FMAC3 ns__LOAD_RES ** SOAP_FMAC4 soap_in_PointerTons__LOAD_RES(struct soap*, const char*, ns__LOAD_RES **, const char*);

#ifndef soap_write_PointerTons__LOAD_RES
#define soap_write_PointerTons__LOAD_RES(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerTons__LOAD_RES(soap, data), 0) || soap_put_PointerTons__LOAD_RES(soap, data, "ns:LOAD-RES", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTons__LOAD_RES(struct soap*, ns__LOAD_RES *const*, const char*, const char*);

#ifndef soap_read_PointerTons__LOAD_RES
#define soap_read_PointerTons__LOAD_RES(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTons__LOAD_RES(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 ns__LOAD_RES ** SOAP_FMAC4 soap_get_PointerTons__LOAD_RES(struct soap*, ns__LOAD_RES **, const char*, const char*);

#ifndef SOAP_TYPE_PointerTons__LOAD_MSG
#define SOAP_TYPE_PointerTons__LOAD_MSG (18)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTons__LOAD_MSG(struct soap*, ns__LOAD_MSG *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTons__LOAD_MSG(struct soap*, const char *, int, ns__LOAD_MSG *const*, const char *);
SOAP_FMAC3 ns__LOAD_MSG ** SOAP_FMAC4 soap_in_PointerTons__LOAD_MSG(struct soap*, const char*, ns__LOAD_MSG **, const char*);

#ifndef soap_write_PointerTons__LOAD_MSG
#define soap_write_PointerTons__LOAD_MSG(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerTons__LOAD_MSG(soap, data), 0) || soap_put_PointerTons__LOAD_MSG(soap, data, "ns:LOAD-MSG", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTons__LOAD_MSG(struct soap*, ns__LOAD_MSG *const*, const char*, const char*);

#ifndef soap_read_PointerTons__LOAD_MSG
#define soap_read_PointerTons__LOAD_MSG(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTons__LOAD_MSG(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 ns__LOAD_MSG ** SOAP_FMAC4 soap_get_PointerTons__LOAD_MSG(struct soap*, ns__LOAD_MSG **, const char*, const char*);

#ifndef SOAP_TYPE_PointerTostring
#define SOAP_TYPE_PointerTostring (14)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_PointerTostring(struct soap*, char **const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_PointerTostring(struct soap*, const char *, int, char **const*, const char *);
SOAP_FMAC3 char *** SOAP_FMAC4 soap_in_PointerTostring(struct soap*, const char*, char ***, const char*);

#ifndef soap_write_PointerTostring
#define soap_write_PointerTostring(soap, data) ( soap_begin_send(soap) || (soap_serialize_PointerTostring(soap, data), 0) || soap_put_PointerTostring(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_PointerTostring(struct soap*, char **const*, const char*, const char*);

#ifndef soap_read_PointerTostring
#define soap_read_PointerTostring(soap, data) ( soap_begin_recv(soap) || !soap_get_PointerTostring(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char *** SOAP_FMAC4 soap_get_PointerTostring(struct soap*, char ***, const char*, const char*);

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
#endif

#define soap_default__QName(soap, a) soap_default_string(soap, a)


#define soap_serialize__QName(soap, a) soap_serialize_string(soap, a)

SOAP_FMAC3 int SOAP_FMAC4 soap_out__QName(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in__QName(struct soap*, const char*, char **, const char*);

#ifndef soap_write__QName
#define soap_write__QName(soap, data) ( soap_begin_send(soap) || (soap_serialize__QName(soap, data), 0) || soap_put__QName(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put__QName(struct soap*, char *const*, const char*, const char*);

#ifndef soap_read__QName
#define soap_read__QName(soap, data) ( soap_begin_recv(soap) || !soap_get__QName(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get__QName(struct soap*, char **, const char*, const char*);

#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif
SOAP_FMAC3 void SOAP_FMAC4 soap_default_string(struct soap*, char **);
SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_string(struct soap*, char *const*);
SOAP_FMAC3 int SOAP_FMAC4 soap_out_string(struct soap*, const char*, int, char*const*, const char*);
SOAP_FMAC3 char * * SOAP_FMAC4 soap_in_string(struct soap*, const char*, char **, const char*);

#ifndef soap_write_string
#define soap_write_string(soap, data) ( soap_begin_send(soap) || (soap_serialize_string(soap, data), 0) || soap_put_string(soap, data, "byte", NULL) || soap_end_send(soap) )
#endif

SOAP_FMAC3 int SOAP_FMAC4 soap_put_string(struct soap*, char *const*, const char*, const char*);

#ifndef soap_read_string
#define soap_read_string(soap, data) ( soap_begin_recv(soap) || !soap_get_string(soap, data, NULL, NULL) || soap_end_recv(soap) )
#endif

SOAP_FMAC3 char ** SOAP_FMAC4 soap_get_string(struct soap*, char **, const char*, const char*);

#endif

/* End of soapH.h */