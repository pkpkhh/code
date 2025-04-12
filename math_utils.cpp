#ifndef MATH_UTILS_CPP
#define MATH_UTILS_CPP

#include "definitions.cpp"

/*
You MUST use recursion to complete TASK 1. You are NOT allowed to use any for or while loop.
*/

/**
 * Returns the absolute value of x.
 */
double absolute(const double x)
{
  // TODO Task 1.1 BEGIN  
  if (x < 0) {
    return -x ;
  }
  return x ;
  // TODO Task 1.1 END
}

/**
 * Indicates if a result from an iterative algorithm is accurate enough.
 * We define "accurate enough" as the difference between the previous and
 * current results to be less than 0.001.
 */
bool is_accurate_enough(const double previous, const double current)
{
  return absolute(previous - current) < 0.001;
}

/**
 * Returns the square root of x.
 */
double square_root(const double x)
{
  // TODO Task 1.2 BEGIN  
  if (x == 0) {
    return 0 ;
  }
  static double guess = x ;
  double next_guess = 0.5 * (guess + x / guess) ;
  if (is_accurate_enough(guess, next_guess)) {
    guess = next_guess ;
    return next_guess ;
  }
  guess = next_guess ;
  return square_root(x) ;
  // TODO Task 1.2 END
}

/**
 * Returns the value of base raised to the exponent power.
 */
double power(const double base, const int exponent)
{
  // TODO Task 1.3 BEGIN  
  if (exponent == 0) {
    return 1;
  } 
  else if (exponent < 0) {
    return 1/power(base, -exponent);
  }
  else {
    return base * power(base, exponent -1) ;
  }
  // TODO Task 1.3 END
}

/**
 * Returns the factorial of n.
 */
double factorial(const int n)
{
  // TODO Task 1.4 BEGIN  
  if (n == 0) {
    return 1;
  }
  else if (n > 0) {
    return n * factorial(n-1) ;
  }
  // TODO Task 1.4 END
}

#endif // MATH_UTILS_CPP
