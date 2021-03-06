// $Id$

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

#include "SplashEffect.h"
#include "TileImageConstants.h"

//********************************************************************************
CSplashEffect::CSplashEffect(
//Constructor.
//
//Params:
	CWidget *pSetWidget,    //(in)   Should be a room widget.
	const CCoord &SetCoord)    //(in)   Location
	: CAnimatedTileEffect(pSetWidget,SetCoord,500,TI_SPLASH1,true)
{
}

//********************************************************************************
bool CSplashEffect::Draw(SDL_Surface* pDestSurface)
//Draw the effect.
//
//Returns:
//True if effect should continue, or false if effect is done.
{
	const Uint32 dwElapsed = TimeElapsed();
	if (dwElapsed >= this->dwDuration) return false; //Effect is done.

	if (!pDestSurface) pDestSurface = GetDestSurface();

	//Draw animated splash.
	const float fPercent = dwElapsed / float(dwDuration);
	static const UINT NUM_FRAMES = 6;
	static const UINT FRAME[NUM_FRAMES] = {TI_SPLASH1, TI_SPLASH2, TI_SPLASH3,
		TI_SPLASH4, TI_SPLASH5, TI_SPLASH6};
	const UINT frame = UINT(fPercent * NUM_FRAMES);
	ASSERT(frame < NUM_FRAMES);

	//Effect fades as it progresses.
	const float fMultiplier = 255.0f / float(this->dwDuration);
	const Uint8 opacity = static_cast<Uint8>((this->dwDuration-dwElapsed) * fMultiplier);
	DrawTile(FRAME[frame], pDestSurface, opacity);

	//Continue effect.
	return true;
}
