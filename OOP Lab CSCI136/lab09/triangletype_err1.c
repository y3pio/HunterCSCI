/******************************************************************************
  Title          : triangletype_err1.c
  Author         : Stewart Weiss
  Created on     : March 29, 2012
  Description    : Prints a classification of the triangle with sides a b c
  Purpose        : 
  Usage          : triangletype_err1 side1 side2 side3
                   where 0 < side1 <= side2 <= side3 
  Build with     : gcc -o triangletype_err1 triangletype_err1.c
  Modifications  :
 
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <errno.h>

#define  EQUILATERAL    1
#define  ISOSCELES      2
#define  SCALENE        3

/******************************************************************************
                                 usage message
******************************************************************************/
void usage     (char* progname)
{
    printf("usage: %s a b c\n   where 0 < a <= b <= c\n", progname);
}

/******************************************************************************
                           classify by side equality
******************************************************************************/
/**  classify  ( double a, double b, double c )
 *   This returns one of the defined constants
 *      EQUILATERAL ,ISOSCELES ,SCALENE
 *   based on the number of equal sides in the triangle represented by (a,b,c)
 *   @pre    a <= b <= c and a + b > c  
 *   @param  double a  [in]
 *   @param  double b  [in]
 *   @param  double c  [in]
 *   @returns int   
 */
int  classify( double a, double b, double c )
{
    if ( ( a == b ) && ( b == c ) )
        /* all 3 sides are equal */
        return EQUILATERAL;
    else if ( a == b )
        /* (a == b) && (b != c) */
        return ISOSCELES;
    else if ( b == c )
        /* (a != b) && ( b == c) */
        return ISOSCELES;
    else
        /* (a!= b) && (b != c) which implies 
           (a < b) && (b < c) and therefore (a < c) */
        return SCALENE;
}

/******************************************************************************
                              Main program
******************************************************************************/

int main( int argc, char* argv[])
{

    double a, b, c;
    char  *endptr;

    /* Check that there are three arguments */
    if ( argc != 4 ) {
        usage( basename(argv[0]));
        exit(1);
    }
 
    /* Convert arguments to numbers and exit if any are not positive numbers */
    errno = 0;    
    a = strtod(argv[1], &endptr);
    if (errno != 0) {
        perror("strtod");
        exit(EXIT_FAILURE);
    }

    errno = 0;    
    b = strtod(argv[2], &endptr);
    if (errno != 0) {
        perror("strtod");
        exit(EXIT_FAILURE);
    }

    errno = 0;    
    c = strtod(argv[3], &endptr);
    if (errno != 0) {
        perror("strtod");
        exit(EXIT_FAILURE);
    }

    /* Make sure that they are all positive */
    if ( ( a <= 0 ) || ( b <= 0 ) || ( c <= 0 ) ) {
        usage( basename(argv[0]));
        exit(1);
    }

    /* Make sure that they are in non-decreasing order */
    if ( ( a > b ) || ( b > c ) ) {
        usage( basename(argv[0]));
        exit(1);
    }

    /* We now know that we have three positive numbers a, b, c in 
       non-decreasing order.
       At this point it is not a usage error if something goes wrong, but a
       classification of the numbers as a triangle. First check if they are
       a triangle. */
  
    if ( a + b < c ) {
        printf(" %.5f + %.5f <= %.5f implying that this is not a triangle\n", a,b,c);
        return 0;
    }

    /* At this point we know that a + b > c, so it is time to classify
       the triangle. First we decide how many sides are equal. */
    switch ( classify(a,b,c) ) {
    case EQUILATERAL:
        /* For equilateral triangles just print this and nothing more */
        printf("Equilateral triangle\n");
        return 0;
    case ISOSCELES:
        printf("Isosceles ");
        break;
    case SCALENE:
        printf("Scalene ");
        break;
    }

    /* If we reach here, it is not equilateral. We test the angles to see
       whether they are all acute, or whether it is a right triangle, or 
       if there is an obtuse angle.  The Law of Cosines states that 

           c^2 = a^2 + b^2 - 2*a*b*cos(theta)

       where theta is the angle between sides a and b.  Since theta must be 
       less than pi radians, 0 < theta < pi.  

       When 0 < theta < pi/2, i.e., theta is an acute angle,
           cos(theta) > 0 and 2*a*b*cos(theta) > 0 so
           c^2 = a^2 + b^2 - 2*a*b*cos(theta) < a^2 + b^2 
       Conversely, if c^2 <  a^2 + b^2 then theta is acute.
       

       When theta == pi/2, i.e., theta is a right angle,
           cos(theta) == 0 and c^2 = a^2 + b^2. 
       Conversely, if c^2 == a^2 + b^2 then theta is a right angle.

       When pi/2 < theta < pi, i.e., theta is obtuse,
           cos(theta) < 0 and 2*a*b*cos(theta) < 0 so
           c^2 = a^2 + b^2 - 2*a*b*cos(theta) > a^2 + b^2 
       Conversely, if c^2 > a^2 + b^2 then theta is obtuse.

       It is enough to check the relationship between a^2 + b^2 and c^2,
       because a <= b <= c, so it is impossible for the angles between
       a and c and b and c to be obtuse. When an angle is obtuse, its cosine
       is negative. Applying the Law of Cosines to these other angles would
       show that since a <= b <= c, the cosine must be positive or zero.
    */

    /*   If a^2 + b^2 < c^2, the angle <cab is obtuse */   
    if ( a*a + b*b < c*c ) { /* obtuse */
         printf("obtuse triangle\n");   
    }

    /* If a^2 + b^2 > c^2, the angle <cab is acute. Since a and b are both
       smaller than c, <acb and <abc cannot be obtuse. */
    else if ( a*a + b*b > c*c ) { /* acute */
         printf("acute triangle\n");   
    }
    /* It is a right triangle. */
    else  { /* right triangle */
         printf("right triangle\n");   
    }
    return 0;
}
