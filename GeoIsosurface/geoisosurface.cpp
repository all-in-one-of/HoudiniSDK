/*
 * Copyright (c) 2016
 *	Side Effects Software Inc.  All rights reserved.
 *
 * Redistribution and use of Houdini Development Kit samples in source and
 * binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. The name of Side Effects Software may not be used to endorse or
 *    promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY SIDE EFFECTS SOFTWARE `AS IS' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO EVENT SHALL SIDE EFFECTS SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *----------------------------------------------------------------------------
 */

#include <GU/GU_Detail.h>
#include <UT/UT_Vector2.h>
#include <UT/UT_Vector3.h>
#include <UT/UT_Vector4.h>
#include <stddef.h>
#include "SDFunctions.h"


static float densityFunction(const UT_Vector3 &P, void *)
{
    // Return the signed distance to the unit sphere
//    return sdSPhere(P,0.4);
    //return opS(sdTriPrism(P,UT_Vector2(1.0f,0.9f)),sdSPhere(P,1.0));
//  return Intercect(Union(sdSPhere(P,1.0),sdCone(P,UT_Vector2(1.0f,0.9f))),
//                         Union(sdCone(P,UT_Vector2(1.0f,0.9f)),sdSPhere(P,1.0)));
//  //return udBox(P,UT_Vector3(1,1,1));
  //return sdPlane(P,UT_Vector4(0,1,0,1));
//  UT_Vector2 c(2.0f,0.5f);
//  c.normalize();
//  return sdCone(P,c);
    //return sdCappedCone(P,P);
   // return sdTorus(P,UT_Vector2(0.2f,0.05f));
  return sdCapsule(P,UT_Vector3(0.02,0.9,0.03),UT_Vector3(0.01,0.02,0.01),0.8);
}



int main()
{
    GU_Detail		gdp;
    UT_BoundingBox	bounds;

    // Evaluate the iso-surface inside this bounding box
    bounds.setBounds(-1, -1, -1, 1, 1, 1);

    // Create an iso-surface
    gdp.polyIsoSurface(densityFunction, NULL, bounds, 100, 100, 100);

    // Save to sphere.bgeo
    gdp.save("sphere.bgeo", NULL);
    return 0;
}
