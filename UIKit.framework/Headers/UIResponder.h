//
//  UIResponder.h
//  UIKit
//
//  Copyright (c) 2005-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIEvent.h>

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIResponder : NSObject {
  @private
}

- (UIResponder*)nextResponder;

- (BOOL)canBecomeFirstResponder;    // default is NO
- (BOOL)becomeFirstResponder;

- (BOOL)canResignFirstResponder;    // default is YES
- (BOOL)resignFirstResponder;

- (BOOL)isFirstResponder;

// Generally, all responders which do custom touch handling should override all four of these methods.
// Your responder will receive either touchesEnded:withEvent: or touchesCancelled:withEvent: for each
// touch it is handling (those touches it received in touchesBegan:withEvent:).
// *** You must handle cancelled touches to ensure correct behavior in your application.  Failure to
// do so is very likely to lead to incorrect behavior or crashes.
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;

- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event NS_AVAILABLE_IOS(3_0);
- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event NS_AVAILABLE_IOS(3_0);
- (void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent *)event NS_AVAILABLE_IOS(3_0);

- (void)remoteControlReceivedWithEvent:(UIEvent *)event NS_AVAILABLE_IOS(4_0);

- (BOOL)canPerformAction:(SEL)action withSender:(id)sender NS_AVAILABLE_IOS(3_0);
@property(nonatomic,readonly) NSUndoManager *undoManager NS_AVAILABLE_IOS(3_0);

@end

@interface NSObject(UIResponderStandardEditActions)   // these methods are not implemented in NSObject

- (void)cut:(id)sender NS_AVAILABLE_IOS(3_0);
- (void)copy:(id)sender NS_AVAILABLE_IOS(3_0);
- (void)paste:(id)sender NS_AVAILABLE_IOS(3_0);
- (void)select:(id)sender NS_AVAILABLE_IOS(3_0);
- (void)selectAll:(id)sender NS_AVAILABLE_IOS(3_0);
- (void)delete:(id)sender NS_AVAILABLE_IOS(3_2);
- (void)makeTextWritingDirectionLeftToRight:(id)sender NS_AVAILABLE_IOS(5_0);
- (void)makeTextWritingDirectionRightToLeft:(id)sender NS_AVAILABLE_IOS(5_0);
- (void)toggleBoldface:(id)sender NS_AVAILABLE_IOS(6_0);
- (void)toggleItalics:(id)sender NS_AVAILABLE_IOS(6_0);
- (void)toggleUnderline:(id)sender NS_AVAILABLE_IOS(6_0);

@end

@interface UIResponder (UIResponderInputViewAdditions)

// Called and presented when object becomes first responder.  Goes up the responder chain.
@property (readonly, retain) UIView *inputView NS_AVAILABLE_IOS(3_2);            
@property (readonly, retain) UIView *inputAccessoryView NS_AVAILABLE_IOS(3_2); 

// If called while object is first responder, reloads inputView and inputAccessoryView.  Otherwise ignored.
- (void)reloadInputViews NS_AVAILABLE_IOS(3_2);

@end
