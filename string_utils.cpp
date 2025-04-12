#ifndef STRING_UTILS_CPP
#define STRING_UTILS_CPP

#include <cstring>

#include "definitions.cpp"
#include "math_utils.cpp"

/*
You MUST use recursion to complete TASK 2. You are NOT allowed to use any for or while loop.
*/

/**
 * Indicates whether the string 'a' represents the same string value as 'b'.
 * @return true if the values are the same; false otherwise.
 */
bool are_equal(const char a[], const char b[])
{
  // TODO Task 2.1 BEGIN
  if (a[0] == '\0' && b[0] == '\0') {
    return true ;
  }
  if (a[0] == '\0' || b[0] == '\0') {
    return false ;
  }
  else {
    return (a[0] == b[0] && are_equal(a+1, b+1)) ;
  }
  // TODO Task 2.1 END
}

/**
 * Returns the index of the *first* character of the *first* pattern occurrence in the string.
 *
 * E.g. str = "This is the pattern 1 and pattern 2", pattern = "pattern"
 * index_of should return 12 (... pattern 1 and pattern 2)
 *                                ^
 */
int index_of(const char str[], const char pattern[])
{
  // TODO Task 2.2 BEGIN
  if (pattern[0] == '\0') {
    return 0 ;
  }
  if (str[0] == '\0') {
    return -1 ;
  }
  if (str[0] == pattern[0]) {
    int matching = index_of(str + 1, pattern +1);
    if (matching == -1) {
      return -1 ;
    }
    return 0 ;
  }
  int nextindex = index_of(str + 1, pattern) ;
  return(nextindex == -1) ? -1 :(nextindex + 1) ;
  // TODO Task 2.2 END
}

/**
 * Returns the index of the *first* character of the *last* pattern occurrence in the string.
 *
 * E.g. str = "This is the pattern 1 and pattern 2", pattern = "pattern"
 * index_of should return 26 (... pattern 1 and pattern 2)   ==> different from index_of
 *                                              ^
 */
int last_index_of(const char str[], const char pattern[])
{
  // TODO Task 2.3 BEGIN
  if (pattern[0] == '\0') {
    return 0 ;
  }
  if (str[0] == '\0') {
    return -1 ;
  }
  int nextindex = last_index_of(str + 1, pattern) ;
  if (nextindex != -1) {
    return nextindex + 1 ;
  }
  if (str[0] == pattern[0]) {
    if (index_of(str + 1, pattern + 1) == 0) {
      return 0;
    }
  }
  return -1 ;
  // TODO Task 2.3 END
}

/**
 * Indicates if the character 'c' is a digit.
 *
 * If 'c' is one of the characters '0', '1', ..., '9', then it is a digit; and
 * this function returns true; otherwise, it returns false.
 */
bool is_digit(const char c) { return c >= '0' && c <= '9'; }

/**
 * Returns the integer value of the digit character 'c'.
 *
 * If 'c' is one of the characters '0', '1', ..., '9', then it returns the
 * corresponding integer value of the digit, i.e., 0, 1, ..., 9.
 */
int parse_digit(const char c) { return c - '0'; }

/**
 * Indicates if the string 'str' represents a number.
 */
bool is_number(const char str[])
{
  // TODO Task 2.4 BEGIN
  if (str[0] == '\0' || str[0] == '-') {
    return false ;
  }
  if (str[0] == '0' && str[1] != '\0' && str[1] != '.') {
    return false ;
  }
  if (str[0] >= '0' && str[0] <= '9') {
    if (str[1] == '\0') {
      return true ;
    }
    if (str[1] == '.') {
      if (str[2] == '\0') {
        return false ;
      }
      return is_number(str + 2) ;
    }
    return is_number(str + 1) ;
  }
  return false ;
  // TODO Task 2.4 END
}

/**
 * Returns the value of the number represented by the string 'str'.
 */
double parse_number(const char str[])
{
  // TODO Task 2.5 BEGIN
  if (str[0] == '\0') {
    return 0.0 ;
  }
  if (str[0] >= '0' && str[0] <= '9') {
    return (str[0] - '0') + 0.1 * parse_number(str + 1) ;
  }
  if (str[0] == '.') {
    return parse_number(str + 1) ;
  }
  // TODO Task 2.5 END
}

/**
 * Remove all leading and trailing whitespaces from the string 'str', and store
 * the result in 'destination'.
 */
void trim(const char str[], char destination[])
{
  // TODO Task 2.6 BEGIN
  if (str[0] == '\0') {
    destination[0] = '\0' ;
    return ;
  }
  if (str[0] == ' ') {
    trim(&str[1], destination) ;
  }
  else {
    destination[0] = str[0] ;
    if (str[1] == '\0' ) {
      destination[1] = '\0' ;
    }
    else if (str[1] == ' ') {
      if (str[2] != '\0' && str[2] != ' ') {
        destination[1]= ' ' ;
        trim(&str[2], destination + 2) ;
      }
      else {
        trim(&str[2], destination + 1) ;
      }
    }
    else {
      trim(&str[1], destination + 1) ;
    }
  }
  // TODO Task 2.6 END
}

#endif // STRING_UTILS_CPP
