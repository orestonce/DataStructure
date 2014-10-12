#ifndef _CONVERT_H_
#define _CONVERT_H_

#include <string>
#include <stdexcept>
/*
 * convert 10-step to x-step by stack
 *  if step < 2 or step > 10  throw a logic_error exception .
 * */
std::string convert(int origin_10, int step ) throw ( std::logic_error );

#endif
