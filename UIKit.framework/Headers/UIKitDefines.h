//
//  UIKitDefines.h
//  UIKit
//
//  Copyright (c) 2007-2012, Apple Inc. All rights reserved.
//

#import <Availability.h>

#ifdef __cplusplus
#define UIKIT_EXTERN		extern "C" __attribute__((visibility ("default")))
#else
#define UIKIT_EXTERN	        extern __attribute__((visibility ("default")))
#endif

#ifndef __has_feature
#define __has_feature(x) 0
#endif

#if !__has_feature(objc_instancetype)
#undef instancetype
#define instancetype id
#endif

#define UIKIT_STATIC_INLINE	static inline
