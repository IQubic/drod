// $Id: PendingBuildEffect.h 8102 2007-08-15 14:55:40Z trick $

/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Deadly Rooms of Death.
 *
 * The Initial Developer of the Original Code is
 * Caravel Software.
 * Portions created by the Initial Developer are Copyright (C) 2002, 2005, 2007
 * Caravel Software. All Rights Reserved.
 *
 * Contributor(s): Mike Rimer (mrimer)
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef PENDINGBUILDEFFECT_H
#define PENDINGBUILDEFFECT_H

#include "DrodEffect.h"

//*****************************************************************************
class CRoomWidget;
class CPendingBuildEffect : public CEffect
{
public:
	CPendingBuildEffect(CWidget *pSetWidget, const UINT wTileImageNo,
			const UINT wX, const UINT wY, const bool bModOpacity);

	virtual bool Draw(SDL_Surface* pDestSurface=NULL);

private:
	SDL_Rect OwnerRect;
	CRoomWidget *pRoomWidget;

	const UINT wX, wY;
	const UINT wTileImageNo;

	bool bModOpacity;
	static unsigned char nOpacity;
	static bool bRising;
};

#endif //...#ifndef PENDINGBUILDEFFECT_H
