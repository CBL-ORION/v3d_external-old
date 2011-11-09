/* gaussianfilter.h
 * 2009-06-03: create this program by Yang Yu
 * 2009-08-14: change into plugin by Yang Yu
 */


#ifndef __GAUSSIANFILTER_H__
#define __GAUSSIANFILTER_H__

//     3D ANISOTROPIC GAUSSIAN FILTERING
//
//     pImage  - input & output
//     N       - width of the image
//     M       - height of the image
//     P       - slice of the image
//     Wx      - window size along x
//     Wy      - window size along y
//     Wz      - window size along z
//
//int GaussianFilter(float *pImage, V3DLONG N, V3DLONG M, V3DLONG P, unsigned int Wx, unsigned int Wy, unsigned int Wz);
//e.g. if(!GaussianFilter(pImg, sz[0], sz[1], sz[2], sigmax, sigmay, sigmaz))
//			cout<<"err"<<endl;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <v3d_interface.h>

class GaussianFilterPlugin : public QObject, public V3DSingleImageInterface2_1
{
    Q_OBJECT
    Q_INTERFACES(V3DSingleImageInterface2_1)

public:
    QStringList menulist() const;
    void processImage(const QString &arg, Image4DSimple *p4DImage, QWidget *parent);
    float getPluginVersion() const {return 1.1f;}
};

#endif



