#pragma once
#include <testlib_export.h>

#if defined(TESTLIB_EXPORT) && defined(testlib_EXPORTS)
  #if (defined(__GNUC__) || defined(__clang__))
      #define EXPORT_TEMPLATE TESTLIB_EXPORT
      #define EXPORT_INSTANTIATE
  #else
      #define EXPORT_TEMPLATE
      #define EXPORT_INSTANTIATE TESTLIB_EXPORT
  #endif
#elif defined(TESTLIB_NO_EXPORT)
  #define EXPORT_TEMPLATE TESTLIB_EXPORT
  #define EXPORT_INSTANTIATE
#endif

