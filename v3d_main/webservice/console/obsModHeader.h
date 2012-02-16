// Reminder: Modify typemap.dat to customize the header file generated by wsdl2h
/* obsHeader.h
   Generated by wsdl2h 2.8.3 from obs.wsdl and typemap.dat
   2012-02-16 16:50:08 GMT

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS
   USE THE soapcpp2-GENERATED SOURCE CODE FILES FOR YOUR PROJECT BUILDS

   gSOAP XML Web services tools.
   Copyright (C) 2001-2010 Robert van Engelen, Genivia Inc. All Rights Reserved.
   Part of this software is released under one of the following licenses:
   GPL or Genivia's license for commercial use.
*/

/** @page page_notes Usage Notes

NOTE:

 - Run soapcpp2 on obsHeader.h to generate the SOAP/XML processing logic.
   Use soapcpp2 option -I to specify paths for #import
   To build with STL, 'stlvector.h' is imported from 'import' dir in package.
   Use soapcpp2 option -i to generate improved proxy and server classes.
 - Use wsdl2h options -c and -s to generate pure C code or C++ code without STL.
 - Use 'typemap.dat' to control namespace bindings and type mappings.
   It is strongly recommended to customize the names of the namespace prefixes
   generated by wsdl2h. To do so, modify the prefix bindings in the Namespaces
   section below and add the modified lines to 'typemap.dat' to rerun wsdl2h.
 - Use Doxygen (www.doxygen.org) on this file to generate documentation.
 - Use wsdl2h options -nname and -Nname to globally rename the prefix 'ns'.
 - Use wsdl2h option -d to enable DOM support for xsd:anyType.
 - Use wsdl2h option -g to auto-generate readers and writers for root elements.
 - Struct/class members serialized as XML attributes are annotated with a '@'.
 - Struct/class members that have a special role are annotated with a '$'.

WARNING:

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS.
   USE THE SOURCE CODE FILES GENERATED BY soapcpp2 FOR YOUR PROJECT BUILDS:
   THE soapStub.h FILE CONTAINS THIS CONTENT WITHOUT ANNOTATIONS.

LICENSE:

@verbatim
--------------------------------------------------------------------------------
gSOAP XML Web services tools
Copyright (C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.

This software is released under one of the following two licenses:
1) GPL or 2) Genivia's license for commercial use.
--------------------------------------------------------------------------------
1) GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
2) A commercial-use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
@endverbatim

*/


//gsoapopt w

/******************************************************************************\
 *                                                                            *
 * Definitions                                                                *
 *   http://ws.FlyWorkstation.it.janelia.org/                                 *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Import                                                                     *
 *                                                                            *
\******************************************************************************/


// STL vector containers (use option -s to remove STL dependency)
#import "stlvector.h"

/******************************************************************************\
 *                                                                            *
 * Schema Namespaces                                                          *
 *                                                                            *
\******************************************************************************/


/* NOTE:

It is strongly recommended to customize the names of the namespace prefixes
generated by wsdl2h. To do so, modify the prefix bindings below and add the
modified lines to typemap.dat to rerun wsdl2h:

fw = "http://ws.FlyWorkstation.it.janelia.org/"

*/

/******************************************************************************\
 *                                                                            *
 * Built-in Schema Types and Top-Level Elements and Attributes                *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Forward Declarations                                                       *
 *                                                                            *
\******************************************************************************/



/******************************************************************************\
 *                                                                            *
 * Services                                                                   *
 *                                                                            *
\******************************************************************************/


//gsoap fw   service name:	ConsoleObserver 
//gsoap fw   service type:	ConsoleObserver 
//gsoap fw   service port:	http://localhost:30001/axis2/services/obs 
//gsoap fw   service namespace:	http://ws.FlyWorkstation.it.janelia.org/ 
//gsoap fw   service transport:	http://schemas.xmlsoap.org/soap/http 

/** @mainpage ConsoleObserver Definitions

@section ConsoleObserver_bindings Service Bindings

  - @ref ConsoleObserver

@section ConsoleObserver_more More Information

  - @ref page_notes "Usage Notes"

  - @ref page_XMLDataBinding "XML Data Binding"

  - @ref SOAP_ENV__Header "SOAP Header Content" (when applicable)

  - @ref SOAP_ENV__Detail "SOAP Fault Detail Content" (when applicable)


*/

/**

@page ConsoleObserver Binding "ObsPortBinding"

@section ConsoleObserver_operations Operations of Binding  "ObsPortBinding"

  - @ref fw__ontologySelected

  - @ref fw__ontologyChanged

  - @ref fw__entityOutlineSelected

  - @ref fw__entityOutlineDeselected

  - @ref fw__entitySelected

  - @ref fw__entityDeselected

  - @ref fw__entityChanged

  - @ref fw__entityViewRequested

  - @ref fw__annotationsChanged

  - @ref fw__sessionSelected

  - @ref fw__sessionDeselected

@section ConsoleObserver_ports Endpoints of Binding  "ObsPortBinding"

  - http://localhost:30001/axis2/services/obs

Note: use wsdl2h option -N to change the service binding prefix name

*/

