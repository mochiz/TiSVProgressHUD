//
//  UIActivityItemProvider.h
//  UIKit
//
//  Copyright 2012 Apple, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@class UIActivityViewController;

@protocol UIActivityItemSource <NSObject>

@required

- (id)activityViewControllerPlaceholderItem:(UIActivityViewController *)activityViewController;	// called to determine data type
- (id)activityViewController:(UIActivityViewController *)activityViewController itemForActivityType:(NSString *)activityType;	// called to fetch data

@end

NS_CLASS_AVAILABLE_IOS(6_0) @interface UIActivityItemProvider : NSOperation <UIActivityItemSource>

- (id)initWithPlaceholderItem:(id)placeholderItem;

@property(nonatomic,retain,readonly) id        placeholderItem;  // return item from init
@property(nonatomic,readonly)        NSString *activityType;      // Activity type available when -item is called. nil at other times.

- (id)item;                                    // called by -main when data is needed. default returns nil. Subclass to override and call status/progress. called on secondary thread

@end
