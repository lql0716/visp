/****************************************************************************
 *
 * $Id$
 *
 * Copyright (C) 1998-2010 Inria. All rights reserved.
 *
 * This software was developed at:
 * IRISA/INRIA Rennes
 * Projet Lagadic
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * http://www.irisa.fr/lagadic
 *
 * This file is part of the ViSP toolkit
 *
 * This file may be distributed under the terms of the Q Public License
 * as defined by Trolltech AS of Norway and appearing in the file
 * LICENSE included in the packaging of this file.
 *
 * Licensees holding valid ViSP Professional Edition licenses may
 * use this file in accordance with the ViSP Commercial License
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Contact visp@irisa.fr if any conditions of this licensing are
 * not clear to you.
 *
 * Description:
 * Median Absolute Deviation (MAD), MPDE, Mean shift kernel density estimation.
 *
 * Authors:
 * Andrew Comport
 *
 *****************************************************************************/

/*!
 \file vpScale.h
*/

// =========================================================
/*!
 * \brief Contains various estimators for scale.
 * \n Methods : Median Absolute Deviation (MAD),
 * 							MPDE, Mean shift kernel density estimation.
 * \author Andrew Comport
 * \date 24/10/03
 */
// ==========================================================


#ifndef VPSCALE_HH
#define VPSCALE_HH

#define EPANECHNIKOV 0

#include <math.h>
#include <visp/vpConfig.h>
#include <visp/vpColVector.h>

/*!
  \class vpScale
  \ingroup Robust

  \brief Contains different methods for estimating the robust scale of
  an error distribution.

  Methods of Median Absolute Deviation and Density Gradient estimation
  using the Mean Shift method.

  \author Andrew Comport
  \date 24/10/03
 */
class VISP_EXPORT vpScale
{

private:
  double bandwidth;
  int dimension;
  int kernel_type;

public:

  //! Constructor
  vpScale();
  vpScale(double, int, int);
  //! Destructor
  virtual ~vpScale(void);

  double MeanShift(vpColVector &error);
  double KernelDensity(vpColVector &error, int position);
  double KernelDensityGradient(vpColVector &error, int position);

  double KernelDensity_EPANECHNIKOV(vpColVector &X);
  double KernelDensityGradient_EPANECHNIKOV(double X, int n);

};

#endif