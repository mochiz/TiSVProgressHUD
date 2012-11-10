TiSVProgressHUD module
===========================================
Titanium Mobile Module project for [SVProgressHUD](https://github.com/samvermette/SVProgressHUD)


![example](https://github.com/downloads/mochiz/TiSVProgressHUD/example.png)


INSTALL MODULE
--------------------
1. Run `build.py` which creates your distribution
2. cd to `/Library/Application Support/Titanium`
3. copy this zip file into the folder of your Titanium SDK

REGISTER MODULE
---------------------
Register your module with your application by editing `tiapp.xml` and adding your module.
Example:

```
<modules>
	<module platform="iphone" version="0.1">com.qnyp.tisvprogresshub</module>
</modules>
```

USING MODULE IN CODE
-------------------------
For example

```
var win = Ti.UI.createWindow();
var tisvprogresshud = require('com.qnyp.tisvprogresshub');
var progress = tisvprogresshud.createView();
win.add(progress);

progress.show();
progress.dismiss();
```

USAGE
-------------------------

show SVProgressHUD
```
progress.show();
progress.showWithStatus({status: 'loading...'});
progress.showWithStatus({status: 'loading...', maskType: '4'});
```

maskType property
```
1: SVProgressHUDMaskTypeNone, // allow user interactions, don't dim background UI (default)
2: SVProgressHUDMaskTypeClear, // disable user interactions, don't dim background UI
3: SVProgressHUDMaskTypeBlack, // disable user interactions, dim background UI with 50% translucent black
4: SVProgressHUDMaskTypeGradient // disable user interactions, dim background UI with translucent radial gradient (a-la-alertView)
```

show Success or Error
```
progress.showSuccessWithStatus({status:'Success!'});
progress.showErrorWithStatus({status:'Error!'});
```

dismiss SVProgressHUD
```
progress.dismiss();
progress.dismissWithSuccess({status:'Success!'});
progress.dismissWithError({status:'Error!'});
```

ABOUT EXAMPLE APP
-------------------------
Example app is in `example` directory.

LICENSE
-------------------------
MIT License
