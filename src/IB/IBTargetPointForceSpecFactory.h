// Filename: IBTargetPointForceSpecFactory.h
// Created on 21 Mar 2007 by Boyce Griffith
//
// Copyright (c) 2002-2010, Boyce Griffith
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of New York University nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef included_IBTargetPointForceSpecFactory
#define included_IBTargetPointForceSpecFactory

/////////////////////////////// INCLUDES /////////////////////////////////////

// IBTK INCLUDES
#include <ibtk/Streamable.h>
#include <ibtk/StreamableFactory.h>

// SAMRAI INCLUDES
#include <IntVector.h>
#include <tbox/AbstractStream.h>
#include <tbox/Pointer.h>

/////////////////////////////// CLASS DEFINITION /////////////////////////////

namespace IBAMR
{
/*!
 * \brief Class IBTargetPointForceSpecFactory is a factory class to rebuild
 * IBTargetPointForceSpec objects from SAMRAI::tbox::AbstractStream data
 * streams.
 */
class IBTargetPointForceSpecFactory
    : public IBTK::StreamableFactory
{
public:
    /*!
     * \brief Default constructor.
     */
    IBTargetPointForceSpecFactory();

    /*!
     * \brief Destructor.
     */
    ~IBTargetPointForceSpecFactory();

    /*!
     * \brief Return the unique identifier used to specify the
     * IBTK::StreamableFactory object used by the IBTK::StreamableManager to
     * extract IBTargetPointForceSpec objects from data streams.
     */
    int
    getStreamableClassID() const;

    /*!
     * \brief Set the unique identifier used to specify the
     * IBTK::StreamableFactory object used by the IBTK::StreamableManager to
     * extract IBTargetPointForceSpec objects from data streams.
     */
    void
    setStreamableClassID(
        const int class_id);

    /*!
     * \brief Build an IBTargetPointForceSpec object by unpacking data from the
     * data stream.
     */
    SAMRAI::tbox::Pointer<IBTK::Streamable>
    unpackStream(
        SAMRAI::tbox::AbstractStream& stream,
        const SAMRAI::hier::IntVector<NDIM>& offset);

private:
    /*!
     * \brief Copy constructor.
     *
     * \note This constructor is not implemented and should not be used.
     *
     * \param from The value to copy to this object.
     */
    IBTargetPointForceSpecFactory(
        const IBTargetPointForceSpecFactory& from);

    /*!
     * \brief Assignment operator.
     *
     * \note This operator is not implemented and should not be used.
     *
     * \param that The value to assign to this object.
     *
     * \return A reference to this object.
     */
    IBTargetPointForceSpecFactory&
    operator=(
        const IBTargetPointForceSpecFactory& that);

    /*
     * The class ID for this object type assigned by the
     * IBTK::StreamableManager.
     */
    static int s_class_id;
};
}// namespace IBAMR

/////////////////////////////// INLINE ///////////////////////////////////////

//#include <ibamr/IBTargetPointForceSpecFactory.I>

//////////////////////////////////////////////////////////////////////////////

#endif //#ifndef included_IBTargetPointForceSpecFactory
