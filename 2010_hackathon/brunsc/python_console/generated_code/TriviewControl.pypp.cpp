// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__convenience.pypp.hpp"
#include "__call_policies.pypp.hpp"
#include "wrappable_v3d.h"
#include "TriviewControl.pypp.hpp"

namespace bp = boost::python;

struct TriviewControl_wrapper : TriviewControl, bp::wrapper< TriviewControl > {

    TriviewControl_wrapper()
    : TriviewControl()
      , bp::wrapper< TriviewControl >(){
        // null constructor
        
    }

    virtual void * getCustomStructPointer(  ) const {
        bp::override func_getCustomStructPointer = this->get_override( "getCustomStructPointer" );
        return func_getCustomStructPointer(  );
    }

    virtual void getFocusLocation( long int & cx, long int & cy, long int & cz ) const  {
        namespace bpl = boost::python;
        if( bpl::override func_getFocusLocation = this->get_override( "getFocusLocation" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_getFocusLocation.ptr() );
            cx = boost::python::extract< long int >( pyplus_conv::get_out_argument( py_result, "cx" ) );
            cy = boost::python::extract< long int >( pyplus_conv::get_out_argument( py_result, "cy" ) );
            cz = boost::python::extract< long int >( pyplus_conv::get_out_argument( py_result, "cz" ) );
        }
        else{
              PyErr_SetString(PyExc_NotImplementedError, "Attempted calling Pure Virtual function that is not implemented :getFocusLocation");
              boost::python::throw_error_already_set();
        }
    }
    
    static boost::python::tuple default_getFocusLocation( ::TriviewControl const & inst ){
        long int cx2;
        long int cy2;
        long int cz2;
        if( dynamic_cast< TriviewControl_wrapper const* >( boost::addressof( inst ) ) ){
              PyErr_SetString(PyExc_NotImplementedError, "Attempted calling Pure Virtual function that is not implemented :getFocusLocation");
              boost::python::throw_error_already_set();
        }
        else{
            inst.getFocusLocation(cx2, cy2, cz2);
        }
        return bp::make_tuple( cx2, cy2, cz2 );
    }

    virtual void getTriViewColorDispType( int & mytype ) {
        namespace bpl = boost::python;
        if( bpl::override func_getTriViewColorDispType = this->get_override( "getTriViewColorDispType" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_getTriViewColorDispType.ptr() );
            mytype = boost::python::extract< int >( pyplus_conv::get_out_argument( py_result, "mytype" ) );
        }
        else{
              PyErr_SetString(PyExc_NotImplementedError, "Attempted calling Pure Virtual function that is not implemented :getTriViewColorDispType");
              boost::python::throw_error_already_set();
        }
    }
    
    static boost::python::object default_getTriViewColorDispType( ::TriviewControl & inst ){
        int mytype2;
        if( dynamic_cast< TriviewControl_wrapper * >( boost::addressof( inst ) ) ){
              PyErr_SetString(PyExc_NotImplementedError, "Attempted calling Pure Virtual function that is not implemented :getTriViewColorDispType");
              boost::python::throw_error_already_set();
        }
        else{
            inst.getTriViewColorDispType(mytype2);
        }
        return bp::object( mytype2 );
    }

    virtual void setCustomStructPointer( void * a ){
        bp::override func_setCustomStructPointer = this->get_override( "setCustomStructPointer" );
        func_setCustomStructPointer( a );
    }

    virtual void setFocusLocation( long int cx, long int cy, long int cz ){
        bp::override func_setFocusLocation = this->get_override( "setFocusLocation" );
        func_setFocusLocation( cx, cy, cz );
    }

    virtual void setTriViewColorDispType( int mytype ){
        bp::override func_setTriViewColorDispType = this->get_override( "setTriViewColorDispType" );
        func_setTriViewColorDispType( mytype );
    }

    virtual void updateMinMax( long int nFrame ){
        bp::override func_updateMinMax = this->get_override( "updateMinMax" );
        func_updateMinMax( nFrame );
    }

};

void register_TriviewControl_class(){

    bp::class_< TriviewControl_wrapper, boost::noncopyable >( "TriviewControl" )    
        .def( 
            "getCustomStructPointer"
            , bp::pure_virtual( (void * ( ::TriviewControl::* )(  ) const)(&::TriviewControl::getCustomStructPointer) )
            , bp::return_value_policy< bp::return_opaque_pointer >() )    
        .def( 
            "getFocusLocation"
            , (boost::python::tuple (*)( ::TriviewControl const & ))( &TriviewControl_wrapper::default_getFocusLocation )
            , ( bp::arg("inst") ) )    
        .def( 
            "getTriViewColorDispType"
            , (boost::python::object (*)( ::TriviewControl & ))( &TriviewControl_wrapper::default_getTriViewColorDispType )
            , ( bp::arg("inst") ) )    
        .def( 
            "setCustomStructPointer"
            , bp::pure_virtual( (void ( ::TriviewControl::* )( void * ) )(&::TriviewControl::setCustomStructPointer) )
            , ( bp::arg("a") ) )    
        .def( 
            "setFocusLocation"
            , bp::pure_virtual( (void ( ::TriviewControl::* )( long int,long int,long int ) )(&::TriviewControl::setFocusLocation) )
            , ( bp::arg("cx"), bp::arg("cy"), bp::arg("cz") ) )    
        .def( 
            "setTriViewColorDispType"
            , bp::pure_virtual( (void ( ::TriviewControl::* )( int ) )(&::TriviewControl::setTriViewColorDispType) )
            , ( bp::arg("mytype") ) )    
        .def( 
            "updateMinMax"
            , bp::pure_virtual( (void ( ::TriviewControl::* )( long int ) )(&::TriviewControl::updateMinMax) )
            , ( bp::arg("nFrame") ) );

}
