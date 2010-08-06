#ifndef JACE_PROXY_LOCI_FORMATS_META_METADATARETRIEVE_H
#define JACE_PROXY_LOCI_FORMATS_META_METADATARETRIEVE_H

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
#ifndef JACE_PROXY_JAVA_LANG_OBJECT_H
#include "jace/proxy/java/lang/Object.h"
#endif

/**
 * Classes which this class is fully dependent upon.
 *
 */
#ifndef JACE_TYPES_JBYTE_H
#include "jace/proxy/types/JByte.h"
#endif

/**
 * Forward declarations for the classes that this class uses.
 *
 */
BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class String;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Integer;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Double;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_4( jace, proxy, java, lang )
class Boolean;
END_NAMESPACE_4( jace, proxy, java, lang )

BEGIN_NAMESPACE_3( jace, proxy, types )
class JInt;
END_NAMESPACE_3( jace, proxy, types )

BEGIN_NAMESPACE_5( jace, proxy, loci, formats, meta )

/**
 * The Jace C++ proxy class for loci.formats.meta.MetadataRetrieve.
 * Please do not edit this class, as any changes you make will be overwritten.
 * For more information, please refer to the Jace Developer's Guide.
 *
 */
class MetadataRetrieve : public virtual ::jace::proxy::java::lang::Object
{
public: 

/**
 * getChannelComponentCount
 *
 */
::jace::proxy::types::JInt getChannelComponentCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDatasetCount
 *
 */
::jace::proxy::types::JInt getDatasetCount();

/**
 * getDatasetRefCount
 *
 */
::jace::proxy::types::JInt getDatasetRefCount( ::jace::proxy::types::JInt p0 );

/**
 * getDetectorCount
 *
 */
::jace::proxy::types::JInt getDetectorCount( ::jace::proxy::types::JInt p0 );

/**
 * getDichroicCount
 *
 */
::jace::proxy::types::JInt getDichroicCount( ::jace::proxy::types::JInt p0 );

/**
 * getExperimentCount
 *
 */
::jace::proxy::types::JInt getExperimentCount();

/**
 * getExperimenterCount
 *
 */
::jace::proxy::types::JInt getExperimenterCount();

/**
 * getExperimenterMembershipCount
 *
 */
::jace::proxy::types::JInt getExperimenterMembershipCount( ::jace::proxy::types::JInt p0 );

/**
 * getFilterCount
 *
 */
::jace::proxy::types::JInt getFilterCount( ::jace::proxy::types::JInt p0 );

/**
 * getFilterSetCount
 *
 */
::jace::proxy::types::JInt getFilterSetCount( ::jace::proxy::types::JInt p0 );

/**
 * getGroupCount
 *
 */
::jace::proxy::types::JInt getGroupCount();

/**
 * getGroupRefCount
 *
 */
::jace::proxy::types::JInt getGroupRefCount( ::jace::proxy::types::JInt p0 );

/**
 * getImageCount
 *
 */
::jace::proxy::types::JInt getImageCount();

/**
 * getInstrumentCount
 *
 */
::jace::proxy::types::JInt getInstrumentCount();

/**
 * getLightSourceCount
 *
 */
::jace::proxy::types::JInt getLightSourceCount( ::jace::proxy::types::JInt p0 );

/**
 * getLightSourceRefCount
 *
 */
::jace::proxy::types::JInt getLightSourceRefCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelCount
 *
 */
::jace::proxy::types::JInt getLogicalChannelCount( ::jace::proxy::types::JInt p0 );

/**
 * getMicrobeamManipulationCount
 *
 */
::jace::proxy::types::JInt getMicrobeamManipulationCount( ::jace::proxy::types::JInt p0 );

/**
 * getMicrobeamManipulationRefCount
 *
 */
::jace::proxy::types::JInt getMicrobeamManipulationRefCount( ::jace::proxy::types::JInt p0 );

/**
 * getOTFCount
 *
 */
::jace::proxy::types::JInt getOTFCount( ::jace::proxy::types::JInt p0 );

/**
 * getObjectiveCount
 *
 */
::jace::proxy::types::JInt getObjectiveCount( ::jace::proxy::types::JInt p0 );

/**
 * getPixelsCount
 *
 */
::jace::proxy::types::JInt getPixelsCount( ::jace::proxy::types::JInt p0 );

/**
 * getPlaneCount
 *
 */
::jace::proxy::types::JInt getPlaneCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPlateCount
 *
 */
::jace::proxy::types::JInt getPlateCount();

/**
 * getPlateRefCount
 *
 */
::jace::proxy::types::JInt getPlateRefCount( ::jace::proxy::types::JInt p0 );

/**
 * getProjectCount
 *
 */
::jace::proxy::types::JInt getProjectCount();

/**
 * getProjectRefCount
 *
 */
::jace::proxy::types::JInt getProjectRefCount( ::jace::proxy::types::JInt p0 );

/**
 * getROICount
 *
 */
::jace::proxy::types::JInt getROICount( ::jace::proxy::types::JInt p0 );

/**
 * getROIRefCount
 *
 */
::jace::proxy::types::JInt getROIRefCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getReagentCount
 *
 */
::jace::proxy::types::JInt getReagentCount( ::jace::proxy::types::JInt p0 );

/**
 * getRegionCount
 *
 */
::jace::proxy::types::JInt getRegionCount( ::jace::proxy::types::JInt p0 );

/**
 * getRoiLinkCount
 *
 */
::jace::proxy::types::JInt getRoiLinkCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getScreenCount
 *
 */
::jace::proxy::types::JInt getScreenCount();

/**
 * getScreenAcquisitionCount
 *
 */
::jace::proxy::types::JInt getScreenAcquisitionCount( ::jace::proxy::types::JInt p0 );

/**
 * getScreenRefCount
 *
 */
::jace::proxy::types::JInt getScreenRefCount( ::jace::proxy::types::JInt p0 );

/**
 * getShapeCount
 *
 */
::jace::proxy::types::JInt getShapeCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getTiffDataCount
 *
 */
::jace::proxy::types::JInt getTiffDataCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellCount
 *
 */
::jace::proxy::types::JInt getWellCount( ::jace::proxy::types::JInt p0 );

/**
 * getWellSampleCount
 *
 */
::jace::proxy::types::JInt getWellSampleCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellSampleRefCount
 *
 */
::jace::proxy::types::JInt getWellSampleRefCount( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getUUID
 *
 */
::jace::proxy::java::lang::String getUUID();

/**
 * getArcType
 *
 */
::jace::proxy::java::lang::String getArcType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getChannelComponentColorDomain
 *
 */
::jace::proxy::java::lang::String getChannelComponentColorDomain( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getChannelComponentIndex
 *
 */
::jace::proxy::java::lang::Integer getChannelComponentIndex( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getChannelComponentPixels
 *
 */
::jace::proxy::java::lang::String getChannelComponentPixels( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getCircleCx
 *
 */
::jace::proxy::java::lang::String getCircleCx( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getCircleCy
 *
 */
::jace::proxy::java::lang::String getCircleCy( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getCircleID
 *
 */
::jace::proxy::java::lang::String getCircleID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getCircleR
 *
 */
::jace::proxy::java::lang::String getCircleR( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getCircleTransform
 *
 */
::jace::proxy::java::lang::String getCircleTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getContactExperimenter
 *
 */
::jace::proxy::java::lang::String getContactExperimenter( ::jace::proxy::types::JInt p0 );

/**
 * getDatasetDescription
 *
 */
::jace::proxy::java::lang::String getDatasetDescription( ::jace::proxy::types::JInt p0 );

/**
 * getDatasetExperimenterRef
 *
 */
::jace::proxy::java::lang::String getDatasetExperimenterRef( ::jace::proxy::types::JInt p0 );

/**
 * getDatasetGroupRef
 *
 */
::jace::proxy::java::lang::String getDatasetGroupRef( ::jace::proxy::types::JInt p0 );

/**
 * getDatasetID
 *
 */
::jace::proxy::java::lang::String getDatasetID( ::jace::proxy::types::JInt p0 );

/**
 * getDatasetLocked
 *
 */
::jace::proxy::java::lang::Boolean getDatasetLocked( ::jace::proxy::types::JInt p0 );

/**
 * getDatasetName
 *
 */
::jace::proxy::java::lang::String getDatasetName( ::jace::proxy::types::JInt p0 );

/**
 * getDatasetRefID
 *
 */
::jace::proxy::java::lang::String getDatasetRefID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorAmplificationGain
 *
 */
::jace::proxy::java::lang::Double getDetectorAmplificationGain( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorGain
 *
 */
::jace::proxy::java::lang::Double getDetectorGain( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorID
 *
 */
::jace::proxy::java::lang::String getDetectorID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorManufacturer
 *
 */
::jace::proxy::java::lang::String getDetectorManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorModel
 *
 */
::jace::proxy::java::lang::String getDetectorModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorOffset
 *
 */
::jace::proxy::java::lang::Double getDetectorOffset( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorSerialNumber
 *
 */
::jace::proxy::java::lang::String getDetectorSerialNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorType
 *
 */
::jace::proxy::java::lang::String getDetectorType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorVoltage
 *
 */
::jace::proxy::java::lang::Double getDetectorVoltage( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorZoom
 *
 */
::jace::proxy::java::lang::Double getDetectorZoom( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorSettingsBinning
 *
 */
::jace::proxy::java::lang::String getDetectorSettingsBinning( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorSettingsDetector
 *
 */
::jace::proxy::java::lang::String getDetectorSettingsDetector( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorSettingsGain
 *
 */
::jace::proxy::java::lang::Double getDetectorSettingsGain( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorSettingsOffset
 *
 */
::jace::proxy::java::lang::Double getDetectorSettingsOffset( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorSettingsReadOutRate
 *
 */
::jace::proxy::java::lang::Double getDetectorSettingsReadOutRate( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDetectorSettingsVoltage
 *
 */
::jace::proxy::java::lang::Double getDetectorSettingsVoltage( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDichroicID
 *
 */
::jace::proxy::java::lang::String getDichroicID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDichroicLotNumber
 *
 */
::jace::proxy::java::lang::String getDichroicLotNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDichroicManufacturer
 *
 */
::jace::proxy::java::lang::String getDichroicManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDichroicModel
 *
 */
::jace::proxy::java::lang::String getDichroicModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDimensionsPhysicalSizeX
 *
 */
::jace::proxy::java::lang::Double getDimensionsPhysicalSizeX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDimensionsPhysicalSizeY
 *
 */
::jace::proxy::java::lang::Double getDimensionsPhysicalSizeY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDimensionsPhysicalSizeZ
 *
 */
::jace::proxy::java::lang::Double getDimensionsPhysicalSizeZ( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDimensionsTimeIncrement
 *
 */
::jace::proxy::java::lang::Double getDimensionsTimeIncrement( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDimensionsWaveIncrement
 *
 */
::jace::proxy::java::lang::Integer getDimensionsWaveIncrement( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDimensionsWaveStart
 *
 */
::jace::proxy::java::lang::Integer getDimensionsWaveStart( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getDisplayOptionsDisplay
 *
 */
::jace::proxy::java::lang::String getDisplayOptionsDisplay( ::jace::proxy::types::JInt p0 );

/**
 * getDisplayOptionsID
 *
 */
::jace::proxy::java::lang::String getDisplayOptionsID( ::jace::proxy::types::JInt p0 );

/**
 * getDisplayOptionsZoom
 *
 */
::jace::proxy::java::lang::Double getDisplayOptionsZoom( ::jace::proxy::types::JInt p0 );

/**
 * getEllipseCx
 *
 */
::jace::proxy::java::lang::String getEllipseCx( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getEllipseCy
 *
 */
::jace::proxy::java::lang::String getEllipseCy( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getEllipseID
 *
 */
::jace::proxy::java::lang::String getEllipseID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getEllipseRx
 *
 */
::jace::proxy::java::lang::String getEllipseRx( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getEllipseRy
 *
 */
::jace::proxy::java::lang::String getEllipseRy( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getEllipseTransform
 *
 */
::jace::proxy::java::lang::String getEllipseTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getEmFilterLotNumber
 *
 */
::jace::proxy::java::lang::String getEmFilterLotNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getEmFilterManufacturer
 *
 */
::jace::proxy::java::lang::String getEmFilterManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getEmFilterModel
 *
 */
::jace::proxy::java::lang::String getEmFilterModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getEmFilterType
 *
 */
::jace::proxy::java::lang::String getEmFilterType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getExFilterLotNumber
 *
 */
::jace::proxy::java::lang::String getExFilterLotNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getExFilterManufacturer
 *
 */
::jace::proxy::java::lang::String getExFilterManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getExFilterModel
 *
 */
::jace::proxy::java::lang::String getExFilterModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getExFilterType
 *
 */
::jace::proxy::java::lang::String getExFilterType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getExperimentDescription
 *
 */
::jace::proxy::java::lang::String getExperimentDescription( ::jace::proxy::types::JInt p0 );

/**
 * getExperimentExperimenterRef
 *
 */
::jace::proxy::java::lang::String getExperimentExperimenterRef( ::jace::proxy::types::JInt p0 );

/**
 * getExperimentID
 *
 */
::jace::proxy::java::lang::String getExperimentID( ::jace::proxy::types::JInt p0 );

/**
 * getExperimentType
 *
 */
::jace::proxy::java::lang::String getExperimentType( ::jace::proxy::types::JInt p0 );

/**
 * getExperimenterEmail
 *
 */
::jace::proxy::java::lang::String getExperimenterEmail( ::jace::proxy::types::JInt p0 );

/**
 * getExperimenterFirstName
 *
 */
::jace::proxy::java::lang::String getExperimenterFirstName( ::jace::proxy::types::JInt p0 );

/**
 * getExperimenterID
 *
 */
::jace::proxy::java::lang::String getExperimenterID( ::jace::proxy::types::JInt p0 );

/**
 * getExperimenterInstitution
 *
 */
::jace::proxy::java::lang::String getExperimenterInstitution( ::jace::proxy::types::JInt p0 );

/**
 * getExperimenterLastName
 *
 */
::jace::proxy::java::lang::String getExperimenterLastName( ::jace::proxy::types::JInt p0 );

/**
 * getExperimenterOMEName
 *
 */
::jace::proxy::java::lang::String getExperimenterOMEName( ::jace::proxy::types::JInt p0 );

/**
 * getExperimenterMembershipGroup
 *
 */
::jace::proxy::java::lang::String getExperimenterMembershipGroup( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilamentType
 *
 */
::jace::proxy::java::lang::String getFilamentType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterFilterWheel
 *
 */
::jace::proxy::java::lang::String getFilterFilterWheel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterID
 *
 */
::jace::proxy::java::lang::String getFilterID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterLotNumber
 *
 */
::jace::proxy::java::lang::String getFilterLotNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterManufacturer
 *
 */
::jace::proxy::java::lang::String getFilterManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterModel
 *
 */
::jace::proxy::java::lang::String getFilterModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterType
 *
 */
::jace::proxy::java::lang::String getFilterType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterSetDichroic
 *
 */
::jace::proxy::java::lang::String getFilterSetDichroic( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterSetEmFilter
 *
 */
::jace::proxy::java::lang::String getFilterSetEmFilter( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterSetExFilter
 *
 */
::jace::proxy::java::lang::String getFilterSetExFilter( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterSetID
 *
 */
::jace::proxy::java::lang::String getFilterSetID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterSetLotNumber
 *
 */
::jace::proxy::java::lang::String getFilterSetLotNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterSetManufacturer
 *
 */
::jace::proxy::java::lang::String getFilterSetManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getFilterSetModel
 *
 */
::jace::proxy::java::lang::String getFilterSetModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getGroupID
 *
 */
::jace::proxy::java::lang::String getGroupID( ::jace::proxy::types::JInt p0 );

/**
 * getGroupName
 *
 */
::jace::proxy::java::lang::String getGroupName( ::jace::proxy::types::JInt p0 );

/**
 * getImageAcquiredPixels
 *
 */
::jace::proxy::java::lang::String getImageAcquiredPixels( ::jace::proxy::types::JInt p0 );

/**
 * getImageCreationDate
 *
 */
::jace::proxy::java::lang::String getImageCreationDate( ::jace::proxy::types::JInt p0 );

/**
 * getImageDefaultPixels
 *
 */
::jace::proxy::java::lang::String getImageDefaultPixels( ::jace::proxy::types::JInt p0 );

/**
 * getImageDescription
 *
 */
::jace::proxy::java::lang::String getImageDescription( ::jace::proxy::types::JInt p0 );

/**
 * getImageExperimentRef
 *
 */
::jace::proxy::java::lang::String getImageExperimentRef( ::jace::proxy::types::JInt p0 );

/**
 * getImageExperimenterRef
 *
 */
::jace::proxy::java::lang::String getImageExperimenterRef( ::jace::proxy::types::JInt p0 );

/**
 * getImageGroupRef
 *
 */
::jace::proxy::java::lang::String getImageGroupRef( ::jace::proxy::types::JInt p0 );

/**
 * getImageID
 *
 */
::jace::proxy::java::lang::String getImageID( ::jace::proxy::types::JInt p0 );

/**
 * getImageInstrumentRef
 *
 */
::jace::proxy::java::lang::String getImageInstrumentRef( ::jace::proxy::types::JInt p0 );

/**
 * getImageName
 *
 */
::jace::proxy::java::lang::String getImageName( ::jace::proxy::types::JInt p0 );

/**
 * getImagingEnvironmentAirPressure
 *
 */
::jace::proxy::java::lang::Double getImagingEnvironmentAirPressure( ::jace::proxy::types::JInt p0 );

/**
 * getImagingEnvironmentCO2Percent
 *
 */
::jace::proxy::java::lang::Double getImagingEnvironmentCO2Percent( ::jace::proxy::types::JInt p0 );

/**
 * getImagingEnvironmentHumidity
 *
 */
::jace::proxy::java::lang::Double getImagingEnvironmentHumidity( ::jace::proxy::types::JInt p0 );

/**
 * getImagingEnvironmentTemperature
 *
 */
::jace::proxy::java::lang::Double getImagingEnvironmentTemperature( ::jace::proxy::types::JInt p0 );

/**
 * getInstrumentID
 *
 */
::jace::proxy::java::lang::String getInstrumentID( ::jace::proxy::types::JInt p0 );

/**
 * getLaserFrequencyMultiplication
 *
 */
::jace::proxy::java::lang::Integer getLaserFrequencyMultiplication( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLaserLaserMedium
 *
 */
::jace::proxy::java::lang::String getLaserLaserMedium( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLaserPockelCell
 *
 */
::jace::proxy::java::lang::Boolean getLaserPockelCell( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLaserPulse
 *
 */
::jace::proxy::java::lang::String getLaserPulse( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLaserRepetitionRate
 *
 */
::jace::proxy::java::lang::Double getLaserRepetitionRate( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLaserTuneable
 *
 */
::jace::proxy::java::lang::Boolean getLaserTuneable( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLaserType
 *
 */
::jace::proxy::java::lang::String getLaserType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLaserWavelength
 *
 */
::jace::proxy::java::lang::Integer getLaserWavelength( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourceID
 *
 */
::jace::proxy::java::lang::String getLightSourceID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourceManufacturer
 *
 */
::jace::proxy::java::lang::String getLightSourceManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourceModel
 *
 */
::jace::proxy::java::lang::String getLightSourceModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourcePower
 *
 */
::jace::proxy::java::lang::Double getLightSourcePower( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourceSerialNumber
 *
 */
::jace::proxy::java::lang::String getLightSourceSerialNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourceRefAttenuation
 *
 */
::jace::proxy::java::lang::Double getLightSourceRefAttenuation( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLightSourceRefLightSource
 *
 */
::jace::proxy::java::lang::String getLightSourceRefLightSource( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLightSourceRefWavelength
 *
 */
::jace::proxy::java::lang::Integer getLightSourceRefWavelength( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLightSourceSettingsAttenuation
 *
 */
::jace::proxy::java::lang::Double getLightSourceSettingsAttenuation( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourceSettingsLightSource
 *
 */
::jace::proxy::java::lang::String getLightSourceSettingsLightSource( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLightSourceSettingsWavelength
 *
 */
::jace::proxy::java::lang::Integer getLightSourceSettingsWavelength( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLineID
 *
 */
::jace::proxy::java::lang::String getLineID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLineTransform
 *
 */
::jace::proxy::java::lang::String getLineTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLineX1
 *
 */
::jace::proxy::java::lang::String getLineX1( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLineX2
 *
 */
::jace::proxy::java::lang::String getLineX2( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLineY1
 *
 */
::jace::proxy::java::lang::String getLineY1( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLineY2
 *
 */
::jace::proxy::java::lang::String getLineY2( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getLogicalChannelContrastMethod
 *
 */
::jace::proxy::java::lang::String getLogicalChannelContrastMethod( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelDetector
 *
 */
::jace::proxy::java::lang::String getLogicalChannelDetector( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelEmWave
 *
 */
::jace::proxy::java::lang::Integer getLogicalChannelEmWave( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelExWave
 *
 */
::jace::proxy::java::lang::Integer getLogicalChannelExWave( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelFilterSet
 *
 */
::jace::proxy::java::lang::String getLogicalChannelFilterSet( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelFluor
 *
 */
::jace::proxy::java::lang::String getLogicalChannelFluor( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelID
 *
 */
::jace::proxy::java::lang::String getLogicalChannelID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelIlluminationType
 *
 */
::jace::proxy::java::lang::String getLogicalChannelIlluminationType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelLightSource
 *
 */
::jace::proxy::java::lang::String getLogicalChannelLightSource( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelMode
 *
 */
::jace::proxy::java::lang::String getLogicalChannelMode( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelName
 *
 */
::jace::proxy::java::lang::String getLogicalChannelName( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelNdFilter
 *
 */
::jace::proxy::java::lang::Double getLogicalChannelNdFilter( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelOTF
 *
 */
::jace::proxy::java::lang::String getLogicalChannelOTF( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelPhotometricInterpretation
 *
 */
::jace::proxy::java::lang::String getLogicalChannelPhotometricInterpretation( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelPinholeSize
 *
 */
::jace::proxy::java::lang::Double getLogicalChannelPinholeSize( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelPockelCellSetting
 *
 */
::jace::proxy::java::lang::Integer getLogicalChannelPockelCellSetting( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelSamplesPerPixel
 *
 */
::jace::proxy::java::lang::Integer getLogicalChannelSamplesPerPixel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelSecondaryEmissionFilter
 *
 */
::jace::proxy::java::lang::String getLogicalChannelSecondaryEmissionFilter( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getLogicalChannelSecondaryExcitationFilter
 *
 */
::jace::proxy::java::lang::String getLogicalChannelSecondaryExcitationFilter( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getMaskHeight
 *
 */
::jace::proxy::java::lang::String getMaskHeight( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskID
 *
 */
::jace::proxy::java::lang::String getMaskID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskTransform
 *
 */
::jace::proxy::java::lang::String getMaskTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskWidth
 *
 */
::jace::proxy::java::lang::String getMaskWidth( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskX
 *
 */
::jace::proxy::java::lang::String getMaskX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskY
 *
 */
::jace::proxy::java::lang::String getMaskY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskPixelsBigEndian
 *
 */
::jace::proxy::java::lang::Boolean getMaskPixelsBigEndian( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskPixelsBinData
 *
 */
::jace::JArray< ::jace::proxy::types::JByte > getMaskPixelsBinData( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskPixelsExtendedPixelType
 *
 */
::jace::proxy::java::lang::String getMaskPixelsExtendedPixelType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskPixelsID
 *
 */
::jace::proxy::java::lang::String getMaskPixelsID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskPixelsSizeX
 *
 */
::jace::proxy::java::lang::Integer getMaskPixelsSizeX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMaskPixelsSizeY
 *
 */
::jace::proxy::java::lang::Integer getMaskPixelsSizeY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getMicrobeamManipulationExperimenterRef
 *
 */
::jace::proxy::java::lang::String getMicrobeamManipulationExperimenterRef( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getMicrobeamManipulationID
 *
 */
::jace::proxy::java::lang::String getMicrobeamManipulationID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getMicrobeamManipulationType
 *
 */
::jace::proxy::java::lang::String getMicrobeamManipulationType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getMicrobeamManipulationRefID
 *
 */
::jace::proxy::java::lang::String getMicrobeamManipulationRefID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getMicroscopeID
 *
 */
::jace::proxy::java::lang::String getMicroscopeID( ::jace::proxy::types::JInt p0 );

/**
 * getMicroscopeManufacturer
 *
 */
::jace::proxy::java::lang::String getMicroscopeManufacturer( ::jace::proxy::types::JInt p0 );

/**
 * getMicroscopeModel
 *
 */
::jace::proxy::java::lang::String getMicroscopeModel( ::jace::proxy::types::JInt p0 );

/**
 * getMicroscopeSerialNumber
 *
 */
::jace::proxy::java::lang::String getMicroscopeSerialNumber( ::jace::proxy::types::JInt p0 );

/**
 * getMicroscopeType
 *
 */
::jace::proxy::java::lang::String getMicroscopeType( ::jace::proxy::types::JInt p0 );

/**
 * getOTFBinaryFile
 *
 */
::jace::proxy::java::lang::String getOTFBinaryFile( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getOTFID
 *
 */
::jace::proxy::java::lang::String getOTFID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getOTFObjective
 *
 */
::jace::proxy::java::lang::String getOTFObjective( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getOTFOpticalAxisAveraged
 *
 */
::jace::proxy::java::lang::Boolean getOTFOpticalAxisAveraged( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getOTFPixelType
 *
 */
::jace::proxy::java::lang::String getOTFPixelType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getOTFSizeX
 *
 */
::jace::proxy::java::lang::Integer getOTFSizeX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getOTFSizeY
 *
 */
::jace::proxy::java::lang::Integer getOTFSizeY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveCalibratedMagnification
 *
 */
::jace::proxy::java::lang::Double getObjectiveCalibratedMagnification( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveCorrection
 *
 */
::jace::proxy::java::lang::String getObjectiveCorrection( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveID
 *
 */
::jace::proxy::java::lang::String getObjectiveID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveImmersion
 *
 */
::jace::proxy::java::lang::String getObjectiveImmersion( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveIris
 *
 */
::jace::proxy::java::lang::Boolean getObjectiveIris( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveLensNA
 *
 */
::jace::proxy::java::lang::Double getObjectiveLensNA( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveManufacturer
 *
 */
::jace::proxy::java::lang::String getObjectiveManufacturer( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveModel
 *
 */
::jace::proxy::java::lang::String getObjectiveModel( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveNominalMagnification
 *
 */
::jace::proxy::java::lang::Integer getObjectiveNominalMagnification( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveSerialNumber
 *
 */
::jace::proxy::java::lang::String getObjectiveSerialNumber( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveWorkingDistance
 *
 */
::jace::proxy::java::lang::Double getObjectiveWorkingDistance( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getObjectiveSettingsCorrectionCollar
 *
 */
::jace::proxy::java::lang::Double getObjectiveSettingsCorrectionCollar( ::jace::proxy::types::JInt p0 );

/**
 * getObjectiveSettingsMedium
 *
 */
::jace::proxy::java::lang::String getObjectiveSettingsMedium( ::jace::proxy::types::JInt p0 );

/**
 * getObjectiveSettingsObjective
 *
 */
::jace::proxy::java::lang::String getObjectiveSettingsObjective( ::jace::proxy::types::JInt p0 );

/**
 * getObjectiveSettingsRefractiveIndex
 *
 */
::jace::proxy::java::lang::Double getObjectiveSettingsRefractiveIndex( ::jace::proxy::types::JInt p0 );

/**
 * getPathD
 *
 */
::jace::proxy::java::lang::String getPathD( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPathID
 *
 */
::jace::proxy::java::lang::String getPathID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPixelsBigEndian
 *
 */
::jace::proxy::java::lang::Boolean getPixelsBigEndian( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsDimensionOrder
 *
 */
::jace::proxy::java::lang::String getPixelsDimensionOrder( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsID
 *
 */
::jace::proxy::java::lang::String getPixelsID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsPixelType
 *
 */
::jace::proxy::java::lang::String getPixelsPixelType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsSizeC
 *
 */
::jace::proxy::java::lang::Integer getPixelsSizeC( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsSizeT
 *
 */
::jace::proxy::java::lang::Integer getPixelsSizeT( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsSizeX
 *
 */
::jace::proxy::java::lang::Integer getPixelsSizeX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsSizeY
 *
 */
::jace::proxy::java::lang::Integer getPixelsSizeY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPixelsSizeZ
 *
 */
::jace::proxy::java::lang::Integer getPixelsSizeZ( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPlaneHashSHA1
 *
 */
::jace::proxy::java::lang::String getPlaneHashSHA1( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPlaneID
 *
 */
::jace::proxy::java::lang::String getPlaneID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPlaneTheC
 *
 */
::jace::proxy::java::lang::Integer getPlaneTheC( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPlaneTheT
 *
 */
::jace::proxy::java::lang::Integer getPlaneTheT( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPlaneTheZ
 *
 */
::jace::proxy::java::lang::Integer getPlaneTheZ( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPlaneTimingDeltaT
 *
 */
::jace::proxy::java::lang::Double getPlaneTimingDeltaT( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPlaneTimingExposureTime
 *
 */
::jace::proxy::java::lang::Double getPlaneTimingExposureTime( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPlateColumnNamingConvention
 *
 */
::jace::proxy::java::lang::String getPlateColumnNamingConvention( ::jace::proxy::types::JInt p0 );

/**
 * getPlateDescription
 *
 */
::jace::proxy::java::lang::String getPlateDescription( ::jace::proxy::types::JInt p0 );

/**
 * getPlateExternalIdentifier
 *
 */
::jace::proxy::java::lang::String getPlateExternalIdentifier( ::jace::proxy::types::JInt p0 );

/**
 * getPlateID
 *
 */
::jace::proxy::java::lang::String getPlateID( ::jace::proxy::types::JInt p0 );

/**
 * getPlateName
 *
 */
::jace::proxy::java::lang::String getPlateName( ::jace::proxy::types::JInt p0 );

/**
 * getPlateRowNamingConvention
 *
 */
::jace::proxy::java::lang::String getPlateRowNamingConvention( ::jace::proxy::types::JInt p0 );

/**
 * getPlateStatus
 *
 */
::jace::proxy::java::lang::String getPlateStatus( ::jace::proxy::types::JInt p0 );

/**
 * getPlateWellOriginX
 *
 */
::jace::proxy::java::lang::Double getPlateWellOriginX( ::jace::proxy::types::JInt p0 );

/**
 * getPlateWellOriginY
 *
 */
::jace::proxy::java::lang::Double getPlateWellOriginY( ::jace::proxy::types::JInt p0 );

/**
 * getPlateRefID
 *
 */
::jace::proxy::java::lang::String getPlateRefID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPlateRefSample
 *
 */
::jace::proxy::java::lang::Integer getPlateRefSample( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPlateRefWell
 *
 */
::jace::proxy::java::lang::String getPlateRefWell( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPointCx
 *
 */
::jace::proxy::java::lang::String getPointCx( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPointCy
 *
 */
::jace::proxy::java::lang::String getPointCy( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPointID
 *
 */
::jace::proxy::java::lang::String getPointID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPointR
 *
 */
::jace::proxy::java::lang::String getPointR( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPointTransform
 *
 */
::jace::proxy::java::lang::String getPointTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPolygonID
 *
 */
::jace::proxy::java::lang::String getPolygonID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPolygonPoints
 *
 */
::jace::proxy::java::lang::String getPolygonPoints( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPolygonTransform
 *
 */
::jace::proxy::java::lang::String getPolygonTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPolylineID
 *
 */
::jace::proxy::java::lang::String getPolylineID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPolylinePoints
 *
 */
::jace::proxy::java::lang::String getPolylinePoints( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getPolylineTransform
 *
 */
::jace::proxy::java::lang::String getPolylineTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getProjectDescription
 *
 */
::jace::proxy::java::lang::String getProjectDescription( ::jace::proxy::types::JInt p0 );

/**
 * getProjectExperimenterRef
 *
 */
::jace::proxy::java::lang::String getProjectExperimenterRef( ::jace::proxy::types::JInt p0 );

/**
 * getProjectGroupRef
 *
 */
::jace::proxy::java::lang::String getProjectGroupRef( ::jace::proxy::types::JInt p0 );

/**
 * getProjectID
 *
 */
::jace::proxy::java::lang::String getProjectID( ::jace::proxy::types::JInt p0 );

/**
 * getProjectName
 *
 */
::jace::proxy::java::lang::String getProjectName( ::jace::proxy::types::JInt p0 );

/**
 * getProjectRefID
 *
 */
::jace::proxy::java::lang::String getProjectRefID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getPumpLightSource
 *
 */
::jace::proxy::java::lang::String getPumpLightSource( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIID
 *
 */
::jace::proxy::java::lang::String getROIID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIT0
 *
 */
::jace::proxy::java::lang::Integer getROIT0( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIT1
 *
 */
::jace::proxy::java::lang::Integer getROIT1( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIX0
 *
 */
::jace::proxy::java::lang::Integer getROIX0( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIX1
 *
 */
::jace::proxy::java::lang::Integer getROIX1( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIY0
 *
 */
::jace::proxy::java::lang::Integer getROIY0( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIY1
 *
 */
::jace::proxy::java::lang::Integer getROIY1( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIZ0
 *
 */
::jace::proxy::java::lang::Integer getROIZ0( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIZ1
 *
 */
::jace::proxy::java::lang::Integer getROIZ1( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getROIRefID
 *
 */
::jace::proxy::java::lang::String getROIRefID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getReagentDescription
 *
 */
::jace::proxy::java::lang::String getReagentDescription( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getReagentID
 *
 */
::jace::proxy::java::lang::String getReagentID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getReagentName
 *
 */
::jace::proxy::java::lang::String getReagentName( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getReagentReagentIdentifier
 *
 */
::jace::proxy::java::lang::String getReagentReagentIdentifier( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getRectHeight
 *
 */
::jace::proxy::java::lang::String getRectHeight( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRectID
 *
 */
::jace::proxy::java::lang::String getRectID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRectTransform
 *
 */
::jace::proxy::java::lang::String getRectTransform( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRectWidth
 *
 */
::jace::proxy::java::lang::String getRectWidth( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRectX
 *
 */
::jace::proxy::java::lang::String getRectX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRectY
 *
 */
::jace::proxy::java::lang::String getRectY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRegionID
 *
 */
::jace::proxy::java::lang::String getRegionID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getRegionName
 *
 */
::jace::proxy::java::lang::String getRegionName( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getRegionTag
 *
 */
::jace::proxy::java::lang::String getRegionTag( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getRoiLinkDirection
 *
 */
::jace::proxy::java::lang::String getRoiLinkDirection( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRoiLinkName
 *
 */
::jace::proxy::java::lang::String getRoiLinkName( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getRoiLinkRef
 *
 */
::jace::proxy::java::lang::String getRoiLinkRef( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getScreenDescription
 *
 */
::jace::proxy::java::lang::String getScreenDescription( ::jace::proxy::types::JInt p0 );

/**
 * getScreenExtern
 *
 */
::jace::proxy::java::lang::String getScreenExtern( ::jace::proxy::types::JInt p0 );

/**
 * getScreenID
 *
 */
::jace::proxy::java::lang::String getScreenID( ::jace::proxy::types::JInt p0 );

/**
 * getScreenName
 *
 */
::jace::proxy::java::lang::String getScreenName( ::jace::proxy::types::JInt p0 );

/**
 * getScreenProtocolDescription
 *
 */
::jace::proxy::java::lang::String getScreenProtocolDescription( ::jace::proxy::types::JInt p0 );

/**
 * getScreenProtocolIdentifier
 *
 */
::jace::proxy::java::lang::String getScreenProtocolIdentifier( ::jace::proxy::types::JInt p0 );

/**
 * getScreenReagentSetDescription
 *
 */
::jace::proxy::java::lang::String getScreenReagentSetDescription( ::jace::proxy::types::JInt p0 );

/**
 * getScreenReagentSetIdentifier
 *
 */
::jace::proxy::java::lang::String getScreenReagentSetIdentifier( ::jace::proxy::types::JInt p0 );

/**
 * getScreenType
 *
 */
::jace::proxy::java::lang::String getScreenType( ::jace::proxy::types::JInt p0 );

/**
 * getScreenAcquisitionEndTime
 *
 */
::jace::proxy::java::lang::String getScreenAcquisitionEndTime( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getScreenAcquisitionID
 *
 */
::jace::proxy::java::lang::String getScreenAcquisitionID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getScreenAcquisitionStartTime
 *
 */
::jace::proxy::java::lang::String getScreenAcquisitionStartTime( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getScreenRefID
 *
 */
::jace::proxy::java::lang::String getScreenRefID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getShapeBaselineShift
 *
 */
::jace::proxy::java::lang::String getShapeBaselineShift( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeDirection
 *
 */
::jace::proxy::java::lang::String getShapeDirection( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFillColor
 *
 */
::jace::proxy::java::lang::String getShapeFillColor( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFillOpacity
 *
 */
::jace::proxy::java::lang::String getShapeFillOpacity( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFillRule
 *
 */
::jace::proxy::java::lang::String getShapeFillRule( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFontFamily
 *
 */
::jace::proxy::java::lang::String getShapeFontFamily( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFontSize
 *
 */
::jace::proxy::java::lang::Integer getShapeFontSize( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFontStretch
 *
 */
::jace::proxy::java::lang::String getShapeFontStretch( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFontStyle
 *
 */
::jace::proxy::java::lang::String getShapeFontStyle( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFontVariant
 *
 */
::jace::proxy::java::lang::String getShapeFontVariant( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeFontWeight
 *
 */
::jace::proxy::java::lang::String getShapeFontWeight( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeG
 *
 */
::jace::proxy::java::lang::String getShapeG( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeGlyphOrientationVertical
 *
 */
::jace::proxy::java::lang::Integer getShapeGlyphOrientationVertical( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeID
 *
 */
::jace::proxy::java::lang::String getShapeID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeLocked
 *
 */
::jace::proxy::java::lang::Boolean getShapeLocked( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeAttribute
 *
 */
::jace::proxy::java::lang::String getShapeStrokeAttribute( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeColor
 *
 */
::jace::proxy::java::lang::String getShapeStrokeColor( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeDashArray
 *
 */
::jace::proxy::java::lang::String getShapeStrokeDashArray( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeLineCap
 *
 */
::jace::proxy::java::lang::String getShapeStrokeLineCap( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeLineJoin
 *
 */
::jace::proxy::java::lang::String getShapeStrokeLineJoin( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeMiterLimit
 *
 */
::jace::proxy::java::lang::Integer getShapeStrokeMiterLimit( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeOpacity
 *
 */
::jace::proxy::java::lang::Double getShapeStrokeOpacity( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeStrokeWidth
 *
 */
::jace::proxy::java::lang::Integer getShapeStrokeWidth( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeText
 *
 */
::jace::proxy::java::lang::String getShapeText( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeTextAnchor
 *
 */
::jace::proxy::java::lang::String getShapeTextAnchor( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeTextDecoration
 *
 */
::jace::proxy::java::lang::String getShapeTextDecoration( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeTextFill
 *
 */
::jace::proxy::java::lang::String getShapeTextFill( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeTextStroke
 *
 */
::jace::proxy::java::lang::String getShapeTextStroke( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeTheT
 *
 */
::jace::proxy::java::lang::Integer getShapeTheT( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeTheZ
 *
 */
::jace::proxy::java::lang::Integer getShapeTheZ( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeVectorEffect
 *
 */
::jace::proxy::java::lang::String getShapeVectorEffect( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeVisibility
 *
 */
::jace::proxy::java::lang::Boolean getShapeVisibility( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getShapeWritingMode
 *
 */
::jace::proxy::java::lang::String getShapeWritingMode( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getStageLabelName
 *
 */
::jace::proxy::java::lang::String getStageLabelName( ::jace::proxy::types::JInt p0 );

/**
 * getStageLabelX
 *
 */
::jace::proxy::java::lang::Double getStageLabelX( ::jace::proxy::types::JInt p0 );

/**
 * getStageLabelY
 *
 */
::jace::proxy::java::lang::Double getStageLabelY( ::jace::proxy::types::JInt p0 );

/**
 * getStageLabelZ
 *
 */
::jace::proxy::java::lang::Double getStageLabelZ( ::jace::proxy::types::JInt p0 );

/**
 * getStagePositionPositionX
 *
 */
::jace::proxy::java::lang::Double getStagePositionPositionX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getStagePositionPositionY
 *
 */
::jace::proxy::java::lang::Double getStagePositionPositionY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getStagePositionPositionZ
 *
 */
::jace::proxy::java::lang::Double getStagePositionPositionZ( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getThumbnailHref
 *
 */
::jace::proxy::java::lang::String getThumbnailHref( ::jace::proxy::types::JInt p0 );

/**
 * getThumbnailID
 *
 */
::jace::proxy::java::lang::String getThumbnailID( ::jace::proxy::types::JInt p0 );

/**
 * getThumbnailMIMEtype
 *
 */
::jace::proxy::java::lang::String getThumbnailMIMEtype( ::jace::proxy::types::JInt p0 );

/**
 * getTiffDataFileName
 *
 */
::jace::proxy::java::lang::String getTiffDataFileName( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getTiffDataFirstC
 *
 */
::jace::proxy::java::lang::Integer getTiffDataFirstC( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getTiffDataFirstT
 *
 */
::jace::proxy::java::lang::Integer getTiffDataFirstT( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getTiffDataFirstZ
 *
 */
::jace::proxy::java::lang::Integer getTiffDataFirstZ( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getTiffDataIFD
 *
 */
::jace::proxy::java::lang::Integer getTiffDataIFD( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getTiffDataNumPlanes
 *
 */
::jace::proxy::java::lang::Integer getTiffDataNumPlanes( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getTiffDataUUID
 *
 */
::jace::proxy::java::lang::String getTiffDataUUID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getTransmittanceRangeCutIn
 *
 */
::jace::proxy::java::lang::Integer getTransmittanceRangeCutIn( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getTransmittanceRangeCutInTolerance
 *
 */
::jace::proxy::java::lang::Integer getTransmittanceRangeCutInTolerance( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getTransmittanceRangeCutOut
 *
 */
::jace::proxy::java::lang::Integer getTransmittanceRangeCutOut( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getTransmittanceRangeCutOutTolerance
 *
 */
::jace::proxy::java::lang::Integer getTransmittanceRangeCutOutTolerance( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getTransmittanceRangeTransmittance
 *
 */
::jace::proxy::java::lang::Integer getTransmittanceRangeTransmittance( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellColumn
 *
 */
::jace::proxy::java::lang::Integer getWellColumn( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellExternalDescription
 *
 */
::jace::proxy::java::lang::String getWellExternalDescription( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellExternalIdentifier
 *
 */
::jace::proxy::java::lang::String getWellExternalIdentifier( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellID
 *
 */
::jace::proxy::java::lang::String getWellID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellReagent
 *
 */
::jace::proxy::java::lang::String getWellReagent( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellRow
 *
 */
::jace::proxy::java::lang::Integer getWellRow( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellType
 *
 */
::jace::proxy::java::lang::String getWellType( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1 );

/**
 * getWellSampleID
 *
 */
::jace::proxy::java::lang::String getWellSampleID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getWellSampleImageRef
 *
 */
::jace::proxy::java::lang::String getWellSampleImageRef( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getWellSampleIndex
 *
 */
::jace::proxy::java::lang::Integer getWellSampleIndex( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getWellSamplePosX
 *
 */
::jace::proxy::java::lang::Double getWellSamplePosX( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getWellSamplePosY
 *
 */
::jace::proxy::java::lang::Double getWellSamplePosY( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getWellSampleTimepoint
 *
 */
::jace::proxy::java::lang::Integer getWellSampleTimepoint( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * getWellSampleRefID
 *
 */
::jace::proxy::java::lang::String getWellSampleRefID( ::jace::proxy::types::JInt p0, ::jace::proxy::types::JInt p1, ::jace::proxy::types::JInt p2 );

/**
 * The following methods are required to integrate this class
 * with the Jace framework.
 *
 */
/**
 * Special no arg constructor for interface virtual inheritance
 *
 */
MetadataRetrieve();
MetadataRetrieve( jvalue value );
MetadataRetrieve( jobject object );
MetadataRetrieve( const MetadataRetrieve& object );
MetadataRetrieve( const NoOp& noOp );
virtual const JClass& getJavaJniClass() const throw ( ::jace::JNIException );
static const JClass& staticGetJavaJniClass() throw ( ::jace::JNIException );
};

END_NAMESPACE_5( jace, proxy, loci, formats, meta )

BEGIN_NAMESPACE( jace )

#ifndef PUT_TSDS_IN_HEADER
  template <> ElementProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::ElementProxy( jarray array, jvalue element, int index );
  template <> ElementProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::ElementProxy( const jace::ElementProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>& proxy );
#else
  template <> inline ElementProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::ElementProxy( jarray array, jvalue element, int index ) : 
    ::jace::proxy::loci::formats::meta::MetadataRetrieve( element ), Object( NO_OP ), mIndex( index )
  {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, array ) );
  }
  template <> inline ElementProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::ElementProxy( const jace::ElementProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>& proxy ) : 
    ::jace::proxy::loci::formats::meta::MetadataRetrieve( proxy.getJavaJniObject() ), Object( NO_OP ), mIndex( proxy.mIndex )
  {
    JNIEnv* env = ::jace::helper::attach();
    parent = static_cast<jarray>( ::jace::helper::newGlobalRef( env, proxy.parent ) );
  }
#endif

#ifndef PUT_TSDS_IN_HEADER
  template <> JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ );
  template <> JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ );
  template <> JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>& object );
#else
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::JFieldProxy( jfieldID fieldID_, jvalue value, jobject parent_ ) : 
    ::jace::proxy::loci::formats::meta::MetadataRetrieve( value ), Object( NO_OP ), fieldID( fieldID_ )
  {
    JNIEnv* env = ::jace::helper::attach();

    if ( parent_ )
      parent = ::jace::helper::newGlobalRef( env, parent_ );
    else
      parent = parent_;

    parentClass = 0;
  }
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::JFieldProxy( jfieldID fieldID_, jvalue value, jclass parentClass_ ) : 
    ::jace::proxy::loci::formats::meta::MetadataRetrieve( value ), Object( NO_OP ), fieldID( fieldID_ )
  {
    JNIEnv* env = ::jace::helper::attach();

    parent = 0;
    parentClass = static_cast<jclass>( ::jace::helper::newGlobalRef( env, parentClass_ ) );
  }
  template <> inline JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>::JFieldProxy( const ::jace::JFieldProxy< ::jace::proxy::loci::formats::meta::MetadataRetrieve>& object ) : 
    ::jace::proxy::loci::formats::meta::MetadataRetrieve( object.getJavaJniValue() ), Object( NO_OP )
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

#endif // #ifndef JACE_PROXY_LOCI_FORMATS_META_METADATARETRIEVE_H

