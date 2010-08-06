#ifndef JACE_PROXY_LOCI_FORMATS_CODEC_NIKONCODECOPTIONS_H
#define JACE_PROXY_LOCI_FORMATS_CODEC_NIKONCODECOPTIONS_H

#ifndef JACE_OS_DEP_H
#include "jace/os_dep.h"
#endif

#ifndef JACE_NAMESPACE_H
#include "jace/namespace.h"
#endif

#ifndef JACE_JOBJECT_H
#include "jace/proxy/JObject.h"
#endif

#ifndef JACE_JARRAY_H
#include "jace/JArray.h"
#endif

#ifndef JACE_JFIELD_PROXY_H
#include "jace/JFieldProxy.h"
#endif

#ifndef JACE_JCLASSIMPL_H
#include "jace/JClassImpl.h"
#endif

/**
 * The super class for this class.
 *
 */
#ifndef JACE_PROXY_LOCI_FORMATS_CODEC_CODECOPTIONS_H
#include "jace/proxy/loci/formats/codec/CodecOptions.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JBOOLEAN_H
#include "jace/proxy/types/JBoolean.h"
#endif

#ifndef JACE_TYPES_JINT_H
#include "jace/proxy/types/JInt.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_3( jace, proxy, types )
class JVoid;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, loci, formats, codec )

/**
 * The Jace C++ proxy class for loci.formats.codec.NikonCodecOptions.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class NikonCodecOptions : public ::jace::proxy::loci::formats::codec::CodecOptions
{
public: 

/**
 * NikonCodecOptions
 *
 */
NikonCodecOptions();

/**
 * public lossy
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JBoolean > lossy();

/**
 * public split
 *
 */
::jace::JFieldProxy< ::jace::proxy::types::JInt > split();

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
NikonCodecOptions( jvalue value );
NikonCodecOptions( jobject object );
NikonCodecOptions( const NikonCodecOptions& object );
NikonCodecOptions( const NoOp& noOp );
virtual const JClass& getJavaJniClass() const throw ( ::jace::JNIException );
static const JClass& staticGetJavaJniClass() throw ( ::jace::JNIException );
};

END_NAMESPACE_5( jace, proxy, loci, formats, codec )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::ElementProxy( const jace::ElementProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::loci::formats::codec::NikonCodecOptions( element ), Object( NO_OP ), mIndex( index )
  {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::ElementProxy( const jace::ElementProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>& proxy ) : 
    ::jace::proxy::loci::formats::codec::NikonCodecOptions( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex )
  {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::loci::formats::codec::NikonCodecOptions( value ), Object( NO_OP ), fieldID( fieldID_ )
  {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ )
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    else
      parent = parent_;

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::loci::formats::codec::NikonCodecOptions( value ), Object( NO_OP ), fieldID( fieldID_ )
  {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::loci::formats::codec::NikonCodecOptions>& object ) : 
    ::jace::proxy::loci::formats::codec::NikonCodecOptions( object.getJavaJniValue() ), Object( NO_OP )
  {
    fieldID = object.fieldID; 

    if ( object.parent )
    {
      JNIEnv* env = ::jace::helper::attach();
      parent = ::jace::helper::newGlobalRef( env, object.parent );
    }
    else
      parent = 0;

    if ( object.parentClass )
    {
      JNIEnv* env = ::jace::helper::attach();
      parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, object.parentClass ) );
    }
    else
      parentClass = 0;
  }
#endif

END_NAMESPACE( jace )

#endif // #ifndef JACE_PROXY_LOCI_FORMATS_CODEC_NIKONCODECOPTIONS_H

