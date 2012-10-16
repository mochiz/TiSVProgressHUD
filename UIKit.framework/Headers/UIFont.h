//
//  UIFont.h
//  UIKit
//
//  Copyright (c) 2007-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIFont : NSObject <NSCopying> {
  @private
}

+ (UIFont *)fontWithName:(NSString *)fontName size:(CGFloat)fontSize;

// Returns an array of font family names for all installed fonts
+ (NSArray *)familyNames;
// Returns an array of font names for the specified family name
+ (NSArray *)fontNamesForFamilyName:(NSString *)familyName;

// Some convenience methods to create system fonts
+ (UIFont *)systemFontOfSize:(CGFloat)fontSize;
+ (UIFont *)boldSystemFontOfSize:(CGFloat)fontSize;
+ (UIFont *)italicSystemFontOfSize:(CGFloat)fontSize;

// Font attributes
@property(nonatomic,readonly,retain) NSString *familyName;
@property(nonatomic,readonly,retain) NSString *fontName;
@property(nonatomic,readonly)        CGFloat   pointSize;
@property(nonatomic,readonly)        CGFloat   ascender;
@property(nonatomic,readonly)        CGFloat   descender;
@property(nonatomic,readonly)        CGFloat   capHeight;
@property(nonatomic,readonly)        CGFloat   xHeight;
@property(nonatomic,readonly)        CGFloat   lineHeight NS_AVAILABLE_IOS(4_0);

// Create a new font that is identical to the current font except the specified size
- (UIFont *)fontWithSize:(CGFloat)fontSize;

@end

@interface UIFont (UIFontDeprecated)
@property(nonatomic,readonly) CGFloat leading; // use lineHeight. does not return actual leading. will be formally deprecated in future
@end
