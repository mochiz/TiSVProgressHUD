/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2012年 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#import "ComQnypTisvprogresshubView.h"
#import "TiUtils.h"
#import "SVProgressHUD.h"


@implementation ComQnypTisvprogresshubView
-(void)dealloc
{
    RELEASE_TO_NIL(square);
    [super dealloc];
}

-(UIView*)square
{
    if (square==nil)
    {
        square = [[UIView alloc] initWithFrame:[self frame]];
        [self addSubview:square];
    }
    return square;
}
-(void)frameSizeChanged:(CGRect)frame bounds:(CGRect)bounds
{
    if (square!=nil)
    {
        [TiUtils setView:square positionRect:bounds];
    }
}

-(void)setColor_:(id)color
{
    UIColor *c = [[TiUtils colorValue:color] _color];
    UIView *s = [self square];
    s.backgroundColor = c;
}

# pragma mark Public APIs

#pragma mark - Show Methods

- (void)show:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
    [SVProgressHUD show];
}

- (void)showWithStatus:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
    // maskTypeがなければshowWithStatusを実行
    if (![args objectForKey:@"maskType"]) {
        NSLog(@"not has maskType");
        [SVProgressHUD showWithStatus:[args objectForKey:@"status"]];
        return;
    } else {
        [SVProgressHUD showWithStatus:[args objectForKey:@"status"]
                             maskType:[[args objectForKey:@"maskType"] intValue]];
    }
}

- (void)showWithMaskType:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
    [SVProgressHUD showWithMaskType:(SVProgressHUDMaskType)[args objectForKey:@"maskType"]];
}

#pragma mark - Show then dismiss methods

- (void)showSuccessWithStatus:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
    [SVProgressHUD showSuccessWithStatus:[args objectForKey:@"status"]];
}

- (void)showErrorWithStatus:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
    [SVProgressHUD showErrorWithStatus:[args objectForKey:@"status"]];
}

#pragma mark - Dismiss Methods

- (void)dismiss:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
   [SVProgressHUD dismiss];
}

- (void)dismissWithSuccess:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
    [SVProgressHUD dismissWithSuccess:[args objectForKey:@"status"]];
  
}

- (void)dismissWithError:(id)args {
    ENSURE_SINGLE_ARG(args,NSDictionary);
    [SVProgressHUD dismissWithError:[args objectForKey:@"status"]];
}


-(void)setStatus:(NSString*)status
{
    [SVProgressHUD setStatus:status];
}


@end
