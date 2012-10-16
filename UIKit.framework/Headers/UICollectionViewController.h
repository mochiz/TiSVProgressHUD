//
//  UICollectionViewController.h
//  UIKit
//
//  Copyright (c) 2011 Apple Inc. All rights reserved.
//

#import <UIKit/UIViewController.h>
#import <UIKit/UICollectionView.h>
#import <UIKit/UIKitDefines.h>

@class UICollectionViewLayout;
@class UICollectionViewController;

NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionViewController : UIViewController <UICollectionViewDelegate, UICollectionViewDataSource>

- (id)initWithCollectionViewLayout:(UICollectionViewLayout *)layout;

@property (nonatomic, retain) UICollectionView *collectionView;
@property (nonatomic) BOOL clearsSelectionOnViewWillAppear; // defaults to YES, and if YES, any selection is cleared in viewWillAppear:

@end
