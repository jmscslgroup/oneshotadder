#ifndef ONESHOTADDER__VISIBILITY_CONTROL_H_
#define ONESHOTADDER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ONESHOTADDER_EXPORT __attribute__ ((dllexport))
    #define ONESHOTADDER_IMPORT __attribute__ ((dllimport))
  #else
    #define ONESHOTADDER_EXPORT __declspec(dllexport)
    #define ONESHOTADDER_IMPORT __declspec(dllimport)
  #endif
  #ifdef ONESHOTADDER_BUILDING_LIBRARY
    #define ONESHOTADDER_PUBLIC ONESHOTADDER_EXPORT
  #else
    #define ONESHOTADDER_PUBLIC ONESHOTADDER_IMPORT
  #endif
  #define ONESHOTADDER_PUBLIC_TYPE ONESHOTADDER_PUBLIC
  #define ONESHOTADDER_LOCAL
#else
  #define ONESHOTADDER_EXPORT __attribute__ ((visibility("default")))
  #define ONESHOTADDER_IMPORT
  #if __GNUC__ >= 4
    #define ONESHOTADDER_PUBLIC __attribute__ ((visibility("default")))
    #define ONESHOTADDER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ONESHOTADDER_PUBLIC
    #define ONESHOTADDER_LOCAL
  #endif
  #define ONESHOTADDER_PUBLIC_TYPE
#endif
#endif  // ONESHOTADDER__VISIBILITY_CONTROL_H_
// Generated 26-Nov-2024 15:47:16
// Copyright 2019-2020 The MathWorks, Inc.