/******************************************************************************\
 *                                                                            *
 * Service Binding                                                            *
 *   ConsoleObserver                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__ontologySelected                                                     *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__ontologySelectedResponse" of service binding "ConsoleObserver" operation "fw__ontologySelected"
struct fw__ontologySelectedResponse
{
};

/// Operation "fw__ontologySelected" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__ontologySelected(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              rootId,
    // response parameters:
    struct fw__ontologySelectedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__ontologySelected(
    struct soap *soap,
    // request parameters:
    LONG64                              rootId,
    // response parameters:
    struct fw__ontologySelectedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	ontologySelected rpc
//gsoap fw   service method-encoding:	ontologySelected literal
//gsoap fw   service method-action:	ontologySelected ""
int fw__ontologySelected(
    LONG64                              rootId,	///< Request parameter
    struct fw__ontologySelectedResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__ontologyChanged                                                      *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__ontologyChangedResponse" of service binding "ConsoleObserver" operation "fw__ontologyChanged"
struct fw__ontologyChangedResponse
{
};

/// Operation "fw__ontologyChanged" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__ontologyChanged(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              rootId,
    // response parameters:
    struct fw__ontologyChangedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__ontologyChanged(
    struct soap *soap,
    // request parameters:
    LONG64                              rootId,
    // response parameters:
    struct fw__ontologyChangedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	ontologyChanged rpc
//gsoap fw   service method-encoding:	ontologyChanged literal
//gsoap fw   service method-action:	ontologyChanged ""
int fw__ontologyChanged(
    LONG64                              rootId,	///< Request parameter
    struct fw__ontologyChangedResponse &	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__entityOutlineSelected                                                *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__entityOutlineSelectedResponse" of service binding "ConsoleObserver" operation "fw__entityOutlineSelected"
struct fw__entityOutlineSelectedResponse
{
};

/// Operation "fw__entityOutlineSelected" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__entityOutlineSelected(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         uniqueId,
    bool                                clearAll,
    // response parameters:
    struct fw__entityOutlineSelectedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__entityOutlineSelected(
    struct soap *soap,
    // request parameters:
    std::string                         uniqueId,
    bool                                clearAll,
    // response parameters:
    struct fw__entityOutlineSelectedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	entityOutlineSelected rpc
//gsoap fw   service method-encoding:	entityOutlineSelected literal
//gsoap fw   service method-action:	entityOutlineSelected ""
int fw__entityOutlineSelected(
    std::string                         _uniqueId,	///< Request parameter
    bool                                _clearAll,	///< Request parameter
    struct fw__entityOutlineSelectedResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__entityOutlineDeselected                                              *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__entityOutlineDeselectedResponse" of service binding "ConsoleObserver" operation "fw__entityOutlineDeselected"
struct fw__entityOutlineDeselectedResponse
{
};

/// Operation "fw__entityOutlineDeselected" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__entityOutlineDeselected(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    std::string                         uniqueId,
    // response parameters:
    struct fw__entityOutlineDeselectedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__entityOutlineDeselected(
    struct soap *soap,
    // request parameters:
    std::string                         uniqueId,
    // response parameters:
    struct fw__entityOutlineDeselectedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	entityOutlineDeselected rpc
//gsoap fw   service method-encoding:	entityOutlineDeselected literal
//gsoap fw   service method-action:	entityOutlineDeselected ""
int fw__entityOutlineDeselected(
    std::string                         uniqueId,	///< Request parameter
    struct fw__entityOutlineDeselectedResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__entitySelected                                                       *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__entitySelectedResponse" of service binding "ConsoleObserver" operation "fw__entitySelected"
struct fw__entitySelectedResponse
{
};

/// Operation "fw__entitySelected" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__entitySelected(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              entityId,
    bool                                clearAll,
    // response parameters:
    struct fw__entitySelectedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__entitySelected(
    struct soap *soap,
    // request parameters:
    LONG64                              entityId,
    bool                                clearAll,
    // response parameters:
    struct fw__entitySelectedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	entitySelected rpc
//gsoap fw   service method-encoding:	entitySelected literal
//gsoap fw   service method-action:	entitySelected ""
int fw__entitySelected(
    LONG64                              _entityId,	///< Request parameter
    bool                                _clearAll,	///< Request parameter
    struct fw__entitySelectedResponse  &	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__entityDeselected                                                     *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__entityDeselectedResponse" of service binding "ConsoleObserver" operation "fw__entityDeselected"
struct fw__entityDeselectedResponse
{
};

/// Operation "fw__entityDeselected" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__entityDeselected(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__entityDeselectedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__entityDeselected(
    struct soap *soap,
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__entityDeselectedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	entityDeselected rpc
//gsoap fw   service method-encoding:	entityDeselected literal
//gsoap fw   service method-action:	entityDeselected ""
int fw__entityDeselected(
    LONG64                              entityId,	///< Request parameter
    struct fw__entityDeselectedResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__entityChanged                                                        *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__entityChangedResponse" of service binding "ConsoleObserver" operation "fw__entityChanged"
struct fw__entityChangedResponse
{
};

/// Operation "fw__entityChanged" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__entityChanged(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__entityChangedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__entityChanged(
    struct soap *soap,
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__entityChangedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	entityChanged rpc
//gsoap fw   service method-encoding:	entityChanged literal
//gsoap fw   service method-action:	entityChanged ""
int fw__entityChanged(
    LONG64                              entityId,	///< Request parameter
    struct fw__entityChangedResponse   &	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__entityViewRequested                                                  *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__entityViewRequestedResponse" of service binding "ConsoleObserver" operation "fw__entityViewRequested"
struct fw__entityViewRequestedResponse
{
};

/// Operation "fw__entityViewRequested" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__entityViewRequested(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__entityViewRequestedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__entityViewRequested(
    struct soap *soap,
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__entityViewRequestedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	entityViewRequested rpc
//gsoap fw   service method-encoding:	entityViewRequested literal
//gsoap fw   service method-action:	entityViewRequested ""
int fw__entityViewRequested(
    LONG64                              entityId,	///< Request parameter
    struct fw__entityViewRequestedResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__annotationsChanged                                                   *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__annotationsChangedResponse" of service binding "ConsoleObserver" operation "fw__annotationsChanged"
struct fw__annotationsChangedResponse
{
};

/// Operation "fw__annotationsChanged" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__annotationsChanged(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__annotationsChangedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__annotationsChanged(
    struct soap *soap,
    // request parameters:
    LONG64                              entityId,
    // response parameters:
    struct fw__annotationsChangedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	annotationsChanged rpc
//gsoap fw   service method-encoding:	annotationsChanged literal
//gsoap fw   service method-action:	annotationsChanged ""
int fw__annotationsChanged(
    LONG64                              entityId,	///< Request parameter
    struct fw__annotationsChangedResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__sessionSelected                                                      *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__sessionSelectedResponse" of service binding "ConsoleObserver" operation "fw__sessionSelected"
struct fw__sessionSelectedResponse
{
};

/// Operation "fw__sessionSelected" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__sessionSelected(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    LONG64                              sessionId,
    // response parameters:
    struct fw__sessionSelectedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__sessionSelected(
    struct soap *soap,
    // request parameters:
    LONG64                              sessionId,
    // response parameters:
    struct fw__sessionSelectedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	sessionSelected rpc
//gsoap fw   service method-encoding:	sessionSelected literal
//gsoap fw   service method-action:	sessionSelected ""
int fw__sessionSelected(
    LONG64                              sessionId,	///< Request parameter
    struct fw__sessionSelectedResponse &	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   fw__sessionDeselected                                                    *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "fw__sessionDeselectedResponse" of service binding "ConsoleObserver" operation "fw__sessionDeselected"
struct fw__sessionDeselectedResponse
{
};

/// Operation "fw__sessionDeselected" of service binding "ConsoleObserver"

/**

Operation details:


  - SOAP RPC literal messaging

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_fw__sessionDeselected(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // request parameters:
    // response parameters:
    struct fw__sessionDeselectedResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int fw__sessionDeselected(
    struct soap *soap,
    // request parameters:
    // response parameters:
    struct fw__sessionDeselectedResponse&
  );
@endcode

C++ proxy class (defined in soapConsoleObserverProxy.h):
@code
  class ConsoleObserverProxy;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapConsoleObserverService.h):
@code
  class ConsoleObserverService;
@endcode
Important: use soapcpp2 option '-i' to generate greatly improved and easy-to-use service classes;

*/

