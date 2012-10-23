/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2012年 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#import "ComQnypTisvprogresshubViewProxy.h"
#import "TiUtils.h"

@implementation ComQnypTisvprogresshubViewProxy

-(void)show:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(show:) withObject:args waitUntilDone:NO];
}

-(void)showWithStatus:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(showWithStatus:) withObject:args waitUntilDone:NO];
}

-(void)showWithMaskType:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(showWithMaskType:) withObject:args waitUntilDone:NO];
}

-(void)showSuccessWithStatus:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(showSuccessWithStatus:) withObject:args waitUntilDone:NO];
}

-(void)showWithStatusAndMaskType:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(showWithStatusAndMaskType:) withObject:args waitUntilDone:NO];
}

-(void)showErrorWithStatus:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(showErrorWithStatus:) withObject:args waitUntilDone:NO];
}

-(void)showImage:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(showImage:) withObject:args waitUntilDone:NO];
}

-(void)dismiss:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(dismiss:) withObject:args waitUntilDone:NO];
}

-(void)dismissWithSuccess:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(dismissWithSuccess:) withObject:args waitUntilDone:NO];
}

-(void)dismissWithError:(id)args
{
	[[self view] performSelectorOnMainThread:@selector(dismissWithError:) withObject:args waitUntilDone:NO];
}

@end
