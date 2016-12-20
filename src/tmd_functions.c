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
/* ********************************************************************
   tmd_arr_functions.c
   code written by David Miller
   mill2723 at msu dot edu

   Additional functions to generate the coordinates for TMD trilayers.

***********************************************************************/

#include "header.h"

double dtor(double deg)
{
  return deg*PI/180.0;
}

double getLatticeVectorAngle(int n, int m)
{
  /* angle = arccos(a*b)/|a|*|b| */
  return acos((n - 0.5*m)/(sqrt(n*n + m*m - n*m*1.0))); 
}

int atob(char a)
{
  if ( (a == 't') || (a == 'T') ) return 1;
  else if ( (a == 'f') || (a == 'F') ) return 0;
  else exit(-1);
}