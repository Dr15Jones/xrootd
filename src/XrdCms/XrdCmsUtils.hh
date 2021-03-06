#ifndef __CMS_UTILS__H
#define __CMS_UTILS__H
/******************************************************************************/
/*                                                                            */
/*                        X r d C m s U t i l s . h h                         */
/*                                                                            */
/* (c) 2013 by the Board of Trustees of the Leland Stanford, Jr., University  */
/*                            All Rights Reserved                             */
/*   Produced by Andrew Hanushevsky for Stanford University under contract    */
/*              DE-AC02-76-SFO0515 with the Department of Energy              */
/*                                                                            */
/* This file is part of the XRootD software suite.                            */
/*                                                                            */
/* XRootD is free software: you can redistribute it and/or modify it under    */
/* the terms of the GNU Lesser General Public License as published by the     */
/* Free Software Foundation, either version 3 of the License, or (at your     */
/* option) any later version.                                                 */
/*                                                                            */
/* XRootD is distributed in the hope that it will be useful, but WITHOUT      */
/* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or      */
/* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public       */
/* License for more details.                                                  */
/*                                                                            */
/* You should have received a copy of the GNU Lesser General Public License   */
/* along with XRootD in a file called COPYING.LESSER (LGPL license) and file  */
/* COPYING (GPL license).  If not, see <http://www.gnu.org/licenses/>.        */
/*                                                                            */
/* The copyright holder's institutional names and contributor's names may not */
/* be used to endorse or promote products derived from this software without  */
/* specific prior written permission of the institution or contributor.       */
/******************************************************************************/

class XrdOucStream;
class XrdOucTList;
class XrdSysError;

class XrdCmsUtils
{
public:

//------------------------------------------------------------------------------
//! Obtain and merge a new manager list with an existing list.
//!
//! @param  eDest    Pointer to the error message object to route messages.
//! @param  oldMans  A pointer to the existing list of managers, if any. If
//!                  oldMans is nil, then the hSpec/hPort/sPort is processed
//!                  but no list is returned.
//! @param  hSpec    the host specification suitable for XrdNetAddr.Set(). The
//!                  hSpec may end with a '+' indicating that all addresses
//!                  assigned to hSpec be considered for inclusion.
//! @param  hPort    the port specification which can be a text number or a
//!                  service name (e.g. xroot).
//!         hWant    Maximum number of list entries wanted. If hWant is greater
//!                  that eight it is set eigth.
//! @param  sPort    If not nil, the *sPort will be set to the numeric hPort if
//!                  the IP address in one of the entries matches the host
//!                  address. Otherwise, the value is unchanged.
//!
//! @return Success: True and if oldMans is supplied, the additional entries
//!                  that do not duplicate existing entries are added to the
//!                  front. Note:
//!                  *oldMans->val  is the port number.
//!                  *oldMans->text is the host name.
//!                  The list of objects belongs to the caller.
//!         Failure: False. Any existing list is not modified. However, sPort
//!                  may be updated, if correct, even when false is returned.
//------------------------------------------------------------------------------
static
bool     ParseMan(XrdSysError *eDest, XrdOucTList **oldMans,
                  char  *hSpec, char *hPort, int *sPort=0);

//------------------------------------------------------------------------------
//! Obtain the port for a manager specification
//!
//! @param  eDest    Pointer to the error message object to route messages.
//! @param  oldMans  The configuration file stream.
//! @param  hSpec    The initial manager specification which may or may not
//!                  have the port number in it.
//!
//! @return Success: Pointer to a copy of the port specification. The caller
//!                  is responsible for freeing it using free().
//!         Failure: A nil pointer. An error message has already been issued.
//------------------------------------------------------------------------------
static
char *ParseManPort(XrdSysError *eDest, XrdOucStream &CFile, char *hSpec);

         XrdCmsUtils() {}
        ~XrdCmsUtils();

private:
};
#endif
