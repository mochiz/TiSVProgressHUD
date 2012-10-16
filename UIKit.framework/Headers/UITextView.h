//
//  UITextView.h
//  UIKit
//
//  Copyright (c) 2007-2012, Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIScrollView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UITextInput.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIDataDetectors.h>

@class DOMHTMLElement;
@class UIDelayedAction;
@class UIEvent, UITouch, UIFont, UIColor;
@class UITextInputTraits;
@class UITextInteractionAssistant;
@class UIWebDocumentView;
@class WebCoreFrameBridge;
@class WebFrame;
@class UITextInteractionAssistant;
@class UITextSelectionView;
@class UITextView;


@protocol UITextViewDelegate <NSObject, UIScrollViewDelegate>

@optional

- (BOOL)textViewShouldBeginEditing:(UITextView *)textView;
- (BOOL)textViewShouldEndEditing:(UITextView *)textView;

- (void)textViewDidBeginEditing:(UITextView *)textView;
- (void)textViewDidEndEditing:(UITextView *)textView;

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)textViewDidChange:(UITextView *)textView;

- (void)textViewDidChangeSelection:(UITextView *)textView;

@end


NS_CLASS_AVAILABLE_IOS(2_0) @interface UITextView : UIScrollView <UITextInput> 
{
  @package
    WebFrame           *m_frame;
    DOMHTMLElement     *m_body;
    int                 m_marginTop;
    UIDelayedAction    *m_selectionTimer;
    UIDelayedAction    *m_longPressAction;
    BOOL                m_editable;
    BOOL                m_editing;
    BOOL                m_becomesEditableWithGestures;
    BOOL                m_reentrancyGuard;
    BOOL                m_readyForScroll;
    BOOL                m_hasExplicitTextAlignment;
    BOOL                m_hasExplicitLineHeight;
    
    // Gesture recognition.
    UITextInteractionAssistant *m_interactionAssistant;
    
    // property ivars
    UIWebDocumentView  *m_webView;
    UIFont             *m_font;
    UIColor            *m_textColor;
    NSTextAlignment     m_textAlignment;
    UIView             *m_inputView;
    UIView             *m_inputAccessoryView;
    CGFloat             m_lineHeight;
    BOOL                m_skipScrollContainingView;
    BOOL                m_allowsEditingTextAttributes;
    BOOL                m_usesAttributedText;
    BOOL                m_clearsOnInsertion;
}

@property(nonatomic,assign) id<UITextViewDelegate> delegate;
@property(nonatomic,copy) NSString *text;
@property(nonatomic,retain) UIFont *font;
@property(nonatomic,retain) UIColor *textColor;
@property(nonatomic) NSTextAlignment textAlignment;    // default is NSLeftTextAlignment
@property(nonatomic) NSRange selectedRange;
@property(nonatomic,getter=isEditable) BOOL editable;
@property(nonatomic) UIDataDetectorTypes dataDetectorTypes NS_AVAILABLE_IOS(3_0);

@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // defaults to NO
@property(nonatomic,copy) NSAttributedString *attributedText NS_AVAILABLE_IOS(6_0); // default is nil
@property(nonatomic,copy) NSDictionary *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes

- (BOOL)hasText;
- (void)scrollRangeToVisible:(NSRange)range;


// Presented when object becomes first responder.  If set to nil, reverts to following responder chain.  If
// set while first responder, will not take effect until reloadInputViews is called.
@property (readwrite, retain) UIView *inputView;             
@property (readwrite, retain) UIView *inputAccessoryView;

@property(nonatomic) BOOL clearsOnInsertion NS_AVAILABLE_IOS(6_0); // defaults to NO. if YES, the selection UI is hidden, and inserting text will replace the contents of the field. changing the selection will automatically set this to NO.

@end

UIKIT_EXTERN NSString * const UITextViewTextDidBeginEditingNotification;
UIKIT_EXTERN NSString * const UITextViewTextDidChangeNotification;
UIKIT_EXTERN NSString * const UITextViewTextDidEndEditingNotification;
