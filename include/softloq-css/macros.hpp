#ifndef SOFTLOQ_CSS_MACROS_HPP
#define SOFTLOQ_CSS_MACROS_HPP

/**
 * @author Brandon Foster
 * @file macros.hpp
 * @version 1.0.0
 * @brief CSS Macros.
 */

// Static/Shared Build Macros

#if _MSC_VER
#define SOFTLOQ_CSS_EXPORT __declspec(dllexport)
#define SOFTLOQ_CSS_IMPORT __declspec(dllimport)
#elif __GNUC__
#define SOFTLOQ_CSS_EXPORT __attribute__((visibility("default")))
#define SOFTLOQ_CSS_IMPORT
#endif

// For Standalone Builds

#ifdef SOFTLOQ_CSS_NO_API
#define SOFTLOQ_CSS_API
#elif SOFTLOQ_CSS_BUILD_API
#define SOFTLOQ_CSS_API SOFTLOQ_CSS_EXPORT
#elif SOFTLOQ_CSS_USE_API
#define SOFTLOQ_CSS_API SOFTLOQ_CSS_IMPORT
#endif

// For Monolithic Builds

#ifndef SOFTLOQ_CSS_API
#ifdef SOFTLOQ_NO_API
#define SOFTLOQ_CSS_API
#elif SOFTLOQ_BUILD_API
#define SOFTLOQ_CSS_API SOFTLOQ_CSS_EXPORT
#elif SOFTLOQ_USE_API
#define SOFTLOQ_CSS_API SOFTLOQ_CSS_IMPORT
#endif
#endif

// Static Build By Default

#ifndef SOFTLOQ_CSS_API
/** @brief Static/Shared Build Macro. */
#define SOFTLOQ_CSS_API
#endif

#endif