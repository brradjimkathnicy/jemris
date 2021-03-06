/** @file ExternalGradPulse.h
 *  @brief Implementation of JEMRIS ExternalGradPulse
 */

/*
 *  JEMRIS Copyright (C) 
 *                        2006-2013  Tony Stoecker
 *                        2007-2013  Kaveh Vahedipour
 *                        2009-2013  Daniel Pflugfelder
 *                                  
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _EXTERNALGRADPULSE_H
#define _EXTERNALGRADPULSE_H

#include <cmath>
#include "GradPulse.h"

/**
 * @brief External gradient prototype.
 */

class ExternalGradPulse : public GradPulse {
  
 public:

    /**
     * @brief Default constructor
     */
    ExternalGradPulse               () : m_scale(1.) {};

    /**
     * @brief Copy constructor.
     */
    ExternalGradPulse               (const ExternalGradPulse&);

    /**
     * @brief Default destructor.
     */
    ~ExternalGradPulse              () {};

    /**
     * @see Prototype::Clone
     */
    inline ExternalGradPulse* Clone () const { return (new ExternalGradPulse(*this)); };

    /**
     * @brief Prepare the external gradient pulse.
     *
     * @param mode Sets the preparation mode, one of enum PrepareMode {PREP_INIT,PREP_VERBOSE,PREP_UPDATE}.
     */
    virtual bool     Prepare      (const PrepareMode mode);

    /**
     * @see GradPulse::GetGradient
     */
    virtual double   GetGradient  (double const time);

    /**
     * @see Pulse::SetTPOIs
     */
    virtual void     SetTPOIs();


 protected:

    /**
     * @brief Get information on this external gradient.
     *
     * @return Information for display.
     */
    string           GetInfo      ();

    string m_fname;                /**< @brief Filename containing the RF amps and phases  */
    double m_scale;                /**< @brief Scaling factor for the amps                 */
    string m_dpath;
    string m_dname;

    vector<double> m_times;       /**< @brief My sample time points                       */
    vector<double> m_magnitudes;  /**< @brief My corresponding amplitudes                 */

};

#endif /*EXTERNALGRADPULSE_*/
