/*
  This file is part of TMD CDW Unit Cell Generator

  TMD CDW Unit Cell Generatort is free software: you can redistribute it
  and/or modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either version
  3 of the License, or (at your option) any later version.

  TMD CDW Unit Cell Generator is distributed in the hope that it will be
  useful, but WITHOUT ANY WARRANTY; without even the implied warranty
  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with TMD CDW Unit Cell Generator.  If not, see
  <http://www.gnu.org/licenses/>.
*/
/* ************************************************************
   fractional.c
   code written by David Miller
   mill2723 at msu dot edu

   Generates the fractional coordinates for a TMD trilayer
****************************************************************/
#include "header.h"

void generateFracCoord(double frac_loc[][3], unsigned num, int supercell[2][2])
{
  unsigned xmax, ymax, count, ii, jj, kk;
  double min_angle;
  
  xmax = (unsigned)(abs(supercell[0][0]) + abs(supercell[1][0]));
  ymax = (unsigned)(abs(supercell[0][1]) + abs(supercell[1][1]));

  count = 0;
  min_angle = getLatticeVectorAngle(supercell[0][0], supercell[0][1]);

  for (ii = 0; ii < xmax; ii++)
    {
      for (jj = 0; jj < ymax; jj++)
	{
	  if (count >= num) { break; }	  
	  
	  if ( (ii == 0) && (jj == 0) )
	    {
	      for (kk = 0; kk < 3; kk++)
		{
		  frac_loc[0][kk] = 0;
		}
	      count++;
	    }
	  else
	    {
	      if( ( getLatticeVectorAngle((int)(ii),(int)(jj)) - min_angle ) > -EPS )
		{
		  frac_loc[count][0] = ii; 
		  frac_loc[count][1] = jj; 
		  frac_loc[count][2] = 0;
  		  count++;
		}
	    }	  
	}
    }
  if (count < num)
    {
      printf("Not enough coordinates made...\n");
      return;
    }
}