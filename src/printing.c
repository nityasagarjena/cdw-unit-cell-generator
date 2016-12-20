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
   printing.c
   code written by David Miller
   mill2723 at msu dot edu

   Contains all functions for output including the VASP and xyz format
   as well as the help printed to terminal.

***********************************************************************/

#include "header.h"
void printXYZ(Location locM[], Location locX[], unsigned n)
{
  unsigned j;
  printf("%d\n",3*n);
  printf("c-cdw-TaS2 super cell SQRT(13)xSQRT(13)x1 (in angstroms)\n");
  
  for (j = 0; j < n; j++)
    {
      printf("Ta        %.4f        %.4f        %.4f\n",\
	     locM[j].x, locM[j].y,locM[j].z);
      printf("S        %.4f        %.4f        %.4f\n",\
	     locX[j].x, locX[j].y,locX[j].z);
      printf("S        %.4f        %.4f        %.4f\n",\
	     locX[j+n].x, locX[j+n].y,locX[j+n].z);
    }
}

void printVASP\
(Location locTa[], Location locS[], unsigned n,\
 double lattice[3][3], char* name, char* elemM, char* elemX)
{
  unsigned i;
  printf("%s\n",name);
  printf("%.1f\n",1.0);

  for (i = 0; i < 3; i++)
    printf("   %.9f                %.9f                %.9f\n",\
	   lattice[i][0], lattice[i][1], lattice[i][2]);

  printf("     %s         %s\n",elemM,elemX);
  printf("      %d         %d\n",n,2*n);
  printf("Cartesian\n");
  
  for (i = 0; i < n; i++) printf("        %.9f                %.9f                %.9f\n",\
				 locTa[i].x,locTa[i].y,locTa[i].z);
  
  for (i = 0; i < 2*n; i++) printf("        %.9f                %.9f                %.9f\n",\
				   locS[i].x,locS[i].y,locS[i].x);
}


void print_VASP_to_file(Location locM[], Location locX[], unsigned n,\
		   double lattice[3][3], char * name, char * elemM,\
		   char * elemX, char * file_name) 
{
  FILE * fp;
  unsigned i;

  fp = fopen(file_name, "w");

  fprintf(fp,"%s\n",name);
  fprintf(fp,"%.1f\n",1.0);

  for (i = 0; i < 3; i++)
    fprintf(fp,"   %.9f                %.9f                %.9f\n",	\
	   lattice[i][0], lattice[i][1], lattice[i][2]);

  fprintf(fp,"     %s         %s\n",elemM,elemX);
  fprintf(fp,"      %d         %d\n",n,2*n);
  fprintf(fp,"Cartesian\n");
  
  for (i = 0; i < n; i++) fprintf(fp,"        %.9f                %.9f                %.9f\n", \
				 locM[i].x,locM[i].y,locM[i].z);
  
  for (i = 0; i < 2*n; i++) fprintf(fp,"        %.9f                %.9f                %.9f\n",	\
				   locX[i].x,locX[i].y,locX[i].x);

  fclose(fp);
}

void printHelp()
{
  printf("TMD CDW Unit Cell Generator");
  printf("\n");
  printf("Code written by David Miller ");
  printf("(mill2723 at msu dot edu)");
  printf("\n");
  printf("This code is licensed under the GNU LGPL License");
  printf("\n");
  printf("For details see <http://www.gnu.org/licenses/>");
  printf("\n");
  printf("There is NO warranty; not even for MERCHANTABILITY or ");
  printf("FITNESS FOR A PARTICULAR PURPOSE.");
  printf("\n");
  printf("\n");;
  printf("Used to generate various sized unit cells for\n");
  printf("1T and 2H trilayers of transition metal \n");
  printf("dichalcogenides (TMD) with the MX2 structure.");
  printf("\n");
  printf("\n");
  printf("\n");;
  printf("All options below must be specified in the following order:");
  printf("\n");;
  printf("\t(1)  Lattice parameter a");
  printf("\n");;
  printf("\t(2)  Lattice parameter c");
  printf("\n");;
  printf("\t(3)  Super cell length a\'");
  printf("\n");;
  printf("\t(4)  Super cell length a\'\'");
  printf("\n");;
  printf("\t(5)  Super cell length b\'");
  printf("\n");;
  printf("\t(6)  Super cell length b\'\'");
  printf("\n");;
  printf("\t(7)  Layers (0 for Bulk)");
  printf("\n");
  printf("\t(8)  1T (T) or 2H (F)");
  printf("\n");
  printf("\t(9)  Randomize coordinates (T/F)");
  printf("\n");
  printf("\t(10) Element M (use atomic number)");
  printf("\n");
  printf("\t(11) Element X (use atomic number)");
  printf("\n");  
  printf("\t(12) Logical for Strain (T/F)");
  printf("\n");  
  printf("\t(13) Strain a axis (T/F)");
  printf("\n");  
  printf("\t(14) Strain b axis (T/F)");
  printf("\n");  
  printf("\t(15) Strain c axis (T/F)");
  printf("\n");  


}