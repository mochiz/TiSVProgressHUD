//
//  UIToolbar.h
//  UIKit
//
//  Copyright (c) 2006-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIView.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIBarButtonItem.h>

typedef NS_ENUM(NSInteger, UIToolbarPosition) {
    UIToolbarPositionAny = 0,
    UIToolbarPositionBottom = 1,
    UIToolbarPositionTop = 2,
};

@class UIBarButtonItem, UIColor;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIToolbar : UIView {
  @private
    id                     _delegate;
    NSArray               *_items;
    UIColor               *_tintColor;
    struct {
        unsigned int barStyle:2;
        unsigned int mode:2;
        unsigned int wasEnabled:1;
        unsigned int downButtonSentAction:1;
        unsigned int isTranslucent:1;
        unsigned int forceTopBarAppearance:1;
        unsigned int autolayoutIsLocked:1;
    } _toolbarFlags;
    CFMutableDictionaryRef _groups;
    NSArray               *_buttonItems;
    NSInteger              _currentButtonGroup;
    NSInteger              _pressedTag;
    CGFloat                _extraEdgeInsets;
    UIView                *_backgroundView;
    id                     _appearanceStorage;
    id                     _currentAlert;
}

@property(nonatomic)        UIBarStyle barStyle;    // default is UIBarStyleDefault (blue)
@property(nonatomic,copy)   NSArray   *items;       // get/set visible UIBarButtonItem. default is nil. changes not animated. shown in order
@property(nonatomic,assign,getter=isTranslucent) BOOL translucent NS_AVAILABLE_IOS(3_0); // Default is NO. Always YES if barStyle is set to UIBarStyleBlackTranslucent

- (void)setItems:(NSArray *)items animated:(BOOL)animated;   // will fade in or out or reorder and adjust spacing

/* Default tintColor is nil. When non-nil, bordered buttons and segmented controls in the toolbar
 will pick up the same tint unless their tints are independently set.
 */
@property(nonatomic,retain) UIColor   *tintColor  UI_APPEARANCE_SELECTOR;

/* Use these methods to set and access custom background images for toolbars.
      Default is nil. When non-nil the image will be used instead of the system image for toolbars in the
 specified position.
      For the barMetrics argument, UIBarMetricsDefault is the fallback.
 
 DISCUSSION: Interdependence of barStyle, tintColor, backgroundImage.
 When barStyle or tintColor is set as well as the bar's background image,
 the bar buttons (unless otherwise customized) will inherit the underlying
 barStyle or tintColor.
 */
- (void)setBackgroundImage:(UIImage *)backgroundImage forToolbarPosition:(UIToolbarPosition)topOrBottom barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
- (UIImage *)backgroundImageForToolbarPosition:(UIToolbarPosition)topOrBottom barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* Default is nil. When non-nil, a custom shadow image to show instead of the default shadow image. For a custom shadow to be shown, a custom background image must also be set with -setBackgroundImage:forToolbarPosition:barMetrics: (if the default background image is used, the default shadow image will be used).
 */
- (void)setShadowImage:(UIImage *)shadowImage forToolbarPosition:(UIToolbarPosition)topOrBottom NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;
- (UIImage *)shadowImageForToolbarPosition:(UIToolbarPosition)topOrBottom NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;

@end