//gsoap fw   service method-style:	sessionDeselected rpc
//gsoap fw   service method-encoding:	sessionDeselected literal
//gsoap fw   service method-action:	sessionDeselected ""
int fw__sessionDeselected(
    struct fw__sessionDeselectedResponse&	///< Response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * XML Data Binding                                                           *
 *                                                                            *
\******************************************************************************/


/**

@page page_XMLDataBinding XML Data Binding

SOAP/XML services use data bindings contractually bound by WSDL and auto-
generated by wsdl2h and soapcpp2 (see Service Bindings). Plain data bindings
are adopted from XML schemas as part of the WSDL types section or when running
wsdl2h on a set of schemas to produce non-SOAP-based XML data bindings.

The following readers and writers are C/C++ data type (de)serializers auto-
generated by wsdl2h and soapcpp2. Run soapcpp2 on this file to generate the
(de)serialization code, which is stored in soapC.c[pp]. Include "soapH.h" in
your code to import these data type and function declarations. Only use the
soapcpp2-generated files in your project build. Do not include the wsdl2h-
generated .h file in your code.

XML content can be retrieved from:
  - a file descriptor, using soap->recvfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->is = ...
  - a buffer, using the soap->frecv() callback

XML content can be stored to:
  - a file descriptor, using soap->sendfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->os = ...
  - a buffer, using the soap->fsend() callback


*/

/* End of obsHeader.h */
